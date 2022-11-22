# Using Native APIs in Application Projects

OpenHarmony applications use JavaScript (JS) when calling native APIs. The native APIs (NAPIs) provided by the [ace_napi](https://gitee.com/openharmony/arkui_napi/tree/master) repository are used to implement interaction with JS. Currently, the **ace_napi** repository supports some third-party **Node.js** interfaces. The names of the NAPIs are the same as those in the third-party **Node.js**. For details about the interfaces supported, see `libnapi.ndk.json` in this repository.

## How to Develop

The IDE has a default project that uses NAPIs. You can choose `File` > `New` > `Create Project` to create a `Native C++` project. The **cpp** directory is generated in the **main** directory. You can use the NAPIs provided by the **ace_napi** repository for development.

You can `import` the native .so that contains the JS processing logic. For example, `import hello from 'libhello.so'` to use the **libhello.so** capability. Then, the JS object created using the NAPI can be passed to the `hello` object of the application to call the native capability.

## Development Guidelines

### Registration

* Add **static** to the **nm_register_func** function to prevent symbol conflicts with other .so files.
* The name of the module registration entry, that is, the function decorated by **\_\_attribute\_\_((constructor))**, must be unique.

### .so Naming Rules

Each module has a .so file. For example, if the module name is `hello`, name the .so file `libhello.so`. The `nm_modname` field in `napi_module` must be `hello`, which is the same as the module name. The sample code for importing the .so file is `import hello from 'libhello.so'`.

### JS Objects and Threads

The Ark engine prevents NAPIs from being called to operate JS objects in non-JS threads. Otherwise, the application will crash. Observe the following rules:

* The NAPIs can be used only in JS threads.
* **env** is bound to a thread and cannot be used across threads. The JS object created by a NAPI can be used only in the thread, in which the object is created, that is, the JS object is bound to the **env** of the thread.

### Importing Header Files

Before using NAPI objects and methods, include **napi/native_api.h**. Otherwise, when only the third-party library header file is included, an error will be reporting, indicating that the interface cannot be found.

### napi_create_async_work

**napi_create_async_work** has two callbacks:

* **execute**: processes service logic asynchronously. This callback is not executed by a JS thread; therefore, it cannot call any NAPI. The return value of **execute** is processed by the **complete** callback.

* **complete**: calls the NAPI to encapsulate the return value of **execute** into a JS object and return it for processing. This callback is executed by a JS thread.

```c++
napi_status napi_create_async_work(napi_env env,
                                   napi_value async_resource,
                                   napi_value async_resource_name,
                                   napi_async_execute_callback execute,
                                   napi_async_complete_callback complete,
                                   void* data,
                                   napi_async_work* result)
```



## Example 1: Encapsulating Synchronous and Asynchronous APIs for the Storage Module

### Overview

This example shows how to encapsulate the synchronous and asynchronous APIs of the storage module. The storage module implements the functions of storing, obtaining, deleting, and clearing data.

### API Declaration

```typescript
import { AsyncCallback } from './basic';
declare namespace storage {
  function get(key: string, callback: AsyncCallback<string>): void;
  function get(key: string, defaultValue: string, callback: AsyncCallback<string>): void;
  function get(key: string, defaultValue?: string): Promise<string>;
  function set(key: string, value: string, callback: AsyncCallback<string>): void;
  function remove(key: string, callback: AsyncCallback<void>): void;
  function clear(callback: AsyncCallback<void>): void;
  function getSync(key: string, defaultValue?: string): string;
  function setSync(key: string, value: string): void;
  function removeSync(key: string): void;
  function clearClear(): void;
}
export default storage;
```



### Implementation

You can obtain the complete code from `sample/native_module_storage/` in the [OpenHarmony/arkui_napi](https://gitee.com/openharmony/arkui_napi/tree/master) repository.

#### Registering the Module

Register four synchronous APIs (`getSync`, `setSync`, `removeSync`, and`clearSync`) and four asynchronous APIs (`get`, `set`, `remove`, and `clear`).

```c++
/***********************************************
 * Module export and register
 ***********************************************/
static napi_value StorageExport(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        DECLARE_NAPI_FUNCTION("get", JSStorageGet),
        DECLARE_NAPI_FUNCTION("set", JSStorageSet),
        DECLARE_NAPI_FUNCTION("remove", JSStorageDelete),
        DECLARE_NAPI_FUNCTION("clear", JSStorageClear),

        DECLARE_NAPI_FUNCTION("getSync", JSStorageGetSync),
        DECLARE_NAPI_FUNCTION("setSync", JSStorageSetSync),
        DECLARE_NAPI_FUNCTION("deleteSync", JSStorageDeleteSync),
        DECLARE_NAPI_FUNCTION("clearSync", JSStorageClearSync),
    };
    NAPI_CALL(env, napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc));
    return exports;
}

// Storage module
static napi_module storage_module = {.nm_version = 1,
                                     .nm_flags = 0,
                                     .nm_filename = nullptr,
                                     .nm_register_func = StorageExport,
                                     .nm_modname = "storage",
                                     .nm_priv = ((void*)0),
                                     .reserved = {0}};

// Register the storage module
extern "C" __attribute__((constructor)) void StorageRegister()
{
    napi_module_register(&storage_module);
}
```

#### Implementing getSync

The **getSync** function registered for the storage module is **JSStorageGetSync**. Obtain data from `gKeyValueStorage`, create a string object, and return it.

```c
static napi_value JSStorageGetSync(napi_env env, napi_callback_info info)
{
    GET_PARAMS(env, info, 2);
    NAPI_ASSERT(env, argc >= 1, "requires 1 parameter");
    char key[32] = {0};
    size_t keyLen = 0;
    char value[128] = {0};
    size_t valueLen = 0;

    // Parse parameters.
    for (size_t i = 0; i < argc; i++) {
        napi_valuetype valueType;
        napi_typeof(env, argv[i], &valueType);

        if (i == 0 && valueType == napi_string) {
            napi_get_value_string_utf8(env, argv[i], key, 31, &keyLen);
        } else if (i == 1 && valueType == napi_string) {
            napi_get_value_string_utf8(env, argv[i], value, 127, &valueLen);
            break;
        } else {
            NAPI_ASSERT(env, false, "type mismatch");
        }
    }

    // Service logic for obtaining data. This example simply obtains data from a global variable.
    auto itr = gKeyValueStorage.find(key);
    napi_value result = nullptr;
    if (itr != gKeyValueStorage.end()) {
        // Use the data obtained to create a JS object of the string type.
        napi_create_string_utf8(env, itr->second.c_str(), itr->second.length(), &result);
    } else if (valueLen > 0) {
        // If no data is obtained, use the default value to create a JS object.
        napi_create_string_utf8(env, value, valueLen, &result);
    } else {
        NAPI_ASSERT(env, false, "key does not exist");
    }
    // Return the result.
    return result;
}
```

#### Implementing get

The `get` function registered for the storage module is `JSStorageGet`.

```c
static napi_value JSStorageGet(napi_env env, napi_callback_info info)
{
    GET_PARAMS(env, info, 3);
    NAPI_ASSERT(env, argc >= 1, "requires 1 parameter");

    // StorageAsyncContext is a custom class used to store data during execution.
    StorageAsyncContext* asyncContext = new StorageAsyncContext();

    asyncContext->env = env;

    // Obtain parameters.
    for (size_t i = 0; i < argc; i++) {
        napi_valuetype valueType;
        napi_typeof(env, argv[i], &valueType);

        if (i == 0 && valueType == napi_string) {
            napi_get_value_string_utf8(env, argv[i], asyncContext->key, 31, &asyncContext->keyLen);
        } else if (i == 1 && valueType == napi_string) {
            napi_get_value_string_utf8(env, argv[i], asyncContext->value, 127, &asyncContext->valueLen);
        } else if (i == 1 && valueType == napi_function) {
            napi_create_reference(env, argv[i], 1, &asyncContext->callbackRef);
            break;
        } else if (i == 2 && valueType == napi_function) {
            napi_create_reference(env, argv[i], 1, &asyncContext->callbackRef);
        } else {
            NAPI_ASSERT(env, false, "type mismatch");
        }
    }

    napi_value result = nullptr;

    // Determine whether promise or callback is used based on the parameters.
    if (asyncContext->callbackRef == nullptr) {
        // Create a promise.
        napi_create_promise(env, &asyncContext->deferred, &result);
    } else {
        napi_get_undefined(env, &result);
    }

    napi_value resource = nullptr;
    napi_create_string_utf8(env, "JSStorageGet", NAPI_AUTO_LENGTH, &resource);

    napi_create_async_work(
        env, nullptr, resource,
        // Callback 1: This callback contains the service logic to be asynchronously executed and is asynchronously executed by the NAPI. Do not operate JS objects using the NAPI because the execution is asynchronous.
        [](napi_env env, void* data) {
            StorageAsyncContext* asyncContext = (StorageAsyncContext*)data;
            auto itr = gKeyValueStorage.find(asyncContext->key);
            if (itr != gKeyValueStorage.end()) {
                strncpy_s(asyncContext->value, 127, itr->second.c_str(), itr->second.length());
                asyncContext->status = 0;
            } else {
                asyncContext->status = 1;
            }
        },
        // Callback 2: This callback is invoked after callback 1 is complete. The JS thread invokes the callback passed in.
        [](napi_env env, napi_status status, void* data) {
            StorageAsyncContext* asyncContext = (StorageAsyncContext*)data;
            napi_value result[2] = {0};
            if (!asyncContext->status) {
                napi_get_undefined(env, &result[0]);
                napi_create_string_utf8(env, asyncContext->value, strlen(asyncContext->value), &result[1]);
            } else {
                napi_value message = nullptr;
                napi_create_string_utf8(env, "key does not exist", NAPI_AUTO_LENGTH, &message);
                napi_create_error(env, nullptr, message, &result[0]);
                napi_get_undefined(env, &result[1]);
            }
            if (asyncContext->deferred) {
                // If a promise is used, check the result of callback 1.
                if (!asyncContext->status) {
                    // Triggered when callback 1 is successful (status is 1), that is, to invoke the callback passed in then in the promise.
                    napi_resolve_deferred(env, asyncContext->deferred, result[1]);
                } else {
                    // Triggered when callback 1 fails (status is 0), that is, to invoke the callback passed in catch in the promise.
                    napi_reject_deferred(env, asyncContext->deferred, result[0]);
                }
            } else {
                // If a callback is used, use napi_call_function to invoke the callback to return the result.
                napi_value callback = nullptr;
                napi_value returnVal;
                napi_get_reference_value(env, asyncContext->callbackRef, &callback);
                napi_call_function(env, nullptr, callback, 2, result, &returnVal);
                napi_delete_reference(env, asyncContext->callbackRef);
            }
            napi_delete_async_work(env, asyncContext->work);
            delete asyncContext;
        },
        (void*)asyncContext, &asyncContext->work);
    napi_queue_async_work(env, asyncContext->work);

    return result;
}
```

### JS Sample Code

```js
import storage from 'libstorage.so';

export default {
  testGetSync() {
  	const name = storage.getSync('name');
    console.log('name is ' + name);
  },
  testGet() {
    storage.get('name')
    .then(date => {
    	console.log('name is ' + data);
    })
    .catch(error => {
    	console.log('error: ' + error);
    });
  }
}
```



## Example 2: Binding Native and JS Objects for the NetServer Module

### Overview

This example shows how to implement the `on/off/once` method and bind C++ and JS objects using the **wrap** API. The NetServer module implements the network service.

### API Declaration

```typescript
export class NetServer {
  function start(port: number): void;
  function stop(): void;
  function on('start' | 'stop', callback: Function): void;
  function once('start' | 'stop', callback: Function): void;
  function off('start' | 'stop', callback: Function): void;
}
```

### Implementation

You can obtain the complete code from `sample/native_module_netserver/` in the [OpenHarmony/arkui_napi](https://gitee.com/openharmony/arkui_napi/tree/master) repository.

#### Registering the Module

```c
static napi_value NetServer::Export(napi_env env, napi_value exports)
{
    const char className[] = "NetServer";
    napi_property_descriptor properties[] = {
        DECLARE_NAPI_FUNCTION("start", JS_Start),
        DECLARE_NAPI_FUNCTION("stop", JS_Stop),
        DECLARE_NAPI_FUNCTION("on", JS_On),
        DECLARE_NAPI_FUNCTION("once", JS_Once),
        DECLARE_NAPI_FUNCTION("off", JS_Off),
    };
    napi_value netServerClass = nullptr;

    napi_define_class(env, className, sizeof(className), JS_Constructor, nullptr, countof(properties), properties,
                      &netServerClass);

    napi_set_named_property(env, exports, "NetServer", netServerClass);

    return exports;
}
```

#### Binding C++ and JS Objects in a Constructor

```c
napi_value NetServer::JS_Constructor(napi_env env, napi_callback_info cbinfo)
{
    napi_value thisVar = nullptr;
    void* data = nullptr;
    napi_get_cb_info(env, cbinfo, nullptr, nullptr, &thisVar, &data);

    // C++ native object to be mapped to the JS object.
    NetServer* netServer = new NetServer(env, thisVar);

    // Use napi_wrap to bind netServer and thisVar (JS object created).
    napi_wrap(
        env, thisVar, netServer,
        // The JS object is automatically released by the engine. When the JS object is released, the callback is triggered to release netServer.
        [](napi_env env, void* data, void* hint) {
            printf("NetServer::Destructor\n");
            NetServer* netServer = (NetServer*)data;
            delete netServer;
        },
        nullptr, nullptr);

    return thisVar;
}
```

#### Obtaining the C++ Object from the JS Object

```c
napi_value NetServer::JS_Start(napi_env env, napi_callback_info cbinfo)
{
    size_t argc = 1;
    napi_value argv[1] = {0};
    napi_value thisVar = nullptr;
    void* data = nullptr;
    napi_get_cb_info(env, cbinfo, &argc, argv, &thisVar, &data);

    NetServer* netServer = nullptr;
    // Obtain the C++ object from thisVar using napi_unwrap.
    napi_unwrap(env, thisVar, (void**)&netServer);

    NAPI_ASSERT(env, argc >= 1, "requires 1 parameter");

    napi_valuetype valueType;
    napi_typeof(env, argv[0], &valueType);
    NAPI_ASSERT(env, valueType == napi_number, "type mismatch for parameter 1");

    int32_t port = 0;
    napi_get_value_int32(env, argv[0], &port);

    // Start the netServer service.
    netServer->Start(port);

    napi_value result = nullptr;
    napi_get_undefined(env, &result);
    return result;
}
```

After `netServer->Start` is executed, call back the `start` event registered by `on`.

```c
int NetServer::Start(int port)
{
    printf("NetServer::Start thread_id: %ld \n", uv_thread_self());

    struct sockaddr_in addr;
    int r;

    uv_ip4_addr("0.0.0.0", port, &addr);

    r = uv_tcp_init(loop_, &tcpServer_);
    if (r) {
        fprintf(stderr, "Socket creation error\n");
        return 1;
    }

    r = uv_tcp_bind(&tcpServer_, (const struct sockaddr*)&addr, 0);
    if (r) {
        fprintf(stderr, "Bind error\n");
        return 1;
    }

    r = uv_listen((uv_stream_t*)&tcpServer_, SOMAXCONN, OnConnection);
    if (r) {
        fprintf(stderr, "Listen error %s\n", uv_err_name(r));
        return 1;
    }

    // Trigger the start event after the service is started.
    Emit("start", nullptr);

    return 0;
}
```

#### Registering Events (on)

```c
napi_value NetServer::JS_On(napi_env env, napi_callback_info cbinfo)
{
    size_t argc = 2;
    napi_value argv[2] = {0};
    napi_value thisVar = 0;
    void* data = nullptr;
    napi_get_cb_info(env, cbinfo, &argc, argv, &thisVar, &data);

    NetServer* netServer = nullptr;
    // Obtain the NetServer pointer using napi_unwrap.
    napi_unwrap(env, thisVar, (void**)&netServer);

    NAPI_ASSERT(env, argc >= 2, "requires 2 parameter");

    // Verify the parameter type.
    napi_valuetype eventValueType;
    napi_typeof(env, argv[0], &eventValueType);
    NAPI_ASSERT(env, eventValueType == napi_string, "type mismatch for parameter 1");

    napi_valuetype eventHandleType;
    napi_typeof(env, argv[1], &eventHandleType);
    NAPI_ASSERT(env, eventHandleType == napi_function, "type mismatch for parameter 2");

    char type[64] = {0};
    size_t typeLen = 0;

    napi_get_value_string_utf8(env, argv[0], type, 63, &typeLen);

    // Register the event handler.
    netServer->On((const char*)type, argv[1]);

    napi_value result = nullptr;
    napi_get_undefined(env, &result);
    return result;
}
```

### JS Sample Code

```javascript
import { NetServer } from 'libnetserver.so';

export default {
  testNetServer() {
  	var netServer = new NetServer();
  	netServer.on('start', (event) => {});
  	netServer.start(1000); // The port number is 1000. After start is executed, invoke the start callback registered.
  }
}
```



## Example 3: Calling Back a JS API in a Non-JS Thread

### Overview

This example describes how to invoke a JS callback in a non-JS thread. For example, a sensor listener is registered for a JS application. The sensor data is reported by an SA. When the SA invokes the client through Inter-Process Communication (IPC), the execution thread is an IPC thread, which is different from the JS thread of the SA. In this case, the JS callback must be thrown to the JS thread to execute. Otherwise, the application will crash.

### Implementation

You can obtain the complete code from `sample/native_module_callback/` in the [OpenHarmony/arkui_napi](https://gitee.com/openharmony/arkui_napi/tree/master) repository.

#### Registering the Module

Register the `test` API to pass in a parameter.

```c++
/***********************************************
 * Module export and register
 ***********************************************/
static napi_value CallbackExport(napi_env env, napi_value exports)
{
    static napi_property_descriptor desc[] = {
        DECLARE_NAPI_FUNCTION("test", JSTest)
    };
    NAPI_CALL(env, napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc));
    return exports;
}

// Define the callback.
static napi_module callbackModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = CallbackExport,
    .nm_modname = "callback",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

// Register the callback.
extern "C" __attribute__((constructor)) void CallbackTestRegister()
{
    napi_module_register(&callbackModule);
}
```

#### Obtaining the Loop in env and Throwing the Task to the JS Thread

```c++
#include <thread>

#include "napi/native_api.h"
#include "napi/native_node_api.h"

#include "uv.h"

struct CallbackContext {
    napi_env env = nullptr;
    napi_ref callbackRef = nullptr;
    int retData = 0;
};

void callbackTest(CallbackContext* context)
{
    uv_loop_s* loop = nullptr;
    // Save the env when the JS callback is registered. Obtain the loop of the JS thread from env.
    napi_get_uv_event_loop(context->env, &loop);
    
    // Create uv_work_t to transfer private data (int type 1 in this example). Note that memory must be released after the callback is complete. The logic for generating the returned data is omitted here.
    uv_work_t* work = new uv_work_t;
    context->retData = 1;
    work->data = (void*)context;
    
    // Call the libuv API to throw the JS task to the loop for execution.
    uv_queue_work(
        loop,
        work,
        // This callback is executed in another common thread to process tasks asynchronously. After the callback is complete, execute the next callback. In this scenario, this callback does not need to execute any task.
        [](uv_work_t* work) {},
        // This callback is executed in the JS thread bound to env.
        [](uv_work_t* work, int status) {
            CallbackContext* context = (CallbackContext*)work->data;
            napi_handle_scope scope = nullptr;
            // Open the handle scope to manage the lifecycle of napi_value. Otherwise, memory leakage occurs.
            napi_open_handle_scope(context->env, &scope);
            if (scope == nullptr) {
                return;
            }

            // Call the NAPIs.
            napi_value callback = nullptr;
            napi_get_reference_value(context->env, context->callbackRef, &callback);
            napi_value retArg;
            napi_create_int32(context->env, context->retData, &retArg);
            napi_value ret;
            napi_call_function(context->env, nullptr, callback, 1, &retArg, &ret);
            napi_delete_reference(context->env, context->callbackRef);

            // Close the handle scope to release napi_value.
            napi_close_handle_scope(context->env, scope);

            // Release the work pointer.
            if (work != nullptr) {
                delete work;
            }

            delete context;
        }
    );
}

static napi_value JSTest(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1] = { 0 };
    napi_value thisVar = nullptr;
    void* data = nullptr;
    napi_get_cb_info(env, info, &argc, argv, &thisVar, &data);

    // Obtain the first input parameter, that is, the callback to be invoked subsequently.
    napi_valuetype valueType = napi_undefined;
    napi_typeof(env, argv[0], &valueType);
    if (valueType != napi_function) {
        return nullptr;
    }
    // Save the env and callback for subsequent transfer.
    auto asyncContext = new CallbackContext();
    asyncContext->env = env;
    napi_create_reference(env, argv[0], 1, &asyncContext->callbackRef);
    // Simulate the logic for throwing a task to a non-JS thread.
    std::thread testThread(callbackTest, asyncContext);
    testThread.detach();

    return nullptr;
}
```

### JS Sample Code

```js
import callback from 'libcallback.so';

export default {
  testcallback() {
  	callback.test((data) => {
      console.error('test result = ' + data)
    })
  }
}
```
