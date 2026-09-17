#include "update.h"
#include "game.h"
#include <strings.h>

void update() {
  if (game.menu == GameMenu_exit) {
    game.status = GameStatus_stop;
    return;
  }

  if (strcasecmp(game.input, "Novo Jogo") == 0) {
    game.menu = GameMenu_new;
    return;
  }

  if (strcasecmp(game.input, "Continuar") == 0) {
    game.menu = GameMenu_continue;
    return;
  }

  if (strcasecmp(game.input, "sair") == 0) {
    game.menu = GameMenu_exit;
    return;
  }

  game.error = GameError_invalidOption;
}
