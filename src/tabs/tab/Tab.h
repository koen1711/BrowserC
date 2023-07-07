#pragma once

#include <string>

class Tab {
    private:
        std::string url;
        std::string md5;
        std::string html;
    public:
        Tab(std::string url);

        void Init();
        void FetchPage();
        std::string toJson();
        std::string getHtml();
};