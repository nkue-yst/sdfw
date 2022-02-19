/**
 * @file    sdfwEngine.cpp
 * @author  Y.Nakaue
 */

#include "sdfwEngine.hpp"
#include "sdfwSocket.hpp"

#include <iostream>
#include <utility>

namespace sdfw
{

    sdfwEngine::sdfwEngine()
    {
        sdfwEngine::pEngine = this;
    }

    sdfwEngine::~sdfwEngine()
    {
        delete sdfwEngine::pEngine;
        sdfwEngine::pEngine = nullptr;
    }

    /* Initialize all components */
    void sdfwEngine::init()
    {
        SDFW_ENGINE(Socket)->init();
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

    /* Quit and release all components */
    void sdfwEngine::quit()
    {
        components::releaseAll(this->components_);
    }

}
