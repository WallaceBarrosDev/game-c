#include "render.h"
#include "game.h"
#include <stdio.h>

void render_msg(const char *msg) { printf("%s\n", msg); }

void render_list(char **list, int size) {
  for (int i = 0; i < size; i++) {
    printf("%s\n", list[i]);
  }
}

void render_menu() {
  render_msg("=>> Bem vindo <<=");
  render_msg("selecione uma opção:\n");
  render_list((char *[]){"Novo Game", "Continuar", "Sair"}, 3);
  printf("\n> ");
}
void render_input() { printf("Input game %s\n", game.input); }
void render_end() { printf("saindo do game ...\n"); }
void render_invalidOption() { printf("Opção invalida, digite novamente\n> "); }

void render() {
  switch (game.error) {
  case GameError_none:
    break;
  case GameError_invalidOption:
    render_invalidOption();
    game.error = GameError_none;
    return;
  }

  switch (game.menuStatus) {
  case GameMenuStatus_init:
    render_menu();
    return;
  case GameMenuStatus_new:
    break;
  case GameMenuStatus_continue:
    break;
  case GameMenuStatus_exit:
    render_end();
    break;
  }

  switch (game.phase) {
  case GamePhase_init:
    // render_init();
    game.phase = GamePhase_input;
    break;
  case GamePhase_input:
    break;
  case GamePhase_stop:
    render_end();
    break;
  }
}
