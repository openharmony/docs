# Managing Date Using JSVM-API

## Overview

JSVM-API provides APIs for processing JavaScript (JS) **Date** objects in C/C++. These APIs are useful for working with time- and date-related logic in the JSVM module.

## Basic Concepts

In JSVM-API, the JS **Date** object provides a way to represent and manage date and time in JS. With the **Date** object, you can create an object that represents a specific time, perform date- and time-related calculations (such as adding or subtracting time intervals), and format date as a string for display. The value of a JS **Date** object is the number of milliseconds elapsed since the Unix epoch (00:00:00 UTC on January 1, 1970).

With the functions for interacting with the **Date** object, the JSVM module can be closely integrated with the JS environment to perform more complex date- and time-related operations.

## Available APIs

| API                      | Description                      |
|----------------------------|--------------------------------|
| OH_JSVM_CreateDate           | Creates a **Date** object representing the given number of milliseconds. |
| OH_JSVM_GetDateValue        | Obtains the C double primitive of the time value for the given JS **Date** object. |
| OH_JSVM_IsDate               | Checks whether a JS object is a date.|

## Example

### OH_JSVM_CreateDate

Create a **Date** object representing the given number of milliseconds.

CPP code

```cpp
// Register a callback for CreateDate.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = CreateDate},
};
static JSVM_CallbackStruct *method = param;
// Expose the alias of the CreateDate method to TS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"createDate", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Create a Date object.
static JSVM_Value CreateDate(JSVM_Env env, JSVM_CallbackInfo info) {
    g_data_type = "date";
    double value = 1501924876711;
    // Call OH_JSVM_CreateDate to convert the double value into a JS value indicating the date and time.
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateDate(env, value, &returnValue);
    return returnValue;
}
```

ArkTS code

```ts
let script: string = `createDate()`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM CreateDate: %{public}s',  JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM CreateDate error: %{public}s', error.message);
}
```

### OH_JSVM_GetDateValue

Obtain the C double primitive of the time value for the given JS **Date** object.

CPP code

```cpp
// Register a callback for GetDateValue.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = GetDateValue},
};
static JSVM_CallbackStruct *method = param;
// Expose the alias of the GetDateValue method to TS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"getDateValue", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call GetDateValue to obtain the C double primitive of the time value.
static JSVM_Value GetDateValue(JSVM_Env env, JSVM_CallbackInfo info) {
    g_data_type = "double";
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);
    // Obtain the Unix timestamp passed in.
    double value;
    JSVM_Status status = OH_JSVM_GetDateValue(env, args[0], &value);
    if (status != JSVM_OK) {
        OH_JSVM_ThrowError(env, nullptr, "OH_JSVM_GetDateValue fail");
        return nullptr;
    }
    // Print the obtained Unix timestamp.
    OH_LOG_INFO(LOG_APP, "JSVM gets the incoming Green time:%{public}lf.", value);
    JSVM_Value returnValue = nullptr;
    OH_JSVM_CreateDouble(env, value, &returnValue);
    return returnValue;
}
```

ArkTS code

```ts
let script: string = `getDateValue(new Date(Date.now()))`;
try {
  let result = napitest.runJsVm(script);
  hilog.info(0x0000, 'testJSVM', 'Test JSVM GetDateValue: %{public}s',  JSON.stringify(result));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM GetDateValue error: %{public}s', error.message);
}
```

### OH_JSVM_IsDate

Check whether a JS object is a date.

CPP code

```cpp
// Register a callback for IsDate.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = IsDate},
};
static JSVM_CallbackStruct *method = param;
// Expose the alias of the IsDate method to TS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"isDate", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
// Call IsDate to check whether the JS object indicates a date.
static JSVM_Value IsDate(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);

    bool result;
    OH_JSVM_IsDate(env, args[0], &result);

    JSVM_Value isDate = nullptr;
    OH_JSVM_GetBoolean(env, result, &isDate);
    return isDate;
}
```

ArkTS code

```ts
try {
  let script: string = `isDate(new Date(Date.now()))`;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM IsDate: %{public}s',  JSON.stringify(napitest.runJsVm(script)));
  script = `
      isDate(1)
  `;
  hilog.info(0x0000, 'testJSVM', 'Test JSVM IsDate: %{public}s', JSON.stringify(napitest.runJsVm(script)));
} catch (error) {
  hilog.error(0x0000, 'testJSVM', 'Test JSVM IsDate error: %{public}s', error.message);
}
```
