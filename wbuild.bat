set files=src/main.cpp src/Game/Game.cpp src/Scene/Scene.cpp src/Entity/Entity.cpp

em++ %files% -o build\web\index.html -std=c++17 -Os -Wall ./lib/libraylib.web.a -I. -I include/ -L. -L llib/ -s USE_GLFW=3 --shell-file build/web/shell.html -DPLATFORM_WEB