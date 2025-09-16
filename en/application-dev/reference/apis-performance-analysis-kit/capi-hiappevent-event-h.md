# hiappevent_event.h

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--SE: @junjie_shi-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Defines the names of all predefined events. In addition to custom events associated with specific applications, you can use predefined events for logging.
**File to include**: <hiappevent/hiappevent_event.h>

**Library**: libhiappevent_ndk.z.so

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Since**: 8

**Related Module**: [HiAppEvent](capi-hiappevent.md)

## Summary

### Macros

| Name                                                                                                        | Description                           |
|------------------------------------------------------------------------------------------------------------|-------------------------------|
| [EVENT_USER_LOGIN](#event_user_login) "hiappevent.user_login"                                              | User login event.<br>**Since**: 8       |
| [EVENT_USER_LOGOUT](#event_user_logout) "hiappevent.user_logout"                                           | User logout event.<br>**Since**: 8       |
| [EVENT_DISTRIBUTED_SERVICE_START](#event_distributed_service_start) "hiappevent.distributed_service_start" | Distributed service event.<br>**Since**: 8      |
| [EVENT_APP_CRASH](#event_app_crash) "APP_CRASH"                                                            | Application crash event.<br>**Since**: 12      |
| [EVENT_APP_FREEZE](#event_app_freeze) "APP_FREEZE"                                                         | Application freeze event.<br>**Since**: 12      |
| [EVENT_APP_LAUNCH](#event_app_launch) "APP_LAUNCH"                                                         | Application loading event.<br>**Since**: 12      |
| [EVENT_SCROLL_JANK](#event_scroll_jank) "SCROLL_JANK"                                                      | Application scrolling jank event.<br>**Since**: 12    |
| [EVENT_CPU_USAGE_HIGH](#event_cpu_usage_high) "CPU_USAGE_HIGH"                                             | High application CPU usage event.<br>**Since**: 12|
| [EVENT_BATTERY_USAGE](#event_battery_usage) "BATTERY_USAGE"                                                | Application power usage event.<br>**Since**: 12   |
| [EVENT_RESOURCE_OVERLIMIT](#event_resource_overlimit) "RESOURCE_OVERLIMIT"                                 | Application resource threshold-crossing event.<br>**Since**: 12    |
| [EVENT_ADDRESS_SANITIZER](#event_address_sanitizer) "ADDRESS_SANITIZER"                                    | Address sanitizer event.<br>**Since**: 12     |
| [EVENT_MAIN_THREAD_JANK](#event_main_thread_jank) "MAIN_THREAD_JANK"                                       | Main thread jank event.<br>**Since**: 12   |
| [EVENT_APP_HICOLLIE](#event_app_hicollie) "APP_HICOLLIE"                                                   | Task execution timeout event.<br>**Since**: 18  |
| [DOMAIN_OS](#domain_os) "OS"                                                                               | OS scope.<br>**Since**: 12       |

## Macro Description

### EVENT_USER_LOGIN

```
#define EVENT_USER_LOGIN "hiappevent.user_login"
```

**Description**

User login event.

**Since**: 8

### EVENT_USER_LOGOUT

```
#define EVENT_USER_LOGOUT "hiappevent.user_logout"
```

**Description**

User logout event.

**Since**: 8

### EVENT_DISTRIBUTED_SERVICE_START

```
#define EVENT_DISTRIBUTED_SERVICE_START "hiappevent.distributed_service_start"
```

**Description**

Distributed service event.

**Since**: 8

### EVENT_APP_CRASH

```
#define EVENT_APP_CRASH "APP_CRASH"
```

**Description**

Application crash event.

**Since**: 12

### EVENT_APP_FREEZE

```
#define EVENT_APP_FREEZE "APP_FREEZE"
```

**Description**

Application freeze event.

**Since**: 12

### EVENT_APP_LAUNCH

```
#define EVENT_APP_LAUNCH "APP_LAUNCH"
```

**Description**

Application loading event.

**Since**: 12

### EVENT_SCROLL_JANK

```
#define EVENT_SCROLL_JANK "SCROLL_JANK"
```

**Description**

Application scrolling jank event.

**Since**: 12

### EVENT_CPU_USAGE_HIGH

```
#define EVENT_CPU_USAGE_HIGH "CPU_USAGE_HIGH"
```

**Description**

High application CPU usage event.

**Since**: 12

### EVENT_BATTERY_USAGE

```
#define EVENT_BATTERY_USAGE "BATTERY_USAGE"
```

**Description**

Application power usage event.

**Since**: 12

### EVENT_RESOURCE_OVERLIMIT

```
#define EVENT_RESOURCE_OVERLIMIT "RESOURCE_OVERLIMIT"
```

**Description**

Application resource threshold-crossing event.

**Since**: 12

### EVENT_ADDRESS_SANITIZER

```
#define EVENT_ADDRESS_SANITIZER "ADDRESS_SANITIZER"
```

**Description**

Address sanitizer event.

**Since**: 12

### EVENT_MAIN_THREAD_JANK

```
#define EVENT_MAIN_THREAD_JANK "MAIN_THREAD_JANK"
```

**Description**

Main thread jank event.

**Since**: 12

### EVENT_APP_HICOLLIE

```
#define EVENT_APP_HICOLLIE "APP_HICOLLIE"
```

**Description**

Task execution timeout event.

**Since**: 18

### DOMAIN_OS

```
#define DOMAIN_OS "OS"
```

**Description**

OS scope.

**Since**: 12
