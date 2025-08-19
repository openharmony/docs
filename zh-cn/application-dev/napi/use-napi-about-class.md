# 使用Node-API进行class相关开发
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## 简介

使用Node-API接口进行class相关开发，处理ArkTS中的类，例如定义类、构造实例等。

## 基本概念

在使用Node-API接口进行class相关开发时，需要理解以下基本概念：

- **类**：类是用于创建对象的模板。它提供了一种封装数据和行为的方式，以便于对数据进行处理和操作。类在ArkTS中是建立在原型（prototype）的基础上的，并且还引入了一些类独有的语法和语义。
- **实例**：实例是通过类创建具体的对象。类定义了对象的结构和行为，而实例则是类的具体表现。通过实例化类，我们可以访问类中定义的属性和方法，并且每个实例都具有自己的属性值。

## 场景和功能介绍

以下Node-API接口主要用于处理class。他们的使用场景如下：
| 接口 | 描述 |
| -------- | -------- |
| napi_new_instance | 需要通过给定的构造函数构建一个实例时，可以使用这个函数。 |
| napi_get_new_target | 使用此函数获取构造函数调用的new.target。 |
| napi_define_class | 在Node-API模块定义与ArkTS类相对应的类。这个函数允许将Node-API模块类绑定到ArkTS类。 |
| napi_wrap | 在ArkTS对象上绑定一个Node-API模块对象实例。这个函数通常在将Node-API模块对象与ArkTS对象进行绑定时使用，以便在ArkTS中使用本地对象的方法和属性。 |
| napi_unwrap | 从ArkTS对象上获取之前绑定的Node-API模块对象实例。 |
| napi_remove_wrap | 从ArkTS对象上获取之前绑定的Node-API模块对象实例，并解除绑定。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。

### napi_new_instance

通过给定的构造函数实例化一个对象，将这个对象返回ArkTS侧使用。

> **说明：**
>
> 参数constructor不是function类型则返回napi_function_expected。

cpp部分代码

