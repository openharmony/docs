# 使用JSVM-API接口处理异步操作
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @huanghan18; @suyuehhh; @KasonChan; @string_sz; @diking-->
<!--SE: @knightaoko-->
<!--TSE: @test_lzz-->

## 简介

使用JSVM-API接口处理异步操作。异步操作是指需要一定时间才能完成的操作，例如从网络下载数据或读取大型文件。与同步操作不同，异步操作不会阻塞主线程，而是会在后台执行。当异步操作完成后，事件循环将把它放入任务队列中，等待主线程空闲时执行。

## 基本概念

Promise是JavaScript中用来处理异步操作的对象，Promise有pending（待定）、fulfilled（已兑现）和rejected（已拒绝）三种状态，Promise的初始状态是pending，resolve函数可以使其状态从pending变为fulfilled（已兑现），reject函数可以使其状态从pending变为rejected(已拒绝)，一旦兑现或拒绝Promise的状态将不能更改。下面是一些基本概念：

- **同步**： 同步是指代码按照顺序一行一行地执行，每行代码的执行都会等待上一行代码执行完成后再继续执行。在同步执行中，如果某个操作需要花费较长时间，那么整个程序的执行就会被阻塞，直到该操作完成才能继续执行后续代码。
- **异步**：异步是指任务可以同时执行，不需要等待上一个任务结束。在JavaScript中，常见的异步操作包括定时器、事件监听、网络请求等。异步任务不会阻塞后续任务的执行，而是通过回调函数或Promise对象来处理任务的结果。
- **Promise**：Promise是一个JavaScript对象，用于处理异步操作。Promise作用于外部，通常通过then、catch和finally方法暴露给外部以添加自定义逻辑。
- **deferred**：deferred是延迟对象，它可以与Promise对象关联，设置Promise的回调函数resolve和reject。deferred作用于内部，维护异步模型的状态并设置回调函数resolve和reject。
- **resolve**：此函数可以将Promise的状态从pending（待定）改为fulfilled（已兑现），向resolve中传入的参数可以在Promise对象的then方法中获取。
- **reject**：此函数可以将Promise的状态从pending（待定）改为rejected（已拒绝），向reject中传入的参数可以在Promise对象的catch方法中获取。

这些基本概念在处理异步操作中非常重要，开发者需要通过适当的方法来处理异步操作，Promise可以链式调用多个异步操作，使代码清晰整洁，便于维护。JSVM-API提供的方法可以帮助开发者在JSVM模块中处理JavaScript中的异步操作。

## 接口说明

| 接口                       | 功能说明                       |
|----------------------------|--------------------------------|
| OH_JSVM_IsPromise            | 查询Promise是否为Promise对象|
| OH_JSVM_CreatePromise        | 创建一个延迟对象和一个JavaScript promise|
| OH_JSVM_ResolveDeferred      | 通过与之关联的延迟对象来解析JavaScript promise|
| OH_JSVM_RejectDeferred       | 通过与之关联的延迟对象来拒绝JavaScript promise|
| OH_JSVM_PromiseRegisterHandler | 为 Promise 创建兑现或拒绝后的回调 |

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

### OH_JSVM_IsPromise

判断给定的JSVM_Value是否表示一个Promise对象。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_IsPromise的样例方法
static JSVM_Value IsPromise(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool isPromise = false;
    JSVM_Status status = OH_JSVM_IsPromise(env, args[0], &isPromise);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_IsPromise fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_IsPromise success:%{public}d", isPromise);
    }
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, isPromise, &result);
    return result;
}
// IsPromise注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsPromise},
};
static JSVM_CallbackStruct *method = param;
// IsPromise方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"isPromise", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(isPromise())JS";
```
<!-- @[oh_jsvm_ispromise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPromise/ispromise/src/main/cpp/hello.cpp) -->

预期结果：
```
JSVM OH_JSVM_IsPromise success:0
```

### OH_JSVM_CreatePromise

OH_JSVM_CreatePromise用于创建一个Promise对象。

### OH_JSVM_ResolveDeferred & OH_JSVM_RejectDeferred

用于对Promise关联的deferred对象进行解析，OH_JSVM_ResolveDeferred将其从挂起状态转换为已兑现状态，OH_JSVM_RejectDeferred将其从挂起状态转换为已拒绝状态。

cpp部分代码

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// OH_JSVM_CreatePromise、OH_JSVM_ResolveDeferred、OH_JSVM_RejectDeferred的样例方法
static JSVM_Value CreatePromise(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Deferred defer = nullptr;
    JSVM_Value promise = nullptr;
    JSVM_Status status = OH_JSVM_CreatePromise(env, &defer, &promise);
    bool isPromise = false;
    JSVM_Value returnIsPromise = nullptr;
    OH_JSVM_IsPromise(env, promise, &isPromise);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreatePromise fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM CreatePromise success:%{public}d", isPromise);
    }
    // 将布尔值转为可以返回的JSVM_Value
    OH_JSVM_GetBoolean(env, isPromise, &returnIsPromise);
    return returnIsPromise;
}

static JSVM_Value ResolveRejectDeferred(JSVM_Env env, JSVM_CallbackInfo info)
{
    // 获得并解析参数
    size_t argc = 3;
    JSVM_Value args[3] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // 第一个参数为向resolve传入的信息，第二个参数为向reject传入的信息，第三个参数为Promise的状态
    bool status = false;
    OH_JSVM_GetValueBool(env, args[2], &status);
    // 创建Promise对象
    JSVM_Deferred deferred = nullptr;
    JSVM_Value promise = nullptr;
    JSVM_Status createStatus = OH_JSVM_CreatePromise(env, &deferred, &promise);
    if (createStatus != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "Create promise failed");
        return nullptr;
    }
    // 根据第三个参数设置resolve或reject
    if (status) {
        OH_JSVM_ResolveDeferred(env, deferred, args[0]);
        OH_LOG_INFO(LOG_APP, "OH_JSVM_ResolveDeferred resolve");
    } else {
        OH_JSVM_RejectDeferred(env, deferred, args[1]);
        OH_LOG_INFO(LOG_APP, "OH_JSVM_RejectDeferred reject");
    }
    JSVM_Value result = nullptr;
    OH_JSVM_GetBoolean(env, true, &result);
    return result;
}
// CreatePromise,ResolveRejectDeferred注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreatePromise},
    {.data = nullptr, .callback = ResolveRejectDeferred},
};
static JSVM_CallbackStruct *method = param;
// CreatePromise,ResolveRejectDeferred方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"createPromise", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"resolveRejectDeferred", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(createPromise();
                                 resolveRejectDeferred('success', 'fail', true);
                                 resolveRejectDeferred('success', 'fail', false);)JS";
```
<!-- @[oh_jsvm_resolvedeferred_and_rejectdeferred](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutPromise/resolvereject/src/main/cpp/hello.cpp) -->

