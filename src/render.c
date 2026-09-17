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
  render_list((char *[]){"Novo Jogo", "Continuar", "Sair"}, 3);
  printf("\n> ");
}
void render_input() { printf("Input game %s\n", game.input); }
void render_end() { printf("saindo do game ...\n"); }
void render_invalidOption() { printf("Opção invalida, digite novamente\n"); }
void render_notImplemetetion() {
  printf("Opção em desenvolvimento, selecione outra\n> ");
}

void render_newGame() { printf("Inciando novo jogo\n"); }

void render_game() {
  char *name = "Jogador";

  printf("Caregando jogo ...\n");
  printf("Bem vindo de volta %s !!!", name);
}

void render() {
  switch (game.error) {
  case GameError_none:
    break;
  case GameError_invalidOption:
    render_invalidOption();
    game.error = GameError_none;
    return;
  }

  switch (game.menu) {
  case GameMenu_none:
    render_menu();
    return;
  case GameMenu_new:
    render_newGame();
    render_notImplemetetion();
    return;
  case GameMenu_continue:
    render_game();
    return;
  case GameMenu_exit:
    render_end();
    return;
  }
}
