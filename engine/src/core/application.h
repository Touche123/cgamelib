#pragma once

#include "defines.h"
struct game;

KAPI b8 application_create(struct game *game_inst);
KAPI b8 application_run();