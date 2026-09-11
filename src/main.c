#include "entity.h"
#include <stdbool.h>
#include <stdio.h>

// TODO: combate de 1 vs varioas entidades;

/*
 * comabat(player, inimigos) {
 *   1. seleciona inimigo
 *   2. ataca
 *   3. todo inimigos atacam
 * }
 *
 * */

void combat(Entity *player, Entity *goblin) {
  while (true) {
    if (entityAttack(player, goblin)) {
      printf("%s ganhou o combate\n", player->name);
      break;
    }
    if (entityAttack(goblin, player)) {
      printf("%s perdeu o combate\n", player->name);
      break;
    }

    printf("digite qualquer botão para continuar ...\n");
    getchar();
  }
}

int main(void) {
  Entity player = entityCreate(entityType_human);
  entitySetName(&player, "Wallace");

  Entity goblin = entityCreate(entityType_goblin);

  combat(&player, &goblin);

  getchar();
  return 0;
}
