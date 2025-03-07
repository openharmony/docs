# IUserAuthInterface


## 概述

声明用户认证驱动的API接口。

**起始版本：** 4.1

**相关模块：**[HdfUserAuth](_hdf_user_auth_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [Init](#init) () | 初始化用户认证驱动缓存信息，用于用户认证框架进程启动时初始化信息。 | 
| [AddExecutor](#addexecutor) ([in] struct [ExecutorRegisterInfo](_executor_register_info_v12.md) info, [out] unsigned long index, [out] unsigned char[] publicKey, [out] unsigned long[] templateIds) | 添加认证执行器来获取认证能力，用于各认证基础服务如口令认证服务等将认证能力对接到用户认证框架。 | 
| [DeleteExecutor](#deleteexecutor) ([in] unsigned long index) | 删除执行器，用于清理失效的执行器信息。 | 
| [OpenSession](#opensession) ([in] int userId, [out] unsigned char[] challenge) | 开启一个认证凭据管理会话，用于在请求管理用户认证凭据前获取有效挑战值。 | 
| [CloseSession](#closesession) ([in] int userId) | 关闭认证凭据管理会话，完成用户认证凭据管理请求处理后，调用该接口使原挑战值失效。 | 
| [BeginEnrollment](#beginenrollment) ([in] int userId, [in] unsigned char[] authToken, [in] struct [EnrollParam](_enroll_param_v12.md) param, [out] struct [ScheduleInfo](_schedule_info_v12.md) info) | 开始注册用户认证凭据。当注册凭据类型为口令且该用户已经注册了口令凭据时，将会更新口令凭据。 | 
| [UpdateEnrollmentResult](#updateenrollmentresult) ([in] int userId, [in] unsigned char[] scheduleResult, [out] struct [EnrollResultInfo](_enroll_result_info_v12.md) info) | 更新用户凭据注册结果，完成凭据注册。 | 
| [CancelEnrollment](#cancelenrollment) ([in] int userId) | 取消注册请求。 | 
| [DeleteCredential](#deletecredential) ([in] int userId, [in] unsigned long credentialId, [in] unsigned char[] authToken, [out] struct [CredentialInfo](_credential_info_v12.md) info) | 删除用户凭据信息。 | 
| [GetCredential](#getcredential) ([in] int userId, [in] enum [AuthType](_hdf_user_auth_v12.md#authtype) authType, [out] struct [CredentialInfo](_credential_info_v12.md)[] infos) | 查询用户凭据信息。 | 
| [GetUserInfo](#getuserinfo) ([in] int userId, [out] unsigned long secureUid, [out] enum [PinSubType](_hdf_user_auth_v12.md#pinsubtype) pinSubType, [out] struct [EnrolledInfo](_enrolled_info_v12.md)[] infos) | 查询用户认证相关信息。 | 
| [DeleteUser](#deleteuser) ([in] int userId, [in] unsigned char[] authToken, [out] struct [CredentialInfo](_credential_info_v12.md)[] deletedInfos) | 删除用户口令认证凭据，在用户IAM系统内删除该用户，该请求由用户触发。 | 
| [EnforceDeleteUser](#enforcedeleteuser) ([in] int userId, [out] struct [CredentialInfo](_credential_info_v12.md)[] deletedInfos) | 强制删除用户，该请求由系统内管理用户的模块触发。 | 
| [BeginAuthentication](#beginauthentication) ([in] unsigned long contextId, [in] struct [AuthSolution](_auth_solution_v12.md) param, [out] struct [ScheduleInfo](_schedule_info_v12.md)[] scheduleInfos) | 开始认证用户，并生成认证方案。 | 
| [UpdateAuthenticationResult](#updateauthenticationresult) ([in] unsigned long contextId, [in] unsigned char[] scheduleResult, [out] struct [AuthResultInfo](_auth_result_info_v12.md) info) | 更新认证结果，评估认证方案的认证结果。 | 
| [CancelAuthentication](#cancelauthentication) ([in] unsigned long contextId) | 取消用户认证请求。 | 
| [BeginIdentification](#beginidentification) ([in] unsigned long contextId, [in] enum [AuthType](_hdf_user_auth_v12.md#authtype) authType, [in] unsigned char[] challenge, [in] unsigned int executorSensorHint, [out] struct [ScheduleInfo](_schedule_info_v12.md) scheduleInfo) | 开始用户身份识别，并生成识别方案。 | 
| [UpdateIdentificationResult](#updateidentificationresult) ([in] unsigned long contextId, [in] unsigned char[] scheduleResult, [out] struct [IdentifyResultInfo](_identify_result_info_v12.md) info) | 更新用户身份识别结果，生成身份识别方案的结果。 | 
| [CancelIdentification](#cancelidentification) ([in] unsigned long contextId) | 取消用户身份识别请求。 | 
| [GetAuthTrustLevel](#getauthtrustlevel) ([in] int userId, [in] enum [AuthType](_hdf_user_auth_v12.md#authtype) authType, [out] unsigned int authTrustLevel) | 获取当前认证类型的认证结果可信等级。 | 
| [GetValidSolution](#getvalidsolution) ([in] int userId, [in] enum [AuthType](_hdf_user_auth_v12.md#authtype)[] authTypes, [in] unsigned int authTrustLevel, [out] enum [AuthType](_hdf_user_auth_v12.md#authtype)[] validTypes) | 获取指定认证结果可信等级下有效的认证方式。 | 
| [BeginEnrollmentV1_1](#beginenrollmentv1_1) ([in] int userId, [in] unsigned char[] authToken, [in] struct [EnrollParam](_enroll_param_v12.md) param, [out] struct [ScheduleInfoV1_1](_schedule_info_v1__1_v12.md) info) | 开始注册用户认证凭据。当注册凭据类型为口令且该用户已经注册了口令凭据时，将会更新口令凭据。 | 
| [BeginAuthenticationV1_1](#beginauthenticationv1_1) ([in] unsigned long contextId, [in] struct [AuthSolution](_auth_solution_v12.md) param, [out] struct [ScheduleInfoV1_1](_schedule_info_v1__1_v12.md)[] scheduleInfos) | 开始认证用户，并生成认证方案。 | 
| [BeginIdentificationV1_1](#beginidentificationv1_1) ([in] unsigned long contextId, [in] enum [AuthType](_hdf_user_auth_v12.md#authtype) authType, [in] unsigned char[] challenge, [in] unsigned int executorSensorHint, [out] struct [ScheduleInfoV1_1](_schedule_info_v1__1_v12.md) scheduleInfo) | 开始用户身份识别，并生成识别方案。 | 
| [GetAllUserInfo](#getalluserinfo) ([out] [UserInfo](_user_info_v12.md)[] userInfos) | 获取所有用户信息。 | 
| [GetAllExtUserInfo](#getallextuserinfo) ([out] [ExtUserInfo](_ext_user_info_v12.md)[] userInfos) | 获取所有用户信息。 | 
| [BeginAuthenticationV1_2](#beginauthenticationv1_2) ([in] unsigned long contextId, [in] struct [AuthSolutionV1_2](_auth_solution_v1__2_v12.md) param, [out] struct [ScheduleInfoV1_1](_schedule_info_v1__1_v12.md)[] scheduleInfos) | 开始认证用户，并生成认证方案。 | 
| [BeginEnrollmentV1_2](#beginenrollmentv1_2) ([in] int userId, [in] unsigned char[] authToken, [in] struct [EnrollParamV1_2](_enroll_param_v1__2_v12.md) param, [out] struct [ScheduleInfoV1_1](_schedule_info_v1__1_v12.md) info) | 开始注册用户认证凭据。当注册凭据类型为口令且该用户已经注册了口令凭据时，将会更新口令凭据。 | 


## 成员函数说明


### AddExecutor()

```
IUserAuthInterface::AddExecutor ([in] struct ExecutorRegisterInfo info, [out] unsigned long index, [out] unsigned char[] publicKey, [out] unsigned long[] templateIds )
```

**描述**


添加认证执行器来获取认证能力，用于各认证基础服务如口令认证服务等将认证能力对接到用户认证框架。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 执行器注册信息[ExecutorRegisterInfo](_executor_register_info_v12.md)。 | 
| index | 用户认证框架的执行器索引。 | 
| publicKey | 用户认证框架公钥。 | 
| templateIds | 该执行器已注册的模版ID列表。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### BeginAuthentication()

```
IUserAuthInterface::BeginAuthentication ([in] unsigned long contextId, [in] struct AuthSolution param, [out] struct ScheduleInfo[] scheduleInfos )
```

**描述**


开始认证用户，并生成认证方案。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| contextId | 上下文索引。 | 
| param | 认证方案[AuthSolution](_auth_solution_v12.md)。 | 
| scheduleInfos | 调度信息[ScheduleInfo](_schedule_info_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


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
| param | 认证方案[AuthSolution](_auth_solution_v12.md)。 | 
| scheduleInfos | 调度信息[ScheduleInfoV1_1](_schedule_info_v1__1_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### BeginAuthenticationV1_2()

```
IUserAuthInterface::BeginAuthenticationV1_2 ([in] unsigned long contextId, [in] struct AuthSolutionV1_2 param, [out] struct ScheduleInfoV1_1[] scheduleInfos )
```

**描述**


开始认证用户，并生成认证方案。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| contextId | 上下文索引。 | 
| param | 认证方案[AuthSolutionV1_2](_auth_solution_v1__2_v12.md)。 | 
| scheduleInfos | 调度信息[ScheduleInfoV1_1](_schedule_info_v1__1_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### BeginEnrollment()

```
IUserAuthInterface::BeginEnrollment ([in] int userId, [in] unsigned char[] authToken, [in] struct EnrollParam param, [out] struct ScheduleInfo info )
```

**描述**


开始注册用户认证凭据。当注册凭据类型为口令且该用户已经注册了口令凭据时，将会更新口令凭据。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| authToken | 用户口令认证令牌。 | 
| param | 注册凭据参数[EnrollParam](_enroll_param_v12.md)。 | 
| info | 调度信息[ScheduleInfo](_schedule_info_v12.md)。 | 

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
| param | 注册凭据参数[EnrollParam](_enroll_param_v12.md)。 | 
| info | 调度信息[ScheduleInfoV1_1](_schedule_info_v1__1_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### BeginEnrollmentV1_2()

```
IUserAuthInterface::BeginEnrollmentV1_2 ([in] int userId, [in] unsigned char[] authToken, [in] struct EnrollParamV1_2 param, [out] struct ScheduleInfoV1_1 info )
```

**描述**


开始注册用户认证凭据。当注册凭据类型为口令且该用户已经注册了口令凭据时，将会更新口令凭据。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| authToken | 用户口令认证令牌。 | 
| param | 注册凭据参数[EnrollParamV1_2](_enroll_param_v1__2_v12.md)。 | 
| info | 调度信息[ScheduleInfoV1_1](_schedule_info_v1__1_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### BeginIdentification()

```
IUserAuthInterface::BeginIdentification ([in] unsigned long contextId, [in] enum AuthType authType, [in] unsigned char[] challenge, [in] unsigned int executorSensorHint, [out] struct ScheduleInfo scheduleInfo )
```

**描述**


开始用户身份识别，并生成识别方案。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| contextId | 上下文索引。 | 
| authType | 用户身份识别类型[AuthType](_hdf_user_auth_v12.md#authtype)。 | 
| challenge | 随机挑战值，用于生成用户身份识别令牌，防止重放。 | 
| executorSensorHint | 执行器传感器提示，用于找到对应认证方式的传感器。 | 
| scheduleInfo | 调度信息[ScheduleInfo](_schedule_info_v12.md)。 | 

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
| authType | 用户身份识别类型[AuthType](_hdf_user_auth_v12.md#authtype)。 | 
| challenge | 随机挑战值，用于生成用户身份识别令牌，防止重放。 | 
| executorSensorHint | 执行器传感器提示，用于找到对应认证方式的传感器，取值不为0。 | 
| scheduleInfo | 调度信息[ScheduleInfoV1_1](_schedule_info_v1__1_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### CancelAuthentication()

```
IUserAuthInterface::CancelAuthentication ([in] unsigned long contextId)
```

**描述**


取消用户认证请求。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| contextId | 上下文索引。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### CancelEnrollment()

```
IUserAuthInterface::CancelEnrollment ([in] int userId)
```

**描述**


取消注册请求。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### CancelIdentification()

```
IUserAuthInterface::CancelIdentification ([in] unsigned long contextId)
```

**描述**


取消用户身份识别请求。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| contextId | 上下文索引。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### CloseSession()

```
IUserAuthInterface::CloseSession ([in] int userId)
```

**描述**


关闭认证凭据管理会话，完成用户认证凭据管理请求处理后，调用该接口使原挑战值失效。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### DeleteCredential()

```
IUserAuthInterface::DeleteCredential ([in] int userId, [in] unsigned long credentialId, [in] unsigned char[] authToken, [out] struct CredentialInfo info )
```

**描述**


删除用户凭据信息。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| credentialId | 凭据ID。 | 
| authToken | 用户口令认证令牌。 | 
| info | 删除的凭据信息[CredentialInfo](_credential_info_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### DeleteExecutor()

```
IUserAuthInterface::DeleteExecutor ([in] unsigned long index)
```

**描述**


删除执行器，用于清理失效的执行器信息。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| index | 用户认证框架的执行器索引。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### DeleteUser()

```
IUserAuthInterface::DeleteUser ([in] int userId, [in] unsigned char[] authToken, [out] struct CredentialInfo[] deletedInfos )
```

**描述**


删除用户口令认证凭据，在用户IAM系统内删除该用户，该请求由用户触发。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| authToken | 用户口令认证令牌。 | 
| deletedInfos | 删除的凭据信息[CredentialInfo](_credential_info_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### EnforceDeleteUser()

```
IUserAuthInterface::EnforceDeleteUser ([in] int userId, [out] struct CredentialInfo[] deletedInfos )
```

**描述**


强制删除用户，该请求由系统内管理用户的模块触发。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| deletedInfos | 删除的凭据信息[CredentialInfo](_credential_info_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetAllExtUserInfo()

```
IUserAuthInterface::GetAllExtUserInfo ([out] ExtUserInfo[] userInfos)
```

**描述**


获取所有用户信息。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userInfos | 用户信息列表[ExtUserInfo](_ext_user_info_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetAllUserInfo()

```
IUserAuthInterface::GetAllUserInfo ([out] UserInfo[] userInfos)
```

**描述**


获取所有用户信息。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userInfos | 用户信息列表[UserInfo](_user_info_v12.md)}。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetAuthTrustLevel()

```
IUserAuthInterface::GetAuthTrustLevel ([in] int userId, [in] enum AuthType authType, [out] unsigned int authTrustLevel )
```

**描述**


获取当前认证类型的认证结果可信等级。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| authType | 认证类型[AuthType](_hdf_user_auth_v12.md#authtype)。 | 
| authTrustLevel | 认证结果可信等级。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetCredential()

```
IUserAuthInterface::GetCredential ([in] int userId, [in] enum AuthType authType, [out] struct CredentialInfo[] infos )
```

**描述**


查询用户凭据信息。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| authType | 凭据类型[AuthType](_hdf_user_auth_v12.md#authtype)。 | 
| infos | 凭据信息[CredentialInfo](_credential_info_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetUserInfo()

```
IUserAuthInterface::GetUserInfo ([in] int userId, [out] unsigned long secureUid, [out] enum PinSubType pinSubType, [out] struct EnrolledInfo[] infos )
```

**描述**


查询用户认证相关信息。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| secureUid | 安全用户ID。 | 
| pinSubType | 口令认证子类型[PinSubType](_hdf_user_auth_v12.md#pinsubtype)。 | 
| infos | 注册信息[EnrolledInfo](_enrolled_info_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetValidSolution()

```
IUserAuthInterface::GetValidSolution ([in] int userId, [in] enum AuthType[] authTypes, [in] unsigned int authTrustLevel, [out] enum AuthType[] validTypes )
```

**描述**


获取指定认证结果可信等级下有效的认证方式。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| authTypes | 用于筛选的认证方式列表[AuthType](_hdf_user_auth_v12.md#authtype)。 | 
| authTrustLevel | 认证结果可信等级。 | 
| validTypes | 有效的认证方式列表[AuthType](_hdf_user_auth_v12.md#authtype)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### Init()

```
IUserAuthInterface::Init ()
```

**描述**


初始化用户认证驱动缓存信息，用于用户认证框架进程启动时初始化信息。

**返回：**

0 表示操作成功。

非0 表示操作失败。


### OpenSession()

```
IUserAuthInterface::OpenSession ([in] int userId, [out] unsigned char[] challenge )
```

**描述**


开启一个认证凭据管理会话，用于在请求管理用户认证凭据前获取有效挑战值。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| challenge | 随机挑战值，用于生成用户身份认证令牌。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### UpdateAuthenticationResult()

```
IUserAuthInterface::UpdateAuthenticationResult ([in] unsigned long contextId, [in] unsigned char[] scheduleResult, [out] struct AuthResultInfo info )
```

**描述**


更新认证结果，评估认证方案的认证结果。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| contextId | 上下文索引。 | 
| scheduleResult | 执行器签发的认证结果。 | 
| info | 认证结果信息[AuthResultInfo](_auth_result_info_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### UpdateEnrollmentResult()

```
IUserAuthInterface::UpdateEnrollmentResult ([in] int userId, [in] unsigned char[] scheduleResult, [out] struct EnrollResultInfo info )
```

**描述**


更新用户凭据注册结果，完成凭据注册。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userId | 用户ID。 | 
| scheduleResult | 执行器签发的注册结果。 | 
| info | 录入结果信息[EnrollResultInfo](_enroll_result_info_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### UpdateIdentificationResult()

```
IUserAuthInterface::UpdateIdentificationResult ([in] unsigned long contextId, [in] unsigned char[] scheduleResult, [out] struct IdentifyResultInfo info )
```

**描述**


更新用户身份识别结果，生成身份识别方案的结果。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| contextId | 上下文索引。 | 
| scheduleResult | 执行器签发的用户身份识别结果。 | 
| info | 用户身份识别结果[IdentifyResultInfo](_identify_result_info_v12.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
