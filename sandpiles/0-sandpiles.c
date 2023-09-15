#include "sandpiles.h"
#include <stdio.h>

/**
 * sandpiles_sum - add two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j, is_stable, temp_grid[3][3];

    /* First Sum */
    for (i = 0; i < 3; ++i){
      for(j = 0; j < 3; ++j){
        grid1[i][j] += grid2[i][j];
      }
    }


    while (1) {
      is_stable = 1;


        /* Check Stability */
      for (i = 0; i<3; ++i){
        for (j = 0; j < 3; ++j ){
          if (grid1[i][j] > 3){
            is_stable = 0;
          }
          temp_grid[i][j] = grid1[i][j];
        }
      }

      /* Break while loop when stable */
      if (is_stable == 1) {
        break;
      }
      printf("=\n");
        /* Print grid1 displayed multiple times in output */
      for (i=0; i < 3; ++i){
        for (j = 0; j < 3; ++j){
          if (j > 0){
            printf(" ");
          }
          printf("%d",grid1[i][j]);
        }
        printf("\n");
      }


        /* Toppling */
      for (i = 0; i < 3; ++i){
        for (j=0; j < 3; ++j) {
          if (temp_grid[i][j] > 3){
            grid1[i][j] -= 4;
            if (i > 0) {
              grid1[i - 1][j] = grid1[i - 1][j] + 1;
            }
            if (j > 0) {
              grid1[i][j-1] = grid1[i][j-1] + 1;
            }
            if (i < 2){
              grid1[i + 1][j] = grid1[i + 1][j] + 1;
            }
            if (j < 2){
              grid1[i][j + 1] = grid1[i][j + 1] + 1;
            }
          }
        }
      }
    }
}
