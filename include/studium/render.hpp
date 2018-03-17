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
            /*!
             * \brief Initializes both the window and the rendering context.
             * If already initialized, does nothing.
             * \return Whether the initialization process succeeded.
             */  
            bool init();

            /*!
             * \brief Performs an infinite game loop, while the game doesn't trigger an exit signal
             * to the window.
             * \return Whether the attempt to run a game loop succeeded.
             */
            bool game_loop();

            //! Performs a full disposal of the window and the rendering context.
            void unload();
        };
    }
}
