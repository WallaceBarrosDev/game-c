#include "combat.h"
#include "entity.h"
#include "entitys.h"
#include <stdbool.h>
#include <stdio.h>

void combat(Entity *player, Entitys *enemys) {
  int target = 0;
  while (true) {
    if (enemys->size < 1) {
      break;
    }

    if (enemys->size > 1) {
      printf("selecione um alvo\n");
      entitysShowAll(enemys);
      printf("> ");
      scanf("%d", &target);
      getchar();
      if (entityAttack(player, &enemys->list[target])) {
        printf("Player eliminiu %s %d\n", enemys->list[target].name, target);
        entitysRemove(enemys, target);
      }

      for (int i = 0; i < enemys->size; i++) {
        if (entityAttack(&enemys->list[i], player)) {
          printf("Player foi eleminado\n");
          return;
        }
      }

      continue;
    }

    if (entityAttack(player, &enemys->list[0])) {
      printf("Player eliminiu todos os inimigos, combate finalizado\n");
      break;
    }

    if (entityAttack(&enemys->list[0], player)) {
      printf("%s, eliminou player, combate finalizado.\n",
             enemys->list[0].name);
      break;
    }

    printf("clique em qualuqer botão para continuar ...\n");
    getchar();
  }
}
