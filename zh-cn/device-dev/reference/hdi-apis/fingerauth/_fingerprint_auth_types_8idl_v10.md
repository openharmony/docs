# FingerprintAuthTypes.idl


## 概述

定义指纹认证驱动枚举和数据结构，包括认证类型、执行器角色、 执行器安全等级、命令ID、指纹提示信息编码、执行器信息和模板信息。

模块包路径：ohos.hdi.fingerprint_auth.v1_0

**起始版本：** 3.2

**相关模块：**[HdfFingerprintAuth](_hdf_fingerprint_auth_v10.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ExecutorInfo](_executor_info_fingerauth_v10.md) | 执行器信息。 | 
| struct&nbsp;&nbsp;[TemplateInfo](_template_info_fingerauth_v10.md) | 凭据模板信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AuthType](_hdf_fingerprint_auth_v10.md#authtype) : int { PIN = 1 , FACE = 2 , FINGERPRINT = 4 } | 枚举用户认证的凭据类型。 | 
| [ExecutorRole](_hdf_fingerprint_auth_v10.md#executorrole) : int { COLLECTOR = 1 , VERIFIER = 2 , ALL_IN_ONE = 3 } | 枚举执行器角色。 | 
| [ExecutorSecureLevel](_hdf_fingerprint_auth_v10.md#executorsecurelevel) : int { ESL0 = 0 , ESL1 = 1 , ESL2 = 2 , ESL3 = 3 } | 枚举执行器安全等级。 | 
| [CommandId](_hdf_fingerprint_auth_v10.md#commandid) : int { LOCK_TEMPLATE = 1 , UNLOCK_TEMPLATE = 2 , VENDOR_COMMAND_BEGIN = 10000 } | 枚举指纹认证功能相关操作命令。 | 
| [FingerprintTipsCode](_hdf_fingerprint_auth_v10.md#fingerprinttipscode) : int {<br/>FINGERPRINT_AUTH_TIP_GOOD = 0 , FINGERPRINT_AUTH_TIP_DIRTY = 1 , FINGERPRINT_AUTH_TIP_INSUFFICIENT = 2 , FINGERPRINT_AUTH_TIP_PARTIAL = 3 ,<br/>FINGERPRINT_AUTH_TIP_TOO_FAST = 4 , FINGERPRINT_AUTH_TIP_TOO_SLOW = 5 , VENDOR_FINGERPRINT_AUTH_TIP_BEGIN = 10000<br/>} | 枚举提示信息编码。 | 
