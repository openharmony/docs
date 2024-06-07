# Using Node-API Extension Capabilities

## Overview

Node-API provides APIs to implement extra capabilities for more flexible interaction between native code and JavaScript (JS) code. You can use these APIs to create custom JS objects.

## Basic Concepts

Before using Node-API extension APIs, you need to understand the following basic concepts:

- Module: A module is independent code unit that can be reused. It encapsulates certain functions that can be referenced and used by another module.
- Namespace: A namespace is a mechanism used to organize code. Related functions, variables, and types can be grouped around a specific functionality in a namespace to prevent naming conflicts.

## Available APIs

The following table lists the Node-API extension APIs.  
| API| Description|
| -------- | -------- |
| napi_load_module | Loads an .abc file as a module. This API returns the namespace of the module. You can use it for the applications that need to dynamically load modules or resources in runtime.|
| napi_create_object_with_properties | Creates a JS object with the given **napi_property_descriptor** in a native module. The key of **napi_property_descriptor** must be a string that cannot be converted into a number.|
| napi_create_object_with_named_properties | Creates a JS object with the given **napi_value** and key in a native module. The key must be a string and cannot be converted into a number.|
| napi_run_script_path | Runs the specified .abc file.|
| napi_queue_async_work_with_qos | Adds an asynchronous work object to the queue and schedules it based on the QoS passed in.|
| napi_coerce_to_native_binding_object | Forcibly binds a JS object and a native callback with necessary data. This API allows the JS object to carry native information.|

## Example

### napi_load_module

[napi_load_module](use-napi-load-module.md)

### napi_create_object_with_properties

Creates a JS object with the given **napipropertydescriptor**. The key of **napipropertydescriptor** must be a string that cannot be converted into a number.

CPP code

```cpp
static napi_value CreateObjectWithProperties(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1] = nullptr;
    // Obtain the parameters of the call.
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    // Declare a desc array in napi_property_descriptor. The desc array contains a property named "name", whose value is the first input parameter argv[0].
    napi_property_descriptor desc[] = {
        {"name", nullptr, nullptr, nullptr, nullptr, argv[0], napi_default_jsproperty, nullptr}};
    napi_value object = nullptr;
    // Call napi_create_object_with_properties to create a JS object with the specified properties.
    napi_create_object_with_properties(env, &object, sizeof(desc) / sizeof(desc[0]), desc);
    napi_valuetype valueType;
    napi_typeof(env, object, &valueType);
    if (valueType == napi_object) {
        return object;
    }
}
```

API declaration

```ts
// index.d.ts
export const createObjectWithProperties: (data: string) => Object;
```

ArkTS code

```ts
import testNapi from 'libentry.so';

let value = testNapi.createObjectWithProperties('createObject');
hilog.info(0x0000, 'testTag', 'NAPI napi_create_object_with_properties:%{public}s', JSON.stringify(value));
```

### napi_create_object_with_named_properties

Create a JS object with the specified **napi_value** and key. The key must be a string and cannot be converted into a number.

CPP code

```cpp
static napi_value CreateObjectWithNameProperties(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value argv[1] = nullptr;
    // Obtain the parameters of the call.
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

API declaration

```ts
// index.d.ts
export const createObjectWithNameProperties: (data: string) => string | { name: string };
```

ArkTS code

```ts
import testNapi from 'libentry.so';

let value = testNapi.createObjectWithNameProperties('ls');
hilog.info(0x0000, 'testTag', 'NAPI napi_create_object_with_named_properties:%{public}s', JSON.stringify(value));
```

### napi_run_script_path

Run an .abc file in the Node-API module.

CPP code

```cpp
static napi_value RunScriptPath(napi_env env, napi_callback_info info)
{
    napi_value value = nullptr;
    // The .abc file in the rawfile directory of the application.
    const char *scriptPath = "/entry/resources/rawfile/test.abc";
    // Call napi_run_script_path to execute the file of the specified path.
    napi_status status = napi_run_script_path(env, scriptPath, &value);
    // Check whether the script execution is successful. If the execution fails, false will be returned.
    napi_value returnValue = nullptr;
    if (value == nullptr || status != napi_ok) {
        napi_get_boolean(env, false, &returnValue);
    }
    napi_get_boolean(env, true, &returnValue);
    return returnValue;
}
```

API declaration

```ts
// index.d.ts
export const runScriptPath: () => boolean;
```

ArkTS code

```ts
import testNapi from 'libentry.so';

