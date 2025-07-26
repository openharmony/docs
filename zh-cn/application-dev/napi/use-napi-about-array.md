# 使用Node-API接口进行array相关开发

## 简介

使用Node-API接口进行array相关开发时，调用相关接口可以在Node-API模块中直接操作和处理ArkTS中的数组。

## 基本概念

使用Node-API接口进行数组（array）相关开发时，涉及的基本概念主要包括数组的创建、访问、修改、遍历以及与数组相关的操作。这些概念对于理解如何在Node-API模块中与ArkTS数组交互非常重要。以下是一些关键概念：

- **数组的创建**：在Node-API模块中需要创建一个新的ArkTS数组，可以使用napi_create_array接口创建数组，将数组传递给ArkTS层。
- **数组相关操作**：在Node-API模块中通过对应的接口获取ArkTS数组的长度、检索指定索引处的元素以及设置指定索引处的元素值，从而实现Node-API模块与ArkTS数组的交互。
- **TypedArray**：ArkTS中的TypedArray是一种用来描述二进制数据的类数组数据视图，可以简单理解为一种指定元素类型的数组，TypedArray没有直接构造器，但是可以用它的子类构造器构造TypedArray类型的数据。TypedArray的子类有：Int8Array、Uint8Array、Uint8ClampedArray、Int16Array、Int32Array等。
- **DataView**：DataView是ArkTS中的一种视图，是可以从ArrayBuffer对象中读写多种数值类型的底层接口。
- **ArrayBuffer**：ArrayBuffer是固定长度的二进制数据缓冲区。

## 场景和功能介绍

使用Node-API接口进行数组相关开发时，可以处理各种涉及ArkTS数组的操作和交互场景。以下是几个具体的使用场景介绍：
| 接口 | 描述 |
| -------- | -------- |
| napi_create_array | 用于在Node-API模块中向ArkTS层创建一个ArkTS数组对象。 |
| napi_create_array_with_length | 用于在Node-API模块中向ArkTS层创建指定长度的ArkTS数组时。 |
| napi_get_array_length | 用于在Node-API模块中获取ArkTS数组对象的长度。 |
| napi_is_array | 用于在Node-API模块中判断一个napi_value值是否为数组。 |
| napi_set_element | 用于在Node-API模块中对ArkTS数组对象的特定索引处设置一个值。 |
| napi_get_element | 用于在Node-API模块中从ArkTS数组对象的特定索引处获取一个值。 |
| napi_has_element | 用于在Node-API模块中判断ArkTS数组对象请求索引处是否包含元素。 |
| napi_delete_element | 用于在Node-API模块中从ArkTS数组对象中删除请求索引对应的元素。 |
| napi_create_typedarray | 用于在Node-API模块中创建指定类型的TypedArray，例如Uint8Array、Int32Array等，通常用于将Node-API模块中的数据转换为ArkTS中的TypedArray，以便进行高性能的数据处理操作。 |
| napi_is_typedarray | 用于在Node-API模块中判断一个给定的napi_value是否为TypedArray对象。 |
| napi_get_typedarray_info | 用于在Node-API模块中获得某个TypedArray的各种属性。 |
| napi_create_dataview |  用于在Node-API模块中创建一个DataView对象，可以访问和操作二进制数据。 |
| napi_is_dataview | 用于在Node-API模块中判断给定的napi_value是否为ArkTS中的DataView对象。 |
| napi_get_dataview_info | 用于在Node-API模块中获得某个DataView的各种属性。 |

## 使用示例

Node-API接口开发流程参考[使用Node-API实现跨语言交互开发流程](use-napi-process.md)，本文仅对接口对应C++及ArkTS相关代码进行展示。具体使用见示例。

### napi_create_array

用于在Node-API模块中创建一个ArkTS数组。

cpp部分代码

