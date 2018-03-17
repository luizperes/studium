#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace studium
{
    //! Wraps all functions and structures related to input handling.
    namespace input
    {
        // Input callbacks

        /*!
         * \brief Callback function for keyboard input events.
         * \note This function should not be called directly.
         */
        void keyboard_callback(GLFWwindow*, int, int, int, int);
        
        /*!
         * \brief Callback function for mouse repositioning events.
         * \note This function should not be called directly.
         */
        void mouse_pos_callback(GLFWwindow*, double, double);

        /*!
         * \brief Callback function for mouse click events.
         * \note This function should not be called directly.
         */
        void mouse_btn_callback(GLFWwindow*, int, int, int);

        /*!
         * \brief Callback function for mouse scroll wheel events.
         * \note This function should not be called directly.
         */
        void mouse_scl_callback(GLFWwindow*, double, double);

        /*!
         * Callback function for gamepad events.
         * \note This function should not be called directly.
         */
        void gamepad_callback(int, int);
    }
}
