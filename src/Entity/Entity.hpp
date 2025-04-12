#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <raylib.h>

class Entity
{
public:
    Texture2D texture;
    Vector2 position;

    float angle = 0.f;
    Vector2 origin = {0,0};

    void Init();
    void Update();
    void Draw();
};

#endif