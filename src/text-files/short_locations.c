//#include "short_locations.h"
#include <stdlib.h>
#include "dwarf-os/flash_helper.h"

#define SHORT_LOCATION_1_STRING_LENGTH 12
#define SHORT_LOCATION_2_STRING_LENGTH 52
#define SHORT_LOCATION_3_STRING_LENGTH 128
#define AMOUNT_SHORT_LOCATION_1_STRINGS 2
#define AMOUNT_SHORT_LOCATION_2_STRINGS 73
#define AMOUNT_SHORT_LOCATION_3_STRINGS 36
#define SHORT_LOCATION_1_INDEX_ARRAY_SIZE 13
#define SHORT_LOCATION_2_INDEX_ARRAY_SIZE 2
#define SHORT_LOCATION_3_INDEX_ARRAY_SIZE 14

typedef struct {
	uint8_t numbers[SHORT_LOCATION_1_INDEX_ARRAY_SIZE];
	char stringInProgramMem[SHORT_LOCATION_1_STRING_LENGTH];
} SHORT_LOCATION_1;

const __attribute__((__progmem__)) SHORT_LOCATION_1 shortLocations_1[AMOUNT_SHORT_LOCATION_1_STRINGS] = {
		{{31,},">$<\n"},
		{{46,47,48,54,56,58,63,81,82,85,86,114,140,},"Dead end.\n"},
};

typedef struct {
	uint8_t numbers[SHORT_LOCATION_2_INDEX_ARRAY_SIZE];
	char stringInProgramMem[SHORT_LOCATION_2_STRING_LENGTH];
} SHORT_LOCATION_2;

const __attribute__((__progmem__)) SHORT_LOCATION_2 shortLocations_2[AMOUNT_SHORT_LOCATION_2_STRINGS] = {
		{{1,},"You're at end of road again.\n"},
		{{2,},"You're at hill in road.\n"},
		{{3,},"You're inside building.\n"},
		{{4,},"You're in valley.\n"},
		{{5,6,},"You're in forest.\n"},
		{{7,},"You're at slit in streambed.\n"},
		{{8,},"You're outside grate.\n"},
		{{9,},"You're below the grate.\n"},
		{{10,},"You're in cobble crawl.\n"},
		{{11,},"You're in debris room.\n"},
		{{12,},"You are in an awkward sloping east/west canyon.\n"},
		{{13,},"You're in bird chamber.\n"},
		{{14,},"You're at top of small pit.\n"},
		{{15,},"You're in hall of mists.\n"},
		{{16,},"The crack is far too small for you to follow.\n"},
		{{17,},"You're on east bank of fissure.\n"},
		{{18,},"You're in nugget of gold room.\n"},
		{{19,},"You're in hall of mt. king.\n"},
		{{21,},"You didn't make it.\n"},
		{{22,},"The dome is unclimbable.\n"},
		{{23,},"You're at west end of twopit room.\n"},
		{{24,},"You're in east pit.\n"},
		{{25,},"You're in west pit.\n"},
		{{29,},"You are in the south side chamber.\n"},
		{{32,},"You can't get by the snake.\n"},
		{{33,},"You're at \"Y2\".\n"},
		{{35,110,},"You're at window on pit.\n"},
		{{36,},"You're in dirty passage.\n"},
		{{39,},"You're in dusty rock room.\n"},
		{{41,},"You're at west end of hall of mists.\n"},
		{{57,},"You're at brink of pit.\n"},
		{{60,},"You're at east end of long hall.\n"},
		{{61,},"You're at west end of long hall.\n"},
		{{64,},"You're at complex junction.\n"},
		{{66,},"You're in swiss cheese room.\n"},
		{{67,},"You're at east end of twopit room.\n"},
		{{68,},"You're in slab room.\n"},
		{{71,},"You're at junction of three secret canyons.\n"},
		{{73,},"Dead end crawl.\n"},
		{{74,},"You're at secret E/W canyon above tight canyon.\n"},
		{{88,},"You're in narrow corridor.\n"},
		{{90,},"You have climbed up the plant and out of the pit.\n"},
		{{91,},"You're at steep incline above large room.\n"},
		{{92,},"You're in giant room.\n"},
		{{93,},"The passage here is blocked by a recent cave-in.\n"},
		{{95,},"You're in cavern with waterfall.\n"},
		{{96,},"You're in soft room.\n"},
		{{97,},"You're in oriental room.\n"},
		{{98,},"You're in misty cavern.\n"},
		{{99,},"You're in alcove.\n"},
		{{100,},"You're in plover room.\n"},
		{{101,},"You're in dark-room.\n"},
		{{102,},"You're in arched hall.\n"},
		{{103,},"You're in shell room.\n"},
		{{105,},"You are in a cul-de-sac about eight feet across.\n"},
		{{106,},"You're in anteroom.\n"},
		{{108,},"You're at Witt's end.\n"},
		{{109,},"You're in mirror canyon.\n"},
		{{111,},"You're at top of stalactite.\n"},
		{{113,},"You're at reservoir.\n"},
		{{115,},"You're at ne end of repository.\n"},
		{{116,},"You're at sw end of repository.\n"},
		{{117,},"You're on sw side of chasm.\n"},
		{{118,},"You're in sloping corridor.\n"},
		{{122,},"You're on ne side of chasm.\n"},
		{{123,},"You're in corridor.\n"},
		{{124,},"You're at fork in path.\n"},
		{{125,},"You're at junction with warm walls.\n"},
		{{126,},"You're at breath-taking view.\n"},
		{{127,},"You're in chamber of boulders.\n"},
		{{128,},"You're in limestone passage.\n"},
		{{129,},"You're in front of barren room.\n"},
		{{130,},"You're in barren room.\n"},
};

