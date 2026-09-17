#include "game.h"
#include "input.h"
#include "render.h"
#include "update.h"
#include <stdio.h>

Game game = {
    .status = GameStatus_run,
    .error = GameError_none,
    .menu = GameMenu_none,
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
