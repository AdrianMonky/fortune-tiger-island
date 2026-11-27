#include "jogo.h"
#include "raylib.h"
#include <stdio.h>
#define TAM 40

int CarregarMapa(const char *nomeArquivo, Jogo *j) {
  FILE *mapa = fopen(nomeArquivo, "r");
  int i, k;
  int c;

  if (mapa == NULL) {
    return 0;
  } else {
    if (fscanf(mapa, "%d %d %d %d", &j->colunas, &j->linhas, &j->energia,
               &j->cristais) !=
        4) { // verifica se o numero de colunas, linhas, energia e minimo de
      fclose(mapa); // cristais foram lidos corretamente
      return 0;
    }

    if (j->colunas > MAX_COLUNAS ||
        j->linhas > MAX_LINHAS) { // verifica se o numero de linhas e colunas
                                  // esta dentro do limite
      fclose(mapa);
      return 0;
    }

    while ((c = fgetc(mapa)) != '\n' && c != EOF)
      ; // Consome quebras de linha e fim de arquivo antes de usar fgets

    for (i = 0; i < j->linhas; i++) {
      if (fgets(j->mapa[i], j->colunas, mapa) ==
          NULL) { // verifica se os caracteres que formam o mapa foram lidos
                  // corretamente
        fclose(mapa);
        return 0;
      };

      j->mapa[i][j->colunas] = '\0'; // Consome quebras de linha
    }
  }
  fclose(mapa);
  return 1;
}

void DesenharJogo(Jogo *j) {
  int i, k;
  int x, y;

  for (i = 0; i < j->linhas; i++) {
    for (k = 0; k < j->colunas; k++) {
      // convertemos a posicao da matriz em coordenadas na tela
      x = k * TAM;
      y = i * TAM;

      DrawRectangle(x, y, TAM, TAM,
                    LIGHTGRAY); // caso base: todo o mapa é caminho livre
      switch (j->mapa[i][k]) {
      case '#':
        DrawRectangle(x, y, TAM, TAM, DARKGRAY); // obstaculo
        break;
          case ''
      }

    }
  }


}
