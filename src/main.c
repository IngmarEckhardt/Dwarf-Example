#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>

//DwarfOS
#include <setup.h>
#include <ascii_helper.h>
#include <mcu_clock.h>
#include <uart_helper.h>
#include <string_repository.h>
#include <heap_management_helper.h>
#include "time.h"

//the clock has states, instance it one time and hold a reference somewhere if you use it
McuClock * mcuClock;
// has states with its managed array, if you just want to load lazy strings with it, it's better to call the
// loadStringsFromFlash function in the string_storage directly, that also doesn't have a state
StringRepository * stringRepository;
//has no state, global reference here just for some convenience
UartHelper * uartHelper;

//not necessary with a watch quartz
volatile uint8_t adJust16MhzToSecond = 0;

// just for the example
uint8_t lastTime;

void adjustTo1Sec(void);

void testOSMethod(void);

int main(void) {

    // Example Setup with using all modules sending the address of these global pointers to the setup, let it instance
    // the modules and put a pointer to the these modules at the address it gets here
    setupMcu(&mcuClock, &stringRepository, &uartHelper);

    //global Interrupts on, could be moved to setup if you don't have other tasks before entering the loop
    sei();
    while (1) {

        sleep_mode();

        adjustTo1Sec();

        // for the example its enough to show you something every second, else we go immediately back to sleep
        if ((uint8_t)time(NULL) != lastTime) {
            lastTime = time(NULL);

            testOSMethod();
        }
    }
}

// This overflow interrupt is connected to counter 2, but counter 2 runs on the system clock
// for real time functionality you need a watch quartz at the TOSC1 and TOSC2 pins and change the setup to use it
ISR(TIMER2_OVF_vect) {
    adJust16MhzToSecond++;
}

// counter overflow in this setup is connected to system clock
// 16Mhz / (pre scaling 1024 x overflow interrupt 256 x 61) = ca 1.0001hz, good enough for logging
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

    // result 1868 byte, less than 200 byte consumed with the modules from setup, heap helper
    uint16_t memoryAmount = heapHelper->getFreeMemory();
    free(heapHelper);

    AsciiHelper * asciiHelper = dOS_initAsciiHelper();
    asciiHelper->integerToAscii(memoryStringArray, memoryAmount, 4, 0);
    free(asciiHelper);

    // you can find easily memory leaks if you make such a check at several places in your code
    uartHelper->sendMsgWithTimestamp(3, (char * []) {"free Memory is: ", memoryStringArray, " byte"});

    //need a small delay until we go to sleep, that the receiver can read the end of our message,
    // otherwise only \r is read not \n
    uartHelper->usartTransmitChar('\0');
}