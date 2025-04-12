#ifndef SCENE_HPP
#define SCENE_HPP

#include <raylib.h>
#include <vector>

#include "../Entity/Entity.hpp"

class Scene
{
public:
    Color bg_color;
    std::vector<std::reference_wrapper<Entity>> entities;

    void Init();
    void Update();
    void Draw();
};

#endif