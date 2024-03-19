#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>

//DwarfOS
#include <setup.h>
#include <mcu_clock.h>
#include <uart_helper.h>
#include <heap_management_helper.h>
#include <time.h>
#include <input_queue.h>

void setup(void);

void adjustTo1Sec(void);

void putIntoQueue(uint8_t item);

void printToSerialOutput(void);

McuClock * mcuClock;
InputQueue * inputQueue;
UartHelper * uartHelper;
HeapManagementHelper * heapHelper;

#define STRING_BUFFER_SIZE 255
const uint8_t adjustToSecondValue = ADJUST_TO_SECOND_VALUE;
uint8_t lastTime;
char * stringReadFromUser;
char * timestamp;
volatile uint8_t adjustCounter;
uint8_t lastTime;


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

// every time a new char is received, the interrupt is triggered and the char is put into the queue
ISR(USART_RX_vect) { putIntoQueue(UDR0); }

void printToSerialOutput(void) {
    stringReadFromUser[0] = '\0';   // clearing the string

    printf("Please Enter a text and send \\n at the end:\n(this inputqueue is blocking as a normal terminal stdin)\n");

    // CAVE: if the user don't send a \n over the serial as line feed, null termination of string with fgets won't work
    fgets(stringReadFromUser, STRING_BUFFER_SIZE, stdin); // lore ipsum 36 words fits into the input queue
    timestamp = ctime(NULL);

    if (*stringReadFromUser) { printf("%s: you entered: %s\n", timestamp, stringReadFromUser); }
    printf("%s: free Memory is: %d byte\n", timestamp, heapHelper->getFreeMemory());
    free(timestamp);
}

void adjustTo1Sec(void) {
    if (adjustCounter == adjustToSecondValue) {
        mcuClock->incrementClockOneSec();
        adjustCounter = 0;
    }
}

// StdIn - Buffer inflow
void putIntoQueue(uint8_t item) {
    inputQueue->enqueue(item, inputQueue);
}

// StdIn - Buffer outflow
int get_char(FILE * stream) {
    int16_t c = inputQueue->get_char(inputQueue);
    return c;
}

// StdOut, has no buffer in this implementation, could also be done with a interrupt driven routine and a buffer
int put_char(char c, FILE * stream) {
    uartHelper->usartTransmitChar(c);
    return 0;
}

static FILE myStdOut = FDEV_SETUP_STREAM(put_char, NULL, _FDEV_SETUP_WRITE);
static FILE myStdIn = FDEV_SETUP_STREAM(NULL, get_char, _FDEV_SETUP_READ);

void setup(void) {
    setupMcu(&mcuClock); // general setup DwarfOS

    uartHelper = dOS_initUartHelper();
    inputQueue = dOS_initInputQueue();
    heapHelper = dOS_initHeapManagementHelper();
    stdin = &myStdIn;
    stdout = &myStdOut;

    stringReadFromUser = malloc(STRING_BUFFER_SIZE * sizeof(char));

    // Enable receiver and transmitter and Interrupt additionally
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
}