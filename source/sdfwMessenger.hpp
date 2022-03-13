/**
 * @file    sdfwMessenger.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include "Color.hpp"
#include <cstdint>
#include <string>
#include <vector>

#ifdef _WIN64
#include <WinSock2.h>
#endif

namespace sdfw
{

    /**
     * @brief  Socket interface class
     */
    class IsdfwMessenger
    {
    public:
        virtual ~IsdfwMessenger() = default;

        /**
         * @brief  Create instance
         */
        static IsdfwMessenger* create();

        /**
         * @brief  Initialize socket
         */
        virtual void init() = 0;

        /**
         * @brief  Send message
         */
        virtual void sendMessage(const char* msg) = 0;

        /**
         * @brief  Execute opening window
         */
        virtual void execOpenWindow(uint32_t width, uint32_t height) = 0;

        /**
         * @brief  Execute close window
         */
        virtual void execCloseWIndow(int32_t win_id) = 0;

        /**
         * @brief  Execute setting background color
         * @param  (color)  New background color
         * @param  (win_id)  Target window ID
         */
        virtual void execSetBackground(Color color, int32_t win_id) = 0;

        /**
         * @brief  Execute print string
         * @param  (str)  Output string
         * @param  (win_id) The ID of window to print string
         */
        virtual void execPrint(std::string str, int32_t win_id) = 0;

        /**
         * @brief  Execute system update
         */
        virtual void execUpdate() = 0;

        /**
         * @brief  Execute quit command
         */
        virtual void execQuit() = 0;

        /**
         * @brief  Receive events
         */
        virtual void recvEvents() = 0;

    protected:
        char sync_msg_buff_;
    };


    /**
     * @brief  Socket class for Windows
     */
    class sdfwWinMessenger : public IsdfwMessenger
    {
    public:
        sdfwWinMessenger();
        ~sdfwWinMessenger() override;

        /**
         * @brief  Initialize socket
         */
        void init() override;

        /**
         * @brief  Send message
         */
        void sendMessage(const char* msg) override;

        /**
         * @brief  Execute opening window
         */
        void execOpenWindow(uint32_t width, uint32_t height) override;

        /**
         * @brief  Execute close window
         */
        void execCloseWIndow(int32_t win_id) override;

        /**
         * @brief  Execute setting background color
         * @param  (color)  New background color
         * @param  (win_id)  Target window ID
         */
        void execSetBackground(Color color, int32_t win_id) override;

        /**
         * @brief  Execute print string
         * @param  (str)  Output string
         * @param  (win_id) The ID of window to print string
         */
        void execPrint(std::string str, int32_t win_id) override;

        /**
         * @brief  Execute system update
         */
        void execUpdate() override;

        /**
         * @brief  Execute quit command
         */
        void execQuit() override;

        /**
         * @brief  Receive events
         */
        void recvEvents() override;

    private:
        /**
         * @brief  Parse a string
         * @param  (str)  Target string
         * @param  (delimiter)  Character used to delimit string
         * @return  Split word list
         */
        static std::vector<std::string> parseMessage(const std::string& str, const char delimiter = '/');

        /// Client socket for command
        SOCKET cmd_sock_;

        /// Server socket info for command
        sockaddr_in cmd_server_;

        /// Client socket for event
        SOCKET ev_sock_;

        /// Server socket info for event
        sockaddr_in ev_server_;
    };


    /**
     * @brief  Socket class for UNIX-based OS
     */
    class sdfwUnixMessenger : public IsdfwMessenger
    {
    };

}
