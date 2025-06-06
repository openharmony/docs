# 使用Node-API扩展能力接口

## 简介

[扩展能力](napi-data-types-interfaces.md#扩展能力)接口进一步扩展了Node-API的功能，提供了一些额外的接口，用于在Node-API模块中与ArkTS进行更灵活的交互和定制，这些接口可以用于创建自定义ArkTS对象等场景。

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

## 模块加载

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_load_module | 用于在Node-API模块中将abc文件作为模块加载，返回模块的命名空间，适用于需要在运行时动态加载模块或资源的应用程序，从而实现灵活的扩展和定制。 |
| napi_load_module_with_info | 用于在Node-API中进行模块的加载，当模块加载出来之后，可以使用函数napi_get_property获取模块导出的变量，也可以使用napi_get_named_property获取模块导出的函数，该函数可以在[新创建的ArkTS基础运行时环境](use-napi-ark-runtime.md)中使用。 |
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
    double valueLeft;
    double valueRight;
    napi_get_value_double(env, args[0], &valueLeft);
    napi_get_value_double(env, args[1], &valueRight);

    // 将转化后的double值相加并转成napi_value返回给ArkTS代码使用
    napi_value sum;
    napi_create_double(env, valueLeft + valueRight, &sum);

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
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

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

用给定的napi_property_descriptor作为属性去创建一个ArkTS对象，并且descriptor的键名必须为string，且不可转为number。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateObjectWithProperties(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
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
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

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
    napi_value argv[1] = {nullptr};
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
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

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
    } else {
        napi_get_boolean(env, true, &returnValue);
    }
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
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

try {
  // 在此处执行错误返回false，成功就返回true
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_run_script_path: %{public}s', testNapi.runScriptPath());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_run_script_path errorMessage: %{public}s', error.message);
}
```

test.js代码，将js代码编成.abc文件，步骤如下：

1. 在SDK的ets/build-tools/ets-loader/bin/ark/build-win/bin目录下放置test.js文件
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

<!--Del-->
[指定异步任务调度优先级](../performance/develop-Native-modules-using-NAPI-safely-and-efficiently.md#指定异步任务调度优先级)
<!--DelEnd-->

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
#include <bits/alltypes.h>
#include <hilog/log.h>
#include <mutex>
#include <unordered_set>
#include <uv.h>
#include "napi/native_api.h"

class Object {
public:
    Object() = default;
    ~Object() = default;

    static Object* GetInstance()
    {
        Object* instance = new Object();
        return instance;
    }

    static napi_value GetAddress(napi_env env, napi_callback_info info)
    {
        napi_value thisVar = nullptr;
        napi_get_cb_info(env, info, nullptr, nullptr, &thisVar, nullptr);
        if (thisVar == nullptr) {
            return nullptr;
        }
        void* object = nullptr;
        napi_unwrap(env, thisVar, &object);
        if (object == nullptr) {
            return nullptr;
        }
        uint64_t addressVal = reinterpret_cast<uint64_t>(object);
        napi_value address = nullptr;
        napi_create_bigint_uint64(env, addressVal, &address);
        return address;
    }

    // 获取数组大小
    static napi_value GetSetSize(napi_env env, napi_callback_info info)
    {
        napi_value thisVar = nullptr;
        napi_get_cb_info(env, info, nullptr, nullptr, &thisVar, nullptr);
        if (thisVar == nullptr) {
            return nullptr;
        }
        void* object = nullptr;
        napi_unwrap(env, thisVar, &object);
        if (object == nullptr) {
            return nullptr;
        }
        std::lock_guard<std::mutex> lock(reinterpret_cast<Object*>(object)->numberSetMutex_);
        uint32_t setSize = reinterpret_cast<Object*>(object)->numberSet_.size();
        napi_value napiSize = nullptr;
        napi_create_uint32(env, setSize, &napiSize);
        return napiSize;
    }

    // 往数组里插入元素
    static napi_value Store(napi_env env, napi_callback_info info)
    {
        size_t argc = 1;
        napi_value args[1] = {nullptr};
        napi_value thisVar = nullptr;
        napi_get_cb_info(env, info, &argc, args, &thisVar, nullptr);
        if (argc != 1) {
            napi_throw_error(env, nullptr, "Store args number must be one.");
            return nullptr;
        }
        napi_valuetype type = napi_undefined;
        napi_typeof(env, args[0], &type);
        if (type != napi_number) {
            napi_throw_error(env, nullptr, "Store args is not number.");
            return nullptr;
        }
        if (thisVar == nullptr) {
            return nullptr;
        }
        uint32_t value = 0;
        napi_get_value_uint32(env, args[0], &value);
        void* object = nullptr;
        napi_unwrap(env, thisVar, &object);
        if (object == nullptr) {
            return nullptr;
        }
        std::lock_guard<std::mutex> lock(reinterpret_cast<Object*>(object)->numberSetMutex_);
        reinterpret_cast<Object *>(object)-> numberSet_.insert(value);
        return nullptr;
    }

    // 删除数组元素
    static napi_value Erase(napi_env env, napi_callback_info info)
    {
        size_t argc = 1;
        napi_value args[1] = {nullptr};
        napi_value thisVar = nullptr;
        napi_get_cb_info(env, info, &argc, args, &thisVar, nullptr);
        if (argc != 1) {
            napi_throw_error(env, nullptr, "Erase args number must be one.");
            return nullptr;
        }
        napi_valuetype type = napi_undefined;
        napi_typeof(env, args[0], &type);
        if (type != napi_number) {
            napi_throw_error(env, nullptr, "Erase args is not number.");
            return nullptr;
        }
        if (thisVar == nullptr) {
            return nullptr;
        }
        uint32_t value = 0;
        napi_get_value_uint32(env, args[0], &value);
        void* object = nullptr;
        napi_unwrap(env, thisVar, &object);
        if (object == nullptr) {
            return nullptr;
        }
        std::lock_guard<std::mutex> lock(reinterpret_cast<Object*>(object)->numberSetMutex_);
        reinterpret_cast<Object *>(object)->numberSet_.erase(value);
        return nullptr;
    }

    // 清空数组
    static napi_value Clear(napi_env env, napi_callback_info info)
    {
        napi_value thisVar = nullptr;
        napi_get_cb_info(env, info, nullptr, nullptr, &thisVar, nullptr);
        if (thisVar == nullptr) {
            return nullptr;
        }
        void* object = nullptr;
        napi_unwrap(env, thisVar, &object);
        if (object == nullptr) {
            return nullptr;
        }
        std::lock_guard<std::mutex> lock(reinterpret_cast<Object*>(object)->numberSetMutex_);
        reinterpret_cast<Object *>(object)->numberSet_.clear();
        return nullptr;
    }

private:
    Object(const Object &) = delete;
    Object &operator=(const Object &) = delete;

    std::unordered_set<uint32_t> numberSet_{};
    std::mutex numberSetMutex_{};
};

void FinializerCallback(napi_env env, void *data, void *hint)
{
    return;
}

// 解绑回调，在序列化时调用，可在对象解绑时执行一些清理操作
void* DetachCallback(napi_env env, void *value, void *hint)
{
    return value;
}

// 绑定回调，在反序列化时调用
napi_value AttachCallback(napi_env env, void* value, void* hint)
{
    napi_value object = nullptr;
    napi_create_object(env, &object);
    napi_property_descriptor desc[] = {
        {"getAddress", nullptr, Object::GetAddress, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getSetSize", nullptr, Object::GetSetSize, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"store", nullptr, Object::Store, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"erase", nullptr, Object::Erase, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"clear", nullptr, Object::Clear, nullptr, nullptr, nullptr, napi_default, nullptr}};
    napi_define_properties(env, object, sizeof(desc) / sizeof(desc[0]), desc);
    // 将JS对象object和native对象value生命周期进行绑定
    napi_status status = napi_wrap(env, object, value, FinializerCallback, nullptr, nullptr);
    if (status != napi_ok) {
        OH_LOG_INFO(LOG_APP, "Node-API attachCallback is failed.");
    }
    // JS对象携带native信息
    napi_coerce_to_native_binding_object(env, object, DetachCallback, AttachCallback, value, hint);
    return object;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        {"getAddress", nullptr, Object::GetAddress, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getSetSize", nullptr, Object::GetSetSize, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"store", nullptr, Object::Store, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"erase", nullptr, Object::Erase, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"clear", nullptr, Object::Clear, nullptr, nullptr, nullptr, napi_default, nullptr}};
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    auto object = Object::GetInstance();
    napi_status status = napi_wrap(env, exports, reinterpret_cast<void*>(object), FinializerCallback, nullptr, nullptr);
    if (status != napi_ok) {
        delete object;
    }
    napi_coerce_to_native_binding_object(env, exports, DetachCallback, AttachCallback, reinterpret_cast<void*>(object),
                                         nullptr);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    napi_module_register(&demoModule);
}
```

