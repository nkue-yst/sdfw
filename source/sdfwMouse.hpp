/**
 * @file    sdfwMouse.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include "Point.hpp"

#include <cstdint>

namespace sdfw
{
    /**
     * @brief  Class that holds button state
     */
    struct MouseButton
    {
    public:
        MouseButton()
            : is_pressed_(false)
        {
        }

        /// Is pressed
        bool is_pressed_;
    };


    /**
     * @brief  Mouse cursor interface class
     */
    class IsdfwMouse
    {
    public:
        virtual ~IsdfwMouse() = default;

        /**
         * @brief  Create instance
         */
        static IsdfwMouse* create();

        /**
         * @brief  Called when mouse button down
         * @param  (button)  Pressed button name
         * @param  (x)  X coordinate of pressed position
         * @param  (y)  Y coordinate of pressed position
         */
        virtual void onButtonDown(const char* button, uint32_t x, uint32_t y) = 0;

        /**
         * @brief  Called when mouse button up
         * @param  (button)  Released button name
         * @param  (x)  X coordinate of released position
         * @param  (y)  Y coordinate of released position
         */
        virtual void onButtonUp(const char* button, uint32_t x, uint32_t y) = 0;

        /// Current cursor position
        Point current_pos_;

        /// Left button
        MouseButton left_btn_;

        /// Middle button
        MouseButton middle_btn_;

        /// Right button
        MouseButton right_btn_;
    };


    /**
     * @brief  Mouse cursor class
     */
    class sdfwMouse : public IsdfwMouse
    {
    public:
        sdfwMouse();
        ~sdfwMouse() override;

        /**
         * @brief  Called when mouse button down
         * @param  (button)  Pressed button name
         * @param  (x)  X coordinate of pressed position
         * @param  (y)  Y coordinate of pressed position
         */
        void onButtonDown(const char* button, uint32_t x, uint32_t y) override;

        /**
         * @brief  Called when mouse button up
         * @param  (button)  Released button name
         * @param  (x)  X coordinate of released position
         * @param  (y)  Y coordinate of released position
         */
        void onButtonUp(const char* button, uint32_t x, uint32_t y) override;
    };

}
