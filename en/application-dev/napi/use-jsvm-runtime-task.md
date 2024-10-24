# Creating and Destroying JSVMs Using JSVM-API

## When to Use

Use **createJsCore** to create a JavaScript virtual machine (JSVM), which a runtime environment for executing JS code. The **createJsCore** returns a core ID, which uniquely identifies a VM.

Use **evaluateJS** to run JS code in the VM of the specified core ID and define a promise in the JS code to asynchronously invoke the callback set in TS.

Use **releaseJsCore** to release a JSVM.

## Example

1. Declare APIs and configure compile settings.

**Declare the APIs.**

  ```ts
  // index.d.ts
  export const createJsCore: (fun: Function) => number;
  export const releaseJsCore: (a: number) => void;
  export const evaluateJS: (a: number, str: string) => string;
  ```

**Configure compile settings.**

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

2. Create multiple JS runtime environments and run JS code.

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
  // Obtain and throw the last error message. Use OH_JSVM_GetLastErrorInfo to obtain error information.
  // If there is error information and no suspended exception, use OH_JSVM_ThrowError to throw an error.
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

  // Call theCall and check whether the return value is JSVM_OK.
  // If no, call GET_AND_THROW_LAST_ERROR to process the error and return retVal.
  #define JSVM_CALL_BASE(env, theCall, retVal)                                                            \
      do {                                                                                                \
          if ((theCall) != JSVM_OK) {                                                                     \
              GET_AND_THROW_LAST_ERROR((env));                                                            \
              return retVal;                                                                              \
          }                                                                                               \
      } while (0)

  // Simplified version of JSVM_CALL_BASE. nullptr is returned.
  #define JSVM_CALL(env, theCall) JSVM_CALL_BASE(env, theCall, nullptr)

  using namespace std;
  // Define a map to manage each independent VM.
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

  // Customize Consoleinfo.
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

  // Create a promise method, which is used to create a promise in JS code.
  static JSVM_Value CreatePromise(JSVM_Env env, JSVM_CallbackInfo info) {
      OH_LOG_INFO(LOG_APP, "JSVM API TEST: CreatePromise start");
      int envID = 0;
      // Obtain envID of the current env.
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
      // Define a ReadTask class to add deferred of the promise object to the execution queue.
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

  // Customize the Add method.
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

  // Customize the AssertEqual method.
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

  // Invoke the native callback passed by TS.
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
      // Obtain the TS callback, which is passed in when the JSVM is created, based on the call ID.
      napi_get_reference_value(g_napiEnvMap[callId], g_callBackMap[callId], &callback);
      napi_value ret;
      // Execute the TS callback.
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

      // VM instance.
      g_vmMap[ENVTAG_NUMBER] = new JSVM_VM;
      JSVM_CreateVMOptions options;
      memset(&options, 0, sizeof(options));
      status = OH_JSVM_CreateVM(&options, g_vmMap[ENVTAG_NUMBER]);
      JSVM_VMScope vmScope;
      OH_JSVM_OpenVMScope(*g_vmMap[ENVTAG_NUMBER], &vmScope);

      // New environment.
      g_envMap[ENVTAG_NUMBER] = new JSVM_Env;
      g_callBackStructMap[ENVTAG_NUMBER] = new JSVM_CallbackStruct[5];
      
      // Register the pointers to the native callbacks and data provided by the user and expose them to JS code through JSVM-API.
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

  // Provide an external interface for creating the JSVM and return the unique ID.
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
      // Store the mapping between the callback passed in by TS and env for subsequent calling.
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

  // Provide an external interface for releasing the JSVM based on envId.
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
  // Provide an external interface for running the JS code in the JSVM identified by a core ID.
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
          // Compile the JS script.
          JSVM_Value sourcecodevalue;
          OH_JSVM_CreateStringUtf8(*g_envMap[envId], dataStr.c_str(), dataStr.size(), &sourcecodevalue);
          JSVM_Script script;
          OH_JSVM_CompileScript(*g_envMap[envId], sourcecodevalue, nullptr, 0, true, nullptr, &script);
          // Run the JS script.
          JSVM_Value result;
          OH_JSVM_RunScript(*g_envMap[envId], script, &result);
          JSVM_ValueType type;
          OH_JSVM_Typeof(*g_envMap[envId], result, &type);
          OH_LOG_INFO(LOG_APP, "JSVM API TEST type: %{public}d", type);
          // Execute tasks in the current env event queue.
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

**Register the module.**

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

  3. Run ArkTS code.

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

              // Create the first VM and bind the TS callback.
              const coreId = testNapi.createJsCore(MyCallback);
              console.log("TEST coreId: " + coreId);
              // Run JS code in the first VM.
              console.log("TEST evaluateJS :   " + testNapi.evaluateJS(coreId, sourcecodestr));

              // Create the second VM and bind the TS callback.
              const coreId1 = testNapi.createJsCore(MyCallback2);
              console.log("TEST coreId: " + coreId1);
              // Run JS code in the second VM.
              console.log("TEST evaluateJS :   " + testNapi.evaluateJS(coreId1, sourcecodestr1));

              // Release the first VM.
              testNapi.releaseJsCore(coreId);
              // Release the second VM.
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
