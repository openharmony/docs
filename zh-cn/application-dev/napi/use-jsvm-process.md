# 使用JSVM-API实现JS与C/C++语言交互开发流程
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

使用JSVM-API实现跨语言交互，首先需按其机制注册和加载模块。

- ArkTS/JS侧：实现C++方法的调用。代码比较简单，import一个对应的so库后，即可调用C++方法。

- Native侧：.cpp文件，实现模块的注册。需要提供注册lib库的名称，并在注册回调方法中定义接口的映射关系，即Native方法及对应的JS/ArkTS接口名称等。

此处以在ArkTS/JS侧和Native侧实现RunJsVm()接口实现跨语言交互为例，展示使用JSVM-API进行跨语言交互的流程。

## 创建Native C++工程

具体见[创建NDK工程](create-with-ndk.md)

## Native侧方法的实现

参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md#native侧方法的实现)，以下代码提供了“使用JSVM-API实现JS与C/C++语言交互开发流程”Native侧方法实现的一个demo。

- 在index.d.ts文件中，提供JS侧的接口方法。

  ```ts
  // entry/src/main/cpp/types/libentry/index.d.ts
  export const runTest: () => void;
  ```
  <!-- @[export_native](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmProcess/entry/src/main/cpp/types/libentry/Index.d.ts) -->

- 在oh-package.json5文件中将index.d.ts与cpp文件关联起来。

  ```json
  {
    "name": "libentry.so",
    "types": "./index.d.ts",
    "version": "",
    "description": "Please describe the basic information."
  }
  ```

- 在CMakeLists.txt文件中配置CMake打包参数。

  ```text
  # entry/src/main/cpp/CMakeLists.txt
  cmake_minimum_required(VERSION 3.4.1)
  project(JSVMDemo)
  
  set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
  # 日志打印配置
  add_definitions( "-DLOG_DOMAIN=0xd0d0" )
  add_definitions( "-DLOG_TAG=\"testTag\"" )
  include_directories(${NATIVERENDER_ROOT_PATH}
                      ${NATIVERENDER_ROOT_PATH}/include)
  
  # 添加名为entry的库
  add_library(entry SHARED hello.cpp)
  # 构建此可执行文件需要链接的库
  target_link_libraries(entry PUBLIC libace_napi.z.so libjsvm.so libhilog_ndk.z.so)
  ```

- 新建entry/src/main/cpp/hello.cpp，实现Native侧的runTest接口。具体代码如下：

  ```cpp
  // entry/src/main/cpp/hello.cpp
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
  
  // 用于调用theCall并检查其返回值是否为JSVM_OK。
  // 如果不是，则调用OH_JSVM_GetLastErrorInfo处理错误并返回retVal。
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
  
  // JSVM_CALL_BASE的简化版本，返回nullptr
  #define JSVM_CALL(theCall) JSVM_CALL_BASE(env, theCall, nullptr)
  
  // OH_JSVM_StrictEquals的样例方法
  static JSVM_Value IsStrictEquals(JSVM_Env env, JSVM_CallbackInfo info) {
      // 接受两个入参
      size_t argc = 2;
      JSVM_Value args[2] = {nullptr};
      JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
      // 调用OH_JSVM_StrictEquals接口判断给定的两个JavaScript value是否严格相等
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
  // IsStrictEquals注册回调
  static JSVM_CallbackStruct param[] = {
      {.data = nullptr, .callback = IsStrictEquals},
  };
  static JSVM_CallbackStruct *method = param;
  // IsStrictEquals方法别名，供JS调用
  static JSVM_PropertyDescriptor descriptor[] = {
      {"isStrictEquals", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
  };
  // 样例测试js
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
      // 初始化JavaScript引擎实例
      if (g_aa == 0) {
          g_aa++;
         CHECK(OH_JSVM_Init(&initOptions));
      }
      // 创建JSVM环境
      CHECK(OH_JSVM_CreateVM(nullptr, &vm));
      CHECK(OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env));
      CHECK(OH_JSVM_OpenVMScope(vm, &vmScope));
      CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
      CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));
  
      // 通过script调用测试函数
      JSVM_Script script;
      JSVM_Value jsSrc;
      CHECK_RET(OH_JSVM_CreateStringUtf8(env, srcCallNative, JSVM_AUTO_LENGTH, &jsSrc));
      CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
      CHECK_RET(OH_JSVM_RunScript(env, script, &result));
  
      // 销毁JSVM环境
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
  
  // 模块初始化
  EXTERN_C_START
  static napi_value Init(napi_env env, napi_value exports) {
      // 实现ArkTS接口与C++接口的绑定和映射  
      napi_property_descriptor desc[] = {
        {"runTest", nullptr, RunTest, nullptr, nullptr, nullptr, napi_default, nullptr}
      };
      // 在exports对象上挂载RunJsVm的Native方法
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
  <!-- @[oh_jsvm_process](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmProcess/entry/src/main/cpp/hello.cpp) -->
  
## ArkTS侧调用C/C++方法实现

```ts
import hilog from '@ohos.hilog';
// 通过import的方式，引入Native能力。
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
<!-- @[call_native_cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmProcess/entry/src/main/ets/pages/Index.ets) -->

预期输出结果
```ts
JSVM OH_JSVM_StrictEquals: success: 0
```