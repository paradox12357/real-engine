#pragma once
#include <iostream>
#include <string>
#include "GraphicsManager.h"
#include "Engine.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "ECSManager.h"
#include "GLFW/glfw3.h"
#include "webgpu/webgpu.h"
#include "glfw3webgpu.h"
#include "glm/glm.hpp"
#include <functional>
#include <algorithm>
#include <vector>
#include <typeindex>
namespace {
    typedef double real;
    typedef std::string string;
	typedef glm::vec2 vec2;
	typedef glm::vec3 vec3;
	typedef glm::mat4 mat4;
	struct {
		int window_width = 640;
		int window_height = 480;
		const char* window_name = "Real Engine";
		bool window_fullscreen = false;
	} defaults;
	std::unique_ptr<realengine::Engine> engine;
	struct Position { real x, y; };
	struct Velocity { real x, y; };
	struct Gravity { real meters_per_second; };
	struct Health { real percent; };
	struct Script { string name; };
	std::unordered_map< EntityID, Position > Positions;
	std::unordered_map< EntityID, Velocity > Velocities;
	std::unordered_map< EntityID, Gravity > Gravities;
	std::unordered_map< EntityID, graphics::GraphicsManager::Sprite > Sprites;
	std::unordered_map< EntityID, Health > Healths;
	std::unordered_map< EntityID, Script > Scripts;
}
