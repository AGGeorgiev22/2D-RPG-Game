#pragma once
#include <raylib.h>
#include "character.h"

class Collision {
public:
    Collision();
    void Draw();
    void CheckCollision();
    bool Colliding = false;

private:
    Rectangle rec1;

    Vector2 position;

    Character player;
    Vector2 manPosition;
    Rectangle playerArea;

    float recWidth;
    float recHeight;
};