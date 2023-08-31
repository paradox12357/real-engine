
#include <iostream>
#include <chrono>
#include <thread>
#include "Types.h"
using namespace std;

class Engine {
private:
public:
	//unique_ptr<GraphicsManager> gGraphics = make_unique<GraphicsManager>();

	void Engine::startup() {
	}

	void Engine::shutdown() {
	}

	void Engine::doThing() {
		
	}

	auto awake_time() {
		using std::chrono::operator""ms;
		return std::chrono::steady_clock::now() + 17ms;
	}

	void Engine::runGameLoop() {

		startup();
		bool running = true;
		while (running) {
			auto start = std::chrono::high_resolution_clock::now();
			doThing();
			auto end = std::chrono::high_resolution_clock::now();
			while (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() < (1000. / 60.)) {
				end = std::chrono::high_resolution_clock::now();
			}
		}
		shutdown();
	}
};

//class GraphicsManager {

//};