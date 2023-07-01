#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include <string>

class HTMLParser
{
private:
    std::string html;
    std::string css;
public:
    HTMLParser(std::string html, std::string css);
    ~HTMLParser();
    void parse();
};

#endif // HTMLPARSER_H