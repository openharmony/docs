# IExecutor


## **概述**

定义执行器接口，用于获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。

**Since：**

3.2

**Version:**

1.0

**所属模块:**

[HdfFaceAuth](_hdf_face_auth.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [GetExecutorInfo](#getexecutorinfo)([out]&nbsp;struct&nbsp;ExecutorInfo&nbsp;executorInfo) | 获取执行器信息，人脸认证服务将执行器注册到用户认证框架时需要通过该接口获取对应信息。 | 
| [GetTemplateInfo](#gettemplateinfo)([in]&nbsp;unsigned&nbsp;long&nbsp;templateId,&nbsp;[out]&nbsp;struct&nbsp;TemplateInfo&nbsp;templateInfo) | 获取凭据模版信息。 | 
| [OnRegisterFinish](#onregisterfinish)([in]&nbsp;unsigned&nbsp;long[]&nbsp;templateIdList,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;frameworkPublicKey,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo) | 完成执行器注册，对人脸特征模版进行对账，用于删除无效的人脸特征模板及相关信息。 | 
| [Enroll](#enroll)([in]&nbsp;unsigned&nbsp;long&nbsp;scheduleId,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo,&nbsp;[in]&nbsp;IExecutorCallback&nbsp;callbackObj) | 注册人脸特征模版。 | 
| [Authenticate](#authenticate)([in]&nbsp;unsigned&nbsp;long&nbsp;scheduleId,&nbsp;[in]&nbsp;unsigned&nbsp;long[]&nbsp;templateIdList,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo,&nbsp;[in]&nbsp;IExecutorCallback&nbsp;callbackObj) | 人脸认证。 | 
| [Identify](#identify)([in]&nbsp;unsigned&nbsp;long&nbsp;scheduleId,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo,&nbsp;[in]&nbsp;IExecutorCallback&nbsp;callbackObj) | 人脸识别。 | 
| [Delete](#delete)([in]&nbsp;unsigned&nbsp;long[]&nbsp;templateIdList) | 删除人脸特征模版。 | 
| [Cancel](#cancel)([in]&nbsp;unsigned&nbsp;long&nbsp;scheduleId) | 取消操作请求。 | 
| [SendCommand](#sendcommand)([in]&nbsp;int&nbsp;commandId,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo,&nbsp;[in]&nbsp;IExecutorCallback&nbsp;callbackObj) | 发送人脸认证功能相关操作命令。 | 
| [SetBufferProducer](#setbufferproducer) ([in]&nbsp;BufferProducerSequenceable&nbsp;bufferProducer) | 设置可用缓冲区生成器。 |


## **成员函数说明**


### Authenticate()

  
```
IExecutor::Authenticate ([in] unsigned long scheduleId, [in] unsigned long[] templateIdList, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述：**

人脸认证。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。 | 
| templateIdList | 指定要认证的模版ID列表。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback.md)。 | 

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
IExecutor::Delete ([in] unsigned long[] templateIdList)
```

**描述：**

删除人脸特征模版。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| templateIdList | 指定要删除的模版ID列表。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### Enroll()

  
```
IExecutor::Enroll ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述：**

注册人脸特征模版。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetExecutorInfo()

  
```
IExecutor::GetExecutorInfo ([out] struct ExecutorInfo executorInfo)
```

**描述：**

获取执行器信息，人脸认证服务将执行器注册到用户认证框架时需要通过该接口获取对应信息。

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


### Identify()

  
```
IExecutor::Identify ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述：**

人脸识别。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### OnRegisterFinish()

  
```
IExecutor::OnRegisterFinish ([in] unsigned long[] templateIdList, [in] unsigned char[] frameworkPublicKey, [in] unsigned char[] extraInfo )
```

**描述：**

完成执行器注册，对人脸特征模版进行对账，用于删除无效的人脸特征模板及相关信息。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| templateIdList | 用户认证框架内由该执行器注册的人脸特征模版ID列表。 | 
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

发送人脸认证功能相关操作命令。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| commandId | 操作命令ID。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。

### SetBufferProducer()


```
IExecutor::SetBufferProducer ([in] BufferProducerSequenceable bufferProducer )
```

**描述：**

设置可用缓冲区生成器。用于传递相机预览流，开始录入前设置为有效值，结束录入后设置为空指针。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| bufferProducer | 可用缓冲区生成器。 |

**返回：**

0 表示操作成功。

非0 表示操作失败。
