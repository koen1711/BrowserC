#pragma once

#include <string>

class Tab {
    private:
    public:
        Tab(std::string url);

        void Init();
        void FetchPage();
};