接口声明

```ts
// index.d.ts
export const getAddress: () => number;
export const getSetSize: () => number;
export const store: (a: number) => void;
export const erase: (a: number) => void;
export const clear: () => void;
```

ArkTS侧示例代码

```ts
// index.ets
import testNapi from 'libentry.so';
import taskpool from '@ohos.taskpool';

@Concurrent
function getAddress() {
  let address: number = testNapi.getAddress();
  console.info("taskpool:: address is " + address);
}

@Concurrent
function store(a:number, b:number, c:number) {
  let size:number = testNapi.getSetSize();
  console.info("set size is " + size + " before store");
  testNapi.store(a);
  testNapi.store(b);
  testNapi.store(c);
  size = testNapi.getSetSize();
  console.info("set size is " + size + " after store");
}

@Concurrent
function erase(a:number) {
  let size:number = testNapi.getSetSize();
  console.info("set size is " + size + " before erase");
  testNapi.erase(a);
  size = testNapi.getSetSize();
  console.info("set size is " + size + " after erase");
}

@Concurrent
function clear() {
  let size:number = testNapi.getSetSize();
  console.info("set size is " + size + " before clear");
  testNapi.clear();
  size = testNapi.getSetSize();
  console.info("set size is " + size + " after clear");
}

async function test01(): Promise<void> {
    let address:number = testNapi.getAddress();
    console.info("host thread address is " + address);

    let task1 = new taskpool.Task(getAddress);
    await taskpool.execute(task1);

    let task2 = new taskpool.Task(store, 1, 2, 3);
    await taskpool.execute(task2);

    let task3 = new taskpool.Task(store, 4, 5, 6);
    await taskpool.execute(task3);

    let task4 = new taskpool.Task(erase, 3);
    await taskpool.execute(task4);

    let task5 = new taskpool.Task(erase, 5);
    await taskpool.execute(task5);

    let task6 = new taskpool.Task(clear);
    await taskpool.execute(task6);
}

test01();
```

