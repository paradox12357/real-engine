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
	resource::ResourceManager::initializeResourceManager();
	ecs::ECSManager::initializeECSManager();

}

void Engine::shutdown() { // runs at the end of the game loop
	(*graphicsManager).GraphicsManager::shutdownGraphicsManager();
	input::InputManager::shutdownInputManager();
	resource::ResourceManager::shutdownResourceManager();
	ecs::ECSManager::shutdownECSManager();
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
    (*graphicsManager).LoadTexture("test", resource::ResourceManager::getPath("assets/image.png"), 0, 0.6, 0.1, 50.0);
    (*graphicsManager).LoadTexture("test2", resource::ResourceManager::getPath("assets/image2.png"), 0, 0, 0.2, 1.0);
    std::vector< graphics::GraphicsManager::Sprite > spritesVector;
    for (const auto& [key, value] : (*graphicsManager).sprites) {
        spritesVector.push_back(value);
    }
	while (true) {
		auto start = std::chrono::high_resolution_clock::now();
		//run loop here
		//doThing(2);
		input::InputManager::Update();
		callback();
        for (auto & sprite : spritesVector) {
            if (input::InputManager::KeyIsPressed(GLFW_KEY_D) && sprite.scale > 3)
                sprite.x += 0.1;
        }
        for (auto & sprite : spritesVector) {
            if (input::InputManager::KeyIsPressed(GLFW_KEY_A) && sprite.scale > 3)
                sprite.x -= 0.1;
        }
        for (auto & sprite : spritesVector) {
            if (input::InputManager::KeyIsPressed(GLFW_KEY_W) && sprite.scale > 3)
                sprite.y += 0.1;
        }
        for (auto & sprite : spritesVector) {
            if (input::InputManager::KeyIsPressed(GLFW_KEY_S) && sprite.scale > 3)
                sprite.y -= 0.1;
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
