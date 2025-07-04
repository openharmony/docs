# hiappevent_event.h


## 概述

定义所有预定义事件的事件名称。

除了与特定应用关联的自定义事件之外，开发者还可以使用预定义事件进行打点。

示例代码：

```
ParamList list = OH_HiAppEvent_CreateParamList();
OH_HiAppEvent_AddInt32Param(list, PARAM_USER_ID, 123);
int res = OH_HiAppEvent_Write("user_domain", EVENT_USER_LOGIN, BEHAVIOR, list);
OH_HiAppEvent_DestroyParamList(list);
```

**引用文件：** &lt;hiappevent/hiappevent_event.h&gt;

**库：** libhiappevent_ndk.z.so

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 8

**相关模块：**[HiAppEvent](_hi_app_event.md)


## 汇总


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [EVENT_USER_LOGIN](_hi_app_event.md#event_user_login)&nbsp;&nbsp;&nbsp;"hiappevent.user_login" | 用户登录事件。  | 
| [EVENT_USER_LOGOUT](_hi_app_event.md#event_user_logout)&nbsp;&nbsp;&nbsp;"hiappevent.user_logout" | 用户登出事件。  | 
| [EVENT_DISTRIBUTED_SERVICE_START](_hi_app_event.md#event_distributed_service_start)&nbsp;&nbsp;&nbsp;"hiappevent.distributed_service_start" | 分布式服务事件。  | 
| [EVENT_APP_CRASH](_hi_app_event.md#event_app_crash)&nbsp;&nbsp;&nbsp;"APP_CRASH" | 应用崩溃事件。  | 
| [EVENT_APP_FREEZE](_hi_app_event.md#event_app_freeze)&nbsp;&nbsp;&nbsp;"APP_FREEZE" | 应用卡顿事件。  | 
| [EVENT_APP_LAUNCH](_hi_app_event.md#event_app_launch)&nbsp;&nbsp;&nbsp;"APP_LAUNCH" | 应用加载事件。  | 
| [EVENT_SCROLL_JANK](_hi_app_event.md#event_scroll_jank)&nbsp;&nbsp;&nbsp;"SCROLL_JANK" | 应用滑动卡顿事件。  | 
| [EVENT_CPU_USAGE_HIGH](_hi_app_event.md#event_cpu_usage_high)&nbsp;&nbsp;&nbsp;"CPU_USAGE_HIGH" | 应用CPU资源占用高事件。  | 
| [EVENT_BATTERY_USAGE](_hi_app_event.md#event_battery_usage)&nbsp;&nbsp;&nbsp;"BATTERY_USAGE" | 应用电源使用率事件。  | 
| [EVENT_RESOURCE_OVERLIMIT](_hi_app_event.md#event_resource_overlimit)&nbsp;&nbsp;&nbsp;"RESOURCE_OVERLIMIT" | 应用资源超限事件。  | 
| [EVENT_ADDRESS_SANITIZER](_hi_app_event.md#event_address_sanitizer)&nbsp;&nbsp;&nbsp;"ADDRESS_SANITIZER" | 应用踩内存事件。  | 
| [EVENT_MAIN_THREAD_JANK](_hi_app_event.md#event_main_thread_jank)&nbsp;&nbsp;&nbsp;"MAIN_THREAD_JANK" | 应用主线程超时事件。  | 
| [EVENT_APP_HICOLLIE](_hi_app_event.md#event_app_hicollie)&nbsp;&nbsp;&nbsp;"APP_HICOLLIE" | 应用任务执行超时事件。  | 
| [EVENT_APP_KILLED](_hi_app_event.md#event_app_killed)&nbsp;&nbsp;&nbsp;"APP_KILLED" | 应用查杀事件。  | 
| [DOMAIN_OS](_hi_app_event.md#domain_os)&nbsp;&nbsp;&nbsp;"OS" | OS作用域。  | 
