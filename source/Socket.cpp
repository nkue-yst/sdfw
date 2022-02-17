/**
 * @file    Socket.cpp
 * @author  Y.Nakaue
 */

#include "Socket.hpp"

#ifdef _WIN64
#include <WinSock2.h>
#endif

#include <iostream>

namespace sdfw
{

    /* Execute opening window */
    void Socket::execOpenWindow(uint16_t width, uint16_t height)
    {
        WSADATA wsa_data;
        WSAStartup(MAKEWORD(2, 0), &wsa_data);

        std::cout << "Open window: " << width << ", " << height << std::endl;

        WSACleanup();
    }

}
