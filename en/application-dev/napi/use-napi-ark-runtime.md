# Creating an ArkTS Runtime Environment Using Node-API
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## When to Use

After creating a thread using **pthread_create**, you can use **napi_create_ark_runtime** to create an ArkTS runtime environment and load the ArkTS module in the runtime environment. To destroy an ArkTS runtime environment that is not required, use **napi_destroy_ark_runtime**.

## Constraints

A maximum of 64 runtime environments can be created for a process.

## Example

1. Declare the APIs, configure compile settings, and register the module.

   **Declare the APIs.**

   ```ts
   // index.d.ts
   export const createArkRuntime: () => object;
   ```
   <!-- @[napi_ark_runtime_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/types/libentry/Index.d.ts) -->

   **Configure compile settings.**

   ```
   // CMakeLists.txt
   # the minimum version of CMake.
   cmake_minimum_required(VERSION 3.4.1)
   project(MyApplication)

   set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

   include_directories(${NATIVERENDER_ROOT_PATH}
                       ${NATIVERENDER_ROOT_PATH}/include)
   add_library(entry SHARED create_ark_runtime.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
   ```

   Configure the **build-profile.json5** file of the current module as follows:
   ```json
   {
       "buildOption" : {
           "arkOptions" : {
               "runtimeOnly" : {
                   "sources": [
                       "./src/main/ets/pages/ObjectUtils.ets"
                   ]
               }
           }
       }
   }
   ```
   <!-- @[napi_ark_runtime_build](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/build-profile.json5) -->

   **Register modules.**

   ```cpp
   // create_ark_runtime.cpp
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "createArkRuntime", nullptr, CreateArkRuntime, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END

   static napi_module nativeModule = {
       .nm_version = 1,
       .nm_flags = 0,
       .nm_filename = nullptr,
       .nm_register_func = Init,
       .nm_modname = "entry",
       .nm_priv = nullptr,
       .reserved = { 0 },
   };

   extern "C" __attribute__((constructor)) void RegisterQueueWorkModule()
   {
       napi_module_register(&nativeModule);
   }
   ```
   <!-- @[napi_ark_runtime_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/napi_init.cpp) -->

2. Create a thread and an ArkTS runtime environment, and load the module. For details about how to load a custom module, see [Loading a Module Using Node-API](use-napi-load-module-with-info.md).

   ```cpp
   // create_ark_runtime.cpp
   #include <pthread.h>
   #include "napi/native_api.h"

   static void *CreateArkRuntimeFunc(void *arg)
   {
       // 1. Create the ArkTS runtime environment.
       napi_env env;
       napi_status ret = napi_create_ark_runtime(&env);
       if (ret != napi_ok) {
           return nullptr;
       }

       // 2. Load custom modules.
       napi_value objUtils;
       ret = napi_load_module_with_info(env, "entry/src/main/ets/pages/ObjectUtils", "com.example.myapplication/entry", &objUtils);
       if (ret != napi_ok) {
           return nullptr;
       }

       // 3. Use the logger in ArkTS.
       napi_value logger;
       ret = napi_get_named_property(env, objUtils, "Logger", &logger);
       if (ret != napi_ok) {
           return nullptr;
       }
       ret = napi_call_function(env, objUtils, logger, 0, nullptr, nullptr);

       // 4. Destroy the ArkTS runtime environment.
       ret = napi_destroy_ark_runtime(&env);
       return nullptr;
   }

   static napi_value CreateArkRuntime(napi_env env, napi_callback_info info)
   {
       pthread_t tid;
       pthread_create(&tid, nullptr, CreateArkRuntimeFunc, nullptr);
       pthread_join(tid, nullptr);
       return nullptr;
   }
   ```
   <!-- @[napi_ark_runtime_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/napi_init.cpp) -->

3. Write the ArkTS code.

   ```ts
   // ObjectUtils.ets
   export function Logger() {
       console.info("print log");
   }
   ```
   <!-- @[napi_ark_runtime_utils](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/ets/pages/ObjectUtils.ets) -->
   ```ts
   // Call ArkTS APIs.
   import testNapi from 'libentry.so';

   testNapi.createArkRuntime();
   ```
   <!-- @[napi_ark_runtime_ets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/ets/pages/Index.ets) -->
