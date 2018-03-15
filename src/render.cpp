#include <studium/render.hpp>
#include <studium/input.hpp>

/*         Renderer2D          */

// ===== Public methods ===== //


studium::render::Renderer2D::~Renderer2D()
{
    this->unload();
}

//!  Initializes both the window and the rendering context.
//   If already initialized, does nothing.
bool
studium::render::Renderer2D::init()
{
    // We do not need to reinitialize a window
    if(window)
        return true;

    // Default initial value
    window = nullptr;
    
    // Initialize GLFW
    if(!glfwInit())
        return false;

    // Initialize window.
    // More info and reference fo future issues:
    // http://www.glfw.org/docs/latest/window_guide.html#window_creation

    // These two will give us a fixed window which will likely also float
    // on Linux tiling WMs such as bspwm and i3
    glfwWindowHint(GLFW_FLOATING,     GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE,    GLFW_FALSE);
    
    glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
    glfwWindowHint(GLFW_REFRESH_RATE, GLFW_DONT_CARE);
    
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_NATIVE_CONTEXT_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    // TODO: Add options to change this.
    window = glfwCreateWindow(1280, 720, "Game", NULL, NULL);
    
    if(!this->window) {
        glfwTerminate();
        return false;
    }

    // Use GL context on this window
    glfwMakeContextCurrent(window);


    // Setup window callbacks.
    // More on: http://www.glfw.org/docs/latest/input_guide.html#events
    glfwSetKeyCallback(window,         studium::input::keyboard_callback);
    glfwSetCursorPosCallback(window,   studium::input::mouse_pos_callback);
    glfwSetMouseButtonCallback(window, studium::input::mouse_btn_callback);
    glfwSetScrollCallback(window,      studium::input::mouse_scl_callback);
    glfwSetJoystickCallback(studium::input::gamepad_callback);

    return true;
}


//!  Performs an infinite game loop, while the game doesn't trigger an exit signal
//   to the window.
bool
studium::render::Renderer2D::game_loop()
{
    if(!window)
        return false;

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // TODO:
        // - Calculate delta time.
        // - Manage scenes.
        // - Maybe something more.
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

//!  Performs a full disposal of the window and the rendering context.
void
studium::render::Renderer2D::unload()
{
    // Delete window
    if(window) {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}
