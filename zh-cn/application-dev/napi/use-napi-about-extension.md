# 使用Node-API扩展能力接口

## 简介

[扩展能力接口](../reference/native-lib/napi.md)进一步扩展了Node-API的功能，提供了一些额外的接口，用于在Node-API模块中与ArkTS进行更灵活的交互和定制，这些接口可以用于创建自定义ArkTS对象等场景。

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

## 模块加载

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_load_module | 用于在Node-API模块中将abc文件作为模块加载，返回模块的命名空间，适用于需要在运行时动态加载模块或资源的应用程序，从而实现灵活的扩展和定制。 |
| napi_load_module_with_info | 用于在Node-API中进行模块的加载，当模块加载出来之后，可以使用函数napi_get_property获取模块导出的变量，也可以使用napi_get_named_property获取模块导出的函数，该函数可以在[新创建的ArkTs基础运行时环境](use-napi-ark-runtime.md)中使用 |
| napi_module_register | 有些功能可能需要通过Node-API模块来实现以获得更好的性能，通过将这些功能实现为自定义模块并注册到ArkTS环境中，可以在一定程度上提高整体的性能。 |

### 使用示例

#### napi_load_module

[使用Node-API接口在主线程中进行模块加载](use-napi-load-module.md)

#### napi_load_module_with_info

[使用Node-API接口进行模块加载](use-napi-load-module-with-info.md)

#### napi_module_register

在ArkTS代码环境中使用Node-API模块编写的代码来实现特定的功能，可以将这部分功能封装成自定义模块，然后通过napi_module_register将其注册到ArkTS代码环境中，以实现功能的扩展和复用。

cpp部分代码

```cpp
#include "napi/native_api.h"

// 此模块是一个Node-API的回调函数
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

    // 将转化后的double值相加并转成napi_value返回给ArkTS代码使用
    napi_value sum;
    napi_create_double(env, valueLift + valueRight, &sum);

    return sum;
}

// C++函数Init用于初始化插件，用于将ArkTS层的函数或属性与C++层的函数进行关联
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    // 通过napi_property_descriptor结构体，可以定义需要导出的属性，并在Node-API模块中使用。napi_define_properties将属性与实际的C++函数进行关联，使其可以被ArkTS层访问和调用
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
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

hilog.info(0x0000, 'testTag', 'Test Node-API 2 + 3 = %{public}d', testNapi.add(2, 3));
```

## ArkTS Object相关

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_create_object_with_properties | 用于在Node-API模块中使用给定的napi_property_descriptor创建ArkTS Object。descriptor的键名必须为string，且不可转为number。 |
| napi_create_object_with_named_properties | 用于在Node-API模块中使用给定的napi_value和键名创建ArkTS Object。键名必须为string，且不可转为number。 |

### 使用示例

#### napi_create_object_with_properties

用于使用给定的napi_property_descriptor作为属性去创建一个ArkTS对象，并且descriptor的键名必须为string，且不可转为number。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateObjectWithProperties(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1] = nullptr;
    // 获取解析传递的参数
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // 声明了一个napi_property_descriptor数组desc，其中包含了一个名为"name"的属性，其值为传入的第一个参数argv[0]。
    napi_property_descriptor desc[] = {
        {"name", nullptr, nullptr, nullptr, nullptr, argv[0], napi_default_jsproperty, nullptr}};
    napi_value object = nullptr;
    // 调用napi_create_object_with_properties来创建一个新的ArkTS对象，并将属性值添加到该对象中。
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
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let value = testNapi.createObjectWithProperties('createObject');
hilog.info(0x0000, 'testTag', 'Node-API napi_create_object_with_properties:%{public}s', JSON.stringify(value));
```

#### napi_create_object_with_named_properties

用于使用给定的napi_value和键名创建一个ArkTS对象，并且给定的键名必须为string，且不可转为number。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateObjectWithNameProperties(napi_env env, napi_callback_info info)
{
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
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let value = testNapi.createObjectWithNameProperties('ls');
hilog.info(0x0000, 'testTag', 'Node-API napi_create_object_with_named_properties:%{public}s', JSON.stringify(value));
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
#include "napi/native_api.h"

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
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

try {
  // 在此处执行错误返回false，成功就返回true
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_run_script_path: %{public}s', testNapi.runScriptPath());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_run_script_path errorMessage: %{public}s', error.message);
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

## 给ArkTS对象绑定回调和回调所需的参数

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_coerce_to_native_binding_object | 用于给ArkTS对象绑定回调和回调所需的参数，其作用是为了给ArkTS对象携带Native信息。 |

### 使用示例

#### napi_coerce_to_native_binding_object

用于给ArkTS Object绑定回调和回调所需的参数，给ArkTS Object携带Native信息。

cpp部分代码

```cpp
#include "napi/native_api.h"

