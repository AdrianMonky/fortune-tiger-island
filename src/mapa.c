#include "jogo.h"
#include <stdio.h>

int CarregarMapa(const char *nomeArquivo, Jogo *j) {
  FILE *mapa = fopen(nomeArquivo, "r");
  int i, k;

  if (mapa == NULL) {
    fclose(mapa);
    return 0;
  } else {
    if ((fscanf(mapa, "%d %d", &j->colunas, &j->linhas) != 2) ||
        (fscanf(mapa, " %d %d", &j->energia, &j->minimoCristais) !=
         2)) {  // verifica se o numero de colunas, linhas, energia e minimo de
                // cristais //
      return 0; // foram lidos corretamente
    }

    for (i = 0; i < j->linhas; i++) {
      if (fgets(j->mapa[i], j->colunas, mapa) ==
          NULL) { // verifica se os caracteres que formam o mapa foram lidos
                  // corretamente
        return 0;
      };
    }
  }
  fclose(mapa);
  return 1;
}

void DesenharJogo(Jogo *j) {}
