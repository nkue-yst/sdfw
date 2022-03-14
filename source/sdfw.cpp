/**
 * @file    sdfw.cpp
 * @author  Y.Nakaue
 */

#include "sdfw.h"
#include "sdfwEngine.hpp"
#include "sdfwMessenger.hpp"

#include <iostream>
#include <thread>

namespace sdfw
{

    namespace events
    {
        void startEventThread()
        {
            SDFW_ENGINE(Messenger)->recvEvents();
        }
    }

    void init()
    {
        sdfwEngine::get()->init();

        /* Start thread for receiving events */
        std::thread th_ev(events::startEventThread);
        th_ev.detach();
    }

    void quit()
    {
        sdfwEngine::get()->quit();
    }

    namespace System
    {
        bool update()
        {
            SDFW_ENGINE(Messenger)->execUpdate();
            sdfwEngine::get()->tick_++;

            return true;
        }
    }

    namespace Time
    {
        uint32_t getTicks()
        {
            return sdfwEngine::get()->tick_;
        }

        uint32_t getMillisec()
        {
            std::chrono::system_clock::time_point now;  // Current time stamp
            now = std::chrono::system_clock::now();

            return static_cast<uint32_t>(std::chrono::duration_cast<std::chrono::milliseconds>(now - sdfwEngine::get()->start_time_).count());
        }
    }

    int32_t openWindow(uint32_t width, uint32_t height)
    {
        SDFW_ENGINE(Messenger)->execOpenWindow(width, height);
        window_index++;

        return window_index - 1;
    }

    void closeWindow(int32_t win_id)
    {
        SDFW_ENGINE(Messenger)->execCloseWIndow(win_id);
    }

    void print(std::string str, int32_t win_id)
    {
        SDFW_ENGINE(Messenger)->execPrint(str, win_id);
    }

    namespace Scene
    {
        void setBackground(Color color, int32_t win_id)
        {
            SDFW_ENGINE(Messenger)->execSetBackground(color, win_id);
        }
    }

}
