# Working with Buffer Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:37:59.121Z pushedAt=2026-08-12T11:05:47.596Z -->

## Introduction

In ArkTS, **Buffer** is a data type used to represent binary data.

## Basic Concepts

Node-API provides APIs for handling binary data with ArkTS via the **Buffer** object. You can use these APIs to create and operate **Buffer** objects, processing binary data in I/O and network transmission.

- **Buffer** object: an object used to represent binary data.

- External buffer: a buffer created in the Node-API module to associate with existing data without copying the data.

## Available APIs

The following table lists the APIs for processing the binary data in the ArkTS layer, such as file I/O and network transmission.

| API| Description|
| -------- | -------- |
| napi_create_buffer | Creates an ArkTS **Buffer** instance of the specified size.|
| napi_create_buffer_copy | Creates and obtains an ArkTS **Buffer** instance of the specified size and initializes the **Buffer** instance with the given parameters.|
| napi_create_external_buffer | Creates an ArkTS **Buffer** instance of the specified size, and initializes it with the given data. You can use this API to add extra data to the buffer. |
| napi_get_buffer_info | Obtains the underlying data buffer and its length of an ArkTS **Buffer** instance.|
| napi_is_buffer | Checks whether the given ArkTS value is a **Buffer** object.|
| napi_create_external_arraybuffer | Creates an ArkTS external **ArrayBuffer**. An external **ArrayBuffer** is a special type of **ArrayBuffer** that holds the reference to external data without actually owning the data.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code related to **Buffer** management.

### napi_create_buffer

Call **napi_create_buffer** to create a **Buffer** instance. A **Buffer** object is used to manipulate binary data in C/C++.

CPP code:

<!-- @[napi_create_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_create_buffer
static napi_value CreateBuffer(napi_env env, napi_callback_info info)
{
    std::string str("CreateBuffer");
    void *bufferPtr = nullptr;
    size_t bufferSize = str.size();
    napi_value buffer = nullptr;
    // Call the napi_create_buffer API to create and obtain an ArkTS Buffer of a specified size.
    napi_status status = napi_create_buffer(env, bufferSize + 1, &bufferPtr, &buffer);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "napi_create_buffer failed");
        return nullptr;
    }
    // Copy the value of the string str to the buffer's memory.
    strcpy((char *)bufferPtr, str.data());
    return buffer;
}
```

API declaration:

<!-- @[napi_create_buffer_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createBuffer: () => string; // napi_create_buffer
```

ArkTS code:

<!-- @[ark_napi_create_buffer_test](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_create_buffer
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_buffer: %{public}s',
    testNapi.createBuffer().toString());
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_create_buffer error');
  // ...
}
```

### napi_create_buffer_copy

Call **napi_create_buffer_copy** to create a **Buffer** instance of the specified size and initialize it with data copied from the passed-in buffer. This API allows the specified data to be copied to a **Buffer** instance created.

CPP code:

<!-- @[napi_create_buffer_copy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_create_buffer_copy
static napi_value CreateBufferCopy(napi_env env, napi_callback_info info)
{
    // Content to be copied.
    char str[] = "CreateBufferCopy";
    napi_value buffer = nullptr;
    // Call the napi_create_buffer_copy API to create a buffer and copy the content of str to the buffer.
    void* resultData = nullptr;
    napi_status status = napi_create_buffer_copy(env, sizeof(str), str, &resultData, &buffer);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "napi_create_buffer_copy failed");
        return nullptr;
    }
    if (resultData != nullptr) {
        OH_LOG_INFO(LOG_APP, "Node-API resultData is : %{public}s.", reinterpret_cast <const char*>(resultData));
    } else {
        OH_LOG_INFO(LOG_APP, "Node-API resultData is nullptr.");
    }
    return buffer;
}
```

API declaration:

