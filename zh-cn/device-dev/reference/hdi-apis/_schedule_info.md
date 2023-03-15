# ScheduleInfo


## **概述**

调度信息。

**Since：**

3.2

**Version：**

1.0

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [scheduleId](#scheduleid) | 调度ID，用于标识一次操作请求的执行器调度过程。 | 
| [templateIds](#templateids) | 模版ID列表。 | 
| [authType](#authtype) | 用户认证凭据类型。 | 
| [executorMatcher](#executormatcher) | 执行器匹配器。 | 
| [scheduleMode](#schedulemode) | 调度模式，支持注册、认证和识别模式。 | 
| [executors](#executors) | 执行器信息列表。 | 


## **类成员变量说明**


### authType

  
```
enum AuthType ScheduleInfo::authType
```

**描述：**

用户认证凭据类型。


### executors

  
```
struct ExecutorInfo [] ScheduleInfo::executors
```

**描述：**

执行器信息列表。


### executorMatcher

  
```
unsigned int ScheduleInfo::executorMatcher
```

**描述：**

执行器匹配器。


### scheduleId

  
```
unsigned long ScheduleInfo::scheduleId
```

**描述：**

调度ID，用于标识一次操作请求的执行器调度过程。


### scheduleMode

  
```
unsigned int ScheduleInfo::scheduleMode
```

**描述：**

调度模式，支持注册、认证和识别模式。


### templateIds

  
```
unsigned long [] ScheduleInfo::templateIds
```

**描述：**

模版ID列表。
