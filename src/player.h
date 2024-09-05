#pragma once

#include <raylib.h>
#include <raymath.h>

#include "wall.h"

typedef struct Player {
    Vector2 position;
    float speed;
    Rectangle rect;
} Player;

void UpdatePlayer(Player *player, Walls *walls, float deltaTime);
void DrawPlayer(Player *player);