#include <iostream>
#include "../include/player.hpp"

void Player::Move(){
	direction.X = 0;
	direction.Y = 0;
	if (IsKeyDown(KEY_A)){
		direction.X = -1;
	}if (IsKeyDown(KEY_S)){
		direction.Y = 1;
	}if (IsKeyDown(KEY_W)){
		direction.Y = -1;
	}if (IsKeyDown(KEY_D)){
		direction.X = 1;
	}
	std::clog << "Pushing with the following directions: " << direction.X << ", " << direction.Y << "\n";
	Push(direction, speed);
}

void Player::Update(){
	Move();

	GetRenderingPosition(*cam);
	if (onScreen){
		DrawRectangle(renderingPosition.X - width / 2, renderingPosition.Y - height / 2, width, height, BLUE);
	}
}
