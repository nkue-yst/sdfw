/**
 * @file    Mouse.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include <cstdint>

namespace sdfw
{
    constexpr int8_t LEFT   = 1 << 0;
    constexpr int8_t MIDDLE = 1 << 1;
    constexpr int8_t RIGHT  = 1 << 2;

    namespace Mouse
    {
        /**
         * @brief  Get is mouse button pressed
         * @param  (button)  Target button by mask
         * @return  Is pressed
         */
        bool pressed(int8_t button);
    }
}
