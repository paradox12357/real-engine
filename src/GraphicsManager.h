#pragma once
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "Engine.h"
namespace graphics{
	class GraphicsManager {
	private:
		GLFWwindow* window;
	public:
		void initializeGraphicsManager(realengine::Engine e);
		void shutdownGraphicsManager();
		void createWindow();
		GLFWwindow* getWindow();
	};
}