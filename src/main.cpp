#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#include "Game/Game.hpp"

Game game;

void UpdateDrawFrame();

int main(void)
{
	game.WIDTH = 840;
	game.HEIGHT = 480;
	InitWindow(game.WIDTH, game.HEIGHT, "raylib [core] example - basic window");

	Scene main;
	main.bg_color = RED;
	main.Init();

	Entity player;
	player.position = {300, 300};
	player.texture = LoadTexture("astro.png");

	game.AddEntity(player, 0); // Add to first scene

	game.Init();
	#if defined(PLATFORM_WEB)
    	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
	#else
		SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
		//--------------------------------------------------------------------------------------

		// Main game loop
		while (!WindowShouldClose())    // Detect window close button or ESC key
		{
			UpdateDrawFrame();
		}
	#endif

	CloseWindow();

	return 0;
}

void UpdateDrawFrame()
{
	std::cout << game.current_scene->entities.size() << '\n';
	game.Update();
	game.Draw();
}