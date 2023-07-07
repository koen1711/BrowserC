#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include "App.h"
#include "Loader/Renderer.h"
#include "EventHandler/EventHandler.h"

App::App(int argc, char** argv) {

    gtk_init(&argc, &argv);

    GtkWidget* webView = webkit_web_view_new();
    WebKitSettings* settings = webkit_web_view_get_settings(WEBKIT_WEB_VIEW(webView));
    g_object_set(G_OBJECT(settings), "enable-scripts", TRUE, NULL);
    g_object_set(G_OBJECT(settings), "enable-web-security", FALSE, NULL);
    webkit_settings_set_enable_javascript(settings, TRUE);
    webkit_settings_set_allow_file_access_from_file_urls(settings, TRUE);
    webkit_settings_set_allow_universal_access_from_file_urls(settings, TRUE);
    webkit_settings_set_allow_modal_dialogs(settings, TRUE);
    webkit_web_view_set_settings(WEBKIT_WEB_VIEW(webView), settings);

    this->renderer_ = new Renderer(this->window_, WEBKIT_WEB_VIEW(webView));
    this->eventHandler_ = new EventHandler(WEBKIT_WEB_VIEW(webView));

    this->window_ = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window_), 800, 600);
    gtk_container_add(GTK_CONTAINER(window_), webView);

    g_signal_connect(window_, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    this->renderer_->renderFile("ui://index.html");
}

App::~App() {
    // Clean up
}

void App::Run() {
    // Run the GTK main loop
    gtk_widget_show_all(window_);
    gtk_main();
}