#ifndef GAME_H
#define GAME_H

#include <vector>
#include <raylib.h>
#include <memory>
#include <string>

#include "../Entity/Entity.hpp"
#include "../Scene/Scene.hpp"

namespace Scenes
{
    extern std::unique_ptr<Scene> main_scene;
    extern std::unique_ptr<Scene> other_scene;
}

class Game
{
public:
    const int WIDTH = 875;
    const int HEIGHT = 455;
    const std::string TITLE = "Level Builder!";

    Camera2D camera;
    std::vector<Rectangle> UI_recs;

    Vector2 world_mouse_pos;
    float CELL_SIZE = 35.f;
    std::vector<Rectangle> cells;
    
    std::vector<std::unique_ptr<Entity>> entities;
    void AddEntity(std::unique_ptr<Entity> entity);

    template <typename T>
    T* GetEntityOfType();

    template <typename T>
    std::vector<T*> GetEntitiesOfType();

    void SetScene(Scene* scene);

    Entity* selected_entity = nullptr;
    bool dragging = false;

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
    for (auto& entity : entities)
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
    for (auto& entity : entities)
    {
        T* result = dynamic_cast<T*>(entity.get());
        if (result != nullptr)
            results.push_back(result);
    }
    return results;
}

#endif