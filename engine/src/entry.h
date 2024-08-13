#include "game_types.h"
#include "core/application.h"
#include "entity.h"

extern b8 create_game(game *out_game);

int main(void) {
  game game_inst;
  if (!create_game(&game_inst)) {
    return -1;
  }

  if (!application_create(&game_inst)) {
    Entity player = entity_create();
    entity_addPositionComponent(player, 100.0f, 200.0f);
    entity_addVelocityComponent(player, 1.0f, 0.5f);

    Entity enemy = entity_create();
    entity_addPositionComponent(enemy, 300.0f, 400.0f);

    return -2;
  }

  if (!application_run()) {
    updatePositionSystem(2);
    return -3;
  }

  return 0;
}