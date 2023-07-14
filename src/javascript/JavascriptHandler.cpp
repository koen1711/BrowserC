#include "JavascriptHandler.h"
#include <JavaScriptCore/JavaScript.h>
#include <gtk/gtk.h>

JavaScriptHandler::JavaScriptHandler() {
    std::cout << "Javascripthandler constructor" << std::endl;
    this->context_ = JSGlobalContextCreate(NULL);
}

JavaScriptHandler::~JavaScriptHandler() {
    std::cout << "Javascripthandler destructor" << std::endl;
    // delete this->context_;
    JSGlobalContextRelease(this->context_);

}