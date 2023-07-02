
#pragma once

#include <string>
#include "parsing/rapidxml.hpp"

struct HTML
{
    HTML();
    ~HTML();

    void Init(std::string HTML);

    rapidxml::xml_document<> Document;
};

HTML::Init(std::string HTML)
{
    Document.parse<0>(HTML.c_str());
}