预期结果：
```
JSVM CreatePromise success:1
OH_JSVM_ResolveDeferred resolve
OH_JSVM_RejectDeferred reject
```

## OH_JSVM_PromiseRegisterHandler

用于设置 Promise 解析或拒绝后的回调，等效于调用原生的 `Promise.then()` 或 `Promise.catch()`。

以下仅对 cpp 部分代码进行展示，其余框架代码如 `TestJSVM` 函数参考 [使用JSVM-API接口进行任务队列相关开发](use-jsvm-execute_tasks.md) OH_JSVM_SetMicrotaskPolicy 段落中的实现。

```cpp
static int PromiseRegisterHandler(JSVM_VM vm, JSVM_Env env) {
    const char *defineFunction = R"JS(
        var x1 = 0;
        var x2 = 0;
        function f1(x) {
            x1 = x;
            return x + 1;
        }
        function f2(x) {
            x2 = x;
            return x + 1;
        }
    )JS";

    const char *init = R"JS(
        x1 = 0;
        x2 = 0;
    )JS";

    JSVM_Script script;
    JSVM_Value jsSrc;
    JSVM_Value result;

    // 定义 JS 函数 f1 和 f2
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, defineFunction, JSVM_AUTO_LENGTH, &jsSrc));
    CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));

    // 初始化 x1， x2 为 0
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, init, JSVM_AUTO_LENGTH, &jsSrc));
    CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));

    // 获取函数 f1 和 f2
    JSVM_Value global;
    CHECK_RET(OH_JSVM_GetGlobal(env, &global));
    JSVM_Value f1;
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "f1", &f1));
    JSVM_Value f2;
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "f2", &f2));

    // 创建 Promise
    JSVM_Value promise;
    JSVM_Deferred deferred;
    CHECK_RET(OH_JSVM_CreatePromise(env, &deferred, &promise));
    // 为 promise 注册回调函数，并将 then 调用的结果（新的 Promise）赋值给 promise1
    JSVM_Value promise1;
    CHECK_RET(OH_JSVM_PromiseRegisterHandler(env, promise, f1, nullptr, &promise1));
    // 为 promise1 注册回调函数
    CHECK_RET(OH_JSVM_PromiseRegisterHandler(env, promise1, f2, nullptr, nullptr));

    // 获取 promise 解析前 x1 和 x2 的值
    JSVM_Value x1;
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "x1", &x1));
    int32_t x1Int = 0;
    CHECK_RET(OH_JSVM_GetValueInt32(env, x1, &x1Int));
    JSVM_Value x2;
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "x2", &x2));
    int32_t x2Int = 0;
    CHECK_RET(OH_JSVM_GetValueInt32(env, x2, &x2Int));
    OH_LOG_INFO(LOG_APP, "Before promise resolved, x1: %{public}d, x2: %{public}d", x1Int, x2Int);

    // 解析 promise
    JSVM_Value resolveValue;
    CHECK_RET(OH_JSVM_CreateInt32(env, 2, &resolveValue));
    if (deferred != nullptr) {
        OH_JSVM_ResolveDeferred(env, deferred, resolveValue);
        deferred = nullptr;
    }

    // 获取 promise 解析后 x1 和 x2 的值
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "x1", &x1));
    CHECK_RET(OH_JSVM_GetValueInt32(env, x1, &x1Int));
    CHECK_RET(OH_JSVM_GetNamedProperty(env, global, "x2", &x2));
    CHECK_RET(OH_JSVM_GetValueInt32(env, x2, &x2Int));
    OH_LOG_INFO(LOG_APP, "After promise resolved, x1: %{public}d, x2: %{public}d", x1Int, x2Int);

    return 0;
}

static void RunDemo(JSVM_VM vm, JSVM_Env env) {
    if (PromiseRegisterHandler(vm, env) != 0) {
        OH_LOG_INFO(LOG_APP, "Run PromiseRegisterHandler failed");
    }
}
```

预期结果：
```
Before promise resolved, x1: 0, x2: 0
After promise resolved, x1: 2, x2: 3
```
