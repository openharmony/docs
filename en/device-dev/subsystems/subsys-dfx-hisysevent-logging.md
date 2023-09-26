# HiSysEvent Logging

## Overview

### Function Introduction

HiSysEvent provides event logging APIs for OpenHarmony to record important information of key processes during system running. Besides, it supports shielding of event logging by event domain, helping you to evaluate the impact of event logging.

### Working Principles

Before logging system events, you need to configure HiSysEvent logging. For details, see [HiSysEvent Logging Configuration](subsys-dfx-hisysevent-logging-config.md).

## How to Develop

### Use Cases

Use HiSysEvent logging to flush logged event data to the event file.

### Available APIs

#### C++ Event Logging API

HiSysEvent logging is implemented using the API provided by the **HiSysEvent** class. For details, see the [API Header Files](/base/hiviewdfx/hisysevent/interfaces/native/innerkits/hisysevent/include/).

> **NOTE**
> 
> In OpenHarmony-3.2-Beta3, HiSysEvent logging is open for restricted use to avoid event storms. The **HiSysEvent::Write** API in Table 1 is replaced by the **HiSysEventWrite** API in Table 2. The **HiSysEvent::Write** API has been deprecated. Use the **HiSysEventWrite** API instead for HiSysEvent logging.

**Table 1** Description of the C++ event logging API (deprecated)

| API                                                      | Description                  |
| ------------------------------------------------------------ | --------------------- |
| template&lt;typename...&nbsp;Types&gt;&nbsp;<br>static&nbsp;int&nbsp;Write(const&nbsp;std::string&nbsp;&amp;domain,&nbsp;const&nbsp;std::string&nbsp;&amp;eventName,&nbsp;EventType&nbsp;type,&nbsp;Types...&nbsp;keyValues) | Flushes logged event data to the event file.|

**Table 2** Description of the C++ event logging API (in use)

| API                                                      | Description                  |
| ------------------------------------------------------------ | --------------------- |
| HiSysEventWrite(domain, eventName, type, ...)                | Flushes logged event data to the event file.|

  **Table 3** Description of EventType enums

| Event Type  | Description       |
| --------- | ----------- |
| FAULT     | Fault event.|
| STATISTIC | Statistical event.|
| SECURITY  | Security event.|
| BEHAVIOR  | Behavior event.|

#### C Event Logging API

HiSysEvent logging is implemented using the API provided in the following table. For details, see the [API Header Files](/base/hiviewdfx/hisysevent/interfaces/native/innerkits/hisysevent/include/).

**Table 4** Description of the C event logging API

| API                                                      | Description                    |
| ------------------------------------------------------------ | ------------------------ |
| int OH_HiSysEvent_Write(const char\* domain, const char\* name, HiSysEventEventType type, HiSysEventParam params[], size_t size); | Flushes logged event data to the event file.|

**Table 5** Description of HiSysEventEventType enums

| Event Type            | Description          |
| -------------------- | -------------- |
| HISYSEVENT_FAULT     | Fault event.|
| HISYSEVENT_STATISTIC | Statistical event.|
| HISYSEVENT_SECURITY  | Security event.|
| HISYSEVENT_BEHAVIOR  | Behavior event.|

**Table 6** Description of the HiSysEventParam structure

| Attribute | Type            | Description                              |
| --------- | -------------------- | ---------------------------------- |
| name      | char name[]          | Event parameter name.                    |
| t         | HiSysEventParamType  | Event parameter type.                    |
| v         | HiSysEventParamValue | Event parameter value.                      |
| arraySize | size_t               | Array length when the event parameter value is of the array type.|

**Table 7** Description of HiSysEventParamType enums

