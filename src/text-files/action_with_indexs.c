//#include "action_with_indexs.h"
#include <stdlib.h>
#include "dwarf-os/flash_helper.h"

#define ACTION_WITH_INDEX_1_STRING_LENGTH 52
#define ACTION_WITH_INDEX_2_STRING_LENGTH 237
#define ACTION_WITH_INDEX_3_STRING_LENGTH 500
#define AMOUNT_ACTION_WITH_INDEX_1_STRINGS 92
#define AMOUNT_ACTION_WITH_INDEX_2_STRINGS 99
#define AMOUNT_ACTION_WITH_INDEX_3_STRINGS 5
#define ACTION_WITH_INDEX_1_INDEX_ARRAY_SIZE 4
#define ACTION_WITH_INDEX_2_INDEX_ARRAY_SIZE 1
#define ACTION_WITH_INDEX_3_INDEX_ARRAY_SIZE 1

typedef struct {
	uint8_t numbers[ACTION_WITH_INDEX_1_INDEX_ARRAY_SIZE];
	char stringInProgramMem[ACTION_WITH_INDEX_1_STRING_LENGTH];
} ACTION_WITH_INDEX_1;

const __attribute__((__progmem__)) ACTION_WITH_INDEX_1 actionWithIndexs_1[AMOUNT_ACTION_WITH_INDEX_1_STRINGS] = {
		{{2,},"A little dwarf with a big knife blocks your way.\n"},
		{{5,},"One sharp, nasty knife is thrown at you!\n"},
		{{6,},"None of them hit you!\n"},
		{{7,},"One of them gets you!\n"},
		{{8,},"A hollow voice says \"Plugh\".\n"},
		{{9,},"There is no way to go that direction.\n"},
		{{12,},"I don't know how to apply that word here.\n"},
		{{13,},"I don't understand that!\n"},
		{{14,},"I'm game.  Would you care to explain how?\n"},
		{{17,},"If you prefer, simply type W rather than West.\n"},
		{{18,},"Are you trying to catch the bird?\n"},
		{{20,},"Are you trying to somehow deal with the snake?\n"},
		{{22,},"Do you really want to quit now?\n"},
		{{24,},"You are already carrying it!\n"},
		{{25,},"You can't be serious!\n"},
		{{27,},"You can catch the bird, but you cannot carry it.\n"},
		{{28,},"There is nothing here with a lock!\n"},
		{{29,},"You aren't carrying it!\n"},
		{{31,},"You have no keys!\n"},
		{{32,},"It has no lock.\n"},
		{{33,},"I don't know how to lock or unlock such a thing.\n"},
		{{34,},"It was already locked.\n"},
		{{35,},"The grate is now locked.\n"},
		{{36,},"The grate is now unlocked.\n"},
		{{37,},"It was already unlocked.\n"},
		{{38,},"You have no source of light.\n"},
		{{39,},"Your lamp is now on.\n"},
		{{40,},"Your lamp is now off.\n"},
		{{42,},"Nothing happens.\n"},
		{{43,},"Where?\n"},
		{{44,},"There is nothing here to attack.\n"},
		{{47,},"You killed a little dwarf.\n"},
		{{49,},"With what? Your bare hands?\n"},
		{{50,},"Good try, but that is an old worn-out magic word.\n"},
		{{52,},"It misses!\n"},
		{{53,},"It gets you!\n"},
		{{54,},"OK\n"},
		{{55,},"You can't unlock the keys.\n"},
		{{58,},"I need more detailed instructions to do that.\n"},
		{{60,},"I don't know that word.\n"},
		{{61,},"What?\n"},
		{{62,},"Are you trying to get into the cave?\n"},
		{{67,},"Blasting requires dynamite.\n"},
		{{68,},"I'm as confused as you are.\n"},
		{{70,},"Your feet are now wet.\n"},
		{{71,},"I think I just lost my appetite.\n"},
		{{72,},"Thank you.  It was delicious!\n"},
		{{74,},"The bottle of water is now empty.\n"},
		{{76,},"Peculiar.  Nothing unexpected happens.\n"},
		{{77,},"Your bottle is empty and the ground is wet.\n"},
		{{78,},"You can't pour that.\n"},
		{{79,},"Watch it!\n"},
		{{80,},"Which way?\n"},
		{{87,88,89,90,},"Reserved\n"},
		{{93,},"You can't go through a locked steel grate!\n"},
		{{94,},"I believe what you want is right here with you.\n"},
		{{95,},"You don't fit through a two-inch slit!\n"},
		{{97,},"There is no way across the fissure.\n"},
		{{98,},"You're not carrying anything.\n"},
		{{99,},"You are currently holding the following:\n"},
		{{101,},"The snake has now devoured your bird.\n"},
		{{104,},"You have nothing in which to carry it.\n"},
		{{105,},"Your bottle is already full.\n"},
		{{107,},"Your bottle is now full of water.\n"},
		{{108,},"Your bottle is now full of oil.\n"},
		{{109,},"You can't fill that.\n"},
		{{110,},"Don't be ridiculous!\n"},
		{{111,},"The door is extremely rusty and refuses to open.\n"},
		{{137,},"Oh, leave the poor unhappy bird alone.\n"},
		{{140,},"You can't get there from here.\n"},
		{{143,},"Do you indeed wish to quit now?\n"},
		{{146,},"It is beyond your power to do that.\n"},
		{{147,},"I don't know how.\n"},
		{{148,},"It is too far up for you to reach.\n"},
		{{155,},"On what?\n"},
		{{160,},"The troll refuses to let you cross.\n"},
		{{161,},"There is no longer any way across the chasm.\n"},
		{{169,},"The bear is still chained to the wall.\n"},
		{{170,},"The chain is still locked.\n"},
		{{171,},"The chain is now unlocked.\n"},
		{{172,},"The chain is now locked.\n"},
		{{174,},"There is nothing here to eat.\n"},
		{{175,},"Do you want the hint?\n"},
		{{176,},"Do you need help getting out of the maze?\n"},
		{{178,},"Are you trying to explore beyond the plover room?\n"},
		{{180,},"Do you need help getting out of here?\n"},
		{{181,},"Don't go west.\n"},
		{{184,},"Your lamp has run out of power.\n"},
		{{190,},"I'm afraid the magazine is written in Dwarvish.\n"},
		{{194,},"It says the same thing it did before.\n"},
		{{195,},"I'm afraid I don't understand.\n"},
		{{200,},"Is this acceptable?\n"},
};

