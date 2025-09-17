# 使用Node-API接口处理异步操作
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## 简介

使用Node-API接口处理异步操作。异步操作是指需要一定时间才能完成的操作，例如从网络下载数据或读取大型文件。与同步操作不同，异步操作不会阻塞主线程，而是会在后台执行。将异步操作完成后的事件放入任务队列，等待主线程空闲时执行。

## 基本概念

Promise是ArkTS中用来处理异步操作的对象，Promise有pending（待定）、fulfilled（已兑现）和rejected（已拒绝）三种状态，Promise的初始状态是pending。resolve函数可以使其状态从pending变为fulfilled（已兑现），reject函数可以使其状态从pending变为rejected（已拒绝），一旦状态变为已兑现或已拒绝，将不能再更改。以下是一些基本概念：

- **同步**：同步是指代码按顺序执行，一行代码执行完后继续执行下一行。如果某个操作耗时较长，整个程序会被阻塞。
- **异步**：异步是指任务可以同时执行，不需要等待上一个任务结束。常见的异步操作有定时器、事件监听和网络请求等。异步任务不会阻塞后续任务的执行，而是通过回调函数或Promise对象来处理任务的结果。
- **Promise**：Promise是一个ArkTS对象，用于处理异步操作。通过then、catch和finally方法添加自定义逻辑。
- **deferred**：deferred是延迟对象，与Promise关联，设置Promise的回调函数resolve和reject。维护异步模型状态。
- **resolve**：此函数可以将Promise的状态从pending（待定）改为fulfilled（已兑现），向resolve中传入的参数可以在Promise对象的then方法中获取。
- **reject**：此函数可以将Promise的状态从pending（待定）改为rejected（已拒绝），向reject中传入的参数可以在Promise对象的catch方法中获取。

这些基本概念非常重要，开发者需要通过适当的方法来处理异步操作，使用Promise链式调用多个异步操作，使代码清晰整洁，便于维护。Node-API提供的方法可以帮助开发者在C/C++应用中处理ArkTS中的异步操作。

## 场景和功能介绍

以下Node-API接口主要用于与ArkTS Promise对象进行交互。它们的使用场景如下：

| 接口 | 描述 |
| -------- | -------- |
| napi_is_promise | 检查一个napi_value是否代表一个Promise对象时，可以使用这个函数。 |
| napi_create_promise | 需要创建一个Promise对象时，可以使用这个函数。 |
| napi_resolve_deferred | 当你需要对promise关联的deferred对象进行resolve，将其从挂起状态转换为已兑现状态时，可以使用这个函数。 |
| napi_reject_deferred | 当你需要对promise关联的deferred对象进行reject，将其从挂起状态转换为已拒绝状态时，可以使用这个函数。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_is_promise

