#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "chessboardValidator.h"
#include "randomNumber.h"

void printChessboard(int m, char matrix[m][m]){
  for (int i = 0; i < m; i++){
    for (int j = 0; j < m; j++){
      printf ("%3c", matrix[i][j]);
    }
    printf("\n");
  }
}



//Generate a chessboard of m x m size with q queens
void generateChessBoard(int m, int q){
  char matrix[m][m];
  int index = 0;
  int counter = 0;

  //Fill the chessboard with dashes
  for (int i = 0; i < m; i++) {
    for(int j = 0; j < m; j++) {
      matrix[i][j] = '-';
    }
  }

  // Randomly insert Q queens in the chessboard
  // Don't overwrite an already inserted queen
  int i = 0;
  while (i < q) {
    int line = randomNumber(0, m-1);
    int col = randomNumber(0, m-1);

    if (matrix[line][col] != 'Q'){
      matrix[line][col] = 'Q';
      i++;
    }
  }


  //print the chessboard with all the queens placed within it
  printChessboard(m, matrix);

  //Check if the queens placement is valide according to user stories
  //return 0 if the placement is valid, return a number between 2 and 10 otherwise
  int n = validator(m, matrix);
  if (n == 0){
    printf("VALID\n");
  }
  else{
    printf("INVALID\n");
  }

}
