# UserAuthTypes.idl


## 概述

定义用户认证驱动的枚举类和数据结构。

**Since:**

3.2

**相关模块:**

[HdfUserAuth](_hdf_user_auth.md)


## 汇总


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [ExecutorRegisterInfo](_executor_register_info.md) | struct<br/>执行器注册信息。 | 
| [ExecutorInfo](_executor_info_userauth.md) | struct<br/>执行器信息。 | 
| [ScheduleInfo](_schedule_info.md) | struct<br/>调度信息。 | 
| [AuthSolution](_auth_solution.md) | struct<br/>认证方案。 | 
| [ExecutorSendMsg](_executor_send_msg.md) | struct<br/>执行器发送的消息。 | 
| [AuthResultInfo](_auth_result_info.md) | struct<br/>用户身份认证结果信息。 | 
| [IdentifyResultInfo](_identify_result_info.md) | struct<br/>用户身份识别结果信息。 | 
| [EnrollParam](_enroll_param.md) | struct<br/>注册认证凭据参数。 | 
| [CredentialInfo](_credential_info.md) | struct<br/>认证凭据信息。 | 
| [EnrolledInfo](_enrolled_info.md) | struct<br/>注册信息。 | 
| [EnrollResultInfo](_enroll_result_info.md) | struct<br/>录入结果信息。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [AuthType](_hdf_user_auth.md#authtype)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;ALL&nbsp;=&nbsp;0,&nbsp;PIN&nbsp;=&nbsp;1,&nbsp;FACE&nbsp;=&nbsp;2,&nbsp;FINGERPRINT&nbsp;=&nbsp;4&nbsp;} | 枚举用户认证凭据类型。 | 
| [ExecutorRole](_hdf_user_auth.md#executorrole)&nbsp;:&nbsp;int&nbsp;{&nbsp;COLLECTOR&nbsp;=&nbsp;1,&nbsp;VERIFIER&nbsp;=&nbsp;2,&nbsp;ALL_IN_ONE&nbsp;=&nbsp;3&nbsp;} | 枚举执行器角色。 | 
| [ExecutorSecureLevel](_hdf_user_auth.md#executorsecurelevel)&nbsp;:&nbsp;int&nbsp;{&nbsp;ESL0&nbsp;=&nbsp;0,&nbsp;ESL1&nbsp;=&nbsp;1,&nbsp;ESL2&nbsp;=&nbsp;2,&nbsp;ESL3&nbsp;=&nbsp;3&nbsp;} | 枚举执行器安全等级。 | 
| [PinSubType](_hdf_user_auth.md#pinsubtype)&nbsp;:&nbsp;int&nbsp;{&nbsp;PIN_SIX&nbsp;=&nbsp;10000,&nbsp;PIN_NUMBER&nbsp;=&nbsp;10001,&nbsp;PIN_MIX&nbsp;=&nbsp;10002&nbsp;} | 口令认证子类型。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.user_auth.v1_0 | 用户认证接口的包路径 | 
