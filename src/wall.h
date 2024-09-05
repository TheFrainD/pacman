#pragma once

#define WALL_WIDTH 64
#define WALL_HEIGHT 64

#include <raylib.h>
#include <raymath.h>

typedef struct Walls {
    Vector2 *positions;
    int count;
} Walls;

void DrawWall(Vector2 position);