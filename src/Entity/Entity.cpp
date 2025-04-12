#include "Entity.hpp"

void Entity::Init()
{

}

void Entity::Update()
{

}

void Entity::Draw()
{
    DrawTexturePro(texture,
        {0, 0, (float)texture.width, (float)texture.height},
        {position.x, position.y, (float)texture.width, (float)texture.height},
        origin,
        angle,
        WHITE
    );
}