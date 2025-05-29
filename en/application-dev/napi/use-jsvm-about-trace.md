# Working with Trace Using JSVM-API

## Introduction

You can use the trace-related APIs in JSVM-API to collect and output various types of runtime information. This capability can be used for fault location and performance analysis in the JSVM module.

## Basic Concepts

With the trace-related APIs, you can specify the categories for data collecting, collect information about JSVM internal events related to the specified categories, and return the collected information in JSON format via the specified callback.

The trace capabilities provided by JSVM-API allow seamless integration of the JSVM module with the JavaScript environment, facilitating the identification of complex problems and system profiling.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_TraceStart           | Starts collecting runtime information based on the specified event type and event count limit. |
| OH_JSVM_TraceStop        | Stops collecting information and returns the collected information in JSON format via the specified callback. |

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in trace development.

### Collecting Data

CPP code:

```cpp
#include <vector>
#include <string>

bool OutputStream(const char *data, int size, void *streamData) {
    std::string value(data, size);
    *(std::string *)streamData = std::string(data, size);
    return true;
}

// OH_JSVM_TraceStart/OH_JSVM_TraceStop methods.
static JSVM_Value Trace(JSVM_Env env, JSVM_CallbackInfo info) {
    // Start trace based on the specified categories.
    std::vector<JSVM_TraceCategory> categories = {JSVM_TRACE_VM};
    JSVM_CALL(OH_JSVM_TraceStart(categories.size(), categories.data(), "trace test", 0));

    // Run the code and trace data.
    JSVM_Script script;
    JSVM_Value jsSrc;
    JSVM_Value result;
    const char* trace_js = R"JS(
      function map(x, y) {
        return {"a": x, "b": y};
      }
      for (var i = 0; i < 80000; ++i) {
        var x = map(i, i);
      }
    )JS";
    JSVM_CALL(OH_JSVM_CreateStringUtf8(env, trace_js, JSVM_AUTO_LENGTH, &jsSrc));
    JSVM_CALL(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    JSVM_CALL(OH_JSVM_RunScript(env, script, &result));
    
    // Stop tracing and write file.
    std::string data;
    JSVM_CALL(OH_JSVM_TraceStop(OutputStream, (void *)&data));

    OH_LOG_INFO(LOG_APP, "JSVM Trace success:%{public}s", data.c_str());
    return nullptr;
}
// Register the trace callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = Trace},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named trace and associate it with a callback. This allows the Trace callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"trace", nullptr, method, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char *srcCallNative = R"JS(trace())JS";
```
Expected result:
```
JSVM Trace success:{"trace test":[{"pid":54485,"tid":54485,"ts":341364468711,"tts":139452,"ph":"B","cat":"devtools.timeline,v8","name":"MinorGC","dur":0,"tdur":0,"args":{"usedHeapSizeBefore":1592824,"type":"allocation failure"}},{"pid":54485,"tid":54485,"ts":341364468727,"tts":139463,"ph":"X","cat":"v8","name":"V8.GCScavenger","dur":203,"tdur":203,"args":{}},{"pid":54485,"tid":54485,"ts":341364468949,"tts":139684,"ph":"E","cat":"devtools.timeline,v8","name":"MinorGC","dur":0,"tdur":0,"args":{"usedHeapSizeAfter":173472}},{"pid":54485,"tid":54485,"ts":341364471055,"tts":141792,"ph":"B","cat":"devtools.timeline,v8","name":"MinorGC","dur":0,"tdur":0,"args":{"usedHeapSizeBefore":1208672,"type":"allocation failure"}},{"pid":54485,"tid":54485,"ts":341364471060,"tts":141796,"ph":"X","cat":"v8","name":"V8.GCScavenger","dur":110,"tdur":110,"args":{}},{"pid":54485,"tid":54485,"ts":341364471182,"tts":141918,"ph":"E","cat":"devtools.timeline,v8","name":"MinorGC","dur":0,"tdur":0,"args":{"usedHeapSizeAfter":173472}},{"pid":54485,"tid":54485,"ts":341364472901,"tts":143638,"ph":"B","cat":"devtools.timeline,v8","name":"MinorGC","dur":0,"tdur":0,"args":{"usedHeapSizeBefore":1221944,"type":"allocation failure"}},{"pid":54485,"tid":54485,"ts":341364472905,"tts":143641,"ph":"X","cat":"v8","name":"V8.GCScavenger","dur":26,"tdur":26,"args":{}},{"pid":54485,"tid":54485,"ts":341364472940,"tts":143675,"ph":"E","cat":"devtools.timeline,v8","name":"MinorGC","dur":0,"tdur":0,"args":{"usedHeapSizeAfter":173472}},{"pid":54485,"tid":54485,"ts":341364474583,"tts":145319,"ph":"B","cat":"devtools.timeline,v8","name":"MinorGC","dur":0,"tdur":0,"args":{"usedHeapSizeBefore":1221944,"type":"allocation failure"}},{"pid":54485,"tid":54485,"ts":341364474585,"tts":145321,"ph":"X","cat":"v8","name":"V8.GCScavenger","dur":17,"tdur":16,"args":{}},{"pid":54485,"tid":54485,"ts":341364474608,"tts":145343,"ph":"E","cat":"devtools.timeline,v8","name":"MinorGC","dur":0,"tdur":0,"args":{"usedHeapSizeAfter":173472}}]}
```
Note: The result of your demo may not be the same as the reference result, as the ID allocation mode is subject to the user environment.
