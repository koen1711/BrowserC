#pragma once

#include <fstream>
#include <string>
#include "../../datamanager/AppData.h"

class FileSystem
{
    private:
        AppData* appData_;
    public:
        FileSystem() {
            this->appData_ = new AppData();
        }
        ~FileSystem();

        std::string getExactPath(std::string path) {
            std::string exactPath;
            if (path.find("internal://") == 0) {
                path = path.substr(11);
                exactPath = this->appData_->getPath() + std::string("assets/internal/") + path;
            } else if (path.find("ui://") == 0) {
                path = path.substr(5);
                exactPath = this->appData_->getPath() + std::string("assets/ui/") + path;
            } else if (path.find("browser://") == 0) {
                path = path.substr(10);
                exactPath = this->appData_->getPath() + std::string("assets/html/") + path;
            } else {
                exactPath = this->appData_->getPath() + std::string("assets/") + path;
            }
            return exactPath;
        }

        std::string getFileContents(std::string path) {
            FILE* file = fopen(path.c_str(), "r");
            if (file == NULL) {
                return std::string("File not found");
            }
            std::string contents;
            char buffer[256];
            while (fgets(buffer, 256, file)) {
                contents += buffer;
            }
            fclose(file);
            return contents;
        }
};