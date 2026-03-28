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
	Push(direction, speed);
}

void Player::Update(){
	Move();

	GetRenderingPosition(*cam);
	if (onScreen){
		DrawRectangle(renderingPosition.X - width / 2, renderingPosition.Y - height / 2, width, height, BLUE);
	}
}

void Player::AssignEssentials(std::shared_ptr<GameFr::Camera2D> cam, std::shared_ptr<GameFr::EventQueue> queue){
	this->cam = cam;
	eventInterface.AssignQueue(queue);
}


Player::Player(GameFr::Vector2 position, uint32_t width, uint32_t height, float speed){
	this->position = position;
	this->width = width;
	this->height = height;
	this->speed = speed;
}
