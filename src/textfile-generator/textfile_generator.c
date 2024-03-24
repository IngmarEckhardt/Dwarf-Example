#include <dwarf-os/pgm_textfile_generator.h>
#include "advent4.h"
#include "advent2.h"

void createTextFiles(void) {
    convertStringsToPGMTextFile(adventtxt4, 201,(uint16_t[]){50, 250, 500}, 3, "ACTION_WITH_INDEX", 1);
    convertStringsToPGMTextFile(adventtxt4, 201,(uint16_t[]){50, 250, 500}, 3, "ACTION", 0);

    convertStringsToPGMTextFile(adventtxt2, 140,(uint16_t[]){15, 50, 150}, 3, "SHORT_LOCATION", 1);
}

int main(void) {



    createTextFiles();


}
