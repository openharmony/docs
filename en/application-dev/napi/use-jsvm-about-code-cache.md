# Accelerating Compilation Using a Code Cache

## Introduction to Code Cache

JSVM-API provides APIs for creating a code cache and using the code cache to store and manage compiled code to accelerate compilation. The code cache stores the code that has been compiled into native code by the compiler. This helps speed up the execution by avoiding repeated compilation of the same code. The procedure for creating and using a code cache is as follows:

- Use the **compile** APIs to obtain **JSVM_Script**.
- Call **OH_JSVM_CreateCodeCache** with the passed-in **JSVM_Script** to create a code cache.
- Save the created code cache. During the next compilation, pass the code cache as a parameter to the **compile** APIs.

The compilation using the code cache greatly reduces the compilation time because the serialized script in the code cache only needs to be deserialized, eliminating the need for parsing and compiling the code. In this way, the compilation process is simplified as a process for reading data.

## Example

The following pseudocode demonstrates a typical use case. If the value of **cacheRejected** is not **true** in the second compilation, the code cache is successfully used.

For details about how to use the JSVM-API, see [JSVM-API Data Types and APIs](./jsvm-data-types-interfaces.md). The following example only demonstrates the call procedure.
For details about the cross-language interaction, see [JSVM-API Development Process](./use-jsvm-process.md).

```c++
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>

void UseCodeCache(JSVM_Env env, JSVM_CallbackInfo info) {
    // Set compilation parameters.
    JSVM_Value jsSrc;
    JSVM_Script script;
    size_t length = 0;
    const uint8_t* dataPtr = nullptr;
    bool cacheRejected = true;
    static std::string src = R"JS(
        a = 65536;
        b = 32768;
        c = a + b;
    )JS";

    // Create a code cache.
    {
        JSVM_HandleScope handleScope;
        OH_JSVM_OpenHandleScope(env, &handleScope);

        // Convert the source code string into a JS string.
        OH_JSVM_CreateStringUtf8(env, src.c_str(), src.size(), &jsSrc);

        // Compile the JS code.
        OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script);

        // Run the JS code.
        JSVM_Value result;
        OH_JSVM_RunScript(env, script, &result);
        int value = 0;
        OH_JSVM_GetValueInt32(env, result, &value);
        OH_LOG_INFO(LOG_APP, "first run result: %{public}d\n", value);

        if (dataPtr && lengthPtr && *dataPtr == nullptr) {
            // Save the script compiled from the JS source code to the cache to prevent repeated compilation and improve performance.
            OH_JSVM_CreateCodeCache(env, script, &dataPtr, &length);
        }

        OH_JSVM_CloseHandleScope(env, handleScope);
    }

    // Use the code cache.
    {
        JSVM_HandleScope handleScope;
        OH_JSVM_OpenHandleScope(env, &handleScope);

        // Convert the source code string into a JS string.
        OH_JSVM_CreateStringUtf8(env, src.c_str(), src.size(), &jsSrc);

        // Use the code cache to compile the JS code.
        OH_JSVM_CompileScript(env, jsSrc, dataPtr, length, true, &cacheRejected, &script);

        // Run the JS code.
        JSVM_Value result;
        OH_JSVM_RunScript(env, script, &result);
        int value = 0;
        OH_JSVM_GetValueInt32(env, result, &value);
        OH_LOG_INFO(LOG_APP, "second run result: %{public}d\n", value);

        OH_JSVM_CloseHandleScope(env, handleScope);
    }
    OH_LOG_INFO(LOG_APP, "cache rejected: %{public}d\n", cacheRejected);
}

// Register the WasmDemo callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = UseCodeCache}
};
static JSVM_CallbackStruct *method = param;
// Register the C++ WasmDemo callback as a JSVM globalThis.UseCodeCache property for the JS to call.
static JSVM_PropertyDescriptor descriptor[] = {
    {"UseCodeCache", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```

**Expected Result**
```
first run result: 98304
second run result: 98304
cache rejected: 0
```

## Precautions

In the preceding code, a code cache is used for compilation. In **OH_JSVM_CompileScript(env, jsSrc, dataPtr, length, true, &cacheRejected, &script)**, the **cacheRejected** parameter is passed in to obtain whether the code cache is rejected in the compilation process. This status includes several situations:

- Code cache verification failed
- Code cache verification successful
- The code cache is not verified because there is a compilation cache in the memory

**cacheRejected** will be set to **true** in the first case and to **false** in the latter two cases. Therefore, it is important to note that event if **cacheRejected** is **false**, it does not necessarily mean that the code cache is used.
