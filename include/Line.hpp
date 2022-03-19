/**
 * @file    Line.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include "Shape.hpp"
#include "Point.hpp"

namespace sdfw
{

    /**
     * @brief  Line class
     */
    class Line : public Shape
    {
    public:
        /**
         * @brief  Constructor with coordinate
         * @param (x0) Start x-coordinate of line
         * @param (y0) Start y-coordinate of line
         * @param (x1) End x-coordinate of line
         * @param (y1) End y-coordinate of line
         * @param (thickness) The thickness of line
         */
        Line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, int32_t thickness = 1);

        /**
         * @brief  Draw this line
         * @param (win) Target window ID
         */
        void draw(int32_t win = 0) override;

    private:
        /// Start coordinate of line
        Point start_;

        /// End coordinate of line
        Point end_;

        /// The thickness of line
        int32_t thickness_;
    };

}
