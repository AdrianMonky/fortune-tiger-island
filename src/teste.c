#include "jogo.h"
#include "raylib.h"
#define MAPA "../mapas/map1.txt"

int main() {
  Jogo j;
  InitWindow(LARGURA_TELA, ALTURA_TELA, "teste");

  while (!WindowShouldClose()) {
    BeginDrawing();
    CarregarMapa(MAPA, &j);
    DesenharJogo(&j);
    EndDrawing();
  }

  return 0;
}
