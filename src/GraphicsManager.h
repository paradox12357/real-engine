#pragma once
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "Engine.h"
namespace graphics{
	class GraphicsManager {
	private:
		GLFWwindow* window;
	public:
		void GraphicsManager::initializeGraphicsManager(realengine::Engine e);
		void GraphicsManager::shutdownGraphicsManager();
		void GraphicsManager::createWindow();
		GLFWwindow* GraphicsManager::getWindow();
	};
}