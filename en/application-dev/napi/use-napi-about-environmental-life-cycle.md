# Associating Data with a Running Environment to Tie Their Lifecycle Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=a532c051393ee6daffab1a4714987334ac546623 translatedAt=2026-08-12T06:39:18.187Z pushedAt=2026-08-12T11:10:19.830Z -->

## Introduction

Node-API provides APIs to associate specific data with the currently running environment so that the data can be retrieved later when required.

## Basic Concepts

By associating the data with the currently running environment, the C++ data struct is associated with that of the environment. This means the associated data remains valid as long as the running environment exists.

## Available APIs

The following table lists the APIs.

| API| Description|
| -------- | -------- |
| napi_set_instance_data | Associates data with the currently running environment.|
| napi_get_instance_data | Retrieves the data that was previously associated with the currently running environment.|

## Example

For details about the Node-API development process, see [Node-API Development Process](use-napi-process.md). This document describes only the related C++ and ArkTS code.

### napi_set_instance_data

Associate data with the currently running environment.

CPP code

<!-- @[napi_set_instance_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIEnvironmentalLifeCycle/entry/src/main/cpp/napi_init.cpp) -->

``` C++
#include "napi/native_api.h"

// Define a structure to store instance data.
struct InstanceData {
    int32_t value;
};

// Callback invoked when the object is released, used to clean up instance data.
void FinalizeCallback(napi_env env, void *finalizeData, void *finalizeHint)
{
    if (finalizeData) {
        InstanceData *data = reinterpret_cast<InstanceData *>(finalizeData);
        // Free the memory and clear the pointer.
        delete (data);
    }
}

// napi_set_instance_data
static napi_value SetInstanceData(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value argv[1];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    int32_t instanceDataValue;
    napi_get_value_int32(env, argv[0], &instanceDataValue);
    InstanceData *instanceData = new InstanceData;
    instanceData->value = instanceDataValue;
    // Call napi_set_instance_data to associate the instance data with the Node-API environment and specify the FinalizeCallback function.
    napi_status status = napi_set_instance_data(env, instanceData, FinalizeCallback, nullptr);
    if (status != napi_ok) {
        delete instanceData;
        napi_throw_error(env, nullptr, "Test Node-API napi_set_instance_data failed");
        return nullptr;
    }
    bool success = true;
    napi_value result = nullptr;
    napi_get_boolean(env, success, &result);
    return result;
}
```

API declaration

<!-- @[napi_set_instance_data_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIEnvironmentalLifeCycle/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const setInstanceData: (data: number) => boolean | undefined; // napi_set_instance_data
```

ArkTS code

<!-- @[ark_napi_set_instance_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIEnvironmentalLifeCycle/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_set_instance_data
let data = 5;
let value = testNapi.setInstanceData(data);
hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_instance_data:%{public}s', value);
```

### napi_get_instance_data

Retrieves the data that was previously associated with the currently running environment.

CPP code

<!-- @[napi_get_instance_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIEnvironmentalLifeCycle/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_instance_data
static napi_value GetInstanceData(napi_env env, napi_callback_info info)
{
    InstanceData *resData = nullptr;
    // Call napi_get_instance_data to obtain the previously associated data item.
    napi_status status = napi_get_instance_data(env, (void **)&resData);
    if (status != napi_ok) {
        return nullptr;
    }

    if (resData == nullptr) {
        napi_throw_error(env, nullptr, "Instance data not set or already freed");
        return nullptr;
    }
    napi_value result = nullptr;
    napi_create_int32(env, resData->value, &result);
    return result;
}
```

API declaration

<!-- @[napi_get_instance_data_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIEnvironmentalLifeCycle/entry/src/main/cpp/types/libentry/Index.d.ts) -->

``` TypeScript
export const getInstanceData: () => number | undefined; // napi_get_instance_data
```

ArkTS code

<!-- @[ark_napi_get_instance_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIEnvironmentalLifeCycle/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_instance_data
let data = 5;
testNapi.setInstanceData(data);
let value = testNapi.getInstanceData();
hilog.info(0x0000, 'testTag', 'Test Node-API napi_set_instance_data:%{public}d', value);
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```

## Notes

1. When `napi_set_instance_data` is called a second time in the same runtime environment, the `FinalizeCallback` registered during the first call is executed, and the original `instance_data` has been released and is no longer valid.

2. During the destruction of the runtime environment, the `FinalizeCallback` registered through the `napi_set_instance_data` API is executed. At this point, the runtime environment is no longer valid. Do not access ArkTS objects such as `napi_ref` and `napi_value` in this callback.