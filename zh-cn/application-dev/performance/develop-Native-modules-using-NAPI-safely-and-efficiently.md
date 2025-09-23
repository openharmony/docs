# 安全和高效的使用N-API开发Native模块

<!--Kit: Common-->
<!--Subsystem: Demo&Sample-->
<!--Owner: @mgy917-->
<!--Designer: @jiangwensai-->
<!--Tester: @Lyuxin-->
<!--Adviser: @huipeizi-->

## 简介

N-API 是 Node.js Addon Programming Interface 的缩写，是 Node.js 提供的一组 C++ API，封装了[V8 引擎](https://dev.nodejs.cn/learn/the-v8-javascript-engine/)的能力，用于编写 Node.js 的 Native 扩展模块。通过 N-API，开发者可以使用 C++ 编写高性能的 Node.js 模块，同时保持与 Node.js 的兼容性。 

[Node.js 官网](https://nodejs.org/api/n-api.html)中已经给出 N-API 接口基础能力的介绍，同时，[方舟 ArkTS 运行时](https://gitcode.com/openharmony/arkcompiler_ets_runtime)提供的 N-API 接口，封装了方舟引擎的能力，在功能上与 Node.js 社区保持一致，这里不再赘述。 

本文将结合应用开发场景，分别从对象生命周期管理、跨语言调用开销、异步操作和线程安全四个角度出发，给出安全、高效的 N-API 开发指导。 

## 对象生命周期管理

在进行 N-API 调用时，引擎堆中对象的句柄 handle 会作为 [napi_value](https://nodejs.org/api/n-api.html#napi_value) 返回，对象的生命周期由这些句柄控制。对象的句柄会与一个 scope 保持一致，默认情况下，对象当前所在 native 方法是 handle 的 scope。在应用 native 模块实际开发过程中，需要对象有比当前所在 native 方法更短或更长的 scope。本文描述了管理对象生命周期的 N-API 接口，开发者通过这些接口可以合理的管理对象生命周期，满足业务诉求。

### 缩短对象生命周期

合理使用 napi_open_handle_scope 和 napi_close_handle_scope 管理 napi_value 的生命周期，做到生命周期最小化，避免发生内存泄漏问题。

例如，考虑一个具有 for 循环的方法，在该循环中遍历获取大型数组的元素，示例代码如下： 
```cpp
for (int i = 0; i < 1000000; i++) {
 napi_value result;
 napi_status status = napi_get_element(env, object, i, &result);
 if (status != napi_ok) {
  break;
 }
 // do something with element
}
```

在 for 循环中会创建大量的 handle，消耗大量资源。为了减小内存开销，N-API 提供创建局部 scope 的能力，在局部 scope 中间所创建 handle 的生命周期将与局部 scpoe 保持一致。一旦不再需要这些 handle，就可以直接关闭局部 scope。

* 打开和关闭 scope 的方法为 napi_open_handle_scope 和 napi_close_handle_scope；
* N-API 中 scope 的层次结构是一个嵌套的层次结构，任何时候只有一个存活的 scope，所有新创建的 handle 都将在该 scope 处于存活状态时与之关联；
* scope 必须按打开的相反顺序关闭，在 native 方法中创建的所有 scope 必须在该方法返回之前关闭。

例如，使用下面的方法，可以确保在循环中，最多只有一个句柄是有效的： 
```cpp
// 在for循环中频繁调用napi接口创建js对象时，要加handle_scope及时释放不再使用的资源；
// 下面例子中，每次循环结束局部变量res的生命周期已结束，因此加scope及时释放其持有的js对象，防止内存泄漏。
for (int i = 0; i < 1000000; i++) {
    napi_handle_scope scope;
    napi_status status = napi_open_handle_scope(env, &scope);
    if (status == napi_ok) {
        napi_value result;
        status = napi_get_element(env, object, i, &result);
        if (status == napi_ok) {
            // do something with element
        }
        status = napi_close_handle_scope(env, scope);
        if (status != napi_ok) {
            break;
        }
    }
}
```
存在一些场景，某些对象的生命周期需要大于对象本身所在区域的生命周期，例如嵌套循环场景。开发者可以通过 napi_open_escapable_handle_scope 与 napi_close_escapable_handle_scope 管理对象的生命周期，在此期间定义的对象的生命周期将与父作用域的生命周期保持一致。 

### 延长对象生命周期

开发者可以通过创建 napi_ref 来延长 napi_value 对象的生命周期，通过 napi_create_reference 创建的对象需要用户手动调用 napi_delete_reference 释放，否则可能造成内存泄漏。

**使用案例1：保存 napi_value**

通过 napi_define_class 创建一个 constructor 并保存下来，后续可以通过保存的 constructor 调用 napi_new_instance 来创建实例。但是，如果 constructor 是以 napi_value 的形式保存下来，一旦超过了 native 方法的 scope，这个 constructor 就会被析构，后续再使用就会造成野指针。推荐写法如下：
* 1、开发者可以改用 napi_ref 的形式把 constructor 保存下来；
* 2、由开发者自己管理 constructor 对象的生命周期，不受 native 方法的 scope 限制。
```cpp
// 1、开发者可以改用 napi_ref 的形式把 constructor 保存下来
static napi_value TestDefineClass(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value result, return_value;

  napi_property_descriptor property_descriptor = {
    "TestDefineClass",
    NULL,
    TestDefineClass,
    NULL,
    NULL,
    NULL,
    napi_enumerable | napi_static,
    NULL};

  NODE_API_CALL(env, napi_create_object(env, &return_value));

  status = napi_define_class(NULL, "TrackedFunction", NAPI_AUTO_LENGTH, TestDefineClass, NULL, 1, &property_descriptor,&result);
  SaveConstructor(env, result);
  ...
}
```
```cpp
// 2、由开发者自己管理 constructor 对象的生命周期
napi_status SaveConstructor(napi_env env, napi_value constructor) {
    return napi_create_reference(env, constructor, 1, &g_constructor);
};

napi_status GetConstructor(napi_env env) {
    napi_value constructor;
    if ( g_constructor == NULL ){
      return napi_generic_failure;
    }
    return napi_get_reference_value(env, g_constructor, &constructor);
};
```

**使用案例2：napi_wrap**

开发者使用 napi_wrap 接口，可以将 native 对象和 js 对象绑定，当 js 对象被 GC 回收时，需要通过回调函数对 native 对象的资源进行清理。napi_wrap 接口本质上也是创建了一个 napi_ref，开发者可以根据业务需要，选择由系统来管理创建的 napi_ref，或是自行释放创建的 napi_ref。
```cpp
// 用法1：napi_wrap不需要接收创建的napi_ref，最后一个参数传递nullptr，创建的napi_ref由系统管理，不需要用户手动释放
napi_wrap(env, jsobject, nativeObject, cb, nullptr, nullptr);

// 用法2：napi_wrap需要接收创建的napi_ref，最后一个参数不为nullptr，返回的napi_ref需要用户手动释放，否则会内存泄漏
napi_ref result;
napi_wrap(env, jsobject, nativeObject, cb, nullptr, &result);
// 当jsobject和result后续不再使用时，及时调用napi_remove_wrap释放result
napi_remove_wrap(env, jsobject, &result);
```

## 跨语言调用开销

### 接口调用

跨语言调用是指在一个程序中使用多种编程语言编写的代码，并且这些代码可以相互调用和交互，ArkTS 调用 C++ 就是一种跨语言调用的方式。使用 N-API 进行函数调用会引入一定的开销，因为需要进行上下文切换、参数传递、函数调用和返回值处理等，这些过程都涉及到一些性能开销。目前，通过 N-API 接口实现 ArkTS 调用 C++ 的场景大致分为三类：ArkTS 直接调用 C++ 接口、ArkTS 监听 C++ 接口以及 ArkTS 接收 C++ 回调。频繁的跨语言接口调用可能会影响业务性能，因此需要开发者合理的设计接口调用频率。 

### 数值转换

使用 N-API 进行 ArkTS 与 C++ 之间的数据转换，有如下建议： 
* 减少数据转换次数：频繁的数据转换可能会导致性能下降，可以通过批量处理数据或者使用更高效的数据结构来优化性能；
* 避免不必要的数据复制：在进行数据转换时，可以使用 N-API 提供的接口来直接访问原始数据，而不是创建新的数据副本；
* 使用缓存：如果某些数据在多次转换中都会被使用到，可以考虑使用缓存来避免重复的数据转换。缓存可以减少不必要的计算，提高性能。

## 异步操作
对于IO、CPU密集型任务需要异步处理， 否则会造成主线程的阻塞。N-API 支持异步能力，允许应用程序在执行某个耗时任务时不会被阻塞，而是继续执行其他任务。当异步操作完成时，应用程序会收到通知，并可以处理异步操作的结果。 

### 异步示例

开发者可以通过如下示例将耗时任务用异步方式实现，大概逻辑包括以下三步： 
* 用 napi_create_promise 接口创建 promise，将创建一个 deferred 对象并与 promise 一起返回，deferred 对象会绑定到已创建的 promise；
* 执行耗时任务，并将执行结果传递给 promise；
* 使用 napi_resolve_deferred 或 napi_reject_deffered 接口来 resolve 或 reject 创建的 promise，并释放 deferred 对象。此处不建议执行耗时操作，否则会阻塞主线程，导致丢帧等问题。  

```cpp
// 在executeCB、completeCB之间传递数据
struct AddonData {
    napi_async_work asyncWork = nullptr;
    napi_deferred deferred = nullptr;
    napi_ref callback = nullptr;

    double args[2] = {0};
    double result = 0;
};

// 2、执行耗时任务，并将执行结果传递给 promise；
static void addExecuteCB(napi_env env, void *data) {
    AddonData *addonData = (AddonData *)data;
    addonData->result = addonData->args[0] + addonData->args[1];
};

// 3、使用 napi_resolve_deferred 或 napi_reject_deffered 接口来 resolve 或 reject 创建的 promise，并释放 deferred 对象。此处不建议执行耗时操作，否则会阻塞主线程，导致丢帧等问题。  
static void addPromiseCompleteCB(napi_env env, napi_status status, void *data) {
    AddonData *addonData = (AddonData *)data;
    napi_value result = nullptr;
    napi_create_double(env, addonData->result, &result);
    napi_resolve_deferred(env, addonData->deferred, result);

    if (addonData->callback != nullptr) {
        napi_delete_reference(env, addonData->callback);
    }

    // 删除异步 work
    napi_delete_async_work(env, addonData->asyncWork);
    delete addonData;
    addonData = nullptr;
};

// 1、用 napi_create_promise 接口创建 promise，将创建一个 deferred 对象并与 promise 一起返回，deferred
// 对象会绑定到已创建的 promise；
static napi_value addPromise(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_value thisArg = nullptr;
    napi_get_cb_info(env, info, &argc, args, &thisArg, nullptr);

    napi_valuetype valuetype0;
    napi_typeof(env, args[0], &valuetype0);
    napi_valuetype valuetype1;
    napi_typeof(env, args[1], &valuetype1);
    if (valuetype0 != napi_number || valuetype1 != napi_number) {
        napi_throw_type_error(env, nullptr, "Wrong arguments. 2 numbers expected.");
        return NULL;
    }

    napi_value promise = nullptr;
    napi_deferred deferred = nullptr;
    napi_create_promise(env, &deferred, &promise);

    // 异步工作项上下文用户数据，传递到异步工作项的execute、complete之间传递数据
    auto addonData = new AddonData{
        .asyncWork = nullptr,
        .deferred = deferred,
    };

    napi_get_value_double(env, args[0], &addonData->args[0]);
    napi_get_value_double(env, args[1], &addonData->args[1]);

    // 创建async work，创建成功后通过最后一个参数(addonData->asyncWork)返回async work的handle
    napi_value resourceName = nullptr;
    napi_create_string_utf8(env, "addAsyncCallback", NAPI_AUTO_LENGTH, &resourceName);
    napi_create_async_work(env, nullptr, resourceName, addExecuteCB, addPromiseCompleteCB, (void *)addonData,
                           &addonData->asyncWork);

    // 将刚创建的async work加到队列，由底层去调度执行
    napi_queue_async_work(env, addonData->asyncWork);

    return promise;
}
```

在异步操作完成后，回调函数将被调用，并将结果传递给 Promise 对象。在 JavaScript 中，可以使用 Promise 对象的 then() 方法来处理异步操作的结果。then() 方法中不建议执行耗时操作，否则会阻塞主线程，导致丢帧等问题。   

```js
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

@Entry
@Component
struct TestAdd {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text("hello world")
        .onClick(() => {
          let num1 = 2;
          let num2 = 3;
          testNapi.addPromise(num1, num2).then((result) => {
            hilog.info(0x0000, 'testTag', '%{public}d', result);
          })
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### 指定异步任务调度优先级

Function Flow 编程模型（[Function Flow Runtime，FFRT](https://gitcode.com/openharmony/resourceschedule_ffrt/blob/master/docs/ffrt-development-guideline.md)）是一种基于任务和数据驱动的并发编程模型，允许开发者通过任务及其依赖关系描述的方式进行应用开发。方舟 ArkTS 运行时提供了扩展 qos 信息的接口，支持传入 qos，并调用 FFRT，根据系统资源使用情况降低功耗、提升性能。 

* 接口示例：napi_status napi_queue_async_work_with_qos(napi_env env, napi_async_work work, napi_qos_t qos)（） 
  * [in] env:调用API的环境；
  * [in] napi_async_work: 异步任务；
  * [in] napi_qos_t: qos 等级；

* qos 等级定义：
```cpp
typedef enum {
    napi_qos_background = 0,
    napi_qos_utility = 1,
    napi_qos_default = 2,
    napi_qos_user_initiated = 3,
} napi_qos_t;
```

* N-API 层封装了对外的接口，对接 libuv 层 uv_queue_work_with_qos(uv_loop_t* loop, uv_work_t* req, uv_work_cb work_cb, uv_after_work_cb after_work_cb, uv_qos_t qos) 函数。

* 相较于已有接口 napi_queue_async_work，增加了 qos 等级，用于控制任务调度的优先级。使用示例：
```cpp
static void PromiseOnExec(napi_env env, void *data) { 
    OH_LOG_INFO(LOG_APP, "PromiseOnExec"); 
}

static void PromiseOnComplete(napi_env env, napi_status status, void *data) {
    int number = *((int *)data);
    OH_LOG_INFO(LOG_APP, "PromiseOnComplete number = %{public}d", number);
}

static napi_value Test(napi_env env, napi_callback_info info) {
    napi_value resourceName = nullptr;
    napi_create_string_utf8(env, "TestExample", NAPI_AUTO_LENGTH, &resourceName);
    napi_async_work async_work;
    int *data = new int(10);
    napi_create_async_work(env, nullptr, resourceName, PromiseOnExec, PromiseOnComplete, data, &async_work);
    napi_queue_async_work_with_qos(env, async_work, napi_qos_default);
    return nullptr;
}
```

## 线程安全

如果应用需要进行大量的计算或者 IO 操作，使用并发机制可以充分利用多核 CPU 的优势，提高应用的处理效率。例如，图像处理、视频编码、数据分析等应用可以使用并发机制来提高处理速度。 

虽然 N-API 本身不支持多线程并发操作，但是可以在多线程环境下进行一些数据交互，且需要格外注意线程安全。在多线程环境下，开发者可以使用 napi_create_threadsafe_function 函数创建一个线程安全函数，然后在任意线程中调用。**应用场景**：当 native 侧有其他线程，并且需要根据这些线程的完成结果调用 JavaScript 函数时，这些线程必须与 native 侧的主线程进行通信，才能在主线程中调用 JavaScript 函数。线程安全函数便提供了一种简化方法，避免了线程间通讯，同时可以回到主线程调用 JavaScript 函数。 

### 使用方法

**ArkTS 侧传入回调函数**

```JS
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            testNapi.threadSafeTest((value) => {
              hilog.info(0x0000, 'testTag', 'js callback value = ' + value);
            })
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

**native 侧主线程中创建线程安全函数**

```cpp
napi_ref cbObj = nullptr;
static void CallJs(napi_env env, napi_value js_cb, void *context, void *data) {

    std::thread::id this_id = std::this_thread::get_id();
    OH_LOG_INFO(LOG_APP, "thread CallJs %{public}d.\n", this_id);
    napi_status status;

    status = napi_get_reference_value(env, cbObj, &js_cb);

    napi_valuetype valueType = napi_undefined;
    napi_typeof(env, js_cb, &valueType);
    OH_LOG_INFO(LOG_APP, "CallJs js_cb is napi_function: %{public}d", valueType == napi_function);

    OH_LOG_INFO(LOG_APP, "CallJs 0");
    if (env != NULL) {
        napi_value undefined, js_the_prime;
        status = napi_create_int32(env, 666, &js_the_prime);
        OH_LOG_INFO(LOG_APP, "CallJs 1: %{public}d", status == napi_ok);
        status = napi_get_undefined(env, &undefined);
        OH_LOG_INFO(LOG_APP, "CallJs 2: %{public}d", status == napi_ok);

        napi_value ret;

        status = napi_call_function(env, undefined, js_cb, 1, &js_the_prime, &ret);
        OH_LOG_INFO(LOG_APP, "CallJs 3: %{public}d", status == napi_ok);
    }
}

napi_threadsafe_function tsfn;

static napi_value ThreadSafeTest(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value js_cb, work_name;
    napi_status status;

    status = napi_get_cb_info(env, info, &argc, &js_cb, NULL, NULL);
    OH_LOG_INFO(LOG_APP, "ThreadSafeTest 0: %{public}d", status == napi_ok);

    status = napi_create_reference(env, js_cb, 1, &cbObj);
    OH_LOG_INFO(LOG_APP, "napi_create_reference of js_cb to cbObj: %{public}d", status == napi_ok);

    status =
        napi_create_string_utf8(env, "Node-API Thread-safe Call from Async Work Item", NAPI_AUTO_LENGTH, &work_name);
    OH_LOG_INFO(LOG_APP, "ThreadSafeTest 1: %{public}d", status == napi_ok);

    std::thread::id this_id = std::this_thread::get_id();
    OH_LOG_INFO(LOG_APP, "thread ThreadSafeTest %{public}d.\n", this_id);

    napi_valuetype valueType = napi_undefined;
    napi_typeof(env, js_cb, &valueType);
    OH_LOG_INFO(LOG_APP, "ThreadSafeTest js_cb is napi_function: %{public}d", valueType == napi_function);

    status = napi_create_threadsafe_function(env, js_cb, NULL, work_name, 0, 1, NULL, NULL, NULL, CallJs, &tsfn);
    OH_LOG_INFO(LOG_APP, "ThreadSafeTest 2: %{public}d", status == napi_ok);
}
```

**其他线程中调用线程安全函数**

```cpp

std::thread t([]() {
    std::thread::id this_id = std::this_thread::get_id();
    OH_LOG_INFO(LOG_APP, "thread0 %{public}d.\n", this_id);
    napi_status status;
    status = napi_acquire_threadsafe_function(tsfn);
    if (status != napi_ok) {
      OH_LOG_ERROR(LOG_APP, "thread1 failed to acquire threadsafe function! Status: %{public}d", status);
    } else {
      OH_LOG_INFO(LOG_APP, "thread1 Successfully acquired threadsafe function");
    }
    status = napi_call_threadsafe_function(tsfn, NULL, napi_tsfn_blocking);
    if (status != napi_ok) {
      OH_LOG_ERROR(LOG_APP, "thread2 failed to call threadsafe function! Status: %{public}d", status);
    } else {
      OH_LOG_INFO(LOG_APP, "thread2 Successfully called threadsafe function");
    }
});
t.detach();
```

### 线程函数使用注意事项
在多线程环境下，需要避免使用共享的数据结构和全局变量，以免竞争和冲突。同时，需要确保线程之间的同步和互斥，以避免数据不一致的情况发生。除此之外，仍需注意： 
* 对线程安全函数的调用是异步进行的，对 JavaScript 回调的调用将被放置在任务队列中；
* 创建 napi_threadsafe_function 时，可以提供 napi_finalize 回调。当线程安全函数即将被销毁时，将在主线程上调用此 napi_finalize 回调；
* 在调用 napi_create_threadsafe_function 时给定了上下文，可以从任何调用 napi_get_threadafe_function_context 的线程中获取。