typedef struct {
	uint8_t numbers[ACTION_WITH_INDEX_2_INDEX_ARRAY_SIZE];
	char stringInProgramMem[ACTION_WITH_INDEX_2_STRING_LENGTH];
} ACTION_WITH_INDEX_2;

const __attribute__((__progmem__)) ACTION_WITH_INDEX_2 actionWithIndexs_2[AMOUNT_ACTION_WITH_INDEX_2_STRINGS] = {
		{{3,},"A little dwarf just walked around a corner, saw you,\nthrew a little axe at you which missed, cursed, and ran away.\n"},
		{{4,},"There is a threatening little dwarf in the room with you!\n"},
		{{10,},"I am unsure how you are facing.  Use compass points or\nnearby objects.\n"},
		{{11,},"I don't know in from out here.  Use compass points or name\nsomething in the general direction you want to go.\n"},
		{{15,},"Sorry, but I am not allowed to give more detail.  I will\nrepeat the long description of your location.\n"},
		{{16,},"It is now pitch dark.  If you proceed you will likely fall\ninto a pit.\n"},
		{{19,},"The bird is frightened right now and you cannot catch\nit no matter what you try.  Perhaps you might try later.\n"},
		{{21,},"You can't kill the snake, or drive it away, or avoid it,\nor anything like that.  There is a way to get by, but you\ndon't have the necessary resources right now.\n"},
		{{23,},"You fell into a pit and broke every bone in your body!\n"},
		{{26,},"The bird was unafraid when you entered, but as you approach\nit becomes disturbed and you cannot catch it.\n"},
		{{30,},"The little bird attacks the green snake, and in an\nastounding flurry drives the snake away.\n"},
		{{41,},"There is no way to get past the bear to unlock the chain,_\nwhich is probably just as well.\n"},
		{{45,},"The little bird is now dead.  Its body disappears.\n"},
		{{46,},"Attacking the snake both doesn't work and is very dangerous.\n"},
		{{48,},"You attack a little dwarf, but he dodges out of the way.\n"},
		{{56,},"You have crawled around in some little holes and wound up\nback in the main passage.\n"},
		{{57,},"I don't know where the cave is, but hereabouts no stream\ncan run on the surface for very long.  I would try the stream.\n"},
		{{59,},"I can only tell you what you see as you move about and\nmanipulate things.  I cannot tell you where remote things are.\n"},
		{{63,},"The grate is very solid and has a hardened steel lock.  You\ncannot enter without a key, and there are no keys nearby.\nI would recommend looking elsewhere for the keys.\n"},
		{{66,},"Digging without a shovel is quite impractical.  Even with a\nshovel progress is unlikely.\n"},
		{{69,},"Mist is a white vapor, usually water.  Seen from time to time\nin caverns.  It can be found anywhere but is frequently a\nsign of a deep pit leading down to water.\n"},
		{{73,},"You have taken a drink from the stream.  The water tastes\nstrongly of minerals, but is not unpleasant.  It is extremely\ncold.\n"},
		{{75,},"Rubbing the electric lamp is not particularly rewarding.\nAnyway, nothing exciting happens.\n"},
		{{81,},"Oh dear, you seem to have gotten yourself killed.  I might\nbe able to help you out, but I've never really done this\nbefore.  Do you want me to try to reincarnate you?\n"},
		{{82,},"All right.  But don't blame me if something goes wr......\n                    --- POOF !! ---\nYou are engulfed in a cloud of orange smoke.  Coughing and\ngasping, you emerge from the smoke and find...\n"},
		{{83,},"You clumsy oaf, you've done it again!  I don't know how long\nI can keep this up.  Do you want me to try reincarnating\nyou again?\n"},
		{{84,},"Okay, now where did I put my orange smoke? ... > POOF! <\nEverything disappears in a dense cloud of orange smoke.\n"},
		{{85,},"Now you've really done it!  I'm out of orange smoke!  You\ndon't expect me to do a decent reincarnation without any\norange smoke, do you?\n"},
		{{86,},"Okay, If you're so smart, do it yourself!  I'm leaving!\n"},
		{{91,},"Sorry, but I no longer seem to remember how it was you\ngot here.\n"},
		{{92,},"You can't carry anything more.  You'll have to drop something\nfirst.\n"},
		{{96,},"I respectfully suggest you go across the bridge instead\nof jumping.\n"},
		{{100,},"It's not hungry (It's merely pinin' for the Fjords).  Besides\nYou have no bird seed.\n"},
		{{102,},"There's nothing here it wants to eat (Except perhaps you).\n"},
		{{103,},"You fool, Dwarves eat only coal!  Now you've made\nhim REALLY mad !!\n"},
		{{106,},"There is nothing here with which to fill the bottle.\n"},
		{{112,},"The plant indignantly shakes the oil off its leaves and asks:\n\"Water?\".\n"},
		{{113,},"The hinges are quite thoroughly rusted now and won't budge.\n"},
		{{114,},"The oil has freed up the hinges so that the door will now move,\nalthough it requires some effort.\n"},
		{{115,},"The plant has exceptionally deep roots and cannot be pulled free.\n"},
		{{116,},"The Dwarves' knives vanish as they strike the walls of the cave.\n"},
		{{117,},"Something you're carrying won't fit through the tunnel with\nyou.  You'd best take inventory and drop something.\n"},
		{{118,},"You can't fit this five-foot clam through that little passage!\n"},
		{{119,},"You can't fit this five foot oyster through that little passage!\n"},
		{{120,},"I advise you to put down the clam before opening it. >STRAIN!<\n"},
		{{121,},"I advise you to put down the oyster before opening it.\n>WRENCH!<\n"},
		{{122,},"You don't have anything strong enough to open the clam.\n"},
		{{123,},"You don't have anything strong enough to open the oyster.\n"},
		{{124,},"A glistening pearl falls out of the clam and rolls away.\nGoodness, this must really be an oyster.  (I never was\nvery good at identifying bivalves.)  Whatever it is,\nit has now snapped shut again.\n"},
		{{125,},"The oyster creaks open, revealing nothing but oyster inside.\nIt promptly snaps shut again.\n"},
		{{126,},"You have crawled around in some little holes and found your\nway blocked by a recent cave-in.  You are now back in the\nmain passage.\n"},
		{{127,},"There are faint rustling noises from the darkness behind\nyou.\n"},
		{{128,},"Out from the shadows behind you pounces a bearded pirate!\n\"Har, har\" he chortles, \"I'll just take all this booty and\nhide it away with me chest deep in the maze!\".  He snatches\nyour treasure and vanishes into the gloom.\n"},
		{{129,},"A sepulchral voice reverberating through the cave says:\n\"Cave closing soon.  All adventurers exit immediately\nthrough main office.\"\n"},
		{{130,},"A mysterious recorded voice groans into life and announces:\n\"This exit is closed.  Please leave via main office.\"\n"},
		{{131,},"It looks as though you're dead.  Well, seeing as how it's so\nclose to closing time anyway, I think we'll just call it a day.\n"},
		{{132,},"The sepulchral voice entones, \"The cave is now closed.\"  As\nthe echoes fade, there is a blinding flash of light (and a\nsmall puff of orange smoke). . . . \nAs your eyes refocus you look around and find...\n"},
		{{134,},"There is a loud explosion, and a twenty-foot hole appears in\nthe far wall, burying the snakes in the rubble.  A river of\nmolten lava pours in through the hole, destroying\neverything in its path, including you!!\n"},
		{{135,},"There is a loud explosion, and you are suddenly splashed across\nthe walls of the room.\n"},
		{{136,},"The resulting ruckus has awakened the Dwarves.  There are now\nseveral threatening little Dwarves in the room with you!\nMost of them throw knives at you!  All of them get you!\n"},
		{{138,},"I daresay whatever you want is around here somewhere.\n"},
		{{139,},"I don't know the word \"stop\".   Use \"quit\" if you want to\ngive up.\n"},
		{{141,},"You are being followed by a very large, tame bear.\n"},
		{{144,},"There is nothing here with which to fill the vase.\n"},
		{{145,},"The sudden change in temperature has delicately shattered\nthe vase.\n"},
		{{149,},"You killed a little Dwarf.  The body vanished in a cloud\nof greasy black smoke.\n"},
		{{150,},"The shell is very strong and impervious to attack.\n"},
		{{151,},"What's the matter, can't you read?  Now you'd best start\nover.\n"},
		{{152,},"The axe bounces harmlessly off the dragon's thick scales.\n"},
		{{153,},"The dragon looks rather nasty.  You'd best not try to get by.\n"},
		{{154,},"The little bird attacks the green dragon, and in an\nastounding flurry gets burnt to a cinder.  The ashes blow away.\n"},
		{{156,},"Okay, from now on I'll only describe a place in full the\nfirst time you come to it.  To get the full description\nsay \"look\".\n"},
		{{157,},"Trolls are close relatives with the rocks and have skin as\ntough as that of a rhinoceros.  The troll fends off your\nblows effortlessly.\n"},
		{{158,},"The troll deftly catches the axe, examines it carefully,\nand tosses it back, declaring, \"Good workmanship,\nbut it's not valuable enough.\".\n"},
		{{159,},"The troll catches your treasure and scurries away out of sight.\n"},
		{{162,},"Just as you reach the other side, the bridge buckles beneath\nthe weight of the bear, which was still following you around.\nYou scrabble desperately for support, but as the bridge \ncollapses you stumble back and fall into the chasm.\n"},
		{{163,},"The bear lumbers toward the troll, who lets out a\nstartled shriek and scurries away.  The bear soon gives\nup pursuit and wanders back.\n"},
		{{164,},"The axe misses and lands near the bear where you can't get\nat it.\n"},
		{{165,},"With what?  Your bare hands?  Against HIS bear hands??\n"},
		{{166,},"The bear is confused;  he only wants to be your friend.\n"},
		{{167,},"For crying out loud, the poor thing is already dead!\n"},
		{{168,},"The bear eagerly wolfs down your food, after which he seems\nto calm down considerably, and even becomes rather friendly.\n"},
		{{173,},"There is nothing here to which the chain can be locked.\n"},
		{{177,},"You can make the passages look less alike by dropping things.\n"},
		{{179,},"There is a way to explore that region without having to\nworry about falling into a pit.  None of the objects\navailable is immediately useful in descovering the secret.\n"},
		{{182,},"Gluttony is not one of the Troll's vices.  Avarice, however, is.\n"},
		{{183,},"Your lamp is getting dim.. You'd best start wrapping this up,\nunless you can find some fresh batteries.  I seem to recall\nthere's a vending machine in the maze.  Bring some coins\nwith you.\n"},
		{{185,},"There's not much point in wandering around out here, and you\ncan't explore the cave without a lamp.  So let's just call\nit a day.\n"},
		{{187,},"Your lamp is getting dim.  You'd best go back for\nthose batteries.\n"},
		{{188,},"Your lamp is getting dim.. I'm taking the liberty of replacing\nthe batteries.\n"},
		{{189,},"Your lamp is getting dim, and you're out of spare batteries.\nYou'd best start wrapping this up.\n"},
		{{191,},"\"This is not the maze where the pirate leaves his treasure\nchest.\"\n"},
		{{192,},"Hmm, this looks like a clue, which means it'll cost you 10\npoints to read it.  Should I go ahead and read it anyway?\n"},
		{{193,},"It says, \"There is something strange about this place,\nsuch that one of the words I've always known now has\na new effect.\"\n"},
		{{196,},"\"Congratulations on bringing light into the dark-room!\"\n"},
		{{197,},"You strike the mirror a resounding blow, whereupon it\nshatters into a myriad tiny fragments.\n"},
		{{198,},"You have taken the vase and hurled it delicately to the\nground.\n"},
		{{199,},"You prod the nearest Dwarf, who wakes up grumpily, takes\none look at you, curses, and grabs for his axe.\n"},
		{{201,},"There's no point in suspending a demonstration game.\n"},
};

