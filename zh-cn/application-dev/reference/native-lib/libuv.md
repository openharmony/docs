# libuv



## 简介



[libuv](http://libuv.org/)是一个跨平台库，基于事件驱动来实现异步I/O，适用于网络编程和文件系统操作。它是Node.js的核心库之一，也被其他语言的开发者广泛使用。

## 支持的能力



[libuv](http://libuv.org/)实现了跨平台的基于事件驱动的异步I/O。

支持标准库接口。

## 接口列表

[libuv支持的API文档](http://docs.libuv.org/en/v1.x/api.html)。


## libuv和OpenHarmony的关系

### 背景

在OpenHarmony的早期版本中，为了兼容node的生态，将node的napi引入到系统中，方便node开发者快速接入OpenHarmony，扩展自己的js接口。同时引入了node的事件循环实现库libuv。

### 演进方向

随着 OpenHarmony 的逐步完善，我们计划在未来的版本中，逐步将应用模型中的事件循环归一，并增强 OpenHarmony 自身的事件循环，以解决许多双 loop 机制下的调度问题，并为开发者提供更加完善的任务优先级、插队等与任务主循环交互的方法。

开发者应尽可能避免在 napi_get_uv_event_loop 接口(将在 API12标记废弃)获取的应用主 loop 上使用 libuv 的 ndk 进行操作，因为这可能会带来各种问题，并给未来的兼容性变更带来大量的工作量。

如果开发者希望跟主线程事件循环交互，比如插入任务等，应当使用[napi提供的接口](../../napi/napi-data-types-interfaces.md)。

OpenHarmony还将长期通过napi来为开发者提供和主线程交互及扩展js接口的能力，但会屏蔽实现层使用的事件循环。尽管我们在api12中给napi_get_uv_event_loop接口标记了废弃。但napi的主要功能接口将会长期维护，并保证与node的原生行为一致，来保证熟悉nodejs的扩展机制的开发者方便地将自己的已有代码接入到OpnHarmony中来。

当然，libuv 的 ndk 短期内不会下架，如果您对 libuv 非常熟悉，并自信能够处理好所有的内存管理和多线程问题，您仍可以像使用原生 libuv 一样，自己启动线程，并在上面使用 libuv 完成自己的业务。在没有特殊版本要求的情况下，您不需要额外引入 libuv 库到您的应用工程中。

### 当前问题和解决方案

众所周知，一个线程上只能存在一个事件循环，为了适配系统应用的主事件循环，在主线程上的js环境中，uvloop中的事件处理是由主事件循环监听其fd，来触发一次uv_run来驱动的。

因此部分依赖uvloop始终循环的功能无法生效，比较常用的场景和解决方案有：

**libuv NDK定时器相关的接口在当前系统的应用主循环中无法生效，并且可能会导致卡顿掉帧的现象。因此不建议直接在JS主线程上使用libuv NDK接口，开发者可通过直接调用napi接口来实现相关功能。**

#### 场景一、在JS主线程抛异步任务到工作线程执行，在主线程中执行JS代码处理返回结果。

**错误示例：**

在native层直接通过调用napi_get_uv_event_loop接口获取系统loop，调用libuv NDK接口实现相关功能。

```cpp
static void execute(uv_work_t *work) {
    OH_LOG_INFO(LOG_APP, "ohos in execute");
}

static void complete(uv_work_t *work, int status) {
    OH_LOG_INFO(LOG_APP, "ohos in complete"); 
    delete(work);
}
static napi_value Add(napi_env env, napi_callback_info info)
{
    napi_value work_name;
    uv_loop_s *loop = nullptr;
    /* 获取应用js主线程的uv_loop */
    napi_get_uv_event_loop(env, &loop);
    uv_work_t *work = new uv_work_t;
    int ret = uv_queue_work(loop, work, execute, complete);
    if (ret != 0) {
        OH_LOG_INFO(LOG_APP, "delete work");
        delete work;
    }
    return 0;
}

```


**正确示例：**

可通过napi_create_async_work、napi_queue_async_work搭配使用。


```cpp
static napi_value Add(napi_env env, napi_callback_info info)
{
    napi_value work_name;
    napi_create_string_utf8(env, "ohos", NAPI_AUTO_LENGTH, &work_name);
    /* 第四个参数是异步线程的work任务，第五个参数为主线程的回调 */
    napi_create_async_work(env, nullptr, work_name, [](napi_env, void *){
        OH_LOG_INFO(LOG_APP, "ohos in execute, %{public}d\n");
    }, [](napi_env env, napi_status status, void *data){
        /* 不关心具体实现 */
        napi_delete_async_work(env, work);
    }, nullptr, &work);

    /* 通过napi_queue_async_work触发异步任务执行 */
    napi_queue_async_work(env, work);
    return 0;
}

```

#### 场景二、在native侧执行定时器任务，定时器不生效

**错误示例：**

通过下面示例启动的定时器，在应用主循环中是不生效的。这是因为uv_timer的正常工作是依赖uv以UV_RUN_DEFAULT运行的时候得到保证的，而当前应用主循环监听了uv_loop的fd，当触发fd事件的时候，只执行一次uv_run，而timer是不会通过触发fd事件生效的。最终导致timer无法在JS主线程中正常执行。


```cpp
static void timer_handle(uv_timer_t *req) {
    OH_LOG_INFO(LOG_APP, "ohos timer print!");
    uv_timer_stop(req);
    delete req;
}
static napi_value Add(napi_env env, napi_callback_info info)
{
    uv_loop_s *loop = nullptr;
    /* 获取应用主线程上的uv_loop */
    napi_get_uv_event_loop(env, &loop);
    uv_timer_t *timer = new uv_timer_t;
    /* 初始化定时器 */
    uv_timer_init(loop, timer);
    /* 启动定时器 */
    uv_timer_start(timer, timer_handle, 0, 0);
    return 0;
}

```

**推荐写法：**

新起一个线程创建loop环境，然后创建timer，在timer回调中执行napi_call_threadsafe_function。该函数可以在主线程中执行JS代码。

```cpp
#include "napi/native_api.h"
#include <unistd.h>
#include "uv.h"
#include "hilog/log.h"
#include <thread>
#define LOG_TAG "MyTag"
#define LOG_DOMAIN 0X0202

struct AppData {
   int32_t id = {0x00};
};

struct AppData appdata = {12345};

// 定义一个回调函数jsCallback，参数包括环境env，回调函数js_cb，上下文context，数据data
static void jsCallback(napi_env env, napi_value js_cb, void *context, void *data) {
   napi_value undefined;
   napi_value argv;
   napi_value ret;

   std::thread::id this_id = std::this_thread::get_id();
   OH_LOG_INFO(LOG_APP, "ohos js call back id: %{public}d
", this_id);
   struct AppData *appdata = reinterpret_cast<struct AppData *>(data); 
   napi_create_int32(env, appdata->id, &argv);
   // 调用js_cb函数，参数为argv，返回值为ret
   napi_call_function(env, undefined, js_cb, 1, &argv, &ret);
}

napi_threadsafe_function tsfn = nullptr;

napi_value jsCb;

// 定义一个定时器处理函数，当定时器到时时，打印日志并调用线程安全函数
static void timer_handle(uv_timer_t *req) {
   OH_LOG_INFO(LOG_APP, "ohos timer print!");
   struct AppData *data = &appdata;
   data->id = 100;
   napi_acquire_threadsafe_function(tsfn);  // 获取线程安全函数
   napi_call_threadsafe_function(tsfn, data, napi_tsfn_blocking);  // 调用线程安全函数
   uv_timer_stop(req);
   delete req;
}

// StartTimerTest对应JS代码中的接口实现
static napi_value StartTimerTest(napi_env env, napi_callback_info info)
{
   std::thread::id this_id = std::this_thread::get_id();
   OH_LOG_INFO(LOG_APP, "ohos  thread id: %{public}d
", this_id);
   size_t argc = 1;
   napi_value workBName;
   
   napi_create_string_utf8(env, "test", NAPI_AUTO_LENGTH, &workBName);
   napi_get_cb_info(env, info, &argc, &jsCb, nullptr, nullptr);

   // 创建一个线程安全函数，当函数被调用时，会在新的线程中执行jsCallback函数
   napi_create_threadsafe_function(env, jsCb, nullptr, workBName, 0, 1, nullptr, nullptr, nullptr, jsCallback, &tsfn);

   std::thread mythread([]() {
       std::thread::id this_id = std::this_thread::get_id();
       OH_LOG_INFO(LOG_APP, " my thread is %{public}d", this_id);
       uv_loop_t *loop = uv_loop_new();
       uv_timer_t *timer = new uv_timer_t;
       uv_timer_init(loop, timer);
       uv_timer_start(timer, timer_handle, 0, 0);
       uv_run(loop, UV_RUN_DEFAULT);
       uv_loop_delete(loop);
   });
   mythread.detach();
   return 0;
}

```


## 技术案例

[libuv中主线程timer回调事件触发时间不正确原因](https://gitee.com/openharmony/third_party_libuv/wikis/06-Wiki-%E6%8A%80%E6%9C%AF%E8%B5%84%E6%BA%90/libuv%E4%B8%AD%E4%B8%BB%E7%BA%BF%E7%A8%8Btimer%E5%9B%9E%E8%B0%83%E4%BA%8B%E4%BB%B6%E8%A7%A6%E5%8F%91%E6%97%B6%E9%97%B4%E4%B8%8D%E6%AD%A3%E7%A1%AE%E5%8E%9F%E5%9B%A0)

[libuv工作线程接入FFRT方案分析](https://gitee.com/openharmony/third_party_libuv/wikis/06-Wiki-%E6%8A%80%E6%9C%AF%E8%B5%84%E6%BA%90/%20libuv%E5%B7%A5%E4%BD%9C%E7%BA%BF%E7%A8%8B%E6%8E%A5%E5%85%A5FFRT%E6%96%B9%E6%A1%88%E5%88%86%E6%9E%90)

[QoS感知的libuv、napi异步接口整改FAQ](https://gitee.com/openharmony/third_party_libuv/wikis/06-Wiki-%E6%8A%80%E6%9C%AF%E8%B5%84%E6%BA%90/QoS%E6%84%9F%E7%9F%A5%E7%9A%84libuv%E3%80%81napi%E5%BC%82%E6%AD%A5%E6%8E%A5%E5%8F%A3%E6%95%B4%E6%94%B9FAQ)