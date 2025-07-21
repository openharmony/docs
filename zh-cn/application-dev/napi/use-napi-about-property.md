# 使用Node-API接口设置ArkTS对象的属性

## 简介

使用Node-API接口获取和设置ArkTS对象的属性，实现更复杂的功能和逻辑。

## 基本概念

处理ArkTS对象属性，确保正确访问、设置、删除属性，并了解属性的继承关系和枚举特性。以下是一些关键概念：

- **对象（Object）**：在ArkTS中，对象是一种复合数据类型，它允许存储多个不同类型的值作为一个单独的实体。对象是属性和方法的集合。属性是与对象相关联的值，而方法则是对象可以执行的操作。
- **属性（Property）**：在ArkTS中，属性是对象特征的键值对。每个属性都有一个名字（也称为键或标识符）和一个值。属性的值可以是任意数据类型，包括基本类型、对象和函数。
- **可枚举属性（EnumerableProperty）**：在ArkTS中，对象的属性分为可枚举和不可枚举之分，它们是由属性的enumerable值决定的，即内部 “可枚举” 标志设置为true或false。可枚举性决定了这个属性能否被 `for...in` 查找遍历到。
- **自有属性（OwnProperty）**：自有属性直接定义在对象上的属性，而不是从原型链上继承来的属性。

## 场景和功能介绍

以下Node-API接口提供了对ArkTS对象属性的操作，包括设置、获取、删除和检查属性是否存在。使用场景如下：
| 接口 | 描述 |
| -------- | -------- |
| napi_get_property_names | 在进行对象操作或调试时，有时需要获取对象的属性和属性名。此接口可以提取对象的属性名，用于动态获取对象的属性信息。 |
| napi_set_property | 此接口可以动态地向对象添加属性。也可修改对象的属性值，满足动态属性值变更的需求。 |
| napi_get_property | 在调用Node-API模块的函数或方法时，可能需要将ArkTS对象的属性值作为参数传递。此接口可以获取属性值，并将其传递给其他函数。 |
| napi_has_property | 在进行属性访问之前，通常需要先检查对象中是否存在指定的属性。此接口可以检查对象中是否存在指定的属性，避免访问不存在属性导致的异常。 |
| napi_delete_property | 此函数用于删除ArkTS对象上的属性。 |
| napi_has_own_property | 此函数用于检查ArkTS对象是否直接拥有（而不是从其原型链上继承）某个属性。 |
| napi_set_named_property | 此函数用于将值赋给ArkTS对象的命名属性。 |
| napi_get_named_property | 此函数用于获取ArkTS对象的命名属性值。 |
| napi_has_named_property | 此函数用于检查ArkTS对象是否包含某个命名属性。 |
| napi_define_properties | 此函数可以在指定的Object中自定义属性，从ArkTS访问和操作这些属性。 |
| napi_get_all_property_names | 此接口可以获取对象的所有属性名称，检查是否包含特定属性名。 |

## 使用示例

Node-API接口开发流程可参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文展示接口对应C++及ArkTS代码。

### napi_get_property_names

以字符串数组的形式获取对象的可枚举属性的名称。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetPropertyNames(napi_env env, napi_callback_info info)
{
    // 解析ArkTS的传参
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 以字符串数组的形式获取对象的可枚举属性的名称，以result传出
    napi_value result;
    napi_status status = napi_get_property_names(env, args[0], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_get_property_names fail");
        return nullptr;
    }
    return result;
}
```
<!-- @[napi_get_property_names](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getPropertyNames: (obj: Object) => Array<string> | void;
```
<!-- @[napi_get_property_names_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  class Obj {
    data: number = 0
    message: string = ""
  }
  let obj: Obj = { data: 0, message: "hello world"};
  let propertyNames = testNapi.getPropertyNames(obj);
  if (Array.isArray(propertyNames) && propertyNames.length > 0) {
    hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_property_names: %{public}s', propertyNames[0]);
    hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_property_names: %{public}s', propertyNames[1]);
  }
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_get_property_names error: %{public}s', error.message);
}
```
<!-- @[ark_napi_get_property_names](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

### napi_set_property

将给定的属性与值设置入给定的Object。

cpp部分代码

```cpp
#include "napi/native_api.h"

static constexpr int INT_ARG_2 = 2; // 入参索引

