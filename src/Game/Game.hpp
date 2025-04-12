#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <iostream>

#include "../Scene/Scene.hpp"

class Game
{
public:
    std::vector<Scene> scenes;
    Scene* current_scene;

    int WIDTH;
    int HEIGHT;

    void Init();
    void Update();
    void Draw();

    void AddEntity(Entity& entity, int scene);
};

#endif