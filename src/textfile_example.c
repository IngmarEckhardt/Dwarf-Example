#ifdef __AVR_HAVE_ELPM__ // Example uses way more than 64kb Program Memory
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
//DwarfOS
#include <dwarf-os/setup.h>
#include <dwarf-os/mcu_clock.h>
#include <dwarf-os/uart_helper.h>
#include <dwarf-os/flash_helper.h>
#include <dwarf-os/heap_management_helper.h>
#include <dwarf-os/stdio.h>
#include <dwarf-os/time.h>

//KISS Deklarations instead of a header
int16_t putFileStrAction(FlashHelper * helper, uint8_t actionNumber);

char * loadActionWithIndex(FlashHelper * helper, uint8_t actionWithIndexNumber);

int16_t putFileStrShortLocation(FlashHelper * helper, uint8_t shortLocationNumber);

void setup(void);

void adjustTo1Sec(void);

void printToSerialOutput(void);

void freeAll(HeapManagementHelper * heapHelper, FlashHelper * flshHelper, char * memoryString, char * formatString);

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
#define ERROR_STRING_LENGTH 19
const __attribute__((__progmem__)) char errorStringOnFlash[ERROR_STRING_LENGTH + 1] = "FATAL ERROR! Code: ";

void printToSerialOutput(void) {
    HeapManagementHelper * heapHelper = dOS_initHeapManagementHelper();
    if (heapHelper) {

        int16_t memoryAmount = heapHelper->getFreeMemory();
        char * memoryString = flashHelper->getOrPutDosMessage(FREE_MEMORY_STRING, 1, flashHelper);
        char * timestamp = ctime(NULL);
        char * formatString = flashHelper->getOrPutDosMessage(TIMESTAMP_STRING_NUMBER_LF_FORMATSTRING, 1, flashHelper);

        if (!(memoryString && flashHelper && timestamp && formatString)) {
            freeAll(heapHelper, flashHelper, memoryString, formatString);
            return;
        }

        printf(formatString, timestamp, memoryString, memoryAmount);

        putFileStrAction(flashHelper, 1);

        char * action2 = loadActionWithIndex(flashHelper, 2);
        if (action2) { printf("%s", action2); }
        free(action2);

        memoryAmount = heapHelper->getFreeMemory();
        printf(formatString, timestamp, memoryString, memoryAmount);

        putFileStrShortLocation(flashHelper, 1);
        memoryAmount = heapHelper->getFreeMemory();
        printf(formatString, timestamp, memoryString, memoryAmount);

        putFileStrAction(flashHelper, 51);
        memoryAmount = heapHelper->getFreeMemory();
        printf(formatString, timestamp, memoryString, memoryAmount);

        putFileStrAction(flashHelper, 142);
        memoryAmount = heapHelper->getFreeMemory();
        printf(formatString, timestamp, memoryString, memoryAmount);

        freeAll(heapHelper, flashHelper, memoryString, formatString);
    }
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

void freeAll(HeapManagementHelper * heapHelper, FlashHelper * flshHelper, char * memoryString, char * formatString) {
    free(heapHelper);
    free(flshHelper);
    free(memoryString);
    free(formatString);
}
#else
int main(void){};
#endif