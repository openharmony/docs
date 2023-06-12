# IExecutor


## 概述

定义执行器接口，用于获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[HdfFaceAuth](_hdf_face_auth.md)


## 汇总


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [GetExecutorInfo](#getexecutorinfo)&nbsp;([out]&nbsp;struct&nbsp;[ExecutorInfo](_executor_info_faceauth.md)&nbsp;executorInfo) | 获取执行器信息，人脸认证服务将执行器注册到用户认证框架时需要通过该接口获取对应信息。 | 
| [GetTemplateInfo](#gettemplateinfo)&nbsp;([in]&nbsp;unsigned&nbsp;long&nbsp;templateId,&nbsp;[out]&nbsp;struct&nbsp;[TemplateInfo](_template_info_faceauth.md)&nbsp;templateInfo) | 获取凭据模版信息。 | 
| [OnRegisterFinish](#onregisterfinish)&nbsp;([in]&nbsp;unsigned&nbsp;long[]&nbsp;templateIdList,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;frameworkPublicKey,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo) | 完成执行器注册，对人脸特征模版进行对账，用于删除无效的人脸特征模板及相关信息。 | 
| [Enroll](#enroll)&nbsp;([in]&nbsp;unsigned&nbsp;long&nbsp;scheduleId,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo,&nbsp;[in]&nbsp;[IExecutorCallback](interface_i_executor_callback_faceauth.md)&nbsp;callbackObj) | 注册人脸特征模版。 | 
| [Authenticate](#authenticate)&nbsp;([in]&nbsp;unsigned&nbsp;long&nbsp;scheduleId,&nbsp;[in]&nbsp;unsigned&nbsp;long[]&nbsp;templateIdList,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo,&nbsp;[in]&nbsp;[IExecutorCallback](interface_i_executor_callback_faceauth.md)&nbsp;callbackObj) | 人脸认证。 | 
| [Identify](#identify)&nbsp;([in]&nbsp;unsigned&nbsp;long&nbsp;scheduleId,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo,&nbsp;[in]&nbsp;[IExecutorCallback](interface_i_executor_callback_faceauth.md)&nbsp;callbackObj) | 人脸识别。 | 
| [Delete](#delete)&nbsp;([in]&nbsp;unsigned&nbsp;long[]&nbsp;templateIdList) | 删除人脸特征模版。 | 
| [Cancel](#cancel)&nbsp;([in]&nbsp;unsigned&nbsp;long&nbsp;scheduleId) | 取消操作请求。 | 
| [SendCommand](#sendcommand)&nbsp;([in]&nbsp;int&nbsp;commandId,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo,&nbsp;[in]&nbsp;[IExecutorCallback](interface_i_executor_callback_faceauth.md)&nbsp;callbackObj) | 发送人脸认证功能相关操作命令。 | 


## 成员函数说明


### Authenticate()

  
```
IExecutor::Authenticate ([in] unsigned long scheduleId, [in] unsigned long[] templateIdList, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述:**

人脸认证。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。 | 
| templateIdList | 指定要认证的模版ID列表。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback_faceauth.md)。 | 

**返回:**

0 表示操作成功。

非0 表示操作失败。


### Cancel()

  
```
IExecutor::Cancel ([in] unsigned long scheduleId)
```

**描述:**

取消操作请求。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。 | 

**返回:**

0 表示操作成功。

非0 表示操作失败。


### Delete()

  
```
IExecutor::Delete ([in] unsigned long[] templateIdList)
```

**描述:**

删除人脸特征模版。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| templateIdList | 指定要删除的模版ID列表。 | 

**返回:**

0 表示操作成功。

非0 表示操作失败。


### Enroll()

  
```
IExecutor::Enroll ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述:**

注册人脸特征模版。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback_faceauth.md)。 | 

**返回:**

0 表示操作成功。

非0 表示操作失败。


### GetExecutorInfo()

  
```
IExecutor::GetExecutorInfo ([out] struct ExecutorInfo executorInfo)
```

**描述:**

获取执行器信息，人脸认证服务将执行器注册到用户认证框架时需要通过该接口获取对应信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| executorInfo | 执行器信息[ExecutorInfo](_executor_info_faceauth.md)。 | 

**返回:**

0 表示操作成功。

非0 表示操作失败。


### GetTemplateInfo()

  
```
IExecutor::GetTemplateInfo ([in] unsigned long templateId, [out] struct TemplateInfo templateInfo )
```

**描述:**

获取凭据模版信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| templateId | 凭据模版ID。 | 
| templateInfo | 凭据模版信息[TemplateInfo](_template_info_faceauth.md)。 | 

**返回:**

0 表示操作成功。

非0 表示操作失败。


### Identify()

  
```
IExecutor::Identify ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述:**

人脸识别。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback_faceauth.md)。 | 

**返回:**

0 表示操作成功。

非0 表示操作失败。


### OnRegisterFinish()

  
```
IExecutor::OnRegisterFinish ([in] unsigned long[] templateIdList, [in] unsigned char[] frameworkPublicKey, [in] unsigned char[] extraInfo )
```

**描述:**

完成执行器注册，对人脸特征模版进行对账，用于删除无效的人脸特征模板及相关信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| templateIdList | 用户认证框架内由该执行器注册的人脸特征模版ID列表。 | 
| frameworkPublicKey | 用户认证框架的公钥，用于校验用户认证框架私钥签名的信息。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 

**返回:**

0 表示操作成功。

非0 表示操作失败。


### SendCommand()

  
```
IExecutor::SendCommand ([in] int commandId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述:**

发送人脸认证功能相关操作命令。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| commandId | 操作命令ID[CommandId](_hdf_face_auth.md#commandid)。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback_faceauth.md)。 | 

**返回:**

0 表示操作成功。

非0 表示操作失败。
