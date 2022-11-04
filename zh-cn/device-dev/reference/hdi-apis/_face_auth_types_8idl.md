# FaceAuthTypes.idl


## **概述**

定义人脸认证驱动的枚举类和数据结构。

**Since：**

3.2

**所属模块:**

[HdfFaceAuth](_hdf_face_auth.md)


## **汇总**


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [ExecutorInfo](_executor_info.md) | 执行器信息。 | 
| [TemplateInfo](_template_info.md) | 凭据模版信息。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [AuthType](_hdf_face_auth.md#authtype):&nbsp;int&nbsp;{&nbsp;PIN&nbsp;=&nbsp;1,&nbsp;FACE&nbsp;=&nbsp;2,&nbsp;FINGERPRINT&nbsp;=&nbsp;4&nbsp;} | 枚举用户认证凭据类型。 | 
| [ExecutorRole](_hdf_face_auth.md#executorrole):&nbsp;int&nbsp;{&nbsp;COLLECTOR&nbsp;=&nbsp;1,&nbsp;VERIFIER&nbsp;=&nbsp;2,&nbsp;ALL_IN_ONE&nbsp;=&nbsp;3&nbsp;} | 枚举执行器角色。 | 
| [ExecutorSecureLevel](_hdf_face_auth.md#executorsecurelevel):&nbsp;int&nbsp;{&nbsp;ESL0&nbsp;=&nbsp;0,&nbsp;ESL1&nbsp;=&nbsp;1,&nbsp;ESL2&nbsp;=&nbsp;2,&nbsp;ESL3&nbsp;=&nbsp;3&nbsp;} | 枚举执行器安全等级。 | 
| [CommandId](_hdf_face_auth.md#commandid):&nbsp;int&nbsp;{&nbsp;LOCK_TEMPLATE&nbsp;=&nbsp;1,&nbsp;UNLOCK_TEMPLATE&nbsp;=&nbsp;2,&nbsp;VENDOR_COMMAND_BEGIN&nbsp;=&nbsp;10000&nbsp;} | 枚举人脸认证功能相关操作命令。 | 
| [FaceTipsCode](_hdf_face_auth.md#facetipscode):&nbsp;int&nbsp;{&nbsp;FACE_AUTH_TIP_TOO_BRIGHT&nbsp;=&nbsp;1,&nbsp;FACE_AUTH_TIP_TOO_DARK&nbsp;=&nbsp;2,&nbsp;FACE_AUTH_TIP_TOO_CLOSE&nbsp;=&nbsp;3,&nbsp;FACE_AUTH_TIP_TOO_FAR&nbsp;=&nbsp;4,&nbsp;&nbsp;&nbsp;FACE_AUTH_TIP_TOO_HIGH&nbsp;=&nbsp;5,&nbsp;FACE_AUTH_TIP_TOO_LOW&nbsp;=&nbsp;6,&nbsp;FACE_AUTH_TIP_TOO_RIGHT&nbsp;=&nbsp;7,&nbsp;FACE_AUTH_TIP_TOO_LEFT&nbsp;=&nbsp;8,&nbsp;&nbsp;&nbsp;FACE_AUTH_TIP_TOO_MUCH_MOTION&nbsp;=&nbsp;9,&nbsp;FACE_AUTH_TIP_POOR_GAZE&nbsp;=&nbsp;10,&nbsp;FACE_AUTH_TIP_NOT_DETECTED&nbsp;=&nbsp;11,&nbsp;VENDOR_FACE_AUTH_TIP_BEGIN&nbsp;=&nbsp;10000&nbsp;} | 枚举提示信息编码。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.face_auth.v1_0 | 人脸认证接口的包路径 | 
