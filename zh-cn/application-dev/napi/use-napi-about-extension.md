# 使用Node-API扩展能力接口

## 简介

[扩展能力接口](../reference/native-lib/napi.md)进一步扩展了Node-API的功能，提供了一些额外的接口，用于在Node-API模块中与JavaScript进行更灵活的交互和定制，这些接口可以用于创建自定义JavaScript对象等场景。

## 模块加载

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_load_module | 用于在Node-API模块中将abc文件作为模块加载，返回模块的命名空间，适用于需要在运行时动态加载模块或资源的应用程序，从而实现灵活的扩展和定制。 |
| napi_load_module_with_info | 用于在Node-API中进行模块的加载，当模块加载出来之后，可以使用函数napi_get_property获取模块导出的变量，也可以使用napi_get_named_property获取模块导出的函数，该函数可以在[新创建的ArkTs基础运行时环境](use-napi-ark-runtime.md)中使用 |
| napi_module_register | 有些功能可能需要通过NAPI模块来实现以获得更好的性能，通过将这些功能实现为自定义模块并注册到JavaScript环境中，可以在一定程度上提高整体的性能。 |

### 使用示例

#### napi_load_module

[使用Node-API接口在主线程中进行模块加载](use-napi-load-module.md)

#### napi_load_module_with_info

[使用Node-API接口进行模块加载](use-napi-load-module-with-info.md)

#### napi_module_register

在JavaScript代码环境中使用NAPI模块编写的代码来实现特定的功能，可以将这部分功能封装成自定义模块，然后通过napi_module_register将其注册到JavaScript代码环境中，以实现功能的扩展和复用。

cpp部分代码

```cpp
#include "napi/native_api.h"

// 此模块是一个NAPI的回调函数
static napi_value Add(napi_env env, napi_callback_info info)
{
    // 接受传入两个参数
    size_t requireArgc = 2;
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);

    // 将传入的napi_value类型的参数转化为double类型
    double valueLift;
    double valueRight;
    napi_get_value_double(env, args[0], &valueLift);
    napi_get_value_double(env, args[1], &valueRight);

    // 将转化后的double值相加并转成napi_value返回给JavaScript代码使用
    napi_value sum;
    napi_create_double(env, valueLift + valueRight, &sum);

    return sum;
}

// C++函数Init用于初始化插件，用于将JavaScript层的函数或属性与C++层的函数进行关联
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    // 通过napi_property_descriptor结构体，可以定义需要导出的属性，并在NAPI模块中使用。napi_define_properties将属性与实际的C++函数进行关联，使其可以被JavaScript层访问和调用
    napi_property_descriptor desc[] = {
        { "add", nullptr, Add, nullptr, nullptr, nullptr, napi_default, nullptr }
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

// 插件的初始化被定义在一个名为demoModule的结构体中，其中包含了模块的基本信息，比如模块的版本号、注册函数等
static napi_module demoModule = {
    .nm_version =1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

// 在RegisterEntryModule函数中，使用napi_module_register函数注册并导出了这个插件
extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    napi_module_register(&demoModule);
}
```

接口声明

```ts
// index.d.ts
export const add: (a: number, b: number) => number;
```

ArkTS侧示例代码

```ts
hilog.info(0x0000, 'testTag', 'Test NAPI 2 + 3 = %{public}d', testNapi.add(2, 3));

```

## JS Object相关

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_create_object_with_properties | 用于在Node-API模块中使用给定的napi_property_descriptor创建js Object。descriptor的键名必须为string，且不可转为number。 |
| napi_create_object_with_named_properties | 用于在Node-API模块中使用给定的napi_value和键名创建js Object。键名必须为string，且不可转为number。 |

### 使用示例

#### napi_create_object_with_properties

用于使用给定的napi_property_descriptor作为属性去创建一个JavaScript对象，并且descriptor的键名必须为string，且不可转为number。

cpp部分代码

```cpp
static napi_value CreateObjectWithProperties(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1] = nullptr;
    // 获取解析传递的参数
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // 声明了一个napi_property_descriptor数组desc，其中包含了一个名为"name"的属性，其值为传入的第一个参数argv[0]。
    napi_property_descriptor desc[] = {
        {"name", nullptr, nullptr, nullptr, nullptr, argv[0], napi_default_jsproperty, nullptr}};
    napi_value object = nullptr;
    // 调用napi_create_object_with_properties来创建一个新的JavaScript对象，并将属性值添加到该对象中。
    napi_create_object_with_properties(env, &object, sizeof(desc) / sizeof(desc[0]), desc);
    napi_valuetype valueType;
    napi_typeof(env, object, &valueType);
    if (valueType == napi_object) {
        return object;
    }
}
```

