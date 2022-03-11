/**
 * @file    Point.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include <cstdint>

namespace sdfw
{

    /**
     * @brief  Structure that holds 2 values
     */
    struct Point
    {
    public:
        Point()
            : x(0)
            , y(0)
        {
        }

        Point(uint32_t X, uint32_t Y)
            : x(X)
            , y(Y)
        {
        }

        /// Value of x
        uint32_t x;

        /// Value of y
        uint32_t y;
    };

}
