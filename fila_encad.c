#include "fila_encad.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10


typedef struct lista_dados {
   int         elementos;
   struct lista_dados *prox;
}dados_celula;

typedef struct fila_encad{
  int inicio, fim, qtd;
  dados_celula lista[N];
}dados_fila;

void cria_fila(dados_fila *fila){
  fila->inicio=0;
  fila->fim=0;
  fila->qtd=0;
}

int fila_cheia(dados_fila *fila){
  if(fila->qtd == N)
  return 1;
  else
  return 0;
}
int fila_vazia(dados_fila *fila){
  if(fila_cheia(fila))
  return 1;
  else
  return 0;
}

void enfileira(int x){
  dados_celula *p;
  dados_celula *nova;
     nova = malloc (sizeof (dados_celula));
     nova->elementos = x;
     nova->prox = p->prox;
     p->prox = nova;
}

int desenfileira(dados_celula *p){
  dados_celula *lixo;
   lixo = p->prox;
   p->prox = lixo->prox;
   free (lixo);
}

void imprime_fila(dados_celula *le) {
   dados_celula *p;
   for (p = le->prox; p != NULL; p = p->prox)
      printf ("%d\n", p->elementos);
}
