#pragma once

#include "defines.h"

typedef struct game {

  b8 (*initialize)(struct game *game_inst);
  b8 (*update)(struct game *game_inst, f32 delta_time);
  b8 (*render)(struct game *game_inst, f32 delta_time);
  void *state;
} game;