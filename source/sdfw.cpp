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
        sdfwEngine::get()->init();
    }

    void openWindow(uint32_t width, uint32_t height)
    {
        SDFW_ENGINE(Socket)->execOpenWindow(width, height);
    }

    void quit()
    {
        sdfwEngine::get()->quit();
    }

}
