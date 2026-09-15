#include "entity.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

// TODO: modularizar as funcões e estruturas relacionadas a combate em um
// arquivo proprio;

typedef struct {
  Entity *list;
  int size;
  int maxSize;
} Entitys;

Entitys entitysCreat(int maxSize) {
  Entitys entitys;
  entitys.list = malloc(sizeof(Entity) * maxSize);
  if (entitys.list == NULL) {
    printf("--- LOG: Erro ao alocar vetor de entidades ---\n");
    return entitys;
  }
  entitys.size = 0;
  entitys.maxSize = maxSize;
  return entitys;
}

void entitysAdd(Entitys *entitys, Entity newEntity) {
  if (entitys->size == entitys->maxSize) {
    printf("---LOG: Vetor de inimigos cheio---\n");
    return;
  }

  entitys->list[entitys->size++] = newEntity;
}

void entitysRemove(Entitys *entitys, int target) {
  // TODO: remover os inimigos mas realocando o vetor para a esquerda a partir
  // da posicão que foi eliminada.

  for (int i = target; i <= entitys->size - 1; i++) {
    entitys->list[i] = entitys->list[i + 1];
  }

  entitys->size--;
  // entitys->list[target] = entitys->list[--entitys->size];
}

void entitysShowAll(Entitys *entitys) {
  for (int i = 0; i < entitys->size; i++) {
    printf("[%d] - Nome: %s | Vida: %d, Força: %d\n", i, entitys->list[i].name,
           entitys->list[i].life, entitys->list[i].strength);
  }
}

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
      printf("Player eliminiu todos os inimigos\n");
      break;
    }

    if (entityAttack(&enemys->list[0], player)) {
      printf("%s, eliminou player, combate finalizado.\n",
             enemys->list[0].name);
      break;
    }
  }
}

int main(void) {
  Entity player = entityCreate(entityType_human);
  printf("Log: ok\n");

  // TODO: erro na funcão ao setar o nome, função encerando programa.

  entitySetName(&player, "Wallace");
  printf("Log: ok 2\n");
  Entitys enemys = entitysCreat(5);
  printf("Log: ok 3\n");

  /*
    entitysAdd(&enemys, entityCreate(entityType_goblin));
    entitysAdd(&enemys, entityCreate(entityType_human));
    entitysAdd(&enemys, entityCreate(entityType_ork));

    combat(&player, &enemys);
  */
  return 0;
}
