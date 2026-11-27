#include "jogo.h"
#include <stdio.h>

int CarregarMapa(const char *nomeArquivo, Jogo *j) {
  FILE *mapa = fopen(nomeArquivo, "r");

  if (mapa == NULL) {
    return 0;
  } else {
    return 1;
  }
}

void DesenharJogo(Jogo *j) {}
