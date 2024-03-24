//#include "actions.h"
#include <stdlib.h>
#include "dwarf-os/flash_helper.h"

#define ACTION_1_STRING_LENGTH 52
#define ACTION_2_STRING_LENGTH 237
#define ACTION_3_STRING_LENGTH 500
#define AMOUNT_ACTION_1_STRINGS 92
#define AMOUNT_ACTION_2_STRINGS 99
#define AMOUNT_ACTION_3_STRINGS 5

typedef struct {
	char stringInProgramMem[ACTION_1_STRING_LENGTH];
} ACTION_1;

const __attribute__((__progmem__)) ACTION_1 actions_1[AMOUNT_ACTION_1_STRINGS] = {
		{"A little dwarf with a big knife blocks your way.\n"},
		{"One sharp, nasty knife is thrown at you!\n"},
		{"None of them hit you!\n"},
		{"One of them gets you!\n"},
		{"A hollow voice says \"Plugh\".\n"},
		{"There is no way to go that direction.\n"},
		{"I don't know how to apply that word here.\n"},
		{"I don't understand that!\n"},
		{"I'm game.  Would you care to explain how?\n"},
		{"If you prefer, simply type W rather than West.\n"},
		{"Are you trying to catch the bird?\n"},
		{"Are you trying to somehow deal with the snake?\n"},
		{"Do you really want to quit now?\n"},
		{"You are already carrying it!\n"},
		{"You can't be serious!\n"},
		{"You can catch the bird, but you cannot carry it.\n"},
		{"There is nothing here with a lock!\n"},
		{"You aren't carrying it!\n"},
		{"You have no keys!\n"},
		{"It has no lock.\n"},
		{"I don't know how to lock or unlock such a thing.\n"},
		{"It was already locked.\n"},
		{"The grate is now locked.\n"},
		{"The grate is now unlocked.\n"},
		{"It was already unlocked.\n"},
		{"You have no source of light.\n"},
		{"Your lamp is now on.\n"},
		{"Your lamp is now off.\n"},
		{"Nothing happens.\n"},
		{"Where?\n"},
		{"There is nothing here to attack.\n"},
		{"You killed a little dwarf.\n"},
		{"With what? Your bare hands?\n"},
		{"Good try, but that is an old worn-out magic word.\n"},
		{"It misses!\n"},
		{"It gets you!\n"},
		{"OK\n"},
		{"You can't unlock the keys.\n"},
		{"I need more detailed instructions to do that.\n"},
		{"I don't know that word.\n"},
		{"What?\n"},
		{"Are you trying to get into the cave?\n"},
		{"Blasting requires dynamite.\n"},
		{"I'm as confused as you are.\n"},
		{"Your feet are now wet.\n"},
		{"I think I just lost my appetite.\n"},
		{"Thank you.  It was delicious!\n"},
		{"The bottle of water is now empty.\n"},
		{"Peculiar.  Nothing unexpected happens.\n"},
		{"Your bottle is empty and the ground is wet.\n"},
		{"You can't pour that.\n"},
		{"Watch it!\n"},
		{"Which way?\n"},
		{"Reserved\n"},
		{"You can't go through a locked steel grate!\n"},
		{"I believe what you want is right here with you.\n"},
		{"You don't fit through a two-inch slit!\n"},
		{"There is no way across the fissure.\n"},
		{"You're not carrying anything.\n"},
		{"You are currently holding the following:\n"},
		{"The snake has now devoured your bird.\n"},
		{"You have nothing in which to carry it.\n"},
		{"Your bottle is already full.\n"},
		{"Your bottle is now full of water.\n"},
		{"Your bottle is now full of oil.\n"},
		{"You can't fill that.\n"},
		{"Don't be ridiculous!\n"},
		{"The door is extremely rusty and refuses to open.\n"},
		{"Oh, leave the poor unhappy bird alone.\n"},
		{"You can't get there from here.\n"},
		{"Do you indeed wish to quit now?\n"},
		{"It is beyond your power to do that.\n"},
		{"I don't know how.\n"},
		{"It is too far up for you to reach.\n"},
		{"On what?\n"},
		{"The troll refuses to let you cross.\n"},
		{"There is no longer any way across the chasm.\n"},
		{"The bear is still chained to the wall.\n"},
		{"The chain is still locked.\n"},
		{"The chain is now unlocked.\n"},
		{"The chain is now locked.\n"},
		{"There is nothing here to eat.\n"},
		{"Do you want the hint?\n"},
		{"Do you need help getting out of the maze?\n"},
		{"Are you trying to explore beyond the plover room?\n"},
		{"Do you need help getting out of here?\n"},
		{"Don't go west.\n"},
		{"Your lamp has run out of power.\n"},
		{"I'm afraid the magazine is written in Dwarvish.\n"},
		{"It says the same thing it did before.\n"},
		{"I'm afraid I don't understand.\n"},
		{"Is this acceptable?\n"},
};

