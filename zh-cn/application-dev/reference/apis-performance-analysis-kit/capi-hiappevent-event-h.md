# hiappevent_event.h

## 概述

定义所有预定义事件的事件名称。除了与特定应用关联的自定义事件之外，开发者还可以使用预定义事件进行打点。示例代码:<br>\<pre>ParamList list = OH_HiAppEvent_CreateParamList();<br>OH_HiAppEvent_AddInt32Param(list, PARAM_USER_ID, 123);<br>int res = OH_HiAppEvent_Write("user_domain", EVENT_USER_LOGIN, BEHAVIOR, list);<br>OH_HiAppEvent_DestroyParamList(list);\</pre>

**引用文件：** &lt;hiappevent/hiappevent_event.h&gt;

**库：** libhiappevent_ndk.z.so

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 8

**相关模块：** [HiAppEvent](capi-hiappevent.md)

## 汇总

### 宏定义

| 名称                                                                                                         | 描述                            |
|------------------------------------------------------------------------------------------------------------|-------------------------------|
| [EVENT_USER_LOGIN](#event_user_login) "hiappevent.user_login"                                              | 用户登录事件。<br>**起始版本：** 8        |
| [EVENT_USER_LOGOUT](#event_user_logout) "hiappevent.user_logout"                                           | 用户登出事件。<br>**起始版本：** 8        |
| [EVENT_DISTRIBUTED_SERVICE_START](#event_distributed_service_start) "hiappevent.distributed_service_start" | 分布式服务事件。<br>**起始版本：** 8       |
| [EVENT_APP_CRASH](#event_app_crash) "APP_CRASH"                                                            | 应用崩溃事件。<br>**起始版本：** 12       |
| [EVENT_APP_FREEZE](#event_app_freeze) "APP_FREEZE"                                                         | 应用卡顿事件。<br>**起始版本：** 12       |
| [EVENT_APP_LAUNCH](#event_app_launch) "APP_LAUNCH"                                                         | 应用加载事件。<br>**起始版本：** 12       |
| [EVENT_SCROLL_JANK](#event_scroll_jank) "SCROLL_JANK"                                                      | 应用滑动卡顿事件。<br>**起始版本：** 12     |
| [EVENT_CPU_USAGE_HIGH](#event_cpu_usage_high) "CPU_USAGE_HIGH"                                             | 应用CPU资源占用高事件。<br>**起始版本：** 12 |
| [EVENT_BATTERY_USAGE](#event_battery_usage) "BATTERY_USAGE"                                                | 应用电源使用率事件。<br>**起始版本：** 12    |
| [EVENT_RESOURCE_OVERLIMIT](#event_resource_overlimit) "RESOURCE_OVERLIMIT"                                 | 应用资源超限事件。<br>**起始版本：** 12     |
| [EVENT_ADDRESS_SANITIZER](#event_address_sanitizer) "ADDRESS_SANITIZER"                                    | 应用踩内存事件。<br>**起始版本：** 12      |
| [EVENT_MAIN_THREAD_JANK](#event_main_thread_jank) "MAIN_THREAD_JANK"                                       | 应用主线程超时事件。<br>**起始版本：** 12    |
| [EVENT_APP_HICOLLIE](#event_app_hicollie) "APP_HICOLLIE"                                                   | 应用任务执行超时事件。<br>**起始版本：** 18   |
| [DOMAIN_OS](#domain_os) "OS"                                                                               | OS作用域。<br>**起始版本：** 12        |

## 宏定义说明

### EVENT_USER_LOGIN

```
#define EVENT_USER_LOGIN "hiappevent.user_login"
```

**描述**

用户登录事件。

**起始版本：** 8

### EVENT_USER_LOGOUT

```
#define EVENT_USER_LOGOUT "hiappevent.user_logout"
```

**描述**

用户登出事件。

**起始版本：** 8

### EVENT_DISTRIBUTED_SERVICE_START

```
#define EVENT_DISTRIBUTED_SERVICE_START "hiappevent.distributed_service_start"
```

**描述**

分布式服务事件。

**起始版本：** 8

### EVENT_APP_CRASH

```
#define EVENT_APP_CRASH "APP_CRASH"
```

**描述**

应用崩溃事件。

**起始版本：** 12

### EVENT_APP_FREEZE

```
#define EVENT_APP_FREEZE "APP_FREEZE"
```

**描述**

应用卡顿事件。

**起始版本：** 12

### EVENT_APP_LAUNCH

```
#define EVENT_APP_LAUNCH "APP_LAUNCH"
```

**描述**

应用加载事件。

**起始版本：** 12

### EVENT_SCROLL_JANK

```
#define EVENT_SCROLL_JANK "SCROLL_JANK"
```

**描述**

应用滑动卡顿事件。

**起始版本：** 12

### EVENT_CPU_USAGE_HIGH

```
#define EVENT_CPU_USAGE_HIGH "CPU_USAGE_HIGH"
```

**描述**

应用CPU资源占用高事件。

**起始版本：** 12

### EVENT_BATTERY_USAGE

```
#define EVENT_BATTERY_USAGE "BATTERY_USAGE"
```

**描述**

应用电源使用率事件。

**起始版本：** 12

### EVENT_RESOURCE_OVERLIMIT

```
#define EVENT_RESOURCE_OVERLIMIT "RESOURCE_OVERLIMIT"
```

**描述**

应用资源超限事件。

**起始版本：** 12

### EVENT_ADDRESS_SANITIZER

```
#define EVENT_ADDRESS_SANITIZER "ADDRESS_SANITIZER"
```

**描述**

应用踩内存事件

**起始版本：** 12

### EVENT_MAIN_THREAD_JANK

```
#define EVENT_MAIN_THREAD_JANK "MAIN_THREAD_JANK"
```

**描述**

应用主线程超时事件。

**起始版本：** 12

### EVENT_APP_HICOLLIE

```
#define EVENT_APP_HICOLLIE "APP_HICOLLIE"
```

**描述**

应用任务执行超时事件。

**起始版本：** 18

### DOMAIN_OS

```
#define DOMAIN_OS "OS"
```

**描述**

OS作用域。

**起始版本：** 12



