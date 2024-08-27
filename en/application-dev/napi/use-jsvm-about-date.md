# Working with Date Using JSVM-API

## Introduction

JSVM-API provides APIs for processing JavaScript (JS) **Date** objects in C/C++. These APIs are useful for working with time- and date-related logic in the JSVM module.

## Basic Concepts

In JSVM-API, the value of a JS **Date** object is the number of milliseconds elapsed since the Unix epoch (00:00:00 UTC on January 1, 1970).

The JS **Date** object provides a way to represent and manage date and time in JS. With the **Date** object, you can create an object that represents a specific moment, perform date- and time-related calculations (such as adding or subtracting time intervals), and format date as a string for display.

With the functions for interacting with the **Date** object, the JSVM module can be closely integrated with the JS environment to perform more complex date- and time-related operations.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_CreateDate           | Creates a **Date** object representing the given number of milliseconds. |
| OH_JSVM_GetDateValue        | Obtains the C double primitive of the time value for the given JS **Date** object. |
| OH_JSVM_IsDate               | Checks whether a JS object is a date.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ and ArkTS code for date management.

### OH_JSVM_CreateDate

Use **OH_JSVM_IsTypedarray** to create a **Date** object representing the given number of milliseconds.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the CreateDate callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateDate},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createDate and associate it with a callback. This allows the createDate callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createDate", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_CreateDate.
static JSVM_Value CreateDate(JSVM_Env env, JSVM_CallbackInfo info) {
    double value = 1501924876711;
    // Call OH_JSVM_CreateDate to convert the double value into a JS value indicating the date and time.
    JSVM_Value returnValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateDate(env, value, &returnValue);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM CreateDate fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM CreateDate success");
    }
    return returnValue;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `createDate()`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM CreateDate: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM CreateDate error: %{public}s', error.message);
}
```

### OH_JSVM_GetDateValue

Use **OH_JSVM_GetDateValue** to obtain the C double primitive of the time value for the given JS **Date** object.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the GetDateValue callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetDateValue},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named getDateValue and associate it with a callback. This allows the GetDateValue callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getDateValue", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_GetDateValue.
static JSVM_Value GetDateValue(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the Unix timestamp passed in.
    double value;
    JSVM_Status status = OH_JSVM_GetDateValue(env, args[0], &value);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsArray fail");
    } else {
        // Print the obtained Unix timestamp.
        OH_LOG_INFO(LOG_APP, "JSVM gets the incoming Green time:%{public}lf.", value);
    }
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateDouble(env, value, &returnValue);
    return returnValue;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
let script: string = `getDateValue(new Date(Date.now()))`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetDateValue: %{public}s', result);
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetDateValue error: %{public}s', error.message);
}
```

### OH_JSVM_IsDate

Use **OH_JSVM_IsDate** to check whether a JS object is a date.

CPP code:

```cpp
// hello.cpp
#include "napi/native_api.h"
#include "ark_runtime/jsvm.h"
#include <hilog/log.h>
// Register the IsDate callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsDate},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named isDate and associate it with a callback. This allows the IsDate callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"isDate", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Define OH_JSVM_IsDate.
static JSVM_Value IsDate(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    bool result;
    JSVM_Status status = OH_JSVM_IsDate(env, args[0], &result);
    if (status != JSVM_OK) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsDate fail");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM IsDate success:%{public}d", result);
    }
    JSVM_Value isDate = nullptr;
    OH_JSVM_GetBoolean(env, result, &isDate);
    return isDate;
}
```

ArkTS code:

```ts
import hilog from "@ohos.hilog"
// Import the native APIs.
import napitest from "libentry.so"
try {
  let script: string = `isDate(new Date(Date.now()))`;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM IsDate: %{public}s', napitest.runJsVm(script));
  script = `
      isDate(1)
  `;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM IsDate: %{public}s', napitest.runJsVm(script));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM IsDate error: %{public}s', error.message);
}
```
