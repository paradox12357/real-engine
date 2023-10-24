#include <iostream>
#include <Types.h>
using namespace std;
int main( int argc, const char* argv[] ) {
    engine = std::make_unique<realengine::Engine>();
    (*engine).runGameLoop( [&]( ) {
        
        });
    return 0;
}
