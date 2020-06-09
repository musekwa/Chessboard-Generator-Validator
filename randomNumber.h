#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//Randomly generate integer index such that n >= min and n <= m
//return index
int randomNumber(int min, int max){
  int index = (rand() % (max - min + 1)) + min;
  return index;
}