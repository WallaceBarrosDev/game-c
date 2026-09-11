#include "entity.h"
#include <stdbool.h>
#include <stdio.h>

Entity entityCreate(EntityType entityType) {
  Entity entity;

  switch (entityType) {
  case entityType_human:
    entity.name = "Human";
    entity.life = 100;
    entity.strength = 25;
    break;
  case entityType_goblin:
    entity.name = "Goblin";
    entity.life = 50;
    entity.strength = 10;
    break;
  }

  return entity;
}

void entitySetName(Entity *entity, const char *newName) {
  entity->name = newName;
}

bool entityAttack(Entity *attacker, Entity *target) {
  target->life -= attacker->strength;

  printf("%s ataca %s e causa %d de dano!\n", attacker->name, target->name,
         attacker->strength);
  if (target->life <= 0) {
    printf("%s foi derrotado!\n", target->name);
    target->life = 0;
    return true;
  }

  return false;
}

void entityShowStats(const Entity *entity) {
  printf("┌────────────────────┐\n");
  printf("│  ⚷  %-15s│\n", entity->name);
  printf("├────────────────────┤\n");
  printf("│  ❤  Life:     %-4d │\n", entity->life);
  printf("│  ⚔  Strength: %-4d │\n", entity->strength);
  printf("└────────────────────┘\n");
}
