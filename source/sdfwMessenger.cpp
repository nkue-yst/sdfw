/**
 * @file    sdfwMessenger.cpp
 * @author  Y.Nakaue
 */

#include "sdfwMessenger.hpp"
#include "Audio.hpp"
#include "sdfwEngine.hpp"
#include "sdfwMouse.hpp"

#include <charconv>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>

#ifdef _WIN64
#include <WS2tcpip.h>
#endif

namespace sdfw
{
    constexpr uint16_t BUFF_SIZE = 512;

    IsdfwMessenger* IsdfwMessenger::create()
    {
    #if defined _WIN64
        return new sdfwWinMessenger();
    #elif defined __unix
        return new sdfwUnixSocket();
    #endif
    }

    sdfwWinMessenger::sdfwWinMessenger()
        : cmd_sock_(0)
    {
    }

    sdfwWinMessenger::~sdfwWinMessenger()
    {
        /* Cleanup WinSock2 */
        WSACleanup();
    }

    void sdfwWinMessenger::init()
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

        /* Create socket for command */
        this->cmd_sock_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (this->cmd_sock_ == INVALID_SOCKET)
        {
            std::cout << "socket() for command failed" << std::endl;
        }

        /* Settings for server for command */
        this->cmd_server_.sin_family = AF_INET;
        this->cmd_server_.sin_port = htons(62491);
        InetPton(this->cmd_server_.sin_family, "127.0.0.1", &this->cmd_server_.sin_addr.S_un.S_addr);

        /* Connect to server for command */
        connect(this->cmd_sock_, (sockaddr*)&this->cmd_server_, sizeof(this->cmd_server_));

        /* Create socket for event */
        this->ev_sock_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (this->ev_sock_ == INVALID_SOCKET)
        {
            std::cout << "socket() for event failed" << std::endl;
        }

        /* Settings for server for event */
        this->ev_server_.sin_family = AF_INET;
        this->ev_server_.sin_port = htons(62492);
        InetPton(this->ev_server_.sin_family, "127.0.0.1", &this->ev_server_.sin_addr.S_un.S_addr);

