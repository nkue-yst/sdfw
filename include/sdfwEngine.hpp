/**
 * @file    sdfwEngine.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include "sdfwComponent.hpp"

#include <tuple>

namespace sdfw
{

    class IsdfwSocket;

    /**
     * @brief  Engine core class
     */
    class sdfwEngine
    {
    private:
        inline static sdfwEngine* pEngine = nullptr;

    public:
        sdfwEngine();
        ~sdfwEngine();

        /**
         * @brief  Initialize all components
         */
        void init();

        /**
         * @brief  Quit and release all components
         */
        void quit();

        /**
         * @brief  Get engine instance
         * @return  Engine instance
         */
        [[nodiscard]]
        static sdfwEngine* get()
        {
            if (sdfwEngine::pEngine == nullptr)
            {
                sdfwEngine::pEngine = new sdfwEngine();
            }

            return sdfwEngine::pEngine;
        }

        /**
         * @brief  Get engine component
         * @return  Specified engine component
         */
        template<class T>
        [[nodiscard]]
        static auto* getComponent()
        {
            return std::get<sdfwComponent<T>>(sdfwEngine::pEngine->components_).get();
        }
        #define SDFW_ENGINE(COMPONENT) sdfwEngine::getComponent<Isdfw##COMPONENT>()

    private:
        /// Engine components
        std::tuple<
            sdfwComponent<IsdfwSocket>
        > components_;
    };

}