typedef struct {
	uint8_t numbers[ACTION_WITH_INDEX_3_INDEX_ARRAY_SIZE];
	char stringInProgramMem[ACTION_WITH_INDEX_3_STRING_LENGTH];
} ACTION_WITH_INDEX_3;

const __attribute__((__progmem__)) ACTION_WITH_INDEX_3 actionWithIndexs_3[AMOUNT_ACTION_WITH_INDEX_3_STRINGS] = {
		{{1,},"Somewhere nearby is Colossal Cave, where others have found fortunes in \ntreasure and gold, though it is rumored that some who enter are never \nseen again.  Magic is said to work in the cave.  I will be your eyes \nand hands.  Direct me with commands of 1 or 2 words.  I should warn \nyou that I look at only the first five letters of each word, so you'll \nhave to enter \"Northeast\" as \"ne\" to distinguish it from \"North\".  \n(Should you get stuck, type \"help\" for some general hints).\n\n"},
		{{64,},"The trees of the forest are large hardwood oak and maple,\nwith an occasional grove of pine or spruce.  There is quite\na bit of undergrowth, largely birch and ash saplings plus\nnondescript bushes of various sorts.  This time of year \nvisibility is quite restricted by all the leaves, but travel\nis quite easy if you detour around the spruce and berry\nbushes.\n"},
		{{65,},"\n                              Welcome to \n\n                       Colossal Cave Adventure!\n\n\n               Original development by Willie Crowther.\n                  Major features added by Don Woods.\n                 Conversion to BDS C by J. R. Jaeger.\n                Unix standardization by Jerry D. Pohl.\n            Port to QNX 4 and bug fixes by James Lummel.\n\nWould you like instructions?\n\n"},
		{{133,},"There is a loud explosion, and a twenty-foot hole appears in\nthe far wall, burying the Dwarves in the rubble.  You march\nthrough the hole and find yourself in the main office, where\na cheering band of friendly elves carry the conquering\nadventurer off into the sunset.\n"},
		{{186,},"There are faint rustling noises from the darkness behind you.\nAs you turn toward them, the beam of your lamp falls across a\nbearded pirate.  He is carrying a large chest.  \"Shiver me\ntimbers!\"  he cries, \"I've been spotted!  I'd best hide\nmeself off to the maze and hide me chest!\".  With that,\nhe vanished into the gloom.\n"},
};

