#include "mainProcess.h"

void mainProcess() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Game");
    ToggleFullscreen();
    SetTargetFPS(60);

    Character Player = Character();
    Collision CollisionCheck = Collision();

    //Game Loop
    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(BLACK);

        Player.Movement();
        Player.Timer();
        Player.Draw();

        CollisionCheck.CheckCollision();

        if (CollisionCheck.Colliding) {
            DrawText("Colliding", GetScreenWidth() / 2 - 200, 200, 100, WHITE);
        }

        CollisionCheck.Draw();


        EndDrawing();
    }

    CloseWindow();
}