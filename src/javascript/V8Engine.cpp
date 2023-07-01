#include "V8Engine.h"

#include <libplatform/libplatform.h>
#include <v8-context.h>
#include <v8-initialization.h>
#include <v8-isolate.h>
#include <v8-local-handle.h>
#include <v8-primitive.h>
#include <v8-script.h>

#include <string>

V8Engine::V8Engine() {
    this->isolate = nullptr;
    this->context = v8::Local<v8::Context>();
}

void V8Engine::init() {
    v8::V8::InitializeICUDefaultLocation("./");
    v8::V8::InitializeExternalStartupData("./");
    std::unique_ptr<v8::Platform> platform = v8::platform::NewDefaultPlatform();
    v8::V8::InitializePlatform(platform.get());
    v8::V8::Initialize();


    v8::Isolate::CreateParams create_params;
    create_params.array_buffer_allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();
    v8::Isolate* isolate = v8::Isolate::New(create_params);
    {
        v8::Isolate::Scope isolate_scope(isolate);

        // Create a stack-allocated handle scope.
        v8::HandleScope handle_scope(isolate);
    }
}

V8Engine::~V8Engine() {
    v8::V8::Dispose();
    v8::V8::DisposePlatform();
}

void V8Engine::startJavaScriptExecution(std::string script) {
    v8::Local<v8::Context> context = v8::Context::New(this->isolate);

    // Enter the context for compiling and running the hello world script.
    v8::Context::Scope context_scope(context);

    {
      // Create a string containing the JavaScript source code.
      v8::Local<v8::String> source =
          v8::String::NewFromUtf8Literal(isolate, "'Hello' + ', World!'");

      v8::Local<v8::Script> script =
          v8::Script::Compile(context, source).ToLocalChecked();
      v8::Local<v8::Value> result = script->Run(context).ToLocalChecked();
      v8::String::Utf8Value utf8(isolate, result);
    }
}
