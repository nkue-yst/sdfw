#include <sdfw.h>

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#define delay(ms) std::this_thread::sleep_for(std::chrono::milliseconds(##ms));

using namespace sdfw;

int main()
{
    init();

    int32_t win = openWindow(1280, 720);

    std::string str;
    while (System::update())
    {
        str = "Ticks: " + std::to_string(Time::getTicks()) + ", Time: " + std::to_string(Time::getMillisec()) + "ms";

        print(str);
        
        if (Time::getTicks() > 50000)
            break;
    }

    delay(2000);

    quit();
}