#define ACTION_WITH_INDEX_51_STRING_LENGTH 1337
const __attribute__((__progmem__)) char actionWithIndex_51[ACTION_WITH_INDEX_51_STRING_LENGTH] = "I know of places, actions, and things.  Most of my vocabulary \ndescribes places and is used to move you there.  To move, try words \nlike forest, building, downstream, enter, east, west, north, south, up \nor down.  \nI know about a few special objects, like a black rod hidden in the \ncave.  These objects can be manipulated using some of the action words \nI know. Usually you will need to give both the object and action words \n(In either order), but sometimes I can infer the object from the verb \nalone.  Some objects also imply verbs; in particular, \"inventory\" \nimplies \"take inventory\", which causes me to give you a list of what \nyou're carrying.\nThe objects have side effects; for instance, the rod scares the bird. \nUsually people having trouble moving just need to try a few more \nwords.  Usually people trying unsuccessfully to manipulate an object \nare attempting something beyond their (or my!) capabilities and should \ntry a completely different tack.\nTo speed the game up, you can sometimes move long distances with a \nsingle word.  For example, \"building\" usually gets you to the building \nfrom anywhere above ground except when lost in the forest.  Also, note \nthat cave passages turn a lot, and that leaving a room to the north \ndoes not guarantee entering the next from the south. Good luck!\n";