```cpp
#include "napi/native_api.h"

static constexpr int INT_NUM_5 = 5; // 数组长度

static napi_value CreateArray(napi_env env, napi_callback_info info)
{
    // 创建一个空数组
    napi_value jsArray = nullptr;
    napi_create_array(env, &jsArray);
    // 将创建好的数组进行赋值
    for (int i = 0; i < INT_NUM_5; i++) {
        napi_value element;
        napi_create_int32(env, i, &element);
        napi_set_element(env, jsArray, i, element);
    }
    // 返回已创建好的数组
    return jsArray;
}
```
<!-- @[napi_create_array](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createArray: () => number[];
```
<!-- @[napi_create_array_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_array:%{public}s', JSON.stringify(testNapi.createArray()));
```
<!-- @[ark_napi_create_array](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_create_array_with_length

用于在Node-API模块中创建一个具有指定长度的ArkTS数组。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateArrayWithLength(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传入的参数
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_value jsArray = nullptr;
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // 获取传递的数组长度
    int32_t length = 0;
    napi_get_value_int32(env, argv[0], &length);
    // 使用napi_create_array_with_length创建指定长度的数组
    napi_create_array_with_length(env, length, &jsArray);
    // 返回数组
    return jsArray;
}
```
<!-- @[napi_create_array_with_length](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createArrayWithLength: (length: number) => void[];
```
<!-- @[napi_create_array_with_length_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let array = testNapi.createArrayWithLength(6);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_array_with_length:%{public}d', array.length);
```
<!-- @[ark_napi_create_array_with_length](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_get_array_length

获取给定array的长度。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetArrayLength(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传入的参数
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_value result;
    uint32_t length;
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 检查参数是否为数组
    bool is_array;
    napi_is_array(env, args[0], &is_array);
    if (!is_array) {
        napi_throw_type_error(env, nullptr, "Argument must be an array");
        return nullptr;
    }
    napi_get_array_length(env, args[0], &length);
    // 创建返回值
    napi_create_uint32(env, length, &result);
    return result;
}
```
<!-- @[napi_get_array_length](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getArrayLength: (arr: Array<any>) => number | undefined;
```
<!-- @[napi_get_array_length_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

const arr = [0, 1, 2, 3, 4, 5];
hilog.info(0x0000, 'testTag', 'Test Node-API get_array_length:%{public}d', testNapi.getArrayLength(arr));
```
<!-- @[ark_napi_get_array_length](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_is_array

判断给定ArkTS值是否为数组。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value IsArray(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传入的参数
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 调用napi_is_array接口判断给定入参是否为array数组
    bool result;
    napi_status status;
    status = napi_is_array(env, args[0], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_is_array fail");
        return nullptr;
    }
    // 将结果转成napi_value类型返回
    napi_value returnValue;
    napi_get_boolean(env, result, &returnValue);

    return returnValue;
}
```
<!-- @[napi_is_array](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const isArray: <T>(data: Array<T> | T) => boolean | undefined;
```
<!-- @[napi_is_array_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  let value = new Array<number>(1);
  let data = "123";
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_array: %{public}s', testNapi.isArray<number>(value));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_array: %{public}s', testNapi.isArray<string>(data));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_array error: %{public}s', error.message);
}
```
<!-- @[ark_napi_is_array](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_set_element

用于在ArkTS数组中设置指定索引位置的元素。
对于以索引值为键的object，可以使用napi_set_element来设置属性值。

cpp部分代码

```cpp
#include "napi/native_api.h"

static constexpr int INT_ARG_2 = 2; // 入参索引

static napi_value NapiSetElement(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传入的参数
    size_t argc = 3;
    napi_value args[3] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 检查第一个参数是否为数组
    bool isArr = false;
    napi_is_array(env, args[0], &isArr);
    if (!isArr) {
        napi_throw_type_error(env, nullptr, "Argument should be an object of type array");
        return nullptr;
    }
    // 获取要设置的元素索引
    double index = 0;
    napi_get_value_double(env, args[1], &index);
    // 将传入的值设置到数组指定索引位置
    napi_set_element(env, args[0], static_cast<uint32_t>(index), args[INT_ARG_2]);

    return nullptr;
}
```
<!-- @[napi_set_element](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
export const napiSetElement: <T>(arr: Array<T>, index: number, value: T) => void;
```
<!-- @[napi_set_element_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
let arr = [10, 20, 30];
testNapi.napiSetElement<number | string>(arr, 1, 'newElement');
testNapi.napiSetElement<number | string>(arr, 2, 50);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_element arr: %{public}s', arr.toString());
hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_element arr[3]: %{public}s', arr[3]);
interface MyObject {
  first: number;
  second: number;
}
let obj: MyObject = {
  first: 1,
  second: 2
};
testNapi.napiSetElement<number | string | Object>(arr, 4, obj);
let objAsString = JSON.stringify(arr[4]);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_element arr[4]: %{public}s', objAsString);
```
<!-- @[ark_napi_set_element](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_get_element

用于从ArkTS数组中获取请求索引位置的元素值。请求索引值应在数组的有效范围内，如果索引超出数组长度，函数会返回undefined。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value NapiGetElement(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传入的参数
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 获取请求元素的索引值
    uint32_t index;
    napi_get_value_uint32(env, args[1], &index);
    // 获取请求索引位置的元素值并存储在result中
    napi_value result;
    napi_get_element(env, args[0], index, &result);

    return result;
}
```
<!-- @[napi_get_element](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const napiGetElement: <T>(arr: Array<T>, index: number) => number | string | Object | boolean | undefined;
```
<!-- @[napi_get_element_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

interface MyObject {
  first: number;
  second: number;
}
let obj: MyObject = {
  first: 1,
  second: 2
};
let arr = [10, 'hello', null, obj];
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_element arr[0]: %{public}d', testNapi.napiGetElement<number | string | null | Object>(arr, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_element arr[1]: %{public}s', testNapi.napiGetElement<number | string | null | Object>(arr, 1));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_element arr[2]: %{public}s', testNapi.napiGetElement<number | string | null | Object>(arr, 2));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_element arr[3]: %{public}s', testNapi.napiGetElement<number | string | null | Object>(arr, 3));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_element arr[4]: %{public}s', JSON.stringify(testNapi.napiGetElement(arr, 4)));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_element arr[null]: %{public}s', testNapi.napiGetElement<number | string | null | Object>(arr, 5));
```
<!-- @[ark_napi_get_element](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_has_element

用于判断ArkTS数组是否具有指定索引的元素。如果索引超出了对象的有效范围，函数返回false，表示没有元素。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value NapiHasElement(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传入的参数
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 获取要判断的元素的索引
    uint32_t index;
    napi_get_value_uint32(env, args[1], &index);
    // 判断指定索引位置的元素是否存在
    bool hasElement = true;
    napi_has_element(env, args[0], index, &hasElement);
    // 将bool结果转换为napi_value并返回
    napi_value result;
    napi_get_boolean(env, hasElement, &result);
    return result;
}
```
<!-- @[napi_has_element](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const napiHasElement: <T>(arr: Array<T>, index: number) => boolean;
```
<!-- @[napi_has_element_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let arr = [10, 'hello', null, 'world'];
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_element arr[0]: %{public}s', testNapi.napiHasElement<number | string | null>(arr, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_element arr[7]: %{public}s', testNapi.napiHasElement<number | string | null>(arr, 7));
```
<!-- @[ark_napi_has_element](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_delete_element

用于从ArkTS数组对象中删除请求索引的元素。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value NapiDeleteElement(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传入的参数
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 获取要删除的元素的索引
    uint32_t index;
    napi_get_value_uint32(env, args[1], &index);
    // 尝试删除请求索引位置的元素
    bool deleted = true;
    napi_delete_element(env, args[0], index, &deleted);
    // 将bool结果转换为napi_value并返回
    napi_value result;
    napi_get_boolean(env, deleted, &result);
    return result;
}
```
<!-- @[napi_delete_element](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const napiDeleteElement: <T>(arr: Array<T>, index: number) => boolean;
```
<!-- @[napi_delete_element_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
// 需要同时导入前文示例代码中的napiHasElement、napiGetElement接口
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let arr = [10, 'hello', null, 'world'];
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_element arr[0]: %{public}s', testNapi.napiHasElement<number | string | null>(arr, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_delete_element arr[0]: %{public}s', testNapi.napiDeleteElement<number | string | null>(arr, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_element deleted arr[0]: %{public}s', testNapi.napiHasElement<number | string | null>(arr, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_element arr[0]: %{public}d', testNapi.napiGetElement<number | string | null>(arr, 0));
```
<!-- @[ark_napi_delete_element](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_create_typedarray

用于在Node-API模块中通过现有的ArrayBuffer创建指定类型的ArkTS TypedArray。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateTypedArray(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传入的参数
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    int32_t typeNum = 0;
    napi_get_value_int32(env, args[0], &typeNum);
    napi_typedarray_type arrayType;
    // 用于存储每个元素的大小
    size_t elementSize = 0;
    // 根据传递的类型值选择创建对应的类型数组
    arrayType = static_cast<napi_typedarray_type>(typeNum);
    switch (typeNum) {
    case napi_int8_array:
    case napi_uint8_array:
    case napi_uint8_clamped_array:
        elementSize = sizeof(int8_t);
        break;
    case napi_int16_array:
    case napi_uint16_array:
        elementSize = sizeof(int16_t);
        break;
    case napi_int32_array:
    case napi_uint32_array:
        elementSize = sizeof(int32_t);
        break;
    case napi_float32_array:
        elementSize = sizeof(float);
        break;
    case napi_float64_array:
        elementSize = sizeof(double);
        break;
    case napi_bigint64_array:
    case napi_biguint64_array:
        elementSize = sizeof(int64_t);
        break;
    default:
    // 默认创建napi_int8_array类型
        arrayType = napi_int8_array;
        elementSize = sizeof(int8_t);
        break;
    }
    size_t length = 3;
    napi_value arrayBuffer = nullptr;
    napi_value typedArray = nullptr;
    void *data;
    // 创建一个ArrayBuffer
    napi_create_arraybuffer(env, length * elementSize, (void **)&data, &arrayBuffer);
    // 根据给定类型创建TypedArray
    napi_create_typedarray(env, arrayType, length, arrayBuffer, 0, &typedArray);
    return typedArray;
}
```
<!-- @[napi_create_typed_array](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const enum TypedArrayTypes {
  INT8_ARRAY = 0,
  UINT8_ARRAY,
  UINT8_CLAMPED_ARRAY,
  INT16_ARRAY,
  UINT16_ARRAY,
  INT32_ARRAY,
  UINT32_ARRAY,
  FLOAT32_ARRAY,
  FLOAT64_ARRAY,
  BIGINT64_ARRAY,
  BIGuINT64_ARRAY,
}
export const createTypedArray: <T>(type: TypedArrayTypes) => T;
```
<!-- @[napi_create_typed_array_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

// 传递要创建的类型值
let typedArray = testNapi.createTypedArray<Int8Array>(testNapi.TypedArrayTypes["INT8_ARRAY"]);
if (typedArray instanceof Int8Array) {
    hilog.info(0x0000, 'testTag', ' Node-API napi_create_typedarray: Int8Array');
}
let uint8Array = testNapi.createTypedArray<Uint8Array>(testNapi.TypedArrayTypes["UINT8_ARRAY"]);
if (uint8Array instanceof Uint8Array) {
    hilog.info(0x0000, 'testTag', ' Node-API napi_create_typedarray: Uint8Array');
}
```
<!-- @[ark_napi_create_typed_array](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

需要对use-napi-process.md中的模块初始化部分进行修改，具体见如下：

```cpp
#include <string>

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    // 定义的TypedArray类型供ArkTS侧使用，用于存放typedArrayTypes类型，使用示例见ArkTS侧的createTypedArray函数
    napi_value typedArrayTypes;
    napi_create_object(env, &typedArrayTypes);
    napi_value typeIndex;
    std::string typeKeys[] = {
        "INT8_ARRAY",   "UINT8_ARRAY",   "UINT8_CLAMPED_ARRAY", "INT16_ARRAY",      "UINT16_ARRAY",    "INT32_ARRAY",
        "UINT32_ARRAY", "FLOAT32_ARRAY", "FLOAT64_ARRAY",       "BIGINT64_ARRAY", "BIGUINT64_ARRAY",
    };
    for (int32_t i = 0; i < sizeof(typeKeys) / sizeof(typeKeys[0]); i++) {
        napi_create_int32(env, i, &typeIndex);
        napi_set_named_property(env, typedArrayTypes, typeKeys[i].c_str(), typeIndex);
    }
    napi_property_descriptor desc[] = {
        {"createTypedArray", nullptr, CreateTypedArray, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"TypedArrayTypes", nullptr, nullptr, nullptr, nullptr, typedArrayTypes, napi_default, nullptr}
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

```
<!-- @[change_use_napi_process](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

### napi_is_typedarray

用于在Node-API模块中判断ArkTS侧给定的napi_value是否为TypedArray对象。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value IsTypedarray(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传入的参数
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 调用napi_is_typedarray接口判断给定入参类型是否为TypedArray。
    bool result = false;
        napi_status status;
    status = napi_is_typedarray(env, args[0], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_is_typedarray fail");
        return nullptr;
    }
    // 将结果转成napi_value类型返回。
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);

    return returnValue;
}
```
<!-- @[napi_is_typed_array](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const isTypedarray: (data: Object) => boolean | undefined;
```
<!-- @[napi_is_typed_array_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  let value = new Uint8Array([1, 2, 3, 4]);
  let data = "123";
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_typedarray: %{public}s', testNapi.isTypedarray(value));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_typedarray: %{public}s', testNapi.isTypedarray(data));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_typedarray error: %{public}s', error.message);
}
```
<!-- @[ark_napi_is_typed_array](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_get_typedarray_info

获取给定TypedArray的各种属性。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetTypedarrayInfo(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传入的参数，第一个参数为需要获得的信息的TypedArray类型数据，第二个参数为需要获得的信息类型的枚举值
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 将第二个参数转为int32类型便于比较
    int32_t infoTypeParam;
    napi_get_value_int32(env, args[1], &infoTypeParam);
    // 定义枚举类型与ArkTS侧枚举类型InfoType顺序含义一致
    enum InfoType { INFO_TYPE = 1, INFO_LENGTH, INFO_ARRAY_BUFFER, INFO_BYTE_OFFSET };
    void *data;
    napi_typedarray_type type;
    size_t byteOffset, length;
    napi_value arraybuffer;
    // 调用接口napi_get_typedarray_info获得TypedArray类型数据的信息
    napi_get_typedarray_info(env, args[0], &type, &length, &data, &arraybuffer, &byteOffset);
    napi_value result;
    // 根据属性名，返回TypedArray对应的属性值
    switch (infoTypeParam) {
    case INFO_TYPE:
        // 如果传入的参数是int8类型的TypedArray数据，它的类型（type）为napi_int8_array
        napi_value int8_type;
        napi_get_boolean(env, type == napi_int8_array, &int8_type);
        result = int8_type;
        break;
    case INFO_LENGTH:
        // TypedArray中元素的字节长度
        napi_value napiLength;
        napi_create_int32(env, length, &napiLength);
        result = napiLength;
        break;
    case INFO_BYTE_OFFSET:
        // TypedArray数组的第一个元素所在的基础原生数组中的字节偏移量
        napi_value napiByteOffset;
        napi_create_int32(env, byteOffset, &napiByteOffset);
        result = napiByteOffset;
        break;
    case INFO_ARRAY_BUFFER:
        // TypedArray下的ArrayBuffer
        result = arraybuffer;
        break;
    default:
        break;
    }
    return result;
}
```
<!-- @[napi_get_typed_array_info](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getTypedarrayInfo: <T>(typeArray: T, infoType: number) => ArrayBuffer | number | boolean;
```
<!-- @[napi_get_typed_array_info_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

// 传入TypedArray类型数据。TypedArray是一种用来描述二进制数据的类数组数据视图，没有直接构造器，可以用其子类构造类数组
// TypedArray的子类有: Int8Array Uint8Array Uint8ClampedArray Int16Array Int32Array等
let int8Array = new Int8Array([15, 7]);
// 定义枚举类型 这些都是TypedArray的属性
enum InfoType {
    TYPE = 1, // 传入的TypedArray的类型
    LENGTH = 2, // 传入的TypedArray的长度
    ARRAY_BUFFER = 3, // TypedArray下的ArrayBuffer
    BYTE_OFFSET = 4 // 数组的第一个元素所在的基础原生数组中的字节偏移量
};
let arrbuff = testNapi.getTypedarrayInfo(int8Array, InfoType.ARRAY_BUFFER) as ArrayBuffer;
// 将arraybuffer转为数组
let arr = new Array(new Int8Array(arrbuff));
hilog.info(0x0000, 'Node-API', 'get_typedarray_info_arraybuffer: %{public}s', arr.toString());
hilog.info(0x0000, 'Node-API', 'get_typedarray_info_isIn8Array: %{public}s', testNapi.getTypedarrayInfo(int8Array, InfoType.TYPE).toString());
hilog.info(0x0000, 'Node-API', 'get_typedarray_info_length: %{public}d', testNapi.getTypedarrayInfo(int8Array, InfoType.LENGTH));
hilog.info(0x0000, 'Node-API', 'get_typedarray_info_byte_offset: %{public}d', testNapi.getTypedarrayInfo(int8Array, InfoType.BYTE_OFFSET));
```
<!-- @[ark_napi_get_typed_array_info](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_create_dataview

创建dataview对象，便于访问和操作二进制数据，需要提供一个指向二进制数据的缓冲区，并指定要包含的字节数。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value CreateDataView(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传入的参数
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_value arraybuffer = nullptr;
    napi_value result = nullptr;
    // DataView的字节长度
    size_t byteLength = 12;
    // 字节偏移量
    size_t byteOffset = 4;
    // 获取回调函数的参数信息
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 将参数转换为对象类型
    napi_coerce_to_object(env, args[0], &arraybuffer);
    // 创建一个数据视图对象，并指定字节长度和字节偏移量
    napi_status status = napi_create_dataview(env, byteLength, arraybuffer, byteOffset, &result);
    if (status != napi_ok) {
        // 抛出创建DataView内容失败的错误
        napi_throw_error(env, nullptr, "Failed to create DataView");
        return nullptr;
    }
    // 获取DataView的指针和长度信息
    uint8_t *data = nullptr;
    size_t length = 0;
    napi_get_dataview_info(env, result, &length, (void **)&data, nullptr, nullptr);
    // 为DataView赋值
    for (size_t i = 0; i < length; i++) {
        data[i] = static_cast<uint8_t>(i + 1);
    }
    return result;
}
```
<!-- @[napi_create_data_view](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const createDataView: (arraybuffer:ArrayBuffer) => DataView | undefined;
```
<!-- @[napi_create_data_view_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

const arrayBuffer = new ArrayBuffer(16);
const dataView = testNapi.createDataView(arrayBuffer) as DataView;
hilog.info(0x0000, 'testTag', 'Test Node-API dataView：%{public}d', dataView.byteLength);
hilog.info(0x0000, 'testTag', 'Test Node-API dataView第一个数据：%{public}d', dataView.getInt8(0));
```
<!-- @[ark_napi_create_data_view](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_is_dataview

用于在Node-API模块中判断ArkTS侧给定的napi_value是否为DataView。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value IsDataView(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传入的参数
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // 调用napi_is_dataview接口判断给定入参是否为DataView数据。
    bool result;
    napi_status status;
    status = napi_is_dataview(env, args[0], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_is_dataview fail");
        return nullptr;
    }
    // 将结果转成napi_value类型返回。
    napi_value returnValue;
    napi_get_boolean(env, result, &returnValue);

    return returnValue;
}
```
<!-- @[napi_is_data_view](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const isDataView: (date: DataView | string) => boolean | undefined;
```
<!-- @[napi_is_data_view_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
  let buffer = new ArrayBuffer(16);
  let dataView = new DataView(buffer);
  let data = "123";
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_dataview: %{public}s', testNapi.isDataView(dataView));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_dataview: %{public}s', testNapi.isDataView(data));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_dataview error: %{public}s', error.message);
}
```
<!-- @[ark_napi_is_data_view](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_get_dataview_info

获取给定DataView的各种属性。

cpp部分代码

```cpp
#include "napi/native_api.h"

static napi_value GetDataViewInfo(napi_env env, napi_callback_info info)
{
    // 获取ArkTS侧传入的参数
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // 将第二个参数转为int32类型的数字
    int32_t infoType;
    napi_get_value_int32(env, args[1], &infoType);
    size_t byteLength;
    void *data;
    napi_value arrayBuffer;
    size_t byteOffset;
    // 定义枚举类型与ArkTS侧枚举类型InfoType顺序含义一致
    enum InfoType { BYTE_LENGTH = 0, ARRAY_BUFFER, BYTE_OFFSET };
    // 获取dataview信息
    napi_get_dataview_info(env, args[0], &byteLength, &data, &arrayBuffer, &byteOffset);
    napi_value result;
    switch (infoType) {
        case BYTE_LENGTH:
            // 返回查询DataView的字节数
            napi_value napiByteLength;
            napi_create_int32(env, byteLength, &napiByteLength);
            result = napiByteLength;
            break;
        case ARRAY_BUFFER:
            // 返回查询DataView的arraybuffer
            result = arrayBuffer;
            break;
        case BYTE_OFFSET:
            // 返回查询DataView的偏移字节量
            napi_value napiByteOffset;
            napi_create_int32(env, byteOffset, &napiByteOffset);
            result = napiByteOffset;
            break;
        default:
            break;
    }
    return result;
}
```
<!-- @[napi_get_data_view_info](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

接口声明

```ts
// index.d.ts
export const getDataViewInfo: (dataView: DataView, infoType: number) => ArrayBuffer | number;
```
<!-- @[napi_get_data_view_info_api](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS侧示例代码

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

// 创建一个ArrayBuffer
let arrayBuffer = new Int8Array([2, 5]).buffer;
// 使用arrayBuffer创建一个dataView
let dataView = new DataView(arrayBuffer);
// 定义一个枚举类型
enum InfoType {
    BYTE_LENGTH = 0,
    ARRAY_BUFFER = 1,
    BYTE_OFFSET = 2,
};
// 传入DataView类型参数查询DataView的字节数
hilog.info(0x0000, 'Node-API', 'get_dataview_info_bytelength %{public}d', testNapi.getDataViewInfo(dataView, InfoType.BYTE_LENGTH));
// 传入DataView类型参数查询DataView的ArrayBuffer
let arrbuff = testNapi.getDataViewInfo(dataView, InfoType.ARRAY_BUFFER) as ArrayBuffer;
// 将arraybuffer转为数组
let arr = Array.from(new Int8Array(arrbuff));
hilog.info(0x0000, 'Node-API', 'get_dataview_info_arraybuffer %{public}s', arr.toString());
// 传入DataView类型参数查询DataView开始投影的数据缓冲区中的字节偏移量
hilog.info(0x0000, 'Node-API', 'get_dataview_info_byteoffset %{public}d', testNapi.getDataViewInfo(dataView, InfoType.BYTE_OFFSET));
```
<!-- @[ark_napi_get_data_view_info](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

以上代码如果要在native cpp中打印日志，需在CMakeLists.txt文件中添加以下配置信息（并添加头文件：#include "hilog/log.h"）：

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
