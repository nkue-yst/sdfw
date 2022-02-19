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
    void sdfwSocket::init()
    {
    #ifdef _WIN64
        WSADATA wsa_data;
        uint32_t error_code;

        /* Startup WinSock2 */
        error_code = WSAStartup(MAKEWORD(2, 0), &wsa_data);
        switch (error_code)
        {
        case WSASYSNOTREADY:
            std::cout << "WSASYSNOTREADY" << std::endl;
            break;

        case WSAVERNOTSUPPORTED:
            std::cout << "WSAVERNOTSUPPORTED" << std::endl;
            break;

        case WSAEINPROGRESS:
            std::cout << "WSAEINPROGRESS" << std::endl;
            break;

        case WSAEPROCLIM:
            std::cout << "WSAEPROCLIM" << std::endl;
            break;

        case WSAEFAULT:
            std::cout << "WSAEFAULT" << std::endl;
            break;

        default:
            break;
        }

        /* Create socket */
        SOCKET sock;
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == INVALID_SOCKET)
        {
            std::cout << "socket() failed" << std::endl;
        }

        /* Settings for server */
        sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons(62491);
        server.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

        /* Connect to server */
        connect(sock, (sockaddr*)&server, sizeof(server));

        /* Cleanup WinSock2 */
        WSACleanup();
    #endif
    }

    /* Execute opening window */
    void sdfwSocket::execOpenWindow(uint16_t width, uint16_t height)
    {
        std::cout << "Open window: " << width << ", " << height << std::endl;
    }

}
