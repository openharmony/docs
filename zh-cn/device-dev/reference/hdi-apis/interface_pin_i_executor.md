# IExecutor


## **概述**

定义执行器标准API接口。接口可用于获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。

**Since：**

3.2

**Version:**

1.0

**所属模块:**

[HdfPinAuth](_hdf_pin_auth.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [GetTemplateInfo](#gettemplateinfo)([in]&nbsp;unsigned&nbsp;long&nbsp;templateId,&nbsp;[out]&nbsp;struct&nbsp;TemplateInfo&nbsp;templateInfo) | 获取凭据模版信息。 | 
| [Cancel](#cancel)([in]&nbsp;unsigned&nbsp;long&nbsp;scheduleId) | 取消操作请求。 | 
| [GetExecutorInfo](#getexecutorinfo)&nbsp;([out]&nbsp;struct&nbsp;ExecutorInfo&nbsp;executorInfo) | 获取执行器信息，口令认证服务将执行器注册到用户认证框架时需要通过该接口获取对应信息。 | 
| [OnRegisterFinish](#onregisterfinish)&nbsp;([in]&nbsp;unsigned&nbsp;long[]&nbsp;templateIdList,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;frameworkPublicKey,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo) | 完成执行器注册，对口令模版信息进行对账，用于删除无效的口令模板及相关信息。 | 
| [OnSetData](#onsetdata)([in]&nbsp;unsigned&nbsp;long&nbsp;scheduleId,&nbsp;[in]&nbsp;unsigned&nbsp;long&nbsp;authSubType,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;data) | 设置口令数据，口令认证驱动处理注册或认证口令请求时，如果口令数据由口令认证服务获取，需要通过该接口将口令数据传给口令认证驱动。 | 
| [Enroll](#enroll)&nbsp;([in]&nbsp;unsigned&nbsp;long&nbsp;scheduleId,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo,&nbsp;[in]&nbsp;IExecutorCallback&nbsp;callbackObj) | 注册口令。 | 
| [Authenticate](#authenticate)&nbsp;([in]&nbsp;unsigned&nbsp;long&nbsp;scheduleId,&nbsp;[in]&nbsp;unsigned&nbsp;long&nbsp;templateId,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo,&nbsp;[in]&nbsp;IExecutorCallback&nbsp;callbackObj) | 认证口令。 | 
| [Delete](#delete)&nbsp;([in]&nbsp;unsigned&nbsp;long&nbsp;templateId) | 删除口令。 | 
| [SendCommand](#sendcommand)&nbsp;([in]&nbsp;int&nbsp;commandId,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo,&nbsp;[in]&nbsp;IExecutorCallback&nbsp;callbackObj) | 发送口令认证功能相关操作命令。 | 


## **成员函数说明**


### Authenticate()

  
```
IExecutor::Authenticate ([in] unsigned long scheduleId, [in] unsigned long templateId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述：**

认证口令。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。 | 
| templateId | 指定要认证的模版ID。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 
| callbackObj | 回调对象[IExecutorCallback](interface_pin_i_executor_callback.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### Cancel()

  
```
IExecutor::Cancel ([in] unsigned long scheduleId)
```

**描述：**

取消操作请求。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### Delete()

  
```
IExecutor::Delete ([in] unsigned long templateId)
```

**描述：**

删除口令。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| templateId | 模版ID。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### Enroll()

  
```
IExecutor::Enroll ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述：**

注册口令。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 
| callbackObj | 回调对象[IExecutorCallback](interface_pin_i_executor_callback.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetExecutorInfo()

  
```
IExecutor::GetExecutorInfo ([out] struct ExecutorInfo executorInfo)
```

**描述：**

获取执行器信息，口令认证服务将执行器注册到用户认证框架时需要通过该接口获取对应信息。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| executorInfo | 执行器信息[ExecutorInfo](_executor_info.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetTemplateInfo()

  
```
IExecutor::GetTemplateInfo ([in] unsigned long templateId, [out] struct TemplateInfo templateInfo )
```

**描述：**

获取凭据模版信息。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| templateId | 凭据模版ID。 | 
| templateInfo | 凭据模版信息[TemplateInfo](_template_info.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### OnRegisterFinish()

  
```
IExecutor::OnRegisterFinish ([in] unsigned long[] templateIdList, [in] unsigned char[] frameworkPublicKey, [in] unsigned char[] extraInfo )
```

**描述：**

完成执行器注册，对口令模版信息进行对账，用于删除无效的口令模板及相关信息。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| templateIdList | 用户认证框架内由该执行器注册的口令凭据模版ID列表。 | 
| frameworkPublicKey | 用户认证框架的公钥，用于校验用户认证框架私钥签名的信息。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### OnSetData()

  
```
IExecutor::OnSetData ([in] unsigned long scheduleId, [in] unsigned long authSubType, [in] unsigned char[] data )
```

**描述：**

设置口令数据，口令认证驱动处理注册或认证口令请求时，如果口令数据由口令认证服务获取，需要通过该接口将口令数据传给口令认证驱动。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。 | 
| authSubType | 口令子类型，如六位数字PIN码等。 | 
| data | 口令数据。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### SendCommand()

  
```
IExecutor::SendCommand ([in] int commandId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述：**

发送口令认证功能相关操作命令。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| commandId | 操作命令ID。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 
| callbackObj | 回调对象[IExecutorCallback](interface_pin_i_executor_callback.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
