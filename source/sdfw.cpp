/**
 * @file    sdfw.cpp
 * @author  Y.Nakaue
 */

#include "sdfw.h"
#include "sdfwEngine.hpp"
#include "sdfwMessenger.hpp"

#include <iostream>
#include <thread>
#include <numeric>

#define MAX_FPS 120

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
            std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
            float frame_ms = static_cast<float>(std::chrono::duration_cast<std::chrono::milliseconds>(now - sdfwEngine::get()->pre_time_).count());
            float max_ms = 1.f / MAX_FPS * 1000.f;

            if (frame_ms < max_ms)
            {
                uint32_t sleep_time = 0;
                sleep_time = static_cast<uint32_t>(max_ms - frame_ms);

                std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
            }

            SDFW_ENGINE(Messenger)->execUpdate();
            sdfwEngine::get()->pre_time_ = std::chrono::system_clock::now();
            sdfwEngine::get()->tick_++;

            return sdfwEngine::get()->loop_flag_;
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

        uint32_t getAverageFPS()
        {
            static std::vector<uint32_t> fps_list;
            static uint32_t fps_average = MAX_FPS;
            uint32_t frame, sec;

            frame = getTicks();
            sec = getMillisec() / 1000;

            if (sec == 0)
            {
                return 0;
            }

            fps_list.push_back(frame / sec);

            if (frame % 10 == 0)
            {
                fps_average = std::accumulate(fps_list.begin(), fps_list.end(), 0) / static_cast<uint32_t>(fps_list.size());
                fps_list.clear();
            }

            return fps_average;
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
