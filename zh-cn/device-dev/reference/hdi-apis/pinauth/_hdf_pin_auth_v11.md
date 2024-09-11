# HdfPinAuth (V1_1)


## 概述

提供口令认证驱动的标准API接口。

口令认证驱动为口令认证服务提供统一的访问接口。获取口令认证驱动代理后，口令认证服务可以调用相关接口获取执行器，获取口令认证执行器后， 口令认证服务可以调用相关接口获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IExecutor.idl](_i_executor_8idl_pinauth_v11.md) | 定义执行器标准API接口。接口可用于获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。 | 
| [IExecutorCallback.idl](_i_executor_callback_8idl_pinauth_v11.md) | 定义异步API接口回调，用于返回异步接口的请求处理结果和获取信息。 | 
| [IPinAuthInterface.idl](_i_pin_auth_interface_8idl_v11.md) | 定义获取口令认证驱动的执行器列表接口，用于从口令认证驱动获取执行器对象列表。 | 
| [PinAuthTypes.idl](_pin_auth_types_8idl_v11.md) | 定义口令认证驱动的枚举类和数据结构。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IExecutor](interface_i_executor_pinauth_v11.md) | 定义执行器标准API接口。接口可用于获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。 | 
| interface&nbsp;&nbsp;[IExecutorCallback](interface_i_executor_callback_pinauth_v11.md) | 定义异步API接口回调，用于返回异步接口的请求处理结果和获取信息。使用细节见[IExecutor](interface_i_executor_pinauth_v11.md)。 | 
| interface&nbsp;&nbsp;[IPinAuthInterface](interface_i_pin_auth_interface_v11.md) | 定义获取口令认证驱动的执行器列表接口。 | 
| struct&nbsp;&nbsp;[Property](_property_pinauth_v11.md) | 执行器属性。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [GetPropertyType](#getpropertytype) : int { AUTH_SUB_TYPE = 1 , LOCKOUT_DURATION = 2 , REMAIN_ATTEMPTS = 3 } | 获取执行器属性信息。 | 


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