接口声明

```ts
// index.d.ts
export const createObjectWithProperties: (data: string) => Object;
```

ArkTS侧示例代码

```ts
import testNapi from 'libentry.so';

let value = testNapi.createObjectWithProperties('createObject');
hilog.info(0x0000, 'testTag', 'NAPI napi_create_object_with_properties:%{public}s', JSON.stringify(value));
```

#### napi_create_object_with_named_properties

用于使用给定的napi_value和键名创建一个js对象，并且给定的键名必须为string，且不可转为number。

cpp部分代码

```cpp
static napi_value CreateObjectWithNameProperties(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1] = nullptr;
    // 获取解析传递的参数
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    napi_value obj = nullptr;
    const char *key[] = {
        "name",
    };
    const napi_value values[] = {
        argv[0],
    };
    napi_property_descriptor desc[] = {{"name", nullptr, nullptr,
                                        nullptr, nullptr, nullptr, napi_default, nullptr}};
    napi_status status;
    status = napi_create_object_with_named_properties(env, &obj, sizeof(desc) / sizeof(desc[0]), key, values);
    if (status != napi_ok) {
        return argv[0];
    }
    return obj;
}
```

接口声明

```ts
// index.d.ts
export const createObjectWithNameProperties: (data: string) => string | { name: string };
```

ArkTS侧示例代码

```ts
import testNapi from 'libentry.so';

let value = testNapi.createObjectWithNameProperties('ls');
hilog.info(0x0000, 'testTag', 'NAPI napi_create_object_with_named_properties:%{public}s', JSON.stringify(value));
```

## 运行指定abc文件

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_run_script_path | 用于在Node-API模块中运行指定abc文件。 |

### 使用示例

#### napi_run_script_path

在Node-API模块中运行abc文件。

cpp部分代码

```cpp
static napi_value RunScriptPath(napi_env env, napi_callback_info info)
{
    napi_value value = nullptr;
    // 注意：记得在应用rawfile目录下放置.abc文件
    const char *scriptPath = "/entry/resources/rawfile/test.abc";
    // 使用napi_run_script_path函数执行指定路径中的文件
    napi_status status = napi_run_script_path(env, scriptPath, &value);
    // 检查是否执行成功，如果失败，返回false
    napi_value returnValue = nullptr;
    if (value == nullptr || status != napi_ok) {
        napi_get_boolean(env, false, &returnValue);
    }
    napi_get_boolean(env, true, &returnValue);
    return returnValue;
}
```

接口声明

```ts
// index.d.ts
export const runScriptPath: () => boolean;
```

ArkTS侧示例代码

```ts
import testNapi from 'libentry.so';

try {
  // 在此处执行错误返回false，成功就返回true
  hilog.info(0x0000, 'testTag', 'Test NAPI napi_run_script_path: %{public}s', testNapi.runScriptPath());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test NAPI napi_run_script_path errorMessage: %{public}s', error.message);
}
```

test.js代码，将js代码编成.abc文件，步骤如下:

1. 在sdK的ets/build-tools/ets-loader/bin/ark/build-win/bin目录下放置test.js文件
2. 执行命令如es2abc.exe test.js  --output test.abc后便可生成test.abc文件

放入指定路径中：/entry/resources/rawfile

```js
function add(a, b) {
  return a+b;
}
add(1, 2);
```

## 异步工作对象加入队列并指定优先级

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_queue_async_work_with_qos | 用于将异步工作对象加入队列，让开发者能够根据QoS优先级来管理和调度异步工作的执行，从而更好地满足程序的性能和响应需求。 |

### 使用示例

#### napi_queue_async_work_with_qos

将异步工作对象加到队列，由底层根据传入的qos优先级去调度执行。

