# FaceAuthTypes.idl


## 概述

定义人脸认证驱动的枚举类和数据结构。

模块包路径：ohos.hdi.face_auth.v1_0

**起始版本：** 3.2

**相关模块：**[HdfFaceAuth](_hdf_face_auth_v10.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ExecutorInfo](_executor_info_faceauth_v10.md) | 执行器信息。 | 
| struct&nbsp;&nbsp;[TemplateInfo](_template_info_faceauth_v10.md) | 凭据模版信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AuthType](_hdf_face_auth_v10.md#authtype) : int { PIN = 1, FACE = 2, FINGERPRINT = 4 } | 枚举用户认证凭据类型。 | 
| [ExecutorRole](_hdf_face_auth_v10.md#executorrole) : int { COLLECTOR = 1, VERIFIER = 2, ALL_IN_ONE = 3 } | 枚举执行器角色。 | 
| [ExecutorSecureLevel](_hdf_face_auth_v10.md#executorsecurelevel) : int { ESL0 = 0, ESL1 = 1, ESL2 = 2, ESL3 = 3 } | 枚举执行器安全等级。 | 
| [CommandId](_hdf_face_auth_v10.md#commandid) : int { LOCK_TEMPLATE = 1, UNLOCK_TEMPLATE = 2, VENDOR_COMMAND_BEGIN = 10000 } | 枚举人脸认证功能相关操作命令。 | 
| [FaceTipsCode](_hdf_face_auth_v10.md#facetipscode) : int { FACE_AUTH_TIP_TOO_BRIGHT = 1, FACE_AUTH_TIP_TOO_DARK = 2, FACE_AUTH_TIP_TOO_CLOSE = 3, FACE_AUTH_TIP_TOO_FAR = 4,&nbsp;&nbsp;&nbsp;FACE_AUTH_TIP_TOO_HIGH = 5, FACE_AUTH_TIP_TOO_LOW = 6, FACE_AUTH_TIP_TOO_RIGHT = 7, FACE_AUTH_TIP_TOO_LEFT = 8,&nbsp;&nbsp;&nbsp;FACE_AUTH_TIP_TOO_MUCH_MOTION = 9, FACE_AUTH_TIP_POOR_GAZE = 10, FACE_AUTH_TIP_NOT_DETECTED = 11, VENDOR_FACE_AUTH_TIP_BEGIN = 10000 } | 枚举提示信息编码。 | 
