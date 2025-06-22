#include "Game.hpp"

#include <iostream>
#include <algorithm>
#include <raygui.h>

void Game::Init()
{

}
    
void Game::Update()
{

}

void Game::Draw()
{
    // std::cout << mode << '\n';
    // std::cout << GetEntitiesOfType<Enemy>().size() << '\n';
    
    BeginDrawing();
    ClearBackground(WHITE);


    EndDrawing();
}

void Game::Reset()
{

}