# HdfPinAuth (V2_0)


## 概述

提供口令认证驱动的标准API接口。

口令认证驱动为口令认证服务提供统一的访问接口。获取口令认证驱动代理后，口令认证服务可以调用相关接口获取执行器，获取口令认证执行器后， 口令认证服务可以调用相关接口获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。

**起始版本：** 5.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IAllInOneExecutor.idl](_i_all_in_one_executor_8idl_v20.md) | 定义全功能执行器标准API接口。接口可用于获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。 | 
| [ICollector.idl](_i_collector_8idl_v20.md) | 定义采集器标准API接口。接口可用于获取执行器信息，取消认证，采集数据，发送消息等。 | 
| [IExecutorCallback.idl](_i_executor_callback_8idl_v20.md) | 定义异步API接口回调，用于返回异步接口的请求处理结果和获取信息。 | 
| [IPinAuthInterface.idl](_i_pin_auth_interface_8idl_v20.md) | 定义获取口令认证驱动的执行器列表接口，用于从口令认证驱动获取执行器对象列表。 | 
| [IVerifier.idl](_i_verifier_8idl_v20.md) | 定义认证器标准API接口。接口可用于获取执行器信息，取消认证，口令认证，发送消息等。 | 
| [PinAuthTypes.idl](_pin_auth_types_8idl_v20.md) | 定义口令认证驱动的枚举类和数据结构，包括认证类型，执行器角色，执行器安全等级命令ID，返回码，执行器信息，模板信息。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IAllInOneExecutor](interface_i_all_in_one_executor_v20.md) | 定义全功能执行器标准API接口。接口可用于获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。 | 
| interface&nbsp;&nbsp;[ICollector](interface_i_collector_v20.md) | 定义采集器标准API接口。接口可用于获取执行器信息，取消认证，采集数据，发送消息等。 | 
| interface&nbsp;&nbsp;[IExecutorCallback](interface_i_executor_callback_v20.md) | 定义异步API接口回调，用于返回异步接口的请求处理结果和获取信息。 | 
| interface&nbsp;&nbsp;[IPinAuthInterface](interface_i_pin_auth_interface_v20.md) | 定义获取口令认证驱动的执行器列表接口，用于从口令认证驱动获取执行器对象列表。 | 
| interface&nbsp;&nbsp;[IVerifier](interface_i_verifier_v20.md) | 定义认证器标准API接口。接口可用于获取执行器信息，取消认证，口令认证，发送消息等。 | 
| struct&nbsp;&nbsp;[ExecutorInfo](_executor_info_v20.md) | 执行器信息。 | 
| struct&nbsp;&nbsp;[Property](_property_v20.md) | 执行器属性。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AuthType](#authtype) : int { PIN = 1 , FACE = 2 , FINGERPRINT = 4 } | 枚举用于认证的凭据类型。 | 
| [ExecutorRole](#executorrole) : int { SCHEDULER = 0 , COLLECTOR = 1 , VERIFIER = 2 , ALL_IN_ONE = 3 } | 枚举执行器角色。 | 
| [ExecutorSecureLevel](#executorsecurelevel) : int { ESL0 = 0 , ESL1 = 1 , ESL2 = 2 , ESL3 = 3 } | 枚举执行器安全等级。 | 
| [GetPropertyType](#getpropertytype) : int { AUTH_SUB_TYPE = 1 , LOCKOUT_DURATION = 2 , REMAIN_ATTEMPTS = 3 , NEXT_FAIL_LOCKOUT_DURATION = 6 } | 获取执行器属性信息。 | 


## 枚举类型说明


### AuthType

```
enum AuthType : int
```

**描述**

枚举用于认证的凭据类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| PIN | 标识认证类型是口令。 | 
| FACE | 标识认证类型是人脸。 | 
| FINGERPRINT | 标识认证类型是指纹。 | 


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
| ESL0 | 执行器安全等级是ESL0。 | 
| ESL1 | 执行器安全等级是ESL1。 | 
| ESL2 | 执行器安全等级是ESL2。 | 
| ESL3 | 执行器安全等级是ESL3。 | 


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
