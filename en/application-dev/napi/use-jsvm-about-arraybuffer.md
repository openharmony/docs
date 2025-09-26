# Working with ArrayBuffer Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Introduction

**ArrayBuffer** in JavaScript (JS) is a type of object that represents a generic, fixed-length buffer of raw binary data. It provides a way to effectively represent and manipulate raw binary data in JS.

## Basic Concepts

- **ArrayBuffer**: An **ArrayBuffer** object represents a generic, fixed-length buffer of raw binary data. The **ArrayBuffer** content cannot be directly operated. Instead, you need to use a TypedArray or **DataView** object to interpret the buffer data in specific formats. **ArrayBuffer** is used to process original binary data of a fixed length, such as files and network data packets.
- Lifecycle and memory management: When using **ArrayBuffer** with JSVM-API, pay special attention to lifecycle and memory management, ensuring timely memory release.

## Available APIs

| API                        | Description                                  |
| ---------------------------- | ------------------------------------------ |
| OH_JSVM_GetArraybufferInfo    | Obtains the underlying data buffer of an **ArrayBuffer** object and its length.|
| OH_JSVM_IsArraybuffer        | Checks whether a JS object is an **ArrayBuffer** object.       |
| OH_JSVM_DetachArraybuffer    | Calls the **Detach()** operation of an **ArrayBuffer** object.           |
| OH_JSVM_IsDetachedArraybuffer | Checks whether an **ArrayBuffer** object has been detached.       |
| OH_JSVM_CreateArraybuffer      | Creates an **ArrayBuffer** object of the specified size.  |

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in **ArrayBuffer** development.

### OH_JSVM_GetArraybufferInfo

Obtains the underlying data buffer of an **ArrayBuffer** object and its length.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_GetArraybufferInfo.
static JSVM_Value GetArraybufferInfo(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    // Parse the input parameters.
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Check whether the parameter is an ArrayBuffer object.
    bool isArrayBuffer = false;
    OH_JSVM_IsArraybuffer(env, args[0], &isArrayBuffer);
    if (!isArrayBuffer) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetArraybufferInfo isArrayBuffer:false");
        return nullptr;
    }
    void *data;
    size_t byteLength = 0;
    // Obtain the underlying data buffer and length of the ArrayBuffer object.
    JSVM_Status status = OH_JSVM_GetArraybufferInfo(env, args[0], &data, &byteLength);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM GetArraybufferInfo: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM GetArraybufferInfo: success");
    }
    return args[0];
}
// Register the GetArraybufferInfo callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetArraybufferInfo},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getArraybufferInfo and associate it with a callback. This allows the GetArraybufferInfo callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getArraybufferInfo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char *srcCallNative = R"JS(
getArraybufferInfo(new ArrayBuffer(10));
)JS";
```

Expected result:
```
JSVM GetArraybufferInfo: success
```

<!-- @[oh_jsvm_get_arraybuffer_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArraybuffer/getarraybufferinfo/src/main/cpp/hello.cpp) -->

### OH_JSVM_IsArraybuffer

Checks whether a JS object is an **ArrayBuffer** object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_IsArraybuffer.
static JSVM_Value IsArrayBuffer(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Call OH_JSVM_IsArraybuffer to check whether the input parameter is an ArrayBuffer object.
    bool isArrayBuffer = false;
    JSVM_Status status = OH_JSVM_IsArraybuffer(env, args[0], &isArrayBuffer);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsArrayBuffer: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM IsArrayBuffer: success");
        OH_LOG_INFO(LOG_APP, "JSVM IsArrayBuffer: %{public}d", isArrayBuffer);
    }
    JSVM_Value boolean = nullptr;
    OH_JSVM_GetBoolean(env, isArrayBuffer, &boolean);
    return boolean;
}
// Register the IsArrayBuffer callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsArrayBuffer},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named isArrayBuffer and associate it with a callback. This allows the IsArrayBuffer callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"isArrayBuffer", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char *srcCallNative = R"JS(
isArrayBuffer(new ArrayBuffer(8));
)JS";
```

