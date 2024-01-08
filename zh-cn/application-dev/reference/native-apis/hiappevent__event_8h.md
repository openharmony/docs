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
| [EVENT_USER_LOGIN](_hi_app_event.md#event_user_login)&nbsp;&nbsp;&nbsp;"hiappevent.user_login" | 用户登录事件。 | 
| [EVENT_USER_LOGOUT](_hi_app_event.md#event_user_logout)&nbsp;&nbsp;&nbsp;"hiappevent.user_logout" | 用户登出事件。 | 
| [EVENT_DISTRIBUTED_SERVICE_START](_hi_app_event.md#event_distributed_service_start)&nbsp;&nbsp;&nbsp;"hiappevent.distributed_service_start" | 分布式服务事件。 | 
