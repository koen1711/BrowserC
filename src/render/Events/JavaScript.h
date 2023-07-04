#pragma once

#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <AppCore/JSHelpers.h>

using namespace ultralight;

class JavaScriptEventHandler: public WindowListener, public ViewListener, public LoadListener {

    public:
        JavaScriptEventHandler() {}

        virtual void OnDOMReady(View* caller,
                            uint64_t frame_id,
                            bool is_main_frame,
                            const String& url) override;

        virtual void OnAddConsoleMessage(View* caller,
                                MessageSource source,
                                MessageLevel level,
                                const String& message,
                                uint32_t line_number,
                                uint32_t column_number,
                                const String& source_id) override;

};