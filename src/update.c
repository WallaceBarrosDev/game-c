#include "update.h"
#include "game.h"
#include <strings.h>

void update() {
  if (game.phase == GamePhase_stop) {
    game.status = GameStatus_stop;
  }

  if (strcasecmp(game.input, "sair") == 0) {
    game.phase = GamePhase_stop;
    return;
  }

  game.error = GameError_invalidOption;
}
