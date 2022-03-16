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
         */
        Line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1);

        /**
         * @brief  Draw this line
         */
        void draw() override;

    private:
        /// Start coordinate of line
        Point start_;

        /// End coordinate of line
        Point end_;
    };

}
