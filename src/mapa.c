#include "jogo.h"
#include "raylib.h"
#include <stdio.h>
#define TAM 28
#define ESPACO 10

int CarregarMapa(const char *nomeArquivo, Jogo *j) {
  FILE *mapa = fopen(nomeArquivo, "r");
  int i, k;

  if (mapa == NULL) {
    return 0;
  } else {
    if (fscanf(mapa, "%d %d %d %d", &j->linhas, &j->colunas, &j->energia,
               &j->minimoCristais) !=
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

    for (i = 0; i < j->linhas; i++) {
      for (k = 0; k < j->colunas; k++) {
        if (fscanf(mapa, " %c",
                   &j->mapa[i][k]) !=
            1) { // verifica se os caracteres foram lidos corretamente
          fclose(mapa);
          return 0;
        }
        if (j->mapa[i][k] == 'P') {
          j->linhasJ = i;
          j->colunasJ = k;
        }
      }

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
      x = k * (TAM + ESPACO);
      y = i * (TAM + ESPACO);

      DrawRectangle(x, y, TAM, TAM,
                    LIGHTGRAY); // caso base: todo o mapa é caminho livre
      switch (j->mapa[i][k]) {
      case '#':
        DrawRectangle(x, y, TAM, TAM, DARKGRAY); // obstaculo
        break;
      case 'P': // jogador
        DrawRectangle(x + TAM / 2, y + TAM / 2, TAM - 10, TAM - 10, MAGENTA);
        DrawText("P", x + TAM / 2, y + TAM / 2, 24, RAYWHITE);
        break;
      case 'C': // cristal
        DrawCircle(x + TAM / 2, y + TAM / 2, 10, GOLD);
        break;
      case 'R': // recuperacao
        DrawRectangle(x + TAM / 2, y + TAM / 2, TAM - 10, TAM - 10, DARKGREEN);
        DrawText("+", x + TAM / 2, y + TAM / 2, 24, RAYWHITE);
        break;
      case 'A': // armadilha
        DrawRectangle(x + TAM / 2, y + TAM / 2, TAM - 10, TAM - 10, RED);
        DrawText("A", x + TAM / 2, y + TAM / 2, 24, RAYWHITE);
        break;
      case 'E': // evento
        DrawRectangle(x + TAM / 2, y + TAM / 2, TAM - 10, TAM - 10, PURPLE);
        DrawText("?", x + TAM / 2, y + TAM / 2, 24, RAYWHITE);
        break;
      case 'S': // saida
        DrawRectangle(x + TAM / 2, y + TAM / 2, TAM - 10, TAM - 10, BLUE);
        DrawText("S", x + TAM / 2, y + TAM / 2, 24, RAYWHITE);
        break;
      }
    }
  }
}
