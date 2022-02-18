/**
 * @file    sdfwEngine.cpp
 * @author  Y.Nakaue
 */

#include "sdfwEngine.hpp"

namespace sdfw
{

    sdfwEngine::sdfwEngine()
    {
        sdfwEngine::pEngine = this;
    }

    sdfwEngine::~sdfwEngine()
    {
        sdfwEngine::pEngine = nullptr;
    }

}
