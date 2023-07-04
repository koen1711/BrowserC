#pragma once

#include "tab/Tab.h"
#include <vector>

class TabManager
{
private:
    std::vector<Tab> tabs;
public:

    TabManager();
    ~TabManager();
};



