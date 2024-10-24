# ScheduleInfoV1_1


## 概述

调度信息。

**起始版本：** 4.0

**相关模块：**[HdfUserAuth](_hdf_user_auth_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [scheduleId](#scheduleid) | 调度ID，用于标识一次操作请求的执行器调度过程。 | 
| unsigned long[] [templateIds](#templateids) | 模版id列表。 | 
| enum AuthType [authType](#authtype) | 用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。 | 
| unsigned int [executorMatcher](#executormatcher) | 执行器匹配器。 | 
| unsigned int [scheduleMode](#schedulemode) | 调度模式[scheduleMode](#schedulemode)。 | 
| struct ExecutorInfo[] [executors](#executors) | 执行器信息列表[ExecutorInfo](_executor_info_v10.md)。 | 
| unsigned char[] [extraInfo](#extrainfo) | 其他相关信息，用于支持信息扩展。 | 


## 类成员变量说明


### authType

```
enum AuthType ScheduleInfoV1_1::authType
```

**描述**


用户认证凭据类型[AuthType](_hdf_user_auth_v10.md#authtype)。


### executorMatcher

```
unsigned int ScheduleInfoV1_1::executorMatcher
```

**描述**


执行器匹配器。


### executors

```
struct ExecutorInfo [] ScheduleInfoV1_1::executors
```

**描述**


执行器信息列表[ExecutorInfo](_executor_info_v10.md)。


### extraInfo

```
unsigned char [] ScheduleInfoV1_1::extraInfo
```

**描述**


其他相关信息，用于支持信息扩展。


### scheduleId

```
unsigned long ScheduleInfoV1_1::scheduleId
```

**描述**


调度ID，用于标识一次操作请求的执行器调度过程。


### scheduleMode

```
unsigned int ScheduleInfoV1_1::scheduleMode
```

**描述**


调度模式[scheduleMode](#schedulemode)。


### templateIds

```
unsigned long [] ScheduleInfoV1_1::templateIds
```

**描述**


模版id列表。
