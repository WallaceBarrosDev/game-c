#include "input.h"
#include "game.h"
#include <stdio.h>

void input() {
  if (game.menuStatus == GameMenuStatus_exit)
    return;

  scanf("%s", game.input);
  getchar();
}
