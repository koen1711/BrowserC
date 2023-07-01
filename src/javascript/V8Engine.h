#pragma once

#include <libplatform/libplatform.h>
#include <v8-context.h>
#include <v8-initialization.h>
#include <v8-isolate.h>
#include <v8-local-handle.h>
#include <v8-primitive.h>
#include <v8-script.h>


class V8Engine {
    private:
        v8::Isolate* isolate;
        v8::Local<v8::Context> context;

    public:
        V8Engine();
        ~V8Engine();

        void init();
        void startJavaScriptExecution(std::string script);
};