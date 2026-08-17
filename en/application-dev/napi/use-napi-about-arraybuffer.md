# Working with ArrayBuffer Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:37:25.502Z pushedAt=2026-08-12T11:05:27.281Z -->

## Introduction

**ArrayBuffer** in ArkTS is a type of object that represents a generic, fixed-length buffer of raw binary data. It provides a way to effectively represent and manipulate raw binary data in ArkTS.

## Basic Concepts

- **ArrayBuffer**: An **ArrayBuffer** object represents a generic, fixed-length buffer of raw binary data. The **ArrayBuffer** content cannot be directly operated. Instead, you need to use a **TypedArray** or **DataView** object to interpret the buffer data in specific formats. **ArrayBuffer** is used to process a large amount of binary data, such as files and network data packets.

## Available APIs

The following table lists the APIs used to manipulate data of the **ArrayBuffer** type.

| API| Description|
| -------- | -------- |
| napi_is_arraybuffer | Checks whether a value is an **ArrayBuffer** object. Note that this API cannot be used to check whether a value is a **TypedArray** object. To check whether a value is a **TypedArray** object, use **napi_is_typedarray**.|
| napi_get_arraybuffer_info | Obtains information of an **ArrayBuffer** object, including the pointer to the data and the data length.|
| napi_detach_arraybuffer | Detaches the underlying data from an **ArrayBuffer** object. After the data is detached, you can operate the data in C/C++.|
| napi_is_detached_arraybuffer | Checks whether an **ArrayBuffer** object has been detached.|
| napi_create_arraybuffer | Creates an ArkTS **ArrayBuffer** object with the specified byte length.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code related to **ArrayBuffer** management.

The following header files are required for the C++ code:

```cpp
#include "napi/native_api.h"
#include <cstring>
#include "hilog/log.h"
```

The following modules are required for the ArkTS code:

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
```

### napi_is_arraybuffer

Call **napi_is_arraybuffer** to check whether a JS value is an **ArrayBuffer** object.

CPP code:

<!-- @[napi_is_arraybuffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArraybuffer/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_is_arraybuffer
static napi_value IsArrayBuffer(napi_env env, napi_callback_info info)
{
    // Obtain a parameter.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Call napi_is_arraybuffer to check whether the input parameter is an **ArrayBuffer** object.
    bool result = false;
    napi_status status = napi_is_arraybuffer(env, args[0], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_is_arraybuffer fail");
        return nullptr;
    }
    // Convert the result to napi_value and return it.
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);
    return returnValue;
}
```

API declaration:

index.d.ts

