#include "wall.h"

#define WALL_COLOR GRAY

void DrawWall(Vector2 position) {
    Rectangle rect = {
        position.x, 
        position.y, 
        WALL_WIDTH, WALL_HEIGHT
    };
    DrawRectangleRec(rect, WALL_COLOR);
}