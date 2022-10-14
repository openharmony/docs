# PinAuthTypes.idl


## **概述**

定义口令认证驱动的枚举类和数据结构。

**Since:**

3.2

**所属模块:**

[HdfPinAuth](_hdf_pin_auth.md)


## **汇总**


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [ExecutorInfo](_executor_info.md) | 执行器信息。 | 
| [TemplateInfo](_template_info.md) | 凭据模版信息。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [AuthType](_hdf_pin_auth.md#authtype):&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;PIN&nbsp;=&nbsp;1,&nbsp;FACE&nbsp;=&nbsp;2,&nbsp;FINGERPRINT&nbsp;=&nbsp;4&nbsp;} | 枚举用户认证凭据类型。 | 
| [ExecutorRole](_hdf_pin_auth.md#executorrole):&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;COLLECTOR&nbsp;=&nbsp;1,&nbsp;VERIFIER&nbsp;=&nbsp;2,&nbsp;ALL_IN_ONE&nbsp;=&nbsp;3&nbsp;} | 枚举执行器角色。 | 
| [ExecutorSecureLevel](_hdf_pin_auth.md#executorsecurelevel):&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;ESL0&nbsp;=&nbsp;0,&nbsp;ESL1&nbsp;=&nbsp;1,&nbsp;ESL2&nbsp;=&nbsp;2,&nbsp;ESL3&nbsp;=&nbsp;3&nbsp;} | 枚举执行器安全等级。 | 
| [CommandId](_hdf_pin_auth.md#commandid):&nbsp;int&nbsp;{&nbsp;DEFAULT&nbsp;=&nbsp;0&nbsp;} | 枚举口令认证功能相关操作命令。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.pin_auth.v1_0 | 口令认证接口的包路径 | 
