#include <sdfw.h>

#include <chrono>
#include <iostream>
#include <thread>

#define delay(ms) std::this_thread::sleep_for(std::chrono::milliseconds(##ms));

using namespace sdfw;

int main()
{
    init();

    int32_t win = openWindow(1280, 720);

    uint32_t i = 0;
    while (System::update())
    {
        print("Test: " + std::to_string(i));
        
        if (++i > 50000)
            break;
    }

    delay(2000);

    quit();
}
