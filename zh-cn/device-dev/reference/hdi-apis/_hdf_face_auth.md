# HdfFaceAuth


## **概述**

提供人脸认证驱动的标准API接口。

人脸认证驱动为人脸认证服务提供统一的访问接口。获取人脸认证驱动代理后，人脸认证服务可以调用相关接口获取执行器，获取人脸认证执行器后， 人脸认证服务可以调用相关接口获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。

**Since：**

3.2


## **汇总**


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [FaceAuthTypes.idl](_face_auth_types_8idl.md) | 定义人脸认证驱动的枚举类和数据结构。 | 
| [IExecutor.idl](face__auth_2_i_executor_8idl.md) | 定义执行器接口，用于获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。 | 
| [IExecutorCallback.idl](face__auth_2_i_executor_callback_8idl.md) | 定义异步API接口回调，用于返回异步接口的请求处理结果和信息。 | 
| [IFaceAuthInterface.idl](_i_face_auth_interface_8idl.md) | 定义获取人脸认证驱动的执行器列表接口，用于从人脸认证驱动获取执行器对象列表。 | 


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [ExecutorInfo](_executor_info.md) | 执行器信息。 | 
| [TemplateInfo](_template_info.md) | 凭据模版信息。 | 
| [IExecutor](interface_i_executor.md) | 定义执行器接口，用于获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。 | 
| [IExecutorCallback](interface_i_executor_callback.md) | 定义异步API接口回调，用于返回异步接口的请求处理结果和信息。使用细节见[IExecutor](interface_i_executor.md)。 | 
| [IFaceAuthInterface](interface_i_face_auth_interface.md) | 定义获取人脸认证驱动的执行器列表接口。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [AuthType](#authtype):&nbsp;int&nbsp;{&nbsp;PIN&nbsp;=&nbsp;1,&nbsp;FACE&nbsp;=&nbsp;2,&nbsp;FINGERPRINT&nbsp;=&nbsp;4&nbsp;} | 枚举用户认证凭据类型。 | 
| [ExecutorRole](#executorrole):&nbsp;int&nbsp;{&nbsp;COLLECTOR&nbsp;=&nbsp;1,&nbsp;VERIFIER&nbsp;=&nbsp;2,&nbsp;ALL_IN_ONE&nbsp;=&nbsp;3&nbsp;} | 枚举执行器角色。 | 
| [ExecutorSecureLevel](#executorsecurelevel):&nbsp;int&nbsp;{&nbsp;ESL0&nbsp;=&nbsp;0,&nbsp;ESL1&nbsp;=&nbsp;1,&nbsp;ESL2&nbsp;=&nbsp;2,&nbsp;ESL3&nbsp;=&nbsp;3&nbsp;} | 枚举执行器安全等级。 | 
| [CommandId](#commandid):&nbsp;int&nbsp;{&nbsp;LOCK_TEMPLATE&nbsp;=&nbsp;1,&nbsp;UNLOCK_TEMPLATE&nbsp;=&nbsp;2,&nbsp;VENDOR_COMMAND_BEGIN&nbsp;=&nbsp;10000&nbsp;} | 枚举人脸认证功能相关操作命令。 | 
| [FaceTipsCode](#facetipscode):&nbsp;int&nbsp;{&nbsp;FACE_AUTH_TIP_TOO_BRIGHT&nbsp;=&nbsp;1,&nbsp;FACE_AUTH_TIP_TOO_DARK&nbsp;=&nbsp;2,&nbsp;FACE_AUTH_TIP_TOO_CLOSE&nbsp;=&nbsp;3,&nbsp;FACE_AUTH_TIP_TOO_FAR&nbsp;=&nbsp;4,&nbsp;&nbsp;&nbsp;FACE_AUTH_TIP_TOO_HIGH&nbsp;=&nbsp;5,&nbsp;FACE_AUTH_TIP_TOO_LOW&nbsp;=&nbsp;6,&nbsp;FACE_AUTH_TIP_TOO_RIGHT&nbsp;=&nbsp;7,&nbsp;FACE_AUTH_TIP_TOO_LEFT&nbsp;=&nbsp;8,&nbsp;&nbsp;&nbsp;FACE_AUTH_TIP_TOO_MUCH_MOTION&nbsp;=&nbsp;9,&nbsp;FACE_AUTH_TIP_POOR_GAZE&nbsp;=&nbsp;10,&nbsp;FACE_AUTH_TIP_NOT_DETECTED&nbsp;=&nbsp;11,&nbsp;VENDOR_FACE_AUTH_TIP_BEGIN&nbsp;=&nbsp;10000&nbsp;} | 枚举提示信息编码。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.face_auth.v1_0 | 人脸认证接口的包路径 | 


## **枚举类型说明**


### AuthType

  
```
enum AuthType : int
```

**描述：**

枚举用户认证凭据类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PIN | 认证凭据类型为口令。 | 
| FACE | 认证凭据类型为人脸。 | 
| FINGERPRINT | 认证凭据类型为指纹。 | 


### CommandId

  
```
enum CommandId : int
```

**描述：**

枚举人脸认证功能相关操作命令。

  | 枚举值 | 描述 | 
| -------- | -------- |
| LOCK_TEMPLATE | 锁定人脸模版。 | 
| UNLOCK_TEMPLATE | 解锁人脸模版。 | 
| VENDOR_COMMAND_BEGIN | 用于厂商自定义操作指令。 | 


### ExecutorRole

  
```
enum ExecutorRole : int
```

**描述：**

枚举执行器角色。

  | 枚举值 | 描述 | 
| -------- | -------- |
| COLLECTOR | 执行器角色为采集器，提供用户认证时的数据采集能力，需要和认证器配合完成用户认证。 | 
| VERIFIER | 执行器角色为认证器，提供用户认证时数据处理能力，读取存储凭据模板信息并完成比对。 | 
| ALL_IN_ONE | 执行器角色为全功能执行器，可提供用户认证数据采集、处理、储存及比对能力。 | 


### ExecutorSecureLevel

  
```
enum ExecutorSecureLevel : int
```

**描述：**

枚举执行器安全等级。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ESL0 | 执行器安全级别为0，关键操作在无访问控制执行环境中完成。 | 
| ESL1 | 执行器安全级别为1，关键操作在有访问控制的执行环境中完成。 | 
| ESL2 | 执行器安全级别为2，关键操作在可信执行环境中完成。 | 
| ESL3 | 执行器安全级别为3，关键操作在高安环境如独立安全芯片中完成。 | 


### FaceTipsCode

  
```
enum FaceTipsCode : int
```

**描述：**

枚举提示信息编码。

  | 枚举值 | 描述 | 
| -------- | -------- |
| FACE_AUTH_TIP_TOO_BRIGHT | 获取的人脸图像由于光照度高而过亮。 | 
| FACE_AUTH_TIP_TOO_DARK | 获取的人脸图像由于光照度低而过暗。 | 
| FACE_AUTH_TIP_TOO_CLOSE | 人脸离设备过近。 | 
| FACE_AUTH_TIP_TOO_FAR | 人脸离设备过远。 | 
| FACE_AUTH_TIP_TOO_HIGH | 设备过高，只拍到人脸的上半部分。 | 
| FACE_AUTH_TIP_TOO_LOW | 设备过低，只拍到人脸的下半部分。 | 
| FACE_AUTH_TIP_TOO_RIGHT | 设备偏右，只拍到人脸的右侧部分。 | 
| FACE_AUTH_TIP_TOO_LEFT | 设备偏左，只拍到人脸的左侧部分。 | 
| FACE_AUTH_TIP_TOO_MUCH_MOTION | 人脸信息采集过程中，人脸移动过多。 | 
| FACE_AUTH_TIP_POOR_GAZE | 用户未注视设备。 | 
| FACE_AUTH_TIP_NOT_DETECTED | 未检测到人脸。 | 
| VENDOR_FACE_AUTH_TIP_BEGIN | 用于厂商自定义提示信息。 | 
