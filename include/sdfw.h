/**
 * @file    sdfw.h
 * @author  Y.Nakaue
 */

#pragma once

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

    static uint32_t window_index = 0;
}
