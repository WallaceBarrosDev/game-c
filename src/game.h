#ifndef GAME_H
#define GAME_H

#define MAX_STRING 254

typedef enum {
  GameStatus_stop,
  GameStatus_run,
  GameStatus_pause,
} GameStatus;

typedef enum {
  GamePhase_init,
  GamePhase_input,
  GamePhase_stop,
} GamePhase;

typedef enum {
  GameMenuStatus_init,
  GameMenuStatus_new,
  GameMenuStatus_continue,
  GameMenuStatus_exit,
} GameMenuStatus;

typedef enum { GameError_none, GameError_invalidOption } GameError;

typedef struct {
  GameStatus status;
  GamePhase phase;
  GameError error;
  GameMenuStatus menuStatus;
  char input[MAX_STRING];
} Game;

extern Game game;

void gameLoad(void);
void gameLoop(void);
void gameClear(void);

#endif
