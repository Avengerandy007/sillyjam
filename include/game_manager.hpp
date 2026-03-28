#pragma once
#include "../External/Raylib/raylib-5.5_linux_amd64/include/raylib.h"
#include "../include/globals.hpp"
#include "../include/player.hpp"
#include "../External/GameFr/include/camera.hpp"
#include "town.hpp"
#include <memory>

class GameManager{
	std::shared_ptr<Player> player;
	std::shared_ptr<GameFr::Camera2D> cam;
	std::shared_ptr<GameFr::EventQueue> eventQueue;
	TownFactory townFactory;
public:
	GameManager();
	void Init();
	void Update();
	void Exit();
};
