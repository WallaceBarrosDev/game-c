#ifndef ENTITYS_H
#define ENTITYS_H

#include "entity.h"

typedef struct {
  Entity *list;
  int size;
  int maxSize;
} Entitys;

Entitys entitysCreat(int maxSize);
void entitysAdd(Entitys *entitys, Entity newEntity);
void entitysRemove(Entitys *entitys, int target);
void entitysShowAll(Entitys *entitys);

#endif
