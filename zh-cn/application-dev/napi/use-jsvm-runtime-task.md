# 使用JSVM-API接口创建多个引擎执行JS代码并销毁

## 场景介绍

开发者通过createJsCore方法来创建一个新的JS基础运行时环境，并通过该方法获得一个CoreID，通过evaluateJS方法使用CoreID对应的运行环境来运行JS代码，在JS代码中创建promise并异步调取TS侧设定的callback函数，最后使用releaseJsCore方法来释放CoreID对应的运行环境。

## 使用示例

1.接口声明和编译配置

**接口声明**

  ```ts
  // index.d.ts
  export const createJsCore: (fun: Function) => number;
  export const releaseJsCore: (a: number) => void;
  export const evaluateJS: (a: number, str: string) => string;
  ```

**编译配置**

  ```
  // CMakeLists.txt
  # the minimum version of CMake.
  cmake_minimum_required(VERSION 3.4.1)
  project(MyApplication)

  set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

  if(DEFINED PACKAGE_FIND_FILE)
  include(${PACKAGE_FIND_FILE})
  endif()

  include_directories(${NATIVERENDER_ROOT_PATH}
                      ${NATIVERENDER_ROOT_PATH}/include)

  add_library(entry SHARED create_jsvm_runtime.cpp)
  target_link_libraries(entry PUBLIC libace_napi.z.so libjsvm.so libhilog_ndk.z.so)
  ```

