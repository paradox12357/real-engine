#include "Types.h"
using namespace std;
using namespace input;
realengine::Engine* mainEngine;
void InputManager::initializeInputManager(realengine::Engine e) {
    mainEngine = &e;
}
void InputManager::shutdownInputManager() {
    
}
void InputManager::Update() {
    glfwPollEvents();
}
bool InputManager::KeyIsPressed(int name) {
    return (glfwGetKey((*mainEngine).getWindow(), name) == GLFW_PRESS);
}
