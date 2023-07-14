#ifndef BROWSER_JAVASCRIPTHANDLER_H
#define BROWSER_JAVASCRIPTHANDLER_H

#include <JavaScriptCore/JavaScript.h>
#include <iostream>
#include <webkit2/webkit2.h>


class JavaScriptHandler {
    public:
        JSGlobalContextRef context_;
        WebKitWebView* webView_;

        static JavaScriptHandler& instance() {
            static JavaScriptHandler instance;  // Create the instance on first access
            return instance;
        }

        // Delete the copy constructor and assignment operator
        JavaScriptHandler(const JavaScriptHandler&) = delete;
        JavaScriptHandler& operator=(const JavaScriptHandler&) = delete;

        // Add your class methods and members here
        void setWebView(WebKitWebView* webView) {
            this->webView_ = webView;

            // update the context
            this->context_ = webkit_web_view_get_javascript_global_context(this->webView_);
        }

        void createBrowserFunctions() {
            JSStringRef functionName = JSStringCreateWithUTF8CString("GetTabs");
            JSObjectRef functionObject = JSObjectMakeFunctionWithCallback(this->context_, functionName, myCFunction);
            JSObjectSetProperty(this->context_, JSContextGetGlobalObject(this->context_), functionName, functionObject, kJSPropertyAttributeNone, NULL);
        }

        // myCFunction
        static JSValueRef myCFunction(JSContextRef context, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)
        {
            std::cout << "Hello World!" << std::endl;

            // Create a JavaScript string containing "Hello World!"
            JSStringRef string = JSStringCreateWithUTF8CString("Hello World!");

            // Create a JavaScript value using the above string
            JSValueRef value = JSValueMakeString(context, string);

            // Release the string
            JSStringRelease(string);

            // Return the JavaScript value
            return value;
        }
    private:
        // Private constructor to prevent direct instantiation
        JavaScriptHandler();

        // Destructor
        ~JavaScriptHandler();
};

#endif //BROWSER_JAVASCRIPTHANDLER_H
