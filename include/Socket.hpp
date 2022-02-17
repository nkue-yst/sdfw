/**
 * @file    Socket.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include "sdfwComponent.hpp"

#include <cstdint>

namespace sdfw
{

    /**
     * @brief  Socket class
     */
    class Socket : public sdfwComponent<Socket>
    {
    private:
        friend class sdfwComponent;

    public:
        /**
         * @brief  Execute opening window
         */
        void execOpenWindow(uint16_t width, uint16_t height);
    };

}