**注意事项**

对ArkTS对象A调用`napi_coerce_to_native_binding_object`将开发者实现的detach/attach回调和native对象信息加到A上，再将A跨线程传递。跨线程传递需要对A进行序列化和反序列化，在当前线程thread1序列化A得到数据data，序列化阶段执行detach回调。然后将data传给目标线程thread2，在thread2中反序列化data，执行attach回调，最终得到ArkTS对象A。

![napi_coerce_to_native_binding_object](figures/napi_coerce_to_native_binding_object.png)

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

[使用Node-API接口创建ArkTS运行时环境](use-napi-ark-runtime.md)

## 序列化和反序列化

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_serialize | 将ArkTS对象转换为native数据。第一个参数env是接口执行的ArkTS环境；第二个参数object是待序列化的ArkTS对象；第三个参数transfer_list是存放需要以transfer传递的arrayBuffer的array，如不涉及可传undefined；第四个参数clone_list是存放需要克隆传递的Sendable对象的array，如不涉及可传undefined；第五个参数result是序列化结果。 |
| napi_deserialize | 将native数据转为ArkTS对象。第一个参数env是接口执行的ArkTS环境；第二个参数buffer是序列化数据；第三个参数object是反序列化得到的结果。 |
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
        napi_throw_error(env, nullptr, "Node-API Wrong type of argument. Expects a number.");
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
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
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
| napi_call_threadsafe_function_with_priority | 将指定优先级和入队方式的任务投递到ArkTS主线程。 |

