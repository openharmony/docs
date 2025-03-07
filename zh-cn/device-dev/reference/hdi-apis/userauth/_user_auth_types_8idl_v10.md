# UserAuthTypes.idl


## 概述

定义用户认证驱动的枚举类和数据结构。

模块包路径：ohos.hdi.user_auth.v1_0

**起始版本：** 3.2

**相关模块：**[HdfUserAuth](_hdf_user_auth_v10.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ExecutorRegisterInfo](_executor_register_info_v10.md) | 执行器注册信息。 | 
| struct&nbsp;&nbsp;[ExecutorInfo](_executor_info_v10.md) | 执行器信息。 | 
| struct&nbsp;&nbsp;[ScheduleInfo](_schedule_info_v10.md) | 调度信息。 | 
| struct&nbsp;&nbsp;[AuthSolution](_auth_solution_v10.md) | 认证方案。 | 
| struct&nbsp;&nbsp;[ExecutorSendMsg](_executor_send_msg_v10.md) | 执行器发送的消息。 | 
| struct&nbsp;&nbsp;[AuthResultInfo](_auth_result_info_v10.md) | 用户身份认证结果信息。 | 
| struct&nbsp;&nbsp;[IdentifyResultInfo](_identify_result_info_v10.md) | 用户身份识别结果信息。 | 
| struct&nbsp;&nbsp;[EnrollParam](_enroll_param_v10.md) | 注册认证凭据参数。 | 
| struct&nbsp;&nbsp;[CredentialInfo](_credential_info_v10.md) | 认证凭据信息。 | 
| struct&nbsp;&nbsp;[EnrolledInfo](_enrolled_info_v10.md) | 注册信息。 | 
| struct&nbsp;&nbsp;[EnrollResultInfo](_enroll_result_info_v10.md) | 录入结果信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AuthType](_hdf_user_auth_v10.md#authtype) : int {&nbsp;&nbsp;ALL = 0, PIN = 1, FACE = 2, FINGERPRINT = 4 } | 枚举用户认证凭据类型。 | 
| [ExecutorRole](_hdf_user_auth_v10.md#executorrole) : int { COLLECTOR = 1, VERIFIER = 2, ALL_IN_ONE = 3 } | 枚举执行器角色。 | 
| [ExecutorSecureLevel](_hdf_user_auth_v10.md#executorsecurelevel) : int { ESL0 = 0, ESL1 = 1, ESL2 = 2, ESL3 = 3 } | 枚举执行器安全等级。 | 
| [PinSubType](_hdf_user_auth_v10.md#pinsubtype) : int { PIN_SIX = 10000, PIN_NUMBER = 10001, PIN_MIX = 10002 } | 口令认证子类型。 | 
| [ScheduleMode](_hdf_user_auth_v10.md#schedulemode) : int { ENROLL = 0 , AUTH = 1 , IDENTIFY = 2 } | 调度模式。 | 
