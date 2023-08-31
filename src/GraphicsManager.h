#pragma once
void createWindow();
namespace {
	struct {
		int window_width = 640;
		int window_height = 480;
		const char* window_name = "Real Engine";
		bool window_fullscreen = false;
	} defaults;
}