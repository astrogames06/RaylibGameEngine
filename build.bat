set files=src/main.cpp src/Game/Game.cpp src/Scene/Scene.cpp src/Entity/Entity.cpp

g++ %files% -o build/windows/app.exe -O1 -Wall -std=c++17 -Wno-missing-braces -I include/ -L lib/ -lraylib.win -lopengl32 -lgdi32 -lwinmm
.\build\windows\app.exe