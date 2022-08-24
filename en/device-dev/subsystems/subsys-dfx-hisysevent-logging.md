# HiSysEvent Logging

## Overview

### Function

HiSysEvent provides event logging APIs for OpenHarmony to record important information of key processes during system running. Besides, it supports shielding of event logging by event domain, helping you to evaluate the impact of event logging.

### Working Principles

Before logging system events, you need to complete HiSysEvent logging configuration. For details, see [HiSysEvent Logging Configuration](subsys-dfx-hisysevent-logging-config.md).

## How to Develop

### Use Cases

Use HiSysEvent logging to flush logged event data to disks.

### Available APIs

#### C++ Event Logging APIs

HiSysEvent logging is implemented using the API provided by the **HiSysEvent** class. For details, see the API Reference.

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> 
> In OpenHarmony-3.2-Beta3, HiSysEvent logging is open for restricted use to avoid event storms. The **HiSysEvent::Write** API in Table 1 is replaced by the **HiSysEventWrite** API in Table 2. The **HiSysEvent::Write** API has been deprecated. Use the **HiSysEventWrite** API instead for HiSysEvent logging.

**Table 1** C++ event logging API (deprecated)

| API                                                      | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| template&lt;typename... Types&gt; <br>static int Write(const std::string &amp;domain, const std::string &amp;eventName, EventType type, Types... keyValues) | Flushes logged event data to disks.|

**Table 2** C++ event logging API (in use)
| API                                                      | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| HiSysEventWrite(domain, eventName, type, ...)                | Flushes logged event data to disks.|

 **Table 3** Event types

| API   | Description        |
| --------- | ------------ |
| FAULT     | Fault event|
| STATISTIC | Statistical event|
| SECURITY  | Security event|
| BEHAVIOR  | Behavior event|

#### Kernel Event Logging APIs

The following table describes the kernel event logging APIs.

**Table 4** Kernel event logging APIs

| API                                                      | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| struct hiview_hisysevent *hisysevent_create(const char *domain, const char *name, enum hisysevent_type type); | Creates a **hisysevent** object.                    |
| void hisysevent_destroy(struct hiview_hisysevent *event);    | Destroys a **hisysevent** object.                    |
| int hisysevent_put_integer(struct hiview_hisysevent *event, const char *key, long long value); | Adds event parameters of the integer type to a **hisysevent** object.  |
| int hisysevent_put_string(struct hiview_hisysevent *event, const char *key, const char *value); | Adds event parameters of the string type to a **hisysevent** object.|
| int hisysevent_write(struct hiview_hisysevent *event);       | Flushes **hisysevent** object data to disks.              |

**Table 5** Kernel event types

| API   | Description        |
| --------- | ------------ |
| FAULT     | Fault event|
| STATISTIC | Statistical event|
| SECURITY  | Security event|
| BEHAVIOR  | Behavior event|

### How to Develop

#### C++ Event Logging

1. Call the event logging API wherever needed, with required event parameters passed to the API.

   ```c++
   HiSysEventWrite(HiSysEvent::Domain::AAFWK, "START_APP", HiSysEvent::EventType::BEHAVIOR, "APP_NAME", "com.ohos.demo");
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
   external_deps = [ "hisysevent_native:libhisysevent" ]
   ```

2. In the application startup function **StartAbility()** of the service module, call the event logging API with the event parameters passed in.

   ```c++
   #include "hisysevent.h"

   int StartAbility()
   {
       ... // Other service logic
       int ret = HiSysEventWrite(HiSysEvent::Domain::AAFWK, "START_APP", HiSysEvent::EventType::BEHAVIOR, "APP_NAME", "com.ohos.demo");
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
