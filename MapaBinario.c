#include <stdio.h>

void Binario(int N, int bin[]){
  int i=31; //Inicia o vetor do Final
  while(N > 0){ //Grava no Vetor o Numero Resto da Divisao por Dois (Converte para Binario)
    bin[i] = N % 2;
	  i--;
	  N = N / 2;	
	}
}

void escreve (int bin[]){ // Escreve na Tela o Numero em Binario
  printf("Em Binario: \n");
  for (int i = 0; i <= 32; i++){
    printf("%d", bin[i]);
  }
}


void contador(int bin[]){

  int contador = 0;
  
  for (int i = 0; i < 32; i++){
    
    if (bin[i] != 0){
      int temp = 0;
      if(contador != 0){ //Armazena Contador
        temp = contador;
        contador = 0;
      }
      for(int j = 1; j < 32; j++){ //Procura Intervalo
        if(bin[i+j] == 0){
          contador++;
        } else {break;}
      }
      if(temp > contador){ //Define Maior Intervalo
        contador = temp;
      }
    }    
  }

  printf("\nContador de intervalo: %d", contador);
  
}

int main(void) {
  int numero;
  int bin[32] = {}; //Limita o tamanho do numero em 2^32
    
  printf("Determine o Numero: ");//Le Numero a Ser Calculado
  scanf("%d", &numero);
    
  Binario(numero, bin); // Passa para binario em um vetor

  escreve(bin);// Escreve Vetor Binario na tela

  contador(bin); //Conta os Intervalos  
  
  
  return 0;
}