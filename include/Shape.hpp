/**
 * @file    Shape.h
 * @author  Y.Nakaue
 */

#pragma once

#include "Color.hpp"

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
         * @param (color) Drawing color
         * @param (win) Target window ID
         */
        virtual void draw(Color color = { 255, 255, 255 }, int32_t win = 0) = 0;
    };

}
