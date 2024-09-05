#include "player.h"

#include <assert.h>
#include <stdlib.h>

#define PLAYER_WIDTH 40.0f
#define PLAYER_HEIGHT 40.0f

void UpdatePlayer(Player *player, float deltaTime) {
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

    player->position = Vector2Add(player->position, Vector2Scale(Vector2Normalize(translation), player->speed * deltaTime));
}

void DrawPlayer(Player *player) {
    Rectangle playerRect = { 
        player->position.x - (PLAYER_WIDTH / 2), 
        player->position.y - (PLAYER_HEIGHT / 2), 
        PLAYER_WIDTH, PLAYER_HEIGHT 
    };
    DrawRectangleRec(playerRect, RED);
}