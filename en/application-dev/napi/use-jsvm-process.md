# JSVM-API Development Process

To implement cross-language interaction using JSVM-API, you need to register and load modules based on the JSVM-API mechanism first.

- ArkTS/JS: Import the .so library and call C++ APIs.  

- Native: Implement module registration via a .cpp file. You need to declare the name of the library to register and define the mappings between the native and JS/ArkTS APIs in the callback registered.

The following demonstrates how to implement cross-language interaction by implementing **RunJsVm()** in ArkTS/JS code and **RunJsVm()** in native code.

## Creating a Native C++ Project

For details, see [Creating an NDK Project](create-with-ndk.md).

## Implementing Native APIs

- Set module registration information.

  For details, see [Setting Module Registration Information](use-napi-process.md#implementing-native-apis).

- Initialize the module.

  Implement the mappings between the ArkTS and C++ APIs.

  ```cpp
  // entry/src/main/cpp/hello.cpp
  EXTERN_C_START
  // Initialize the module.
  static napi_value Init(napi_env env, napi_value exports)
  {
      // Implement the mappings between the ArkTS runJsVm and C++ RunJsVm.
      napi_property_descriptor desc[] = {
          {"runTest", nullptr, RunTest, nullptr, nullptr, nullptr, napi_default, nullptr},
      };
      // Register the native RunJsVm function with the JS exports object, making the native function available to JS.
      napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
      return exports;
  }
  EXTERN_C_END
  ```     

- In the **index.d.ts** file, declare the JS methods.

  ```ts
  // entry/src/main/cpp/types/libentry/index.d.ts
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

- Implement the native runTest function. The code is as follows:

  ```cpp
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

  // Call theCall and check whether the return value is JSVM_OK.
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

  // Simplified version of JSVM_CALL_BASE, which returns nullptr.
  #define JSVM_CALL(theCall) JSVM_CALL_BASE(env, theCall, nullptr)

  // Define OH_JSVM_StrictEquals.
  static JSVM_Value IsStrictEquals(JSVM_Env env, JSVM_CallbackInfo info) {
      // Obtain the two parameters passed from JS.
      size_t argc = 2;
      JSVM_Value args[2] = {nullptr};
      JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
      // Call OH_JSVM_StrictEquals to check whether two given JS values are strictly equal.
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
  // Set a property descriptor named isStrictEquals and associate it with a callback. This allows the isStrictEquals callback to be called from JS.
  static JSVM_PropertyDescriptor descriptor[] = {
      {"isStrictEquals", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
  };
  // Call the C++ code from JS.
  const char *srcCallNative = R"JS(    let data = '123';
      let value = 123;
      isStrictEquals(data,value);)JS";

  static int32_t TestJSVM() {
      JSVM_InitOptions initOptions = {0};
      JSVM_VM vm;
      JSVM_Env env = nullptr;
      JSVM_VMScope vmScope;
      JSVM_EnvScope envScope;
      JSVM_HandleScope handleScope;
      JSVM_Value result;
      // Initialize the JSVM instance.
      if (g_aa == 0) {
          g_aa++;
         CHECK(OH_JSVM_Init(&initOptions));
      }
      // Create a JSVM environment.
      CHECK(OH_JSVM_CreateVM(nullptr, &vm));
      CHECK(OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env));
      CHECK(OH_JSVM_OpenVMScope(vm, &vmScope));
      CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
      CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));

      // Call the test function through the script.
      JSVM_Script script;
      JSVM_Value jsSrc;
      CHECK_RET(OH_JSVM_CreateStringUtf8(env, srcCallNative, JSVM_AUTO_LENGTH, &jsSrc));
      CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
      CHECK_RET(OH_JSVM_RunScript(env, script, &result));

      // Destroy the JSVM environment.
      CHECK_RET(OH_JSVM_CloseHandleScope(env, handleScope));
      CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
      CHECK(OH_JSVM_CloseVMScope(vm, vmScope));
      CHECK(OH_JSVM_DestroyEnv(env));
      CHECK(OH_JSVM_DestroyVM(vm));
      return 0;
  }

  static napi_value RunTest(napi_env env, napi_callback_info info)
  {
      TestJSVM();
      return nullptr;
  }

  // Module registration information, which enables calling from the ArkTS side.
  EXTERN_C_START
  static napi_value Init(napi_env env, napi_value exports) {
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

```ts
import hilog from '@ohos.hilog'
// Import the native APIs.
import napitest from 'libentry.so'

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
            // runtest
            napitest.runTest();
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

**Expected output**
```ts
JSVM OH_JSVM_StrictEquals: success: 1
```
