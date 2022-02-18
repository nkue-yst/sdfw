/**
 * @file    sdfw.cpp
 * @author  Y.Nakaue
 */

#include "sdfw.h"
#include "sdfwEngine.hpp"
#include "sdfwSocket.hpp"

#include <iostream>

namespace sdfw
{

    void init()
    {
        std::cout << "init()" << std::endl;
    }

    void openWindow(uint16_t width, uint16_t height)
    {
        sdfwEngine::getComponent<sdfwSocket>()->execOpenWindow(width, height);
    }

    void quit()
    {
        std::cout << "quit()" << std::endl;
    }

}
