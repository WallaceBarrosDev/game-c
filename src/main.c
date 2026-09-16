#include "game.h"

// DONE: 1 Fazer menu principal e o exit game;
// TODO: 2 Fazer jogador acessar menu a qualquer momento, sistemas de menus
// TODO: 5 salvar dados em arquivo .txt
// TODO: 3 fazer funcionar o Novo Game
// TODO: 4 fazer funcionar o Continuar

int main(void) {
  gameLoad();
  gameLoop();
  gameClear();
  return 0;
}
