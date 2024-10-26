# Working with Primitives Using JSVM-API

## Introduction

JSVM-API provides APIs for converting data between C/C++ and JavaScript (JS) data types and obtaining the JS object of the specified type.

## Basic Concepts

Before using JSVM-API to operate JS objects, you need to understand the following basic concepts:

- Conversion between JS and C/C primitives: You can use JSVM-API to convert JS values to C/C++ data types, for example, convert a JS value into a C/C++ integer and convert a JS string into a C/C++ string array. You can also convert C/C++ data into a JS value and return the JS value to JS.

## Available APIs

| API                  | Description                                               |
| ---------------------- | ------------------------------------------------------- |
| OH_JSVM_CoerceToBool   | Converts a JS value to an object of the Boolean type.  |
| OH_JSVM_CoerceToNumber | Converts a JS value to an object of the number type.   |
| OH_JSVM_CoerceToObject | Converts a JS value to an object of the object type.   |
| OH_JSVM_CoerceToString | Converts a JS value to an object of the string type.   |
| OH_JSVM_GetBoolean       | Obtains a JS singleton object that is used to represent the given Boolean value. |
| OH_JSVM_GetValueBool    | Obtains the C Boolean primitive equivalent of the given JS Boolean. |
| OH_JSVM_GetGlobal      | Obtains the **global** object of the current environment.                                     |
| OH_JSVM_GetNull          | Obtains the JS **null** object.                                       |
| OH_JSVM_GetUndefined     | Obtains the JS **undefined** object.                                  |

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code involved in primitive-related APIs.

### OH_JSVM_CoerceToBool

Use **OH_JSVM_CoerceToBool** to forcibly convert a JS value to a JS Boolean value.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CoerceToBool callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CoerceToBool},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named coerceToBool and associate it with a callback. This allows the CoerceToBool callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"coerceToBool", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CoerceToBool.
static JSVM_Value CoerceToBool(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value boolean = nullptr;
    JSVM_Status status = OH_JSVM_CoerceToBool(env, args[0], &boolean);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CoerceToBool failed");
    } else {
        bool result = false;
        OH_JSVM_GetValueBool(env, boolean, &result);
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToBool success:%{public}d", result);
    }
    return boolean;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `coerceToBool("123")`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'CoerceToBool: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'CoerceToBool: %{public}s', error.message);
}
```

### OH_JSVM_CoerceToNumber

Use **OH_JSVM_CoerceToNumber** to forcibly convert a JS value to a JS number.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CoerceToNumber callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CoerceToNumber},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named coerceToNumber and associate it with a callback. This allows the CoerceToNumber callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"coerceToNumber", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CoerceToNumber.
static JSVM_Value CoerceToNumber(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value number = nullptr;
    JSVM_Status status = OH_JSVM_CoerceToNumber(env, args[0], &number);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CoerceToNumber failed");
    } else {
        int32_t result = 0;
        OH_JSVM_GetValueInt32(env, number, &result);
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToNumber success:%{public}d", result);
    }
    return number;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `coerceToNumber(true)`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'CoerceToNumber: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'CoerceToNumber: %{public}s', error.message);
}
```

### OH_JSVM_CoerceToObject

Use **OH_JSVM_CoerceToObject** to forcibly convert a JS value to a JS object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CoerceToObjec callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CoerceToObject},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named coerceToObject and associate it with a callback. This allows the CoerceToObject callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"coerceToObject", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CoerceToObject.
static JSVM_Value CoerceToObject(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value obj;
    JSVM_Status status = OH_JSVM_CoerceToObject(env, args[0], &obj);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_CoerceToObject failed");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToObject success");
    }
    return obj;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `coerceToObject(123)`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'CoerceToObject001: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'CoerceToObject001: %{public}s', error.message);
}
```

### OH_JSVM_CoerceToString

Use **OH_JSVM_CoerceToString** to forcibly convert a JS value to a JS string.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CoerceToString callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CoerceToString},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named coerceToString and associate it with a callback. This allows the CoerceToString callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"coerceToString", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CoerceToString.
static JSVM_Value CoerceToString(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    JSVM_Value str;
    JSVM_Status status = OH_JSVM_CoerceToString(env, args[0], &str);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "JSVM OH_JSVM_CoerceToString fail");
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToString success");
    }
    return str;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `coerceToString(22222)`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'CoerceToString: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'CoerceToString: %{public}s', error.message);
}
```

### OH_JSVM_GetBoolean

