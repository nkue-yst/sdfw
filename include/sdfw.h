/**
 * @file    sdfw.h
 * @author  Y.Nakaue
 */

#pragma once

#include <cstdint>

namespace sdfw
{
    void init();

    void openWindow(uint32_t width, uint32_t height);

    void quit();
}