#define ACTION_WITH_INDEX_142_STRING_LENGTH 1430
const __attribute__((__progmem__)) char actionWithIndex_142[ACTION_WITH_INDEX_142_STRING_LENGTH] = "If you want to end your adventure early, say \"quit\".  To suspend your \nadventure such that you can continue later say \"suspend\" (or \"pause\" \nor \"save\").  To load a previously saved game, say 'load' or 'restore'.  \nTo see how well you're doing, say \"score\".  To get full credit for a \ntreasure, you must have left it safely in the building, though you get \npartial credit just for locating it. You lose points for getting \nkilled, or for quitting, though the former costs you more. \nThere are also points based on how much (If any) of the cave you've \nmanaged to explore;  in particular, there is a large bonus just for \ngetting in (to distinguish the beginners from the rest of the pack), \nand there are other ways to determine whether you've been through some \nof the more harrowing sections. \nIf you think you've found all the treasures, just keep exploring for a \nwhile.  If nothing interesting happens, you haven't found them all \nyet.  If something interesting DOES happen, it means you're getting a \nbonus and have an opportunity to garner many more points in the \nmaster's section.\nI may occasionally offer hints in you seem to be having trouble.  If I \ndo, I'll warn you in advance how much it will affect your score to \naccept the hints.  Finally, to save paper, you may specify \"brief\", \nwhich tells me never to repeat the full description of a place unless \nyou explicitly ask me to.\n";


