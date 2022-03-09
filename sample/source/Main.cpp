#include "sdfw.h"

#include <thread>
#include <chrono>
#include <iostream>

#define delay(ms) std::this_thread::sleep_for(std::chrono::milliseconds(##ms));

using namespace sdfw;

int main()
{
    init();

    int32_t win = openWindow(1280, 720);
    int32_t sub_win = openWindow(500, 200);

    Scene::setBackground(Color(255, 128, 0), sub_win);

    uint32_t i = 0;
    while (System::update())
    {
        delay(2000);

        if (i > 5)
            break;

        ++i;
    }

    closeWindow(sub_win);

    delay(2000);

    quit();
}
