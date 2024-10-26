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

  Create the mappings between the ArkTS and C++ APIs.

  ```cpp
  // entry/src/main/cpp/hello.cpp
  EXTERN_C_START
  // Initialize the module.
  static napi_value Init(napi_env env, napi_value exports)
  {
      // Implement the mappings between the ArkTS runJsVm and C++ RunJsVm.
      napi_property_descriptor desc[] = {
          {"runJsVm", nullptr, RunJsVm, nullptr, nullptr, nullptr, napi_default, nullptr},
      };
      // Register the native RunJsVm function with the JS exports object, making the native function available to JS.
      napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
      return exports;
  }
  EXTERN_C_END
  ```

- In the **index.d.ts** file, declare the JS API.

  ```ts
  // entry/src/main/cpp/types/libentry/index.d.ts
  export const runJsVm: (jsCode: string) => void;
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

- Implement the native RunJsVm function. The code is as follows:

  ```cpp
  // entry/src/main/cpp/hello.cpp
  #include "napi/native_api.h"
  #include "ark_runtime/jsvm.h"
  #include <sys/stat.h>
  #include <thread>
  #include <unistd.h>
  #include <bits/alltypes.h>
  #include <hilog/log.h>
  static int g_aa = 0;
  static JSVM_Value Assert(JSVM_Env env, JSVM_CallbackInfo info)
  {
    size_t argc = 2;
    JSVM_Value args[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool isStrictEquals;
    if (argc > 1) {
        OH_JSVM_StrictEquals(env, args[0], args[1], &isStrictEquals);
    } else {
        JSVM_Value valTrue;
        OH_JSVM_GetBoolean(env, true, &valTrue);
        OH_JSVM_StrictEquals(env, args[0], valTrue, &isStrictEquals);
    }
    if (isStrictEquals) {
        OH_LOG_INFO(LOG_APP, "JSVM API TEST RESULT: PASS");
    } else {
        OH_LOG_ERROR(LOG_APP, "JSVM API TEST RESULT: FAILED");
    }
    JSVM_Value result;
    OH_JSVM_GetBoolean(env, isStrictEquals, &result);
    return result;
  }
  
  // Allow the JS environment to call the native Assert function through the asset property.
  static JSVM_CallbackStruct param[] = {
      {.data = nullptr, .callback = Assert},
  };
  static JSVM_CallbackStruct *method = param;
  // Alias of the Assert function to be called by the TS.
  static JSVM_PropertyDescriptor descriptor[] = {
      {"assert", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
  };

  // Obtain the JS code string.
  static std::string getCodeString(napi_env nEnv, napi_callback_info nInfo) {
      size_t argc = 1;
      napi_value argv[1] = {nullptr};
      napi_get_cb_info(nEnv, nInfo, &argc, argv, nullptr, nullptr);
      std::string jsCodeStr;
      size_t result = 0;
      napi_get_value_string_utf8(nEnv, argv[0], nullptr, NAPI_AUTO_LENGTH, &result);
      const size_t bufSize = result + 1;
      char *buf = new char[bufSize];
      napi_status status = napi_get_value_string_utf8(nEnv, argv[0], buf, bufSize, &result);
      if (status == napi_ok) {
          jsCodeStr = buf;
      }
      free(buf);
      return jsCodeStr;
  }
  
  // Process logic when the JS code fails to be executed.
  void RunScriptFail(napi_env &nEnv, JSVM_Env &env, JSVM_Status &res) {
      JSVM_Value exceptionValue;
      JSVM_Status status = OH_JSVM_GetAndClearLastException(env, &exceptionValue);
      if (status == JSVM_OK) {
          JSVM_Value message;
          OH_JSVM_GetNamedProperty(env, exceptionValue, "message", &message);
          size_t length;
          OH_JSVM_GetValueStringUtf8(env, message, nullptr, 0, &length);
          char *buffer = new char[length + 1];
          OH_JSVM_GetValueStringUtf8(env, message, buffer, length + 1, nullptr);
          napi_throw_error(nEnv, std::to_string(static_cast<int>(status)).c_str(), buffer);
          delete[] buffer;
      } else {
          napi_throw_error(nEnv, std::to_string(static_cast<int>(status)).c_str(), nullptr);
          OH_LOG_INFO(LOG_APP, "JSVM RunJsVm failed Error code:  %{public}d", static_cast<int>(res));
      }
  }
  // Create a JSVM to run JS code to obtain JSVM_Value.
  static napi_value RunJsVm(napi_env nEnv, napi_callback_info nInfo) {
      std::string jsCodeStr = getCodeString(nEnv, nInfo);
      JSVM_InitOptions initOptions;
      memset(&initOptions, 0, sizeof(initOptions));
      // Set the initialization options for the JSVM.
      initOptions.externalReferences = nullptr;
      if (g_aa == 0) {
          g_aa++;
          // Initialize the JSVM instance.
          OH_JSVM_Init(&initOptions);
      }
      JSVM_VM vm;
      JSVM_CreateVMOptions options;
      memset(&options, 0, sizeof(options));
      // Create a JSVM instance.
      OH_JSVM_CreateVM(&options, &vm);
      JSVM_VMScope vmScope;
      // Open a VM scope. The VM instance can be used only within the scope and will not be garbage-collected until the scope is closed.
      OH_JSVM_OpenVMScope(vm, &vmScope);
      JSVM_Env env;
      // Create a JS context and registers the specified native function.
      JSVM_Status res = OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);
      if (res != JSVM_OK) {
          OH_LOG_INFO(LOG_APP, "JSVM API OH_JSVM_CreateEnv failed res is %{public}d", static_cast<int>(res));
      }
      JSVM_EnvScope envScope;
      // Open a JS context scope. The context can be used only within the scope.
      OH_JSVM_OpenEnvScope(env, &envScope);
      JSVM_HandleScope handleScope;
      // Open a handle scope.
      OH_JSVM_OpenHandleScope(env, &handleScope);
      std::string sourceCodeStr = jsCodeStr;
      napi_value nResult = nullptr;
      JSVM_Value jsVmResult;
      OH_LOG_INFO(LOG_APP, "JSVM API RunJsVm %{public}s", sourceCodeStr.c_str());
      // Determine whether to call the JSVM API based on the JS code string passed in.
      if (strcmp(sourceCodeStr.c_str(), "defineClass") == 0) {
          // DefineClass is reserved.
           OH_LOG_INFO(LOG_APP, "JSVM API DefineClass called");
      } else {
          JSVM_Value sourceCodeValue = nullptr;
          OH_JSVM_CreateStringUtf8(env, sourceCodeStr.c_str(), sourceCodeStr.size(), &sourceCodeValue);
          JSVM_Script script;
          // Compile the JS code string and return the compiled script.
          OH_JSVM_CompileScript(env, sourceCodeValue, nullptr, 0, true, nullptr, &script);
          // Execute the JS script.
          res = OH_JSVM_RunScript(env, script, &jsVmResult);
          if (res != JSVM_OK) {
              RunScriptFail(nEnv, env, res);
              napi_get_boolean(nEnv, false, &nResult);
          } else {
              napi_get_boolean(nEnv, true, &nResult);
          }
      }
      // Close the handle scope.
      OH_JSVM_CloseHandleScope(env, handleScope);
      // Close the JS context scope.
      OH_JSVM_CloseEnvScope(env, envScope);
      // Close the VM scope.
      OH_JSVM_CloseVMScope(vm, vmScope);
      // Destroys the JS context.
      OH_JSVM_DestroyEnv(env);
      // Destroy the JSVM instance.
      OH_JSVM_DestroyVM(vm);
      return nResult;
  }
  ```
  
## Calling C/C++ APIs from ArkTS

```ts
import hilog from '@ohos.hilog'
// Import the native APIs.
import napitest from 'libentry.so'
// Test assert.
try {
  let data = false;
  let script: string = `assert(${data});`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM Assert:%{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM Assert error: %{public}s', error);
}
```
