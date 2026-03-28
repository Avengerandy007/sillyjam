#include "../include/game_manager.hpp"

GameManager::GameManager(){
	player = std::make_shared<Player>(GameFr::Vector2(0, 0), 50, 50, 1);
	cam = std::make_shared<GameFr::Camera2D>(GameFr::Camera2D::Modes::FOLLOW, player, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	eventQueue = std::make_shared<GameFr::EventQueue>();
	player->AssignEssentials(cam, eventQueue);
	townFactory.AssignEssentials(player, eventQueue, cam);
}

void GameManager::Init(){
	InitWindow(SCREEN_SIZE_X, SCREEN_SIZE_Y, "silly");
	SetTargetFPS(60);
	townFactory.CreateTown();
}

void GameManager::Update(){
	while(!WindowShouldClose()){
		BeginDrawing();
		
		cam->Update();
		player->Update();
		townFactory.Update();
		townFactory.UpdateTowns();
		
		ClearBackground(BLACK);

		EndDrawing();
	}
}

void GameManager::Exit(){
	CloseWindow();
}