### 使用示例

#### napi_call_threadsafe_function_with_priority

[使用Node-API接口从异步线程向ArkTS线程投递指定优先级和入队方式的的任务](use-call-threadsafe-function-with-priority.md)

## Sendable相关

### 接口描述

| 接口                       | 描述                               |
| -------------------------- | ---------------------------------- |
| napi_is_sendable           | 判断给定ArkTS value是否是Sendable的。 |
| napi_define_sendable_class | 创建一个sendable类。               |
| napi_create_sendable_object_with_properties | 使用给定的napi_property_descriptor创建一个sendable对象。|
| napi_create_sendable_array | 创建一个sendable数组。|
| napi_create_sendable_array_with_length | 创建一个指定长度的sendable数组。|
| napi_create_sendable_arraybuffer | 创建一个sendable ArrayBuffer。|
| napi_create_sendable_typedarray | 创建一个sendable TypedArray。|
| napi_wrap_sendable | 包裹一个native实例到ArkTS对象中。|
| napi_wrap_sendable_with_size | 包裹一个native实例到ArkTS对象中并指定大小。|
| napi_unwrap_sendable | 获取ArkTS对象包裹的native实例。|
| napi_remove_wrap_sendable | 移除并获取ArkTS对象包裹的native实例，移除后回调将不再触发，需手动delete释放内存。|

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
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

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

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {};
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    napi_value cons = DefineSendableClass(env);
    napi_set_named_property(env, exports, "SendableClass", cons);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    napi_module_register(&demoModule);
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
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

let value = new testNapi.SendableClass();
hilog.info(0x0000, 'testTag', 'Node-API napi_define_sendable_class: %{public}s', value.str);
```

#### napi_create_sendable_object_with_properties

使用给定的napi_property_descriptor创建一个sendable对象。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetSendableObject(napi_env env, napi_callback_info info) {
    napi_value val_true;
    napi_get_boolean(env, true, &val_true);
    napi_property_descriptor desc1[] = {
        {"x", nullptr, nullptr, nullptr, nullptr, val_true, napi_default_jsproperty, nullptr},
    };
    napi_value obj;
    napi_create_sendable_object_with_properties(env, 1, desc1, &obj);
    return obj;
}
```

接口声明

```ts
// index.d.ts
export const getSendableObject: () => { x: true };
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

let value = testNapi.getSendableObject();
hilog.info(0x0000, 'testTag', 'Node-API napi_create_sendable_object_with_properties: %{public}s', JSON.stringify(value));
```

#### napi_create_sendable_array

创建一个sendable数组。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetSendableArray(napi_env env, napi_callback_info info) {
    napi_value result = nullptr;
    napi_create_sendable_array(env, &result);
    return result;
}
```

接口声明

```ts
// index.d.ts
export const getSendableArray: () => [];
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

let value = testNapi.getSendableArray();
hilog.info(0x0000, 'testTag', 'Node-API napi_create_sendable_array: %{public}s', JSON.stringify(value));
```

#### napi_create_sendable_array_with_length

创建一个指定长度的sendable数组。

cpp部分代码

```cpp
static napi_value GetSendableArrayWithLength(napi_env env, napi_callback_info info) {
    napi_value result = nullptr;
    napi_create_sendable_array_with_length(env, 1, &result);
    return result;
}
```

接口声明

```ts
// index.d.ts
export const getSendableArrayWithLength: () => [];
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

