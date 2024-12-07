# Working with Other Node-API Utilities 

## Introduction

Node-API also provides some useful APIs to improve development experience.

## Basic Concepts

- Module loading: A module is an ArkTS file that contains specific functionalities. You can import a module to the shared library. Understanding the loading mechanism and dependencies between Node-API modules is helpful for using **node_api_get_module_file_name** correctly.
- File path and URL: The return value of **node_api_get_module_file_name** is the absolute path of the module to be loaded.
- Strict equality check: The strict equality check is used to check whether two ArkTS values are equal in type and value. When type conversion is considered, if the values being compared are of different types, **false** will be returned even if the values are the same.
- Asynchronous operation processing: libuv can be used to implement asynchronous operations to avoid blocking the main thread.
- Event loop: The Node-API module leverages libuv to implement the event-driven programming model. libuv provides an event loop mechanism to process events, trigger callbacks, and manage event queues.

## Available APIs

| API| Description|
| -------- | -------- |
| node_api_get_module_file_name | Obtains the absolute path of the module to be loaded.|
| napi_strict_equals | Checks whether two values are strictly equal, that is, equal in both the value and type. For example, you can use **napi_strict_equals** to ensure data consistency when working on data structs or algorithms of the specific type. |

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code involved in the APIs mentioned in this topic.

### node_api_get_module_file_name

Use **node_api_get_module_file_name** to obtain the absolute path of the module to be loaded.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value GetModuleFileName(napi_env env, napi_callback_info info)
{
    // Declare file, a pointer variable of the const char type, to store the absolute path of the module.
    const char *file = nullptr;
    napi_value value = nullptr;
    // Obtain the absolute path of the module and store it in the file variable.
    napi_status status = node_api_get_module_file_name(env, &file);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Failed to get module file name");
        return nullptr;
    }
    // Create a string of the napi_value type that contains the absolute path.
    napi_create_string_utf8(env, file, NAPI_AUTO_LENGTH, &value);
    return value;
}
```

API declaration:

```ts
// index.d.ts
export const getModuleFileName: () => string | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'

let filename = testNapi.getModuleFileName();
hilog.info(0x0000, 'testTag', 'Test Node-API node_api_get_module_file_name:%{public}s', filename);
```

### napi_strict_equals

Use **napi_strict_equals** to check whether two ArkTS values are strictly equal.

CPP code:

```cpp
#include "napi/native_api.h"

static napi_value StrictEquals(napi_env env, napi_callback_info info)
{
    // Obtain the two parameters passed from ArkTS.
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Call napi_strict_equals to check whether two ArkTS values are strictly equal.
    bool result = true;
    napi_status status = napi_strict_equals(env, args[0], args[1], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_get_cb_info fail");
        return nullptr;
    }
    // Convert the result to napi_value and return napi_value.
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);
    return returnValue;
}
```

API declaration:

```ts
// index.d.ts
export const strictEquals : (lhs: string, rhs: string | number) => boolean | void;
```

ArkTS code:

```ts
import hilog from '@ohos.hilog'
import testNapi from 'libentry.so'
try {
  let lhs = "123";
  let rhs = "123";
  let str = "456";
  let num = 123;
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_strict_equals: %{public}s', testNapi.strictEquals(lhs, rhs));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_strict_equals: %{public}s', testNapi.strictEquals(lhs, str));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_strict_equals: %{public}s', testNapi.strictEquals(lhs, num));
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_strict_equals error: %{public}s', error.message);

}
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```
