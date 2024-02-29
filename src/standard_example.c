#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>

//DwarfOS
#include <setup.h>
#include <ascii_helper.h>
#include <mcu_clock.h>
#include <uart_helper.h>
#include <heap_management_helper.h>
#include "time.h"

McuClock * mcuClock;
volatile uint8_t adJust16MhzToSecond = 0;
uint8_t lastTime;

void adjustTo1Sec(void);

void testOSMethod(void);

int main(void) {

    setupMcu(&mcuClock);
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

    AsciiHelper * asciiHelper = dOS_initAsciiHelper();
    asciiHelper->integerToAscii(memoryStringArray, memoryAmount, 4, 0);
    free(asciiHelper);

    UartHelper * uartHelper = dOS_initUartHelper();
    uartHelper->sendMsgWithTimestamp(3, (char * []) {"free Memory is: ", memoryStringArray, "byte"});
    uartHelper->usartTransmitChar('\0');
    free(uartHelper);
}