        /* Connect to server for event */
        connect(this->ev_sock_, (sockaddr*)&this->ev_server_, sizeof(this->ev_server_));
    }

    void sdfwWinMessenger::sendMessage(const char* msg)
    {
        recv(this->cmd_sock_, &this->sync_msg_buff_, sizeof(char), 0);

        int32_t result = send(this->cmd_sock_, msg, static_cast<int32_t>(strlen(msg) + 1), 0);
        if (result == SOCKET_ERROR)
        {
            std::cout << "Send failed: " << WSAGetLastError() << std::endl;
            closesocket(this->cmd_sock_);
        }
    }

    void sdfwWinMessenger::execOpenWindow(uint32_t width, uint32_t height)
    {
        char msg[BUFF_SIZE] = "openWindow/";
        strcat_s(msg, std::to_string(width).c_str());   // New window width
        strcat_s(msg, "/");
        strcat_s(msg, std::to_string(height).c_str());  // New window height

        this->sendMessage(msg);

        std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }

    void sdfwWinMessenger::execCloseWIndow(int32_t win_id)
    {
        char msg[BUFF_SIZE] = "closeWindow/";
        strcat_s(msg, std::to_string(win_id).c_str());  // Target window ID

        this->sendMessage(msg);
    }

    void sdfwWinMessenger::execSetBackground(Color color, int32_t win_id)
    {
        char msg[BUFF_SIZE] = "setBackground/";
        strcat_s(msg, std::to_string(color.r).c_str());  // Red value
        strcat_s(msg, "/");
        strcat_s(msg, std::to_string(color.g).c_str());  // Green value
        strcat_s(msg, "/");
        strcat_s(msg, std::to_string(color.b).c_str());  // Blue value
        strcat_s(msg, "/");
        strcat_s(msg, std::to_string(win_id).c_str());  // Target window ID

        this->sendMessage(msg);
    }

    void sdfwWinMessenger::execDrawShape(EShape name, std::vector<int32_t> params)
    {
        char msg[BUFF_SIZE] = "draw/";

        switch (name)
        {
        case EShape::Line:
            strcat_s(msg, "Line/");
            strcat_s(msg, std::to_string(params.at(0)).c_str());  // x0
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(1)).c_str());  // y0
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(2)).c_str());  // x1
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(3)).c_str());  // y1
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(4)).c_str());  // Thickness
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(5)).c_str());  // Red value
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(6)).c_str());  // Green value
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(7)).c_str());  // Blue value
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(8)).c_str());  // Alpha value
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(9)).c_str());  // Target window ID
            break;

        case EShape::Circle:
            strcat_s(msg, "Circle/");
            strcat_s(msg, std::to_string(params.at(0)).c_str());  // x
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(1)).c_str());  // y
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(2)).c_str());  // r
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(3)).c_str());  // Red value
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(4)).c_str());  // Green value
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(5)).c_str());  // Blue value
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(6)).c_str());  // Alpha value
            strcat_s(msg, "/");
            strcat_s(msg, std::to_string(params.at(7)).c_str());  // Target window ID
            break;

        default:
            break;
        }

        this->sendMessage(msg);
    }

    void sdfwWinMessenger::execPrint(std::string str, int32_t win_id)
    {
        char msg[BUFF_SIZE] = "print/";
        strcat_s(msg, str.c_str());  // Output string
        strcat_s(msg, "/");
        strcat_s(msg, std::to_string(win_id).c_str());  // Target window ID

        this->sendMessage(msg);
    }

    void sdfwWinMessenger::execLoadAudioAsset(std::string path)
    {
        char msg[BUFF_SIZE] = "load/Audio/";
        strcat_s(msg, path.c_str());

        this->sendMessage(msg);
    }

    void sdfwWinMessenger::execPlayAudio(Audio* audio)
    {
        char msg[BUFF_SIZE] = "play/Audio/";
        strcat_s(msg, audio->path_.string().c_str());

        this->sendMessage(msg);
    }

    void sdfwWinMessenger::execUpdate()
    {
        char msg[BUFF_SIZE] = "update";

        this->sendMessage(msg);
    }

    void sdfwWinMessenger::execQuit()
    {
        char msg[BUFF_SIZE] = "quit";
        
        this->sendMessage(msg);
    }

    void sdfwWinMessenger::recvEvents()
    {
        char buff;
        std::string str_buff;
        std::vector<std::string> word_list;

        char sync_msg = '0';
        send(this->ev_sock_, &sync_msg, sizeof(sync_msg), 0);

        while (sdfwEngine::get()->loop_flag_)
        {
            recv(this->ev_sock_, &buff, sizeof(char), 0);

            if (buff == '\0')
            {
                // Converting from string to word list
                word_list = this->parseMessage(str_buff);
                
                /* Store received events by category */
                // For mouse events
                if (word_list.at(0) == "Mouse")
                {
                    // For mouse button events
                    if (word_list.at(1) == "Button")
                    {
                        if (word_list.at(2) == "Down")
                        {
                            SDFW_ENGINE(Mouse)->onButtonDown(word_list.at(3).c_str(), stoi(word_list.at(4)), stoi(word_list.at(5)));
                        }
                        else if (word_list.at(2) == "Up")
                        {
                            SDFW_ENGINE(Mouse)->onButtonUp(word_list.at(3).c_str(), stoi(word_list.at(4)), stoi(word_list.at(5)));
                        }
                    }
                    // For mouse coord info
                    else if (word_list.at(1) == "X")
                    {
                        SDFW_ENGINE(Mouse)->current_pos_.x = stoi(word_list.at(2));
                        SDFW_ENGINE(Mouse)->current_pos_.y = stoi(word_list.at(4));
                    }
                }
                // For quit event
                else if (word_list.at(0) == "QUIT")
                {
                    sdfwEngine::get()->loop_flag_ = false;
                }
                
                /* Reset buffer and send sync message */
                str_buff.clear();
                send(this->ev_sock_, &sync_msg, sizeof(sync_msg), 0);
            }
            else
            {
                str_buff += buff;
            }
        }
    }

    std::vector<std::string> sdfwWinMessenger::parseMessage(const std::string& str, const char delimiter)
    {
        std::vector<std::string> words;
        std::string word;

        for (int8_t c : str)
        {
            if (c == delimiter)
            {
                if (!word.empty())
                {
                    words.push_back(word);
                }
                word.clear();
            }
            else
            {
                word += c;
            }
        }

        if (!word.empty())
        {
            words.push_back(word);
        }

        return words;
    }
}
