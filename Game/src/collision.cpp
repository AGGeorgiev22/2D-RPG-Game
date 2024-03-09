#include "collision.h"

Collision::Collision() {
    position.x = 250;
    position.y = 450;
    recWidth = 300;
    recHeight = 250;
    rec1 = { position.x, position.y, recWidth, recHeight };

    player = Character();
    manPosition = player.playerPosition;

    playerArea = { manPosition.x, manPosition.y, 40, 80 };
}

void Collision::CheckCollision() {
    player.Movement();
    player.Timer();

    manPosition = player.playerPosition;
    playerArea = { manPosition.x, manPosition.y, 40, 80 };

    Colliding = CheckCollisionRecs(rec1, playerArea);

    if (Colliding) {
        player.moving = false;
    }
}

void Collision::Draw() {

    DrawRectangleRec(rec1, RED);
}