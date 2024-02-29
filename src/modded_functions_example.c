#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>

//DwarfOS
#include <setup.h>
#include <ascii_helper.h>
#include <mcu_clock.h>
#include <uart_helper.h>
#include "time.h"
#include "heap_management_helper.h"

McuClock * mcuClock;
AsciiHelper * asciiHelper;
volatile uint8_t adJust16MhzToSecond = 0;
uint8_t lastTime;

void adjustTo1Sec(void);

void testOSMethod(void);

void moddedIntegerToAscii(char * result, uint32_t num, uint8_t size, uint8_t position);

int main(void) {

    setupMcu(&mcuClock);

    asciiHelper = dOS_initAsciiHelper();
    if (asciiHelper != NULL) {
        asciiHelper->integerToAscii = moddedIntegerToAscii;
    }


    sei();
    while (1) {
        sleep_mode();
        adjustTo1Sec();

        if ((uint8_t) time(NULL) != lastTime) {
            lastTime = time(NULL);
            testOSMethod();
        }
    }
}

ISR(TIMER2_OVF_vect) { adJust16MhzToSecond++; }

void adjustTo1Sec(void) {
    if (adJust16MhzToSecond == 61) {
        mcuClock->incrementClockOneSec();
        adJust16MhzToSecond = 0;
    }
}

void testOSMethod(void) {
    char memoryStringArray[5];
    memoryStringArray[4] = '\0';

    HeapManagementHelper * heapHelper = dOS_initHeapManagementHelper();
    uint16_t memoryAmount = heapHelper->getFreeMemory();
    free(heapHelper);

    asciiHelper->integerToAscii(memoryStringArray, memoryAmount, 4, 0);

    UartHelper * uartHelper = dOS_initUartHelper();
    uartHelper->sendMsgWithTimestamp(3, (char * []) {"free Memory is: ", memoryStringArray, "byte"});
    uartHelper->usartTransmitChar('\0');
    free(uartHelper);
}

void moddedIntegerToAscii(char * result, uint32_t num, uint8_t size, uint8_t position) {
    result[0] = (char)num;
    result[1] = size;
    result[2] = position;
    result[3] = 4;
}