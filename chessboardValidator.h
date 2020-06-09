#include <stdio.h>
#include <stdlib.h>



//Check if any queen Q is adjacent to any other queen Q. if true, return an integer between 3 and 10 inclusively
//If no queen Q is adjacent to any other within the chessboard, return 0
int validator(int m, char matrix[m][m]){
  for (int i = 0; i < m; i++){
    for (int j = 0; j < m; j++){
      if (matrix[i][j] == 'Q'){
        if (i == 0 && j == 0 && (matrix[i+1][j] == 'Q' ||  matrix[i][j+1] == 'Q' || matrix[i+1][j+1] == 'Q')){
          return 2;
        }
        else if (i == 0 && j < m-1 && (matrix[i][j-1] == 'Q' || matrix[i+1][j-1] == 'Q' || matrix[i+1][j] == 'Q' ||  matrix[i+1][j+1] == 'Q' || matrix[i][j+1] == 'Q' )){
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
