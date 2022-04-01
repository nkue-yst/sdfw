/**
 * @file    Audio.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include "Asset.hpp"


namespace sdfw
{

    class Audio : public Asset
    {
    public:
        Audio(std::string path);

        void play();
    };

    void playAudio(std::string path);

}
