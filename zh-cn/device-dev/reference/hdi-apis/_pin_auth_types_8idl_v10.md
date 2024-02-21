# PinAuthTypes.idl


## 概述

定义口令认证驱动的枚举类和数据结构。

模块包路径：ohos.hdi.pin_auth.v1_0

**起始版本：** 3.2

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v10.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ExecutorInfo](_executor_info_pinauth_v10.md) | 执行器信息。 | 
| struct&nbsp;&nbsp;[TemplateInfo](_template_info_pinauth_v10.md) | 凭据模版信息，口令模版在用户注册口令认证凭据时生成并存储，用于支持通过口令认证方式验证用户身份。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AuthType](_hdf_pin_auth_v10.md#authtype) : int {&nbsp;&nbsp;&nbsp;PIN = 1, FACE = 2, FINGERPRINT = 4 } | 枚举用户认证凭据类型。 | 
| [ExecutorRole](_hdf_pin_auth_v10.md#executorrole) : int {&nbsp;&nbsp;&nbsp;COLLECTOR = 1, VERIFIER = 2, ALL_IN_ONE = 3 } | 枚举执行器角色。 | 
| [ExecutorSecureLevel](_hdf_pin_auth_v10.md#executorsecurelevel) : int {&nbsp;&nbsp;&nbsp;ESL0 = 0, ESL1 = 1, ESL2 = 2, ESL3 = 3 } | 枚举执行器安全等级。 | 
| [CommandId](_hdf_pin_auth_v10.md#commandid) : int { DEFAULT = 0 } | 枚举口令认证相关功能操作命令。 | 
