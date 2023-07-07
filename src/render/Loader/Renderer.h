#pragma once

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include "FileSystem.h"
#include <iostream>

class Renderer
{
    private:
        GtkWidget* window_;
        WebKitWebView* webView_;
        FileSystem* fileSystem_ = new FileSystem();

    public:
        Renderer(GtkWidget* window, WebKitWebView* webView) {
            this->window_ = window;
            this->webView_ = webView;
        }
        ~Renderer();

        void renderFile(std::string path) {
            std::cout << path << std::endl;
            std::string exactPath = this->fileSystem_->getExactPath(path);
            webkit_web_view_load_uri(this->webView_, (std::string("file://") + exactPath).c_str());
        }
};