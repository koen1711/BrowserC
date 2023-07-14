#pragma once

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include <JavaScriptCore/JavaScript.h>
#include <iostream>
#include "../../javascript/JavascriptHandler.h"

class EventHandler {

    public:
        WebKitWebView* webView_;

        EventHandler(WebKitWebView* webView) {
            this->webView_ = webView;
            webkit_settings_set_enable_developer_extras(webkit_web_view_get_settings(WEBKIT_WEB_VIEW(webView_)), TRUE);
            g_signal_connect(webView, "load-changed", G_CALLBACK(onWebViewReady), NULL);
            g_signal_connect(webView, "context-menu", G_CALLBACK(onWebViewContextMenu), NULL);
            g_signal_connect(webView, "load-failed", G_CALLBACK(onLoadFailed), NULL);
            // add the event for creating a jscontext
        }

        static void onWebViewContextMenu(WebKitWebView* webView, WebKitContextMenu* contextMenu, GdkEvent* event, WebKitHitTestResult* hitTestResult, gpointer userData)
        {
            GtkWidget* inspectMenuItem = gtk_menu_item_new_with_label("Inspect Element");
            g_signal_connect(inspectMenuItem, "activate", G_CALLBACK(onInspectMenuItemActivate), webView);
            gtk_menu_shell_append(GTK_MENU_SHELL(contextMenu), inspectMenuItem);
            gtk_widget_show_all(GTK_WIDGET(contextMenu));
        }

        static void onInspectMenuItemActivate(GtkMenuItem* menuItem, gpointer userData) {
            WebKitWebView *webView = WEBKIT_WEB_VIEW(userData);
            webkit_web_inspector_show(webkit_web_view_get_inspector(webView));
        }



        static void onWebViewReady(WebKitWebView* webView, gpointer userData)
        {
            JavaScriptHandler::instance().createBrowserFunctions();
        }

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

        static void onLoadFailed(WebKitWebView* webView, WebKitLoadEvent loadEvent, gchar* failingURI, GError* error, gpointer userData) {
            // Handle load failure
            g_print("Failed to load script: %s\n", failingURI);
            g_print("Error message: %s\n", error->message);
        }

    private:
};