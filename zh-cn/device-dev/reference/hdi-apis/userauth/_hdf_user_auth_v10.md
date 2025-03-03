# HdfUserAuth (V1_0)


## 概述

提供用户认证驱动的标准API接口。

用户认证驱动为用户认证服务提供统一的访问接口。获取用户认证驱动代理后，用户认证服务可以调用相关接口注册执行器，管理用户认证凭据，完成PIN码和生物特征认证。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IUserAuthInterface.idl](_i_user_auth_interface_8idl_v10.md) | 声明用户认证驱动的API接口。接口可用于注册执行器，管理用户认证凭据，完成PIN码和生物特征认证。 | 
| [UserAuthTypes.idl](_user_auth_types_8idl_v10.md) | 定义用户认证驱动的枚举类和数据结构。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IUserAuthInterface](interface_i_user_auth_interface_v10.md) | 声明用户认证驱动的API接口。 | 
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
| [AuthType](#authtype) : int {&nbsp;&nbsp;ALL = 0, PIN = 1, FACE = 2, FINGERPRINT = 4 } | 枚举用户认证凭据类型。 | 
| [ExecutorRole](#executorrole) : int { COLLECTOR = 1, VERIFIER = 2, ALL_IN_ONE = 3 } | 枚举执行器角色。 | 
| [ExecutorSecureLevel](#executorsecurelevel) : int { ESL0 = 0, ESL1 = 1, ESL2 = 2, ESL3 = 3 } | 枚举执行器安全等级。 | 
| [PinSubType](#pinsubtype) : int { PIN_SIX = 10000, PIN_NUMBER = 10001, PIN_MIX = 10002 } | 口令认证子类型。 | 
| [ScheduleMode](#schedulemode) : int { ENROLL = 0 , AUTH = 1 , IDENTIFY = 2 } | 调度模式。 | 


## 枚举类型说明


### AuthType

```
enum AuthType : int
```

**描述**


枚举用户认证凭据类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| ALL | 表示包含所有认证凭据类型。 | 
| PIN | 认证凭据类型为口令。 | 
| FACE | 认证凭据类型为人脸。 | 
| FINGERPRINT | 认证凭据类型为指纹。 | 


### ExecutorRole

```
enum ExecutorRole : int
```

**描述**


枚举执行器角色。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| COLLECTOR | 执行器角色为采集器，提供用户认证时的数据采集能力，需要和认证器配合完成用户认证。 | 
| VERIFIER | 执行器角色为认证器，提供用户认证时数据处理能力，读取存储凭据模板信息并完成比对。 | 
| ALL_IN_ONE | 执行器角色为全功能执行器，可提供用户认证数据采集、处理、储存及比对能力。 | 


### ExecutorSecureLevel

```
enum ExecutorSecureLevel : int
```

**描述**


枚举执行器安全等级。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| ESL0 | 执行器安全级别为0，关键操作在无访问控制执行环境中完成。 | 
| ESL1 | 执行器安全级别为1，关键操作在有访问控制的执行环境中完成。 | 
| ESL2 | 执行器安全级别为2，关键操作在可信执行环境中完成。 | 
| ESL3 | 执行器安全级别为3，关键操作在高安环境如独立安全芯片中完成。 | 


### PinSubType

```
enum PinSubType : int
```

**描述**


口令认证子类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| PIN_SIX | 六位口令密码。 | 
| PIN_NUMBER |数字口令密码。  | 
| PIN_MIX | 混合密码。 | 


### ScheduleMode

```
enum ScheduleMode : int
```

**描述**


调度模式。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| ENROLL | 录入模式。 | 
| AUTH | 认证模式。 | 
| IDENTIFY | 识别模式。 | 
