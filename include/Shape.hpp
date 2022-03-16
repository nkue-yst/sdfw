/**
 * @file    Shape.h
 * @author  Y.Nakaue
 */

#pragma once

#include <cstdint>

namespace sdfw
{

    /**
     * @brief  Shape name list
     */
    enum class EShape : uint8_t
    {
        Line,
        Circle,
        Rectangle,
        Point,
    };

    /**
     * @brief  Base class of shape
     */
    class Shape
    {
    public:
        Shape() = default;
        ~Shape() = default;

        /**
         * @brief  Draw some shape
         */
        virtual void draw() = 0;
    };

}
