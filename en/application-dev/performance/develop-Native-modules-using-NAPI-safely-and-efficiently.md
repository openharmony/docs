# Secure and Efficient N-API Development

## Introduction

N-API, short for Node.js Addon Programming Interface, is a set of C++ APIs provided by Node.js. Shipped with the capabilities of the [V8 engine](https://v8.dev/docs), it is used to build Node.js native addons. By drawing on N-API, you can write high-performance Node.js modules in C++ while maintaining compatibility with Node.js.

N-API provided in [ArkCompiler ArkTS runtime](https://gitee.com/openharmony/arkcompiler_ets_runtime), shipped with the capabilities of the Ark engine, provides the same basic functionality as described in the [Node.js documentation](https://nodejs.org/api/n-api.html).

This document is intended to provide guidance on secure and efficient N-API development. Designed with carefully curated use cases, it is structured into four parts: object lifetime management, cross-language invocation overhead, asynchronous operation, and thread security.

## Object Lifetime Management

As N-API calls are made, handles to objects in the VM heap may be returned as **napi_value**s. These handles control the lifetime of the objects. Object handles are associated with a scope. The default lifespan of the scope is tied to the lifespan of the native method. In some real-world cases, however, an object may require a scope with a shorter or longer lifespan than that of the native method. This section describes how to use N-API functions to change the object lifespan.

### Shortening Object Lifespan

You can use **napi_open_handle_scope** and **napi_close_handle_scope** to manage the lifetime of **napi_value**, so as to minimize the object lifespan and avoid memory leak.

For example, consider a method that has a **for** loop, which iterates through the elements in a large array:
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

In this case, a large number of handles may be created, consuming substantial resources. To handle this case, N-API provides the function to establish a new scope to which newly created handles will be associated. Once those handles are no longer needed, the scope can be closed and any handles associated with the scope are invalidated.

* The methods available to open and close scopes are **napi_open_handle_scope** and **napi_close_handle_scope**, respectively.
* N-API only supports a single nested hierarchy of scopes. There is only one active scope at any time, and all new handles will be associated with that scope while it is active.
* Scopes must be closed in the reverse order from which they are opened. In addition, all scopes created within a native method must be closed before returning from that method.

The following is an optimization based on the earlier example. In this example, at most a single handle is valid throughout the execution of the loop.
```cpp
// When N-API is frequently called to create JS objects in the for loop, add handle_scope to release in a timely manner resources that are no longer used.
// In the following code, the lifespan of the local variable res ends at the end of each loop. Therefore, a scope is added to release the JS object in time to prevent memory leak.
for (int i = 0; i < 1000000; i++) {
    napi_handle_scope scope;
    napi_status status = napi_open_handle_scope(env, &scope);
    if (status != napi_ok) {
        break;
    }
    napi_value result;
    status = napi_get_element(env, object, i, &result);
    if (status != napi_ok) {
        break;
    }
    // do something with element
    status = napi_close_handle_scope(env, scope);
    if (status != napi_ok) {
        break;
    }
}
```
There are cases where a handle from a scope needs to outlive the scope, for example, in nested loop scenarios. For this purpose, you can use **napi_open_escapable_handle_scope** and **napi_close_escapable_handle_scope** to open and close an escapable scope, where the lifespan of the defined handle is the same as that of the outer scope.

### Extending Object Lifespan

You can extend the lifespan of an **napi_value** object, by creating an **napi_ref** reference to a **napi_value** object. All **napi_ref** references, created by calling **napi_create_reference**, must be deleted manually by calling **napi_delete_reference**. Failure to delete a reference may results in memory leak.

#### Use Case 1: Saving napi_value

Use **napi_define_class** to create a constructor and save it. You can use the saved constructor to call **napi_new_instance** to create an instance. However, if the constructor is saved as a **napi_value**, it will be destructed once it exceeds the scope of the native method. In this case, continuing to use the constructor will result in a wild pointer. To avoid this issue, it is recommended that you:
* Save the constructor as an **napi_ref** reference.
* Manage the lifespan of the constructor object on your own so that it is not restricted by the scope of the native method.
```cpp
// 1. Save the constructor as an napi_ref reference.
static napi_value TestDefineClass(napi_env env,
                                  napi_callback_info info) {
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

  status = napi_define_class(NULL,
                             "TrackedFunction",
                             NAPI_AUTO_LENGTH,
                             TestDefineClass,
                             NULL,
                             1,
                             &property_descriptor,
                             &result);
  SaveConstructor(env, result);
  ...
}
```
```cpp
// 2. Manage the lifespan of the constructor object on your own.
napi_status SaveConstructor(napi_env env, napi_value constructor) {
    return napi_create_reference(env, constructor, 1, &g_constructor);
};

napi_status GetConstructor(napi_env env) {
    napi_value constructor;
    return napi_get_reference_value(env, g_constructor, &constructor);
};
```

#### Use Case 2: napi_wrap

You can use **napi_wrap** to wrap a native instance in a JavaScript object. When the JavaScript object is garbage-collected, use a callback to free the native instance. In effect, the **napi_wrap** API creates an **napi_ref** reference. You can designate the system to manage the created **napi_ref** reference. Alternatively, you can release the reference manually.
```cpp
// Usage 1: napi_wrap does not need to receive the created napi_ref reference. The last parameter is nullptr. The created napi_ref reference is managed by the system and does not need to be manually released.
napi_wrap(env, jsobject, nativeObject, cb, nullptr, nullptr);

// Usage 2: napi_wrap needs to receive the created napi_ref reference. The last parameter is not nullptr. The created napi_ref reference needs to be manually released. Otherwise, memory leak occurs.
napi_ref result;
napi_wrap(env, jsobject, nativeObject, cb, nullptr, &result);
// When the JavaScript object and result are no longer used, call napi_remove_wrap to release the result in a timely manner.
napi_value result1;
napi_remove_wrap(env, jsobject, result1)
```

## Cross-Language Invocation Overhead

### API Call

Cross-language invocation is the process where code written in different programming languages calls and interacts with each other in an application. For example, ArkTS invoking C++ is one of the cross-language invocation modes. Using N-API to call functions causes certain overhead, because context switching, parameter transfer, function invoking, and return value processing are required. Currently, there are three scenarios where C++ code is called from ArkTS through N-API: call C++ APIs, listen for C++ APIs , and receive C++ callbacks. Frequent cross-language API calls may detract from service performance. Therefore, properly design the API call frequency.

### Value Conversion

When using N-API to convert data between ArkTS and C++, take note of the following:
* Reduce the number of data conversion times: Frequent data conversion may cause performance deterioration. You can process data in batches or use a more efficient data structure to optimize performance.
* Avoid unnecessary data replication: During data conversion, use N-API to directly access the original data instead of creating a new data copy.
* Use cache: If some data is used in multiple conversions, you can store it in the cache to avoid repeated data conversions. In this way, unnecessary calculations can be reduced, leading to better performance.

## Asynchronous Operations
I/O- and CPU-intensive tasks must be processed asynchronously. Otherwise, the main thread will be blocked. N-API provides the asynchronous capability, allowing an application to continue executing other tasks instead of being blocked when executing a time-consuming task. When an asynchronous operation is complete, the application receives a notification and can process the operation result.

### Example of Asynchronous Processing

You can refer to the following example to implement time-consuming tasks in asynchronous mode. The logic includes the following steps:
* Call **napi_create_promise** to create a promise. When a promise is created, a "deferred" object is created and returned alongside the promise.
* Execute the time-consuming task and pass the execution result to the promise.
* Call **napi_resolve_deferred** or **napi_reject_deferred** to resolve or reject the created promise and release the deferred object.

```cpp
// Transfer data between executeCB and completeCB.
struct AddonData {
    napi_async_work asyncWork = nullptr;
    napi_deferred deferred = nullptr;
    napi_ref callback = nullptr;

    double args[2] = {0};
    double result = 0;
};

// 2. Execute the time-consuming task and pass the execution result to the promise.
static void addExecuteCB(napi_env env, void *data) {
    AddonData *addonData = (AddonData *)data;
    addonData->result = addonData->args[0] + addonData->args[1];
};

// 3. Call napi_resolve_deferred or napi_reject_deferred to resolve or reject the created promise and release the deferred object.
static void addPromiseCompleteCB(napi_env env, napi_status status, void *data) {
    AddonData *addonData = (AddonData *)data;
    napi_value result = nullptr;
    napi_create_double(env, addonData->result, &result);
    napi_resolve_deferred(env, addonData->deferred, result);

    if (addonData->callback != nullptr) {
        napi_delete_reference(env, addonData->callback);
    }

    // Delete the asynchronous work.
    napi_delete_async_work(env, addonData->asyncWork);
    delete addonData;
    addonData = nullptr;
};

// 1. Call napi_create_promise to create a promise. When a promise is created,
// a "deferred" object is created and returned alongside the promise.
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

    // Asynchronous work context user data, which is transferred between execute and complete callbacks of the asynchronous work.
    auto addonData = new AddonData{
        .asyncWork = nullptr,
        .deferred = deferred,
    };

    napi_get_value_double(env, args[0], &addonData->args[0]);
    napi_get_value_double(env, args[1], &addonData->args[1]);

    // Create an async work. When the creation is successful, the handle to the async work is returned through the last parameter (addonData->asyncWork).
    napi_value resourceName = nullptr;
    napi_create_string_utf8(env, "addAsyncCallback", NAPI_AUTO_LENGTH, &resourceName);
    napi_create_async_work(env, nullptr, resourceName, addExecuteCB, addPromiseCompleteCB, (void *)addonData,
                           &addonData->asyncWork);

    // Add the newly created async work to the queue for the underlying layer to schedule and execute.
    napi_queue_async_work(env, addonData->asyncWork);

    return promise;
}
```

After the asynchronous operation is complete, the callback is invoked and the result is passed to the **Promise** object. In JavaScript, you can use the **then()** method of the **Promise** object to process the result of an asynchronous operation.

```js
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so'

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

### Prioritizing Asynchronous Tasks

For applications developed using [Function Flow](https://gitee.com/openharmony/resourceschedule_ffrt/blob/master/docs/user_guide.md)), a task-based and data-driven concurrent programming model, you can schedule tasks with the help of the Function Flow Runtime (FFRT). Ark ArkTS runtime provides an extension API, which you can call to invoke FFRT with the QoS information of tasks passed in. The tasks are then scheduled based on their QoS level and system resource usage for a balance between power consumption and performance.

* API example: napi_status napi_queue_async_work_with_qos(napi_env env, napi_async_work work, napi_qos_t qos) ()
  * **env**: environment for invoking the API.
  * **napi_async_work**: asynchronous task.
  * **napi_qos_t**: QoS level.

* QoS levels:
```cpp
typedef enum {
    napi_qos_background = 0,
    napi_qos_utility = 1,
    napi_qos_default = 2,
    napi_qos_user_initiated = 3,
} napi_qos_t;
```

* The N-API layer encapsulates an external API to connect to the **uv_queue_work_with_qos(uv_loop_t* loop, uv_work_t* req, uv_work_cb work_cb, uv_after_work_cb after_work_cb, uv_qos_t qos)** function at the libuv layer.

* Compared with the existing API **napi_queue_async_work**, this API adds the QoS level to specify the priority for task scheduling. Example:
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

## Thread Security

If an application needs to perform a large number of computing or I/O operations, the concurrency mechanism is handy, in that it can make full use of the multi-core CPU to improve the processing efficiency of the application. For example, applications specialized in image processing, video coding, and data analysis may use a concurrency mechanism to improve processing speeds.

Although N-API itself does not support concurrent operations with multithreading, it does allow for some data interactions in a multi-thread environment, where thread security would be a concern. In a multi-thread environment, you can use **napi_create_threadsafe_function** to create a thread-safe function and then call the function in any thread.

*Application scenario*: When there are other threads on the native side and JavaScript functions need to be called based on the completion results of these threads, these threads must communicate with the main thread on the native side so that JavaScript functions can be called in the main thread. Thread-safe functions provide a simplified way to avoid inter-thread communication and to return to the main thread to call JavaScript functions.

### How to Use

#### Passing Callback from the ArkTS Side
```JS
struct Index {
  @State message: string = 'Hello World'

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

#### Creating Thread-Safe Function in Main Thread on Native Side
```cpp
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

#### Calling Thread-Safe Functions in Other Threads
```cpp
std::thread t([]() {
    std::thread::id this_id = std::this_thread::get_id();
    OH_LOG_INFO(LOG_APP, "thread0 %{public}d.\n", this_id);
    napi_status status;
    status = napi_acquire_threadsafe_function(tsfn);
    OH_LOG_INFO(LOG_APP, "thread1 : %{public}d", status == napi_ok);
    status = napi_call_threadsafe_function(tsfn, NULL, napi_tsfn_blocking);
    OH_LOG_INFO(LOG_APP, "thread2 : %{public}d", status == napi_ok);
});
t.detach();
```

### Precautions for Using Thread Functions
In a multi-thread environment, avoid using shared data structures and global variables to avoid competition and conflicts. Ensure that threads are synchronized and mutually exclusive to avoid data inconsistency. In addition, pay attention to the following:
* The calls to thread-safe functions are asynchronous, and the calls to the JavaScript callbacks are placed in the task queue.
* When **napi_threadsafe_function** is called to create a thread-safe function, the **napi_finalize** callback can be provided. When the thread-safe function is about to be destroyed, the **napi_finalize** callback is invoked on the main thread.
* The context is given when **napi_create_threadsafe_function** is called and can be obtained from any thread that calls **napi_get_threadsafe_function_context**.
