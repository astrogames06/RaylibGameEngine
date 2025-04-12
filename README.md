# RaylibGameEngine

## How it works!
```cpp
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
```
*current_scene* will be running and each scene has a *vector<Entity* and each entity has its own *Update() and *Draw()* functions