let value = testNapi.getSendableArrayWithLength();
hilog.info(0x0000, 'testTag', 'Node-API napi_create_sendable_array_with_length: %{public}s', JSON.stringify(value.length));
```

#### napi_create_sendable_arraybuffer

创建一个sendable ArrayBuffer。

cpp部分代码

```cpp
#include "napi/native_api.h"
#include "hilog/log.h"

static napi_value GetSendableArrayBuffer(napi_env env, napi_callback_info info) {
    static size_t LENGTH = 1024;
    void *data;
    napi_value result = nullptr;
    napi_create_sendable_arraybuffer(env, LENGTH, &data, &result);
    bool isArrayBuffer = false;
    napi_is_arraybuffer(env, result, &isArrayBuffer);
    OH_LOG_INFO(LOG_APP, "isArrayBuffer: %{public}d", isArrayBuffer);
    return result;
}
```

接口声明

```ts
// index.d.ts
export const getSendableArrayBuffer: () => void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

testNapi.getSendableArrayBuffer();
```

#### napi_create_sendable_typedarray

创建一个sendable TypedArray。

cpp部分代码

```cpp
#include "napi/native_api.h"
#include "hilog/log.h"

static napi_value GetSendableTypedArray(napi_env env, napi_callback_info info) {
    static size_t LENGTH = 1024;
    static size_t OFFSET = 0;
    void *data;
    napi_value arraybuffer = nullptr;
    napi_create_sendable_arraybuffer(env, LENGTH, &data, &arraybuffer);

    napi_value result = nullptr;
    napi_create_sendable_typedarray(env, napi_uint8_array, LENGTH, arraybuffer, OFFSET, &result);
    bool isTypedArray = false;
    napi_is_typedarray(env, result, &isTypedArray);
    OH_LOG_INFO(LOG_APP, "isTypedArray: %{public}d", isTypedArray);
    return result;
}
```

接口声明

```ts
// index.d.ts
export const getSendableTypedArray: () => void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

testNapi.getSendableTypedArray();
```

#### napi_wrap_sendable

包裹一个native实例到ArkTS对象中。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value WrapSendable(napi_env env, napi_callback_info info) {
    napi_value val_true;
    napi_get_boolean(env, true, &val_true);
    napi_property_descriptor desc1[] = {
        {"x", nullptr, nullptr, nullptr, nullptr, val_true, napi_default_jsproperty, nullptr},
    };
    napi_value obj;
    napi_create_sendable_object_with_properties(env, 1, desc1, &obj);

    const char* testStr = "test";
    napi_wrap_sendable(env, obj, (void*)testStr, [](napi_env env, void* data, void* hint) {}, nullptr);

    return nullptr;
}
```

接口声明

```ts
// index.d.ts
export const wrapSendable: () => void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

testNapi.wrapSendable();
```

#### napi_wrap_sendable_with_size

包裹一个native实例到ArkTS对象中并指定大小。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value WrapSendableWithSize(napi_env env, napi_callback_info info) {
    napi_value val_true;
    napi_get_boolean(env, true, &val_true);
    napi_property_descriptor desc1[] = {
        {"x", nullptr, nullptr, nullptr, nullptr, val_true, napi_default_jsproperty, nullptr},
    };
    napi_value obj;
    napi_create_sendable_object_with_properties(env, 1, desc1, &obj);

    const char* testStr = "test";
    napi_wrap_sendable_with_size(env, obj, (void*)testStr, [](napi_env env, void* data, void* hint) {}, nullptr, 100);

    return nullptr;
}
```

接口声明

```ts
// index.d.ts
export const wrapSendableWithSize: () => void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