判断给定的napi_value是否表示一个Promise对象。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value IsPromise(napi_env env, napi_callback_info info)
{
    napi_value argv[1] = {nullptr};
    size_t argc = 1;
    napi_status status;
    // 获取传入的参数
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    bool isPromise = false;
    // 检查给定的入参是否为Promise对象，将结果保存在isPromise变量中
    status = napi_is_promise(env, argv[0], &isPromise);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_is_promise failed");
        return nullptr;
    }
    napi_value result = nullptr;
    // 将isPromise的值转换为napi_value中的类型返回
    napi_get_boolean(env, isPromise, &result);
    return result;
}
```
<!-- @[napi_is_promise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const isPromise: <T>(value: T) => boolean;
```
<!-- @[napi_is_promise_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let value = Promise.resolve();
// 传入的对象为Promise时，返回true，否则返回false
hilog.info(0x0000, 'Node-API', 'napi_is_promise %{public}s', testNapi.isPromise(value));
hilog.info(0x0000, 'Node-API', 'napi_is_promise string %{public}s', testNapi.isPromise(''));
```
<!-- @[ark_napi_is_promise](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/ets/pages/Index.ets) -->

### napi_create_promise

napi_create_promise用于创建一个Promise对象。

使用该接口时应注意：

1. 未处理异常时调用`napi_create_promise`会返回`napi_pending_exception`。
2. 使用`napi_create_promise`后未判断返回值是否为`napi_ok`，之后使用了无效的`deferred`和`promise`会导致应用崩溃。

```c++
napi_value NapiPromiseDemo(napi_env env, napi_callback_info info)
{
    napi_deferred deferred = nullptr;
    napi_value promise = nullptr;
    napi_status status = napi_ok;

    napi_throw_error(env, "500", "common error");

    status = napi_create_promise(env, &deferred, &promise); // 有异常返回napi_pending_exception，且deferred、promise都为nullptr
    if (status == napi_ok) {
        // do something
    }

    return nullptr;
}
```

### napi_resolve_deferred & napi_reject_deferred

使用napi_resolve_deferred对Promise关联的deferred对象进行解析，从挂起状态转换为已兑现状态，或从挂起状态转换为已拒绝状态。

为确保微任务正确执行，ArkTS运行时在使用Node-API方法兑现Promise时，会触发一次微任务执行。

CPP部分代码

```cpp
#include "napi/native_api.h"

static constexpr int INT_ARG_2 = 2; // 入参索引

static napi_value CreatePromise(napi_env env, napi_callback_info info)
{
    // deferred是一个延迟对象，作用是将函数延迟一定时间再执行
    napi_deferred deferred = nullptr;
    napi_value promise = nullptr;
    // 调用接口创建Promise对象
    napi_status status = napi_create_promise(env, &deferred, &promise);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Create promise failed");
        return nullptr;
    }
    // 调用napi_is_promise判断napi_create_promise接口创建的是不是Promise对象
    bool isPromise = false;
    napi_value returnIsPromise = nullptr;
    status = napi_is_promise(env, promise, &isPromise);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_is_promise failed");
        return nullptr;
    }
    // 将布尔值转为可以返回的napi_value
    napi_get_boolean(env, isPromise, &returnIsPromise);
    return returnIsPromise;
}

static napi_value ResolveRejectDeferred(napi_env env, napi_callback_info info)
{
    // 获得并解析参数
    size_t argc = 3;
    napi_value args[3] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 第一个参数为向resolve传入的信息，第二个参数为向reject传入的信息，第三个参数为Promise的状态
    bool promiseStatus;
    napi_status status = napi_get_value_bool(env, args[INT_ARG_2], &promiseStatus);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_get_value_bool failed");
        return nullptr;
    }

    // 创建Promise对象
    napi_deferred deferred = nullptr;
    napi_value promise = nullptr;
    status = napi_create_promise(env, &deferred, &promise);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Create promise failed");
        return nullptr;
    }
    // 根据第三个参数设置resolve或reject
    if (promiseStatus) {
        napi_resolve_deferred(env, deferred, args[0]);
    } else {
        napi_reject_deferred(env, deferred, args[1]);
    }
    // 返回设置了resolve或reject的Promise对象
    return promise;
}
```
<!-- @[napi_resolve_reject_deferred](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/cpp/napi_init.cpp) -->

接口声明示例

```ts
// index.d.ts
export const createPromise: () => boolean | undefined;
export const resolveRejectDeferred: (resolve: string, reject: string, status: boolean) => Promise<string> | undefined;
```
<!-- @[napi_resolve_reject_deferred_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

// 创建promise如果创建成功返回true，创建失败返回false
hilog.info(0x0000, 'Node-API', 'napi_create_promise %{public}s', testNapi.createPromise());
// 调用resolveRejectDeferred函数设置resolve和reject的返回结果以及Promise状态
// Promise状态为true时设置resolve，返回结果在then函数中获得
let promiseSuccess: Promise<string> = testNapi.resolveRejectDeferred('success', 'fail', true) as Promise<string>;
promiseSuccess.then((res) => {
  hilog.info(0x0000, 'Node-API', 'get_resolve_deferred resolve %{public}s', res)
}).catch((err: Error) => {
  hilog.info(0x0000, 'Node-API', 'get_resolve_deferred reject %{public}s', err)
})
// Promise状态为false时设置reject，返回结果在catch函数中获得
let promiseFail: Promise<string> = testNapi.resolveRejectDeferred('success', 'fail', false) as Promise<string>;
promiseFail.then((res) => {
  hilog.info(0x0000, 'Node-API', 'get_resolve_deferred resolve %{public}s', res)
}).catch((err: Error) => {
  hilog.info(0x0000, 'Node-API', 'get_resolve_deferred reject %{public}s', err)
})
```
<!-- @[ark_napi_resolve_reject_deferred](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIPromise/entry/src/main/ets/pages/Index.ets) -->

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
