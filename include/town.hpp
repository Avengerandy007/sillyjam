#pragma once
#include "../include/player.hpp"
#include <memory>
#include <vector>
#include "../External/GameFr/include/util/Randomizer.hpp"

class Town : public EventTiedEntity{
	uint32_t riches;
	uint32_t policePresence;
	std::shared_ptr<GameFr::Camera2D> cam;
public:
	void Update() override;
	Town(const GameFr::Vector2 pos, const uint32_t width, const uint32_t height, const uint32_t riches, const uint32_t policePresence, std::shared_ptr<GameFr::EventQueue> queue, std::shared_ptr<GameFr::Camera2D> camera);
};

class TownFactory{
	std::vector<std::shared_ptr<Town>> comuna;
	std::shared_ptr<GameFr::EventQueue> queue;
	std::shared_ptr<GameFr::Camera2D> cam;
	std::shared_ptr<Player> player;
	GameFr::EventInterface eventInterface;
	GameFr::Randomizer random;
public:
	void AssignEssentials(std::shared_ptr<Player> pl, std::shared_ptr<GameFr::EventQueue> q, std::shared_ptr<GameFr::Camera2D> camera);
	TownFactory();
	void CreateTown();
	void UpdateTowns();
	void Update();
};
