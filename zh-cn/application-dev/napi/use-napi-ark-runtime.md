# 使用Node-API接口创建ArkTS运行时环境
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello; @yuanyao14; @lzj0614-->
<!--SE: @shilei123-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

## 场景介绍

开发者通过pthread_create创建新线程后，可以通过`napi_create_ark_runtime`来创建一个新的ArkTS基础运行时环境，并通过该运行时环境加载ArkTS模块。当使用结束后，开发者需要通过`napi_destroy_ark_runtime`来销毁所创建的ArkTS基础运行时环境。

## 约束限制

一个进程最多只能创建64个运行时环境。

## 使用示例

1. 接口声明、编译配置以及模块注册。

   **接口声明**

   ```ts
   // index.d.ts
   export const createArkRuntime: () => object;
   ```
   <!-- @[napi_ark_runtime_dts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/cpp/types/libentry/Index.d.ts) -->

   **编译配置**

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

   在当前模块的build-profile.json5文件中进行以下配置：
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

   **模块注册**

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

2. 新建线程并创建ArkTS基础运行时环境，加载自定义模块请参考[napi_load_module_with_info](./use-napi-load-module-with-info.md)。

   ```cpp
   // create_ark_runtime.cpp
   #include <pthread.h>
   #include "napi/native_api.h"

   static void *CreateArkRuntimeFunc(void *arg)
   {
       // 1. 创建基础运行环境
       napi_env env;
       napi_status ret = napi_create_ark_runtime(&env);
       if (ret != napi_ok) {
           return nullptr;
       }

       // 2. 加载自定义模块
       napi_value objUtils;
       ret = napi_load_module_with_info(env, "entry/src/main/ets/pages/ObjectUtils", "com.example.myapplication/entry", &objUtils);
       if (ret != napi_ok) {
           return nullptr;
       }

       // 3. 使用ArkTS中的logger
       napi_value logger;
       ret = napi_get_named_property(env, objUtils, "Logger", &logger);
       if (ret != napi_ok) {
           return nullptr;
       }
       ret = napi_call_function(env, objUtils, logger, 0, nullptr, nullptr);

       // 4. 销毁ArkTS环境
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

3. 编写ArkTS侧示例代码。

   ```ts
   // ObjectUtils.ets
   export function Logger() {
       console.info("print log");
   }
   ```
   <!-- @[napi_ark_runtime_utils](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/ets/pages/ObjectUtils.ets) -->
   ```ts
   // ArkTS侧调用接口
   import testNapi from 'libentry.so';

   testNapi.createArkRuntime();
   ```
   <!-- @[napi_ark_runtime_ets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIClassicUseCases/NodeAPIApplicationScenario/entry/src/main/ets/pages/Index.ets) -->
