# 使用JSVM-API接口进行函数创建和调用

## 简介

函数调用允许开发者从JSVM模块中调用JavaScript函数，并传递参数进行调用，或者直接在JSVM模块中创建一个JavaScript方法。

## 基本概念

函数是一种非常重要的编程概念，可以执行特定的任务或操作、提高代码的可读性、把复杂任务简化、提高代码复用性以及支持代码的组织与管理。每个函数可以负责不同的功能，提供一种将代码模块化和组织结构化的方式，使其更易于理解、维护和重用。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_GetCbInfo          | 从给定的callback info中获取有关调用的详细信息，如参数和this指针。|
| OH_JSVM_CallFunction       | 在C/C++侧调用JavaScript方法。|
| OH_JSVM_IsFunction         | 判断对象是否为函数对象 |
| OH_JSVM_CreateFunction     | 用于创建JavaScript函数,用于从JavaScript环境中调用C/C++代码中的函数, 需要设置到一个js对象中才可以进行调用。 |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### OH_JSVM function整合测试

cpp测试全量代码，入口为TEST_FUNC
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
    void *data;
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    JSVM_Value thisArg;
    // 获取callback 参数信息
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
        // 单个进程只用初始化一次
        OH_JSVM_Init(&initOptions);
    }
    CHECK_RET(OH_JSVM_CreateVM(nullptr, &vm));
    CHECK_RET(OH_JSVM_CreateEnv(vm, 0, nullptr, &env));
    CHECK_RET(OH_JSVM_OpenVMScope(vm, &vmScope));
    CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handleScope));

    // 创建并检查函数
    char hello[] = "Hello World!";
    JSVM_CallbackStruct cb = {NativeCreateFunctionTest, (void*)hello};
    JSVM_Value func;
    CHECK_RET(OH_JSVM_CreateFunction(env, "", JSVM_AUTO_LENGTH, &cb, &func));
    bool isFunction = false;
    CHECK_RET(OH_JSVM_IsFunction(env, func, &isFunction));
    CHECK(isFunction);

    // 将函数设置到全局对象中
    JSVM_Value global;
    CHECK_RET(OH_JSVM_GetGlobal(env, &global));
    JSVM_Value key;
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, "NativeFunc", JSVM_AUTO_LENGTH, &key));
    CHECK_RET(OH_JSVM_SetProperty(env, global, key, func));

    // 通过call 接口调用函数
    JSVM_Value argv[1] = {nullptr};
    OH_JSVM_CreateStringUtf8(env, "jsvm api call function", JSVM_AUTO_LENGTH, &argv[0]);
    CHECK_RET(OH_JSVM_CallFunction(env, global, func, 1, argv, &result));

    // 通过script调用函数
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
预期的输出
```
jsvm: jsvm api call function; Hello World!
jsvm: js source call function; Hello World!
```