#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>

#include "player.h"
#include "wall.h"

#define MAP_WIDTH 8
#define MAP_HEIGHT 10
int map[] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 1, 0, 0, 1,
    1, 0, 0, 0, 1, 0, 0, 1,
    1, 0, 0, 0, 1, 0, 0, 1,
    1, 0, 9, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 1, 0, 0, 0, 1,
    1, 0, 0, 1, 0, 0, 0, 1,
    1, 0, 0, 1, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
};

#define WINDOW_WIDTH MAP_WIDTH * WALL_WIDTH
#define WINDOW_HEIGHT MAP_HEIGHT * WALL_HEIGHT
#define WINDOW_TITLE "Pacman"

Player player = { 0 };
Walls walls = { 0 };

Walls GetWalls() {
    Walls walls = { 0 };
    for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; ++i) {
        if (map[i] == 1) {
            ++walls.count;
        }
    }

    walls.positions = (Vector2 *)malloc(sizeof(Vector2) * walls.count);

    int index = 0;
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            if (map[y * MAP_WIDTH + x] == 1) {
                walls.positions[index++] = (Vector2){ x * WALL_WIDTH, y * WALL_HEIGHT };
            }
        }
    }

    return walls;
}

void Update(float deltaTime) {
    UpdatePlayer(&player, &walls, deltaTime);
}

void Draw() {
    BeginDrawing(); 
    ClearBackground(RAYWHITE);
    
    DrawPlayer(&player);

    for (int i = 0; i < walls.count; ++i) {
        DrawWall(walls.positions[i]);
    }

    EndDrawing();
}

int main(int argc, char **argv) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    walls = GetWalls();

    for (int x = 0; x < MAP_WIDTH; ++x) {
        for (int y = 0; y < MAP_HEIGHT; ++y) {
            if (map[y * MAP_WIDTH + x] == 9) {
                player.position = (Vector2){x * WALL_WIDTH, y * WALL_HEIGHT};
                break;
            }
        }
    }

    player.speed = 100.0f;
    player.direction = (Vector2){ -1.0f, 0.0f };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        Update(deltaTime); 
        Draw();
    }

    CloseWindow();

    return 0;
}