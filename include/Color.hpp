/**
 * @file    Color.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include <cstdint>

namespace sdfw
{

    /**
     * @brief  Structure that defines the color
     */
    struct Color
    {
    public:
        Color()
            : r(0)
            , g(0)
            , b(0)
            , a(255)
        {}

        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
        {
            this->r = red;
            this->g = green;
            this->b = blue;
            this->a = alpha;
        }

        /// Red value
        uint8_t r;
        
        /// Green value
        uint8_t g;

        /// Blue value
        uint8_t b;

        /// Alpha value
        uint8_t a;
    };

}
