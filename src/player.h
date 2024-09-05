#pragma once

#include <raylib.h>
#include <raymath.h>

typedef struct Player {
    Vector2 position;
    float speed;
} Player;

void UpdatePlayer(Player *player, float deltaTime);
void DrawPlayer(Player *player);