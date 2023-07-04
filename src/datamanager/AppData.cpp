#include "AppData.h"
#include <openssl/md5.h>
#include <cstdlib>
#include <iostream>
#include <string>

#ifdef __linux__
AppData::AppData() {
    const char* username = std::getenv("USER");
    if (username) {
        path = std::string("/home/") + username + "/.cache/browserc/";
    } else {
        path = nullptr; // Handle the case when the username cannot be retrieved
    }
}
#elif _WIN32
const char* getPath() {
    const char* username = std::getenv("USERPROFILE");
    if (username) {
        path = std::string(username) + "\\AppData\\Local\\browserc\\";
    } else {
        path = nullptr; // Handle the case when the username cannot be retrieved
    }
}
#endif

AppData::~AppData()
{
}

std::string AppData::getPath()
{
    return path;
}

std::string AppData::generateHtmlPath(std::string site)
{
    // turn site into a md5 hash
    unsigned char digest[MD5_DIGEST_LENGTH];
    // return the normal path + the hash
    return path + "/pages/" + std::string((char*)digest);

}