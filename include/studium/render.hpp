#pragma once

#include <epoxy/gl.h>
#include <epoxy/glx.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <studium/types.hpp>

namespace studium
{
    //! Wraps all functions and structures related to graphics rendering.
    namespace render
    {
        //!  A class to manage the window and the rendering context.
        class Renderer2D
        {
        private:
            GLFWwindow* window;
            glm::vec2   size;
        public:
            ~Renderer2D();
            bool init();
            bool game_loop();
            void unload();
        };
    }
}