typedef struct {
	uint8_t numbers[SHORT_LOCATION_3_INDEX_ARRAY_SIZE];
	char stringInProgramMem[SHORT_LOCATION_3_STRING_LENGTH];
} SHORT_LOCATION_3;

const __attribute__((__progmem__)) SHORT_LOCATION_3 shortLocations_3[AMOUNT_SHORT_LOCATION_3_STRINGS] = {
		{{20,},"You are the the bottom of the pit with a broken neck.\n"},
		{{26,},"You clamber up the plant and scurry through the hole at the\ntop.\n"},
		{{27,},"You are on the west side of the fissure in the hall of mists.\n"},
		{{28,},"You are in a low N/S passage at a hole in the floor.  The\nhole goes down to an E/W passage.\n"},
		{{30,},"You are in the west side chamber of the hall of the\nmountain king.  A passage continues west and up here.\n"},
		{{34,},"You are in a jumble of rock, with cracks everywhere.\n"},
		{{37,},"You are on the brink of a small clean climbable pit.  A\ncrawl leads west.\n"},
		{{38,},"You are in the bottom of a small pit with a little stream,\nwhich enters and exits through tiny slits.\n"},
		{{40,},"You have crawled through a very low wide passage parallel\nto and north of the hall of mists.\n"},
		{{42,43,44,45,49,50,51,52,53,55,80,83,84,87,},"You are in a maze of twisty little passages, all alike.\n"},
		{{59,},"You have crawled through a very low wide passage paralled\nto and north of the hall of mists.\n"},
		{{62,},"You are at a crossover of a high N/S passage and a low\nE/W one.\n"},
		{{65,},"You are in bedquilt, a long east/west passage with holes\neverywhere.  To explore at random select north, south, up\nor down.\n"},
		{{69,},"You are in a secret N/S canyon above a large room.\n"},
		{{70,},"You are in a secret N/S canyon above a sizable passage.\n"},
		{{72,},"You are in a large low room.  Crawls lead north, se, and sw.\n"},
		{{75,},"You are at a wide place in a very tight N/S canyon.\n"},
		{{76,},"The canyon here becomes too tight to go further south.\n"},
		{{77,},"You are in a tall E/W canyon.  A low tight crawl goes 3\nfeet north and seems to open up.\n"},
		{{78,},"The canyon runs into a mass of boulders -- dead end.\n"},
		{{79,},"The stream flows out through a pair of 1 foot diameter\nsewer pipes.  It would be advisable to use the exit.\n"},
		{{89,},"There is nothing here to climb.  Use \"up\" or \"out\" to leave\nthe pit.\n"},
		{{94,},"You are at one end of an immense north/south passage.\n"},
		{{104,},"You are in a long sloping corridor with ragged sharp walls.\n"},
		{{107,},"You are in a maze of twisty little passages, all different.\n"},
		{{112,},"You are in a little maze of twisting passages, all different.\n"},
		{{119,120,121,},"You are in a secret canyon which exits to the north and east.\n"},
		{{131,},"You are in a maze of twisting little passages, all different.\n"},
		{{132,},"You are in a little maze of twisty passages, all different.\n"},
		{{133,},"You are in a twisting maze of little passages, all different.\n"},
		{{134,},"You are in a twisting little maze of passages, all different.\n"},
		{{135,},"You are in a twisty little maze of passages, all different.\n"},
		{{136,},"You are in a twisty maze of little passages, all different.\n"},
		{{137,},"You are in a little twisty maze of passages, all different.\n"},
		{{138,},"You are in a maze of little twisting passages, all different.\n"},
		{{139,},"You are in a maze of little twisty passages, all different.\n"},
};


#define LOAD_FROM(NUM) \
	stringToReturn = helper->createFileString_P(&(TextFile) { \
		.pointerToArray = addressOf(shortLocations_##NUM), \
		.maxLengthOfStrings = SHORT_LOCATION_##NUM##_STRING_LENGTH, \
		.sizeOfIndexArray = SHORT_LOCATION_##NUM##_INDEX_ARRAY_SIZE, \
		.amountOfEntries = AMOUNT_SHORT_LOCATION_##NUM##_STRINGS, \
	}, shortLocationNumber, helper); \
	if (stringToReturn != NULL) { return stringToReturn; }

#define PUT_FROM(NUM) \
	if (helper->putFileString_P(&(TextFile) { \
		.pointerToArray =  addressOf(shortLocations_##NUM), \
		.maxLengthOfStrings = SHORT_LOCATION_##NUM##_STRING_LENGTH, \
		.sizeOfIndexArray = SHORT_LOCATION_##NUM##_INDEX_ARRAY_SIZE, \
		.amountOfEntries = AMOUNT_SHORT_LOCATION_##NUM##_STRINGS, \
	}, shortLocationNumber, helper) == 0) { return 0;}; \

char * loadShortLocation(FlashHelper * helper, uint8_t shortLocationNumber) {
	char * stringToReturn = NULL;

	LOAD_FROM(1)
	LOAD_FROM(2)
	LOAD_FROM(3)

	return stringToReturn;
}

int16_t putFileStrShortLocation(FlashHelper * helper, uint8_t shortLocationNumber) {
	PUT_FROM(1)
	PUT_FROM(2)
	PUT_FROM(3)

	return -1;
}

//getter function expects an initialized instance of FlashHelper as reachable global reference
//char * getShortLocation(int shortLocationNumber) {
//	return loadShortLocation(flashHelper, shortLocationNumber);
//}
////getter function expects an initialized instance of FlashHelper as reachable global reference
//char * putShortLocation(int shortLocationNumber) {
//	return putFileStrShortLocation(flashHelper, shortLocationNumber);
//}