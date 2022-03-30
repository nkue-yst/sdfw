/**
 * @file    Circle.cpp
 * @author  Y.Nakaue
 */

#include "Circle.hpp"
#include "sdfwEngine.hpp"
#include "sdfwMessenger.hpp"

#include <vector>

namespace sdfw
{

    Circle::Circle(uint32_t x, uint32_t y, uint32_t r)
        : center_(Point(x, y))
        , rad(r)
    {
    }

    void Circle::draw(Color color, int32_t win)
    {
        std::vector<int32_t> params;
        params.push_back(this->center_.x);
        params.push_back(this->center_.y);
        params.push_back(this->rad);
        params.push_back(color.r);
        params.push_back(color.g);
        params.push_back(color.b);
        params.push_back(color.a);
        params.push_back(win);

        SDFW_ENGINE(Messenger)->execDrawShape(EShape::Circle, params);
    }

}

