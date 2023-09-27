#include <iostream>
#include <chrono>
#include <thread>
#include "Types.h"

using namespace std;
using namespace realengine;
using namespace resource;
std::unique_ptr<graphics::GraphicsManager> graphicsManager;

void Engine::startup() { // runs at the beginning of the game loop, creates managers.
	graphicsManager = std::make_unique<graphics::GraphicsManager>();
	(*graphicsManager).initializeGraphicsManager(*this);
	input::InputManager::initializeInputManager(*this);
}

void Engine::shutdown() { // runs at the end of the game loop
	(*graphicsManager).GraphicsManager::shutdownGraphicsManager();
	input::InputManager::shutdownInputManager();
}

int x = 0;
void Engine::doThing(int ticktock) { // test function, currently set up to print a tick every frame and tock every second to verify timing. 0 = tick and tock, 1 = tick, 2 = tock
	x++;
	if (ticktock == 0 || ticktock == 1)
		std::cout << "tick" << std::endl;
	if (x == 60) {
		x = 0;
		if (ticktock == 0 || ticktock == 2)
			std::cout << "tock" << std::endl;
	}
}

GLFWwindow* Engine::getWindow() {
	return (*graphicsManager).getWindow();
}

void Engine::runGameLoop(const UpdateCallback& callback) { // main game loop, calls all other functions and managers.

	startup();
	while (true) {
		auto start = std::chrono::high_resolution_clock::now();
		//run loop here
		//doThing(2);
		input::InputManager::Update();
		callback();
		(*graphicsManager).LoadTexture("test", resource::ResourceManager::getPath("assets/image.png"));
		std::vector< graphics::GraphicsManager::Sprite > spritesVector;
		for (const auto& [key, value] : (*graphicsManager).sprites) {
			spritesVector.push_back(value);
		}
		(*graphicsManager).Draw(spritesVector);
		//end loop code here
		auto end = std::chrono::high_resolution_clock::now();
		while (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() < (1000. / fps)) {
			end = std::chrono::high_resolution_clock::now();
		}
		if (input::InputManager::KeyIsPressed(GLFW_KEY_ESCAPE))
			break;
		if (glfwWindowShouldClose(getWindow()))
			break;
	}
	shutdown();
}
