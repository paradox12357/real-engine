#pragma once
#include <iostream>
#include "Types.h"
#include <Engine.cpp>
int main( int argc, const char* argv[] ) {
    std::cout << "Hello, World!\n";
    std::unique_ptr<Engine> engine = std::make_unique<Engine>();
    (*engine).runGameLoop();
    return 0;
}