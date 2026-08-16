# Working with Date Using Node-API

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:38:44.322Z pushedAt=2026-08-12T11:10:07.033Z -->

## Overview

Node-API provides APIs for processing ArkTS **Date** objects in C/C++. These APIs are useful for working with time- and date-related logic in the ArkTS module.

## Basic Concepts

In Node-API, the value of a ArkTS **Date** object is the number of milliseconds elapsed since the Unix epoch (00:00:00 UTC on January 1, 1970).

The ArkTS **Date** object provides a way to represent and manage date and time in ArkTS. With the **Date** object, you can create an object that represents a specific time, perform date- and time-related calculations (such as adding or subtracting time intervals), and format date as a string for display.

With the functions for interacting with the **Date** object, the JSVM module can be closely integrated with the ArkTS environment to perform more complex date- and time-related operations.

## Available APIs

The following table lists the APIs for manipulating ArkTS date in C/C++.  

| API| Description|
| -------- | -------- |
| napi_create_date | Creates an ArkTS **Date** object.|
| napi_get_date_value | Obtains the C equivalent of the given ArkTS **Date** object.|
| napi_is_date | Checks whether the given ArkTS value is a **Date** object. You can use this API to check the type of the parameter passed from ArkTS.|

## Example

If you are just starting out with Node-API, see [Node-API Development Process](use-napi-process.md). The following demonstrates only the C++ and ArkTS code related to promise development.

### napi_create_date

Use **napi_create_date** to create an ArkTS **Date** object from a C++ double value.

CPP code:

<!-- @[napi_create_date](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/cpp/napi_init.cpp) -->

``` C++
#include <hilog/log.h>
#include "napi/native_api.h"

// napi_create_date
static napi_value CreateDate(napi_env env, napi_callback_info info)
{
    // Obtain the incoming Unix time stamp.
    double value = 1501924876711;
    // Call napi_create_date to convert the double value into an ArkTS object representing a date and time, and place it in returnValue.
    napi_value returnValue = nullptr;
    napi_create_date(env, value, &returnValue);
    return returnValue;
}
```

API declaration:

<!-- @[napi_create_date_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/cpp/types/libentry/Index.d.ts) -->    

``` TypeScript
export const createDate: () => Date; // napi_create_date
```

ArkTS code:

 <!-- @[ark_napi_create_date](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/ets/pages/Index.ets) -->   

 ``` TypeScript
 // napi_create_date
 hilog.info(0x0000, 'testTag', 'Test Node-API napi_create_date: %{public}s',
   testNapi.createDate().toString());
 ```

### napi_get_date_value

Use **napi_get_date_value** to obtain the C++ double equivalent of the given ArkTS **Date** object.

CPP code:

<!-- @[napi_get_date_value](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_get_date_value
static napi_value GetDateValue(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // Obtain the incoming Unix time stamp.
    double value = 0;
    napi_status status = napi_get_date_value(env, args[0], &value);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "napi_get_date_value fail");
        return nullptr;
    }

    // Print the obtained Unix time stamp.
    OH_LOG_INFO(LOG_APP, "Node-API gets unix time stamp is:%{public}lf.", value);

    // Create an ArkTS double value from the converted Unix time stamp and place it in returnValue.
    napi_value returnValue = nullptr;
    napi_create_double(env, value, &returnValue);
    return returnValue;
}
```

API declaration:

<!-- @[napi_get_date_value_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/cpp/types/libentry/Index.d.ts) -->   

``` TypeScript
export const getDateValue: (date: Date) => number | undefined; // napi_get_date_value
```

ArkTS code:

<!-- @[ark_napi_get_date_value](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_get_date_value
try {
  const date = new Date();
  hilog.info(0x0000, 'testTag', 'Node-API: output the Unix Time Stamp: %{public}d', date.getTime());
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_get_date_value: %{public}d',
    testNapi.getDateValue(date));
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_get_date_value error: %{public}s',
    error.message);
  // ...
}
```

### napi_is_date

Use **napi_is_date** to check whether an ArkTS value is an ArkTS **Date** object.

CPP code:

<!-- @[napi_is_date](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// napi_is_date
static napi_value IsDate(napi_env env, napi_callback_info info)
{
    // Accept one input parameter.
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    // Call napi_is_date to check whether the given input parameter is Date data.
    bool result = false;
    napi_status status = napi_is_date(env, args[0], &result);
    if (status != napi_ok) {
        napi_throw_error(env, nullptr, "Node-API napi_is_date fail");
        return nullptr;
    }
    // Convert the result to the napi_value type and return it.
    napi_value returnValue = nullptr;
    napi_get_boolean(env, result, &returnValue);

    return returnValue;
}
```

API declaration:

<!-- @[napi_is_date_api](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/cpp/types/libentry/Index.d.ts) -->    

``` TypeScript
export const isDate: <T>(date: T) => boolean | undefined; // napi_is_date
```

ArkTS code:

<!-- @[ark_napi_is_date](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/NodeAPI/NodeAPIUse/NodeAPIDate/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// napi_is_date
try {
  let now: Date = new Date();
  let date = "123";
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_date: %{public}s', testNapi.isDate(now));
  hilog.info(0x0000, 'testTag', 'Test Node-API napi_is_date: %{public}s', testNapi.isDate(date));
  // ...
} catch (error) {
  hilog.error(0x0000, 'testTag', 'Test Node-API napi_is_date error: %{public}s', error.message);
  // ...
}
```

To print logs in the native CPP, add the following information to the **CMakeLists.txt** file and add the header file by using **#include "hilog/log.h"**.

```text
// CMakeLists.txt
add_definitions( "-DLOG_DOMAIN=0xd0d0" )
add_definitions( "-DLOG_TAG=\"testTag\"" )
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)
```