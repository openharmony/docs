# 使用JSVM-API进行异常的定制化处理

## 简介

JSVM-API提供了一组用于处理JSVM异常的接口。用户可以通过这些接口，向JSVM中注册回调函数。当JSVM触发异常时，会触发对所注册的回调函数的回调。
这些接口提供了对JS引擎中某些关键错误的定制化处理能力，可以帮助开发者在运行时更好地管理错误和异常情况。

## 基本概念

当JS引擎遇到内存不足的问题时，系统会抛出一个OOM Error，如果开发者提前向JS引擎中注册了OOM-Error的处理函数，系统就会调用这个设置的处理函数，开发者可以在处理函数中执行一些清理或者日志记录操作。
当JS引擎发生致命错误时，例如执行JavaScript代码时出现无法恢复的错误，系统会抛出一个Fatal Error，同时系统会调用用户提前设置的处理Fatal Error的函数。在这个处理函数中，用户可以输出额外的日志或者报告错误，而不是让程序直接崩溃。
当JavaScript中的Promise被拒绝，而这个拒绝又没有被catch处理时，系统就会抛出一个Promise Reject，同时系统会调用用户提前设置的处理Promise Reject的函数。在这个处理函数中，用户可以处理未捕获的Promise拒绝。

## 接口说明

| 接口                       | 功能说明                            |
|----------------------------|-------------------------------------|
| OH_JSVM_SetHandlerForOOMError         | 用于在VM中设置处理OOM-Error的函数|
| OH_JSVM_SetHandlerForFatalError   | 用于在VM中设置处理Fatal-Error的函数|
| OH_JSVM_SetHandlerForPromiseReject | 用于在VM中设置处理Promise-Reject的函数 |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### OH_JSVM_SetHandlerForOOMError
通过OH_JSVM_SetHandlerForOOMError，用户可以设置处理OOM Error的函数。当多次调用这个API进行函数设置时，仅最后一次设置会生效。当用户传入的设置函数为NULL时，则表示取消之前设置的处理函数。

#### cpp部分代码

```cpp
#include <csetjmp>
#include <vector>

static jmp_buf buf;
static bool oomHandlerFinished = false;

void OnOOMError(const char *location, const char *detail, bool isHeapOOM)
{
    oomHandlerFinished = true;
    longjmp(buf, 1);
}

static JSVM_Value TriggerOOMError(JSVM_Env env, JSVM_CallbackInfo info)
{
    oomHandlerFinished = false;
    JSVM_VM vm;
    JSVM_CALL(OH_JSVM_GetVM(env, &vm));
    // 设置OOM Error处理函数
    JSVM_CALL(OH_JSVM_SetHandlerForOOMError(vm, OnOOMError));
    bool oomed = false;
    setjmp(buf);
    if (!oomed) {
        oomed = true;
        // 触发OOM
        std::vector<JSVM_Value> arrayVec;
        int loopCount = 1000;
        for (int i = 0; i < loopCount; i++) {
            JSVM_Value array;
            JSVM_CALL(OH_JSVM_CreateArrayWithLength(env, 0xffffff, &array));
            arrayVec.push_back(array);
        }
    }
    if (oomHandlerFinished) {
      OH_LOG_INFO(LOG_APP, "JSVM Trigger OOM-Error: success");
    } else {
      OH_LOG_ERROR(LOG_APP, "JSVM Trigger OOM-Error: failed");
    }
    // 取消对OOM Error处理函数的设置
    JSVM_CALL(OH_JSVM_SetHandlerForOOMError(vm, NULL));
    JSVM_Value checked;
    OH_JSVM_GetBoolean(env, true, &checked);
    return checked;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = TriggerOOMError},
};
static JSVM_CallbackStruct *method = param;

static JSVM_PropertyDescriptor descriptor[] = {
    {"triggerOOMError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```
#### 样例测试JS

const char *srcCallNative = R"JS(triggerOOMError();)JS";

#### 执行结果

在LOG中输出：　JSVM Trigger OOM-Error: success

### OH_JSVM_SetHandlerForFatalError
通过OH_JSVM_SetHandlerForFatalError，用户可以设置处理Fatal Error的函数。当多次调用这个API进行函数设置时，仅最后一次设置会生效。当用户传入的设置函数为NULL时，则表示取消之前设置的处理函数。
#### cpp部分代码

