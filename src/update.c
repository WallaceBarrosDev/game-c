#include "update.h"
#include "game.h"
#include <strings.h>

void update() {
  if (game.menuStatus == GameMenuStatus_exit) {
    game.status = GameStatus_stop;
    return;
  }

  if (strcasecmp(game.input, "Novo game") == 0) {
    game.menuStatus = GameMenuStatus_new;
    return;
  }

  if (strcasecmp(game.input, "Continuar game") == 0) {
    game.menuStatus = GameMenuStatus_continue;
    return;
  }

  if (strcasecmp(game.input, "sair") == 0) {
    game.menuStatus = GameMenuStatus_exit;
    return;
  }

  game.error = GameError_invalidOption;
}
