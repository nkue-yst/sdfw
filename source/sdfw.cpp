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

    void quit()
    {
        sdfwEngine::get()->quit();
    }

    namespace System
    {
        bool update()
        {
            SDFW_ENGINE(Socket)->execUpdate();

            return true;
        }
    }

    int32_t openWindow(uint32_t width, uint32_t height)
    {
        SDFW_ENGINE(Socket)->execOpenWindow(width, height);
        window_index++;

        return window_index - 1;
    }

    void closeWindow(int32_t win_id)
    {
        SDFW_ENGINE(Socket)->execCloseWIndow(win_id);
    }

    namespace Scene
    {
        void setBackground(Color color, int32_t win_id)
        {
            SDFW_ENGINE(Socket)->execSetBackground(color, win_id);
        }
    }

}