2.新建多个JS运行时环境并运行JS代码

  ```cpp
  // create_jsvm_runtime.cpp
  #include "napi/native_api.h"
  #include "ark_runtime/jsvm.h"
  #include <bits/alltypes.h>
  #include <deque>
  #include <map>
  #include <unistd.h>
  #include <hilog/log.h>
  #include <cstring>
  #include <string>
  #include <vector>
  #include <sstream>

  #define LOG_TAG "TEST_TAG"
  // 用于获取并抛出最后一个错误信息。通过OH_JSVM_GetLastErrorInfo获取错误信息，
  // 如果没有挂起的异常且错误信息存在，则通过 OH_JSVM_ThrowError 抛出错误。
  #define GET_AND_THROW_LAST_ERROR(env)                                                                   \
      do {                                                                                                \
          const JSVM_ExtendedErrorInfo* errorInfo = nullptr;                                              \
          OH_JSVM_GetLastErrorInfo((env), &errorInfo);                                                    \
          bool isPending = false;                                                                         \
          OH_JSVM_IsExceptionPending((env), &isPending);                                                  \
              JSVM_Value error;                                                                           \
          if (isPending && JSVM_OK == OH_JSVM_GetAndClearLastException((env), &error)) {                  \
                                                                                                          \
              JSVM_Value stack;                                                                           \
              OH_JSVM_GetNamedProperty((env), error, "stack", &stack);                                    \
                                                                                                          \
              JSVM_Value message;                                                                         \
              OH_JSVM_GetNamedProperty((env), error, "message", &message);                                \
                                                                                                          \
              char stackstr[256];                                                                         \
              OH_JSVM_GetValueStringUtf8(env, stack, stackstr, 256, nullptr);                             \
              OH_LOG_INFO(LOG_APP, "JSVM error stack: %{public}s", stackstr);                             \
              char messagestr[256];                                                                       \
              OH_JSVM_GetValueStringUtf8(env, message, messagestr, 256, nullptr);                         \
              OH_LOG_INFO(LOG_APP, "JSVM error message: %{public}s", messagestr);                         \
          }                                                                                               \
          if (!isPending && errorInfo != nullptr) {                                                       \
              const char* errorMessage =                                                                  \
                  errorInfo->errorMessage != nullptr ? errorInfo->errorMessage : "empty error message";   \
              OH_JSVM_ThrowError((env), nullptr, errorMessage);                                           \
          }                                                                                               \
      } while (0)

  // 用于调用theCall并检查其返回值是否为JSVM_OK。
  // 如果不是，则调用GET_AND_THROW_LAST_ERROR处理错误并返回retVal。
  #define JSVM_CALL_BASE(env, theCall, retVal)                                                            \
      do {                                                                                                \
          if ((theCall) != JSVM_OK) {                                                                     \
              GET_AND_THROW_LAST_ERROR((env));                                                            \
              return retVal;                                                                              \
          }                                                                                               \
      } while (0)

  // JSVM_CALL_BASE的简化版本，返回nullptr 
  #define JSVM_CALL(env, theCall) JSVM_CALL_BASE(env, theCall, nullptr)

  using namespace std;
  // 定义map管理每个独立vm环境
  static map<int, JSVM_VM*> g_vmMap;
  static map<int, JSVM_Env*> g_envMap;
  static map<int, napi_env> g_napiEnvMap;
  static map<int, napi_ref> g_callBackMap;
  static map<int, JSVM_CallbackStruct*> g_callBackStructMap;
  static uint32_t ENVTAG_NUMBER = 0;
  static std::mutex envMapLock;
  static int aa = 0;

  class Task {
  public:
      virtual ~Task() = default;
      virtual void Run() = 0;
  };
  static map<int, deque<Task *>> g_taskQueueMap;

  // 自定义Consoleinfo方法
  static JSVM_Value Consoleinfo(JSVM_Env env, JSVM_CallbackInfo info) {
      size_t argc = 1;
      JSVM_Value args[1];
      char log[256] = "";
      size_t log_length;
      OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL);

      OH_JSVM_GetValueStringUtf8(env, args[0], log, 255, &log_length);
      log[255] = 0;
      OH_LOG_INFO(LOG_APP, "JSVM API TEST: %{public}s", log);
      return nullptr;
  }

  // 自定义创建Promise方法用以在JS代码中创建Promise
  static JSVM_Value CreatePromise(JSVM_Env env, JSVM_CallbackInfo info) {
      OH_LOG_INFO(LOG_APP, "JSVM API TEST: CreatePromise start");
      int envID = 0;
      // 通过当前env获取envID
      for (auto it = g_envMap.begin(); it != g_envMap.end(); ++it) {
          if (*it->second == env) {
              envID = it->first;
              break;
          }
      }
      if (envID == -1) {
          OH_LOG_INFO(LOG_APP, "JSVM API TEST: CreatePromise envID faild");
          return nullptr;
      }
      JSVM_Value promise;
      JSVM_Deferred deferred;
      OH_JSVM_CreatePromise(env, &deferred, &promise);
      // 设计ReadTask类用以将promise对象的deferred加入执行队列
      class ReadTask : public Task {
      public:
          ReadTask(JSVM_Env env, JSVM_Deferred deferred, int envNum) : env_(env), envID_(envNum), deferred_(deferred) {}
          void Run() override {
              //string str = "TEST RUN OH_JSVM_ResolveDeferred";
              int envID = 0;
              for (auto it = g_envMap.begin(); it != g_envMap.end(); ++it) {
                  if (*it->second == env_) {
                      envID = it->first;
                      break;
                  }
              }
              OH_LOG_INFO(LOG_APP, "JSVM API TEST: CreatePromise %{public}d", envID);
              JSVM_Value result;
              OH_JSVM_CreateInt32(env_, envID, &result);
              OH_JSVM_ResolveDeferred(env_, deferred_, result);
          }
      private:
          JSVM_Env env_;
          int envID_;
          JSVM_Deferred deferred_;
      };
      g_taskQueueMap[envID].push_back(new ReadTask(env, deferred, envID));
      OH_LOG_INFO(LOG_APP, "JSVM API TEST: CreatePromise end");
      return promise;
  }

  // 自定义Add方法
  static JSVM_Value Add(JSVM_Env env, JSVM_CallbackInfo info) {
      size_t argc = 2;
      JSVM_Value args[2];
      OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL);
      double num1, num2;
      OH_JSVM_GetValueDouble(env, args[0], &num1);
      OH_JSVM_GetValueDouble(env, args[1], &num2);
      JSVM_Value sum = nullptr;
      OH_JSVM_CreateDouble(env, num1 + num2, &sum);
      return sum;
  }

  // 自定义AssertEqual方法
  static JSVM_Value AssertEqual(JSVM_Env env, JSVM_CallbackInfo info) {
      size_t argc = 2;
      JSVM_Value args[2];
      JSVM_CALL(env, OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));

      bool isStrictEquals = false;
      OH_JSVM_StrictEquals(env, args[0], args[1], &isStrictEquals);

      if (isStrictEquals) {
          OH_LOG_INFO(LOG_APP, "JSVM API TEST RESULT: PASS");
      } else {
          OH_LOG_INFO(LOG_APP, "JSVM API TEST RESULT: FAILED");
      }
      return nullptr;
  }

  // 用以在native层中调用TS侧传入的Callback函数
  static JSVM_Value OnJSResultCallback(JSVM_Env env, JSVM_CallbackInfo info) {
      size_t argc = 3;
      JSVM_Value args[3];
      JSVM_CALL(env, OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));
      int callId = 0;
      OH_JSVM_GetValueInt32(env, args[0], &callId);
      napi_value callArgs[2] = {nullptr, nullptr};
      size_t size;
      size_t size1;

      OH_JSVM_GetValueStringUtf8(env, args[1], nullptr, 0, &size);
      char Str1[size + 1];
      OH_JSVM_GetValueStringUtf8(env, args[1], Str1, size + 1, &size);
      
      OH_JSVM_GetValueStringUtf8(env, args[2], nullptr, 0, &size1);
      char Str2[size1 + 1];
      OH_JSVM_GetValueStringUtf8(env, args[2], Str2, size1 + 1, &size1);
      
      napi_create_string_utf8(g_napiEnvMap[callId], Str1, size + 1, &callArgs[0]);
      napi_create_string_utf8(g_napiEnvMap[callId], Str2, size1 + 1, &callArgs[1]);
      napi_value callback = nullptr;
      // 通过callId获取在创建当前JSVM环境时传入的TS回调方法
      napi_get_reference_value(g_napiEnvMap[callId], g_callBackMap[callId], &callback);
      napi_value ret;
      // 执行TS回调方法
      napi_call_function(g_napiEnvMap[callId], nullptr, callback, 2, callArgs, &ret);
      char retStr[256];
      napi_get_value_string_utf8(g_napiEnvMap[callId], ret, retStr, 256, &size);
      
      JSVM_Value returnVal;
      OH_JSVM_CreateStringUtf8(env, retStr, JSVM_AUTO_LENGTH, &returnVal);
      return returnVal;
  }

  std::string napiValueToString(napi_env env, napi_value nValue) {
      size_t buffLen = 0;
      napi_get_value_string_utf8(env, nValue, nullptr, 0, &buffLen);
      char buffer[buffLen + 1];
      napi_get_value_string_utf8(env, nValue, buffer, buffLen + 1, &buffLen);

      return buffer;
  }

  static std::string fromOHStringValue(JSVM_Env &env, JSVM_Value &value) {
      size_t size;
      JSVM_Status status;
      status = OH_JSVM_GetValueStringUtf8(env, value, nullptr, 0, &size);
      char resultStr[size + 1];
      status = OH_JSVM_GetValueStringUtf8(env, value, resultStr, size + 1, &size);
      return resultStr;
  }

  static void CreateArkJSContext() {
      JSVM_Status status;
      JSVM_InitOptions init_options;
      memset(&init_options, 0, sizeof(init_options));
      if (aa == 0) {
          OH_JSVM_Init(&init_options);
          aa++;
      }

      // 虚拟机实例
      g_vmMap[ENVTAG_NUMBER] = new JSVM_VM;
      JSVM_CreateVMOptions options;
      memset(&options, 0, sizeof(options));
      status = OH_JSVM_CreateVM(&options, g_vmMap[ENVTAG_NUMBER]);
      JSVM_VMScope vmScope;
      OH_JSVM_OpenVMScope(*g_vmMap[ENVTAG_NUMBER], &vmScope);

      // 新环境
      g_envMap[ENVTAG_NUMBER] = new JSVM_Env;
      g_callBackStructMap[ENVTAG_NUMBER] = new JSVM_CallbackStruct[5];
      
      // 注册用户提供的本地函数的回调函数指针和数据，通过JSVM-API暴露给js
      for (int i = 0; i < 5; i++) {
          g_callBackStructMap[ENVTAG_NUMBER][i].data = nullptr;
      }
      g_callBackStructMap[ENVTAG_NUMBER][0].callback = Consoleinfo;
      g_callBackStructMap[ENVTAG_NUMBER][1].callback = Add;
      g_callBackStructMap[ENVTAG_NUMBER][2].callback = AssertEqual;
      g_callBackStructMap[ENVTAG_NUMBER][3].callback = OnJSResultCallback;
      g_callBackStructMap[ENVTAG_NUMBER][4].callback = CreatePromise;
      JSVM_PropertyDescriptor descriptors[] = {
          {"consoleinfo", NULL, &g_callBackStructMap[ENVTAG_NUMBER][0], NULL, NULL, NULL, JSVM_DEFAULT},
          {"add", NULL, &g_callBackStructMap[ENVTAG_NUMBER][1], NULL, NULL, NULL, JSVM_DEFAULT},
          {"assertEqual", NULL, &g_callBackStructMap[ENVTAG_NUMBER][2], NULL, NULL, NULL, JSVM_DEFAULT},
          {"onJSResultCallback", NULL, &g_callBackStructMap[ENVTAG_NUMBER][3], NULL, NULL, NULL, JSVM_DEFAULT},
          {"createPromise", NULL, &g_callBackStructMap[ENVTAG_NUMBER][4], NULL, NULL, NULL, JSVM_DEFAULT},
      };
      status = OH_JSVM_CreateEnv(*g_vmMap[ENVTAG_NUMBER], sizeof(descriptors) / sizeof(descriptors[0]), descriptors, g_envMap[ENVTAG_NUMBER]);
      OH_JSVM_CloseVMScope(*g_vmMap[ENVTAG_NUMBER], vmScope);
  }

  // 提供创建JSVM运行环境的对外接口并返回对应唯一ID
  static napi_value CreateJsCore(napi_env env1, napi_callback_info info) { 
      OH_LOG_ERROR(LOG_APP, "JSVM CreateJsCore START");
      size_t argc = 1;
      napi_value argv[1];
      napi_get_cb_info(env1, info, &argc, argv, nullptr, nullptr);
      if (argc < 1) {
          OH_LOG_ERROR(LOG_APP, "JSVM CreateJsCore the number of params must be one");
          return nullptr;
      }
      g_napiEnvMap[ENVTAG_NUMBER] = env1;
      g_taskQueueMap[ENVTAG_NUMBER] = deque<Task *>{};
      // 将TS侧传入的回调函数与env对应存储方便后续调用
      napi_ref callFun;
      napi_create_reference(env1, argv[0], 1, &callFun);
      g_callBackMap[ENVTAG_NUMBER] = callFun;
      napi_value coreID = 0;
      {
          std::lock_guard<std::mutex> lock_guard(envMapLock);
          CreateArkJSContext();
          napi_create_uint32(env1, ENVTAG_NUMBER, &coreID);
          ENVTAG_NUMBER++;
      }
      OH_LOG_ERROR(LOG_APP, "JSVM CreateJsCore END");
      return coreID;
  }

  // 对外提供释放JSVM环境接口，通过envId释放对应环境
  static napi_value ReleaseJsCore(napi_env env1, napi_callback_info info) {
      OH_LOG_ERROR(LOG_APP, "JSVM ReleaseJsCore START");
      size_t argc = 1;
      napi_value argv[1];
      napi_get_cb_info(env1, info, &argc, argv, nullptr, nullptr);
      if (argc < 1) {
          OH_LOG_ERROR(LOG_APP, "JSVM ReleaseJsCore the number of params must be one");
          return nullptr;
      }
      
      uint32_t coreEnvId;
      napi_status status = napi_get_value_uint32(env1, argv[0], &coreEnvId);
      if (status != napi_ok) {
          OH_LOG_ERROR(LOG_APP, "JSVM CreateJsCore napi_get_value_uint32 faild");
          return nullptr;
      }
      if (g_envMap.count(coreEnvId) == 0 ) {
          OH_LOG_ERROR(LOG_APP, "JSVM CreateJsCore not has env ");
          return nullptr;
      }
      if (g_envMap[coreEnvId] != nullptr) {
          std::lock_guard<std::mutex> lock_guard(envMapLock);
          OH_JSVM_DestroyEnv(*g_envMap[coreEnvId]);
          g_envMap[coreEnvId] = nullptr;
          g_envMap.erase(coreEnvId);
          OH_JSVM_DestroyVM(*g_vmMap[coreEnvId]);
          g_vmMap[coreEnvId] = nullptr;
          g_vmMap.erase(coreEnvId);
          delete [] g_callBackStructMap[coreEnvId];
          g_callBackStructMap[coreEnvId] = nullptr;
          g_callBackStructMap.erase(coreEnvId);
          napi_delete_reference(env1, g_callBackMap[coreEnvId]);
          g_callBackMap.erase(coreEnvId);
          g_taskQueueMap.erase(coreEnvId);
      }
      OH_LOG_ERROR(LOG_APP, "JSVM ReleaseJsCore END");
      return nullptr;
  }

  static std::mutex mutexLock;
  // 对外提供执行JS代码接口，通过coreID在对应的JSVN环境中执行JS代码
  static napi_value EvaluateJS(napi_env env, napi_callback_info info) {
      OH_LOG_ERROR(LOG_APP, "JSVM EvaluateJS START");
      size_t argc = 2;
      napi_value args[2] = {nullptr};
      napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
      uint32_t envId;
      napi_status status = napi_get_value_uint32(env, args[0], &envId);
      if (status != napi_ok) {
          OH_LOG_ERROR(LOG_APP, "EvaluateJS first param should be number");
          return nullptr;
      }
      
      if (g_envMap.count(envId) == 0 || g_envMap[envId] == nullptr) {
          OH_LOG_ERROR(LOG_APP, "EvaluateJS env is null");
          return nullptr;
      }
      std::string dataStr = napiValueToString(env, args[1]);
      napi_value res = nullptr;
      std::lock_guard<std::mutex> lock_guard(mutexLock);
      {
          // open vm scope
          JSVM_VMScope vmscope;
          OH_JSVM_OpenVMScope(*g_vmMap[envId], &vmscope);
          // open env scope
          JSVM_EnvScope envscope;
          OH_JSVM_OpenEnvScope(*g_envMap[envId], &envscope);
          // open handle scope
          JSVM_HandleScope handlescope;
          OH_JSVM_OpenHandleScope(*g_envMap[envId], &handlescope);
          // compile js script
          JSVM_Value sourcecodevalue;
          OH_JSVM_CreateStringUtf8(*g_envMap[envId], dataStr.c_str(), dataStr.size(), &sourcecodevalue);
          JSVM_Script script;
          OH_JSVM_CompileScript(*g_envMap[envId], sourcecodevalue, nullptr, 0, true, nullptr, &script);
          // run js script
          JSVM_Value result;
          OH_JSVM_RunScript(*g_envMap[envId], script, &result);
          JSVM_ValueType type;
          OH_JSVM_Typeof(*g_envMap[envId], result, &type);
          OH_LOG_INFO(LOG_APP, "JSVM API TEST type: %{public}d", type);
          // Execute tasks in the current env event queue
          while (!g_taskQueueMap[envId].empty()) {
              auto task = g_taskQueueMap[envId].front();
              g_taskQueueMap[envId].pop_front();
              task->Run();
              delete task;
          }

          if (type == JSVM_STRING) {
              std::string stdResult = fromOHStringValue(*g_envMap[envId], result);
              napi_create_string_utf8(env, stdResult.c_str(), stdResult.length(), &res);
          } else if (type == JSVM_BOOLEAN) {
              bool ret = false;
              std::string stdResult;
              OH_JSVM_GetValueBool(*g_envMap[envId], result, &ret);
              ret ? stdResult = "true" : stdResult = "false";
              napi_create_string_utf8(env, stdResult.c_str(), stdResult.length(), &res);
          } else if (type == JSVM_NUMBER) {
              int32_t num;
              OH_JSVM_GetValueInt32(*g_envMap[envId], result, &num);
              std::string stdResult = std::to_string(num);
              napi_create_string_utf8(env, stdResult.c_str(), stdResult.length(), &res);
          } else if (type == JSVM_OBJECT) {
              JSVM_Value objResult;
              OH_JSVM_JsonStringify(*g_envMap[envId], result, &objResult);
              std::string stdResult = fromOHStringValue(*g_envMap[envId], objResult);
              napi_create_string_utf8(env, stdResult.c_str(), stdResult.length(), &res);
      }
          bool aal = false;
          OH_JSVM_PumpMessageLoop(*g_vmMap[envId], &aal);
          OH_JSVM_PerformMicrotaskCheckpoint(*g_vmMap[envId]);
          OH_JSVM_CloseHandleScope(*g_envMap[envId], handlescope);
          OH_JSVM_CloseEnvScope(*g_envMap[envId], envscope);
          OH_JSVM_CloseVMScope(*g_vmMap[envId], vmscope);
      }
      OH_LOG_ERROR(LOG_APP, "JSVM EvaluateJS END");
      return res;
  }
  ```