Use **OH_JSVM_GetBoolean** to obtain a JS singleton object that is used to represent the given Boolean value.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetBoolean callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetBoolean},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getBoolean and associate it with a callback. This allows the GetBoolean callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getBoolean", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetBoolean.
static JSVM_Value GetBoolean(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Pass in two parameters and parse them.
    size_t argc = 2;
    JSVM_Value argv[2] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, argv, nullptr, nullptr);
    int32_t paramData;
    OH_JSVM_GetValueInt32(env, argv[0], &paramData);
    int32_t paramValue;
    OH_JSVM_GetValueInt32(env, argv[1], &paramValue);
    JSVM_Value returnValue = nullptr;
    bool type = false;
    if (paramData == paramValue)
        　{
            OH_LOG_INFO(LOG_APP, "JSVM resultType equal");
            type = true;
        }
    JSVM_Status status = OH_JSVM_GetBoolean(env, type, &returnValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_CoerceToNumber fail");
    } else {
        bool result = false;
        OH_JSVM_GetValueBool(env, returnValue, &result);
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_CoerceToNumber success:%{public}d", result);
    }
    // Return the result.
    return returnValue;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let data = 1;
  let compareData = 2;
  let script: string = `getBoolean(${data}, ${compareData})`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'GetBoolean: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'GetBoolean: %{public}s', error.message);
}
try {
  let data = 1;
  let compareData = 1;
  let script: string = `getBoolean(${data}, ${compareData})`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'GetBoolean: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'GetBoolean: %{public}s', error.message);
}
```

### OH_JSVM_GetValueBool

Use **OH_JSVM_GetValueBool** to obtain the C Boolean equivalent of the given JS Boolean.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetValueBool callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetValueBool},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getValueBool and associate it with a callback. This allows the GetValueBool callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getValueBool", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetValueBool.
static JSVM_Value GetValueBool(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool result;
    JSVM_Status status = OH_JSVM_GetValueBool(env, args[0], &result);
    if (status == JSVM_BOOLEAN_EXPECTED || status != JSVM_OK) {
        // If OH_JSVM_GetValueBool is successful, JSVM_OK is returned. If a non-Boolean value is passed in, JSVM_BOOLEAN_EXPECTED is returned.
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetValueBool fail:%{public}d", status);
        return nullptr;
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetValueBool success:%{public}d", result);
    }
    JSVM_Value boolJv;
    OH_JSVM_GetBoolean(env, result, &boolJv);
    return boolJv;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
// Pass in a Boolean value and a non-Boolean value. After the Boolean value is passed in, the Boolean value is returned. After the non-Boolean value is passed in, undefined is returned.
try {
  let data = `"abc"`;
  let script: string = `getValueBool(${data})`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'GetValueBool: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'GetValueBool: %{public}s', error.message);
}
try {
  let data = true;
  let script: string = `getValueBool(${data})`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'GetValueBool: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'GetValueBool: %{public}s', error.message);
}
try {
  let data = false;
  let script: string = `getValueBool(${data})`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'GetValueBool: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'GetValueBool: %{public}s', error.message);
}
```

### OH_JSVM_GetGlobal

Use **OH_JSVM_GetGlobal** to obtain a JS global object. You can use this API to obtain the **JSVM_Value** that represents a JS global object, so that the JSVM module can interact with the global variables and functions defined in the JS context.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetGlobal callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetGlobal},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getGlobal and associate it with a callback. This allows the GetGlobal callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getGlobal", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetGlobal.
static JSVM_Value GetGlobal(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain the global object.
    JSVM_Value value = nullptr;
    JSVM_Value global;
    OH_JSVM_CreateInt32(env, 1, &value);
    JSVM_Status status = OH_JSVM_GetGlobal(env, &global);
    OH_JSVM_SetNamedProperty(env, global, "Row", value);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetGlobal fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetGlobal success");
    }
    return global;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `getGlobal()`
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'GetGlobal: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'GetGlobal: %{public}s', error.message);
}
```

### OH_JSVM_GetNull

Use **OH_JSVM_GetNull** to obtain a JS **null** object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetNull callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetNull},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getNull and associate it with a callback. This allows the GetNull callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getNull", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetNull.
static JSVM_Value GetNull(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_Value nullValue;
    JSVM_Status status = OH_JSVM_GetNull(env, &nullValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetNull fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetNull success");
    }
    return nullValue;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let script: string = `getNull()`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'GetNull: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'GetNull: %{public}s', error.message);
}
```

### OH_JSVM_GetUndefined

Use **OH_JSVM_GetUndefined** to obtain a JS **undefined** object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetUndefined callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetUndefined},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getUndefined and associate it with a callback. This allows the GetUndefined callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getUndefined", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetUndefined.
static JSVM_Value GetUndefined(JSVM_Env env, JSVM_CallbackInfo info)
{
    // Obtain and parse the parameters passed in.
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Create the value 'undefined'.
    JSVM_Value value;
    JSVM_Status status = OH_JSVM_GetUndefined(env, &value);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM OH_JSVM_GetUndefined failed");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM OH_JSVM_GetUndefined success");
    }
    return value;
}
```

API declaration:

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let script: string = `getUndefined()`;
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'JSVM', 'GetUndefined: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'JSVM', 'GetUndefined: %{public}s', error.message);
}
```