#define LOAD_FROM(NUM) \
	stringToReturn = helper->createFileString_P(&(TextFile) { \
		.pointerToArray = addressOf(actionWithIndexs_##NUM), \
		.maxLengthOfStrings = ACTION_WITH_INDEX_##NUM##_STRING_LENGTH, \
		.sizeOfIndexArray = ACTION_WITH_INDEX_##NUM##_INDEX_ARRAY_SIZE, \
		.amountOfEntries = AMOUNT_ACTION_WITH_INDEX_##NUM##_STRINGS, \
	}, actionWithIndexNumber, helper); \
	if (stringToReturn != NULL) { return stringToReturn; }

#define PUT_FROM(NUM) \
	if (helper->putFileString_P(&(TextFile) { \
		.pointerToArray =  addressOf(actionWithIndexs_##NUM), \
		.maxLengthOfStrings = ACTION_WITH_INDEX_##NUM##_STRING_LENGTH, \
		.sizeOfIndexArray = ACTION_WITH_INDEX_##NUM##_INDEX_ARRAY_SIZE, \
		.amountOfEntries = AMOUNT_ACTION_WITH_INDEX_##NUM##_STRINGS, \
	}, actionWithIndexNumber, helper) == 0) { return 0;}; \

char * loadActionWithIndex(FlashHelper * helper, uint8_t actionWithIndexNumber) {
	char * stringToReturn = NULL;

	if (actionWithIndexNumber == 51) {
		stringToReturn = (char *) malloc(ACTION_WITH_INDEX_51_STRING_LENGTH);
		helper->copyString_P(stringToReturn,  addressOf(actionWithIndex_51));
	}
	if (actionWithIndexNumber == 142) {
		stringToReturn = (char *) malloc(ACTION_WITH_INDEX_142_STRING_LENGTH);
		helper->copyString_P(stringToReturn,  addressOf(actionWithIndex_142));
	}
	LOAD_FROM(1)
	LOAD_FROM(2)
	LOAD_FROM(3)

	return stringToReturn;
}

int16_t putFileStrActionWithIndex(FlashHelper * helper, uint8_t actionWithIndexNumber) {
	if (actionWithIndexNumber == 51) {
		return helper->putString_P(addressOf(actionWithIndex_51));
	}
	if (actionWithIndexNumber == 142) {
		return helper->putString_P(addressOf(actionWithIndex_142));
	}
	PUT_FROM(1)
	PUT_FROM(2)
	PUT_FROM(3)

	return -1;
}

//getter function expects an initialized instance of FlashHelper as reachable global reference
//char * getActionWithIndex(int actionWithIndexNumber) {
//	return loadActionWithIndex(flashHelper, actionWithIndexNumber);
//}
////getter function expects an initialized instance of FlashHelper as reachable global reference
//char * putActionWithIndex(int actionWithIndexNumber) {
//	return putFileStrActionWithIndex(flashHelper, actionWithIndexNumber);
//}