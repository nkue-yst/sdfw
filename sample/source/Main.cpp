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

    std::string str1, str2;
    while (System::update())
    {
        str1 = "Ticks: " + std::to_string(Time::getTicks());
        str2 = "Time1: " + std::to_string(Time::getMillisec()) + "ms";
        print(str1);
        print(str2);

        Line(500, 500, 600, 600).draw();
        
        if (Time::getMillisec() > 10000)
            break;
    }

    delay(2000);

    closeWindow(win);
    quit();
}
