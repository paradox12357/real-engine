#pragma once
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "Engine.h"
namespace input{
	class InputManager {
	private:
	public:
		static void InputManager::initializeInputManager(realengine::Engine e);
		static void InputManager::shutdownInputManager();
		static void InputManager::Update();
		static bool InputManager::KeyIsPressed(int name);
	};
}