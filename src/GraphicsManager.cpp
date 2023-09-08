#pragma once
#include "Types.h"

using namespace std;
using namespace graphics;
void GraphicsManager::initializeGraphicsManager(realengine::Engine e) {
    createWindow();
}
void GraphicsManager::shutdownGraphicsManager() {
    glfwTerminate();
}
void GraphicsManager::createWindow() {
    glfwInit();
    // We don't want GLFW to set up a graphics API.
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    // Create the window.
    GraphicsManager::window = glfwCreateWindow(defaults.window_width, defaults.window_height, defaults.window_name, defaults.window_fullscreen ? glfwGetPrimaryMonitor() : 0, 0);
    glfwSetWindowAspectRatio(GraphicsManager::window, defaults.window_width, defaults.window_height);
    if (!GraphicsManager::window)
    {
        std::cerr << "Failed to create a window." << std::endl;
        glfwTerminate();
    }
}
GLFWwindow* GraphicsManager::getWindow() {
    return window;
}