#pragma once
#include "GLFW/glfw3.h"
#include "Engine.h"
#include "webgpu/webgpu.h"
#include "glfw3webgpu.h"
#include "glm/glm.hpp"
#include <string>
using std::string;
typedef glm::mat4 mat4;
namespace graphics{
	class GraphicsManager {
	private:
		struct image {
			int width;
			int height;
			WGPUTexture texture;
			~image() {
				wgpuTextureDestroy(texture);
				wgpuTextureRelease(texture);
			}
			//image(const  image&) = delete;
			//image& operator=(const  image&) = delete;
		};
		struct Uniforms {
			mat4 projection{};
		};
		GLFWwindow* window;
		WGPUInstance instance;
		WGPUSurface surface;
		WGPUAdapter adapter;
		WGPUDevice device;
		WGPUQueue queue;
		WGPUBuffer vertex_buffer;
		WGPUSwapChain swapchain;
		WGPUBuffer uniform_buffer;
		WGPUSampler sampler;
		WGPUShaderModule shader_module;
		WGPURenderPipeline pipeline;
		std::unordered_map< string, image > images;
	public:
		struct Sprite {
			double x, y, z, scale; //z is between 0 and 1
			image i;
		};
		void initializeGraphicsManager(realengine::Engine e);
		void shutdownGraphicsManager();
		void createWindow();
		GLFWwindow* getWindow();
		bool LoadTexture(const string& name, const string& path);
		void Draw(const std::vector< Sprite >& sprites);
	};
}
