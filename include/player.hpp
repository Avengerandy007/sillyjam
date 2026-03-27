#pragma once
#include "../External/GameFr/include/entities.hpp"
#include "../External/Raylib/raylib-5.5_linux_amd64/include/raylib.h"
#include <memory>

class Player : public GameFr::Entity2D{
	GameFr::Vector2 direction;	
	Rectangle rayrect;

	void Move();

	GameFr::EventInterface eventInterface;
public:
	std::shared_ptr<GameFr::Camera2D> cam;
	float speed;
	void Update() override;
};
