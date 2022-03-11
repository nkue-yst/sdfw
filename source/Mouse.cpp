/**
 * @file    Mouse.cpp
 * @author  Y.Nakaue
 */

#include "Mouse.hpp"
#include "sdfwMouse.hpp"
#include "sdfwEngine.hpp"

namespace sdfw
{
    namespace Mouse
    {
        bool pressed(int8_t button)
        {
            bool is_pressed = true;

            if (button & LEFT)
                is_pressed &= SDFW_ENGINE(Mouse)->left_btn_.is_pressed_;

            if (button & MIDDLE)
                is_pressed &= SDFW_ENGINE(Mouse)->middle_btn_.is_pressed_;

            if (button & RIGHT)
                is_pressed &= SDFW_ENGINE(Mouse)->right_btn_.is_pressed_;

            return is_pressed;
        }
    }
}
