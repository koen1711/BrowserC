#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <AppCore/JSHelpers.h>
#include <iostream>


using namespace ultralight;


class MainApp : public WindowListener,
              public ViewListener, public LoadListener {
  RefPtr<App> app_;
  RefPtr<Window> window_;
  RefPtr<Overlay> overlay_;
public:
  virtual void OnDOMReady(View* caller,
                          uint64_t frame_id,
                          bool is_main_frame,
                          const String& url) override {
    RefPtr<JSContext> context = caller->LockJSContext();
    SetJSContext(context->ctx());
    JSObject global = JSGlobalObject();
    global["GetTabs"] = static_cast<ultralight::JSCallbackWithRetval>([](const ultralight::JSObject& thisObject, const ultralight::JSArgs& args) -> ultralight::JSValue {
      std::cout << "GetMessage called" << std::endl;
      return ultralight::JSValue("");
    });

    global.
    // showlog function it gives us a string and we can print it
    global["showlog"] = static_cast<ultralight::JSCallbackWithRetval>([](const ultralight::JSObject& thisObject, const ultralight::JSArgs& args) -> ultralight::JSValue {
      std::cout << "showlog called" << std::endl;
      std::cout << args[0].ToString() << std::endl;
      return ultralight::JSValue("");
    });

  }

  MainApp() {
    app_ = App::Create();


    window_ = Window::Create(app_->main_monitor(), 900, 600, false, kWindowFlags_Titled);
    window_->SetTitle("Ultralight Sample 2 - Basic App");
    overlay_ = Overlay::Create(window_, window_->width(), window_->height(), 0, 0);
    overlay_->view()->LoadURL("file:///index.html");
    window_->set_listener(this);

    overlay_->view()->set_load_listener(this);

    overlay_->view()->set_view_listener(this);
  }

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