| Type               | Description                      |
| ----------------------- | -------------------------- |
| HISYSEVENT_INVALID      | Invalid event parameter.        |
| HISYSEVENT_BOOL         | Event parameter of the bool type.        |
| HISYSEVENT_INT8         | Event parameter of the int8_t type.      |
| HISYSEVENT_UINT8        | Event parameter of the uint8_t type.     |
| HISYSEVENT_INT16        | Event parameter of the int16_t type.     |
| HISYSEVENT_UINT16       | Event parameter of the uint16_t type.    |
| HISYSEVENT_INT32        | Event parameter of the int32_t type.     |
| HISYSEVENT_UINT32       | Event parameter of the uint32_t type.    |
| HISYSEVENT_INT64        | Event parameter of the int64_t type.     |
| HISYSEVENT_UINT64       | Event parameter of the uint64_t type.    |
| HISYSEVENT_FLOAT        | Event parameter of the float type.       |
| HISYSEVENT_DOUBLE       | Event parameter of the double type.      |
| HISYSEVENT_STRING       | Event parameter of the char* type.       |
| HISYSEVENT_BOOL_ARRAY   | Event parameter of the bool array type.    |
| HISYSEVENT_INT8_ARRAY   | Event parameter of the int8_t array type.  |
| HISYSEVENT_UINT8_ARRAY  | Event parameter of the uint8_t array type. |
| HISYSEVENT_INT16_ARRAY  | Event parameter of the int16_t array type. |
| HISYSEVENT_UINT16_ARRAY | Event parameter of the uint16_t array type.|
| HISYSEVENT_INT32_ARRAY  | Event parameter of the int32_t array type. |
| HISYSEVENT_UINT32_ARRAY | Event parameter of the uint32_t array type.|
| HISYSEVENT_INT64_ARRAY  | Event parameter of the int64_t array type. |
| HISYSEVENT_UINT64_ARRAY | Event parameter of the uint64_t array type.|
| HISYSEVENT_FLOAT_ARRAY  | Event parameter of the float array type.   |
| HISYSEVENT_DOUBLE_ARRAY | Event parameter of the double array type.  |
| HISYSEVENT_STRING_ARRAY | Event parameter of the char* array type.   |

**Table 8** Description of the HiSysEventParamValue union

| Attribute| Type| Description                    |
| -------- | -------- | ------------------------ |
| b        | bool     | Event parameter value of the bool type.    |
| i8       | int8_t   | Event parameter value of the int8_t type.  |
| ui8      | uint8_t  | Event parameter value of the uint8_t type. |
| i16      | int16_t  | Event parameter value of the int16_t type. |
| ui16     | uint16_t | Event parameter value of the uint16_t type.|
| i32      | int32_t  | Event parameter value of the int32_t type. |
| ui32     | uint32_t | Event parameter value of the uint32_t type.|
| i64      | int64_t  | Event parameter value of the int64_t type. |
| ui64     | uint64_t | Event parameter value of the uint64_t type.|
| f        | float    | Event parameter value of the float type.   |
| d        | double   | Event parameter value of the double type.  |
| s        | char*    | Event parameter value of the char* type.   |
| array    | void*    | Event parameter value of the array type.    |

#### Kernel Event Logging APIs

Kernel event logging is implemented using the APIs provided in the following table. For details, see the [API Header File](/kernel/linux/linux-5.10/include/dfx/hiview_hisysevent.h).

**Table 9** Description of kernel event logging APIs

| API                                                      | Description                                |
| ------------------------------------------------------------ | ----------------------------------- |
| struct hiview_hisysevent *hisysevent_create(const char *domain, const char *name, enum hisysevent_type type); | Creates a **hisysevent** object.   |
| void hisysevent_destroy(struct hiview_hisysevent *event);    | Destroys a **hisysevent** object.                                                    |
| int hisysevent_put_integer(struct hiview_hisysevent *event, const char *key, long long value); | Adds event parameters of the integer type to a **hisysevent** object.  |
| int hisysevent_put_string(struct hiview_hisysevent *event, const char *key, const char *value); | Adds event parameters of the string type to a **hisysevent** object.|
| int hisysevent_write(struct hiview_hisysevent *event);       | Flushes **hisysevent** object data to the event file.                                               |

**Table 10** Description of hisysevent_type enums

| Event Type  | Description       |
| --------- | ----------- |
| FAULT     | Fault event.|
| STATISTIC | Statistical event.|
| SECURITY  | Security event.|
| BEHAVIOR  | Behavior event.|

### How to Develop

#### C++ Event Logging

Call the event logging API wherever needed, with required event parameters passed to the API.

   ```c++
   HiSysEventWrite(HiSysEvent::Domain::AAFWK, "START_APP", HiSysEvent::EventType::BEHAVIOR, "APP_NAME", "com.ohos.demo");
   ```

