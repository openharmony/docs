# libuv



## Introduction



[libuv](http://libuv.org/) is a cross-platform library that implements asynchronous I/O based on event loops. It applies to network programming and file system operations. It is one of the core libraries of Node.js and has been widely used by other software projects.

## Supported Capabilities



- Event-driven asynchronous I/O across platforms.

- Support for standard library interfaces.

## Available APIs

For details, see [API documentation](http://docs.libuv.org/en/v1.x/api.html).


## Relationship Between libuv and OpenHarmony

### Background

OpenHarmony introduced Node-API of Node.js in its earlier versions to facilitate Node.js developers to extend their JavaScript APIs with OpenHarmony. It also introduced libuv of Node.js to implement event loops.

### Evolution Trend

To address the scheduling issues caused when the application main thread has an event loop that contains **uvloop**, we plan to normalize the event loops in the application model to allow only one task queue in the application main loop with task priorities controlled.

Avoid using the NDK of libuv to perform operations on the application main loop obtained by **napi_get_uv_event_loop** (deprecated in API version 12). This may cause various problems and large amount of workload to address compatibility issues.

If you want to implement interaction with the main thread cyclically, for example, inserting a task, use [APIs provided by Node-API](../../napi/napi-data-types-interfaces.md).

OpenHarmony will continue to provide capabilities of interacting with the main thread and extending JS APIs through Node-API for a long period of time, but shields the event loops used in the implementation layer. Although **napi_get_uv_event_loop** is deprecated in API version 12, the main functional APIs of Node-API will be maintained for a long time and provide the same native behavior of Node-API, so that the developers who are familiar with the node.js extension mechanism can easily expand their code to OpenHarmony.

The NDK of libuv will still be available for a long period of time. If you are familiar with libuv and can handle memory management and multithreading problems, you can use libuv to develop your services on OpenHarmony. Unless otherwise required, you do not need to import the libuv library to your application project.

### Current Problems and Solutions

Only one event loop can exist in a thread. To ensure proper running of the main event loop of the system application, the main event loop listens for the FD events in the JS environment and executes uv_run only when an FD event is reported.

As a result, certain functions that depend on **uvloop** cannot take effect. Common scenarios and solutions are as follows:

The APIs related to the libuv NDK timer do not work as expected in the application main loop of the current system, and may cause freezing or loss of frames. You are advised not to directly use the libuv NDK APIs on the JS main thread. Instead, use Node-API to implement related functions.

#### Scenario 1: The JS main thread throws an async task to a worker thread for execution, and executes the result returned by the JS code.

**Example (incorrect)**

Call **napi_get_uv_event_loop()** to obtain the system loop, and use libuv NDK APIs to implement related functions.

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
    /* Obtain the uv_loop of the application JS main thread. */
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


**Example (correct)**:

Use **napi_create_async_work** and **napi_queue_async_work** together.


```cpp
static napi_value Add(napi_env env, napi_callback_info info)
{
    napi_value work_name;
    napi_create_string_utf8(env, "ohos", NAPI_AUTO_LENGTH, &work_name);
    /* The fourth parameter specifies the work task of the asynchronous thread, and the fifth parameter is the callback of the main thread. */
    napi_create_async_work(env, nullptr, work_name, [](napi_env, void *){
        OH_LOG_INFO(LOG_APP, "ohos in execute, %{public}d\n");
    }, [](napi_env env, napi_status status, void *data){
        /* The specific implementation is skipped. */
        napi_delete_async_work(env, work);
    }, nullptr, &work);

    /* Call napi_queue_async_work to trigger an async task. */
    napi_queue_async_work(env, work);
    return 0;
}

```

#### Scenario 2: The timer does not take effect when the timer task is executed on the native side.

**Example (incorrect)**

The timer started in the following example does not take effect in the application main loop. **uv_timer** depends on the uv running in uv_RUN_DEFAULT mode. However, the application main loop listens for the FD of uv_loop and executes **uv_run** only when an FD event is reported. The FE event will not trigger the timer. As a result, the timer cannot be executed in the JS main thread.


```cpp
static void timer_handle(uv_timer_t *req) {
    OH_LOG_INFO(LOG_APP, "ohos timer print!");
    uv_timer_stop(req);
    delete req;
}
static napi_value Add(napi_env env, napi_callback_info info)
{
    uv_loop_s *loop = nullptr;
    /* Obtain uv_loop in the main thread of the application. */
    napi_get_uv_event_loop(env, &loop);
    uv_timer_t *timer = new uv_timer_t;
    /* Initialize a timer. */
    uv_timer_init(loop, timer);
    /* Start the timer. */
    uv_timer_start(timer, timer_handle, 0, 0);
    return 0;
}

```

Modify the code as follows:

Create a loop in a new thread. Create a timer, and execute **napi_call_threadsafe_function** in the timer callback. This function allows the JS code to be executed in the main thread.

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

// Define a callback function jsCallback, which contains parameters env, js_cb, context, and data.
static void jsCallback(napi_env env, napi_value js_cb, void *context, void *data) {
   napi_value undefined;
   napi_value argv;
   napi_value ret;

   std::thread::id this_id = std::this_thread::get_id();
   OH_LOG_INFO(LOG_APP, "ohos js call back id: %{public}d
", this_id);
   struct AppData *appdata = reinterpret_cast<struct AppData *>(data); 
   napi_create_int32(env, appdata->id, &argv);
   // Call the js_cb function with the parameter argv. The return value is ret.
   napi_call_function(env, undefined, js_cb, 1, &argv, &ret);
}

napi_threadsafe_function tsfn = nullptr;

napi_value jsCb;

// Define a timer processing function. When the timer expires, print logs and call the thread-safe function.
static void timer_handle(uv_timer_t *req) {
   OH_LOG_INFO(LOG_APP, "ohos timer print!");
   struct AppData *data = &appdata;
   data->id = 100;
   napi_acquire_threadsafe_function(tsfn); // Obtain the thread-safe function.
   napi_call_threadsafe_function(tsfn, data, napi_tsfn_blocking); // Call the thread-safe function.
   uv_timer_stop(req);
   delete req;
}

// Implementation of StartTimerTest in the JS code.
static napi_value StartTimerTest(napi_env env, napi_callback_info info)
{
   std::thread::id this_id = std::this_thread::get_id();
   OH_LOG_INFO(LOG_APP, "ohos  thread id: %{public}d
", this_id);
   size_t argc = 1;
   napi_value workBName;
   
   napi_create_string_utf8(env, "test", NAPI_AUTO_LENGTH, &workBName);
   napi_get_cb_info(env, info, &argc, &jsCb, nullptr, nullptr);

   // Create a thread-safe function. When the function is called, jsCallback will be executed in a new thread.
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


## Cases

[Cause of Incorrect Triggering Time of the Timer Callback in the Main Thread of libuv](https://gitee.com/openharmony/third_party_libuv/wikis/06-Wiki-%E6%8A%80%E6%9C%AF%E8%B5%84%E6%BA%90/libuv%E4%B8%AD%E4%B8%BB%E7%BA%BF%E7%A8%8Btimer%E5%9B%9E%E8%B0%83%E4%BA%8B%E4%BB%B6%E8%A7%A6%E5%8F%91%E6%97%B6%E9%97%B4%E4%B8%8D%E6%AD%A3%E7%A1%AE%E5%8E%9F%E5%9B%A0)

[Incorporating libuv Worker Threads to the FFRT](https://gitee.com/openharmony/third_party_libuv/wikis/06-Wiki-%E6%8A%80%E6%9C%AF%E8%B5%84%E6%BA%90/%20libuv%E5%B7%A5%E4%BD%9C%E7%BA%BF%E7%A8%8B%E6%8E%A5%E5%85%A5FFRT%E6%96%B9%E6%A1%88%E5%88%86%E6%9E%90)

[FAQs for QoS-Aware libuv and Node-API Async API Improvements](https://gitee.com/openharmony/third_party_libuv/wikis/06-Wiki-%E6%8A%80%E6%9C%AF%E8%B5%84%E6%BA%90/QoS%E6%84%9F%E7%9F%A5%E7%9A%84libuv%E3%80%81napi%E5%BC%82%E6%AD%A5%E6%8E%A5%E5%8F%A3%E6%95%B4%E6%94%B9FAQ)
