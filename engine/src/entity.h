#include "defines.h"

typedef u32 Entity;
#define MAX_ENTITIES 1000
#define MAX_COMPONENTS 1000

typedef struct {
  float x, y;
} PositionComponent;

typedef struct {
  float vx, vy;
} VelocityComponent;

PositionComponent positionComponents[MAX_COMPONENTS];
VelocityComponent velocityComponents[MAX_COMPONENTS];
int entityAlive[MAX_ENTITIES];

typedef enum {
  COMPONENT_POSITION = 1 << 0,
  COMPONENT_VELOCITY = 1 << 1
} ComponentType;

unsigned int entityComponentMask[MAX_ENTITIES];

Entity entity_create() {
  for (Entity e = 0; e < MAX_ENTITIES; e++) {
    if (!entityAlive[e]) {
      entityAlive[e] = 1;
      entityComponentMask[e] = 0;
      return e;
    }
  }
  return MAX_ENTITIES;
}

void entity_destroy(Entity e) {
  entityAlive[e] = 0;
  entityComponentMask[e] = 0;
}

void entity_addPositionComponent(int id, float x, float y) {
  positionComponents[id] = (PositionComponent){x, y};
  entityComponentMask[id] = COMPONENT_POSITION;
}

void entity_addVelocityComponent(Entity e, float vx, float vy) {
  velocityComponents[e] = (VelocityComponent){vx, vy};
  entityComponentMask[e] |= COMPONENT_VELOCITY;
}

void entity_removeComponent(Entity e, ComponentType type) {
  entityComponentMask[e] &= ~type;
}

void updatePositionSystem(float deltaTime) {
  for (Entity e = 0; e < MAX_ENTITIES; e++) {
    if ((entityComponentMask[e] & (COMPONENT_POSITION | COMPONENT_VELOCITY)) ==
        (COMPONENT_POSITION | COMPONENT_VELOCITY)) {

      positionComponents[e].x += velocityComponents[e].vx * deltaTime;
      positionComponents[e].y += velocityComponents[e].vy * deltaTime;
    }
  }
}