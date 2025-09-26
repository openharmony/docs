# Working with Arrays Using Node-API
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## Introduction

Node-API provides APIs for directly managing ArkTS arrays.

## Basic Concepts

Node-API can be used to create, access, modify, and traverse arrays. Before using Node-API, it's helpful if you understand the following concepts:

- Array creation: You can use **napi_create_array** to create an array and pass it to the ArkTS layer.
- Array-related operations: You can use the APIs provides by the Node-API module to obtain the length of an ArkTS array, retrieve the element at the specified index, and set the element value at the specified index.
- **TypedArray**: A **TypedArray** object in ArkTS is an array-like view of an underlying binary data buffer. It can be understood as an array of elements of the specified type. There is no constructor for **TypedArray** objects, but they can be constructed by their child class constructors. The child classes of **TypedArray** include **Int8Array**, **Uint8Array**, **Uint8ClampedArray**, **Int16Array**, and **Int32Array**.
- **DataView**: **DataView** is a flexible binary data access view in ArkTS. It provides methods for reading and writing multiple number types from an **ArrayBuffer**. Unlike **TypedArray**, **DataView** does not require data to be aligned at specific bytes. Therefore, it can process data structures with arbitrary byte offsets. DataView supports the following methods (each method has a **get** and **set** version): **Int8**, **Uint8**, **Int16**, **Uint16**, **Int32**, **Uint32**, **Float32**, and **Float64**.
- **ArrayBuffer**: **ArrayBuffer** is a data struct used to represent a binary data buffer of fixed length. It cannot be read or written directly, but its content can be operated through **TypedArray** or **DataView**.

## Available APIs

The following table describes the APIs for managing ArkTS arrays.
| API| Description|
| -------- | -------- |
| napi_create_array | Creates an ArkTS array.|
| napi_create_array_with_length | Creates an ArkTS array of the specified length.|
| napi_get_array_length | Obtains the length of an ArkTS array.|
| napi_is_array | Checks whether the given **napi_value** is an array.|
| napi_set_element | Sets an element at the specified index in the given ArkTS array.|
| napi_get_element | Obtains the element at the specified index in the given ArkTS array.|
| napi_has_element | Checks whether the element at the specified index exists.|
| napi_delete_element | Deletes the element at the specified index of the given ArkTS array.|
| napi_create_typedarray | Creates an ArkTS **TypedArray** object of the specified type, such as **Uint8Array** or **Int32Array**. You can use this API to convert a native value into a **TypedArray** object for performant data processing.  |
| napi_is_typedarray | Checks whether the given **napi_value** is a **TypedArray** object.|
| napi_get_typedarray_info | Obtains the properties of a **TypedArray** object.|
| napi_create_dataview |  Creates a **DataView** object, which allows access to binary data.|
| napi_is_dataview | Checks whether the given **napi_value** is a **DataView** object in ArkTS.|
| napi_get_dataview_info | Obtains the properties of a **DataView** object.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code for array management APIs.  

### napi_create_array

Call **napi_create_array** to create an ArkTS array.

CPP code:

