#include "input.h"
#include "game.h"
#include <ctype.h>
#include <stdio.h>

void input() {
  if (game.menu == GameMenu_exit)
    return;

  scanf("%99[^\n]", game.input);
  getchar();

  for (int i = 0; game.input[i] != '\0'; i++)
    game.input[i] = tolower(game.input[i]);
}
