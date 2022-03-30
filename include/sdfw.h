/**
 * @file    sdfw.h
 * @author  Y.Nakaue
 */

#pragma once

#include "Circle.hpp"
#include "Color.hpp"
#include "Line.hpp"
#include "Mouse.hpp"
#include "Point.hpp"

#include <cstdint>
#include <string>

namespace sdfw
{
    /**
     * @brief  Initialize engine components
     */
    void init();

    /**
     * @brief  Quit process for engine components
     */
    void quit();

    namespace System
    {
        /**
         * @brief  Update all drawings to the latest state
         * @return  Whether to exit the main loop
         */
        bool update();
    }

    namespace Time
    {
        /**
         * @brief  Get the count of ticks (called "update()") since the engine startup
         * @return  Tick count since the engine startup
         */
        uint32_t getTicks();

        /**
         * @brief  Get the time (milliseconds) since the engine startup
         * @return  Elapsed time since the engine startup
         */
        uint32_t getMillisec();

        /**
         * @brief  Get average FPS until current frame
         * @return  Average FPS until current frame
         */
        uint32_t getAverageFPS();
    }

    /**
     * @brief  Open new window
     * @param  (width)  Width of the new window
     * @param  (height)  Height of the new window
     * @return  New window ID
     */
    int32_t openWindow(uint32_t width, uint32_t height);

    /**
     * @brief  Close window
     * @param  (win_id)  The ID of window to close
     */
    void closeWindow(int32_t win_id);

    /**
     * @brief  Print string
     * @param  (str)  Output string
     * @param  (win_id)  The ID of window to print string
     */
    void print(std::string str, int32_t win_id = 0);

    namespace Scene
    {
        /**
         * @brief  Set new background color
         * @param  (color)  New background color
         * @param  (win_id)  Target window ID
         */
        void setBackground(Color color, int32_t win_id = 0);
    }

    static uint32_t window_index = 0;
}
