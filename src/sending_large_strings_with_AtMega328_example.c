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

void setup(void);

void adjustTo1Sec(void);

void printToSerialOutput(void);

void freeAll(HeapManagementHelper * helper, FlashHelper * pHelper, char * memoryString, char * formatString);

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
#define LONG_LOCATION_126_STRING_LENGTH 1300
const __attribute__((__progmem__)) char longLocation_126[LONG_LOCATION_126_STRING_LENGTH] = "You are on the edge of a breath-taking view.  Far below you is an \nactive volcano, from which great gouts of molten lava come surging \nout, cascading back down into the depths. The glowing rock fills the \nfarthest reaches of the cavern with a blood-red glare, giving \neverything an eerie, macabre appearance.\nThe air is filled with flickering sparks of ash and a heavy smell of \nbrimstone.  The walls are hot to the touch, and the thundering of the \nvolcano drowns out all other sounds.  Embedded in the jagged roof far \noverhead are myriad formations composed of pure white alabaster, which \nscatter their murky light into sinister apparitions upon the walls.\nTo one side is a deep gorge, filled with a bizarre chaos of tortured \nrock which seems to have been crafted by the Devil Himself.  An \nimmense river of fire crashes out from the depths of the volcano, \nburns its way through the gorge, and plummets into a bottomless pit \nfar off to your left.  \nTo the right, an immense geyser of blistering steam erupts \ncontinuously from a barren island in the center of a sulfurous lake, \nwhich bubbles ominously. The far right wall is aflame with an \nincandescence of its own, which lends an additional infernal splendor \nto the already hellish scene.  \nA dark, foreboding passage exits to the south.\n";
#define ACTION_142_STRING_LENGTH 1430
const __attribute__((__progmem__)) char action_142[ACTION_142_STRING_LENGTH] = "If you want to end your adventure early, say \"quit\".  To suspend your \nadventure such that you can continue later say \"suspend\" (or \"pause\" \nor \"save\").  To load a previously saved game, say 'load' or 'restore'.  \nTo see how well you're doing, say \"score\".  To get full credit for a \ntreasure, you must have left it safely in the building, though you get \npartial credit just for locating it. You lose points for getting \nkilled, or for quitting, though the former costs you more. \nThere are also points based on how much (If any) of the cave you've \nmanaged to explore;  in particular, there is a large bonus just for \ngetting in (to distinguish the beginners from the rest of the pack), \nand there are other ways to determine whether you've been through some \nof the more harrowing sections. \nIf you think you've found all the treasures, just keep exploring for a \nwhile.  If nothing interesting happens, you haven't found them all \nyet.  If something interesting DOES happen, it means you're getting a \nbonus and have an opportunity to garner many more points in the \nmaster's section.\nI may occasionally offer hints in you seem to be having trouble.  If I \ndo, I'll warn you in advance how much it will affect your score to \naccept the hints.  Finally, to save paper, you may specify \"brief\", \nwhich tells me never to repeat the full description of a place unless \nyou explicitly ask me to.\n";


void printToSerialOutput(void) {
    HeapManagementHelper * heapHelper = dOS_initHeapManagementHelper();
    if (heapHelper) {
        int16_t memoryAmount = heapHelper->getFreeMemory();
        FlashHelper * flashHelper = dOS_initFlashHelper(0);
        char * memoryString = flashHelper->getOrPutDosMessage(FREE_MEMORY_STRING, 1, flashHelper);
        char * formatString = flashHelper->getOrPutDosMessage(TIMESTAMP_STRING_NUMBER_LF_FORMATSTRING, 1, flashHelper);


        if (!(memoryString && formatString && flashHelper)) {
            freeAll(heapHelper, flashHelper, memoryString, formatString);
            return;
        }
        if (lastTime % 2) {
            char * actionString = malloc(LONG_LOCATION_126_STRING_LENGTH + 1);
            flashHelper->copyString_P(actionString, addressOf(longLocation_126));
            printf("%s", actionString);
            free(actionString);
        } else {
            char * action2String = malloc(ACTION_142_STRING_LENGTH + 1);
            flashHelper->copyString_P(action2String, addressOf(action_142));
            printf("%s", action2String);
            free(action2String);
        }
        char * timestamp = ctime(NULL);
        printf("%s:%s%d\n", timestamp, memoryString, memoryAmount);
        freeAll(heapHelper, flashHelper, memoryString, formatString);
        free(timestamp);
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

void freeAll(HeapManagementHelper * helper, FlashHelper * pHelper, char * memoryString, char * formatString) {
    free(helper);
    free(pHelper);
    free(memoryString);
    free(formatString);
}