typedef struct {
	char stringInProgramMem[ACTION_2_STRING_LENGTH];
} ACTION_2;

const __attribute__((__progmem__)) ACTION_2 actions_2[AMOUNT_ACTION_2_STRINGS] = {
		{"A little dwarf just walked around a corner, saw you,\nthrew a little axe at you which missed, cursed, and ran away.\n"},
		{"There is a threatening little dwarf in the room with you!\n"},
		{"I am unsure how you are facing.  Use compass points or\nnearby objects.\n"},
		{"I don't know in from out here.  Use compass points or name\nsomething in the general direction you want to go.\n"},
		{"Sorry, but I am not allowed to give more detail.  I will\nrepeat the long description of your location.\n"},
		{"It is now pitch dark.  If you proceed you will likely fall\ninto a pit.\n"},
		{"The bird is frightened right now and you cannot catch\nit no matter what you try.  Perhaps you might try later.\n"},
		{"You can't kill the snake, or drive it away, or avoid it,\nor anything like that.  There is a way to get by, but you\ndon't have the necessary resources right now.\n"},
		{"You fell into a pit and broke every bone in your body!\n"},
		{"The bird was unafraid when you entered, but as you approach\nit becomes disturbed and you cannot catch it.\n"},
		{"The little bird attacks the green snake, and in an\nastounding flurry drives the snake away.\n"},
		{"There is no way to get past the bear to unlock the chain,_\nwhich is probably just as well.\n"},
		{"The little bird is now dead.  Its body disappears.\n"},
		{"Attacking the snake both doesn't work and is very dangerous.\n"},
		{"You attack a little dwarf, but he dodges out of the way.\n"},
		{"You have crawled around in some little holes and wound up\nback in the main passage.\n"},
		{"I don't know where the cave is, but hereabouts no stream\ncan run on the surface for very long.  I would try the stream.\n"},
		{"I can only tell you what you see as you move about and\nmanipulate things.  I cannot tell you where remote things are.\n"},
		{"The grate is very solid and has a hardened steel lock.  You\ncannot enter without a key, and there are no keys nearby.\nI would recommend looking elsewhere for the keys.\n"},
		{"Digging without a shovel is quite impractical.  Even with a\nshovel progress is unlikely.\n"},
		{"Mist is a white vapor, usually water.  Seen from time to time\nin caverns.  It can be found anywhere but is frequently a\nsign of a deep pit leading down to water.\n"},
		{"You have taken a drink from the stream.  The water tastes\nstrongly of minerals, but is not unpleasant.  It is extremely\ncold.\n"},
		{"Rubbing the electric lamp is not particularly rewarding.\nAnyway, nothing exciting happens.\n"},
		{"Oh dear, you seem to have gotten yourself killed.  I might\nbe able to help you out, but I've never really done this\nbefore.  Do you want me to try to reincarnate you?\n"},
		{"All right.  But don't blame me if something goes wr......\n                    --- POOF !! ---\nYou are engulfed in a cloud of orange smoke.  Coughing and\ngasping, you emerge from the smoke and find...\n"},
		{"You clumsy oaf, you've done it again!  I don't know how long\nI can keep this up.  Do you want me to try reincarnating\nyou again?\n"},
		{"Okay, now where did I put my orange smoke? ... > POOF! <\nEverything disappears in a dense cloud of orange smoke.\n"},
		{"Now you've really done it!  I'm out of orange smoke!  You\ndon't expect me to do a decent reincarnation without any\norange smoke, do you?\n"},
		{"Okay, If you're so smart, do it yourself!  I'm leaving!\n"},
		{"Sorry, but I no longer seem to remember how it was you\ngot here.\n"},
		{"You can't carry anything more.  You'll have to drop something\nfirst.\n"},
		{"I respectfully suggest you go across the bridge instead\nof jumping.\n"},
		{"It's not hungry (It's merely pinin' for the Fjords).  Besides\nYou have no bird seed.\n"},
		{"There's nothing here it wants to eat (Except perhaps you).\n"},
		{"You fool, Dwarves eat only coal!  Now you've made\nhim REALLY mad !!\n"},
		{"There is nothing here with which to fill the bottle.\n"},
		{"The plant indignantly shakes the oil off its leaves and asks:\n\"Water?\".\n"},
		{"The hinges are quite thoroughly rusted now and won't budge.\n"},
		{"The oil has freed up the hinges so that the door will now move,\nalthough it requires some effort.\n"},
		{"The plant has exceptionally deep roots and cannot be pulled free.\n"},
		{"The Dwarves' knives vanish as they strike the walls of the cave.\n"},
		{"Something you're carrying won't fit through the tunnel with\nyou.  You'd best take inventory and drop something.\n"},
		{"You can't fit this five-foot clam through that little passage!\n"},
		{"You can't fit this five foot oyster through that little passage!\n"},
		{"I advise you to put down the clam before opening it. >STRAIN!<\n"},
		{"I advise you to put down the oyster before opening it.\n>WRENCH!<\n"},
		{"You don't have anything strong enough to open the clam.\n"},
		{"You don't have anything strong enough to open the oyster.\n"},
		{"A glistening pearl falls out of the clam and rolls away.\nGoodness, this must really be an oyster.  (I never was\nvery good at identifying bivalves.)  Whatever it is,\nit has now snapped shut again.\n"},
		{"The oyster creaks open, revealing nothing but oyster inside.\nIt promptly snaps shut again.\n"},
		{"You have crawled around in some little holes and found your\nway blocked by a recent cave-in.  You are now back in the\nmain passage.\n"},
		{"There are faint rustling noises from the darkness behind\nyou.\n"},
		{"Out from the shadows behind you pounces a bearded pirate!\n\"Har, har\" he chortles, \"I'll just take all this booty and\nhide it away with me chest deep in the maze!\".  He snatches\nyour treasure and vanishes into the gloom.\n"},
		{"A sepulchral voice reverberating through the cave says:\n\"Cave closing soon.  All adventurers exit immediately\nthrough main office.\"\n"},
		{"A mysterious recorded voice groans into life and announces:\n\"This exit is closed.  Please leave via main office.\"\n"},
		{"It looks as though you're dead.  Well, seeing as how it's so\nclose to closing time anyway, I think we'll just call it a day.\n"},
		{"The sepulchral voice entones, \"The cave is now closed.\"  As\nthe echoes fade, there is a blinding flash of light (and a\nsmall puff of orange smoke). . . . \nAs your eyes refocus you look around and find...\n"},
		{"There is a loud explosion, and a twenty-foot hole appears in\nthe far wall, burying the snakes in the rubble.  A river of\nmolten lava pours in through the hole, destroying\neverything in its path, including you!!\n"},
		{"There is a loud explosion, and you are suddenly splashed across\nthe walls of the room.\n"},
		{"The resulting ruckus has awakened the Dwarves.  There are now\nseveral threatening little Dwarves in the room with you!\nMost of them throw knives at you!  All of them get you!\n"},
		{"I daresay whatever you want is around here somewhere.\n"},
		{"I don't know the word \"stop\".   Use \"quit\" if you want to\ngive up.\n"},
		{"You are being followed by a very large, tame bear.\n"},
		{"There is nothing here with which to fill the vase.\n"},
		{"The sudden change in temperature has delicately shattered\nthe vase.\n"},
		{"You killed a little Dwarf.  The body vanished in a cloud\nof greasy black smoke.\n"},
		{"The shell is very strong and impervious to attack.\n"},
		{"What's the matter, can't you read?  Now you'd best start\nover.\n"},
		{"The axe bounces harmlessly off the dragon's thick scales.\n"},
		{"The dragon looks rather nasty.  You'd best not try to get by.\n"},
		{"The little bird attacks the green dragon, and in an\nastounding flurry gets burnt to a cinder.  The ashes blow away.\n"},
		{"Okay, from now on I'll only describe a place in full the\nfirst time you come to it.  To get the full description\nsay \"look\".\n"},
		{"Trolls are close relatives with the rocks and have skin as\ntough as that of a rhinoceros.  The troll fends off your\nblows effortlessly.\n"},
		{"The troll deftly catches the axe, examines it carefully,\nand tosses it back, declaring, \"Good workmanship,\nbut it's not valuable enough.\".\n"},
		{"The troll catches your treasure and scurries away out of sight.\n"},
		{"Just as you reach the other side, the bridge buckles beneath\nthe weight of the bear, which was still following you around.\nYou scrabble desperately for support, but as the bridge \ncollapses you stumble back and fall into the chasm.\n"},
		{"The bear lumbers toward the troll, who lets out a\nstartled shriek and scurries away.  The bear soon gives\nup pursuit and wanders back.\n"},
		{"The axe misses and lands near the bear where you can't get\nat it.\n"},
		{"With what?  Your bare hands?  Against HIS bear hands??\n"},
		{"The bear is confused;  he only wants to be your friend.\n"},
		{"For crying out loud, the poor thing is already dead!\n"},
		{"The bear eagerly wolfs down your food, after which he seems\nto calm down considerably, and even becomes rather friendly.\n"},
		{"There is nothing here to which the chain can be locked.\n"},
		{"You can make the passages look less alike by dropping things.\n"},
		{"There is a way to explore that region without having to\nworry about falling into a pit.  None of the objects\navailable is immediately useful in descovering the secret.\n"},
		{"Gluttony is not one of the Troll's vices.  Avarice, however, is.\n"},
		{"Your lamp is getting dim.. You'd best start wrapping this up,\nunless you can find some fresh batteries.  I seem to recall\nthere's a vending machine in the maze.  Bring some coins\nwith you.\n"},
		{"There's not much point in wandering around out here, and you\ncan't explore the cave without a lamp.  So let's just call\nit a day.\n"},
		{"Your lamp is getting dim.  You'd best go back for\nthose batteries.\n"},
		{"Your lamp is getting dim.. I'm taking the liberty of replacing\nthe batteries.\n"},
		{"Your lamp is getting dim, and you're out of spare batteries.\nYou'd best start wrapping this up.\n"},
		{"\"This is not the maze where the pirate leaves his treasure\nchest.\"\n"},
		{"Hmm, this looks like a clue, which means it'll cost you 10\npoints to read it.  Should I go ahead and read it anyway?\n"},
		{"It says, \"There is something strange about this place,\nsuch that one of the words I've always known now has\na new effect.\"\n"},
		{"\"Congratulations on bringing light into the dark-room!\"\n"},
		{"You strike the mirror a resounding blow, whereupon it\nshatters into a myriad tiny fragments.\n"},
		{"You have taken the vase and hurled it delicately to the\nground.\n"},
		{"You prod the nearest Dwarf, who wakes up grumpily, takes\none look at you, curses, and grabs for his axe.\n"},
		{"There's no point in suspending a demonstration game.\n"},
};

