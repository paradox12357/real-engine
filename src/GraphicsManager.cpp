#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "Types.h"
#include "GraphicsManager.h"
using namespace std;

void createWindow() {
    glfwInit();
    // We don't want GLFW to set up a graphics API.
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    // Create the window.
    GLFWwindow* window = glfwCreateWindow(defaults.window_width, defaults.window_height, defaults.window_name, defaults.window_fullscreen ? glfwGetPrimaryMonitor() : 0, 0);
    glfwSetWindowAspectRatio(window, defaults.window_width, defaults.window_height);
    if (!window)
    {
        std::cerr << "Failed to create a window." << std::endl;
        glfwTerminate();
    }
}