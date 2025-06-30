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

namespace Scenes
{
    std::unique_ptr<Scene> main_scene;
    std::unique_ptr<Scene> other_scene;
}

Game game;

void UpdateDrawFrame();

int main(void)
{
	InitWindow(game.WIDTH, game.HEIGHT, game.TITLE.c_str());
	game.Init();

	Scenes::main_scene = std::make_unique<Scene>();
    Scenes::other_scene = std::make_unique<Scene>();

    game.SetScene(Scenes::main_scene.get());

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
	game.Update();
	game.Draw();
}