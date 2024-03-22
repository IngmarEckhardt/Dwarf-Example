#ifndef __AVR_HAVE_ELPM__ // example dont uses far pointers, works only for devices with < 64kB

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
#include <dwarf-os/time.h>

#include "lorem_ipsum.h"

void setup(void);

void adjustTo1Sec(void);

void printToSerialOutput(void);

void freeAll(HeapManagementHelper * helper, FlashHelper * pHelper, char * memoryString, char * formatString,
             char * timeStamp);

McuClock * mcuClock;
UartHelper * uartHelper;

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


void printToSerialOutput(void) {
    HeapManagementHelper * heapHelper = dOS_initHeapManagementHelper();
    if (heapHelper) {
        int16_t memoryAmount = heapHelper->getFreeMemory(); // 1989
        FlashHelper * flashHelper = dOS_initFlashHelper(0);
        char * timestamp = ctime(NULL);
        char * memoryString = flashHelper->getOrPutDosMessage(FREE_MEMORY_STRING, 1, flashHelper);
        char * formatString = flashHelper->getOrPutDosMessage(TIMESTAMP_STRING_NUMBER_LF_FORMATSTRING, 1, flashHelper);

        if (!(memoryString && formatString && flashHelper && timestamp)) {
            freeAll(heapHelper, flashHelper, memoryString, formatString, timestamp);
            return;
        }
        printf(formatString, timestamp, memoryString, memoryAmount);

        //sending 25kB String with 2kB Ram, but without RAM Consumption at all (harvard architecture)
        puts_P(loremIpsum8);

        memoryAmount = heapHelper->getFreeMemory();
        printf(formatString, timestamp, memoryString, memoryAmount); //1981, costs us 8 byte on the stack this function because of the pointer references
        freeAll(heapHelper, flashHelper, memoryString, formatString, timestamp);
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
}
void freeAll(HeapManagementHelper * helper, FlashHelper * pHelper, char * memoryString, char * formatString,
             char * timeStamp) {
    free(helper);
    free(pHelper);
    free(memoryString);
    free(formatString);
    free(timeStamp);
}

#else
int main(void){};
#endif