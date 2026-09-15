#include <stdio.h>
#include <strings.h>

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

GameStatus gameStatus = GameStatus_run;
GamePhase gamePhase = GamePhase_init;
char input_game[MAX_STRING];

void gameLoad() {};

void input() {
  if (gamePhase == GamePhase_stop)
    return;

  scanf("%s", input_game);
  getchar();
}

void update() {
  if (gamePhase == GamePhase_stop) {
    gameStatus = GameStatus_stop;
  }

  if (strcasecmp(input_game, "stop") == 0) {
    gamePhase = GamePhase_stop;
    return;
  }
}

void render_init() { printf("=>> Bem vindo <<=\n"); }

void render_setInput(const char *msg) { printf("%s\n> ", msg); }

void render_input() { printf("Input game %s\n", input_game); }

void render_end() { printf("saido do game ...\n"); }

void render() {

  switch (gamePhase) {
  case GamePhase_init:
    render_init();
    render_setInput("Digite alguma coisa");
    gamePhase = GamePhase_input;
    break;
  case GamePhase_input:
    render_input();
    render_setInput("Digite um comando");
    break;
  case GamePhase_stop:
    render_end();
    break;
  }
}

void gameClear() {
  printf("Digite qualuqer coisa para finalizar ...\n");
  getchar();
};

void gameLoop() {
  while (gameStatus) {
    render();
    input();
    update();
  }
}

int main(void) {
  gameLoad();

  gameLoop();

  gameClear();

  return 0;
}
