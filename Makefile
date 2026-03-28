ray_win=./External/Raylib/raylib-5.5_win64_mingw-w64/lib/
ray_linx=./External/Raylib/raylib-5.5_linux_amd64/lib/

gamefr_include= \
	-I./External/GameFr/include \
	-I./External/GameFr/include/util

linux:
	g++ $(gamefr_include) -I./include ./src/*.cpp ./External/GameFr/src/*.cpp ./External/GameFr/src/util/*.cpp -o build/silly -L$(ray_linx) -lraylib

windows:
	g++ $(gamefr_include) -I./include ./src/*.cpp ./External/GameFr/src/*.cpp ./External/GameFr/src/util/*.cpp -o build/silly.exe -L$(ray_win) -lraylib -lopengl32 -lgdi32 -lwinmm -static -static-libgcc -static-libstdc++
