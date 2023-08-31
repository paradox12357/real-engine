#pragma once
#include <iostream>
#include <Engine.h>
int main( int argc, const char* argv[] ) {
    std::cout << "Hello, World!\n";
    std::unique_ptr<realengine::Engine> engine = std::make_unique<realengine::Engine>();
    (*engine).runGameLoop();
    return 0;
}