```cpp
#include <csetjmp>
#include <vector>

static jmp_buf buf;
static bool fatalHandlerFinished = false;
void OnFatalError(const char *location, const char *message)
{
    fatalHandlerFinished = true;
    OH_LOG_INFO(LOG_APP, "Run in 106");
    longjmp(buf, 1);
}

static JSVM_Value TriggerFatalError(JSVM_Env env, JSVM_CallbackInfo info)
{
    fatalHandlerFinished = false;
    JSVM_VM vm;
    JSVM_CALL(OH_JSVM_GetVM(env, &vm));
    // 设置Fatal Error处理函数
    JSVM_CALL(OH_JSVM_SetHandlerForFatalError(vm, OnFatalError));
    bool fataled = false;
    setjmp(buf);
    if (!fataled) {
        fataled = true;
        std::vector<JSVM_Value> arrayVec;
        int loopCount = 1000;
        for (int i = 0; i < loopCount; i++) {
            JSVM_Value array;
            JSVM_CALL(OH_JSVM_CreateArrayWithLength(env, 0xffffff, &array));
            arrayVec.push_back(array);
        }
    }
    if (fatalHandlerFinished) {
      OH_LOG_INFO(LOG_APP, "JSVM Trigger Fatal-Error: success");
    } else {
      OH_LOG_ERROR(LOG_APP, "JSVM Trigger Fatal-Error: failed");
    }
    // 取消对Fatal Error处理函数的设置
    JSVM_CALL(OH_JSVM_SetHandlerForFatalError(vm, NULL));
    JSVM_Value checked;
    OH_JSVM_GetBoolean(env, true, &checked);
    return checked;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = TriggerFatalError},
};
static JSVM_CallbackStruct *method = param;

static JSVM_PropertyDescriptor descriptor[] = {
    {"triggerFatalError", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```
#### 样例测试JS

const char* srcCallNative = R"JS(triggerFatalError())JS";

#### 执行结果

在LOG中输出：　JSVM Trigger Fatal-Error: success

### OH_JSVM_SetHandlerForPromiseReject
通过OH_JSVM_SetHandlerForPromiseReject，用户可以设置处理Promise Reject的函数。当多次调用这个API进行函数设置时，仅最后一次设置会生效。当用户传入的设置函数为NULL时，则表示取消之前设置的处理函数。
#### cpp部分代码

```cpp
static bool promiseRejectHandlerFinished = false;

void OnPromiseReject(JSVM_Env env, JSVM_PromiseRejectEvent rejectEvent, JSVM_Value rejectInfo)
{
    bool result;
    OH_JSVM_IsObject(env, rejectInfo, &result);
    JSVM_Value promise;
    JSVM_Value key1;
    OH_JSVM_CreateStringUtf8(env, "promise", JSVM_AUTO_LENGTH, &key1);
    OH_JSVM_GetProperty(env, rejectInfo, key1, &promise);
    bool isPromise = false;
    OH_JSVM_IsPromise(env, promise, &isPromise);
    JSVM_Value value;
    JSVM_Value key2;
    OH_JSVM_CreateStringUtf8(env, "value", JSVM_AUTO_LENGTH, &key2);
    OH_JSVM_GetProperty(env, rejectInfo, key2, &value);
    JSVM_Value js_number;
    OH_JSVM_CoerceToNumber(env, value, &js_number);
    double res;
    OH_JSVM_GetValueDouble(env, js_number, &res);
    if (res == 42 && isPromise) {
        promiseRejectHandlerFinished = true;
    }
}

static JSVM_Value TriggerPromiseReject(JSVM_Env env, JSVM_CallbackInfo info)
{
    promiseRejectHandlerFinished = false;
    JSVM_VM vm;
    JSVM_CALL(OH_JSVM_GetVM(env, &vm));
    // 设置Promise Reject处理函数
    JSVM_CALL(OH_JSVM_SetHandlerForPromiseReject(vm, OnPromiseReject));
    JSVM_Value strVal;
    char *str = "new Promise((resolve, reject) => { reject(42); })";
    OH_JSVM_CreateStringUtf8(env, str, JSVM_AUTO_LENGTH, &strVal);
    JSVM_Script script;
    OH_JSVM_CompileScript(env, strVal, nullptr, 0, false, nullptr, &script);
    JSVM_Value result;
    JSVM_Status status = OH_JSVM_RunScript(env, script, &result);
    
    if (promiseRejectHandlerFinished) {
      OH_LOG_INFO(LOG_APP, "JSVM Trigger PromiseReject: success");
    } else {
      OH_LOG_ERROR(LOG_APP, "JSVM Trigger PromiseReject: failed");
    }
    // 取消对Promise Reject处理函数的设置
    JSVM_CALL(OH_JSVM_SetHandlerForPromiseReject(vm, NULL));
    JSVM_Value checked;
    OH_JSVM_GetBoolean(env, true, &checked);
    return checked;
}

static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = TriggerPromiseReject},
};
static JSVM_CallbackStruct *method = param;

static JSVM_PropertyDescriptor descriptor[] = {
    {"triggerPromiseReject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
```
#### 样例测试JS

const char* srcCallNative = R"JS(triggerPromiseReject())JS";

#### 执行结果

在LOG中输出：　JSVM Trigger PromiseReject: success