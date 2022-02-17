/**
 * @file    sdfwComponent.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include <utility>

namespace sdfw
{

    /**
     * @brief  Singleton base class
     */
    template<typename T>
    class sdfwComponent
    {
    public:
        /**
         * @brief  Get singleton instance
         */
        template<typename... Args>
        static T& getInstance(Args... args)
        {
            static T instance{ std::forward<Args>(args)... };
            return instance;
        }

    protected:
        sdfwComponent() = default;
        virtual ~sdfwComponent() = default;
        sdfwComponent(const sdfwComponent&) = delete;
        sdfwComponent& operator=(const sdfwComponent&) = delete;
    };

}
