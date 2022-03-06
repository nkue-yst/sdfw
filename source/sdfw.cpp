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

    int32_t openWindow(uint32_t width, uint32_t height)
    {
        SDFW_ENGINE(Socket)->execOpenWindow(width, height);
        window_index++;

        return window_index - 1;
    }

    void quit()
    {
        sdfwEngine::get()->quit();
    }

}
