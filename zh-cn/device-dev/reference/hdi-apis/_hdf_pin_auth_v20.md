# HdfPinAuth（V2_0）


## 概述

提供口令认证驱动的标准API接口。

口令认证驱动为口令认证服务提供统一的访问接口。获取口令认证驱动代理后，口令认证服务可以调用相关接口获取执行器，获取口令认证执行器后， 口令认证服务可以调用相关接口获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。

**起始版本：** 5.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IAllInOneExecutor.idl](_i_all_in_one_executor_8idl_pinauth_v20.md) | 定义全功能执行器标准API接口。接口可用于获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。 | 
| [ICollector.idl](_i_collector_8idl_pinauth_v20.md) | 定义采集器标准API接口。接口可用于获取执行器信息，取消认证，采集数据，发送消息等。 | 
| [IExecutorCallback.idl](_i_executor_callback_8idl_pinauth_v20.md) | 定义异步API接口回调，用于返回异步接口的请求处理结果和获取信息。 | 
| [IPinAuthInterface.idl](_i_pin_auth_interface_8idl_v20.md) | 定义获取口令认证驱动的执行器列表接口，用于从口令认证驱动获取执行器对象列表。 | 
| [IVerifier.idl](_i_verifier_8idl_pinauth_v20.md) | 定义认证器标准API接口。接口可用于获取执行器信息，取消认证，口令认证，发送消息等。 | 
| [PinAuthTypes.idl](_pin_auth_types_8idl_v20.md) | 定义口令认证驱动的枚举类和数据结构。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface [IAllInOneExecutor](interface_i_all_in_one_executor_pinauth_v20.md) | 定义全功能执行器标准API接口。接口可用于获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。 | 
| interface [ICollector](interface_i_collector_pinauth_v20.md) | 定义采集器标准API接口。接口可用于获取执行器信息，取消认证，采集数据，发送消息等。 | 
| interface [IExecutorCallback](interface_i_executor_callback_pinauth_v20.md) | 定义异步API接口回调，用于返回异步接口的请求处理结果和获取信息。使用细节见[IExecutor](interface_i_all_in_one_executor_pinauth_v20.md)。 | 
| interface [IPinAuthInterface](interface_i_pin_auth_interface_v20.md) | 定义获取口令认证驱动的执行器列表接口。 | 
| struct [Property](_property_pinauth_v20.md) | 执行器属性。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AuthType](#authtype) : int { PIN = 1, FACE = 2, FINGERPRINT = 4 } | 枚举用户认证凭据类型。 | 
| [ExecutorRole](#executorrole) : int { SCHEDULER = 0, COLLECTOR = 1, VERIFIER = 2, ALL_IN_ONE = 3 } | 枚举执行器角色。 | 
| [ExecutorSecureLevel](#executorsecurelevel) : int { ESL0 = 0, ESL1 = 1, ESL2 = 2, ESL3 = 3 } | 枚举执行器安全等级。 | 
| [GetPropertyType](#getpropertytype) : int { AUTH_SUB_TYPE = 1 , LOCKOUT_DURATION = 2 , REMAIN_ATTEMPTS = 3 , NEXT_FAIL_LOCKOUT_DURATION = 6 } | 获取执行器属性信息。 | 


## 枚举类型说明


### GetPropertyType

```
enum GetPropertyType : int
```

**描述**

获取执行器属性信息。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUTH_SUB_TYPE | 获取执行器的认证子类型。 | 
| LOCKOUT_DURATION | 获取执行器的剩余锁定时间。 | 
| REMAIN_ATTEMPTS | 获取执行器的剩余可重试次数。 | 
| NEXT_FAIL_LOCKOUT_DURATION | 获取执行器的下一次失败锁定时间。 | 


### AuthType

```
enum AuthType : int
```

**描述**

枚举用户认证凭据类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| PIN | 认证凭据类型为口令。 | 
| FACE | 认证凭据类型为人脸。 | 
| FINGERPRINT | 认证凭据类型为指纹。 | 


### ExecutorRole

```
enum ExecutorRole : int
```

**描述**

枚举执行器角色。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| SCHEDULER | 执行器角色为调度器。 | 
| COLLECTOR | 执行器角色为采集器，提供用户认证时的数据采集能力，需要和认证器配合完成用户认证。 | 
| VERIFIER | 执行器角色为认证器，提供用户认证时数据处理能力，读取存储凭据模板信息并完成比对。 | 
| ALL_IN_ONE | 执行器角色为全功能执行器，可提供用户认证数据采集、处理、储存及比对能力。 | 


### ExecutorSecureLevel

```
enum ExecutorSecureLevel : int
```

**描述**

枚举执行器安全等级。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| ESL0 | 执行器安全级别为0，关键操作在无访问控制执行环境中完成。 | 
| ESL1 | 执行器安全级别为1，关键操作在有访问控制的执行环境中完成。 | 
| ESL2 | 执行器安全级别为2，关键操作在可信执行环境中完成。 | 
| ESL3 | 执行器安全级别为3，关键操作在高安环境如独立安全芯片中完成。 | 

