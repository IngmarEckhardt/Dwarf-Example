#ifdef __AVR_HAVE_ELPM__

#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <avr/pgmspace.h>

//DwarfOS
#include <dwarf-os/setup.h>
#include <dwarf-os/mcu_clock.h>
#include <dwarf-os/uart_helper.h>
#include <dwarf-os/flash_helper.h>
#include <dwarf-os/heap_management_helper.h>
#include <dwarf-os/stdio.h>
#include <dwarf-os/time.h>

//KISS Deklarations instead of a header
char * loadAction(FlashHelper * helper, uint8_t actionNumber);
int16_t putFileStrAction(FlashHelper * helper, uint8_t actionNumber);

char * loadActionWithIndex(FlashHelper * helper, uint8_t actionWithIndexNumber);
int16_t putFileStrActionWithIndex(FlashHelper * helper, uint8_t actionWithIndexNumber);

char * loadShortLocation(FlashHelper * helper, uint8_t shortLocationNumber);
int16_t putFileStrShortLocation(FlashHelper * helper, uint8_t shortLocationNumber);


void setup(void);

void adjustTo1Sec(void);

void printToSerialOutput(void);


McuClock * mcuClock;
UartHelper * uartHelper;
FlashHelper * flashHelper;

const uint8_t adjustToSecondValue = ADJUST_TO_SECOND_VALUE;
uint8_t lastTime;
volatile uint8_t adjustCounter;



int main(void) {

    setup();

    sei();

    while (1) {

        sleep_mode();
        adjustTo1Sec();
        if ((uint8_t) time(NULL) != lastTime) {

            lastTime = time(NULL);

            printToSerialOutput();

        }
    }
}




ISR(TIMER2_OVF_vect) { adjustCounter++; }

// example placement of string in Progmem
#define MEMORY_STRING_LENGTH 25
const __attribute__((__progmem__)) char memoryStringOnFlash[MEMORY_STRING_LENGTH + 1] = ": free Memory is (byte): ";
#define ERROR_STRING_LENGTH 19
const __attribute__((__progmem__)) char errorStringOnFlash[ERROR_STRING_LENGTH + 1] = "FATAL ERROR! Code: ";
const char formatStr[] = "%s:%s%d\n";

void printToSerialOutput(void) {
    HeapManagementHelper * heapHelper = dOS_initHeapManagementHelper();
    if (heapHelper) {
        int16_t memoryAmount = heapHelper->getFreeMemory();

        char * memoryString = malloc(MEMORY_STRING_LENGTH + 1);

        char * timestamp = ctime(NULL);

        if (memoryString && flashHelper && timestamp) {
            flashHelper->loadString_P(memoryString, pgm_get_far_address(memoryStringOnFlash));
            printf(formatStr, timestamp, memoryString, memoryAmount);
        }

        putFileStrAction(flashHelper, 1);

        char * longLocation =  loadActionWithIndex(flashHelper, 2);
        if (longLocation) {
            printf("%s", longLocation);
        }


        free(timestamp);
        free(memoryString);
    }
    free(heapHelper);
}


void adjustTo1Sec(void) {
    if (adjustCounter == adjustToSecondValue) {
        mcuClock->incrementClockOneSec();
        adjustCounter = 0;
    }
}

// StdOut, has no buffer in this implementation, could also be done with a interrupt driven routine and a buffer
int put_char(char c, FILE * stream) {
    uartHelper->usartTransmitChar(c);
    return 0;
}

// the example only need a stdout
static FILE myStdOut = FDEV_SETUP_STREAM(put_char, NULL, _FDEV_SETUP_WRITE);

void setup(void) {
    setupMcu(&mcuClock); // general setup DwarfOS

    uartHelper = dOS_initUartHelper();
    stdout = &myStdOut;

    flashHelper = dOS_initFlashHelper(0);

    if (!flashHelper) { puts_PF(pgm_get_far_address(errorStringOnFlash)); }

}

#else
int main(void){};
#endif