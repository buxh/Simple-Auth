#include "includes.hpp"
#include "auth.hpp"

int main() 
{
    auth::antidebugger();
    auth::hwidCheck();
    
    if (!auth::access) {
        // enter your code
        std::cout << "Hello World" << std::endl;
        while (true) { auth::antidebugger(); }
    }

    return std::cin.get();
}
