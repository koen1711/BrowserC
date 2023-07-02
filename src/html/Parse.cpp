#include "Parse.h"
#include <string>
#include "parsing/rapidxml.hpp"
#include <sstream>

#include <iostream>

#include <tidy.h>
#include <tidybuffio.h>

HTMLParser::HTMLParser()
{
}

HTMLParser::~HTMLParser()
{
}



void HTMLParser::Init(std::string HTML)
{
    rapidxml::xml_document<> Document;
    Document.parse<0>(const_cast<char*>(HTML.c_str()));

    rapidxml::xml_node<> *root = Document.first_node();
    ParseNode(root);
}

void HTMLParser::ParseNode(rapidxml::xml_node<> *node)
{
    std::cout << "Parsing node: " << node->name() << std::endl;
    if (std::string(node->name()) == "script")
    {
        scriptNodes.push_back(node);
        if (node->parent())
            node->parent()->remove_node(node);
        std::cout << "Script node found" << std::endl;
    }
    else
    {
        for (rapidxml::xml_node<> *child = node->first_node(); child; child = child->next_sibling())
        {
            ParseNode(child);
        }
    }
}

void HTMLParser::Render()
{
    const char* input = "<html><head><title>Test</title></head><body><h1>Test</h1><script>alert('Hello, World!')</script></body></html>";

    TidyDoc tdoc = tidyCreate();

    tidyParseString(tdoc, input);
}
