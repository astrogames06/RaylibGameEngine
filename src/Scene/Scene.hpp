#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <raylib.h>

#include "../Entity/Entity.hpp"

class Scene
{
public:
    Color background_color = WHITE;
    std::vector<std::unique_ptr<Entity>> entities;

    virtual ~Scene() = default;
    virtual void Init() {}
    virtual void Update() {}
    virtual void Draw() {}
};

#endif