/**
 * @file    sdfwEngine.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include "sdfwComponent.hpp"

#include <tuple>

namespace sdfw
{

    class sdfwSocket;

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
         * @brief  Get engine component
         * @return  Specified engine component
         */
        template<class T>
        [[nodiscard]]
        static auto* getComponent()
        {
            return std::get<sdfwComponent<T>>(sdfwEngine::pEngine->components_).get();
        }
        #define SDFW_ENGINE(COMPONENT) sdfwEngine::getComponent<sdfw##COMPONENT>()

    private:
        /// Engine components
        std::tuple<
            sdfwComponent<sdfwSocket>
        > components_;
    };

}
