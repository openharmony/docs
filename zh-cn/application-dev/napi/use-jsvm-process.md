# 使用JSVM-API实现JS与C/C++语言交互开发流程

使用JSVM-API实现跨语言交互，首先需要按照JSVM-API的机制实现模块的注册和加载等相关动作。

- ArkTS/JS侧：实现C++方法的调用。代码比较简单，import一个对应的so库后，即可调用C++方法。

- Native侧：.cpp文件，实现模块的注册。需要提供注册lib库的名称，并在注册回调方法中定义接口的映射关系，即Native方法及对应的JS/ArkTS接口名称等。

此处以在ArkTS/JS侧实现RunJsVm()接口、在Native侧实现RunJsVm()接口，从而实现跨语言交互为例，呈现使用JSVM-API进行跨语言交互的流程。

## 创建Native C++工程

具体见[创建NDK工程](create-with-ndk.md)

## Native侧方法的实现

- 设置模块注册信息

  具体见[设置模块注册信息](use-napi-process.md#native侧方法的实现)

- 模块初始化

  实现ArkTS接口与C++接口的绑定和映射。

  ```cpp
  // entry/src/main/cpp/hello.cpp
  EXTERN_C_START
  // 模块初始化
  static napi_value Init(napi_env env, napi_value exports)
  {
      // ArkTS接口与C++接口的绑定和映射
      napi_property_descriptor desc[] = {
          {"runJsVm", nullptr, RunJsVm, nullptr, nullptr, nullptr, napi_default, nullptr},
      };
      // 在exports对象上挂载RunJsVm的Native方法
      napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
      return exports;
  }
  EXTERN_C_END
  ```

- 在index.d.ts文件中，提供JS侧的接口方法。

  ```ts
  // entry/src/main/cpp/types/libentry/index.d.ts
  export const runJsVm: (jsCode: string) => void;
  ```

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

- 实现Native侧的RunJsVm接口。具体代码如下：

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
  
  // Assert方法注册回调
  static JSVM_CallbackStruct param[] = {
      {.data = nullptr, .callback = Assert},
  };
  static JSVM_CallbackStruct *method = param;
  // Assert方法别名，TS侧调用
  static JSVM_PropertyDescriptor descriptor[] = {
      {"assert", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
  };

  // 获取JavaScript代码字符串
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
  
  // javascript代码执行失败的处理
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
  // RunJsVm函数创建JavaScript VM，创建JS执行的上下文环境来执行JS代码获取JSVM_Value。
  static napi_value RunJsVm(napi_env nEnv, napi_callback_info nInfo) {
      std::string jsCodeStr = getCodeString(nEnv, nInfo);
      JSVM_InitOptions initOptions;
      memset(&initOptions, 0, sizeof(initOptions));
      // InitOptions外部引用赋值
      initOptions.externalReferences = nullptr;
      if (g_aa == 0) {
          g_aa++;
          // 初始化JavaScript引擎实例
          OH_JSVM_Init(&initOptions);
      }
      JSVM_VM vm;
      JSVM_CreateVMOptions options;
      memset(&options, 0, sizeof(options));
      // 创建JavaScript引擎实例
      OH_JSVM_CreateVM(&options, &vm);
      JSVM_VMScope vmScope;
      // 打开一个新的VM scope，引擎实例只能在scope范围内使用，可以保证引擎实例不被销毁
      OH_JSVM_OpenVMScope(vm, &vmScope);
      JSVM_Env env;
      // 创建一个新的JS执行上下文环境，并注册指定的Native函数
      JSVM_Status res = OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);
      if (res != JSVM_OK) {
          OH_LOG_INFO(LOG_APP, "JSVM API OH_JSVM_CreateEnv failed res is %{public}d", static_cast<int>(res));
      }
      JSVM_EnvScope envScope;
      // 打开一个新的Env scope，Env只能在scope范围内使用
      OH_JSVM_OpenEnvScope(env, &envScope);
      JSVM_HandleScope handleScope;
      // 打开一个Handle scope
      OH_JSVM_OpenHandleScope(env, &handleScope);
      std::string sourceCodeStr = jsCodeStr;
      napi_value nResult = nullptr;
      JSVM_Value jsVmResult;
      OH_LOG_INFO(LOG_APP, "JSVM API RunJsVm %{public}s", sourceCodeStr.c_str());
      // 根据传入的JavaScript代码字符串判断是否调用获取自定义结构数据的方法
      if (strcmp(sourceCodeStr.c_str(), "defineClass") == 0) {
          // DefineClass预留
           OH_LOG_INFO(LOG_APP, "JSVM API DefineClass called");
      } else {
          JSVM_Value sourceCodeValue = nullptr;
          OH_JSVM_CreateStringUtf8(env, sourceCodeStr.c_str(), sourceCodeStr.size(), &sourceCodeValue);
          JSVM_Script script;
          // 编译JavaScript代码字符串并返回编译后的脚本
          OH_JSVM_CompileScript(env, sourceCodeValue, nullptr, 0, true, nullptr, &script);
          // 执行JavaScript代码字符串
          res = OH_JSVM_RunScript(env, script, &jsVmResult);
          if (res != JSVM_OK) {
              RunScriptFail(nEnv, env, res);
              napi_get_boolean(nEnv, false, &nResult);
          } else {
              napi_get_boolean(nEnv, true, &nResult);
          }
      }
      // 关闭Handle scope
      OH_JSVM_CloseHandleScope(env, handleScope);
      // 关闭Env scope
      OH_JSVM_CloseEnvScope(env, envScope);
      // 关闭VM scope
      OH_JSVM_CloseVMScope(vm, vmScope);
      // 销毁一个JS执行上下文环境
      OH_JSVM_DestroyEnv(env);
      // 销毁JavaScript引擎实例
      OH_JSVM_DestroyVM(vm);
      return nResult;
  }
  ```
  
## ArkTS侧调用C/C++方法实现

```ts
import hilog from '@ohos.hilog'
// 通过import的方式，引入Native能力。
import napitest from 'libentry.so'
// test assert
try {
  let data = false;
  let script: string = `assert(${data});`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM Assert:%{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM Assert error: %{public}s', error);
}
```
