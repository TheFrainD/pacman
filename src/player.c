#include "player.h"

#include <assert.h>
#include <stdlib.h>

#include "aabb.h"

#define PLAYER_WIDTH 40.0f
#define PLAYER_HEIGHT 40.0f

void UpdatePlayer(Player *player, Walls *walls, float deltaTime) {
    assert(player != NULL);

    Vector2 translation = {0.0f, 0.0f};

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        translation.x = -1.0f;
    } else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        translation.x = 1.0f;
    }

    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        translation.y = -1.0f;
    } else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        translation.y = 1.0f;
    }

    translation = Vector2Scale(Vector2Normalize(translation), player->speed * deltaTime);

    for (int i = 0; i < walls->count; ++i) {
        if (aabb_collision(
            (Rectangle) { 
                player->position.x + translation.x, 
                player->position.y + translation.y, 
                PLAYER_WIDTH, PLAYER_HEIGHT 
            },
            (Rectangle) {
                walls->positions[i].x, 
                walls->positions[i].y, 
                WALL_WIDTH, WALL_HEIGHT 
            }
        )) {
            return;
        }
    }

    player->position = Vector2Add(player->position, translation);

    player->rect = (Rectangle){ 
        player->position.x, 
        player->position.y, 
        PLAYER_WIDTH, PLAYER_HEIGHT 
    };
}

void DrawPlayer(Player *player) {    
    DrawRectangleRec(player->rect, RED);
}