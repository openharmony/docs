# Working with Date Using JSVM-API
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Introduction

JSVM-API provides APIs for processing JavaScript (JS) **Date** objects in C/C++. These APIs are useful for working with time- and date-related logic in the JSVM module.

## Basic Concepts

In JSVM-API, the value of a JS **Date** object is the number of milliseconds elapsed since the Unix epoch (00:00:00 UTC on January 1, 1970).

The JavaScript Date object is used to represent and manipulate date and time in JavaScript. With the **Date** object, you can create an object that represents a specific time, perform date- and time-related calculations (such as adding or subtracting time intervals), and format date as a string for display.

With the functions for interacting with the **Date** object, the JSVM module can be closely integrated with the JS environment to perform more complex date- and time-related operations.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_CreateDate           | Use **OH_JSVM_IsTypedarray** to create a **Date** object representing the given number of milliseconds.|
| OH_JSVM_GetDateValue        | Obtains the C double primitive of the time value for the given JS **Date** object. |
| OH_JSVM_IsDate               | Checks whether a JS object is a date.|

## Example

If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in proxy-related APIs.

### OH_JSVM_CreateDate

Use **OH_JSVM_IsTypedarray** to create a **Date** object representing the given number of milliseconds.

CPP code:

```cpp
#include <time.h>
// Define OH_JSVM_CreateDate.
static JSVM_Value CreateDate(JSVM_Env env, JSVM_CallbackInfo info) {
    // Obtain the number of seconds elapsed since the Unix epoch using the C function and convert the value into milliseconds.
    double value = static_cast<double>(static_cast<uint64_t>(time(NULL)) * 1000ULL);
    // Call OH_JSVM_CreateDate to convert the double value into a JS value indicating the date and time.
    JSVM_Value returnValue = nullptr;

    JSVM_CALL(OH_JSVM_CreateDate(env, value, &returnValue));

    bool isDate = false;
    JSVM_CALL(OH_JSVM_IsDate(env, returnValue, &isDate));
    if (!isDate) {
        OH_LOG_ERROR(LOG_APP, "JSVM IsDate fail");
        return returnValue;
    }

    value = 0;
    JSVM_CALL(OH_JSVM_GetDateValue(env, returnValue, &value));

    uint64_t time = static_cast<uint64_t>(value) / 1000;
    char *date = ctime(reinterpret_cast<time_t *>(&time));
    OH_LOG_INFO(LOG_APP, "JSVM CreateDate success:%{public}s", date);

    return returnValue;
}

// Register the CreateDate callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateDate},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createDate and associate it with a callback. This allows the createDate callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createDate", nullptr, method, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char *srcCallNative = R"JS(createDate())JS";
```

Expected result:
```
JSVM CreateDate success:Mon Jul 7 10:42:34 2025
```

<!-- @[oh_jsvm_create_date](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutDate/createdate/src/main/cpp/hello.cpp) -->

### OH_JSVM_GetDateValue

Obtains the C double primitive of the time value for the given JS **Date** object.

CPP code:

```cpp
#include <ctime>
// Define OH_JSVM_GetDateValue.
static JSVM_Value GetDateValue(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
    // Obtain the Unix timestamp passed in.
    double value = 0;
    JSVM_CALL(OH_JSVM_GetDateValue(env, args[0], &value)); 
   
    // Convert the obtained Unix Time Stamp time into a date string for printing.
    uint64_t time = static_cast<uint64_t>(value) / 1000;
    char *date = ctime(reinterpret_cast<time_t *>(&time));
    OH_LOG_INFO(LOG_APP, "JSVM GetDateValue success:%{public}s", date);
   
    JSVM_Value returnValue = nullptr;
    JSVM_CALL(OH_JSVM_CreateDouble(env, value, &returnValue));
    return returnValue;
}

// Register the CreateDate callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetDateValue},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createDate and associate it with a callback. This allows the createDate callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getDateValue", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char *srcCallNative = R"JS(getDateValue(new Date(Date.now())))JS";
```

Expected result:
```
JSVM GetDateValue success:Mon Jul 7 10:47:08 2025
```

<!-- @[oh_jsvm_get_date_value](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutDate/getdatevalue/src/main/cpp/hello.cpp) -->

### OH_JSVM_IsDate

Checks whether a JS object is a date.

CPP code:

```cpp
// Define OH_JSVM_IsDate.
static JSVM_Value IsDate(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr));
    bool isData = false;
    JSVM_CALL(OH_JSVM_IsDate(env, args[0], &isData));
    OH_LOG_INFO(LOG_APP, "JSVM IsDate success:%{public}d", isData);
    
    JSVM_Value result = nullptr;
    JSVM_CALL(OH_JSVM_GetBoolean(env, isData, &result));
    return result;
}
// Register the CreateDate callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsDate},
};
static JSVM_CallbackStruct *method = param;
// Set a property descriptor named createDate and associate it with a callback. This allows the createDate callback to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"isDate", nullptr, method, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call the C++ code from JS.
const char *srcCallNative = R"JS(isDate(new Date(Date.now())))JS";
```

Expected result:
```
JSVM IsDate success:1
```

<!-- @[oh_jsvm_is_date](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutDate/isdate/src/main/cpp/hello.cpp) -->