[指定异步任务调度优先级](../performance/develop-Native-modules-using-NAPI-safely-and-efficiently.md#指定异步任务调度优先级)

## 给JavaScript对象绑定回调和回调所需的参数

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_coerce_to_native_binding_object | 用于给JavaScript对象绑定回调和回调所需的参数，其作用是为了给JavaScript对象携带Native信息。 |

### 使用示例

#### napi_coerce_to_native_binding_object

用于给JS Object绑定回调和回调所需的参数，给JS Object携带Native信息。

cpp部分代码

```cpp
// 解绑回调，一般在序列化时调用，可在对象解绑时执行一些清理操作
static void *DetachCb(napi_env env, void *nativeObject, void *hint)
{
    OH_LOG_INFO(LOG_APP, "NAPI this is detach callback");
    return nativeObject;
}

// 绑定回调，一般在序列化时调用
static napi_value AttachCb(napi_env env, void *nativeObject, void *hint)
{
    OH_LOG_INFO(LOG_APP, "NAPI this is attach callback");
    napi_value object = nullptr;
    napi_value name = nullptr;
    // hint: 一个指针，可以用于传递附加的信息给回调函数
    // 在这里判断hint是否为空
    if (hint != nullptr) {
        // 将void*类型的nativeObject类型强转为napi_value的object
        object = reinterpret_cast<napi_value>(nativeObject);
        // 设置name属性
        napi_create_string_utf8(env, "Leili", NAPI_AUTO_LENGTH, &name);
    } else {
        napi_create_object(env, &object);
        // 设置name属性
        napi_create_string_utf8(env, "Hanmeimei", NAPI_AUTO_LENGTH, &name);
    }
    // 将Native的值设置到Javascript object中
    napi_set_named_property(env, object, "name", name);
    return object;
}

static napi_value CoerceToNativeBindingObject(napi_env env, napi_callback_info info)
{
    // 创建一个Javascript object
    napi_value object = nullptr;
    napi_create_object(env, &object);
    // 调用napi_coerce_to_native_binding_object给JS Object携带Native信息
    napi_status status = napi_coerce_to_native_binding_object(env, object, DetachCb, AttachCb,
                                                              reinterpret_cast<void *>(object), nullptr);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "NAPI napi_coerce_to_native_binding_object fail");
        return nullptr;
}
    }
    return object;
}
```

接口声明

```ts
// index.d.ts
export const coerceToNativeBindingObject: () => Object | void;
```

ArkTS侧示例代码

```ts
// index.ets
// 需要加入worker模块，这是为了触发序列化
import hilog from '@ohos.hilog'
import worker from '@ohos.worker';
import testNapi from 'libentry.so';

let wk = new worker.ThreadWorker("entry/ets/workers/worker.ts");
// 发送消息到worker线程
wk.postMessage("test napi_coerce_to_native_binding_object");
// 处理来自worker线程的消息
wk.onmessage = (message) => {
  hilog.info(0x0000, 'testTag', 'Test NAPI message from worker thread: %{public}s', JSON.stringify(message));
};
```

```ts
// worker.ts
// 处理来自主线程的消息
import worker from '@ohos.worker';
import testNapi from 'libentry.so'
import hilog from '@ohos.hilog'

let parent = worker.workerPort;
parent.onmessage = function(message) {
  hilog.info(0x0000, 'testTag', 'Test NAPI message from main thread: %{public}s', JSON.stringify(message));
  // 发送消息到主线程
  parent.postMessage(testNapi.coerceToNativeBindingObject());
}
```

worker相关开发配置和流程参考以下链接：
[使用Worker进行线程间通信](../reference/apis-arkts/js-apis-worker.md)

## 事件循环

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_run_event_loop | 触发底层的事件循环。 |
| napi_stop_event_loop | 停止底层的事件循环。 |

### 使用示例

#### napi_run_event_loop、napi_stop_event_loop

[使用扩展的Node-API接口在异步线程中运行和停止事件循环](use-napi-event-loop.md)

### 编译配置、模块注册

- 编译配置

```text
// CMakeLists.txt
# the minimum version of CMake.
cmake_minimum_required(VERSION 3.4.1)
project(AboutExtension)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

add_library(entry SHARED extension.cpp)
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```

- 模块注册

```cpp
// extension.cpp
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        {"createObjectWithProperties", nullptr, CreateObjectWithProperties, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createObjectWithNameProperties", nullptr, CreateObjectWithNameProperties, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"runScriptPath", nullptr, RunScriptPath, nullptr, nullptr, nullptr, napi_default, nullptr}，
        {"queueAsyncWorkWithQos", nullptr, QueueAsyncWorkWithQos, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"coerceToNativeBindingObject", nullptr, CoerceToNativeBindingObject, nullptr, nullptr, nullptr, napi_default, nullptr}
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END
```
