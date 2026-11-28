#include "jogo.h"
#include "raylib.h"
#include <stdio.h>
#define TAM 40
#define ESPACO 20

int CarregarMapa(const char *nomeArquivo, Jogo *j) {
  FILE *mapa = fopen(nomeArquivo, "r");
  int i;
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
      x = k * (TAM + ESPACO);
      y = i * (TAM + ESPACO);

      DrawRectangle(x, y, TAM, TAM,
                    LIGHTGRAY); // caso base: todo o mapa é caminho livre
      switch (j->mapa[i][k]) {
      case '#':
        DrawRectangle(x, y, TAM, TAM, DARKGRAY); // obstaculo
        break;
      case 'P': // jogador
        DrawRectangle(x, y, TAM - 10, TAM - 10, MAGENTA);
        DrawText("P", x, y, 24, RAYWHITE);
        break;
      case 'C': // cristal
        DrawCircle(x, y, 30, GOLD);
        break;
      case 'R': // recuperacao
        DrawRectangle(x, y, TAM - 10, TAM - 10, DARKGREEN);
        DrawText("+", x, y, 24, RAYWHITE);
        break;
      case 'A': // armadilha
        DrawRectangle(x, y, TAM - 10, TAM - 10, RED);
        DrawText("A", x, y, 24, RAYWHITE);
        break;
      case 'E': // evento
        DrawRectangle(x, y, TAM - 10, TAM - 10, PURPLE);
        DrawText("?", x, y, 24, RAYWHITE);
        break;
      case 'S': // saida
        DrawRectangle(x, y, TAM - 10, TAM - 10, BLUE);
        DrawText("S", x, y, 24, RAYWHITE);
        break;
      }
    }
  }
}
