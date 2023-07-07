#include "tab/Tab.h"
#include "TabManager.h"
#include <vector>
#include <string>

TabManager::TabManager(std::vector<std::string> urls)
{
    if (urls.size() == 0) {
        tabs.push_back(Tab("https://www.google.com"));
    }

    for (int i = 0; i < urls.size(); i++) {
        tabs.push_back(Tab(urls[i]));
    }
}


TabManager::~TabManager()
{
}

void TabManager::fetchTabs(bool refetch) {
    for (int i = 0; i < tabs.size(); i++) {
        if (tabs[i].getHtml() == "" || refetch) {
            tabs[i].FetchPage();
        } else if (tabs[i].getHtml() == "") {
            tabs[i].FetchPage();
        }
    }
}

std::string TabManager::parseTabsJson() {
    std::string json = "[";
    for (int i = 0; i < tabs.size(); i++) {
        json += tabs[i].toJson();
        if (i != tabs.size() - 1) {
            json += ",";
        }
    }
    json += "]";
    return json;

}