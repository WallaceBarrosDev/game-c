#ifndef GAME_H
#define GAME_H

#define MAX_STRING 254

typedef enum {
  GameStatus_stop,
  GameStatus_run,
  GameStatus_pause,
} GameStatus;

typedef enum {
  GameMenu_none,
  GameMenu_new,
  GameMenu_continue,
  GameMenu_exit,
} GameMenu;

typedef enum { GameError_none, GameError_invalidOption } GameError;

typedef struct {
  GameStatus status;
  GameError error;
  GameMenu menu;
  char input[MAX_STRING];
} Game;

extern Game game;

void gameLoad(void);
void gameLoop(void);
void gameClear(void);

#endif
