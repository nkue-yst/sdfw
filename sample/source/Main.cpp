#include "sdfw.h"

#include <thread>
#include <chrono>
#include <iostream>

int main()
{
    sdfw::init();

    std::cout << sdfw::openWindow(1280, 720) << std::endl;
    std::cout << sdfw::openWindow(500, 200) << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    sdfw::quit();
}
