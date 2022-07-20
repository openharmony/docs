# UserAuthTypes.idl


## **概述**

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [ExecutorRegisterInfo](_executor_register_info.md) | 执行器注册信息。&nbsp;[更多...](_executor_register_info.md) | 
| [ExecutorInfo](_executor_info.md) | 执行器信息。&nbsp;[更多...](_executor_info.md) | 
| [ScheduleInfo](_schedule_info.md) | 调度信息。&nbsp;[更多...](_schedule_info.md) | 
| [AuthSolution](_auth_solution.md) | 认证方案。&nbsp;[更多...](_auth_solution.md) | 
| [ExecutorSendMsg](_executor_send_msg.md) | 执行器发送的消息。&nbsp;[更多...](_executor_send_msg.md) | 
| [AuthResultInfo](_auth_result_info.md) | 用户身份认证结果信息。&nbsp;[更多...](_auth_result_info.md) | 
| [IdentifyResultInfo](_identify_result_info.md) | 用户身份识别结果信息。&nbsp;[更多...](_identify_result_info.md) | 
| [EnrollParam](_enroll_param.md) | 注册认证凭据参数。&nbsp;[更多...](_enroll_param.md) | 
| [CredentialInfo](_credential_info.md) | 认证凭据信息。&nbsp;[更多...](_credential_info.md) | 
| [EnrolledInfo](_enrolled_info.md) | 注册信息。&nbsp;[更多...](_enrolled_info.md) | 
| [EnrollResultInfo](_enroll_resultinfo.md) | 录入结果信息。[更多...](_enroll_resultinfo.md) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [AuthType](_hdf_user_auth.md#authtype)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;PIN&nbsp;=&nbsp;1,&nbsp;FACE&nbsp;=&nbsp;2,&nbsp;FINGERPRINT&nbsp;=&nbsp;4,&nbsp;ALL&nbsp;=&nbsp;0&nbsp;} | 枚举用户认证凭据类型。&nbsp;[更多...](_hdf_user_auth.md#authtype) | 
| [ExecutorRole](_hdf_user_auth.md#executorrole)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;COLLECTOR&nbsp;=&nbsp;1,&nbsp;VERIFIER&nbsp;=&nbsp;2,&nbsp;ALL_IN_ONE&nbsp;=&nbsp;3&nbsp;} | 枚举执行器角色。&nbsp;[更多...](_hdf_user_auth.md#executorrole) | 
| [ExecutorSecureLevel](_hdf_user_auth.md#executorsecurelevel)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;ESL0&nbsp;=&nbsp;0,&nbsp;ESL1&nbsp;=&nbsp;1,&nbsp;ESL2&nbsp;=&nbsp;2,&nbsp;ESL3&nbsp;=&nbsp;3&nbsp;} | 枚举执行器安全等级。&nbsp;[更多...](_hdf_user_auth.md#executorsecurelevel) | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.user_auth.v1_0 | 用户认证接口的包路径 | 


## **详细描述**

定义用户认证驱动的枚举类和数据结构。

**Since：**

3.2
