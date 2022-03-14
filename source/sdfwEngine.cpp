/**
 * @file    sdfwEngine.cpp
 * @author  Y.Nakaue
 */

#include "sdfwEngine.hpp"
#include "sdfwMessenger.hpp"
#include "sdfwMouse.hpp"

#include <iostream>
#include <utility>

namespace sdfw
{

    sdfwEngine::sdfwEngine()
        : loop_flag_(true)
        , tick_(0)
    {
        sdfwEngine::pEngine = this;
    }

    sdfwEngine::~sdfwEngine()
    {
        delete sdfwEngine::pEngine;
        sdfwEngine::pEngine = nullptr;
    }

    void sdfwEngine::init()
    {
        SDFW_ENGINE(Messenger)->init();
        this->start_time_ = std::chrono::system_clock::now();
    }

    namespace components
    {
        /**
         * @brief  Release an engine component
         */
        template<size_t N, class T>
        static void release(T&& t)
        {
            std::get<N>(t).release();

            if constexpr (N > 0)
            {
                components::release<N - 1>(t);
            }
        }

        /**
         * @brief  Release all engine components
         */
        template <class T>
        static void releaseAll(T&& t)
        {
            return components::release<std::tuple_size_v<std::remove_reference_t<T>> -1>(std::forward<T>(t));
        }
    }

    void sdfwEngine::quit()
    {
        SDFW_ENGINE(Messenger)->execQuit();

        this->loop_flag_ = false;

        components::releaseAll(this->components_);
    }

}
