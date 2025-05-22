# IUserAuthInterface


## 概述

声明用户认证驱动的API接口。

**起始版本：** 4.0

**相关模块：**[HdfUserAuth](_hdf_user_auth_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [BeginEnrollmentV1_1](#beginenrollmentv1_1) ([in] int userId, [in] unsigned char[] authToken, [in] struct EnrollParam param, [out] struct [ScheduleInfoV1_1](_schedule_info_v1__1_v11.md) info) | 开始注册用户认证凭据。当注册凭据类型为口令且该用户已经注册了口令凭据时，将会更新口令凭据。 | 
| [BeginAuthenticationV1_1](#beginauthenticationv1_1) ([in] unsigned long contextId, [in] struct AuthSolution param, [out] struct [ScheduleInfoV1_1](_schedule_info_v1__1_v11.md)[] scheduleInfos) | 开始认证用户，并生成认证方案。 | 
| [BeginIdentificationV1_1](#beginidentificationv1_1) ([in] unsigned long contextId, [in] enum AuthType authType, [in] unsigned char[] challenge, [in] unsigned int executorSensorHint, [out] struct [ScheduleInfoV1_1](_schedule_info_v1__1_v11.md) scheduleInfo) | 开始用户身份识别，并生成识别方案。 | 
| [GetAllUserInfo](#getalluserinfo) ([out] [UserInfo](_user_info_v11.md)[] userInfos) | 获取所有用户信息. | 


## 成员函数说明


### BeginAuthenticationV1_1()

```
IUserAuthInterface::BeginAuthenticationV1_1 ([in] unsigned long contextId, [in] struct AuthSolution param, [out] struct ScheduleInfoV1_1[] scheduleInfos )
```

**描述**


开始认证用户，并生成认证方案。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| contextId | 上下文索引。 | 
| param | 认证方案[AuthSolution](_auth_solution_v10.md)。 | 
| scheduleInfos | 调度信息[ScheduleInfoV1_1](_schedule_info_v1__1_v11.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### BeginEnrollmentV1_1()

```
IUserAuthInterface::BeginEnrollmentV1_1 ([in] int userId, [in] unsigned char[] authToken, [in] struct EnrollParam param, [out] struct ScheduleInfoV1_1 info )
```

**描述**


开始注册用户认证凭据。当注册凭据类型为口令且该用户已经注册了口令凭据时，将会更新口令凭据。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| authToken | 用户口令认证令牌。 | 
| param | 注册凭据参数[EnrollParam](_enroll_param_v10.md)。 | 
| info | 调度信息[ScheduleInfoV1_1](_schedule_info_v1__1_v11.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### BeginIdentificationV1_1()

```
IUserAuthInterface::BeginIdentificationV1_1 ([in] unsigned long contextId, [in] enum AuthType authType, [in] unsigned char[] challenge, [in] unsigned int executorSensorHint, [out] struct ScheduleInfoV1_1 scheduleInfo )
```

**描述**


开始用户身份识别，并生成识别方案。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| contextId | 上下文索引。 | 
| authType | 用户身份识别类型AuthType}。 | 
| challenge | 随机挑战值，用于生成用户身份识别令牌，防止重放。 | 
| executorSensorHint | 执行器传感器提示，用于找到对应认证方式的传感器，值为0时表示没有指定传感器。 | 
| scheduleInfo | 调度信息[ScheduleInfoV1_1](_schedule_info_v1__1_v11.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetAllUserInfo()

```
IUserAuthInterface::GetAllUserInfo ([out] UserInfo[] userInfos)
```

**描述**


获取所有用户信息.

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userInfos | 用户信息列表[UserInfo](_user_info_v11.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
