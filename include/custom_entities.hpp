#pragma once
#include "../External/GameFr/include/entities.hpp"
#include "../External/Raylib/raylib-5.5_linux_amd64/include/raylib.h"

class EventTiedEntity : public GameFr::Entity2D{
protected:
	GameFr::EventInterface eventInterface;
};

class MovingEntity : public EventTiedEntity{
protected:
	GameFr::Vector2 direction;	
	Rectangle rayrect;
	float speed;
	virtual void Move() = 0;
};
