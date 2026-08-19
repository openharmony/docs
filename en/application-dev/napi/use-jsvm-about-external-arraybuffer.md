# Creating an ArrayBuffer from External Memory Using JSVM-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:32:28.570Z pushedAt=2026-08-12T10:56:00.802Z -->

## Overview

ArrayBuffer is a JavaScript data type that represents a generic, fixed-length raw binary data buffer. It provides a way to efficiently represent and manipulate raw binary data in JavaScript.

In certain scenarios, such as when an app already has a block of external memory (for example, memory mapped from a file, a hardware buffer, or memory allocated by another native module), you may want to wrap it as a JavaScript ArrayBuffer object for read and write operations in the JS layer. Starting from API version 26.0.0, JSVM-API provides the [OH_JSVM_CreateArrayBufferFromExternalMemory](../reference/common/capi-jsvm-h.md#oh_jsvm_createarraybufferfromexternalmemory) API to address such scenarios.

## Basic Concepts

- **Zero-copy and copy**: This API **does not guarantee zero-copy**. In certain JSVM implementations or versions, the external memory may be copied to an internal engine buffer. The output parameter `copied` indicates whether a copy has occurred. **You must not rely on zero-copy behavior**, because the value of `copied` may change as the JSVM version evolves.

- **Memory lifecycle**: This API accepts an optional callback of type [JSVM_FinalizeArrayBuffer](../reference/common/capi-jsvm-types-h.md#jsvm_finalizearraybuffer). The callback includes a `bool copied` parameter that indicates whether the data has been copied. When `copied` is false (zero-copy), the ArrayBuffer directly references the external memory, and the caller **must ensure that the memory is not freed before finalizeCb is called** (the caller can free the external memory in the callback). When `copied` is true, the caller can free the external memory immediately after the API returns.

## Available APIs

> **NOTE**
>
> This API is experimental. Define the `JSVM_EXPERIMENTAL` macro before using it.

| Name                                        | Description                                                 |
| ------------------------------------------- | -------------------------------------------------------- |
| OH_JSVM_CreateArrayBufferFromExternalMemory | Creates an ArrayBuffer object from external memory. |

### Parameter Description

| Name | Description |
| -- | -- |
| [JSVM_Env](../reference/common/capi-jsvm-jsvm-env--8h.md) env | JSVM-API environment. |
| void *externalData | External memory pointer. **Must be 8-byte aligned**. |
| size_t byteLength | Length of the external memory in bytes. Must not exceed the maximum ArrayBuffer size of the engine. |
| [JSVM_FinalizeArrayBuffer](../reference/common/capi-jsvm-types-h.md#jsvm_finalizearraybuffer) finalizeCb | Optional parameter. Callback invoked when the ArrayBuffer is reclaimed by GC. The callback signature includes a `bool copied` parameter that indicates whether a copy occurred. Pass NULL for this parameter when byteLength is 0. |
| void* finalizeHint | Optional parameter. Custom hint data passed to finalizeCb. |
| bool* copied | Optional output parameter. The value **true** indicates that the data is copied, and **false** indicates zero-copy. |
| [JSVM_Value](../reference/common/capi-jsvm-jsvm-value--8h.md) *result | Output parameter. The created ArrayBuffer object. |

### JSVM_FinalizeArrayBuffer Callback Type

```c
typedef void (*JSVM_FinalizeArrayBuffer)(JSVM_Env env, void* finalizeData, void* finalizeHint, bool copied);
```

| Name | Description |
| ------------- | --------------------------------------------------------------------- |
| env | Environment handle. Always NULL and must not be used. |
| finalizeData | Pointer to `externalData` passed when the API is called. |
| finalizeHint | Pointer to `finalizeHint` passed when the API is called. |
| copied | Whether a copy occurred. The value **true** indicates that the engine copied the data and the original `externalData` memory is not managed by the engine; **false** indicates zero-copy, meaning the engine directly references the `externalData` memory. |

The `JSVM_FinalizeArrayBuffer` callback is invoked when the associated ArrayBuffer object is reclaimed, so that native cleanup actions can be performed. Observe the following rules when using `JSVM_FinalizeArrayBuffer`:

- Because the timing of the `JSVM_FinalizeArrayBuffer` callback invocation is indeterminate (it may occur during GC or VM destruction), the JSVM environment may already be destroyed when the callback is invoked. Therefore, the `env` parameter of `JSVM_FinalizeArrayBuffer` is always NULL.

- The callback must only release resources and must not execute complex logic. Do not call other JSVM APIs within the callback.

- The callback may be invoked on a thread other than the JSVM main thread. If the callback needs to access shared state, atomic operations or locks must be used for synchronization.

- The memory release strategy is determined by the `copied` parameter.

### Return Values

- **JSVM_OK**: The creation is successful.

- **JSVM_INVALID_ARG**: Invalid parameter. Possible causes: `result` is NULL; `byteLength` > 0 but `externalData` is NULL; `externalData` is not 8-byte aligned; `byteLength` exceeds the engine's maximum limit; `byteLength` == 0 but `finalizeCb` is not NULL.

## Special Notes

1. **The experimental macro must be enabled**: `#define JSVM_EXPERIMENTAL` must be placed before `#include "ark_runtime/jsvm.h"` and `#include "ark_runtime/jsvm_types.h"`, otherwise the API is not visible.

2. **Zero-copy is not guaranteed**: The value of the `copied` output parameter depends on the current JSVM implementation and may change as the version evolves. You **must not rely on zero-copy behavior in your business logic**, otherwise undefined behavior may occur.

3. **8-byte alignment**: `externalData` must be 8-byte aligned, otherwise `JSVM_INVALID_ARG` is returned.

4. **Managing memory with the `copied` parameter**:

   - **Recommended approach**: In `finalizeCb`, determine whether to release the external memory based on the `copied` parameter. When `copied` is false, release the external memory in `finalizeCb` (otherwise the underlying memory of the ArrayBuffer will leak).

   - The `copied` parameter of `finalizeCb` is always consistent with the value of the API output parameter `copied`.

5. **finalizeCb call timing**: finalizeCb is called when the ArrayBuffer object is reclaimed by GC, and the call timing is indeterminate. Do not perform time-consuming operations in finalizeCb.

## Usage Example

For the JSVM-API development process, see [JSVM-API Development Process](use-jsvm-process.md). This document only presents the C++ code related to the API.

This example demonstrates how to create an ArrayBuffer from external memory and properly manage the external memory lifecycle based on the `copied` parameter.

C++ code:

<!-- @[oh_jsvm_create_arraybuffer_from_external_memory](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutExternalArraybuffer/createarraybufferfromexternalmemory/src/main/cpp/hello.cpp) -->

``` C++
#define JSVM_EXPERIMENTAL  // Must be defined before including jsvm.h; otherwise, experimental APIs cannot be called.
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include "hilog/log.h"
#include <cstdlib>
#include <cstring>
// ...

// Simulate obtaining image pixel data from an external module (RGBA, 4 pixels).
static void *LoadPixelData(size_t *outSize)
{
    *outSize = 16;  // 4pixels×4bytes(RGBA)
    uint8_t *data = static_cast<uint8_t *>(malloc(*outSize));
    if (data == nullptr) {
        return nullptr;
    }
    // Fill sample pixels: red, green, blue, and white.
    uint8_t pixels[] = {
        255, 0, 0, 255,     // Red
        0, 255, 0, 255,     // Green
        0, 0, 255, 255,     // Blue
        255, 255, 255, 255  // White
    };
    memcpy(data, pixels, *outSize);
    return data;
}

// Finalize callback: determines whether to release external memory based on the copied parameter.
static void PixelDataFinalize(JSVM_Env env, void *data, void *hint, bool copied)
{
    if (!copied) {
        // Zero-copy mode: the engine releases the reference to the external memory, and you are responsible for freeing it.
        free(data);
    } else {
        // Copy mode: the engine has copied the data, and the original memory should have been freed after the API returned.
        // The data pointer may be invalid. Do not use it.
    }
}

// Sample method for OH_JSVM_CreateArrayBufferFromExternalMemory
static JSVM_Value CreateArrayBufferFromExternal(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_Value undef = nullptr;
    OH_JSVM_GetUndefined(env, &undef);
    // 1. Obtain data from an external module (allocated by malloc, meeting the 8-byte alignment requirement).
    size_t dataSize = 0;
    void *pixelData = LoadPixelData(&dataSize);
    if (pixelData == nullptr) {
        OH_LOG_ERROR(LOG_APP, "JSVM: failed to load pixel data");
        return undef;
    }

    JSVM_HandleScope scope = nullptr;
    OH_JSVM_OpenHandleScope(env, &scope);

    // 2. Create an ArrayBuffer.
    JSVM_Value arrayBuffer = nullptr;
    bool copied = false;
    JSVM_Status status = OH_JSVM_CreateArrayBufferFromExternalMemory(
        env, pixelData, dataSize, PixelDataFinalize, nullptr, &copied, &arrayBuffer);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateArrayBufferFromExternalMemory: failed");
        free(pixelData);  // Manually release memory on creation failure.
        return undef;
    }

    // 3. Manage the original memory based on the copied parameter.
    if (copied) {
        // The engine copied the data. The original external memory is no longer used by the engine and can be freed immediately.
        free(pixelData);
    }
    // When copied==false: The engine directly uses the external memory, and finalizeCb is responsible for freeing it during GC.

    // 4. Obtain the data pointer to the ArrayBuffer through OH_JSVM_GetArraybufferInfo to access the data.
    //    Do not directly use the pixelData pointer, because in copy mode the ArrayBuffer internally uses
    //    the copied data, and pixelData points to the original external memory.
    void *abData = nullptr;
    size_t abLen = 0;
    OH_JSVM_GetArraybufferInfo(env, arrayBuffer, &abData, &abLen);
    OH_LOG_INFO(LOG_APP, "JSVM CreateArrayBufferFromExternalMemory: success, "
                "byteLength=%{public}zu", abLen);

    OH_JSVM_CloseHandleScope(env, scope);

    // Trigger GC to reclaim the External ArrayBuffer.
    OH_JSVM_MemoryPressureNotification(env, JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL);
    return undef;
}

// Register the CreateArrayBufferFromExternal callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateArrayBufferFromExternal},
};
static JSVM_CallbackStruct *method = param;
// Alias of the CreateArrayBufferFromExternal method for JS invocation.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createArrayBufferFromExternal", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Sample test JS.
const char *SRC_CALL_NATIVE = R"JS(
createArrayBufferFromExternal();
)JS";
```

Expected result:

```txt
JSVM CreateArrayBufferFromExternalMemory: success, byteLength=16
```