#include "Scene.hpp"

#include "../Game/Game.hpp"

extern Game game;

void Scene::Init()
{
    game.scenes.push_back(*this);
    for (Entity& entity : entities)
    {
        entity.Init();
    }
}

void Scene::Update()
{
    for (Entity& entity : entities)
    {
        entity.Update();
    }
}

void Scene::Draw()
{
    for (Entity& entity : entities)
    {
        entity.Draw();
        DrawRectangleLines(entity.position.x, entity.position.y, entity.texture.width, entity.texture.height, GREEN);
    }
}