# HdfFingerprintAuth (V1_0)


## 概述

提供指纹认证驱动的API接口。

指纹认证驱动程序为指纹认证服务提供统一的接口，用于访问指纹认证驱动程序。获取指纹认证驱动代理后，服务可以调用相关API获取执行器。 获取指纹认证执行器后，服务可以调用相关API获取执行器信息，获取凭据模板信息、注册指纹特征模板、进行用户指纹认证、删除指纹特征模板等。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [FingerprintAuthTypes.idl](_fingerprint_auth_types_8idl_v10.md) | 定义指纹认证驱动枚举和数据结构，包括认证类型、执行器角色、 执行器安全等级、命令ID、指纹提示信息编码、执行器信息和模板信息。 | 
| [IExecutor.idl](_i_executor_8idl_fingerauth_v10.md) | 定义执行器接口，用于获取执行器，获取凭据模版信息，注册指纹特征模版，进行用户指纹认证，删除指纹特征模版等。 | 
| [IExecutorCallback.idl](_i_executor_callback_8idl_fingerauth_v10.md) | 定义异步API接口回调，用于返回异步接口的请求处理结果和信息。 | 
| [IFingerprintAuthInterface.idl](_i_fingerprint_auth_interface_8idl_v10.md) | 定义指纹认证驱动的执行器列表接口。此接口可用于获取驱动的执行器列表。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ExecutorInfo](_executor_info_fingerauth_v10.md) | 执行器信息。 | 
| struct&nbsp;&nbsp;[TemplateInfo](_template_info_fingerauth_v10.md) | 凭据模板信息。 | 
| interface&nbsp;&nbsp;[IExecutor](interface_i_executor_fingerauth_v10.md) | 定义执行器接口，用于获取执行器，获取凭据模版信息，注册指纹特征模版，进行用户指纹认证，删除指纹特征模版等。 | 
| interface&nbsp;&nbsp;[IExecutorCallback](interface_i_executor_callback_fingerauth_v10.md) | 定义异步API接口回调。当执行器使用者调用异步函数时该回调需要被注册。使用细节见[IExecutor](interface_i_executor_fingerauth_v10.md)。 | 
| interface&nbsp;&nbsp;[IFingerprintAuthInterface](interface_i_fingerprint_auth_interface_v10.md) | 定义获取指纹认证驱动的执行器列表接口。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AuthType](#authtype) : int { PIN = 1 , FACE = 2 , FINGERPRINT = 4 } | 枚举用户认证的凭据类型。 | 
| [ExecutorRole](#executorrole) : int { COLLECTOR = 1 , VERIFIER = 2 , ALL_IN_ONE = 3 } | 枚举执行器角色。 | 
| [ExecutorSecureLevel](#executorsecurelevel) : int { ESL0 = 0 , ESL1 = 1 , ESL2 = 2 , ESL3 = 3 } | 枚举执行器安全等级。 | 
| [CommandId](#commandid) : int { LOCK_TEMPLATE = 1 , UNLOCK_TEMPLATE = 2 , VENDOR_COMMAND_BEGIN = 10000 } | 枚举指纹认证功能相关操作命令。 | 
| [FingerprintTipsCode](#fingerprinttipscode) : int {<br/>FINGERPRINT_AUTH_TIP_GOOD = 0 , FINGERPRINT_AUTH_TIP_DIRTY = 1 , FINGERPRINT_AUTH_TIP_INSUFFICIENT = 2 , FINGERPRINT_AUTH_TIP_PARTIAL = 3 ,<br/>FINGERPRINT_AUTH_TIP_TOO_FAST = 4 , FINGERPRINT_AUTH_TIP_TOO_SLOW = 5 , VENDOR_FINGERPRINT_AUTH_TIP_BEGIN = 10000<br/>} | 枚举提示信息编码。 | 


## 枚举类型说明


### AuthType

```
enum AuthType : int
```

**描述**


枚举用户认证的凭据类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| PIN | 认证凭据类型为口令。 | 
| FACE | 认证凭据类型为人脸。 | 
| FINGERPRINT | 认证凭据类型为指纹。 | 


### CommandId

```
enum CommandId : int
```

**描述**


枚举指纹认证功能相关操作命令。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| LOCK_TEMPLATE | 锁定指纹模板。 | 
| UNLOCK_TEMPLATE | 解锁指纹模板。 | 
| VENDOR_COMMAND_BEGIN | 用于厂商自定义操作指令。 | 


### ExecutorRole

```
enum ExecutorRole : int
```

**描述**


枚举执行器角色。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| COLLECTOR | 表示执行器角色是采集器，提供用户认证时的数据采集能力，需要和认证器配合完成用户认证。 | 
| VERIFIER | 表示执行器角色是认证器，提供用户认证时数据处理能力，读取存储凭据模板信息并完成比对。 | 
| ALL_IN_ONE | 表示执行器角色是全功能执行器，可提供用户认证数据采集、处理、储存及比对能力。 | 


### ExecutorSecureLevel

```
enum ExecutorSecureLevel : int
```

**描述**


枚举执行器安全等级。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| ESL0 | 表示执行器安全等级是0，关键操作在无访问控制执行环境中完成。 | 
| ESL1 | 表示执行器安全等级是1，关键操作在有访问控制的执行环境中完成。 | 
| ESL2 | 表示执行器安全等级是2，关键操作在可信执行环境中完成。 | 
| ESL3 | 表示执行器安全等级是3，关键操作在高安环境如独立安全芯片中完成。 | 


### FingerprintTipsCode

```
enum FingerprintTipsCode : int
```

**描述**


枚举提示信息编码。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| FINGERPRINT_AUTH_TIP_GOOD | 获取的指纹图像是完整的。 | 
| FINGERPRINT_AUTH_TIP_DIRTY | 指纹图像非常模糊，原因是传感器上存在可疑或检测到的污垢。 | 
| FINGERPRINT_AUTH_TIP_INSUFFICIENT | 仅检测到部分指纹图像。 | 
| FINGERPRINT_AUTH_TIP_PARTIAL | 仅检测到部分指纹图像。 | 
| FINGERPRINT_AUTH_TIP_TOO_FAST | 指纹图像由于快速移动而不完整。 | 
| FINGERPRINT_AUTH_TIP_TOO_SLOW | 指纹图像由于没有移动而无法读取。 | 
| VENDOR_FINGERPRINT_AUTH_TIP_BEGIN | 用于厂商自定义提示信息。 | 
