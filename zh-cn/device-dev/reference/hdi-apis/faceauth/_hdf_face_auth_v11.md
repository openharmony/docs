# HdfFaceAuth (V1_1)


## 概述

提供人脸认证驱动的标准API接口。

人脸认证驱动为人脸认证服务提供统一的访问接口。获取人脸认证驱动代理后，人脸认证服务可以调用相关接口获取执行器，获取人脸认证执行器后， 人脸认证服务可以调用相关接口获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [FaceAuthTypes.idl](_face_auth_types_8idl_v11.md) | 定义人脸认证驱动的枚举类和数据结构，包括AuthType, ExecutorRole, ExecutorSecureLevel, CommandId, FaceTipsCode, ExecutorInfo, 和TemplateInfo。 | 
| [IExecutor.idl](_i_executor_8idl_faceauth_v11.md) | 定义执行器接口，用于获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。 | 
| [IFaceAuthInterface.idl](_i_face_auth_interface_8idl_v11.md) | 定义获取人脸认证驱动的执行器列表接口，用于从人脸认证驱动获取执行器对象列表。 | 
| [ISaCommandCallback.idl](_i_sa_command_callback_8idl_faceauth_v11.md) | 定义异步 API 的回调，该回调可用于向 SA 发送命令。详细说明请参考[IExecutor](interface_i_executor_faceauth_v11.md). | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[Property](_property_faceauth_v11.md) | 执行器相关属性。 | 
| struct&nbsp;&nbsp;[SaCommandParamNone](_sa_command_param_none_faceauth_v11.md) | sa命令参数为空。 | 
| union&nbsp;&nbsp;[SaCommandParam](union_sa_command_param_faceauth_v11.md) | sa命令参数。 | 
| struct&nbsp;&nbsp;[SaCommand](_sa_command_faceauth_v11.md) | SA命令相关。 | 
| interface&nbsp;&nbsp;[IExecutor](interface_i_executor_faceauth_v11.md) | 定义执行器接口，用于获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。 | 
| interface&nbsp;&nbsp;[IFaceAuthInterface](interface_i_face_auth_interface_v11.md) | 定义获取人脸认证驱动执行器列表的接口。 | 
| interface&nbsp;&nbsp;[ISaCommandCallback](interface_i_sa_command_callback_faceauth_v11.md) | 定义异步 API 的回调，该回调可用于向 SA 发送命令。详细说明请参考[IExecutor](interface_i_executor_faceauth_v11.md). | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [GetPropertyType](#getpropertytype) : int {<br/>AUTH_SUB_TYPE = 1 , LOCKOUT_DURATION = 2 , REMAIN_ATTEMPTS = 3 , ENROLL_PROGRESS = 4 ,<br/>SENSOR_INFO = 5<br/>} | 枚举获得属性类型。 | 
| [SaCommandId](#sacommandid) : int { BEGIN_SCREEN_BRIGHTNESS_INCREASE = 1 , END_SCREEN_BRIGHTNESS_INCREASE = 2 } | 枚举sa命令id。 | 
| [CommandId](#commandid) : int { LOCK_TEMPLATE = 1 , UNLOCK_TEMPLATE = 2 , INIT_ALGORITHM = 3 , VENDOR_COMMAND_BEGIN = 10000 } | 枚举人脸认证功能相关操作命令。 | 


## 枚举类型说明


### CommandId

```
enum CommandId : int
```

**描述**


枚举人脸认证功能相关操作命令。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| LOCK_TEMPLATE | 锁定人脸模版。 | 
| UNLOCK_TEMPLATE | 解锁人脸模版。 | 
| INIT_ALGORITHM | 初始化算法。 | 
| VENDOR_COMMAND_BEGIN | 用于厂商自定义操作指令。 | 


### GetPropertyType

```
enum GetPropertyType : int
```

**描述**


枚举获得属性类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUTH_SUB_TYPE | 人脸认证子类型。 | 
| LOCKOUT_DURATION | 认证方式被冻结的时间。 | 
| REMAIN_ATTEMPTS | 认证方式距离被冻结的可处理认证请求次数。 | 
| ENROLL_PROGRESS | 人脸录入进程。 | 
| SENSOR_INFO | 传感器信息。 | 


### SaCommandId

```
enum SaCommandId : int
```

**描述**


枚举sa命令id。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| BEGIN_SCREEN_BRIGHTNESS_INCREASE | 开始增加屏幕亮度 | 
| END_SCREEN_BRIGHTNESS_INCREASE | 结束增加屏幕亮度 | 
