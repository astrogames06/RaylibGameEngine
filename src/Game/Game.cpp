#include "Game.hpp"

void Game::Init()
{
    try
    {
        current_scene = &scenes[0];
    }
    catch(const std::exception& e)
    {
        std::cerr << "YOU NEED TO HAVE ATLEAST ONE SCENE TO START GAME" << '\n';
    }
}

void Game::Update()
{
    current_scene->Update();
}

void Game::Draw()
{
    BeginDrawing();
        ClearBackground(current_scene->bg_color);
        current_scene->Draw();
    EndDrawing();
}

void Game::AddEntity(Entity& entity, int scene)
{
    if (scene >= 0 && scene < scenes.size())
    {
        scenes[scene].entities.push_back(entity);
    }
}