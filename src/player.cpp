#include "../include/player.hpp"
#include <optional>

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

	if (IsKeyDown(KEY_LEFT_SHIFT)) speed = 2;
	else if (speed != 1) speed = 1;

	Push(direction, speed);
}

void Player::PollKeys(){
	if (IsKeyPressed(KEY_T)){
		GameFr::Event ev(GameFr::Event::Types::ADD_TOWN, GetPtr(), nullptr, std::nullopt);
		eventInterface.queue->CreateEvent(std::make_shared<const GameFr::Event>(ev));
	}
}

void Player::ChangeHP(int amount){
	this->health += amount;
}

void Player::Update(){
	Move();
	PollKeys();

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
