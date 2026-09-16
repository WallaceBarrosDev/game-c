#include "game.h"
#include "input.h"
#include "render.h"
#include "update.h"
#include <stdio.h>

Game game = {
    .status = GameStatus_run,
    .phase = GamePhase_init,
    .error = GameError_none,
    .menuStatus = GameMenuStatus_init,
    .input = "",
};

void gameLoad() {}

void gameLoop() {
  while (game.status) {
    render();
    input();
    update();
  }
}

void gameClear() {
  printf("Digite qualquer coisa para finalizar ...\n");
  getchar();
}
