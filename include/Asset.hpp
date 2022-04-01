/**
 * @file    Asset.hpp
 * @author  Y.Nakaue
 */

#pragma once

#include <filesystem>

namespace sdfw
{

    class Asset
    {
    public:
        Asset(std::string path)
        {
            this->path_ = std::filesystem::absolute(path);
        }

        std::filesystem::path path_;
    };

}
