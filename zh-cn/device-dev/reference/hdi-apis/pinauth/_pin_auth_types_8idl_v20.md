# PinAuthTypes.idl


## 概述

定义口令认证驱动的枚举类和数据结构，包括认证类型，执行器角色，执行器安全等级命令ID，返回码，执行器信息，模板信息。

模块包路径：ohos.hdi.pin_auth.v2_0

**起始版本：** 3.2

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v20.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ExecutorInfo](_executor_info_v20.md) | 执行器信息。 | 
| struct&nbsp;&nbsp;[Property](_property_v20.md) | 执行器属性。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AuthType](_hdf_pin_auth_v20.md#authtype) : int { PIN = 1 , FACE = 2 , FINGERPRINT = 4 } | 枚举用于认证的凭据类型。 | 
| [ExecutorRole](_hdf_pin_auth_v20.md#executorrole) : int { SCHEDULER = 0 , COLLECTOR = 1 , VERIFIER = 2 , ALL_IN_ONE = 3 } | 枚举执行器角色。 | 
| [ExecutorSecureLevel](_hdf_pin_auth_v20.md#executorsecurelevel) : int { ESL0 = 0 , ESL1 = 1 , ESL2 = 2 , ESL3 = 3 } | 枚举执行器安全等级。 | 
| [GetPropertyType](_hdf_pin_auth_v20.md#getpropertytype) : int { AUTH_SUB_TYPE = 1 , LOCKOUT_DURATION = 2 , REMAIN_ATTEMPTS = 3 , NEXT_FAIL_LOCKOUT_DURATION = 6 } | 获取执行器属性信息。 | 