try {
  // Return true is the script is executed successfully; returns false otherwise.
  hilog.info(0x0000, 'testTag', 'Test NAPI napi_run_script_path: %{public}s', testNapi.runScriptPath());
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test NAPI napi_run_script_path errorMessage: %{public}s', error.message);
}
```

To compile JS code, **test.js** for example, into an .abc file, perform the following steps:

1. Place the **test.js** file in the **ets/build-tools/ets-loader/bin/ark/build-win/bin** directory of the SDK.
2. Run the **es2abc.exe test.js --output test.abc** command. The **test.abc** file is generated.

Save the file to the **/entry/resources/rawfile** directory.

```js
function add(a, b) {
  return a+b;
}
add(1, 2);
```

### napi_queue_async_work_with_qos

Add an asynchronous work object to the queue and schedules it based on the QoS passed in.

See [Specifying the Asynchronous Work Priority](../performance/develop-Native-modules-using-NAPI-safely-and-efficiently.md#specifying-the-asynchronous-work-priority).

### napi_coerce_to_native_binding_object

Forcibly bind a JS object and a native callback with necessary data. This API allows the JS object to carry native information.

CPP code

```cpp
// Detach a callback. Generally, it is called in serialization to perform clear operations when the object is detached.
static void *DetachCb(napi_env env, void *nativeObject, void *hint)
{
    OH_LOG_INFO(LOG_APP, "NAPI this is detach callback");
    return nativeObject;
}

// Attach a callback. It is generally called during serialization.
static napi_value AttachCb(napi_env env, void *nativeObject, void *hint)
{
    OH_LOG_INFO(LOG_APP, "NAPI this is attach callback");
    napi_value object = nullptr;
    napi_value name = nullptr;
    // hint is a pointer to the additional information to be passed to the callback function.
    // Check whether hint is null.
    if (hint != nullptr) {
        // Forcibly convert nativeObject of the void* type to the object of napi_value.
        object = reinterpret_cast<napi_value>(nativeObject);
        // Set name.
        napi_create_string_utf8(env, "Leili", NAPI_AUTO_LENGTH, &name);
    } else {
        napi_create_object(env, &object);
        // Set name.
        napi_create_string_utf8(env, "Hanmeimei", NAPI_AUTO_LENGTH, &name);
    }
    // Set the native value to the JS object.
    napi_set_named_property(env, object, "name", name);
    return object;
}

static napi_value CoerceToNativeBindingObject(napi_env env, napi_callback_info info)
{
    // Create a JS object.
    napi_value object = nullptr;
    napi_create_object(env, &object);
    // Call napi_coerce_to_native_binding_object to enable the JS object to carry native information.
    napi_status status = napi_coerce_to_native_binding_object(env, object, DetachCb, AttachCb,
                                                              reinterpret_cast<void *>(object), nullptr);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "NAPI napi_coerce_to_native_binding_object fail");
        return nullptr;
}
    }
    return object;
}
```

API declaration

```ts
// index.d.ts
export const coerceToNativeBindingObject: () => Object | void;
```

ArkTS code

```ts
// index.ets
// Import the worker module to trigger serialization.
import hilog from '@ohos.hilog'
import worker from '@ohos.worker';
import testNapi from 'libentry.so';

let wk = new worker.ThreadWorker("entry/ets/workers/worker.ts");
// Send a message to the worker thread.
wk.postMessage("test napi_coerce_to_native_binding_object");
// Process the message from the worker thread.
wk.onmessage = (message) => {
  hilog.info(0x0000, 'testTag', 'Test NAPI message from worker thread: %{public}s', JSON.stringify(message));
};
```

```ts
// worker.ts
// Process the message from the main thread.
import worker from '@ohos.worker';
import testNapi from 'libentry.so'
import hilog from '@ohos.hilog'

let parent = worker.workerPort;
parent.onmessage = function(message) {
  hilog.info(0x0000, 'testTag', 'Test NAPI message from main thread: %{public}s', JSON.stringify(message));
  // Send a message to the main thread.
  parent.postMessage(testNapi.coerceToNativeBindingObject());
}
```

For details about the worker development, see:
[Starting the Worker](../reference/apis-arkts/js-apis-worker.md)

### Configuring Compile Settings and Registering a Module

- Configure compile settings.

```text
// CMakeLists.txt
# the minimum version of CMake.
cmake_minimum_required(VERSION 3.4.1)
project(AboutExtension)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

add_library(entry SHARED extension.cpp)
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```

- Register the module.

```cpp
// extension.cpp
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        {"createObjectWithProperties", nullptr, CreateObjectWithProperties, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createObjectWithNameProperties", nullptr, CreateObjectWithNameProperties, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"runScriptPath", nullptr, RunScriptPath, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"queueAsyncWorkWithQos", nullptr, QueueAsyncWorkWithQos, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"coerceToNativeBindingObject", nullptr, CoerceToNativeBindingObject, nullptr, nullptr, nullptr, napi_default, nullptr}
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END
```

<!--no_check-->