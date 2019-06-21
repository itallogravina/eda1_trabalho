//#include "fila_vet.h"
//#include "fila_circu.h"
#include "fila_encad.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Menu();
void casos();

int main(){
  casos();
  return 0;
}

void Menu(){
  printf("\n\tMENU FILA\n");
  printf("\n1_ Inserir 'n' elementos na fila\n2_ Remover elementos da fila\n3_Imprimir a fila\n4_Sair\n\n");
  printf("\tEscolha uma opção:\n\n");
}

void casos(){
  int opcao, nao_coube;
  int *y, z;
  int retirar=0;
    Menu();
  while(scanf("%d", &opcao)>0 && opcao!=4){
    if(opcao>4)
    printf("Valor inválido.\nDigite um número entre 1 e 4.\n");
    switch (opcao){
      case 1:
      system("clear");
      fila_vazia();

      printf("Quantos elementos deseja inserir na fila?\n");
      scanf("%d", &z);
      y = malloc(z*sizeof(int));
      printf("Digite os %d elementos na fila\n", z);
      for(int i=0;i<z; i++){
        int garantia;
        scanf("%d\n", &garantia);
        if(garantia <= 999 && garantia >= 0){
          y[i] = garantia;
        }
      }
      int qtd=0;
      int j=0;
      while(!fila_cheia() && j != z) {
        enfileira(y[j]);
        qtd++;
        j++;
      }
      if(qtd != z){
        nao_coube = z - qtd;
        printf("\nNão coube na fila %d elementos\n\n", nao_coube);
      }
      Menu();
      free(y);
      break;

      case 2:
      system("clear");
      printf("Digite a quantidade de elementos que deseja retirar da fila\n");
      scanf("%d", &retirar);
      printf("Foram removidos: %d elementos\n", retirar);
      int remov = 0;
      while(!fila_vazia() && retirar){
        retirar--;
        remov++;
        desenfileira();
        //printf("Foram removidos: %d elementos\n", remov);
      }
      Menu();
      break;

      case 3:
      system("clear");
      imprime_fila();
      Menu();
      break;
    }
  };
}
