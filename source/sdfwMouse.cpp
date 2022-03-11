/**
 * @file    sdfwMouse.cpp
 * @author  Y.Nakaue
 */

#include "sdfwMouse.hpp"

#include <iostream>
#include <string>

namespace sdfw
{

    IsdfwMouse* IsdfwMouse::create()
    {
        return new sdfwMouse();
    }

    sdfwMouse::sdfwMouse()
    {
    }

    sdfwMouse::~sdfwMouse()
    {
    }

    void sdfwMouse::onButtonDown(const char* button, uint32_t x, uint32_t y)
    {
        if (!strcmp(button, "LEFT"))
        {
            this->left_btn_.is_pressed_ = true;
        }
        else if (!strcmp(button, "MIDDLE"))
        {
            this->middle_btn_.is_pressed_ = true;
        }
        else if (!strcmp(button, "RIGHT"))
        {
            this->right_btn_.is_pressed_ = true;
        }

        this->current_pos_ = Point(x, y);
    }

    void sdfwMouse::onButtonUp(const char* button, uint32_t x, uint32_t y)
    {
        if (!strcmp(button, "LEFT"))
        {
            this->left_btn_.is_pressed_ = false;
        }
        else if (!strcmp(button, "MIDDLE"))
        {
            this->middle_btn_.is_pressed_ = false;
        }
        else if (!strcmp(button, "RIGHT"))
        {
            this->right_btn_.is_pressed_ = false;
        }

        this->current_pos_ = Point(x, y);
    }

}