typedef struct {
	char stringInProgramMem[ACTION_3_STRING_LENGTH];
} ACTION_3;

const __attribute__((__progmem__)) ACTION_3 actions_3[AMOUNT_ACTION_3_STRINGS] = {
		{"Somewhere nearby is Colossal Cave, where others have found fortunes in \ntreasure and gold, though it is rumored that some who enter are never \nseen again.  Magic is said to work in the cave.  I will be your eyes \nand hands.  Direct me with commands of 1 or 2 words.  I should warn \nyou that I look at only the first five letters of each word, so you'll \nhave to enter \"Northeast\" as \"ne\" to distinguish it from \"North\".  \n(Should you get stuck, type \"help\" for some general hints).\n\n"},
		{"The trees of the forest are large hardwood oak and maple,\nwith an occasional grove of pine or spruce.  There is quite\na bit of undergrowth, largely birch and ash saplings plus\nnondescript bushes of various sorts.  This time of year \nvisibility is quite restricted by all the leaves, but travel\nis quite easy if you detour around the spruce and berry\nbushes.\n"},
		{"\n                              Welcome to \n\n                       Colossal Cave Adventure!\n\n\n               Original development by Willie Crowther.\n                  Major features added by Don Woods.\n                 Conversion to BDS C by J. R. Jaeger.\n                Unix standardization by Jerry D. Pohl.\n            Port to QNX 4 and bug fixes by James Lummel.\n\nWould you like instructions?\n\n"},
		{"There is a loud explosion, and a twenty-foot hole appears in\nthe far wall, burying the Dwarves in the rubble.  You march\nthrough the hole and find yourself in the main office, where\na cheering band of friendly elves carry the conquering\nadventurer off into the sunset.\n"},
		{"There are faint rustling noises from the darkness behind you.\nAs you turn toward them, the beam of your lamp falls across a\nbearded pirate.  He is carrying a large chest.  \"Shiver me\ntimbers!\"  he cries, \"I've been spotted!  I'd best hide\nmeself off to the maze and hide me chest!\".  With that,\nhe vanished into the gloom.\n"},
};

