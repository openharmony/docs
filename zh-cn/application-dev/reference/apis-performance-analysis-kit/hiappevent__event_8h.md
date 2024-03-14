# hiappevent_event.h


## 概述

定义所有预定义事件的事件名称。

除了与特定应用关联的自定义事件之外，您还可以使用预定义事件进行打点。

示例代码：

```
ParamList list = OH_HiAppEvent_CreateParamList();
OH_HiAppEvent_AddInt32Param(list, PARAM_USER_ID, 123);
int res = OH_HiAppEvent_Write("user_domain", EVENT_USER_LOGIN, BEHAVIOR, list);
OH_HiAppEvent_DestroyParamList(list);
```

**起始版本：** 8

**相关模块：**[HiAppEvent](_hi_app_event.md)


## 汇总


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [EVENT_USER_LOGIN](_hi_app_event.md#event_user_login)   "hiappevent.user_login" | 用户登录事件。  | 
| [EVENT_USER_LOGOUT](_hi_app_event.md#event_user_logout)   "hiappevent.user_logout" | 用户登出事件。  | 
| [EVENT_DISTRIBUTED_SERVICE_START](_hi_app_event.md#event_distributed_service_start)   "hiappevent.distributed_service_start" | 分布式服务事件。  | 
| [EVENT_APP_CRASH](_hi_app_event.md#event_app_crash)   "APP_CRASH" | 应用崩溃事件。  | 
| [EVENT_APP_FREEZE](_hi_app_event.md#event_app_freeze)   "APP_FREEZE" | 应用卡顿事件。  | 
| [EVENT_APP_LAUNCH](_hi_app_event.md#event_app_launch)   "APP_LAUNCH" | 应用加载事件。  | 
| [EVENT_SCROLL_JANK](_hi_app_event.md#event_scroll_jank)   "SCROLL_JANK" | 应用滑动卡顿事件。  | 
| [EVENT_CPU_USAGE_HIGH](_hi_app_event.md#event_cpu_usage_high)   "CPU_USAGE_HIGH" | 应用CPU资源占用高事件。  | 
| [EVENT_BATTERY_USAGE](_hi_app_event.md#event_battery_usage)   "BATTERY_USAGE" | 应用电源使用率事件。  | 
| [EVENT_RESOURCE_OVERLIMIT](_hi_app_event.md#event_resource_overlimit)   "RESOURCE_OVERLIMIT" | 应用资源超限事件。  | 
| [DOMAIN_OS](_hi_app_event.md#domain_os)   "OS" | OS作用域。  | 
