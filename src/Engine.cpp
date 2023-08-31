
#include <iostream>
#include <chrono>
#include <thread>
#include "Types.h"
#include "Engine.h"
using namespace std;
using namespace realengine;

void Engine::startup() { // runs at the beginning of the game loop, creates managers.
	createWindow();
}

void Engine::shutdown() { // runs at the end of the game loop

}

//int x = 0;
void Engine::doThing() { // test function, currently set up to print a tick every frame and tock every second to verify timing.
	/*x++;
	std::cout << "tick" << std::endl;
	if (x == 60) {
		x = 0;
		std::cout << "tock" << std::endl;
	}*/
}

void Engine::runGameLoop() { // main game loop, calls all other functions and managers.

	startup();
	bool running = true;
	while (running) {
		auto start = std::chrono::high_resolution_clock::now();
		doThing();
		auto end = std::chrono::high_resolution_clock::now();
		while (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() < (1000. / fps)) {
			end = std::chrono::high_resolution_clock::now();
		}
	}
	shutdown();
}