#define ACTION_51_STRING_LENGTH 1337
const __attribute__((__progmem__)) char action_51[ACTION_51_STRING_LENGTH] = "I know of places, actions, and things.  Most of my vocabulary \ndescribes places and is used to move you there.  To move, try words \nlike forest, building, downstream, enter, east, west, north, south, up \nor down.  \nI know about a few special objects, like a black rod hidden in the \ncave.  These objects can be manipulated using some of the action words \nI know. Usually you will need to give both the object and action words \n(In either order), but sometimes I can infer the object from the verb \nalone.  Some objects also imply verbs; in particular, \"inventory\" \nimplies \"take inventory\", which causes me to give you a list of what \nyou're carrying.\nThe objects have side effects; for instance, the rod scares the bird. \nUsually people having trouble moving just need to try a few more \nwords.  Usually people trying unsuccessfully to manipulate an object \nare attempting something beyond their (or my!) capabilities and should \ntry a completely different tack.\nTo speed the game up, you can sometimes move long distances with a \nsingle word.  For example, \"building\" usually gets you to the building \nfrom anywhere above ground except when lost in the forest.  Also, note \nthat cave passages turn a lot, and that leaving a room to the north \ndoes not guarantee entering the next from the south. Good luck!\n";

#define ACTION_142_STRING_LENGTH 1430
const __attribute__((__progmem__)) char action_142[ACTION_142_STRING_LENGTH] = "If you want to end your adventure early, say \"quit\".  To suspend your \nadventure such that you can continue later say \"suspend\" (or \"pause\" \nor \"save\").  To load a previously saved game, say 'load' or 'restore'.  \nTo see how well you're doing, say \"score\".  To get full credit for a \ntreasure, you must have left it safely in the building, though you get \npartial credit just for locating it. You lose points for getting \nkilled, or for quitting, though the former costs you more. \nThere are also points based on how much (If any) of the cave you've \nmanaged to explore;  in particular, there is a large bonus just for \ngetting in (to distinguish the beginners from the rest of the pack), \nand there are other ways to determine whether you've been through some \nof the more harrowing sections. \nIf you think you've found all the treasures, just keep exploring for a \nwhile.  If nothing interesting happens, you haven't found them all \nyet.  If something interesting DOES happen, it means you're getting a \nbonus and have an opportunity to garner many more points in the \nmaster's section.\nI may occasionally offer hints in you seem to be having trouble.  If I \ndo, I'll warn you in advance how much it will affect your score to \naccept the hints.  Finally, to save paper, you may specify \"brief\", \nwhich tells me never to repeat the full description of a place unless \nyou explicitly ask me to.\n";


