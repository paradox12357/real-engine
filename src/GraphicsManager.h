#pragma once
#include "GLFW/glfw3.h"
#include "Engine.h"
#include "webgpu/webgpu.h"
#include "glfw3webgpu.h"
#include <string>
using std::string;
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
			image(const  image&) = delete;
			image& operator=(const  image&) = delete;
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
		std::unordered_map< string, image > images;
	public:
		void initializeGraphicsManager(realengine::Engine e);
		void shutdownGraphicsManager();
		void createWindow();
		GLFWwindow* getWindow();
		bool LoadTexture(const string& name, const string& path);
	};
}
