/**
 * @file    Line.cpp
 * @author  Y.Nakaue
 */

#include "Line.hpp"
#include "sdfwEngine.hpp"
#include "sdfwMessenger.hpp"

#include <vector>

namespace sdfw
{

    Line::Line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, int32_t thickness)
        : start_(Point(x0, y0))
        , end_(Point(x1, y1))
        , thickness_(thickness)
    {
    }

    void Line::draw(int32_t win)
    {
        std::vector<int32_t> params;
        params.push_back(this->start_.x);
        params.push_back(this->start_.y);
        params.push_back(this->end_.x);
        params.push_back(this->end_.y);
        params.push_back(this->thickness_);
        params.push_back(win);

        SDFW_ENGINE(Messenger)->execDrawShape(EShape::Line, params);
    }

}

