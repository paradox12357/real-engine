#pragma once
namespace realengine {
	class Engine {
	private:
	public:
		//unique_ptr<GraphicsManager> gGraphics = make_unique<GraphicsManager>();

		void startup();

		void shutdown();

		void doThing();

		auto awake_time();

		void runGameLoop();
	};
}