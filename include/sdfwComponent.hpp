/**
 * @file    sdfwComponent.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include <iostream>

namespace sdfw
{

    /**
     * @brief  Engine component base class
     */
    template<class T>
    class sdfwComponent
    {
    private:
        inline static T* pComponent = nullptr;

    public:
        /**
         * @brief  Get component (return self pointer)
         */
        [[nodiscard]]
        T* get()
        {
            if (pComponent == nullptr)
            {
                pComponent = T::create();
            }

            return pComponent;
        }

        /**
         * @brief  Release this component
         */
        void release()
        {
            delete pComponent;
            pComponent = nullptr;
        }
    };

}
