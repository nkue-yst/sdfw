/**
 * @file    sdfw.h
 * @author  Y.Nakaue
 */

#pragma once

#include "Color.hpp"
#include "Mouse.hpp"
#include "Point.hpp"

#include <cstdint>

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
