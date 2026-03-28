#include "../include/town.hpp"
#include <iostream>
#include <memory>

Town::Town(const GameFr::Vector2 pos, const uint32_t width, const uint32_t height, const uint32_t riches, const uint32_t policePresence, std::shared_ptr<GameFr::EventQueue> queue, std::shared_ptr<GameFr::Camera2D> camera){
	position = pos;
	this->width = width;
	this->height = height;
	this->riches = riches;
	this->policePresence = policePresence;
	cam = camera;
	eventInterface.AssignQueue(queue);
}

void Town::Update(){
	std::shared_ptr<const GameFr::Event> targetedEvent = eventInterface.Listen(GetPtr());
	if (targetedEvent){
		std::clog << "A town has been pinged\n";
	}
	
	GetRenderingPosition(*cam);
	if (onScreen){
		DrawRectangle(renderingPosition.X, renderingPosition.Y, width, height, RED);
	}
}

void TownFactory::AssignEssentials(std::shared_ptr<Player> pl, std::shared_ptr<GameFr::EventQueue> q, std::shared_ptr<GameFr::Camera2D> camera){
	player = pl;
	queue = q;
	cam = camera;
	eventInterface.AssignQueue(queue);
}

TownFactory::TownFactory() : random(0, 1){}

void TownFactory::CreateTown(){
	GameFr::Vector2 pos;
	uint32_t riches, policePresence;

	random.ChangeRange(player->position.X - 10, player->position.Y + 10);
	pos.X = random.GetRandomNumber();
	random.ChangeRange(player->position.Y - 10, player->position.Y + 10);
	pos.Y = random.GetRandomNumber();

	random.ChangeRange(100, 500);
	riches = random.GetRandomNumber();
	random.ChangeRange(100, 200);
	policePresence = random.GetRandomNumber();

	comuna.push_back(std::make_shared<Town>(pos, 50, 50, riches, policePresence, queue, cam));
}

void TownFactory::UpdateTowns(){
	for(std::shared_ptr<Town>& t : comuna){
		t->Update();
	}
}

void TownFactory::Update(){
	std::shared_ptr<const GameFr::Event> ev = eventInterface.Listen(GameFr::Event::Types::ADD_TOWN);
	if (ev){
		CreateTown();
	}
}
