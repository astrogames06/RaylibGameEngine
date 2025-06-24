#include "Game.hpp"

#include <iostream>
#include <algorithm>
#include <raygui.h>

namespace Scenes
{
    std::unique_ptr<Scene> main_scene;
    std::unique_ptr<Scene> other_scene;
}

void Game::Init()
{
    Scenes::main_scene = std::make_unique<Scene>();
    Scenes::other_scene = std::make_unique<Scene>();

    SetScene(Scenes::main_scene.get());
}
    
void Game::Update()
{
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

    if (IsKeyPressed(KEY_E))
    {
        if (current_scene == Scenes::main_scene.get()) current_scene = Scenes::other_scene.get();
        else current_scene = Scenes::main_scene.get();
    }

    if (IsKeyPressed(KEY_SPACE))
    {
        std::unique_ptr<Entity> new_entity = std::make_unique<Entity>();
        new_entity->x = GetRandomValue(0, WIDTH);
        new_entity->y = GetRandomValue(0, HEIGHT);
        AddEntity(std::move(new_entity));
    }

    if (IsKeyPressed(KEY_B))
    {
        current_scene->entities[0]->Delete();
    }
}

void Game::Draw()
{
    // std::cout << mode << '\n';
    // std::cout << GetEntitiesOfType<Enemy>().size() << '\n';
    
    BeginDrawing();
    ClearBackground(WHITE);

    for (std::unique_ptr<Entity>& entity : current_scene->entities)
    {
        entity->Draw();
    }

    EndDrawing();
}

void Game::Reset()
{

}

void Game::AddEntity(std::unique_ptr<Entity> entity)
{
    current_scene->entities.push_back(std::move(entity));
}
void Game::SetScene(Scene* scene)
{
    current_scene = scene;
    current_scene->Init();
}