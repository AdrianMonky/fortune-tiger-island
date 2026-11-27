#include "jogo.h"
#include <stdio.h>

int CarregarMapa(const char *nomeArquivo, Jogo *j) {
  FILE *mapa = fopen(nomeArquivo, "r");

  if (mapa == NULL) {
    fclose(mapa);
    return 0;
  } else {
    if ((fscanf(mapa, "%d %d", &j->colunas, &j->linhas) != 2) ||
        (fscanf(mapa, " %d %d", &j->energia, &j->minimoCristais) != 2)) {
      return 0;
    }
  }
}

void DesenharJogo(Jogo *j) {}
