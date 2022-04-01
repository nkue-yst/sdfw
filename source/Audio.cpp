/**
 * @file    Audio.cpp
 * @author  Y.Nakaue
 */

#include "Audio.hpp"
#include "sdfwEngine.hpp"
#include "sdfwMessenger.hpp"

#include <iostream>

namespace sdfw
{

    Audio::Audio(std::string path)
        : Asset(path)
    {
        SDFW_ENGINE(Messenger)->execLoadAudioAsset(this->path_.string());
    }

    void Audio::play()
    {
        SDFW_ENGINE(Messenger)->execPlayAudio(this);
    }

    void playAudio(std::string path)
    {
        Audio audio(path);
        SDFW_ENGINE(Messenger)->execPlayAudio(&audio);
    }

}
