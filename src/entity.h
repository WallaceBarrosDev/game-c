#ifndef ENTITY_H
#define ENTITY_H

#include <stdbool.h>

typedef struct {
  const char *name;
  int life;
  int strength;
} Entity;

typedef enum {
  entityType_human,
  entityType_goblin,
} EntityType;

Entity entityCreate(EntityType entityType);
void entitySetName(Entity *entity, const char *newName);
void entityShowStats(const Entity *entity);
bool entityAttack(Entity *attacker, Entity *target);

#endif
