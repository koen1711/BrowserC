#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include "JavaScript.h"

#include <iostream>
#include <string>

using namespace ultralight;

inline std::string ToUTF8(const String& str) {
  String8 utf8 = str.utf8();
  return std::string(utf8.data(), utf8.length());
}

inline const char* Stringify(MessageSource source) {
  switch(source) {
    case kMessageSource_XML: return "XML";
    case kMessageSource_JS: return "JS";
    case kMessageSource_Network: return "Network";
    case kMessageSource_ConsoleAPI: return "ConsoleAPI";
    case kMessageSource_Storage: return "Storage";
    case kMessageSource_AppCache: return "AppCache";
    case kMessageSource_Rendering: return "Rendering";
    case kMessageSource_CSS: return "CSS";
    case kMessageSource_Security: return "Security";
    case kMessageSource_ContentBlocker: return "ContentBlocker";
    case kMessageSource_Other: return "Other";
    default: return "";
  }
}

inline const char* Stringify(MessageLevel level) {
  switch(level) {
    case kMessageLevel_Log: return "Log";
    case kMessageLevel_Warning: return "Warning";
    case kMessageLevel_Error: return "Error";
    case kMessageLevel_Debug: return "Debug";
    case kMessageLevel_Info: return "Info";
    default: return "";
  }
}

void JavaScriptEventHandler::OnAddConsoleMessage(View* caller,
                                MessageSource source,
                                MessageLevel level,
                                const String& message,
                                uint32_t line_number,
                                uint32_t column_number,
                                const String& source_id) {
  
  std::cout << "[Console]: [" << Stringify(source) << "] ["
            << Stringify(level) << "] " << ToUTF8(message);
  
  if (source == kMessageSource_JS) {
    std::cout << " (" << ToUTF8(source_id) << " @ line " << line_number 
              << ", col " << column_number << ")";
  }

  std::cout << std::endl;

}

void JavaScriptEventHandler::OnDOMReady(View* caller,
                          uint64_t frame_id,
                          bool is_main_frame,
                          const String& url)
{
    RefPtr<JSContext> context = caller->LockJSContext();
    SetJSContext(context->ctx());
    JSObject global = JSGlobalObject();
    global["GetTabs"] = static_cast<ultralight::JSCallbackWithRetval>([](const ultralight::JSObject& thisObject, const ultralight::JSArgs& args) -> ultralight::JSValue {
      std::cout << "GetMessage called" << std::endl;
      return ultralight::JSValue("");
    });

    global["ShowLog"] = static_cast<ultralight::JSCallbackWithRetval>([](const ultralight::JSObject& thisObject, const ultralight::JSArgs& args) -> ultralight::JSValue {
        std::cout << "showlog called" << std::endl;
        std::cout << args[0].ToString() << std::endl;
        return ultralight::JSValue("");
    });

}


