#include <cstdio>
#include <studium/engine.hpp>

int main(int argc, char** argv)
{
    studium::Renderer2D renderer;
    renderer.init();
    renderer.game_loop();
    renderer.unload();
    return 0;
}