Expected result:
```
JSVM IsArrayBuffer: success
JSVM IsArrayBuffer: 1
```

<!-- @[oh_jsvm_is_arraybuffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArraybuffer/isarraybuffer/src/main/cpp/hello.cpp) -->

### OH_JSVM_DetachArraybuffer

Use **OH_JSVM_DetachArraybuffer** to call the **Detach()** operation of an **ArrayBuffer** object.

### OH_JSVM_IsDetachedArraybuffer

Use **OH_JSVM_IsDetachedArraybuffer** to check whether an **ArrayBuffer** object has been detached.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_DetachArraybuffer and OH_JSVM_IsDetachedArraybuffer.
static JSVM_Value DetachArraybuffer(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value arraybuffer = args[0];
    JSVM_Status status = OH_JSVM_DetachArraybuffer(env, arraybuffer);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM DetachArraybuffer: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM DetachArraybuffer: success");
    }
    return arraybuffer;
}
static JSVM_Value IsDetachedArraybuffer(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value arraybuffer = args[0];
    OH_JSVM_DetachArraybuffer(env, arraybuffer);
    bool result = false;
    JSVM_Status status = OH_JSVM_IsDetachedArraybuffer(env, arraybuffer, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsDetachedArraybuffer: failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM IsDetachedArraybuffer: success");
        OH_LOG_INFO(LOG_APP, "JSVM IsArrayBuffer: %{public}d", result);
    }
    JSVM_Value isDetached = nullptr;
    OH_JSVM_GetBoolean(env, result, &isDetached);
    return isDetached;
}
// Register the DetachArraybuffer and IsDetachedArraybuffer callbacks.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = DetachArraybuffer},
    {.data = nullptr, .callback = IsDetachedArraybuffer},
};
static JSVM_CallbackStruct *method = param;
// Set property descriptors named DetachArraybuffer and IsDetachedArraybuffer, and associate them with a callback each. This allows the DetachArraybuffer and IsDetachedArraybuffer callbacks to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"detachArraybuffer", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
    {"isDetachedArraybuffer", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char *srcCallNative = R"JS(
let arrayBuffer = new ArrayBuffer(10);
detachArraybuffer(arrayBuffer);
isDetachedArraybuffer(arrayBuffer);
)JS";
```

Expected result:
```
JSVM DetachArraybuffer: success
JSVM IsDetachedArraybuffer: success
JSVM IsArrayBuffer: 1
```

<!-- @[oh_jsvm_is_detached_arraybuffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArraybuffer/isdetachedarraybuffer/src/main/cpp/hello.cpp) -->

### OH_JSVM_CreateArraybuffer

Use **OH_JSVM_CreateArraybuffer** to create an **ArrayBuffer** object of the specified size.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Define OH_JSVM_CreateArraybuffer.
static JSVM_Value CreateArraybuffer(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value argv[1] = {nullptr};
    JSVM_Value result = nullptr;
    // Parse the input parameters.
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    int32_t value = 0;
    size_t length = 0;
    JSVM_CALL(OH_JSVM_GetValueInt32(env, argv[0], &value));
    length = size_t(value);
    void *data;
    // Create an ArrayBuffer object.
    JSVM_Status status = OH_JSVM_CreateArraybuffer(env, length, &data, &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateArraybuffer: failed");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM CreateArraybuffer: success");
        OH_LOG_INFO(LOG_APP, "JSVM ArrayBuffer length: %{public}d", length);
    }
    // Return the created ArrayBuffer.
    return result;
}
// Register the CreateArraybuffer callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateArraybuffer},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createArraybuffer and associate it with a callback. This allows the CreateArraybuffer callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createArraybuffer", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char *srcCallNative = R"JS(
createArraybuffer(8);
)JS";
```

Expected result:
```
JSVM CreateArraybuffer: success
JSVM ArrayBuffer length: 8
```

<!-- @[oh_jsvm_create_arraybuffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutArraybuffer/createarraybuffer/src/main/cpp/hello.cpp) -->
