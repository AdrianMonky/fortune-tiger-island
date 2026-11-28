#ifndef JOGO_H
#define JOGO_H

// CONSTANTES DO JOGO
#define MAX_LINHAS 20
#define MAX_COLUNAS 40
#define TAM_MSG 80
#define EM_ANDAMENTO 0
#define VITORIA 1
#define DERROTA 2
#define DESISTIU 3
#define ALTURA_TELA 750
#define LARGURA_TELA 1160

typedef struct {
  char mapa[MAX_LINHAS][MAX_COLUNAS];
  int linhas, colunas;   // dimensões lidas do arquivo
  int linhasJ, colunasJ; // posição do jogador
  int energia;
  int minimoCristais;
  int cristais, turnos;
  char msg[TAM_MSG];
} Jogo;

/*
 * ===================================================
 *  FUNÇÕES DO MAPA
 * ===================================================
 */

int CarregarMapa(const char *nomeArquivo, Jogo *j);
void DesenharJogo(Jogo *j);
int ValidaMovimento(Jogo *j, int comando);

#endif // !JOGO_H
