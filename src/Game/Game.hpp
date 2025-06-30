#ifndef GAME_H
#define GAME_H

#include <vector>
#include <raylib.h>
#include <memory>
#include <string>

#include "../Entity/Entity.hpp"
#include "../Scene/Scene.hpp"

class Game
{
public:
    const int WIDTH = 875;
    const int HEIGHT = 455;
    const std::string TITLE = "Level Builder!";

    Camera2D camera;

    float CELL_SIZE = 35.f;
    
    void AddEntity(std::unique_ptr<Entity> entity);

    template <typename T>
    T* GetEntityOfType();

    template <typename T>
    std::vector<T*> GetEntitiesOfType();

    void SetScene(Scene* scene);

    void Init();
    void Update();
    void Draw();

    void Reset();
private:
    Scene* current_scene;
};

template <typename T>
T* Game::GetEntityOfType()
{
    for (auto& entity : current_scene->entities)
    {
        T* result = dynamic_cast<T*>(entity.get());
        if (result != nullptr)
            return result;
    }
    return nullptr;
}

template <typename T>
std::vector<T*> Game::GetEntitiesOfType()
{
    std::vector<T*> results;
    for (auto& entity : current_scene->entities)
    {
        T* result = dynamic_cast<T*>(entity.get());
        if (result != nullptr)
            results.push_back(result);
    }
    return results;
}

#endif