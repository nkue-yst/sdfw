/**
 * @file    sdfw.cpp
 * @author  Y.Nakaue
 */

#include "sdfw.h"
#include "Socket.hpp"

#include <iostream>

namespace sdfw
{

    void init()
    {
        std::cout << "init()" << std::endl;
    }

    void openWindow(uint16_t width, uint16_t height)
    {
        Socket::getInstance().execOpenWindow(width, height);
    }

    void quit()
    {
        std::cout << "quit()" << std::endl;
    }

}
