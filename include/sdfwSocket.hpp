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
    class sdfwSocket
    {
    public:
        /**
         * @brief  Create instance
         */
        static sdfwSocket* create();

        /**
         * @brief  Initialize socket
         * @return  Success or failure
         */
        bool init(uint32_t port = 62491);

        /**
         * @brief  Execute opening window
         */
        void execOpenWindow(uint16_t width, uint16_t height);
    };

}
