#pragma once
#include "GraphicsManager.h"
namespace realengine {
	class Engine {
	private:
		const double fps = 60.;
	public:

		void startup();

		void shutdown();

		void doThing();

		auto awake_time();

		void runGameLoop();
	};
}