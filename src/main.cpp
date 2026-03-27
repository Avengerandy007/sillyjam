#include <iostream>
#include <memory>
#include "../External/Raylib/raylib-5.5_linux_amd64/include/raylib.h"
#include "../include/player.hpp"
#include "../External/GameFr/include/camera.hpp"

int main(){
    int n;
    std::shared_ptr<Player> pl = std::make_shared<Player>();
    std::shared_ptr<GameFr::Camera2D> cam = std::make_shared<GameFr::Camera2D>(GameFr::Camera2D::Modes::FOLLOW, pl, 500, 500);
    pl->width = 50;
    pl->height = 50;
    pl->speed = 1;
    pl->cam = cam;
    std::cout << "hello";
    InitWindow(500, 500, "silly");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
	BeginDrawing();

	cam->Update();
	pl->Update();

	ClearBackground(BLACK);

	EndDrawing();
    }
    CloseWindow();
    return 0;
}
