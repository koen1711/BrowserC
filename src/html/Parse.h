#pragma once

#include <string>
#include <vector>
#include "parsing/rapidxml.hpp"


class HTMLParser
{
public:
    HTMLParser();
    ~HTMLParser();

    void Init(std::string HTML);
    void ParseNode(rapidxml::xml_node<> *node);
    void Render();

    rapidxml::xml_document<> Document;
    std::vector<rapidxml::xml_node<>*> scriptNodes;
};
