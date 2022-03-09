#include "sdfw.h"

#include <thread>
#include <chrono>
#include <iostream>

#define delay(ms) std::this_thread::sleep_for(std::chrono::milliseconds(##ms));

int main()
{
    sdfw::init();

    int32_t win = sdfw::openWindow(1280, 720);
    int32_t sub_win = sdfw::openWindow(500, 200);

    delay(1000);

    sdfw::closeWindow(sub_win);

    delay(1000);

    sdfw::quit();
}
