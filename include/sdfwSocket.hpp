/**
 * @file    Socket.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include <cstdint>

#ifdef _WIN64
#include <WinSock2.h>
#endif

namespace sdfw
{

    /**
     * @brief  Socket interface class
     */
    class IsdfwSocket
    {
    public:
        virtual ~IsdfwSocket() = default;

        /**
         * @brief  Create instance
         */
        static IsdfwSocket* create();

        /**
         * @brief  Initialize socket
         */
        virtual void init() = 0;

        /**
         * @brief  Execute opening window
         */
        virtual void execOpenWindow(uint32_t width, uint32_t height) = 0;

        /**
         * @brief  Execute quit command
         */
        virtual void execQuit() = 0;
    };


    /**
     * @brief  Socket class for Windows
     */
    class sdfwWinSocket : public IsdfwSocket
    {
    public:
        sdfwWinSocket();
        ~sdfwWinSocket() override;

        /**
         * @brief  Initialize socket
         */
        void init() override;

        /**
         * @brief  Execute opening window
         */
        void execOpenWindow(uint32_t width, uint32_t height) override;

        /**
         * @brief  Execute quit command
         */
        void execQuit() override;

    private:
        /// Client socket
        SOCKET sock_;

        /// Server socket info
        sockaddr_in server_;
    };


    /**
     * @brief  Socket class for UNIX-based OS
     */
    class sdfwUnixSocket : public IsdfwSocket
    {
    };

}
