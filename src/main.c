#include <stdio.h>

#include <raylib.h>

#include "node.h"

#define WINDOW_WIDTH 240
#define WINDOW_HEIGHT 320
#define WINDOW_TITLE "Pacman"

NodeGroup *nodeGroup;

void Update(float deltaTime) {

}

void Draw() {
    NodeGroupDraw(nodeGroup);
}

int main(int argc, char **argv) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    nodeGroup = NodeGroupCreate();

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        Update(deltaTime);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        Draw();

        EndDrawing();
    }

    NodeGroupFree(&nodeGroup);

    CloseWindow();

    return 0;
}