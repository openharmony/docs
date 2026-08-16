# JSVM-API Development Process

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=d475d826f8ab6e97b4b69944b8a9a6d84f792324 translatedAt=2026-08-12T06:37:44.093Z pushedAt=2026-08-12T11:03:40.860Z -->

To implement cross-language interaction using JSVM-API, you need to register and load modules based on the JSVM-API mechanism first.

- ArkTS/JS: Import the .so library and call C++ APIs.  

- Native: Implement module registration via a .cpp file. You need to declare the name of the library to register and define the mappings between the native and JS/ArkTS APIs in the callback registered.

This section demonstrates the cross-language interaction process with JSVM-API by using the `RunTest()` interface implemented on both the ArkTS/JS side and the native side as an example.

## Creating a Native C++ Project

For details, see [Creating an NDK Project](create-with-ndk.md).

## Implementing Native APIs

By referring to [Node-API Development Process](use-napi-process.md#implementing-native-apis), the following code provides a demo for implementing a native method by following "JSVM-API Development Process".

- In the **index.d.ts** file, declare the JS methods.

  <!-- @[export_native](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmProcess/entry/src/main/cpp/types/libentry/Index.d.ts) -->

  ``` TypeScript
  export const runTest: () => void;
  ```

- Associate **index.d.ts** with **.cpp** in the **oh-package.json5** file.

  ```json
  {
    "name": "libentry.so",
    "types": "./index.d.ts",
    "version": "",
    "description": "Please describe the basic information."
  }
  ```

- Set CMake packaging parameters in the **CMakeLists.txt** file.

  ```text
  # entry/src/main/cpp/CMakeLists.txt
  cmake_minimum_required(VERSION 3.4.1)
  project(JSVMDemo)
  
  set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
  # Set logging information.
  add_definitions( "-DLOG_DOMAIN=0xd0d0" )
  add_definitions( "-DLOG_TAG=\"testTag\"" )
  include_directories(${NATIVERENDER_ROOT_PATH}
                      ${NATIVERENDER_ROOT_PATH}/include)
  
  # Add a shared library named entry from the source file hello.cpp.
  add_library(entry SHARED hello.cpp)
  # Link the entry library with the specified shared libraries.
  target_link_libraries(entry PUBLIC libace_napi.z.so libjsvm.so libhilog_ndk.z.so)
  ```

- Create **entry/src/main/cpp/hello.cpp** and implement **runTest()** on the native side. The code is as follows:

  <!-- @[oh_jsvm_process](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmProcess/entry/src/main/cpp/hello.cpp) -->

``` C++
#include "napi/native_api.h"
#include "hilog/log.h"
#include "ark_runtime/jsvm.h"

#define LOG_DOMAIN 0x3200
#define LOG_TAG "APP"

static int g_aa = 0;

#define CHECK_RET(theCall)                                                                                             \
    do {                                                                                                               \
        JSVM_Status cond = theCall;                                                                                    \
        if ((cond) != JSVM_OK) {                                                                                       \
            const JSVM_ExtendedErrorInfo *info;                                                                        \
            OH_JSVM_GetLastErrorInfo(env, &info);                                                                      \
            OH_LOG_ERROR(LOG_APP, "jsvm fail file: %{public}s line: %{public}d ret = %{public}d message = %{public}s", \
                         __FILE__, __LINE__, cond, info != nullptr ? info->errorMessage : "");                         \
            return -1;                                                                                                 \
        }                                                                                                              \
    } while (0)

#define CHECK(theCall)                                                                                                 \
    do {                                                                                                               \
        JSVM_Status cond = theCall;                                                                                    \
        if ((cond) != JSVM_OK) {                                                                                       \
            OH_LOG_ERROR(LOG_APP, "jsvm fail file: %{public}s line: %{public}d ret = %{public}d", __FILE__, __LINE__,  \
                         cond);                                                                                        \
            return -1;                                                                                                 \
        }                                                                                                              \
    } while (0)

// Used to call theCall and check whether its return value is JSVM_OK.
// If not, call OH_JSVM_GetLastErrorInfo to handle the error and return retVal.
#define JSVM_CALL_BASE(env, theCall, retVal)                                                                           \
    do {                                                                                                               \
        JSVM_Status cond = theCall;                                                                                    \
        if (cond != JSVM_OK) {                                                                                         \
            const JSVM_ExtendedErrorInfo *info;                                                                        \
            OH_JSVM_GetLastErrorInfo(env, &info);                                                                      \
            OH_LOG_ERROR(LOG_APP, "jsvm fail file: %{public}s line: %{public}d ret = %{public}d message = %{public}s", \
                         __FILE__, __LINE__, cond, info != nullptr ? info->errorMessage : "");                         \
            return retVal;                                                                                             \
        }                                                                                                              \
    } while (0)

// Simplified version of JSVM_CALL_BASE that returns nullptr.
#define JSVM_CALL(theCall) JSVM_CALL_BASE(env, theCall, nullptr)

// Sample method for OH_JSVM_StrictEquals.
static JSVM_Value IsStrictEquals(JSVM_Env env, JSVM_CallbackInfo info)
{
    //     // Accept two input parameters.
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
    //     // Call OH_JSVM_StrictEquals to determine whether the two given JavaScript values are strictly equal.
    bool result = false;
    JSVM_Status status = OH_JSVM_StrictEquals(env, args[0], args[1], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_StrictEquals: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_StrictEquals: success: %{public}d", result);
    }
    JSVM_Value isStrictEqual;
    JSVM_CALL(OH_JSVM_GetBoolean(env, result, &isStrictEqual));
    return isStrictEqual;
}
// Register the IsStrictEquals callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsStrictEquals},
};
static JSVM_CallbackStruct *method = param;
// Alias of the IsStrictEquals method, for JS to call.
static JSVM_PropertyDescriptor descriptor[] = {
    {"isStrictEquals", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(    let data = '123';
    let value = 123;
    isStrictEquals(data, value);)JS";

static int32_t TestJSVM()
{
    JSVM_InitOptions initOptions = {0};
    JSVM_VM vm;
    JSVM_Env env = nullptr;
    JSVM_VMScope vmScope;
    JSVM_EnvScope envScope;
    JSVM_HandleScope handleScope;
    JSVM_Value result;
    //     // Initialize the JavaScript engine instance.
    if (g_aa == 0) {
        g_aa++;
        CHECK(OH_JSVM_Init(&initOptions));
    }
    //     // Create a JSVM environment.
    CHECK(OH_JSVM_CreateVM(nullptr, &vm));
    CHECK(OH_JSVM_OpenVMScope(vm, &vmScope));
    CHECK(OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env));
    CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));

    //     // Call the test function through the script.
    JSVM_Script script;
    JSVM_Value jsSrc;
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, SRC_CALL_NATIVE, JSVM_AUTO_LENGTH, &jsSrc));
    CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));

    //     // Destroy the JSVM environment.
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handleScope));
    CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_CloseVMScope(vm, vmScope));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}

static napi_value RunTest(napi_env env, napi_callback_info info)
{
    TestJSVM();
    return nullptr;
}

// Module registration information, for the ArkTS side to call.
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {{"runTest", nullptr, RunTest, nullptr, nullptr, nullptr, napi_default, nullptr}};
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void) { napi_module_register(&demoModule); }
```

## Calling C/C++ APIs in ArkTS

<!-- @[call_native_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmProcess/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import napitest from 'libentry.so';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            try {
              napitest.runTest();
              this.message = 'success';
            } catch (error) {
              console.error('An error occurred: ', error);
              this.message = 'fail';
            }
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

Expected result:

```ts
JSVM OH_JSVM_StrictEquals: success: 0
```