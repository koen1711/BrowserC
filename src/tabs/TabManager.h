#pragma once

#include "tab/Tab.h"
#include <vector>
#include <string>

class TabManager
{
private:
    std::vector<Tab> tabs;
public:

    TabManager(std::vector<std::string> urls = {});
    ~TabManager();

    std::string parseTabsJson();
    void fetchTabs(bool refetch = false);
};



