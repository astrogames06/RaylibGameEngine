#ifndef GAME_H
#define GAME_H

#include <vector>
#include <raylib.h>
#include <memory>
#include <string>
#include <optional>
#include <queue>

#include "../Entity/Entity.hpp"
#include "../Scene/Scene.hpp"

class Game
{
public:
    const int WIDTH = 800;
    const int HEIGHT = 450;
    const std::string TITLE = "raylib [core] example - basic window";
    Vector2 mouse_pos; // Mouse position relative to camera;
    Camera2D camera;
    
    void AddEntity(std::unique_ptr<Entity> entity);

    template <typename T>
    T* GetEntityOfType(std::optional<Scene*> scene = std::nullopt);

    template <typename T>
    std::vector<T*> GetEntitiesOfType(std::optional<Scene*> scene = std::nullopt);

    void SetScene(Scene* scene);
    void SetStartScene(Scene* scene);

    void Init();
    void Update();
    void Draw();

    void Reset();
private:
    Scene* current_scene;
    Scene* next_scene;
    std::queue<std::unique_ptr<Entity>> pending_entities;
};

template <typename T>
T* Game::GetEntityOfType(std::optional<Scene*> scene)
{
    // Sets the scene that will be checked if it is passed as a parameter
    // Otherwise its gets the current scene
    Scene* selected_scene = scene.has_value() ? scene.value() : current_scene;

    for (auto& entity : selected_scene->entities)
    {
        T* result = dynamic_cast<T*>(entity.get());
        if (result != nullptr)
            return result;
    }
    return nullptr;
}

template <typename T>
std::vector<T*> Game::GetEntitiesOfType(std::optional<Scene*> scene)
{
    // Sets the scene that will be checked if it is passed as a parameter
    // Otherwise its gets the current scene
    Scene* selected_scene = scene.has_value() ? scene.value() : current_scene;

    std::vector<T*> results;
    for (auto& entity : selected_scene->entities)
    {
        T* result = dynamic_cast<T*>(entity.get());
        if (result != nullptr)
            results.push_back(result);
    }
    return results;
}

#endif