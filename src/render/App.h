#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>

#include <iostream>
#include "../datamanager/AppData.h"
#include "Events/JavaScript.h"

using namespace ultralight;


class MainApp : public WindowListener,
              public ViewListener, public LoadListener {
  AppData* app_data_;
  JavaScriptEventHandler* js_event_handler_;
  RefPtr<App> app_;
  RefPtr<Window> window_;
  RefPtr<Overlay> overlay_;
  RefPtr<Overlay> inspector_overlay_;


public:




  MainApp();

  virtual ~MainApp() {}

  virtual void OnClose(ultralight::Window* window) override {
    app_->Quit();
  }
  virtual void OnResize(ultralight::Window* window, uint32_t width, uint32_t height) override {}

  virtual void OnChangeCursor(ultralight::View* caller, ultralight::Cursor cursor) override {
    window_->SetCursor(cursor);
  }



  void Run() {
    app_->Run();
  }
};