# FingerprintAuthTypes.idl


## 概述

定义指纹认证驱动枚举和数据结构，包括认证类型、执行器角色、 执行器安全等级、命令ID、指纹提示信息编码、执行器信息和模板信息。

模块包路径：ohos.hdi.fingerprint_auth.v1_1

**起始版本：** 4.0

**相关模块：**[HdfFingerprintAuth](_hdf_fingerprint_auth_v11.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[Property](_property_fingerauth_v11.md) | 执行器属性。 | 
| struct&nbsp;&nbsp;[SaCommandParamEnableSensorIllumination](_sa_command_param_enable_sensor_illumination_fingerauth_v11.md) | 光斑使能的sa命令参数。 | 
| struct&nbsp;&nbsp;[SaCommandParamNone](_sa_command_param_none_fingerauth_v11.md) | sa命令参数为空。 | 
| union&nbsp;&nbsp;[SaCommandParam](union_sa_command_param_fingerauth_v11.md) | sa命令参数。 | 
| struct&nbsp;&nbsp;[SaCommand](_sa_command_fingerauth_v11.md) | sa命令ID。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [FingerprintTipsCode](_hdf_fingerprint_auth_v11.md#fingerprinttipscode) : int {<br/>FINGERPRINT_AUTH_TIP_GOOD = 0 , FINGERPRINT_AUTH_TIP_DIRTY = 1 , FINGERPRINT_AUTH_TIP_INSUFFICIENT = 2 , FINGERPRINT_AUTH_TIP_PARTIAL = 3 ,<br/>FINGERPRINT_AUTH_TIP_TOO_FAST = 4 , FINGERPRINT_AUTH_TIP_TOO_SLOW = 5 ,<br/>FINGERPRINT_AUTH_TIP_FINGER_DOWN = 6 , FINGERPRINT_AUTH_TIP_FINGER_UP = 7 , VENDOR_FINGERPRINT_AUTH_TIP_BEGIN = 10000<br/>} | 枚举提示信息编码。 | 
| [GetPropertyType](_hdf_fingerprint_auth_v11.md#getpropertytype) : int {<br/>AUTH_SUB_TYPE = 1 , LOCKOUT_DURATION = 2 , REMAIN_ATTEMPTS = 3 , ENROLL_PROGRESS = 4 , SENSOR_INFO = 5<br/>} | 获取指纹执行器属性。 | 
| [SaCommandId](_hdf_fingerprint_auth_v11.md#sacommandid) : int { ENABLE_SENSOR_ILLUMINATION = 1 , DISABLE_SENSOR_ILLUMINATION = 2 , TURN_ON_SENSOR_ILLUMINATION = 3 , TURN_OFF_SENSOR_ILLUMINATION = 4 } | 枚举sa命令ID。 | 
| [CommandId](_hdf_fingerprint_auth_v11.md#commandid) : int { LOCK_TEMPLATE = 1 , UNLOCK_TEMPLATE = 2 , INIT_ALGORITHM = 3 , VENDOR_COMMAND_BEGIN = 10000 } | 枚举命令ID。 | 
