/**
 * @file    Socket.cpp
 * @author  Y.Nakaue
 */

#include "sdfwSocket.hpp"
#include <charconv>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>

namespace sdfw
{
    constexpr uint16_t BUFF_SIZE = 512;

    /* Create instance */
    IsdfwSocket* IsdfwSocket::create()
    {
    #if defined _WIN64
        return new sdfwWinSocket();
    #elif defined __unix
        return new sdfwUnixSocket();
    #endif
    }

    sdfwWinSocket::sdfwWinSocket()
        : sock_(0)
    {
    }

    sdfwWinSocket::~sdfwWinSocket()
    {
        /* Cleanup WinSock2 */
        WSACleanup();
    }

    /* Initialize socket */
    void sdfwWinSocket::init()
    {
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
        this->sock_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (this->sock_ == INVALID_SOCKET)
        {
            std::cout << "socket() failed" << std::endl;
        }

        /* Settings for server */
        this->server_.sin_family = AF_INET;
        this->server_.sin_port = htons(62491);
        this->server_.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

        /* Connect to server */
        connect(this->sock_, (sockaddr*)&this->server_, sizeof(this->server_));
    }

    /* Send message */
    void sdfwWinSocket::sendMessage(const char* msg)
    {
        recv(this->sock_, &this->sync_msg_, sizeof(char), 0);

        int32_t result = send(this->sock_, msg, static_cast<int32_t>(strlen(msg) + 1), 0);
        if (result == SOCKET_ERROR)
        {
            std::cout << "Send failed: " << WSAGetLastError() << std::endl;
            closesocket(this->sock_);
        }
    }

    /* Execute opening window */
    void sdfwWinSocket::execOpenWindow(uint32_t width, uint32_t height)
    {
        char msg[BUFF_SIZE] = "openWindow/";
        strcat(msg, std::to_string(width).c_str());
        strcat(msg, "/");
        strcat(msg, std::to_string(height).c_str());

        this->sendMessage(msg);
    }

    /* Execute quit command */
    void sdfwWinSocket::execQuit()
    {
        char msg[BUFF_SIZE] = "quit";
        
        this->sendMessage(msg);
    }

}
