#include "fila_encad.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10


typedef struct lista {
   int         conteudo;
   struct lista *prox;
}celula;

celula *fila;

void cria_fila(){
  fila = malloc (sizeof (celula));
  fila->prox = NULL;
}

int fila_cheia(){

  if(fila->prox == N)
  return 1;
  else
  return 0;
}

int fila_vazia(){
  if(fila_cheia())
  return 1;
  else
  return 0;
}
//Inserir na fila
void enfileira(int y){
  celula *fila;
  celula *nova;
     nova = malloc (sizeof (celula));
     if(nova==NULL)
     return 0;
     else{
       nova->conteudo = y;
       nova->prox = fila->prox;
       fila->prox = nova;
       //fila = nova;
       return 1;
     }
}
//Remover da fila
int desenfileira(){
  celula *lixo;
  lixo = fila->prox;
   fila = lixo->prox;
   fila->prox = lixo->prox;
   free (lixo);
   return 1;
}
//funcao rcursiva
void imprime_fila() {
   celula *fila;
   if(fila != NULL){
     printf ("%d\n", fila->conteudo);
     imprime_fila(fila->prox);
   }
}
//librar lista
/*void libera_fila(){
  _celula *lixo, *prox;

  prox = fila->prox;
  while(prox != fila){
    lixo = prox;
    prox = lixo->prox;
    free(lixo);
  }
}*/

//Implmatacao altrnativa
void libera_fila(){
  int elementos;
  while(desenfileira(&elementos))
  free(fila);
}
9
