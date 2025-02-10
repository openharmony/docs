# hiappevent_param.h


## 概述

定义所有预定义事件的参数名称。

除了与特定应用关联的自定义事件之外，您还可以使用预定义事件进行打点。

示例代码：

```
ParamList list = OH_HiAppEvent_CreateParamList();
OH_HiAppEvent_AddInt32Param(list, PARAM_USER_ID, 123);
int res = OH_HiAppEvent_Write("user_domain", EVENT_USER_LOGIN, BEHAVIOR, list);
OH_HiAppEvent_DestroyParamList(list);
```

**引用文件：** &lt;hiappevent/hiappevent_param.h&gt;

**库：** libhiappevent_ndk.z.so

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 8

**相关模块：**[HiAppEvent](_hi_app_event.md)


## 汇总


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [PARAM_USER_ID](_hi_app_event.md#param_user_id)   "user_id" | 用户ID。 | 
| [PARAM_DISTRIBUTED_SERVICE_NAME](_hi_app_event.md#param_distributed_service_name)   "ds_name" | 分布式服务名称。 | 
| [PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID](_hi_app_event.md#param_distributed_service_instance_id)   "ds_instance_id" | 分布式服务实例ID。 | 
