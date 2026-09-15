#include "combat.h"
#include "entity.h"
#include "entitys.h"
#include <stdio.h>

int main(void) {
  Entity player = entityCreate(entityType_human);
  entitySetName(&player, "Wallace");

  Entitys enemys = entitysCreat(5);
  entitysAdd(&enemys, entityCreate(entityType_goblin));
  entitysAdd(&enemys, entityCreate(entityType_goblin));
  entitysAdd(&enemys, entityCreate(entityType_goblin));

  combat(&player, &enemys);

  getchar();
  printf("Fim de jogo ...\n");
  getchar();
  return 0;
}
