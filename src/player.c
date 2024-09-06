#include "player.h"

#include <assert.h>
#include <stdlib.h>

#include "aabb.h"

#define PLAYER_WIDTH 40.0f
#define PLAYER_HEIGHT 40.0f

void UpdatePlayer(Player *player, Walls *walls, float deltaTime) {
    assert(player != NULL);

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        player->direction = (Vector2){ -1.0f, 0.0f };
    } else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        player->direction = (Vector2){ 1.0f, 0.0f };
    } else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        player->direction = (Vector2){ 0.0f, -1.0f };
    } else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        player->direction = (Vector2){ 0.0f, 1.0f };
    }

    Vector2 translation = Vector2Scale(player->direction, player->speed * deltaTime);

    bool collision = false;
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
            collision = true;
            break;
        }
    }

    if (!collision) {
        player->position = Vector2Add(player->position, translation);
    }
    
    player->rect = (Rectangle){ 
        player->position.x, 
        player->position.y, 
        PLAYER_WIDTH, PLAYER_HEIGHT 
    };
}

void DrawPlayer(Player *player) {    
    DrawRectangleRec(player->rect, RED);
}