<!-- @[napi_create_buffer_copy_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createBufferCopy: () => string; // napi_create_buffer_copy
```

ArkTS code:

<!-- @[ark_napi_create_buffer_copy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_create_buffer_copy
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_buffer_copy: %{public}s',
    testNapi.createBufferCopy().toString());
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_create_buffer_copy error');
  // ...
}
```

### napi_create_external_buffer

Call **napi_create_external_buffer** to create an ArkTS **Buffer** instance that holds a pointer to existing data. This allows the ArkTS layer to directly access and operate the memory, avoiding additional memory allocation and copy operations.

CPP code:

<!-- @[napi_create_external_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// Callback function used to release memory.
void FinalizeCallback(napi_env env, void *data, void *hint)
{
    if (data == nullptr) {
        return;
    }
    free(data);
    data = nullptr;
}

// napi_create_external_buffer
static napi_value CreateExternalBuffer(napi_env env, napi_callback_info info)
{
    // Create a string.
    std::string str("CreateExternalBuffer");
    // Allocate memory on the heap, with the size equal to the string length.
    void* data = malloc(str.size() + 1);
    if (data == nullptr) {
        OH_LOG_ERROR(LOG_APP, "malloc failed");
        return nullptr;
    }
    memset(data, 0, str.size() + 1);
    // Copy the string to the allocated memory.
    strcpy(static_cast<char *>(data), str.data());
    // Use the napi_create_external_buffer API to create and obtain a buffer of a specified size.
    napi_value buffer = nullptr;
    napi_status status = napi_create_external_buffer(env, str.size(), data, FinalizeCallback, nullptr, &buffer);
    if (status != napi_ok) {
        free(data);
        OH_LOG_ERROR(LOG_APP, "napi_create_external_buffer failed");
        return nullptr;
    }
    return buffer;
}
```

API declaration:

<!-- @[napi_create_external_buffer_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createExternalBuffer: () => string; // napi_create_external_buffer
```

ArkTS code:

<!-- @[ark_napi_create_external_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_create_external_buffer
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_external_buffer: %{public}s',
    testNapi.createExternalBuffer()
      .toString());
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_create_external_buffer error');
  // ...
}
```

### napi_get_buffer_info

Before performing an operation on the data in a **Buffer** instance in ArkTS, use **napi_get_buffer_info** to obtain the pointer to the data and the data length. This allows the data to be operated without copying data.

CPP code:

<!-- @[napi_get_buffer_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_buffer_info
static napi_value GetBufferInfo(napi_env env, napi_callback_info info)
{
    // Create a string.
    std::string str("GetBufferInfo");
    napi_value buffer = nullptr;
    void *bufferPtr = nullptr;
    size_t bufferSize = str.size();
    napi_status status = napi_create_buffer(env, bufferSize + 1, &bufferPtr, &buffer);
    if (status != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "napi_create_buffer failed");
        return nullptr;
    }
    strcpy((char *)bufferPtr, str.data());

    // Obtain the Buffer information.
    void *tmpBufferPtr = nullptr;
    size_t bufferLength = 0;
    napi_get_buffer_info(env, buffer, &tmpBufferPtr, &bufferLength);

    // Create a new ArkTS string to hold the Buffer content and return it.
    if (bufferLength == 0 || ((char*)tmpBufferPtr)[bufferLength - 1] != '\0') {
        OH_LOG_ERROR(LOG_APP, "Buffer is not null-terminated");
        return nullptr;
    }
    napi_value returnValue = nullptr;
    napi_create_string_utf8(env, (char*)tmpBufferPtr, bufferLength, &returnValue);
    return returnValue;
}
```

API declaration:

<!-- @[napi_get_buffer_info_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const getBufferInfo: () => string; // napi_get_buffer_info
```

ArkTS code:

<!-- @[ark_napi_get_buffer_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_buffer_info
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_buffer_info: %{public}s',
    testNapi.getBufferInfo().toString());
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_get_buffer_info error');
  // ...
}
```

### napi_is_buffer

Call **napi_is_buffer** to check whether an ArkTS value is a **Buffer** object.

CPP code:

<!-- @[napi_is_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_is_buffer
static napi_value IsBuffer(napi_env env, napi_callback_info info)
{
    // Create a Buffer object.
    std::string str = "buffer";
    napi_value buffer = nullptr;
    void *bufferPtr = nullptr;
    napi_create_buffer(env, str.size(), &bufferPtr, &buffer);

    // Call the napi_is_buffer API to determine whether the created object is a buffer.
    bool result = false;
    napi_is_buffer(env, buffer, &result);
    // Return the result.
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);
    return returnValue;
}
```

API declaration:

<!-- @[napi_is_buffer_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const isBuffer: () => boolean; // napi_is_buffer
```

ArkTS code:

<!-- @[ark_napi_is_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_is_buffer
try {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_buffer: %{public}s',
    JSON.stringify(testNapi.isBuffer()));
  // ...
} catch (error) {
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_buffer error');
  // ...
}
```

### napi_create_external_arraybuffer

Call **napi_create_external_arraybuffer** to create an ArkTS **ArrayBuffer** with external data.

CPP code:

<!-- @[napi_create_external_arraybuffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/cpp/napi_init.cpp) -->

``` C++
static constexpr int INT_ARG_5 = 5; // Input parameter index.

typedef struct {
    uint8_t *data;
    size_t length;
} BufferData;

void FinalizeCallback1(napi_env env, void *finalizeData, void *finalizeHint)
{
    // Obtain the data upon finalization.
    BufferData *bufferData = static_cast<BufferData *>(finalizeHint);

    // Perform cleanup operations, such as releasing resources.
    delete[] bufferData->data;
    delete bufferData;
}

// napi_create_external_arraybuffer
napi_value CreateExternalArraybuffer(napi_env env, napi_callback_info info)
{
    // Create a C++ array with five elements.
    uint8_t *dataArray = new uint8_t[5]{1, 2, 3, 4, 5};
    napi_value externalBuffer = nullptr;
    BufferData *bufferData = new BufferData{dataArray, 5};

    // Use napi_create_external_arraybuffer to create an external ArrayBuffer object and specify the finalization callback.
    napi_status status =
        napi_create_external_arraybuffer(env, dataArray, INT_ARG_5, FinalizeCallback1, bufferData, &externalBuffer);
    if (status != napi_ok) {
        // Handle the error.
        delete[] dataArray;
        delete bufferData;
        napi_throw_error(env, nullptr, "Node-API napi_create_external_arraybuffer fail");
        return nullptr;
    }
    napi_value outputArray;
    // Use napi_create_typedarray to create an Array object, passing the externalBuffer object as a parameter.
    status = napi_create_typedarray(env, napi_int8_array, INT_ARG_5, externalBuffer, 0, &outputArray);
    if (status != napi_ok) {
        // Handle the error.
        napi_throw_error(env, nullptr, "Node-API napi_create_typedarray fail");
        return nullptr;
    }
    return outputArray;
}
```

API declaration:

<!-- @[napi_create_external_arraybuffer_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const createExternalArraybuffer: () => ArrayBuffer | undefined; // napi_create_external_arraybuffer
```

ArkTS code:

<!-- @[ark_napi_create_external_arraybuffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIBuffer/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_create_external_arraybuffer
hilog.info(0x0000, 'testTag', 'Node-API createExternalArraybuffer: %{public}s',
  JSON.stringify(testNapi.createExternalArraybuffer()));
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```