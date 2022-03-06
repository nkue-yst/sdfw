/**
 * @file    sdfw.h
 * @author  Y.Nakaue
 */

#pragma once

#include <cstdint>

namespace sdfw
{
    void init();

    int32_t openWindow(uint32_t width, uint32_t height);

    void quit();

    static uint32_t window_index = 0;
}
