#include "game.h"

#include <entry.h>
#include <core/application.h>

b8 create_game(game* out_game) {
  out_game->initialize = game_initialize;
  out_game->update = game_update;
  out_game->render = game_render;

  return TRUE;
}