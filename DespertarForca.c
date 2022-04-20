#include <stdio.h>


void movimento(int skywalkerX , int skywalkerY, int reyX, int reyY, int mov[50]){
  int i = 0; // Variavel de Controle
  while (skywalkerX != reyX && skywalkerY != reyY){ // Procura Movimento 8 Opcoes e Codifica no Vetor
    
    if ((skywalkerX == reyX) && (skywalkerY < reyY)){
      reyY--;
      mov[i] = 1;
      i++;      
    }
    
    if ((skywalkerX > reyX) && (skywalkerY > reyY)){
      reyX++;
      reyY++;
      mov[i] = 4;
      i++;
    }

    if ((skywalkerX > reyX) && (skywalkerY == reyY)){
      reyX++;
      mov[i] = 3;
      i++;
    }

    if ((skywalkerX == reyX) && (skywalkerY > reyY)){
      reyY++;
      mov[i] = 5;
      i++;
    }

    if ((skywalkerX > reyX) && (skywalkerY < reyY)){
      reyX++;
      reyY--;
      mov[i] = 2;
      i++;
    }

    if ((skywalkerX == reyX) && (skywalkerY < reyY)){
      reyX--;
      mov[i] = 7;
      i++;
    }
    
    if ((skywalkerX < reyX) && (skywalkerY < reyY)){
      reyX--;
      reyY--;
      mov[i] = 8;
      i++;
    }

    if ((skywalkerX < reyX) && (skywalkerY > reyY)){
      reyX--;
      reyY++;
      mov[i] = 6;
      i++;
    }
  }    
}

void escreve(int mov[]){
  for(int i = 0; i < 50; i++){ //Decodifica os Movimentos e Printa Sequencia
    if(mov[i] == 1){
      printf("Movimento %d - N\n", i+1);
    }
    if(mov[i] == 2){
      printf("Movimento %d - NE\n", i+1);
    }
    if(mov[i] == 3){
      printf("Movimento %d - E\n", i+1);
    }
    if(mov[i] == 4){
      printf("Movimento %d - SE\n", i+1);
    }
    if(mov[i] == 5){
      printf("Movimento %d - S\n", i+1);
    }
    if(mov[i] == 6){
      printf("Movimento %d - SW\n", i+1);
    }
    if(mov[i] == 7){
      printf("Movimento %d - W\n", i+1);
    }
    if(mov[i] == 8){
      printf("Movimento %d - NW\n", i+1);
    }
  }
}


int main(void) {
  int skywalkerX, skywalkerY, reyX, reyY; //Posicoes dos Pontos
  int mov[50]= {}; // Vetor com Numero Maximo de Movientos

  //Le Posicao da Rey
  printf("Posicao X da Rey: ");
  scanf("%d", &reyX);
  printf("Posicao Y da Rey: ");
  scanf("%d", &reyY);

  //Le Posicao do Luke
  printf("Posicao X do Luke: ");
  scanf("%d", &skywalkerX);
  printf("Posicao Y do Luke: ");
  scanf("%d", &skywalkerY);

  //Cria um vetor dos Movimentos
  movimento(skywalkerX, skywalkerY, reyX, reyY, mov);

  //Escreve na Tela os Movimentos
  escreve(mov);
  
  return 0;
}