#### C Event Logging

1. If you want to pass custom event parameters to the event logging API, create an event parameter object based on the event parameter type and add the object to the event parameter array.

   ```c
   // Create an event parameter of the int32_t type.
   HiSysEventParam param1 = {
       .name = "KEY_INT32",
       .t = HISYSEVENT_INT32,
       .v = { .i32 = 1 },
       .arraySize = 0,
   };

   // Create an event parameter of the int32_t array type.
   int32_t int32Arr[] = { 1, 2, 3 };
   HiSysEventParam param2 = {
       .name = "KEY_INT32_ARR",
       .t = HISYSEVENT_INT32_ARRAY,
       .v = { .array = int32Arr },
       .arraySize = sizeof(int32Arr) / sizeof(int32Arr[0]),
   };

   // Add the event parameter object to the created event parameter array.
   HiSysEventParam params[] = { param1, param2 };
   ```

2. Call the event logging API wherever needed, with required event parameters passed to the API.

   ```c
   OH_HiSysEvent_Write("TEST_DOMAIN", "TEST_NAME", HISYSEVENT_BEHAVIOR, params, sizeof(params) / sizeof(params[0]));
   ```

#### Kernel Event Logging

1. Create a **hisysevent** object based on the specified event domain, event name, and event type.

   ```c
   struct hiview_hisysevent *event = hisysevent_create("KERNEL", "BOOT", BEHAVIOR);
   ```

2. Pass the customized event parameters to the **hisysevent** object.

   ```c
   // Add a parameter of the integer type.
   hisysevent_put_integer(event, "BOOT_TIME", 100);

   // Add a parameter of the string type.
   hisysevent_put_string(event, "MSG", "This is a test message");
   ```

3. Trigger reporting of the **hisysevent** event.

   ```c
   hisysevent_write(event);
   ```

4. Manually destroy the **hisysevent** object.

   ```c
   hisysevent_destroy(&event);
   ```

#### Shielding of Event Logging by Event Domain

1. In the corresponding file, define the **DOMAIN_MASKS** macro with content similar to DOMAIN_NAME_1|DOMAIN_NAME_2|...|DOMAIN_NAME_n. There are three scenarios:

- Shielding only event logging for the event domains configured in the current source code file: Define the **DOMAIN_MASKS** macro before importing the **.cpp** file to the **hisysevent.h** file.
   ```c++
   #define DOMAIN_MASKS "DOMAIN_NAME_1|DOMAIN_NAME_2|...|DOMAIN_NAME_n"
   #include "hisysevent.h"
   ```

- Shielding event logging for event domains of the entire module: Define the **DOMAIN_MASKS** macro in the **BUILD.gn** file of the module.
   ```gn
   config("module_a"){
     cflags_cc += ["-DDOMAIN_MASKS=\"DOMAIN_NAME_1|DOMAIN_NAME_2|...|DOMAIN_NAME_n\""]
   }
   ```

- Shielding event logging for event domains globally: Define the **DOMAIN_MASKS** macro in **/build/config/compiler/BUILD.gn**.
   ```gn
     cflags_cc += ["-DDOMAIN_MASKS=\"DOMAIN_NAME_1|DOMAIN_NAME_2|...|DOMAIN_NAME_n\""]
   ```

2. Perform event logging by using the **HiSysEventWrite** API.
   ```c++
   constexpr char DOMAIN[] = "DOMAIN_NAME_1";
   const std::string eventName = "EVENT_NAME1";
   OHOS:HiviewDFX::HiSysEvent::EventType eventType = OHOS:HiviewDFX::HiSysEvent::EventType::FAULT;
   HiSysEventWrite(domain, eventName, eventType); // Event logging is shielded for DOMAIN_NAME_1 because it has been defined in the DOMAIN_MASKS macro.
   ```

### Development Example

#### C++ Event Logging

Assume that a service module needs to trigger event logging during application startup to record the application startup event and application bundle name. The following is the complete sample code:

1. Add the HiSysEvent component dependency to the **BUILD.gn** file of the service module.

   ```c++
   external_deps = [ "hisysevent:libhisysevent" ]
   ```

