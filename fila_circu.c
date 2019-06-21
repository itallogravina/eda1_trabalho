// Arquivo filadeints.c.

#include "fila_circu.h"
#include <stdio.h>
#include <stdlib.h>


// Variáveis globais do módulo.
// A fila reside em fila[p..u-1].
static int *fila;
static int p, u, N,s;

void cria_fila(void) {
   N = 2;
   fila = malloc (N * sizeof (int));
   p = 0, u = 0;
}

int fila_vazia(void) {
   return p >= u;
}

static void redimensiona (void) {
   N *= 2;
   fila = realloc (fila, N * sizeof (int));
   for (int i = p; i < u; i++)
      fila[i-p] = fila[i];
   u -= p;
   p = 1;
}

void enfileira(int y) {
   if (u == N) redimensiona ();
   fila[u++] = y;
}

// Supõe que p < u.
int desenfileira () {
   fila[p++];


}

void imprime_fila(){
  for (int i = p; i < N; i++) {
    printf("%d\n",fila[i] );
    printf("p = %d\n",p);
  }
}

void liberafila (void) {
   free (fila);
}
