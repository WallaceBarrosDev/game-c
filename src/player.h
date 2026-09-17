#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"

typedef struct {
  const char *name;
  Entity status;
} Player;

extern Player player;

#endif