// 解绑回调，一般在序列化时调用，可在对象解绑时执行一些清理操作
static void *DetachCb(napi_env env, void *nativeObject, void *hint)
{
    OH_LOG_INFO(LOG_APP, "Node-API this is detach callback");
    return nativeObject;
}

// 绑定回调，一般在序列化时调用
static napi_value AttachCb(napi_env env, void *nativeObject, void *hint)
{
    OH_LOG_INFO(LOG_APP, "Node-API this is attach callback");
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
    // 调用napi_coerce_to_native_binding_object给ArkTS Object携带Native信息
    napi_status status = napi_coerce_to_native_binding_object(env, object, DetachCb, AttachCb,
                                                              reinterpret_cast<void *>(object), nullptr);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_coerce_to_native_binding_object fail");
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
  hilog.info(0x0000, 'testTag', 'Test Node-API message from worker thread: %{public}s', JSON.stringify(message));
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
  hilog.info(0x0000, 'testTag', 'Test Node-API message from main thread: %{public}s', JSON.stringify(message));
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

## ArkTS基础运行时环境

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_create_ark_runtime | 创建基础运行时环境。 |
| napi_destroy_ark_runtime | 销毁基础运行时环境。 |

### 使用示例

#### napi_create_ark_runtime、napi_destroy_ark_runtime

[使用Node-API接口创建ArkTs运行时环境](use-napi-ark-runtime.md)

## 序列化和反序列化

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_serialize | 将ArkTS对象转换为native数据。 |
| napi_deserialize | 将native数据转为ArkTS对象。 |
| napi_delete_serialization_data | 删除序列化数据。 |

### 使用示例

#### napi_serialize、napi_deserialize、napi_delete_serialization_data

用于将ArkTS对象转换为native数据、将native数据转为ArkTS对象、删除序列化数据等操作。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value AboutSerialize(napi_env env, napi_callback_info info)
{
    // 获取传入的ts的一个对象作为参数
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    napi_value undefined = nullptr;
    // 构造napi_serialize方法所需参数
    napi_get_undefined(env, &undefined);
    void *data = nullptr;
    // 调用napi_serialize方法将ts对象转化为native数据
    napi_status status = napi_serialize(env, args[0], undefined, undefined, &data);
    if (status != napi_ok ||data == nullptr) {
        napi_throw_error(env, nullptr, "Node-API napi_serialize fail");
        return nullptr;
    }
    // 构造napi_value类型的数据，用于接收将native数据转化为ts对象后的数据
    napi_value result = nullptr;
    napi_deserialize(env, data, &result);
    napi_value number = nullptr;
    // 获取native数据转化为ts对象后的数据中的numKey属性的值
    napi_get_named_property(env, result, "numKey", &number);
    // 判断获取到的属性值是否为number类型
    napi_valuetype valuetype;
    napi_typeof(env, number, &valuetype);
    if (valuetype != napi_number) {
        napi_throw_error(env, nullptr, "Node-API Wrong type of argment. Expects a number.");
        return nullptr;
    }
    // 调用napi_delete_serialization_data方法删除序列化数据
    napi_delete_serialization_data(env, data);
    // 返回获取到的属性值
    return number;
}
```

接口声明

```ts
// index.d.ts
export const aboutSerialize: (obj: Object) => number;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
class Obj {
  numKey:number = 0;
}
let obj: Obj = { numKey: 500 };
hilog.info(0x0000, 'testTag', ' Node-API aboutSerialize: %{public}d', testNapi.aboutSerialize(obj));
```

## 根据任务指定的优先级和入队方式进行处理异步线程向ArkTS线程投递的任务

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_call_threadsafe_function_with_priority | 将指定优先级和入队方式的任务投递到ArkTS线程。 |

### 使用示例

#### napi_call_threadsafe_function_with_priority

[使用Node-API接口从异步线程向ArkTS线程投递指定优先级和入队方式的的任务](use-call-threadsafe-function-with-priority.md)

## Sendable相关

### 接口描述

| 接口                       | 描述                               |
| -------------------------- | ---------------------------------- |
| napi_is_sendable           | 判断给定ArkTS value是否是Sendable的。 |
| napi_define_sendable_class | 创建一个sendable类。               |

### 使用示例

#### napi_is_sendable

判断给定ArkTS value是否是Sendable的。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value IsSendable(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    bool isSendable = false;
    napi_is_sendable(env, args[0], &isSendable);
    napi_value result;
    napi_get_boolean(env, isSendable, &result);
    return result;
}
```

接口声明

```ts
// index.d.ts
export const isSendable: <T>(a: T) => boolean;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let value = testNapi.isSendable('createObject');
hilog.info(0x0000, 'testTag', 'Node-API napi_is_sendable: %{public}s', JSON.stringify(value));
```

#### napi_define_sendable_class

创建一个sendable类。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value func(napi_env env, napi_callback_info info) {
    napi_value val;
    napi_create_string_utf8(env, "func result", NAPI_AUTO_LENGTH, &val);
    return val;
}

static napi_value DefineSendableClass(napi_env env) {
    napi_value str;
    napi_create_string_utf8(env, "str", NAPI_AUTO_LENGTH, &str);

    napi_property_descriptor props[] = {
        {"staticStr", nullptr, nullptr, nullptr, nullptr, str,
         static_cast<napi_property_attributes>(napi_static | napi_writable), nullptr},
        {"staticFunc", nullptr, func, nullptr, nullptr, nullptr, napi_static, nullptr},
        {"str", nullptr, nullptr, nullptr, nullptr, str, static_cast<napi_property_attributes>(1 << 9 | napi_writable),
         nullptr},
        {"func", nullptr, nullptr, nullptr, nullptr, nullptr,
         static_cast<napi_property_attributes>(1 << 11 | napi_writable), nullptr},
    };

    napi_value sendableClass = nullptr;
    napi_define_sendable_class(
        env, "SendableClass", NAPI_AUTO_LENGTH,
        [](napi_env env, napi_callback_info info) -> napi_value {
            napi_value thisVar = nullptr;
            napi_get_cb_info(env, info, nullptr, nullptr, &thisVar, nullptr);
            napi_value str;
            napi_create_string_utf8(env, "instance str", NAPI_AUTO_LENGTH, &str);
            napi_property_descriptor props[] = {
                {"str", nullptr, nullptr, nullptr, nullptr, str, napi_default, nullptr},
                {"func", nullptr, func, nullptr, nullptr, nullptr, napi_default, nullptr},
            };
            napi_define_properties(env, thisVar, sizeof(props) / sizeof(props[0]), props);
            return thisVar;
        },
        nullptr, sizeof(props) / sizeof(props[0]), props, nullptr, &sendableClass);

    return sendableClass;
}
```

接口声明

```ts
// index.d.ts
@Sendable
export class SendableClass {
  static staticStr: string;
  static staticFunc(): string;
  str: string;
  func(): string;
}
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let value = new testNapi.SendableClass();
hilog.info(0x0000, 'testTag', 'Node-API napi_define_sendable_class: %{public}s', value.str);
```

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
