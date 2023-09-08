#pragma once
#include <iostream>
#include <Types.h>
using namespace std;
int main( int argc, const char* argv[] ) {
    engine = std::make_unique<realengine::Engine>();
    std::cout << "Hello, World!\n";
    (*engine).runGameLoop( [&]( ) {
        cout << input::InputManager::KeyIsPressed(GLFW_KEY_A) << endl;
        });
    return 0;
}