#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Randomly generate integer index such that n >= min and n <= m
//return index
int randomNumber(int min, int max){
  int index = (rand() % (max - min + 1)) + min;
  return index;
}

void printChessboard(int m, char matrix[m][m]){
  for (int i = 0; i < m; i++){
    for (int j = 0; j < m; j++){
      printf ("%3c", matrix[i][j]);
    }
    printf("\n");
  }
}

//Check if any queen Q is adjacent to any other queen Q. if true, return an integer between 3 and 10 inclusively
//If no queen Q is adjacent to any other within the chessboard, return 0
int validator(int m, char matrix[m][m]){
  for (int i = 0; i < m; i++){
    for (int j = 0; j < m; j++){
      if (matrix[i][j] == 'Q'){
        if (i == 0 && j == 0 && (matrix[i+1][j] == 'Q' ||  matrix[i][j+1] == 'Q' || matrix[i+1][j+1] == 'Q')){
          return 3;
        }
        else if (i == 0 && j == m-1 && (matrix[i][j-1] == 'Q' || matrix[i+1][j-1] == 'Q' || matrix[i+1][j] == 'Q')){
          return 4;
        }
        else if (i > 0 && i < m-1 && j == 0 && (matrix[i][j+1] == 'Q' || matrix[i-1][j] == 'Q' || matrix[i+1][j] == 'Q' || matrix[i-1][j+1] == 'Q' || matrix[i+1][j+1] == 'Q' )){
          return 5;
        }
        else if (i > 0 && i < m-1 && j == m-1 && (matrix[i][j-1] == 'Q' || matrix[i+1][j] == 'Q' || matrix[i+1][j-1] == 'Q' || matrix[i-1][j] == 'Q' || matrix[i-1][j-1] == 'Q')){
          return 6;
        }
        else if (i == m-1 && j == 0 && (matrix[i-1][j] == 'Q' || matrix[i][j+1] == 'Q' || matrix[i-1][j+1] == 'Q')){
          return 7;
        }
        else if (i == m-1 && j > 0 && j < m-1 && (matrix[i][j-1] == 'Q'|| matrix[i][j+1] == 'Q' || matrix[i-1][j+1] == 'Q'|| matrix[i-1][j-1] == 'Q' || matrix[i-1][j] == 'Q')){
          return 8;
        }
        else if(i == m-1 && j == m-1 && (matrix[i][j-1] == 'Q' || matrix[i-1][j-1] == 'Q' || matrix[i-1][j] == 'Q')){
          return 9;
        }
        else if (i > 0 && i < m-1 && j > 0 && j < m-1 && (matrix[i][j-1] == 'Q' ||matrix[i][j+1] == 'Q'||matrix[i-1][j-1] == 'Q' || matrix[i-1][j] == 'Q' || matrix[i-1][j+1]== 'Q' || matrix[i+1][j-1] == 'Q' || matrix[i+1][j] == 'Q' || matrix[i+1][j+1] == 'Q')){
          return 10;
        }
      }
    }
  }
  return 0;
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