testNapi.wrapSendableWithSize();
```

#### napi_unwrap_sendable

获取ArkTS对象包裹的native实例。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value UnwrapSendable(napi_env env, napi_callback_info info) {
    napi_value val_true;
    napi_get_boolean(env, true, &val_true);
    napi_property_descriptor desc1[] = {
        {"x", nullptr, nullptr, nullptr, nullptr, val_true, napi_default_jsproperty, nullptr},
    };
    napi_value obj;
    napi_create_sendable_object_with_properties(env, 1, desc1, &obj);

    const char* testStr = "test";
    napi_wrap_sendable(env, obj, (void*)testStr, [](napi_env env, void* data, void* hint) {}, nullptr);

    char* tmpTestStr = nullptr;
    napi_unwrap_sendable(env, obj, (void**)&tmpTestStr);
    OH_LOG_INFO(LOG_APP, "native value is %{public}s", tmpTestStr);

    return nullptr;
}
```

接口声明

```ts
// index.d.ts
export const unwrapSendable: () => void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

testNapi.unwrapSendable();
```

#### napi_remove_wrap_sendable

移除并获取ArkTS对象包裹的native实例，移除后回调将不再触发，需手动delete释放内存。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value RemoveWrapSendable(napi_env env, napi_callback_info info) {
    napi_value val_true;
    napi_get_boolean(env, true, &val_true);
    napi_property_descriptor desc1[] = {
        {"x", nullptr, nullptr, nullptr, nullptr, val_true, napi_default_jsproperty, nullptr},
    };
    napi_value obj;
    napi_create_sendable_object_with_properties(env, 1, desc1, &obj);

    const char* testStr = "test";
    napi_wrap_sendable(env, obj, (void*)testStr, [](napi_env env, void* data, void* hint) {}, nullptr);

    char* tmpTestStr = nullptr;
    napi_remove_wrap_sendable(env, obj, (void**)&tmpTestStr);
    OH_LOG_INFO(LOG_APP, "native value is %{public}s", tmpTestStr);

    return nullptr;
}
```

接口声明

```ts
// index.d.ts
export const removeWrapSendable: () => void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

testNapi.removeWrapSendable();
```

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```


## napi_wrap接口增强

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_wrap_enhance | 在ArkTS对象上绑定一个Node-API模块对象实例并指定实例大小，开发者可以指定绑定的回调函数是否异步执行，如果异步执行，则回调函数必须是线程安全的。 |

### 使用示例

#### napi_wrap_enhance

在ArkTS对象上绑定一个Node-API模块对象实例并指定实例大小，开发者可以指定绑定的回调函数是否异步执行，如果异步执行，则回调函数必须是线程安全的。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value TestNapiWrapEnhance(napi_env env, napi_callback_info info)
{
    napi_value testClass = nullptr;
    napi_define_class(
        env, "TestClass", NAPI_AUTO_LENGTH,
        [](napi_env env, napi_callback_info info) -> napi_value {
            napi_value thisVar = nullptr;
            napi_get_cb_info(env, info, nullptr, nullptr, &thisVar, nullptr);
            return thisVar;
        },
        nullptr, 0, nullptr, &testClass);

    napi_value obj = nullptr;
    napi_new_instance(env, testClass, 0, nullptr, &obj);
    const char* testStr = "test";
    napi_ref wrappedRef = nullptr;
    napi_wrap_enhance(env, obj, (void*)testStr, [](napi_env env, void* data, void* hint) {}, false, nullptr, sizeof(testStr), &wrappedRef);
    return nullptr;
}
```

接口声明

```ts
// index.d.ts
export const testNapiWrapEnhance: () => void;
```

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

testNapi.testNapiWrapEnhance();
```

## napi提供多上下文环境能力

### 接口描述

| 接口 | 描述 |
| -------- | -------- |
| napi_create_ark_context | 创建基础运行时上下文环境。 |
| napi_destroy_ark_context | 销毁基础运行时上下文环境。 |
### 使用示例

#### napi_create_ark_context、napi_destroy_ark_context

[使用扩展的Node-API接口创建、切换和销毁上下文环境](use-napi-about-context.md)