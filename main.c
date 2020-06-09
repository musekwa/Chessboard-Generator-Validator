#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "chessboardGenerator.h"






int main(int argc, char* argv[]) {

  //the seed's random number generator 
  srand((unsigned)time(NULL));

  //Make sure this usage is followed so to run this program
  if (argc != 3){
    printf("\nUsage: ./main <integer> <integer>\n");
    return 2;
  }

  int m = atoi(argv[1]);
  int queens = atoi(argv[2]); 

  generateChessBoard(m, queens);

  return 0;
}