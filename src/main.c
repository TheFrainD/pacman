#include <stdio.h>

#include <raylib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Pacman"

int main(int argc, char **argv) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    while (!WindowShouldClose()) {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        DrawText("Hello, Pacman!", 330, 270, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}