#include <stdio.h>

#include <raylib.h>

#include "player.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Pacman"

Player player = { 0 };

void Update(float deltaTime) {
    UpdatePlayer(&player, deltaTime);
}

void Draw() {
    BeginDrawing(); 
    ClearBackground(RAYWHITE);
    
    DrawPlayer(&player);

    EndDrawing();
}

int main(int argc, char **argv) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    player.position = (Vector2){100, 100};
    player.speed = 100.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        Update(deltaTime); 
        Draw();
    }

    CloseWindow();

    return 0;
}