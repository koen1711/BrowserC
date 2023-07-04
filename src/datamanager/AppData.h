#pragma once

#include <string>

class AppData
{
    private:
        std::string path;
    public:
        AppData();
        ~AppData();
        std::string getPath();
        std::string generateHtmlPath(std::string site);
};