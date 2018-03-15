#include <studium/input.hpp>

//! Callback function for keyboard input events.
void
studium::input::keyboard_callback(GLFWwindow* window,
                                  int         key,
                                  int         scancode,
                                  int         action,
                                  int         mods)
{
    // Well, uhm, TO-DO!
}

//! Callback function for mouse repositioning events.
void
studium::input::mouse_pos_callback(GLFWwindow* window,
                                   double      xpos,
                                   double      ypos)
{
    // TODO
}

//! Callback function for mouse click events.
void
studium::input::mouse_btn_callback(GLFWwindow* window,
                                   int         button,
                                   int         action,
                                   int         mods)
{
    // also TODO
}

//! Callback function for mouse scroll wheel events.
void
studium::input::mouse_scl_callback(GLFWwindow* window,
                                   double      xoffset,
                                   double      yoffset)
{
    // TODO
}

//! Callback function for gamepad events.
void
studium::input::gamepad_callback(int gamepad, int event)
{
    // TODO as well.
}
