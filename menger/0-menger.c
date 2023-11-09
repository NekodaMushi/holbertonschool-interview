#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * menger - Draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 */
void menger(int level) {
    int size, i, j, block, i_block, j_block;

    if (level < 0) {
        return; 
    }

    size = pow(3, level);


    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            block = 0;
            i_block = i;
            j_block = j;


            while (i_block > 0 && j_block > 0) {
                if (i_block % 3 == 1 && j_block % 3 == 1) {
                    block = 1;
                    break;
                }
                i_block /= 3;
                j_block /= 3;
            }

            if (block) {
                putchar(' ');
            } else {
                putchar('#');
            }
        }
        putchar('\n');
    }
}
