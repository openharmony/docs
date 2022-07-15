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


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [AuthType](_hdf_user_auth.md#authtype)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[PIN](_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a048efb7462d3f8cced82716c66926168)&nbsp;=&nbsp;1,&nbsp;[FACE](_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a5cfae78048cf95359061c2e812e7d691)&nbsp;=&nbsp;2,&nbsp;[FINGERPRINT](_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1ad03eae85b35bf9bc22d787c8913b795a)&nbsp;=&nbsp;4,&nbsp;[ALL](_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1ab1d5eac4b1dca480c8056eaea7663b7a)&nbsp;=&nbsp;0&nbsp;} | 枚举用户认证凭据类型。&nbsp;[更多...](_hdf_user_auth.md#authtype) | 
| [ExecutorRole](_hdf_user_auth.md#executorrole)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[COLLECTOR](_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a539c54e76bcc96cddb85f0cabcff39ec)&nbsp;=&nbsp;1,&nbsp;[VERIFIER](_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a1286a5d974d0c68d7bc43ffc0576a6d4)&nbsp;=&nbsp;2,&nbsp;[ALL_IN_ONE](_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a7eebd77a403f81c5968b4c2898ee6fd4)&nbsp;=&nbsp;3&nbsp;} | 枚举执行器角色。&nbsp;[更多...](_hdf_user_auth.md#executorrole) | 
| [ExecutorSecureLevel](_hdf_user_auth.md#executorsecurelevel)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[ESL0](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa0cd05a2adda94d3c676fca84f96c0638)&nbsp;=&nbsp;0,&nbsp;[ESL1](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fae6a34bbf2764541238bf81569faf29d3)&nbsp;=&nbsp;1,&nbsp;[ESL2](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa8f898bca57625d548a011ba2aaf4285f)&nbsp;=&nbsp;2,&nbsp;[ESL3](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa9a6fb8a4530b6a09dba2fbfdf2e6c2e9)&nbsp;=&nbsp;3&nbsp;} | 枚举执行器安全等级。&nbsp;[更多...](_hdf_user_auth.md#executorsecurelevel) | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.user_auth.v1_0 | 用户认证接口的包路径 | 


## **详细描述**

定义用户认证驱动的枚举类和数据结构。

**Since：**

3.2
