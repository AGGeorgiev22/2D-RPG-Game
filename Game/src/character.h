#pragma once
#include <raylib.h>

class Character {
public:
	Character();
	void Movement();
	void Timer();
	void Draw();
	Vector2 playerPosition;
	bool moving = false;

private:

	Texture2D ManRight;
	Texture2D ManLeft;
	Texture2D Man;

	float frameWidth;
	float frameHeight;

	Rectangle frames[4];
	int currentFrame;
	float frameRate;
	float frameTimer;

	Vector2 speed;
};