<!-- @[napi_is_arraybuffer_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArraybuffer/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const isArrayBuffer: <T>(arrayBuffer: T) => boolean | undefined; // napi_is_arraybuffer
```

ArkTS code:

<!-- @[ark_napi_is_arraybuffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArraybuffer/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// test interface napi_is_arraybuffer
try {
  let value = new ArrayBuffer(1);
  let data = "123";
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_arraybuffer: %{public}s',
    testNapi.isArrayBuffer(value));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_arraybuffer: %{public}s',
    testNapi.isArrayBuffer(data));
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_arraybuffer error: %{public}s',
    error.message);
  // ...
}
```

Log output:

Test Node-API napi_is_arraybuffer: true<br>
Test Node-API napi_is_arraybuffer: false

### napi_get_arraybuffer_info

Call **napi_get_arraybuffer_info** to obtain the underlying data buffer and length of an **ArrayBuffer** object. This API can process only **ArrayBuffer** objects. Do not pass other types to the API. To obtain an **ArrayBuffer** object from a **Uint8Array** object, you need to execute the **.buffer** operation on the ArkTS side.

CPP code:

<!-- @[napi_get_arraybuffer_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArraybuffer/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_arraybuffer_info
static napi_value GetArrayBufferInfo(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Check whether the parameter is an ArrayBuffer object.
    bool isArrayBuffer = false;
    napi_is_arraybuffer(env, args[0], &isArrayBuffer);
    if (!isArrayBuffer) {
        napi_throw_type_error(env, nullptr, "Argument must be an ArrayBuffer");
        return nullptr;
    }

    void *data = nullptr;
    size_t byteLength = 0;
    // Obtain the underlying data buffer and length of the ArrayBuffer object.
    napi_status status = napi_get_arraybuffer_info(env, args[0], &data, &byteLength);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to get ArrayBuffer info");
        return nullptr;
    }
    // Create a result object.
    napi_value result = nullptr;
    napi_create_object(env, &result);
    // Set the byte length property of the data buffer.
    napi_value byteLengthValue = nullptr;
    napi_create_uint32(env, byteLength, &byteLengthValue);
    napi_set_named_property(env, result, "byteLength", byteLengthValue);
    napi_value bufferData = nullptr;
    void *newData = nullptr;
    napi_create_arraybuffer(env, byteLength, &newData, &bufferData);
    memcpy(newData, data, byteLength);
    napi_set_named_property(env, result, "buffer", bufferData);
    return result;
}
```

API declaration:

index.d.ts

<!-- @[napi_get_arraybuffer_info_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArraybuffer/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export class ArrayBufferInfo {
  byteLength: number;
  buffer: ArrayBuffer;
}
export const getArrayBufferInfo: (data: ArrayBuffer) => ArrayBufferInfo | undefined; // napi_get_arraybuffer_info
```

ArkTS code:

<!-- @[ark_napi_get_arraybuffer_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArraybuffer/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// test interface napi_get_arraybuffer_info
try {
  let typedArray = new Uint8Array([1, 2, 3, 4, 5]);
  let buffer = typedArray.buffer;
  let result = testNapi.getArrayBufferInfo(buffer) as testNapi.ArrayBufferInfo;
  let resBuffer = new Uint8Array(result.buffer);
  hilog.info(0x0000, 'testTag', 'Test Node-API get_arrayBuffer_info byteLength: %{public}d buffer: %{public}s', result.byteLength, JSON.stringify(resBuffer));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API get_arrayBuffer_info error: %{public}s', error.message);
}
```

Log output:

Test Node-API napi_get_arraybuffer_info byteLength: 5 buffer: {"0":1,"1":2,"2":3,"3":4,"4":5}

### napi_detach_arraybuffer

Call **napi_detach_arraybuffer** to detach the underlying data from an **ArrayBuffer** object.

### napi_is_detached_arraybuffer

Call **napi_is_detached_arraybuffer** to check whether an **ArrayBuffer** object has been detached.

CPP code:

<!-- @[napi_detach_arraybuffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArraybuffer/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_detach_arraybuffer
static napi_value DetachedArrayBuffer(napi_env env, napi_callback_info info)
{
    // Call napi_detach_arraybuffer to detach the underlying data from an ArrayBuffer object.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    napi_value arrayBuffer = args[0];
    napi_detach_arraybuffer(env, arrayBuffer);
    // Pass out the detached ArrayBuffer object.
    return arrayBuffer;
}

// napi_is_detach_arraybuffer
static napi_value IsDetachedArrayBuffer(napi_env env, napi_callback_info info)
{
    // Call napi_is_detached_arraybuffer to check whether the specified ArrayBuffer object has been detached.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    napi_value arrayBuffer = args[0];
    bool result = false;
    napi_is_detached_arraybuffer(env, arrayBuffer, &result);
    // Call napi_get_boolean to convert the return value to napi_value, and pass out the napi_value for printing.
    napi_value returnValue;
    napi_get_boolean(env, result, &returnValue);
    return returnValue;
}
```

API declaration:

index.d.ts

<!-- @[napi_detach_arraybuffer_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArraybuffer/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const detachedArrayBuffer: (buffer:ArrayBuffer) => ArrayBuffer; // napi_detach_arraybuffer
export const isDetachedArrayBuffer: (arrayBuffer: ArrayBuffer) => boolean; //napi_is_detached_arraybuffer
```

ArkTS code:

<!-- @[ark_napi_detach_arraybuffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArraybuffer/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// test interface napi_detach_arraybuffer and napi_is_detached_arraybuffer
try {
  const bufferArray = new ArrayBuffer(8);
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_detached_arraybuffer one: %{public}s',
    testNapi.isDetachedArrayBuffer(bufferArray));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_detached_arraybuffer two: %{public}s ',
    testNapi.isDetachedArrayBuffer(testNapi.detachedArrayBuffer(bufferArray)));
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_detached_arraybuffer error: %{public}s',
    error.message);
  // ...
}
```

Log output:

Test Node-API napi_is_detached_arraybuffer one: false<br>
Test Node-API napi_is_detached_arraybuffer two: true

### napi_create_arraybuffer

Call **napi_create_arraybuffer** to create an ArkTS **ArrayBuffer** object with the specified byte length in C/C++. If the caller wants to directly operate the buffer, return the underlying buffer to the caller. To write data to this buffer from ArkTS, you need to create a **TypedArray** or **DataView** object.

> **NOTE**
>
> If **byte_length** of **napi_create_arraybuffer** is **0** or an excessively large value, nullptr will be returned in **data**. Therefore, it is necessary to check whether **data** is empty before using it.

CPP code:

<!-- @[napi_create_arraybuffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArraybuffer/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_create_arraybuffer
static napi_value CreateArrayBuffer(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    napi_value result = nullptr;
    // Parse the input parameters.
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    int32_t value;
    size_t length;
    // Convert the parameter passed from ArkTS to the size_t type and use it as the parameter of napi_create_arraybuffer.
    napi_get_value_int32(env, argv[0], &value);
    length = size_t(value);
    void *data = nullptr;
    // Create an ArrayBuffer object.
    napi_create_arraybuffer(env, length, &data, &result);
    if (data != nullptr) {
        // Check data before using it for subsequent operations.
    } else {
        // Handle the memory allocation failure.
        OH_LOG_ERROR(LOG_APP, "Failed to allocate memory for ArrayBuffer");
        return nullptr;
    }
    // Return the ArrayBuffer object.
    return result;
}
```

API declaration:

index.d.ts

<!-- @[napi_create_arraybuffer_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArraybuffer/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createArrayBuffer: (size: number) => ArrayBuffer; // napi_create_arraybuffer
```

ArkTS code:

<!-- @[ark_napi_create_arraybuffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIArraybuffer/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// test interface napi_create_arraybuffer
hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_arraybuffer:%{public}s',
  testNapi.createArrayBuffer(10).toString());
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```

Log output:

Test Node-API napi_create_arraybuffer:[object ArrayBuffer]

## NOTE

- Lifecycle and memory management: When using Node-API to process **ArrayBuffer** objects, note that the lifecycle of the buffer data segment of the **void*** type is managed by the engine and [cannot be deleted by users. Otherwise, a double free error may occur](napi-guidelines.md#avoiding-releasing-the-obtained-buffer-repeatedly).

- Allocated buffer size: When the value of **byte_length** is large, no exception is thrown when the allocation fails. The memory specified by **data** is **nullptr**. It is recommended that ***data == nullptr** be strictly checked and the upper limit of **byte_length** be checked to avoid OOM.