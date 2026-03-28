#pragma once
#include "../External/GameFr/include/entities.hpp"
#include "../External/Raylib/raylib-5.5_linux_amd64/include/raylib.h"

class Player : public GameFr::Entity2D{
	GameFr::Vector2 direction;	
	Rectangle rayrect;
	float speed;
	std::shared_ptr<GameFr::Camera2D> cam;
	GameFr::EventInterface eventInterface;

	void Move();

public:
	void Update() override;
	void AssignEssentials(std::shared_ptr<GameFr::Camera2D> cam, std::shared_ptr<GameFr::EventQueue> queue);
	Player(GameFr::Vector2 position, uint32_t width, uint32_t height, float speed);
};
