#pragma once
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "Engine.h"
namespace input{
	class InputManager {
	private:
	public:
		static void initializeInputManager(realengine::Engine e);
		static void shutdownInputManager();
		static void Update();
		static bool KeyIsPressed(int name);
	};
}