```cpp
static napi_value NewInstance(napi_env env, napi_callback_info info)
{
    // 传入并解析参数，第一个参数为传入的构造函数，第二个参数为需要传入构造函数的参数
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 调用napi_new_instance接口，实例化一个对象，将这个对象返回
    napi_value result = nullptr;
    napi_new_instance(env, args[0], 1, &args[1], &result);
    return result;
}
```
<!-- @[napi_new_instance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIClass/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const newInstance: (obj: Object, param: string) => Object;
```
<!-- @[napi_new_instance_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIClass/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
class Fruit {
  name: string;
  constructor(name: string) {
    this.name = name;
  }
}
// 调用函数，用变量obj接收函数返回的实例化对象
let obj = testNapi.newInstance(Fruit, 'test');
// 打印实例化对象obj的信息
hilog.info(0x0000, 'Node-API', 'napi_new_instance %{public}s', JSON.stringify(obj));
```
<!-- @[ark_napi_new_instance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIClass/entry/src/main/ets/pages/Index.ets) -->

### napi_get_new_target

用于获取构造函数的new.target值。在ArkTS中，new.target是一个特殊的元属性，用于在构造函数中判断是否通过new关键字调用了该构造函数。

示例代码可以参考链接：

[Native与ArkTS对象绑定](use-napi-object-wrap.md)

### napi_define_class

用于定义一个ArkTS类。该函数允许在Node-API模块中创建一个ArkTS类，并将类的方法和属性与相应的Node-API模块关联起来。

示例代码可以参考链接：

[Native与ArkTS对象绑定](use-napi-object-wrap.md)

### napi_wrap

在ArkTS object上绑定一个native对象实例。

> **说明：**
>
> 参数js_object不为object类型或function类型时返回napi_object_expected。

### napi_unwrap

从一个被包装的对象中解除包装并获取与之关联的数据指针。

> **说明：**
>
> 参数js_object不为object类型或function类型时返回napi_object_expected。

### napi_remove_wrap

从ArkTS object上获取先前绑定的native对象实例，并解除绑定。

> **说明：**
>
> 参数js_object不为object类型或function类型时返回napi_object_expected。

cpp部分代码

```cpp
#include <hilog/log.h>
#include <string>
#include "napi/native_api.h"

static constexpr int INT_ARG_18 = 18; // 年龄18岁

struct Object {
    std::string name;
    int32_t age;
};

static void DerefItem(napi_env env, void *data, void *hint) {
    // 可选的原生回调，用于在ArkTS对象被垃圾回收时释放原生实例
    OH_LOG_INFO(LOG_APP, "Node-API DerefItem");
    Object *obj = reinterpret_cast<Object *>(data);
    if (obj != nullptr) {
        delete obj;
    }
}

static napi_value Wrap(napi_env env, napi_callback_info info)
{
    OH_LOG_INFO(LOG_APP, "Node-API wrap");
    // 初始化Node-API模块的object
    struct Object *obj = new struct Object();
    obj->name = "liLei";
    obj->age = INT_ARG_18;
    size_t argc = 1;
    napi_value toWrap;
    // 调用napi_wrap将Node-API模块的object绑定到ArkTS object上
    napi_status status_cb = napi_get_cb_info(env, info, &argc, &toWrap, NULL, NULL);
    if (status_cb != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "napi_get_cb_info failed");
        delete obj;
        return nullptr;
    }
    napi_status status = napi_wrap(env, toWrap, reinterpret_cast<void *>(obj), DerefItem, NULL, NULL);
    if (status != napi_ok) {
        // 主动释放内存
        delete obj;
    }

    return toWrap;
}

static napi_value RemoveWrap(napi_env env, napi_callback_info info)
{
    OH_LOG_INFO(LOG_APP, "Node-API removeWrap");
    size_t argc = 1;
    napi_value wrapped = nullptr;
    void *data = nullptr;
    // 调用napi_remove_wrap从一个被包装的对象中解除包装
    napi_get_cb_info(env, info, &argc, &wrapped, nullptr, nullptr);
    napi_remove_wrap(env, wrapped, &data);
    return nullptr;
}

static napi_value UnWrap(napi_env env, napi_callback_info info)
{
    OH_LOG_INFO(LOG_APP, "Node-API unWrap");
    size_t argc = 1;
    napi_value wrapped = nullptr;
    napi_get_cb_info(env, info, &argc, &wrapped, nullptr, nullptr);
    // 调用napi_unwrap取出绑定在ArkTS object中的数据并打印
    struct Object *data = nullptr;
    napi_status status = napi_unwrap(env, wrapped, reinterpret_cast<void **>(&data));
    if (status != napi_ok || data == nullptr) {
        OH_LOG_ERROR(LOG_APP, "Node-API napi_unwrap failed or data is nullptr");
        return nullptr;
    }
    OH_LOG_INFO(LOG_APP, "Node-API name: %{public}s", data->name.c_str());
    OH_LOG_INFO(LOG_APP, "Node-API age: %{public}d", data->age);
    return nullptr;
}
```
<!-- @[napi_wrap_unwrap_remove_wrap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIClass/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const wrap: (obj: Object) => Object;
export const unWrap: (obj: Object) => void;
export const removeWrap: (obj: Object) => void;
```
<!-- @[napi_wrap_unwrap_remove_wrap_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIClass/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
    class Obj {}
    let obj: Obj = {};
    testNapi.wrap(obj)
    testNapi.unWrap(obj)
    testNapi.removeWrap(obj)
} catch (error) {
    hilog.error(0x0000, 'testTag', 'Test Node-API error: %{public}s', error.message);
}
```
<!-- @[ark_napi_wrap_unwrap_remove_wrap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIClass/entry/src/main/ets/pages/Index.ets) -->

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