```cpp
#include "napi/native_api.h"

static constexpr int INT_NUM_5 = 5; // Array length.

static napi_value CreateArray(napi_env env, napi_callback_info info)
{
    // Create an empty array.
    napi_value jsArray = nullptr;
    napi_create_array(env, &jsArray);
    // Assign a value to the created array.
    for (int i = 0; i < INT_NUM_5; i++) {
        napi_value element;
        napi_create_int32(env, i, &element);
        napi_set_element(env, jsArray, i, element);
    }
    // Return the created array.
    return jsArray;
}
```
<!-- @[napi_create_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const createArray: () => number[];
```
<!-- @[napi_create_array_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_array:%{public}s', JSON.stringify(testNapi.createArray()));
```
<!-- @[ark_napi_create_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_create_array_with_length

Call **napi_create_array_with_length** to create an ArkTS array of the specified length.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CreateArrayWithLength(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed from ArkTS.
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_value jsArray = nullptr;
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Obtain the array length passed.
    int32_t length = 0;
    napi_get_value_int32(env, argv[0], &length);
    // Use napi_create_array_with_length to create an array of the specified length.
    napi_create_array_with_length(env, length, &jsArray);
    // Return the array.
    return jsArray;
}
```
<!-- @[napi_create_array_with_length](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const createArrayWithLength: (length: number) => void[];
```
<!-- @[napi_create_array_with_length_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let array = testNapi.createArrayWithLength(6);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_array_with_length:%{public}d', array.length);
```
<!-- @[ark_napi_create_array_with_length](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_get_array_length

Call **napi_get_array_length** to obtain the length of an array.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetArrayLength(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed from ArkTS.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_value result;
    uint32_t length;
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Check whether the parameter is an array.
    bool is_array;
    napi_is_array(env, args[0], &is_array);
    if (!is_array) {
        napi_throw_error(env, nullptr, "Argument must be an array");
        return nullptr;
    }
    napi_get_array_length(env, args[0], &length);
    // Create a return value.
    napi_create_uint32(env, length, &result);
    return result;
}
```
<!-- @[napi_get_array_length](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getArrayLength: (arr: Array<any>) => number | undefined;
```
<!-- @[napi_get_array_length_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

const arr = [0, 1, 2, 3, 4, 5];
hilog.info(0x0000, 'testTag', 'Test Node-API get_array_length:%{public}d', testNapi.getArrayLength(arr));
```
<!-- @[ark_napi_get_array_length](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_is_array

Call **napi_is_array** to check whether the given ArkTS value is an array.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value IsArray(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed from ArkTS.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Call napi_is_array to check whether the input parameter is an array.
    bool result;
    napi_status status;
    status = napi_is_array(env, args[0], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_is_array fail");
        return nullptr;
    }
    // Convert the result to napi_value and return it.
    napi_value returnValue;
    napi_get_boolean(env, result, &returnValue);

    return returnValue;
}
```
<!-- @[napi_is_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const isArray: <T>(data: Array<T> | T) => boolean | undefined;
```
<!-- @[napi_is_array_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

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
<!-- @[ark_napi_is_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_set_element

Call **napi_set_element** to set an element at the specified index in an ArkTS array.
For the object that uses the index value as the key, you can use **napi_set_element** to set the property value.

CPP code:

```cpp
#include "napi/native_api.h"

static constexpr int INT_ARG_2 = 2; // Input parameter index.

static napi_value NapiSetElement(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed from ArkTS.
    size_t argc = 3;
    napi_value args[3] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Check whether the first parameter is an array.
    bool isArr = false;
    napi_is_array(env, args[0], &isArr);
    if (!isArr) {
        napi_throw_error(env, nullptr, "Argument should be an object of type array");
        return nullptr;
    }
    // Obtain the index of the element to be set.
    double index = 0;
    napi_status status = napi_get_value_double(env, args[1], &index);
    if (status != napi_ok || index < 0) {
        napi_throw_error(env, nullptr, "The index should be a non-negative number");
        return nullptr;
    }
    // Set the input value at the specified index of the array.
    napi_set_element(env, args[0], static_cast<uint32_t>(index), args[INT_ARG_2]);

    return nullptr;
}
```
<!-- @[napi_set_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
export const napiSetElement: <T>(arr: Array<T>, index: number, value: T) => void;
```
<!-- @[napi_set_element_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
try {
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
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_set_element error: %{public}s', error.message);
}
```
<!-- @[ark_napi_set_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_get_element

Call **napi_get_element** to obtain the element at the specified index in an ArkTS array. The index must be within the valid range of the array. Otherwise, **undefined** will be returned.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value NapiGetElement(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the index value of the element.
    uint32_t index;
    napi_get_value_uint32(env, args[1], &index);
    // Obtain the element value at the index and store it in result.
    napi_value result;
    napi_get_element(env, args[0], index, &result);

    return result;
}
```
<!-- @[napi_get_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const napiGetElement: <T>(arr: Array<T>, index: number) => number | string | Object | boolean | undefined;
```
<!-- @[napi_get_element_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

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
<!-- @[ark_napi_get_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_has_element

Call **napi_has_element** to check whether an ArkTS array has the element at the specified index. If the specified index exceeds the valid range of the array, **false** will be returned, which indicates that the element does not exist.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value NapiHasElement(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the index of the element to be checked.
    uint32_t index;
    napi_get_value_uint32(env, args[1], &index);
    // Check whether the element exists based on the given index.
    bool hasElement = true;
    napi_has_element(env, args[0], index, &hasElement);
    // Convert the bool value to napi_value and return it.
    napi_value result;
    napi_get_boolean(env, hasElement, &result);
    return result;
}
```
<!-- @[napi_has_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const napiHasElement: <T>(arr: Array<T>, index: number) => boolean;
```
<!-- @[napi_has_element_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let arr = [10, 'hello', null, 'world'];
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_element arr[0]: %{public}s', testNapi.napiHasElement<number | string | null>(arr, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_element arr[7]: %{public}s', testNapi.napiHasElement<number | string | null>(arr, 7));
```
<!-- @[ark_napi_has_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_delete_element

Call **napi_delete_element** to delete the element at the specified index from an ArkTS array.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value NapiDeleteElement(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the index of the element to delete.
    uint32_t index;
    napi_get_value_uint32(env, args[1], &index);
    // Delete the element at the specified index.
    bool deleted = true;
    napi_delete_element(env, args[0], index, &deleted);
    // Convert the bool value to napi_value and return it.
    napi_value result;
    napi_get_boolean(env, deleted, &result);
    return result;
}
```
<!-- @[napi_delete_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const napiDeleteElement: <T>(arr: Array<T>, index: number) => boolean;
```
<!-- @[napi_delete_element_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
// Import napiHasElement and napiGetElement.
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

let arr = [10, 'hello', null, 'world'];
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_element arr[0]: %{public}s', testNapi.napiHasElement<number | string | null>(arr, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_delete_element arr[0]: %{public}s', testNapi.napiDeleteElement<number | string | null>(arr, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_has_element deleted arr[0]: %{public}s', testNapi.napiHasElement<number | string | null>(arr, 0));
hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_element arr[0]: %{public}d', testNapi.napiGetElement<number | string | null>(arr, 0));
```
<!-- @[ark_napi_delete_element](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_create_typedarray

Call **napi_create_typedarray** to create an ArkTS **TypedArray** object of the specified type from an existing **ArrayBuffer** object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CreateTypedArray(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed from ArkTS.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    int32_t typeNum = 0;
    napi_get_value_int32(env, args[0], &typeNum);
    napi_typedarray_type arrayType;
    // Set the element size.
    size_t elementSize = 0;
    // Determine the type of the array to create based on the type value passed.
    arrayType = static_cast<napi_typedarray_type>(typeNum);
    switch (arrayType) {
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
    // By default, an array of the napi_int8_array type is created.
        arrayType = napi_int8_array;
        elementSize = sizeof(int8_t);
        break;
    }
    size_t length = 3;
    napi_value arrayBuffer = nullptr;
    napi_value typedArray = nullptr;
    void *data;
    // Create an ArrayBuffer object.
    napi_create_arraybuffer(env, length * elementSize, (void **)&data, &arrayBuffer);
    // Create a TypedArray object of the specified type.
    napi_create_typedarray(env, arrayType, length, arrayBuffer, 0, &typedArray);
    return typedArray;
}
```
<!-- @[napi_create_typed_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

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
  BIGUINT64_ARRAY,
}
export const createTypedArray: <T>(type: TypedArrayTypes) => T;
```
<!-- @[napi_create_typed_array_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

// Pass the type of the array to create.
let typedArray = testNapi.createTypedArray<Int8Array>(testNapi.TypedArrayTypes["INT8_ARRAY"]);
if (typedArray instanceof Int8Array) {
    hilog.info(0x0000, 'testTag', ' Node-API napi_create_typedarray: Int8Array');
}
let uint8Array = testNapi.createTypedArray<Uint8Array>(testNapi.TypedArrayTypes["UINT8_ARRAY"]);
if (uint8Array instanceof Uint8Array) {
    hilog.info(0x0000, 'testTag', ' Node-API napi_create_typedarray: Uint8Array');
}
```
<!-- @[ark_napi_create_typed_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

Modify the module initialization in **use-napi-process.md** as follows:

```cpp
#include <string>

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    // The defined TypedArray type is used by ArkTS to store typedArrayTypes. For details about the example, see createTypedArray() on ArkTS.
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
<!-- @[change_use_napi_process](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

### napi_is_typedarray

Call **napi_is_typedarray** to check whether the **napi_value** given from ArkTS is a **TypedArray** object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value IsTypedarray(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed from ArkTS.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Call napi_is_typedarray to check whether the input parameter type is TypedArray.
    bool result = false;
        napi_status status;
    status = napi_is_typedarray(env, args[0], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_is_typedarray fail");
        return nullptr;
    }
    // Convert the result to napi_value and return it.
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);

    return returnValue;
}
```
<!-- @[napi_is_typed_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const isTypedarray: (data: Object) => boolean | undefined;
```
<!-- @[napi_is_typed_array_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

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
<!-- @[ark_napi_is_typed_array](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_get_typedarray_info

Call **napi_get_typedarray_info** to obtain properties of a **TypedArray** object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetTypedarrayInfo(napi_env env, napi_callback_info info)
{
    // Obtain and parse the parameters passed from ArkTS. The first parameter is the TypedArray type of the property to obtain, and the second parameter is the enums of the property type to obtain.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the second parameter to the int32 type for comparison.
    int32_t infoTypeParam;
    napi_get_value_int32(env, args[1], &infoTypeParam);
    // Define the InfoType enums in the same sequence as those in ArkTS.
    enum InfoType { INFO_TYPE = 1, INFO_LENGTH, INFO_ARRAY_BUFFER, INFO_BYTE_OFFSET };
    void *data;
    napi_typedarray_type type;
    size_t byteOffset, length;
    napi_value arraybuffer;
    // Call napi_get_typedarray_info to obtain TypedArray information.
    napi_get_typedarray_info(env, args[0], &type, &length, &data, &arraybuffer, &byteOffset);
    napi_value result = nullptr;
    // Return the property value based on the property name.
    switch (infoTypeParam) {
    case INFO_TYPE:
        // If the input parameter is TypedArray data of the int8 type, the value type is napi_int8_array.
        napi_value int8_type;
        napi_get_boolean(env, type == napi_int8_array, &int8_type);
        result = int8_type;
        break;
    case INFO_LENGTH:
        // Byte length of elements in TypedArray.
        napi_value napiLength;
        napi_create_int32(env, length, &napiLength);
        result = napiLength;
        break;
    case INFO_BYTE_OFFSET:
        // Byte offset of the first TypedArray element in the native array.
        napi_value napiByteOffset;
        napi_create_int32(env, byteOffset, &napiByteOffset);
        result = napiByteOffset;
        break;
    case INFO_ARRAY_BUFFER:
        // ArrayBuffer under TypedArray.
        result = arraybuffer;
        break;
    default:
        napi_throw_error(env, nullptr, "infoType is not the InfoType");
        break;
    }
    return result;
}
```
<!-- @[napi_get_typed_array_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getTypedarrayInfo: <T>(typeArray: T, infoType: number) => ArrayBuffer | number | boolean;
```
<!-- @[napi_get_typed_array_info_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

// Pass in the TypedArray type. TypedArray is a class array data view used to describe binary data. It does not have a constructor and can be constructed from its child class.
// The child classes of TypedArray include Int8Array, Uint8Array, Uint8ClampedArray, Int16Array, and Int32Array. 
let int8Array = new Int8Array([15, 7]);
// Define the InfoType enums, which are the properties of TypedArray.
enum InfoType {
    TYPE = 1, // Type of the TypedArray.
    LENGTH = 2, // Length of the input TypedArray.
    ARRAY_BUFFER = 3, // ArrayBuffer under TypedArray.
    BYTE_OFFSET = 4 // Offset of the first ArrayBuffer element in the native array.
};
try {
  let arrbuff = testNapi.getTypedarrayInfo(int8Array, InfoType.ARRAY_BUFFER) as ArrayBuffer;
  // Convert arraybuffer to an array.
  let arr = new Array(new Int8Array(arrbuff));
  hilog.info(0x0000, 'Node-API', 'get_typedarray_info_arraybuffer: %{public}s', arr.toString());
  hilog.info(0x0000, 'Node-API', 'get_typedarray_info_isIn8Array: %{public}s', testNapi.getTypedarrayInfo(int8Array, InfoType.TYPE).toString());
  hilog.info(0x0000, 'Node-API', 'get_typedarray_info_length: %{public}d', testNapi.getTypedarrayInfo(int8Array, InfoType.LENGTH));
  hilog.info(0x0000, 'Node-API', 'get_typedarray_info_byte_offset: %{public}d', testNapi.getTypedarrayInfo(int8Array, InfoType.BYTE_OFFSET));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_get_typedarray_info error: %{public}s', error.message);
}
```
<!-- @[ark_napi_get_typed_array_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_create_dataview

Call **napi_create_dataview** to create a **DataView** object to facilitate access and operation of binary data. You need to specify a buffer pointing to the binary data and the number of bytes included.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value CreateDataView(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed from ArkTS.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_value arraybuffer = nullptr;
    napi_value result = nullptr;
    // Byte length of DataView.
    size_t byteLength = 12;
    // Offset of the byte.
    size_t byteOffset = 4;
    // Obtain the parameters of the callback.
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the parameter into the object type.
    napi_coerce_to_object(env, args[0], &arraybuffer);
    // Create a DataView object with the specified byte length and offset.
    napi_status status = napi_create_dataview(env, byteLength, arraybuffer, byteOffset, &result);
    if (status != napi_ok) {
        // Throw an error indicating that the DataView fails to be created.
        napi_throw_error(env, nullptr, "Failed to create DataView");
        return nullptr;
    }
    // Obtain the pointer to the DataView object and the length.
    uint8_t *data = nullptr;
    size_t length = 0;
    napi_get_dataview_info(env, result, &length, (void **)&data, nullptr, nullptr);
    // Assign values to DataView.
    for (size_t i = 0; i < length; i++) {
        data[i] = static_cast<uint8_t>(i + 1);
    }
    return result;
}
```
<!-- @[napi_create_data_view](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const createDataView: (arraybuffer:ArrayBuffer) => DataView | undefined;
```
<!-- @[napi_create_data_view_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

const arrayBuffer = new ArrayBuffer(16);
const dataView = testNapi.createDataView(arrayBuffer) as DataView;
hilog.info(0x0000, 'testTag', 'Test Node-API dataView: %{public}d', dataView.byteLength);
hilog.info(0x0000, 'testTag','Test Node-API dataView first data: %{public}d', dataView.getInt8(0));
```
<!-- @[ark_napi_create_data_view](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_is_dataview

Call **napi_is_dataview** to check whether the **napi_value** given from ArkTS is a **DataView** object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value IsDataView(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed from ArkTS.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // Call napi_is_dataview to check whether the input parameter is a DataView object.
    bool result;
    napi_status status;
    status = napi_is_dataview(env, args[0], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_is_dataview fail");
        return nullptr;
    }
    // Convert the result to napi_value and return it.
    napi_value returnValue;
    napi_get_boolean(env, result, &returnValue);

    return returnValue;
}
```
<!-- @[napi_is_data_view](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const isDataView: (date: DataView | string) => boolean | undefined;
```
<!-- @[napi_is_data_view_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

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
<!-- @[ark_napi_is_data_view](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

### napi_get_dataview_info

Call **napi_get_dataview_info** to obtain properties of a **DataView** object.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetDataViewInfo(napi_env env, napi_callback_info info)
{
    // Obtain the parameters passed from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Convert the second parameter to an int32 number.
    int32_t infoType;
    napi_get_value_int32(env, args[1], &infoType);
    size_t byteLength;
    void *data;
    napi_value arrayBuffer;
    size_t byteOffset;
    // Define the InfoType enums in the same sequence as those in ArkTS.
    enum InfoType { BYTE_LENGTH = 0, ARRAY_BUFFER, BYTE_OFFSET };
    // Obtain DataView information.
    napi_get_dataview_info(env, args[0], &byteLength, &data, &arrayBuffer, &byteOffset);
    napi_value result = nullptr;
    switch (infoType) {
        case BYTE_LENGTH:
            // Return the number of bytes of the DataView object.
            napi_value napiByteLength;
            napi_create_int32(env, byteLength, &napiByteLength);
            result = napiByteLength;
            break;
        case ARRAY_BUFFER:
            // Return the ArrayBuffer of the DataView object.
            result = arrayBuffer;
            break;
        case BYTE_OFFSET:
            // Return the byte offset of the DataView object.
            napi_value napiByteOffset;
            napi_create_int32(env, byteOffset, &napiByteOffset);
            result = napiByteOffset;
            break;
        default:
            napi_throw_error(env, nullptr, "infoType is not the InfoType");
            break;
    }
    return result;
}
```
<!-- @[napi_get_data_view_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/napi_init.cpp) -->

API declaration:

```ts
// index.d.ts
export const getDataViewInfo: (dataView: DataView, infoType: number) => ArrayBuffer | number;
```
<!-- @[napi_get_data_view_info_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/cpp/types/libentry/Index.d.ts) -->

ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

// Create an ArrayBuffer object.
let arrayBuffer = new Int8Array([2, 5]).buffer;
// Use arrayBuffer to create a DataView object.
let dataView = new DataView(arrayBuffer);
// Define an enum type.
enum InfoType {
    BYTE_LENGTH = 0,
    ARRAY_BUFFER = 1,
    BYTE_OFFSET = 2,
};
try {
  // Pass in the parameter of DataView to obtain the number of bytes in DataView.
  hilog.info(0x0000, 'Node-API', 'get_dataview_info_bytelength %{public}d', testNapi.getDataViewInfo(dataView, InfoType.BYTE_LENGTH));
  // Pass in the parameter of DataView to obtain the ArrayBuffer of DataView.
  let arrbuff = testNapi.getDataViewInfo(dataView, InfoType.ARRAY_BUFFER) as ArrayBuffer;
  // Convert arraybuffer to an array.
  let arr = Array.from(new Int8Array(arrbuff));
  hilog.info(0x0000, 'Node-API', 'get_dataview_info_arraybuffer %{public}s', arr.toString());
  // Pass in the parameter of DataView to obtain the byte offset in the data buffer of DataView.
  hilog.info(0x0000, 'Node-API', 'get_dataview_info_byteoffset %{public}d', testNapi.getDataViewInfo(dataView, InfoType.BYTE_OFFSET));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_get_dataview_info error: %{public}s', error.message);
}
```
<!-- @[ark_napi_get_data_view_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArray/entry/src/main/ets/pages/Index.ets) -->

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```
