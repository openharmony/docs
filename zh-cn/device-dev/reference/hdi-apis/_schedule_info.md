# ScheduleInfo


## 概述

调度信息。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[HdfUserAuth](_hdf_user_auth.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [scheduleId](#scheduleid) | unsigned&nbsp;long<br/>调度ID，用于标识一次操作请求的执行器调度过程。 | 
| [templateIds](#templateids) | unsigned&nbsp;long[]<br/>模版id列表。 | 
| [authType](#authtype) | enum&nbsp;[AuthType](_hdf_user_auth.md#authtype)<br/>用户认证凭据类型。 | 
| [executorMatcher](#executormatcher) | unsigned&nbsp;int<br/>执行器匹配器。 | 
| [scheduleMode](#schedulemode) | unsigned&nbsp;int<br/>调度模式，支持注册、认证和识别模式。 | 
| [executors](#executors) | struct&nbsp;[ExecutorInfo](_executor_info_userauth.md)[]<br/>执行器信息列表。 | 


## 类成员变量说明


### authType

  
```
enum AuthType ScheduleInfo::authType
```

**描述:**

用户认证凭据类型[AuthType](_hdf_user_auth.md#authtype)。


### executorMatcher

  
```
unsigned int ScheduleInfo::executorMatcher
```

**描述:**

执行器匹配器。


### executors

  
```
struct ExecutorInfo [] ScheduleInfo::executors
```

**描述:**

执行器信息列表[ExecutorInfo](_executor_info_userauth.md)。


### scheduleId

  
```
unsigned long ScheduleInfo::scheduleId
```

**描述:**

调度ID，用于标识一次操作请求的执行器调度过程。


### scheduleMode

  
```
unsigned int ScheduleInfo::scheduleMode
```

**描述:**

调度模式，支持注册、认证和识别模式。


### templateIds

  
```
unsigned long [] ScheduleInfo::templateIds
```

**描述:**

模版id列表。
