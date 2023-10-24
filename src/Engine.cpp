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
	ecs::initializeECSManager();

}

void Engine::shutdown() { // runs at the end of the game loop
	(*graphicsManager).GraphicsManager::shutdownGraphicsManager();
	input::InputManager::shutdownInputManager();
	resource::ResourceManager::shutdownResourceManager();
	ecs::shutdownECSManager();
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
	std::vector< graphics::GraphicsManager::Sprite > spritesVector;
	spritesVector.push_back((*graphicsManager).LoadTexture("test", resource::ResourceManager::getPath("assets/image.png"), 0, 0, 0.1, 15.0, true));
	spritesVector.push_back((*graphicsManager).LoadTexture("test2", resource::ResourceManager::getPath("assets/image2.png"), 0, 0, 0.2, 1.0, true));
	spritesVector.push_back((*graphicsManager).LoadTexture("test3", resource::ResourceManager::getPath("assets/image3.png"), 0, 0, 0.05, 1.35, false));
	vector<int> colors = { 255, 0, 0 };
	bool rainbow = false;
	while (true) {
		auto start = std::chrono::high_resolution_clock::now();
		//run loop here
		//doThing(2);
		input::InputManager::Update();
		callback();
        for (auto & sprite : spritesVector) {
            if (input::InputManager::KeyIsPressed(GLFW_KEY_A) && sprite.z == 0.2)
                sprite.x += 0.015;
        }
        for (auto & sprite : spritesVector) {
            if (input::InputManager::KeyIsPressed(GLFW_KEY_D) && sprite.z == 0.2)
                sprite.x -= 0.015;
        }
        for (auto & sprite : spritesVector) {
            if (input::InputManager::KeyIsPressed(GLFW_KEY_S) && sprite.z == 0.2)
                sprite.y += 0.015;
        }
        for (auto & sprite : spritesVector) {
            if (input::InputManager::KeyIsPressed(GLFW_KEY_W) && sprite.z == 0.2)
                sprite.y -= 0.015;
        }
		for (auto& sprite : spritesVector) {
			if (input::InputManager::KeyIsPressed(GLFW_KEY_UP)) {
				if (sprite.z == 0.2) {
					sprite.scale *= 1.05;
					sprite.x *= 1.05;
					sprite.y *= 1.05;
				}
			}
		}
		for (auto& sprite : spritesVector) {
			if (input::InputManager::KeyIsPressed(GLFW_KEY_DOWN)) {
				if (sprite.z == 0.2) {
					sprite.scale *= 0.95;
					sprite.x *= 0.95;
					sprite.y *= 0.95;
				}
			}
		}
		if (input::InputManager::KeyIsPressed(GLFW_KEY_R)) {
			if (input::InputManager::KeyIsPressed(GLFW_KEY_LEFT_SHIFT))
				rainbow = false;
			else
				rainbow = true;
		}
		for (auto& sprite : spritesVector) {
			if (input::InputManager::KeyIsPressed(GLFW_KEY_F) && sprite.z == 0.05) {
				if (!input::InputManager::KeyIsPressed(GLFW_KEY_LEFT_SHIFT))
					sprite.draw = true;
				else
					sprite.draw = false;
			}
		}
		if (rainbow) {
			if (colors[0] > 0 && colors[1] >= 0 && colors[2] == 0) {
				colors[1] += 1;
				colors[0] -= 1;
			}
			else if (colors[0] == 0 && colors[1] > 0 && colors[2] >= 0) {
				colors[2] += 1;
				colors[1] -= 1;
			} 
			else {
				colors[0] += 1;
				colors[2] -= 1;
			}
			graphicsManager->red = colors[0] / 255.0;
			graphicsManager->green = colors[1] / 255.0;
			graphicsManager->blue = colors[2] / 255.0;
		}
		else {
			graphicsManager->red = 0;
			graphicsManager->green = 0;
			graphicsManager->blue = 0;
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
