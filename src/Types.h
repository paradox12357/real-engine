#pragma once
#include <iostream>
#include <string>
#include "GraphicsManager.h"
#include "Engine.h"
#include "InputManager.h"
#include "GLFW/glfw3.h"
#include <functional>
namespace {
    typedef double real;
    typedef std::string string;
	struct {
		int window_width = 640;
		int window_height = 480;
		const char* window_name = "Real Engine";
		bool window_fullscreen = false;
	} defaults;
	std::unique_ptr<realengine::Engine> engine;
}
