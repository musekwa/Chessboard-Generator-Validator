#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* gerador(int m, int n, int q) { 
    int min = 0, max = m;
    int* numerosGerados = (int*)malloc(sizeof(int)*(q*2));

    //utilizar o tempo (hora) atual como a 'seed' do gerador de numero aleatorio
    srand(time(0));

    //gerar q*2 numeros para atribuir indeces aos caracteres dentro do vetor
    for (int i = 0; i < n; i++){
      for (int j = 0; j < q*2; j++) { 
          int num = (rand() % (max - min + 1)) + min;  
          numerosGerados[j] = num;
      }
      for (int j = 0; j < m; j++) {
        
      }
    }
    return numerosGerados;
}





void validador(char* configuracao, int m){
  char tabuleiro[m][m];
  int index = 0;
  int size = sizeof(configuracao);
  int contador = 0;

  for (int i = 0; i < m; i++) {
    for(int j = 0; j < m; j++) {
      tabuleiro[i][j] = configuracao[index++];
      printf("%2c", tabuleiro[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < m; i ++) {
    for (int j = 0; j < m; j++) {
      if (tabuleiro[i][j] == 'D'){
          if (i == 0 && j == 0 && (tabuleiro[i+1][j] == 'D' ||
                tabuleiro[i][j+1] == 'D' || tabuleiro[i+1][j+1] == 'D')) {
            printf("INVALIDO\n");
            contador++;
            return ;
          }
          else if (i == 0 && j > 0 && j < m-1 && (tabuleiro[i][j-1] == 'D' ||
                    tabuleiro[i][j+1] == 'D' || tabuleiro[i+1][j] == 'D' || 
                    tabuleiro[i+1][j-1] == 'D' || tabuleiro[i+1][j+1] == 'D')) {
            printf("INVALIDO\n");
            contador++;
            return ;
          }
          else if (i == 0 && j == m-1 && (tabuleiro[i][j-1] == 'D' ||
                    tabuleiro[i+1][j-1] == 'D' || tabuleiro[i+1][j] == 'D')) {
            printf("INVALIDO\n");
            contador++;
            return ;
          }
          else if (i > 0 && i < m-1 && j == 0 && (tabuleiro[i][j+1] == 'D' ||
                    tabuleiro[i-1][j] == 'D' || tabuleiro[i+1][j] == 'D' || 
                    tabuleiro[i-1][j+1] == 'D' || tabuleiro[i+1][j+1] == 'D' )) {
            printf("INVALIDO\n");
            contador++;
            return ;
          }
          else if (i > 0 && i < m-1 && j == m-1 && (tabuleiro[i][j-1] == 'D' || 
                      tabuleiro[i+1][j] == 'D' || tabuleiro[i+1][j-1] == 'D' || tabuleiro[i-1][j] =='D' ||
                      tabuleiro[i-1][j-1] == 'D')){
            printf("INVALIDO\n");
            contador++;
            return ;
          }
          else if (i == m-1 && j == 0 && (tabuleiro[i-1][j] == 'D' || tabuleiro[i][j+1] == 'D' ||
                      tabuleiro[i-1][j+1] == 'D')) {
            printf("INVALIDO\n");
            contador++;
            return ;
          }
          else if (i == m-1 && j > 0 && j < m-1 && (tabuleiro[i][j-1] == 'D' || tabuleiro[i][j+1] == 'D' ||
                      tabuleiro[i-1][j+1] == 'D' || tabuleiro[i-1][j-1] == 'D' || tabuleiro[i-1][j] == 'D')){
            printf("INVALIDO\n");
            contador++;
            return ;
          }
          else if (i == m-1 && j == m-1 && (tabuleiro[i][j-1] == 'D' || tabuleiro[i-1][j-1] == 'D' ||
                      tabuleiro[i-1][j] == 'D')) {
            printf("INVALIDO\n");
            contador++;
            return ;
          }
          else if (i > 0 && i < m-1 && j > 0 && j < m-1 && (tabuleiro[i][j-1] == 'D' || 
                      tabuleiro[i][j+1] == 'D' || tabuleiro[i-1][j-1] == 'D' ||
                      tabuleiro[i-1][j] == 'D' || tabuleiro[i-1][j+1]== 'D' || tabuleiro[i+1][j-1] == 'D' || 
                      tabuleiro[i+1][j] == 'D' || tabuleiro[i+1][j+1] == 'D')){
            printf("INVALIDO\n");
            contador++;
            return ;
          }
      }
    }
  }

  if (contador == 0) {
    printf("VALIDO\n");
  }
}


int main(void) {

  char configuracao[64];
  int tamanho;
  printf("Tamanho do tabuleiro: ");
 // scanf("%d", &tamanho);
  printf("Configuracao: ");
 // scanf("%s", configuracao);
  gerador(8, 8);
  

  validador(configuracao, tamanho);
  return 0;
}