#include "Game.hpp"

#include <iostream>
#include <algorithm>
#include <raygui.h>

#include "../Utils/null_img.h"
Image null_img;
Texture2D null_tex;

void Game::Init()
{
    camera.target = { 0, 0 };
    camera.offset = { 0, 0 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    null_img.data = NULL_IMG_DATA;
    null_img.format = NULL_IMG_FORMAT;
    null_img.width = NULL_IMG_WIDTH;
    null_img.height = NULL_IMG_HEIGHT;
    null_img.mipmaps = 1;
    null_tex = LoadTextureFromImage(null_img);
}
    
void Game::Update()
{
    mouse_pos = GetScreenToWorld2D(GetMousePosition(), camera);

    // Sets the next scene in queue ! MUST DO FIRST !
    if (next_scene)
    {
        current_scene = next_scene;
        std::cout << "SET Current Scene: " << current_scene << '\n';
        std::cout << "SET Next Scene: " << next_scene << '\n';
        if (current_scene)
            current_scene->Init();
        next_scene = nullptr;
    }

    // Adds queued entities first
    while (!pending_entities.empty())
    {
        pending_entities.front()->Init();
        current_scene->entities.push_back(std::move(pending_entities.front()));
        pending_entities.pop();
    }

    if (current_scene != nullptr)
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
}

void Game::Draw()
{
    BeginDrawing();
    if (current_scene != nullptr)
    {
        ClearBackground(current_scene->background_color);
    }
    BeginMode2D(camera);

    if (current_scene != nullptr)
    {
        current_scene->Draw();
        for (std::unique_ptr<Entity>& entity : current_scene->entities)
        {
            entity->Draw();
        }   
    }

    EndMode2D();

    if (current_scene != nullptr)
    {
        current_scene->DrawUI();
    }
    EndDrawing();
}

void Game::Reset()
{

}

void SetupEntity(Entity* entity)
{
    entity->texture = null_tex;
}
void Game::AddEntity(std::unique_ptr<Entity> entity)
{
    if (current_scene != nullptr)
    {
        SetupEntity(entity.get());
        entity->Init();
        pending_entities.push(std::move(entity));
    }
    else
        std::cout << "! WARNING CURRENT SCENE IS NULLPTR !\n";
}

void Game::SetScene(Scene* scene)
{
    if (next_scene != scene)
        next_scene = scene;
}
void Game::SetStartScene(Scene* scene)
{
    current_scene = scene;
    current_scene->Init();
}