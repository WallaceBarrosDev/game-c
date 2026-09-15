#include "input.h"
#include "game.h"
#include <stdio.h>

void input() {
  if (game.phase == GamePhase_stop)
    return;

  scanf("%s", game.input);
  getchar();
}
