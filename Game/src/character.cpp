#include "character.h"

Character::Character() {

    ManRight = LoadTexture("assets/walking-man-right.png");
    ManLeft = LoadTexture("assets/walking-man-left.png");
    Man = ManRight;

    frameHeight = 80;
    frameWidth = 40;

    frames[0] = { 0, 0, frameWidth, frameHeight };
    frames[1] = { 0, frameHeight, frameWidth, frameHeight };
    frames[2] = { 0, frameHeight * 2, frameWidth, frameHeight };
    frames[3] = { 0, frameHeight * 3, frameWidth, frameHeight };

    currentFrame = 0;
    frameRate = 0.1f;
    frameTimer = 0.0f;

    playerPosition.x = 600;
    playerPosition.y = 500;
    
    speed.x = 2;
    speed.y = 2;

}

void Character::Timer() {
    frameTimer += GetFrameTime();
    if (frameTimer >= frameRate) {
        frameTimer = 0.0f;
        currentFrame++;
        if (currentFrame >= 3) {
            currentFrame = 0;
        }
    }
}

void Character::Movement() {
        if (IsKeyDown(KEY_W) && playerPosition.y >= -10) {
           playerPosition.y -= speed.y;
        }

        if (IsKeyDown(KEY_S) && playerPosition.y <= GetScreenHeight() - 90) {
            playerPosition.y += speed.y;
        }

        if (IsKeyDown(KEY_A) && playerPosition.x >= -25) {
            playerPosition.x -= speed.x;
            Man = ManLeft;
        }

        if (IsKeyDown(KEY_D) && playerPosition.x <= GetScreenWidth() - 80) {
            playerPosition.x += speed.x;
            Man = ManRight;
        }

        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_S) || IsKeyDown(KEY_A) || IsKeyDown(KEY_D)) {
            moving = true;
        }

        else moving = false;

        if (IsKeyDown(KEY_W) && IsKeyDown(KEY_S) || IsKeyDown(KEY_A) && IsKeyDown(KEY_D)) {
            moving = false;
        }
    }



void Character::Draw() {
    if (moving) {
        DrawTextureRec(Man, frames[currentFrame], playerPosition, WHITE);
    }

    else{
        DrawTextureRec(Man, frames[0], playerPosition, WHITE);
    }
}