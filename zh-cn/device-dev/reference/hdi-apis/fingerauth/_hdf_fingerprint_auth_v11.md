# HdfFingerprintAuth (V1_1)


## 概述

提供指纹认证驱动的API接口。

指纹认证驱动程序为指纹认证服务提供统一的接口，用于访问指纹认证驱动程序。获取指纹认证驱动代理后，服务可以调用相关API获取执行器。 获取指纹认证执行器后，服务可以调用相关API获取执行器信息，获取凭据模板信息、注册指纹特征模板、进行用户指纹认证、删除指纹特征模板等。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [FingerprintAuthTypes.idl](_fingerprint_auth_types_8idl_v11.md) | 定义指纹认证驱动枚举和数据结构，包括认证类型、执行器角色、 执行器安全等级、命令ID、指纹提示信息编码、执行器信息和模板信息。 | 
| [IExecutor.idl](_i_executor_8idl_fingerauth_v11.md) | 定义执行器接口，用于获取执行器，获取凭据模版信息，注册指纹特征模版，进行用户指纹认证，删除指纹特征模版等。 | 
| [IFingerprintAuthInterface.idl](_i_fingerprint_auth_interface_8idl_v11.md) | 定义指纹认证驱动的执行器列表接口。此接口可用于获取驱动的执行器列表。 | 
| [ISaCommandCallback.idl](_i_sa_command_callback_8idl_fingerauth_v11.md) | 定义异步API接口回调，可以发送命令给SA。见[IExecutor](interface_i_executor_fingerauth_v11.md)。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[Property](_property_fingerauth_v11.md) | 执行器属性。 | 
| struct&nbsp;&nbsp;[SaCommandParamEnableSensorIllumination](_sa_command_param_enable_sensor_illumination_fingerauth_v11.md) | 光斑使能的sa命令参数。 | 
| struct&nbsp;&nbsp;[SaCommandParamNone](_sa_command_param_none_fingerauth_v11.md) | sa命令参数为空。 | 
| union&nbsp;&nbsp;[SaCommandParam](union_sa_command_param_fingerauth_v11.md) | sa命令参数。 | 
| struct&nbsp;&nbsp;[SaCommand](_sa_command_fingerauth_v11.md) | sa命令ID | 
| interface&nbsp;&nbsp;[IExecutor](interface_i_executor_fingerauth_v11.md) | 定义执行器接口，用于获取执行器，获取凭据模版信息，注册指纹特征模版，进行用户指纹认证，删除指纹特征模版等。 | 
| interface&nbsp;&nbsp;[IFingerprintAuthInterface](interface_i_fingerprint_auth_interface_v11.md) | 定义获取指纹认证驱动的执行器列表接口。 | 
| interface&nbsp;&nbsp;[ISaCommandCallback](interface_i_sa_command_callback_fingerauth_v11.md) | 定义异步API接口回调，可以发送命令给SA。见[IExecutor](interface_i_executor_fingerauth_v11.md)。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [FingerprintTipsCode](#fingerprinttipscode) : int {<br/>FINGERPRINT_AUTH_TIP_GOOD = 0 , FINGERPRINT_AUTH_TIP_DIRTY = 1 , FINGERPRINT_AUTH_TIP_INSUFFICIENT = 2 , FINGERPRINT_AUTH_TIP_PARTIAL = 3 ,<br/>FINGERPRINT_AUTH_TIP_TOO_FAST = 4 , FINGERPRINT_AUTH_TIP_TOO_SLOW = 5 ,<br/>FINGERPRINT_AUTH_TIP_FINGER_DOWN = 6 , FINGERPRINT_AUTH_TIP_FINGER_UP = 7 , VENDOR_FINGERPRINT_AUTH_TIP_BEGIN = 10000<br/>} | 枚举提示信息编码。 | 
| [GetPropertyType](#getpropertytype) : int {<br/>AUTH_SUB_TYPE = 1 , LOCKOUT_DURATION = 2 , REMAIN_ATTEMPTS = 3 , ENROLL_PROGRESS = 4 , SENSOR_INFO = 5<br/>} | 获取指纹执行器属性。 | 
| [SaCommandId](#sacommandid) : int { ENABLE_SENSOR_ILLUMINATION = 1 , DISABLE_SENSOR_ILLUMINATION = 2 , TURN_ON_SENSOR_ILLUMINATION = 3 , TURN_OFF_SENSOR_ILLUMINATION = 4 } | 枚举sa命令ID。 | 
| [CommandId](#commandid) : int { LOCK_TEMPLATE = 1 , UNLOCK_TEMPLATE = 2 , INIT_ALGORITHM = 3 , VENDOR_COMMAND_BEGIN = 10000 } | 枚举命令ID。 | 


## 枚举类型说明


### CommandId

```
enum CommandId : int
```

**描述**


枚举命令ID。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| LOCK_TEMPLATE | 指纹锁定的命令ID。 | 
| UNLOCK_TEMPLATE | 指纹解锁的命令ID。 | 
| INIT_ALGORITHM | 初始化算法的命令ID。 | 
| VENDOR_COMMAND_BEGIN | 用于厂商自定义提示信息。 | 


### FingerprintTipsCode

```
enum FingerprintTipsCode : int
```

**描述**


枚举提示信息编码。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| FINGERPRINT_AUTH_TIP_GOOD | 获取的指纹图像是完整的。 | 
| FINGERPRINT_AUTH_TIP_DIRTY | 指纹图像非常模糊，原因是传感器上存在可疑或检测到的污垢。 | 
| FINGERPRINT_AUTH_TIP_INSUFFICIENT | 仅检测到部分指纹图像。 | 
| FINGERPRINT_AUTH_TIP_PARTIAL | 仅检测到部分指纹图像。 | 
| FINGERPRINT_AUTH_TIP_TOO_FAST | 指纹图像由于快速移动而不完整。 | 
| FINGERPRINT_AUTH_TIP_TOO_SLOW | 指纹图像由于没有移动而无法读取。 | 
| FINGERPRINT_AUTH_TIP_FINGER_DOWN | 按下手指。 从4.0版本开始支持使用。 | 
| FINGERPRINT_AUTH_TIP_FINGER_UP | 抬起手指。 从4.0版本开始支持使用。 | 
| VENDOR_FINGERPRINT_AUTH_TIP_BEGIN | 用于厂商自定义提示信息。 | 


### GetPropertyType

```
enum GetPropertyType : int
```

**描述**


获取指纹执行器属性。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| AUTH_SUB_TYPE | 获取认证子类型。 | 
| LOCKOUT_DURATION | 获取指纹剩余锁定时间。 | 
| REMAIN_ATTEMPTS | 获取指纹剩余比对次数。 | 
| ENROLL_PROGRESS | 获取指纹录入进度。 | 
| SENSOR_INFO | 获取指纹光斑的信息。 | 


### SaCommandId

```
enum SaCommandId : int
```

**描述**


枚举sa命令ID。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| ENABLE_SENSOR_ILLUMINATION | 打开光斑功能。 | 
| DISABLE_SENSOR_ILLUMINATION | 关闭光斑功能。 | 
| TURN_ON_SENSOR_ILLUMINATION | 点亮光斑。 | 
| TURN_OFF_SENSOR_ILLUMINATION | 熄灭光斑。 | 