**模块注册**

  ```cpp
  // create_jsvm_runtime.cpp
  EXTERN_C_START
  static napi_value Init(napi_env env, napi_value exports) {
      napi_property_descriptor desc[] = {
          {"createJsCore", nullptr, CreateJsCore, nullptr, nullptr, nullptr, napi_default, nullptr},
          {"releaseJsCore", nullptr, ReleaseJsCore, nullptr, nullptr, nullptr, napi_default, nullptr},
          {"evaluateJS", nullptr, EvaluateJS, nullptr, nullptr, nullptr, napi_default, nullptr}
      };

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

3.ArkTS侧示例代码

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import testNapi from 'libentry.so';

  function MyCallback(a:string, b:string):string {
      console.log("TEST MyCallback run: " + a);
      b = "callback done";
      console.log("TEST MyCallback run: " + b);
      return "callback pass";
  }

  function MyCallback2(a:string, b:string):string {
    console.log("TEST MyCallback2 start: a =  " + a);
    console.log("TEST MyCallback2 start: b =  " + b);
    return "MyCallback2 pass";
  }

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
              let sourcecodestr = `{
            let a = "hello World";
            consoleinfo(a);
            const mPromise = createPromise();
            mPromise.then((result) => {
            assertEqual(result, 0);
            onJSResultCallback(result, "abc", "v");
            });
            a;
            };`;

              let sourcecodestr1 = `{
            let a = "second hello";
            consoleinfo(a);
            let b = add(99, 1);
            assertEqual(100, b);
            assertEqual(add(99, 1), 100);
            createPromise().then((result) => {
            assertEqual(result, 1);
            consoleinfo(onJSResultCallback(result, '999','666'));
            });
            a;
            };`;

              // 创建首个运行环境，并绑定TS回调
              const coreId = testNapi.createJsCore(MyCallback);
              console.log("TEST coreId: " + coreId);
              // 在首个运行环境中执行JS代码
              console.log("TEST evaluateJS :   " + testNapi.evaluateJS(coreId, sourcecodestr));

              //创建第二个运行环境，并绑定TS回调
              const coreId1 = testNapi.createJsCore(MyCallback2);
              console.log("TEST coreId: " + coreId1);
              // 在第二个运行环境中执行JS代码
              console.log("TEST evaluateJS :   " + testNapi.evaluateJS(coreId1, sourcecodestr1));

              // 释放首个运行环境
              testNapi.releaseJsCore(coreId);
              // 释放第二个运行环境
              testNapi.releaseJsCore(coreId1);
              hilog.info(0x0000, 'testTag', 'Test NAPI end');
            })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```