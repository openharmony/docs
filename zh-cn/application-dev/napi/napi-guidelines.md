# Native API在应用工程中的使用指导

OpenHarmony的应用必须用js来桥接native。需要使用[ace_napi](https://gitee.com/openharmony/arkui_napi/tree/master)仓中提供的napi接口来处理js交互。napi提供的接口名与三方Node.js一致，目前支持部分接口，符号表见仓下的该文件`libnapi.ndk.json`。

## 开发流程

IDE中会包含使用Native API的默认工程，使用`File`->`New`->`Create Project`创建`Native C++`模板工程。创建后在`main`目录下会包含`cpp`目录，可以使用ace_napi仓下提供的napi接口进行开发。

js侧通过`import`引入native侧包含处理js逻辑的so，如：`import hello from 'libhello.so'`，意为使用libhello.so的能力，native侧通过napi接口创建的js对象会给到应用js侧的`hello`对象。

## 开发建议

### 1. 注册建议

* nm_register_func对应的函数需要加上static，防止与其他so里的符号冲突。
* 模块注册的入口，即使用\_\_attribute\_\_((constructor))修饰的函数的函数名需要确保不与其他模块重复。
### 2. so命名规则

* 每个模块对应一个so
* 如模块名为`hello`，则so的名字为`libhello.so`，`napi_module`中`nm_modname`字段应为`hello`，大小写与模块名保持一致，应用使用时写作：`import hello from 'libhello.so'`

### 3. js对象线程限制

ark引擎会对js对象线程使用进行保护，不正确使用会引起应用crash。

* napi接口只能在js线程使用。
* env与线程绑定，不能跨线程使用。native侧js对象只能在创建时的线程使用，即与线程所持有的env绑定。

### 4. napi_create_async_work接口说明

napi_create_async_work里有两个回调：

* execute：用于异步处理业务逻辑。因为不在JS线程中，所以不允许调用napi的接口。业务逻辑的返回值可以返回到complete回调中处理。

* complete：可以调用napi的接口，将execute中的返回值封装成JS对象返回。此回调在JS线程中执行。

```c++
napi_status napi_create_async_work(napi_env env,
                                   napi_value async_resource,
                                   napi_value async_resource_name,
                                   napi_async_execute_callback execute,
                                   napi_async_complete_callback complete,
                                   void* data,
                                   napi_async_work* result)
```



## 示例一 storage 模块——同步异步接口封装

### 模块简介

本例通过实现 `storage` 模块展示了同步和异步方法的封装。`storage ` 模块实现了数据的保存、获取、删除、清除功能。

### 接口声明

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



### 具体实现

完整代码参见仓下路径：[OpenHarmony/arkui_napi](https://gitee.com/openharmony/arkui_napi/tree/master)仓库`sample/native_module_storage/`

#### 模块注册

如下，注册了4个同步接口（`getSync`、`setSync`、`removeSync`、`clearSync`）、4个异步接口（`get`、`set`、`remove`、`clear`）。

```c++
/***********************************************
 * Module export and register
 ***********************************************/
static napi_value StorgeExport(napi_env env, napi_value exports)
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

// storage module
static napi_module storage_module = {.nm_version = 1,
                                     .nm_flags = 0,
                                     .nm_filename = nullptr,
                                     .nm_register_func = StorgeExport,
                                     .nm_modname = "storage",
                                     .nm_priv = ((void*)0),
                                     .reserved = {0}};

// storage module register
extern "C" __attribute__((constructor)) void StorageRegister()
{
    napi_module_register(&storage_module);
}
```

#### getSync 函数实现

如上注册时所写，`getSync` 对应的函数是 `JSStorageGetSync` 。从 `gKeyValueStorage` 中获取数据后，创建一个字符串对象并返回。

```c
static napi_value JSStorageGetSync(napi_env env, napi_callback_info info)
{
    GET_PARAMS(env, info, 2);
    NAPI_ASSERT(env, argc >= 1, "requires 1 parameter");
    char key[32] = {0};
    size_t keyLen = 0;
    char value[128] = {0};
    size_t valueLen = 0;

    // 参数解析
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

    // 获取数据的业务逻辑，这里简单地从一个全局变量中获取
    auto itr = gKeyValueStorage.find(key);
    napi_value result = nullptr;
    if (itr != gKeyValueStorage.end()) {
        // 获取到数据后创建一个string类型的JS对象
        napi_create_string_utf8(env, itr->second.c_str(), itr->second.length(), &result);
    } else if (valueLen > 0) {
        // 没有获取到数据使用默认值创建JS对象
        napi_create_string_utf8(env, value, valueLen, &result);
    } else {
        NAPI_ASSERT(env, false, "key does not exist");
    }
    // 返回结果
    return result;
}
```

#### get 函数实现

如上注册时所写，`get`对应的函数式`JSStorageGet`。

```c
static napi_value JSStorageGet(napi_env env, napi_callback_info info)
{
    GET_PARAMS(env, info, 3);
    NAPI_ASSERT(env, argc >= 1, "requires 1 parameter");

    // StorageAsyncContext是自己定义的一个类，用于保存执行过程中的数据
    StorageAsyncContext* asyncContext = new StorageAsyncContext();

    asyncContext->env = env;

    // 获取参数
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

    // 根据参数判断开发者使用的是promise还是callback
    if (asyncContext->callbackRef == nullptr) {
        // 创建promise
        napi_create_promise(env, &asyncContext->deferred, &result);
    } else {
        napi_get_undefined(env, &result);
    }

    napi_value resource = nullptr;
    napi_create_string_utf8(env, "JSStorageGet", NAPI_AUTO_LENGTH, &resource);

    napi_create_async_work(
        env, nullptr, resource,
        // 回调1：此回调由napi异步执行，里面就是需要异步执行的业务逻辑。由于是异步线程执行，所以不要在此通过napi接口操作JS对象。
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
        // 回调2：此回调在上述异步回调执行完后执行，此时回到了JS线程来回调开发者传入的回调
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
                // 如果走的是promise，那么判断回调1的结果
                if (!asyncContext->status) {
                    // 回调1执行成功（status为1）时触发，也就是触发promise里then里面的回调
                    napi_resolve_deferred(env, asyncContext->deferred, result[1]);
                } else {
                    // 回调1执行失败（status为0）时触发，也就是触发promise里catch里面的回调
                    napi_reject_deferred(env, asyncContext->deferred, result[0]);
                }
            } else {
                // 如果走的是callback，则通过napi_call_function调用callback回调返回结果
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



## 示例二 NetServer 模块——native与js对象绑定

### 模块简介

本例展示了`on/off/once`订阅方法的实现，同时也包含了 C++ 与 JS 对象通过 wrap 接口的绑定。NetServer 模块实现了一个网络服务。

### 接口声明

```typescript
export class NetServer {
  function start(port: number): void;
  function stop(): void;
  function on('start' | 'stop', callback: Function): void;
  function once('start' | 'stop', callback: Function): void;
  function off('start' | 'stop', callback: Function): void;
}
```

### 具体实现

完整代码参见：[OpenHarmony/arkui_napi](https://gitee.com/openharmony/arkui_napi/tree/master)仓库`sample/native_module_netserver/`

#### 模块注册

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

#### 在构造函数中绑定 C++ 与 JS 对象

```c
napi_value NetServer::JS_Constructor(napi_env env, napi_callback_info cbinfo)
{
    napi_value thisVar = nullptr;
    void* data = nullptr;
    napi_get_cb_info(env, cbinfo, nullptr, nullptr, &thisVar, &data);

    // C++ Native对象，准备与JS对象映射在一起
    NetServer* netServer = new NetServer(env, thisVar);

    // 使用napi_wrap将netServer与thisVar（即当前创建的这个JS对象）做绑定
    napi_wrap(
        env, thisVar, netServer,
        // JS对象由引擎自动回收释放，当JS对象释放时触发该回调，在改回调中释放netServer
        [](napi_env env, void* data, void* hint) {
            printf("NetServer::Destructor\n");
            NetServer* netServer = (NetServer*)data;
            delete netServer;
        },
        nullptr, nullptr);

    return thisVar;
}
```

#### 从 JS 对象中取出 C++ 对象

```c
napi_value NetServer::JS_Start(napi_env env, napi_callback_info cbinfo)
{
    size_t argc = 1;
    napi_value argv[1] = {0};
    napi_value thisVar = nullptr;
    void* data = nullptr;
    napi_get_cb_info(env, cbinfo, &argc, argv, &thisVar, &data);

    NetServer* netServer = nullptr;
    // 通过napi_unwrap从thisVar中取出C++对象
    napi_unwrap(env, thisVar, (void**)&netServer);

    NAPI_ASSERT(env, argc >= 1, "requires 1 parameter");

    napi_valuetype valueType;
    napi_typeof(env, argv[0], &valueType);
    NAPI_ASSERT(env, valueType == napi_number, "type mismatch for parameter 1");

    int32_t port = 0;
    napi_get_value_int32(env, argv[0], &port);

    // 开启服务
    netServer->Start(port);

    napi_value result = nullptr;
    napi_get_undefined(env, &result);
    return result;
}
```

`netServer->Start`后回调通过`on`注册的`start`事件。

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

    // 服务启动后触发“start”事件
    Emit("start", nullptr);

    return 0;
}
```

#### 注册或释放（on/off/once）事件，以 on 为例

```c
napi_value NetServer::JS_On(napi_env env, napi_callback_info cbinfo)
{
    size_t argc = 2;
    napi_value argv[2] = {0};
    napi_value thisVar = 0;
    void* data = nullptr;
    napi_get_cb_info(env, cbinfo, &argc, argv, &thisVar, &data);

    NetServer* netServer = nullptr;
    // 通过napi_unwrap取出NetServer指针
    napi_unwrap(env, thisVar, (void**)&netServer);

    NAPI_ASSERT(env, argc >= 2, "requires 2 parameter");

    // 参数类型校验
    napi_valuetype eventValueType;
    napi_typeof(env, argv[0], &eventValueType);
    NAPI_ASSERT(env, eventValueType == napi_string, "type mismatch for parameter 1");

    napi_valuetype eventHandleType;
    napi_typeof(env, argv[1], &eventHandleType);
    NAPI_ASSERT(env, eventHandleType == napi_function, "type mismatch for parameter 2");

    char type[64] = {0};
    size_t typeLen = 0;

    napi_get_value_string_utf8(env, argv[0], type, 63, &typeLen);

    // 注册事件handler
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
  	netServer.start(1000); // 端口号1000, start完成后回调上面注册的 “start” 回调
  }
}
```



## 示例三 在非JS线程中回调JS接口

### 模块简介

本模块介绍如何在非JS线程中回调JS应用的回调函数。例如JS应用中注册了某个sensor的监听，这个sensor的数据是由一个SA服务来上报的，当SA通过IPC调到客户端时，此时的执行线程是一个IPC通信线程，与应用的JS线程是两个不同的线程。这时就需要将执行JS回调的任务抛到JS线程中才能执行，否则会出现崩溃。

### 具体实现

完整代码参见：[OpenHarmony/arkui_napi](https://gitee.com/openharmony/arkui_napi/tree/master)仓库`sample/native_module_callback/`

#### 模块注册

如下，注册了1个接口`test`，会传入一个参数，类型为包含一个参数的函数。

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

// callback module define
static napi_module callbackModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = CallbackExport,
    .nm_modname = "callback",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

// callback module register
extern "C" __attribute__((constructor)) void CallbackTestRegister()
{
    napi_module_register(&callbackModule);
}
```

#### 获取env中的loop，抛任务回JS线程

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
    // 此处的env需要在注册JS回调时保存下来。从env中获取对应的JS线程的loop。
    napi_get_uv_event_loop(context->env, &loop);
    
    // 创建uv_work_t用于传递私有数据，注意回调完成后需要释放内存,此处省略生成回传数据的逻辑，传回int类型1。
    uv_work_t* work = new uv_work_t;
    context->retData = 1;
    work->data = (void*)context;
    
    // 调用libuv接口抛JS任务到loop中执行。
    uv_queue_work(
        loop,
        work,
        // 此回调在另一个普通线程中执行，用于处理异步任务，回调执行完后执行下面的回调。本场景下该回调不需要执行任务。
        [](uv_work_t* work) {},
        // 此回调会在env对应的JS线程中执行。
        [](uv_work_t* work, int status) {
            CallbackContext* context = (CallbackContext*)work->data;
            napi_handle_scope scope = nullptr;
            // 打开handle scope用于管理napi_value的生命周期，否则会内存泄露。
            napi_open_handle_scope(context->env, &scope);
            if (scope == nullptr) {
                return;
            }

            // 调用napi。
            napi_value callback = nullptr;
            napi_get_reference_value(context->env, context->callbackRef, &callback);
            napi_value retArg;
            napi_create_int32(context->env, context->retData, &retArg);
            napi_value ret;
            napi_call_function(context->env, nullptr, callback, 1, &retArg, &ret);
            napi_delete_reference(context->env, context->callbackRef);

            // 关闭handle scope释放napi_value。
            napi_close_handle_scope(context->env, scope);

            // 释放work指针。
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

    // 获取第一个入参，即需要后续触发的回调函数
    napi_valuetype valueType = napi_undefined;
    napi_typeof(env, argv[0], &valueType);
    if (valueType != napi_function) {
        return nullptr;
    }
    // 存下env与回调函数，用于传递
    auto asyncContext = new CallbackContext();
    asyncContext->env = env;
    napi_create_reference(env, argv[0], 1, &asyncContext->callbackRef);
    // 模拟抛到非js线程执行逻辑
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