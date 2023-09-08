#pragma once
#include <functional>
namespace realengine {
	class Engine {
	private:
		const double fps = 60.;
		
	public:
		void startup();

		void shutdown();

		void doThing(int ticktock);

		GLFWwindow* getWindow();
		typedef std::function<void()> UpdateCallback;
		void runGameLoop(const UpdateCallback& callback);
	};
}