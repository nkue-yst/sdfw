/**
 * @file    sdfw.h
 * @author  Y.Nakaue
 */

#pragma once

#include <cstdint>

namespace sdfw
{
    void init();

    void openWindow(uint16_t width, uint16_t height);

    void quit();
}
