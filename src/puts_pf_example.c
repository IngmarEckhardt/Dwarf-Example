#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <avr/pgmspace.h>

//DwarfOS
#include <setup.h>
#include <mcu_clock.h>
#include <uart_helper.h>
#include <flash_helper.h>
#include <heap_management_helper.h>
#include <time.h>

#include "lorem_ipsum.h"

void setup(void);

void adjustTo1Sec(void);

void printToSerialOutput(void);

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

// example placement of string in Progmem
#define MEMORY_STRING_LENGTH 26
const __attribute__((__progmem__)) char memoryStringOnFlash[MEMORY_STRING_LENGTH] = ": free Memory is (byte): ";

int16_t puts_PF(uint32_t farPointerToString) {//Should be possible to check if this is a far pointer with a flag-bit
    char charToPut = 0;
    while ((charToPut = (char) pgm_read_byte_far(farPointerToString))) {
        if ((stdout->flags & __SWR) != 0) {
            if ((stdout->put(charToPut, stdout) != 0)) {
                return EOF;
            } else {
                farPointerToString++;
            }
        }
    }
    return 0;
}

const char formatStr[] = "%s:%s%d\n";
void printToSerialOutput(void) {
    HeapManagementHelper * heapHelper = dOS_initHeapManagementHelper();
    if (heapHelper) {
        int16_t memoryAmount = heapHelper->getFreeMemory();

        char * memoryString = malloc(MEMORY_STRING_LENGTH + 1);
        FlashHelper * flashHelper = dOS_initFlashHelper();
        char * timestamp = ctime(NULL);

        if (memoryString && flashHelper && timestamp) {
            // getting the near string isn't really safe with progmem usage way beyond 64kb, seem the placement from executables is prior to headers, we are very lucky
            flashHelper->loadNearStringFromFlash(memoryString, memoryStringOnFlash);
            printf(formatStr, timestamp, memoryString, memoryAmount);

            //32kB each string
            puts_PF(pgm_get_far_address(loremIpsum1));
            //no changes in the situation behind this first check
            memoryAmount = heapHelper->getFreeMemory();
            printf(formatStr, timestamp, memoryString, memoryAmount);

            puts_PF(pgm_get_far_address(loremIpsum2));
            puts_PF(pgm_get_far_address(loremIpsum3));
            puts_PF(pgm_get_far_address(loremIpsum4));
            puts_PF(pgm_get_far_address(loremIpsum5));
            puts_PF(pgm_get_far_address(loremIpsum6));
            puts_PF(pgm_get_far_address(loremIpsum7));

            // still no changes, but why not, we check again
            memoryAmount = heapHelper->getFreeMemory();
            printf(formatStr, timestamp, memoryString, memoryAmount);


        }
        free(timestamp);
        free(flashHelper);
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
}