/**
 * @file    Circle.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include "Shape.hpp"
#include "Point.hpp"

namespace sdfw
{

    /**
     * @brief  Circle class
     */
    class Circle : public Shape
    {
    public:
        /**
         * @brief  Constructor with coordinate
         * @param
         */
        Circle(uint32_t x, uint32_t y, uint32_t r);

        /**
         * @brief  Draw this line
         * @param (color) Drawing color
         * @param (win) Target window ID
         */
        void draw(Color color = { 255, 255, 255, 255 }, int32_t win = 0) override;

    private:
        /// Center coordinate
        Point center_;

        /// Radius
        uint32_t rad;
    };

}