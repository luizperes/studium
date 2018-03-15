#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace studium
{
    //! Wraps all functions and structures related to input handling.
    namespace input
    {
        // Input callbacks, you shouldn't need to care about those
        // in general.
        void keyboard_callback(GLFWwindow*, int, int, int, int);
        void mouse_pos_callback(GLFWwindow*, double, double);
        void mouse_btn_callback(GLFWwindow*, int, int, int);
        void mouse_scl_callback(GLFWwindow*, double, double);
        void gamepad_callback(int, int);
    }
}