#define LOAD_FROM(NUM) \
	stringToReturn = helper->createFileString_P(&(TextFile) { \
		.pointerToArray = addressOf(actions_##NUM), \
		.maxLengthOfStrings = ACTION_##NUM##_STRING_LENGTH, \
		.sizeOfIndexArray = 0, \
		.amountOfEntries = AMOUNT_ACTION_##NUM##_STRINGS, \
	}, actionNumber, helper); \
	if (stringToReturn != NULL) { return stringToReturn; }

#define PUT_FROM(NUM) \
	if (helper->putFileString_P(&(TextFile) { \
		.pointerToArray =  addressOf(actions_##NUM), \
		.maxLengthOfStrings = ACTION_##NUM##_STRING_LENGTH, \
		.sizeOfIndexArray = 0, \
		.amountOfEntries = AMOUNT_ACTION_##NUM##_STRINGS, \
	}, actionNumber, helper) == 0) { return 0;}; \

char * loadAction(FlashHelper * helper, uint8_t actionNumber) {
	char * stringToReturn = NULL;

	if (actionNumber == 51) {
		stringToReturn = (char *) malloc(ACTION_51_STRING_LENGTH);
		helper->copyString_P(stringToReturn,  addressOf(action_51));
	}
	if (actionNumber == 142) {
		stringToReturn = (char *) malloc(ACTION_142_STRING_LENGTH);
		helper->copyString_P(stringToReturn,  addressOf(action_142));
	}
	LOAD_FROM(1)
	LOAD_FROM(2)
	LOAD_FROM(3)

	return stringToReturn;
}

int16_t putFileStrAction(FlashHelper * helper, uint8_t actionNumber) {
	if (actionNumber == 51) {
		return helper->putString_P(addressOf(action_51));
	}
	if (actionNumber == 142) {
		return helper->putString_P(addressOf(action_142));
	}
	PUT_FROM(1)
	PUT_FROM(2)
	PUT_FROM(3)

	return -1;
}

//getter function expects an initialized instance of FlashHelper as reachable global reference
//char * getAction(int actionNumber) {
//	return loadAction(flashHelper, actionNumber);
//}
////getter function expects an initialized instance of FlashHelper as reachable global reference
//char * putAction(int actionNumber) {
//	return putFileStrAction(flashHelper, actionNumber);
//}