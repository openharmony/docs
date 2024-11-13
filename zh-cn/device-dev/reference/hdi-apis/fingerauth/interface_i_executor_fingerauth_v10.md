# IExecutor


## 概述

定义执行器接口，用于获取执行器，获取凭据模版信息，注册指纹特征模版，进行用户指纹认证，删除指纹特征模版等。

**起始版本：** 3.2

**相关模块：**[HdfFingerprintAuth](_hdf_fingerprint_auth_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetExecutorInfo](#getexecutorinfo) ([out] struct [ExecutorInfo](_executor_info_fingerauth_v10.md) executorInfo) | 获取执行器信息。  | 
| [GetTemplateInfo](#gettemplateinfo) ([in] unsigned long templateId, [out] struct [TemplateInfo](_template_info_fingerauth_v10.md) templateInfo) | 获取凭据模板信息。  | 
| [OnRegisterFinish](#onregisterfinish) ([in] unsigned long[] templateIdList, [in] unsigned char[] frameworkPublicKey, [in] unsigned char[] extraInfo) | 完成执行器注册，对指纹特征模版进行对账，用于删除无效的指纹特征模板及相关信息。  | 
| [Enroll](#enroll) ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] [IExecutorCallback](interface_i_executor_callback_fingerauth_v10.md) callbackObj) | 注册指纹特征模版。  | 
| [Authenticate](#authenticate) ([in] unsigned long scheduleId, [in] unsigned long[] templateIdList, [in] unsigned char[] extraInfo, [in] [IExecutorCallback](interface_i_executor_callback_fingerauth_v10.md) callbackObj) | 指纹认证。  | 
| [Identify](#identify) ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] [IExecutorCallback](interface_i_executor_callback_fingerauth_v10.md) callbackObj) | 指纹识别。  | 
| [Delete](#delete) ([in] unsigned long[] templateIdList) | 删除指纹特征模版。  | 
| [Cancel](#cancel) ([in] unsigned long scheduleId) | 取消操作请求。  | 
| [SendCommand](#sendcommand) ([in] int commandId, [in] unsigned char[] extraInfo, [in] [IExecutorCallback](interface_i_executor_callback_fingerauth_v10.md) callbackObj) | 发送指纹认证功能相关操作命令。  | 


## 成员函数说明


### Authenticate()

```
IExecutor::Authenticate ([in] unsigned long scheduleId, [in] unsigned long[] templateIdList, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```
**描述**

指纹认证。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。  | 
| templateIdList | 指定要认证的模版ID列表。  | 
| extraInfo | 其他相关信息，用于支持信息扩展。  | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback_fingerauth_v10.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### Cancel()

```
IExecutor::Cancel ([in] unsigned long scheduleId)
```
**描述**

取消操作请求。

**起始版本：** 3.2

**参数:**

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
**描述**

删除指纹特征模版。

**起始版本：** 3.2

**参数:**

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
**描述**

注册指纹特征模版。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。  | 
| extraInfo | 其他相关信息，用于支持信息扩展。  | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback_fingerauth_v10.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetExecutorInfo()

```
IExecutor::GetExecutorInfo ([out] struct ExecutorInfo executorInfo)
```
**描述**

获取执行器信息。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executorInfo | 执行器信息[ExecutorInfo](_executor_info_fingerauth_v10.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### GetTemplateInfo()

```
IExecutor::GetTemplateInfo ([in] unsigned long templateId, [out] struct TemplateInfo templateInfo )
```
**描述**

获取凭据模板信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| templateId | 凭据模板ID。  | 
| templateInfo | 凭据模板信息[TemplateInfo](_template_info_fingerauth_v10.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### Identify()

```
IExecutor::Identify ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```
**描述**

指纹识别。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的调度过程。  | 
| extraInfo | 其他相关信息，用于支持信息扩展。  | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback_fingerauth_v10.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### OnRegisterFinish()

```
IExecutor::OnRegisterFinish ([in] unsigned long[] templateIdList, [in] unsigned char[] frameworkPublicKey, [in] unsigned char[] extraInfo )
```
**描述**

完成执行器注册，对指纹特征模版进行对账，用于删除无效的指纹特征模板及相关信息。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| templateIdList | 用户认证框架内由该执行器注册的指纹特征模版ID列表。  | 
| frameworkPublicKey | 用户认证框架的公钥，用于校验用户认证框架私钥签名的信息。  | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### SendCommand()

```
IExecutor::SendCommand ([in] int commandId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```
**描述**

发送指纹认证功能相关操作命令。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| commandId | 操作命令ID[CommandId](_hdf_fingerprint_auth_v10.md#commandid)。  | 
| extraInfo | 其他相关信息，用于支持信息扩展。  | 
| callbackObj | 回调对象[IExecutorCallback](interface_i_executor_callback_fingerauth_v10.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
