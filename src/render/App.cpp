#include "App.h"

#include <Ultralight/Ultralight.h>
#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <AppCore/JSHelpers.h>
#include <iostream>
#include "../tabs/TabManager.h"
#include "../datamanager/AppData.h"
#include "Events/JavaScript.h"


MainApp::MainApp() {
  js_event_handler_ = new JavaScriptEventHandler();
  app_data_ = new AppData();
  // copy the /assets folder to the appdata folder
  // this is where we will store all of our data
  const char* assets = "assets/";
  Settings settings;
  Config config;

  settings.file_system_path = String(assets);



  config.resource_path_prefix = String("/resources/");

  app_ = App::Create(settings, config);


  window_ = Window::Create(app_->main_monitor(), 900, 600, false, kWindowFlags_Titled);
  window_->SetTitle("AA");

  overlay_ = Overlay::Create(window_, window_->width(), window_->height(), 0, 0);
  overlay_->view()->LoadURL("file:///index.html");
  window_->set_listener(this);

  window_->set_listener(js_event_handler_);
  overlay_->view()->set_load_listener(js_event_handler_);

  overlay_->view()->set_view_listener(this);
}


