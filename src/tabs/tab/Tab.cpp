#include "Tab.h"
#include <curl/curl.h>
#include <openssl/md5.h>
#include <sstream>
#include <iomanip>
#include "../../datamanager/AppData.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <filesystem>



std::string md5ToString(const unsigned char* digest) {
    std::ostringstream oss;
    oss << std::hex << std::setfill('0');

    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        oss << std::setw(2) << static_cast<unsigned int>(digest[i]);
    }

    return oss.str();
}

AppData* app_data_ = new AppData();

Tab::Tab(std::string url)
{
    this->url = url;
    // create md5 hash
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((const unsigned char*)url.c_str(), url.length(), digest);

    this->md5 = md5ToString(digest);

}

void Tab::FetchPage() {
    std::cout << "MD5: " << this->md5 << std::endl;
    std::string save_directory = app_data_->getPath() + "assets/html/" + this->md5;
    std::string save_path = save_directory + "/index.html";

    // Create the directory if it doesn't exist
    std::filesystem::create_directories(save_directory);

    // Create the file if it doesn't exist
    std::ofstream file(save_path, std::ios::binary | std::ios::app);

    if (!file) {
        // Handle the case when the file cannot be opened or created
        std::cerr << "Failed to open or create the file: " << save_path << std::endl;
        return;
    }

    FILE* file_ = fopen(save_path.c_str(), "wb");

    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, this->url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file_);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    std::cout << "Fetched: " << this->url << std::endl;

    file.close();
}




std::string Tab::toJson() {
    return "{\"url\":\"" + this->url + "\",\"md5\":\"" + this->md5 + "\"}";
}

std::string Tab::getHtml() {
    return this->html;
}