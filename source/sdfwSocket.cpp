/**
 * @file    Socket.cpp
 * @author  Y.Nakaue
 */

#include "sdfwSocket.hpp"

#ifdef _WIN64
#include <WinSock2.h>
#endif

#include <iostream>

namespace sdfw
{

    /* Create instance */
    sdfwSocket* sdfwSocket::create()
    {
        return new sdfwSocket();
    }

    /* Initialize socket */
    bool sdfwSocket::init(uint32_t port)
    {
        return true;
    }

    /* Execute opening window */
    void sdfwSocket::execOpenWindow(uint16_t width, uint16_t height)
    {
        std::cout << "Open window: " << width << ", " << height << std::endl;
    }

}