static napi_value SetProperty(napi_env env, napi_callback_info info)
{
    // 接收ArkTS侧传入的三个参数：第一个参数为想要设置的object，第二个参数为属性，第三个参数为属性对应的值
    size_t argc = 3;
    napi_value args[3] = {nullptr};
    napi_status status = napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_get_cb_info fail");
    }
    // 通过调用napi_set_property接口将属性与值设置入object，如果失败，直接抛出错误
    status = napi_set_property(env, args[0], args[1], args[INT_ARG_2]);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_set_property fail");
        return nullptr;
    }
    // 返回设置成功的object对象
    return args[0];
}
```
<!-- @[napi_set_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const setProperty: (obj: Object, key: String, value: string) => Object | void;
```
<!-- @[napi_set_property_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  class Obj {
    data: number = 0
    message: string = ""
  }
  let obj: Obj = { data: 0, message: "hello world"};
  let result = testNapi.setProperty(obj, "code", "hi");
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_property: %{public}s', JSON.stringify(result));
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_property error: %{public}s', error.message);
}
```
<!-- @[ark_napi_set_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

### napi_get_property

获取object指定的属性的值。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetProperty(napi_env env, napi_callback_info info)
{
    // 接收两个ArkTS传来的参数
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 传入的第一个参数为要检测的object，第二个对象为要检测的属性，通过调用napi_get_property接口获取对应的值
    napi_value result;
    napi_status status = napi_get_property(env, args[0], args[1], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_get_property fail");
        return nullptr;
    }
    return result;
}
```
<!-- @[napi_get_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getProperty: (obj: Object, key: string) => string | void;
```
<!-- @[napi_get_property_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  class Obj {
    data: number = 0
    message: string = ""
  }
  let obj: Obj = { data: 0, message: "hello world"};
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_property: %{public}s', testNapi.getProperty(obj, "message"));
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_property error: %{public}s', error.message);
}
```
<!-- @[ark_napi_get_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

### napi_has_property

检查对象中是否存在指定的属性，避免访问不存在属性导致的异常。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value HasProperty(napi_env env, napi_callback_info info)
{
    // 从ArkTS侧传入两个参数：第一个参数为要检验的对象，第二个参数为要检测是否存在对象的属性
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // 将参数传入napi_has_property方法中，若接口调用成功则将结果转化为napi_value类型抛出，否则抛出错误
    bool result;
    napi_status status = napi_has_property(env, args[0], args[1], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_has_property fail");
        return nullptr;
    }

    // 若传入属性存在传入对象中，则输出true将结果转化为napi_value类型抛出
    napi_value returnResult;
    napi_get_boolean(env, result, &returnResult);
    return returnResult;
}
```
<!-- @[napi_has_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const hasProperty: (obj: Object, key: number | string) => boolean | void;
```
<!-- @[napi_has_property_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  class Obj {
    data: number = 0
    message: string = ""
  }
  let obj: Obj = { data: 0, message: "hello world"};
  let resultFalse = testNapi.hasProperty(obj, 0);
  let resultTrue = testNapi.hasProperty(obj, "data");
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_property: %{public}s', JSON.stringify(resultFalse));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_property: %{public}s', JSON.stringify(resultTrue));
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_property error: %{public}s', error.message);
}
```
<!-- @[ark_napi_has_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

### napi_delete_property

尝试从给定的Object中删除由key指定的属性，并返回操作的结果。
如果对象不可扩展或属性不可配置，则可能无法删除该属性。

cpp部分代码

```cpp
#include "napi/native_api.h"

// 从传入的Object对象中删除指定属性，返回是否删除成功的bool结果值
static napi_value DeleteProperty(napi_env env, napi_callback_info info)
{
    // 接收两个ArkTS传来的参数
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    napi_valuetype valueType;
    napi_typeof(env, args[0], &valueType);
    if (valueType != napi_object) {
        napi_throw_error(env, nullptr, "Expects an object as argument.");
        return nullptr;
    }
    // 删除指定属性，结果存储在result中
    bool result = false;
    napi_status status = napi_delete_property(env, args[0], args[1], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_delete_property failed");
        return nullptr;
    }
    // 将bool结果转换为napi_value并返回
    napi_value ret;
    napi_get_boolean(env, result, &ret);
    return ret;
}
```
<!-- @[napi_delete_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const deleteProperty: (obj: Object, key:string) => boolean;
```
<!-- @[napi_delete_property_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
class Obj {
  first: number = 0;
}
let obj: Obj = { first: 1};
hilog.info(0x0000, 'testTag', 'Test Node-API napi_delete_property first: %{public}s', testNapi.deleteProperty(obj, 'first'));
// 设置新的属性为不可配置
// 这里的Object.defineProperty方法在DevEco Studio 4.1.0.400及其以上版本不支持，需在ts使用
Object.defineProperty(obj, 'config', {
  configurable: false,
  value: "value"
})
hilog.info(0x0000, 'testTag', 'Test Node-API napi_delete_property config: %{public}s', testNapi.deleteProperty(obj, 'config'));
```
<!-- @[ark_napi_delete_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/napiDeleteProperty.ts) -->

### napi_has_own_property

用于检查传入的Object是否包含自己的命名属性，不包括从原型链上继承的属性。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value NapiHasOwnProperty(napi_env env, napi_callback_info info)
{
    // 接收两个ArkTS传来的参数
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 检查第一个参数是否为对象
    napi_valuetype valueTypeObj;
    napi_typeof(env, args[0], &valueTypeObj);
    if (valueTypeObj != napi_object) {
        napi_throw_error(env, nullptr, "First argument must be an object.");
        return nullptr;
    }
    // 检查第二个参数是否为string
    napi_valuetype valuetypeStr;
    napi_typeof(env, args[1], &valuetypeStr);
    if (valuetypeStr != napi_string) {
        napi_throw_error(env, nullptr, "Second argument must be a string.");
        return nullptr;
    }
    // 检查对象是否具有指定属性，结果存储在hasProperty中
    bool hasProperty;
    napi_status status = napi_has_own_property(env, args[0], args[1], &hasProperty);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_has_own_property failed");
        return nullptr;
    }
    // 将bool结果转换为napi_value并返回
    napi_value result;
    napi_get_boolean(env, hasProperty, &result);
    return result;
}
```
<!-- @[napi_has_own_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const napiHasOwnProperty: (obj: Object, key:string) => boolean | void;
```
<!-- @[napi_has_own_property_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

let myObj = { 'myProperty': 1 };
let inheritedObj = { 'inheritedProperty': 2 };
// 这里的Object.setPrototypeOf方法在DevEco Studio 4.1.0.400及其以上版本不支持，需在ts使用
Object.setPrototypeOf(myObj, inheritedObj);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_own_property my: %{public}s', testNapi.napiHasOwnProperty(myObj, 'myProperty'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_own_property inherited: %{public}s', testNapi.napiHasOwnProperty(myObj, 'inheritedProperty'));
```
<!-- @[ark_napi_has_own_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/napiHasOwnProperty.ts) -->

### napi_set_named_property

在传入的ArkTS对象上添加一个命名属性。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value NapiSetNamedProperty(napi_env env, napi_callback_info info)
{
    // 接收一个ArkTS传来的参数
    size_t argc = 1;
    napi_value str;
    const int32_t strLength = 32;
    char strKey[strLength] = "";
    napi_get_cb_info(env, info, &argc, &str, nullptr, nullptr);
    // 获取传入参数字符串并存储在strKey中
    size_t keyLength;
    napi_get_value_string_utf8(env, str, strKey, strLength, &keyLength);
    // 创建一个新对象
    napi_value newObj;
    napi_create_object(env, &newObj);
    // 设置整数值1234为属性值
    int32_t value = 1234;
    napi_value numValue;
    napi_create_int32(env, value, &numValue);
    // 将整数值与指定属性名关联
    napi_status status = napi_set_named_property(env, newObj, strKey, numValue);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_set_named_property failed");
        return nullptr;
    }
    // 返回设置了命名属性的对象newObj
    return newObj;
}
```
<!-- @[napi_set_named_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const napiSetNamedProperty: (key: string) => Object | void;
```
<!-- @[napi_set_named_property_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

let obj = testNapi.napiSetNamedProperty('myProperty');
let objAsString = JSON.stringify(obj);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_named_property: %{public}s', objAsString);
```
<!-- @[ark_napi_set_named_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

### napi_get_named_property

从ArkTS对象中获取命名属性的值。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value NapiGetNamedProperty(napi_env env, napi_callback_info info)
{
    // 接收两个ArkTS传来的参数
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    const int32_t strLength = 32;
    char strKey[strLength] = "";
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 获取要获取的属性名
    size_t keyLength;
    napi_get_value_string_utf8(env, args[1], strKey, strLength, &keyLength);
    // 获取指定属性的值并存储在result中
    napi_value result;
    napi_status status = napi_get_named_property(env, args[0], strKey, &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_get_named_property failed");
        return nullptr;
    }
    // 返回result
    return result;
}
```
<!-- @[napi_get_named_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const napiGetNamedProperty: (obj: Object, key:string) => boolean | number | string | Object | void;
```
<!-- @[napi_get_named_property_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';

interface NestedObj {
  nestedStr: string;
  nestedNum: number;
}
class Obj {
  str: string = "";
  num: number = 0;
  bol: boolean = false;
  nestedObj: NestedObj = { nestedStr: "", nestedNum: 0 };
}
let obj: Obj = {str: "bar", num: 42, bol: true,
  nestedObj: { nestedStr: "nestedValue", nestedNum: 123 }};
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}s', testNapi.napiGetNamedProperty(obj, 'str'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}d', testNapi.napiGetNamedProperty(obj, 'num'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}s', testNapi.napiGetNamedProperty(obj, 'bol'));
let nestedObj = testNapi.napiGetNamedProperty(obj, 'nestedObj');
let objAsString = JSON.stringify(nestedObj);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}s', objAsString);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_named_property : %{public}s', testNapi.napiGetNamedProperty(obj, 'null'));
```
<!-- @[ark_napi_get_named_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

### napi_has_named_property

检查ArkTS对象中是否具有指定的命名属性。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value NapiHasNamedProperty(napi_env env, napi_callback_info info)
{
    // 接收两个ArkTS传来的参数
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    const int32_t strLength = 32;
    char strKey[strLength] = "";
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 获取要检查的属性名
    size_t keyLength;
    napi_get_value_string_utf8(env, args[1], strKey, strLength, &keyLength);
    // 检查对象是否具有指定命名的属性，并将结果存储在hasProperty中
    bool hasProperty = false;
    napi_status status = napi_has_named_property(env, args[0], strKey, &hasProperty);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_has_named_property failed");
        return nullptr;
    }
    // 将bool结果转换为napi_value并返回
    napi_value result;
    napi_get_boolean(env, hasProperty, &result);
    return result;
}
```
<!-- @[napi_has_named_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const napiHasNamedProperty: (obj: Object, key:string) => boolean | void;
```
<!-- @[napi_has_named_property_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
interface NestedObj {
  nestedStr: string;
  nestedNum: number;
}
class Obj {
  str: string = "";
  num: number = 0;
  bol: boolean = false;
  nestedObj: NestedObj = { nestedStr: "", nestedNum: 0 };
}
let obj: Obj = {str: "bar", num: 42, bol: true,
  nestedObj: { nestedStr: "nestedValue", nestedNum: 123 }};
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_named_property : %{public}s', testNapi.napiHasNamedProperty(obj, 'str'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_named_property : %{public}s', testNapi.napiHasNamedProperty(obj, 'nestedStr'));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_named_property : %{public}s', testNapi.napiHasNamedProperty(obj, 'bol'));
```
<!-- @[ark_napi_has_named_property](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

### napi_define_properties

设置对象的属性。

cpp部分代码

```cpp
#include <string>
#include "napi/native_api.h"

static napi_value DefineMethodPropertiesExample(napi_env env, napi_callback_info info)
{
    // 创建一个int32类型的属性值
    int32_t propValue = 26;
    napi_value returnValue = nullptr;
    napi_create_int32(env, propValue, &returnValue);
    return returnValue;
}
// Getter回调函数
static napi_value GetterCallback(napi_env env, napi_callback_info info)
{
    napi_value result;
    const char *str = u8"World!";
    size_t length = strlen(str);
    // 创建属性的值
    napi_create_string_utf8(env, str, length, &result);
    return result;
}

// Setter回调函数
static napi_value SetterCallback(napi_env env, napi_callback_info info)
{
    // 获取传递给setter的参数
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_value result;
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    size_t length = 0;
    napi_get_value_string_utf8(env, argv[0], nullptr, 0, &length);
    char* buf = new char[length + 1];
    std::memset(buf, 0, length + 1);
    napi_get_value_string_utf8(env, argv[0], buf, length + 1, &length);
    napi_create_string_utf8(env, buf, length, &result);
    delete[] buf;
    return result;
}
static napi_value DefineMethodProperties(napi_env env, napi_callback_info info)
{
    napi_value obj;
    napi_create_object(env, &obj);
    // 在obj对象上定义了一个函数defineMethodPropertiesExample，在函数defineMethodPropertiesExample中定义了一个变量并返回，在调用obj的这个对象时可以调用这个函数
    napi_property_descriptor descriptor[] = {
        {"defineMethodPropertiesExample", nullptr, DefineMethodPropertiesExample, nullptr, nullptr, nullptr, napi_default, nullptr}};
    napi_define_properties(env, obj, sizeof(descriptor) / sizeof(descriptor[0]), descriptor);
    return obj;
}
static napi_value DefineStringProperties(napi_env env, napi_callback_info info)
{
    napi_value obj;
    napi_create_object(env, &obj);
    // 创建一个string类型的属性值
    napi_value string_value;
    napi_create_string_utf8(env, "Hello!", NAPI_AUTO_LENGTH, &string_value);
    napi_property_descriptor descriptor[] = {
        {"defineStringPropertiesExample", nullptr, nullptr, nullptr, nullptr, string_value, napi_default, nullptr}};
    napi_define_properties(env, obj, sizeof(descriptor) / sizeof(descriptor[0]), descriptor);
    return obj;
}

static napi_value CreateStringWithGetterSetter(napi_env env, napi_callback_info info)
{
    napi_value obj;
    napi_create_object(env, &obj);
    // 定义getter函数
    napi_value getterFn;
    napi_create_function(env, nullptr, 0, GetterCallback, nullptr, &getterFn);
    napi_set_named_property(env, obj, "getterCallback", getterFn);
    // 定义setter函数
    napi_value setterFn;
    napi_create_function(env, nullptr, 0, SetterCallback, nullptr, &setterFn);
    napi_set_named_property(env, obj, "setterCallback", setterFn);
    // 定义带有getter和setter的属性
    napi_property_descriptor desc = {"defineGetterSetter", nullptr, GetterCallback, SetterCallback, nullptr, obj, napi_enumerable, nullptr};
    napi_define_properties(env, obj, 1, &desc);
    return obj;
}
```
<!-- @[napi_define_properties](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export class DefineMethodObj {
  defineMethodPropertiesExample: Function;
}
export class DefineStringObj {
  defineStringPropertiesExample: string;
}
export class DefineGetterSetterObj {
  getterCallback: Function;
  setterCallback: Function;
}
export const defineMethodProperties: () => DefineMethodObj;
export const defineStringProperties: () => DefineStringObj;
export const createStringWithGetterSetter: () => DefineGetterSetterObj;
```
<!-- @[napi_define_properties_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
// 定义method类型的属性
hilog.info(0x0000, 'testTag', 'Test Node-API define_method_properties:%{public}d', testNapi.defineMethodProperties()
  .defineMethodPropertiesExample());
// 定义string类型的属性
hilog.info(0x0000, 'testTag', 'Test Node-API define_string_properties::%{public}s ', testNapi.defineStringProperties()
  .defineStringPropertiesExample);
// getter和setter
hilog.info(0x0000, 'testTag', 'Test Node-API get::%{public}s ', testNapi.createStringWithGetterSetter()
  .getterCallback());
hilog.info(0x0000, 'testTag', 'Test Node-API setter::%{public}s ', testNapi.createStringWithGetterSetter()
  .setterCallback('set data'));
```
<!-- @[ark_napi_define_properties](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

### napi_get_all_property_names

获取传入的ArkTS对象的所有属性名。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetAllPropertyNames(napi_env env, napi_callback_info info)
{
    // 传入一个参数
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // 获取给定对象的所有属性名称
    napi_value result;
    napi_status status = napi_get_all_property_names(env, args[0], napi_key_own_only, napi_key_writable,
                                                     napi_key_numbers_to_strings, &result);
    // 如果获取属性名失败，抛出一个错误
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_get_all_property_names fail");
        return nullptr;
    }

    return result;
}
```
<!-- @[napi_get_all_property_names](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getAllPropertyNames : (obj: Object) => Array<string> | void;
```
<!-- @[napi_get_all_property_names_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import hilog from '@ohos.hilog';
import testNapi from 'libentry.so';
try {
  class Obj {
    data: number = 0
    message: string = ""
  }
  let obj: Obj = { data: 0, message: "hello world"};
  let propertyNames = testNapi.getAllPropertyNames(obj);
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_all_property_names: %{public}s', JSON.stringify(propertyNames));
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_all_property_names error: %{public}s', error.message);
}
```
<!-- @[ark_napi_get_all_property_names](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIProperty/entry/src/main/ets/pages/Index.ets) -->

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
