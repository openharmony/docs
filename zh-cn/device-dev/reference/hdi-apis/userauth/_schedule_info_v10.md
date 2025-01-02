# ScheduleInfo


## 概述

调度信息。

**弃用:**

从4.0版本开始废弃，使用**ScheduleInfoV1_1**接口代替。

**起始版本：** 3.2

**相关模块：**[HdfUserAuth](_hdf_user_auth_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [scheduleId](#scheduleid) | 调度ID，用于标识一次操作请求的执行器调度过程。 | 
| unsigned long[] [templateIds](#templateids) | 模版id列表。 | 
| enum [AuthType](_hdf_user_auth_v10.md#authtype)[authType](#authtype) | 用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。 | 
| unsigned int [executorMatcher](#executormatcher) | 执行器匹配器。 | 
| unsigned int [scheduleMode](#schedulemode) | 调度模式[ScheduleMode](_hdf_user_auth_v10.md#schedulemode)。 | 
| struct [ExecutorInfo](_executor_info_v10.md)[] [executors](#executors) | 执行器信息列表[ExecutorInfo](_executor_info_v10.md)。 | 


## 类成员变量说明


### authType

```
enum AuthType ScheduleInfo::authType
```

**描述**


用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。


### executorMatcher

```
unsigned int ScheduleInfo::executorMatcher
```

**描述**


执行器匹配器。


### executors

```
struct ExecutorInfo [] ScheduleInfo::executors
```

**描述**


执行器信息列表[ExecutorInfo](_executor_info_v10.md)。


### scheduleId

```
unsigned long ScheduleInfo::scheduleId
```

**描述**


调度ID，用于标识一次操作请求的执行器调度过程。


### scheduleMode

```
unsigned int ScheduleInfo::scheduleMode
```

**描述**


调度模式[ScheduleMode](_hdf_user_auth_v10.md#schedulemode)。


### templateIds

```
unsigned long [] ScheduleInfo::templateIds
```

**描述**


模版id列表。