2. In the application startup function **StartAbility()** of the service module, call the event logging API with event parameters passed in.

   ```c++
   #include "hisysevent.h"

   int StartAbility()
   {
       ... // Other service logic
       int ret = HiSysEventWrite(HiSysEvent::Domain::AAFWK, "START_APP", HiSysEvent::EventType::BEHAVIOR, "APP_NAME", "com.ohos.demo");
       ... // Other service logic
   }
   ```

#### C Event Logging

Assume that a service module needs to trigger event logging during application startup to record the application startup event and application bundle name. The following is the complete sample code:

1. Add the HiSysEvent component dependency to the **BUILD.gn** file of the service module.

   ```c++
   external_deps = [ "hisysevent:libhisysevent" ]
   ```

2. In the application startup function **StartAbility()** of the service module, call the event logging API with event parameters passed in.

   ```c
   #include "hisysevent_c.h"

   int StartAbility()
   {
       ... // Other service logic
       char packageName[] = "com.ohos.demo";
       HiSysEventParam param = {
           .name = "APP_NAME",
           .t = HISYSEVENT_STRING,
           .v = { .s = packageName },
           .arraySize = 0,
       };
       HiSysEventParam params[] = { param };
       int ret = OH_HiSysEvent_Write("AAFWK", "START_APP", HISYSEVENT_BEHAVIOR, params, sizeof(params) / sizeof(params[0]));
       ... // Other service logic
   }
   ```

#### Kernel Event Logging

Assume that the kernel service module needs to trigger event logging during device startup to record the device startup event. The following is the complete sample code:

1. In the device startup function **device_boot()**, construct a **hisysevent** object. After that, trigger event reporting, and then destroy the **hisysevent** object.

    ```c
    #include <dfx/hiview_hisysevent.h>

    #include <linux/errno.h>
    #include <linux/printk.h>

    int device_boot()
    {
        ... // Other service logic
        struct hiview_hisysevent *event = NULL;
        int ret = 0;

        event = hisysevent_create("KERNEL", "BOOT", BEHAVIOR);
        if (!event) {
            pr_err("failed to create event");
            return -EINVAL;
        }
        ret = hisysevent_put_string(event, "MSG", "This is a test message");
        if (ret != 0) {
            pr_err("failed to put sting to event, ret=%d", ret);
            goto hisysevent_end;
        }
        ret = hisysevent_write(event);

    hisysevent_end:
        hisysevent_destroy(&event);
        ... // Other service logic
    }
    ```

#### Shielding of Event Logging by Event Domain

- If you want to shield event logging for the **AAFWK** and **POWER** domains in a **.cpp** file, define the **DOMAIN_MASKS** macro before including the **hisysevent.h** header file to the **.cpp** file.
    ```c++
    #define DOMAIN_MASKS "AAFWK|POWER"

    #include "hisysevent.h"
    ... // Other service logic
    HiSysEventWrite(OHOS:HiviewDFX::HiSysEvent::Domain::AAFWK, "JS_ERROR", OHOS:HiviewDFX::HiSysEvent::EventType::FAULT, "MODULE", "com.ohos.module"); // HiSysEvent logging is not performed.
    ... // Other service logic
    HiSysEventWrite(OHOS:HiviewDFX::HiSysEvent::Domain::POWER, "POWER_RUNNINGLOCK", OHOS:HiviewDFX::HiSysEvent::EventType::FAULT, "NAME", "com.ohos.module"); // HiSysEvent logging is not performed.
    ```

- If you want to shield event logging for the **AAFWK** and **POWER** domains of the entire service module, define the **DOMAIN_MASKS** macro as follows in the **BUILG.gn** file of the service module.
    ```gn
    config("module_a") {
        ... // Other configuration items
        cflags_cc += ["-DDOMAIN_MASKS=\"AAFWK|POWER\""]
    }
    ```

- If you want to shield event logging for the **AAFWK** and **POWER** domains globally, define the **DOMAIN_MASKS** macro as follows in **/build/config/compiler/BUILD.gn**.
    ```gn
    ... // Other configuration items
    cflags_cc += ["-DDOMAIN_MASKS=\"AAFWK|POWER\""]
    ```

# Reference

The HiSysEvent module writes the logged event data to the node file, and the Hiview module parses and processes the event data in a unified manner. For details, see the [Hiview Development Guide](subsys-dfx-hiview.md).
