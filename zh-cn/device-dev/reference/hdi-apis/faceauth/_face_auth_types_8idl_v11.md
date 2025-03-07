# FaceAuthTypes.idl


## 概述

定义人脸认证驱动的枚举类和数据结构，包括AuthType, ExecutorRole, ExecutorSecureLevel, CommandId, FaceTipsCode, ExecutorInfo, 和TemplateInfo。

模块包路径：ohos.hdi.face_auth.v1_1

**起始版本：** 4.0

**相关模块：**[HdfFaceAuth](_hdf_face_auth_v11.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[Property](_property_faceauth_v11.md) | 执行器相关属性。 | 
| struct&nbsp;&nbsp;[SaCommandParamNone](_sa_command_param_none_faceauth_v11.md) | SA命令参数为空。 | 
| union&nbsp;&nbsp;[SaCommandParam](union_sa_command_param_faceauth_v11.md) | SA命令参数。 | 
| struct&nbsp;&nbsp;[SaCommand](_sa_command_faceauth_v11.md) | SA命令相关。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [GetPropertyType](_hdf_face_auth_v11.md#getpropertytype) : int {<br/>AUTH_SUB_TYPE = 1 , LOCKOUT_DURATION = 2 , REMAIN_ATTEMPTS = 3 , ENROLL_PROGRESS = 4 ,<br/>SENSOR_INFO = 5<br/>} | 枚举获得属性类型。 | 
| [SaCommandId](_hdf_face_auth_v11.md#sacommandid) : int { BEGIN_SCREEN_BRIGHTNESS_INCREASE = 1 , END_SCREEN_BRIGHTNESS_INCREASE = 2 } | 枚举sa命令id。 | 
| [CommandId](_hdf_face_auth_v11.md#commandid) : int { LOCK_TEMPLATE = 1 , UNLOCK_TEMPLATE = 2 , INIT_ALGORITHM = 3 , VENDOR_COMMAND_BEGIN = 10000 } | 枚举人脸认证功能相关操作命令。 | 
