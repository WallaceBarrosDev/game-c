#include "entitys.h"
#include <stdio.h>
#include <stdlib.h>

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
  for (int i = target; i <= entitys->size - 1; i++) {
    entitys->list[i] = entitys->list[i + 1];
  }
  entitys->size--;
}

void entitysShowAll(Entitys *entitys) {
  for (int i = 0; i < entitys->size; i++) {
    printf("[%d] - Nome: %s | Vida: %d, Força: %d\n", i, entitys->list[i].name,
           entitys->list[i].life, entitys->list[i].strength);
  }
}
