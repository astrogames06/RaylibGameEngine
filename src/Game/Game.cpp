#include "Game.hpp"

#include <iostream>
#include <algorithm>
#include <raygui.h>

void Game::Init()
{
    camera.target = { 0, 0 };
    camera.offset = { 0, 0 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}
    
void Game::Update()
{
    current_scene->Update();
    for (std::unique_ptr<Entity>& entity : current_scene->entities)
    {
        entity->Update();
    }

    // Remove it if Entity->remove = true;
    current_scene->entities.erase(
        std::remove_if(
            current_scene->entities.begin(),
            current_scene->entities.end(),
            [](const std::unique_ptr<Entity>& e) { return e->remove; }
        ),
        current_scene->entities.end()
    );
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(current_scene->background_color);
    BeginMode2D(camera);

    current_scene->Draw();
    for (std::unique_ptr<Entity>& entity : current_scene->entities)
    {
        entity->Draw();
    }

    EndMode2D();
    EndDrawing();
}

void Game::Reset()
{

}

void Game::AddEntity(std::unique_ptr<Entity> entity)
{
    if (current_scene != nullptr)
    {
        entity->Init();
        current_scene->entities.push_back(std::move(entity));
    }
    else
        std::cout << "! WARNING CURRENT SCENE IS NULLPTR !\n";
}
void Game::SetScene(Scene* scene)
{
    current_scene = scene;
    current_scene->Init();
}