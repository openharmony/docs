# Creating and Calling JS Functions Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Introduction

Function calling allows you to call JavaScript functions from the JSVM module and transfer parameters, or directly create a JavaScript function in the JSVM module.

## Basic Concepts

Functions are an important programming concept. They are used to execute specific tasks, improve code readability and reusability, simplify complex operations, and modularize and structure code for easy understanding, maintenance, and expansion.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_GetCbInfo          | Obtains detailed information about the call, such as the parameters and **this** pointer, from the given callback information.|
| OH_JSVM_CallFunction       | Calls a JS function from a C/C++ addon.|
| OH_JSVM_IsFunction         | Checks whether an object is a function object.|
| OH_JSVM_CreateFunction     | Creates a JS function to call a C/C++ function in JS environment. The function can be called only after it is set in a JS object.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in creating and calling functions.

### OH_JSVM function Test

Full code for the CPP test. The entry is **TEST_FUNC**.
``` cpp
#include "hilog/log.h"
#include "ark_runtime/jsvm.h"

#define LOG_DOMAIN 0x3200
#define LOG_TAG "APP"

#define CHECK_RET(cond) \
  if ((cond)) { \
    const JSVM_ExtendedErrorInfo* info; \
    OH_JSVM_GetLastErrorInfo(env, &info); \
    OH_LOG_ERROR(LOG_APP, "jsvm fail file: %{public}s line: %{public}d ret = %{public}d message = %{public}s", __FILE__, __LINE__, cond, info != nullptr ? info->errorMessage : ""); \
    return -1;   \
  }

#define CHECK(cond) \
  if (!(cond)) { \
     OH_LOG_ERROR(LOG_APP, "jsvm fail file: %{public}s line: %{public}d ret = %{public}d", __FILE__, __LINE__, cond); \
     return -1;   \
  }

JSVM_Value NativeCreateFunctionTest(JSVM_Env env, JSVM_CallbackInfo info) {
    void *data = nullptr;
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    JSVM_Value thisArg;
    // Obtain the callback parameters.
    JSVM_Status ret = OH_JSVM_GetCbInfo(env, info, &argc, &argv[0], &thisArg, &data);
    if (ret != JSVM_OK) {
      const JSVM_ExtendedErrorInfo* info;
      OH_JSVM_GetLastErrorInfo(env, &info);
      OH_LOG_ERROR(LOG_APP, "jsvm fail file: %{public}s line: %{public}d ret = %{public}d message = %{public}s", __FILE__, __LINE__, ret, info != nullptr ? info->errorMessage : "");
      return nullptr;
    }
    char message[256];
    OH_JSVM_GetValueStringLatin1(env, argv[0], message, 256, nullptr);
    if (data == nullptr) {
        OH_LOG_ERROR(LOG_APP, "jsvm: %{public}s; callback data null", message);
    } else {
        OH_LOG_INFO(LOG_APP, "jsvm: %{public}s; %{public}s", message, (char*)data);
    }
    return nullptr;
}

static int32_t TEST_FUNC() {
    JSVM_InitOptions initOptions{};
    JSVM_VM vm;
    JSVM_Env env = nullptr;
    JSVM_VMScope vmScope;
    JSVM_EnvScope envScope;
    JSVM_HandleScope handleScope;
    JSVM_Value result;
    static bool isVMInit = false;
    if (!isVMInit) {
        isVMInit = true;
        // A single process needs to be initialized only once.
        OH_JSVM_Init(&initOptions);
    }
    CHECK_RET(OH_JSVM_CreateVM(nullptr, &vm));
    CHECK_RET(OH_JSVM_CreateEnv(vm, 0, nullptr, &env));
    CHECK_RET(OH_JSVM_OpenVMScope(vm, &vmScope));
    CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));

    // Create a function and check it.
    char hello[] = "Hello World!";
    JSVM_CallbackStruct cb = {NativeCreateFunctionTest, (void*)hello};
    JSVM_Value func;
    CHECK_RET(OH_JSVM_CreateFunction(env, "", JSVM_AUTO_LENGTH, &cb, &func));
    bool isFunction = false;
    CHECK_RET(OH_JSVM_IsFunction(env, func, &isFunction));
    CHECK(isFunction);

    // Set the function to a global object.
    JSVM_Value global;
    CHECK_RET(OH_JSVM_GetGlobal(env, &global));
    JSVM_Value key;
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, "NativeFunc", JSVM_AUTO_LENGTH, &key));
    CHECK_RET(OH_JSVM_SetProperty(env, global, key, func));

    // Call the function through OH_JSVM_CallFunction.
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_CreateStringUtf8(env, "jsvm api call function", JSVM_AUTO_LENGTH, &argv[0]);
    CHECK_RET(OH_JSVM_CallFunction(env, global, func, 1, argv, &result));

    // Call the function through the script.
    JSVM_Script script;
    JSVM_Value jsSrc;
    const char* srcCallNative = R"JS(NativeFunc('js source call function');)JS";
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, srcCallNative, JSVM_AUTO_LENGTH, &jsSrc));
    CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));

    CHECK_RET(OH_JSVM_CloseHandleScope(env, handleScope));
    CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
    CHECK_RET(OH_JSVM_CloseVMScope(vm, vmScope));
    CHECK_RET(OH_JSVM_DestroyEnv(env));
    CHECK_RET(OH_JSVM_DestroyVM(vm));
    return 0;
}
```
<!-- @[jsvm_function_call](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/UsageInstructionsOne/functioncall/src/main/cpp/hello.cpp) -->

**Expected output**
```
jsvm: jsvm api call function; Hello World!
jsvm: js source call function; Hello World!
```
