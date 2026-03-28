#pragma once
#include "../include/custom_entities.hpp"

class Player : public MovingEntity{
	uint32_t health;
	std::shared_ptr<GameFr::Camera2D> cam;
	void Move() override;
	void PollKeys();
public:
	void Update() override;
	void ChangeHP(int amount);
	void AssignEssentials(std::shared_ptr<GameFr::Camera2D> cam, std::shared_ptr<GameFr::EventQueue> queue);
	Player(GameFr::Vector2 position, uint32_t width, uint32_t height, float speed);
};
