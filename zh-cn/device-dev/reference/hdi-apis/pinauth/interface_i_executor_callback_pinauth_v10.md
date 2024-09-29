# IExecutorCallback


## 概述

定义异步API接口回调，用于返回异步接口的请求处理结果和获取信息。使用细节见[IExecutor](interface_i_executor_pinauth_v10.md)。

**起始版本：** 3.2

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnResult](#onresult) ([in] int result, [in] unsigned char[] extraInfo) | 定义操作请求处理结果回调函数。  | 
| [OnGetData](#ongetdata) ([in] unsigned long scheduleId, [in] unsigned char[] salt, [in] unsigned long authSubType) | 定义请求获取口令数据回调函数。  | 


## 成员函数说明


### OnGetData()

```
IExecutorCallback::OnGetData ([in] unsigned long scheduleId, [in] unsigned char[] salt, [in] unsigned long authSubType )
```
**描述**

定义请求获取口令数据回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| salt | 盐值，用于对口令 明文进行单向处理。  | 
| authSubType | 口令子类型，如六位数字PIN码等。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### OnResult()

```
IExecutorCallback::OnResult ([in] int result, [in] unsigned char[] extraInfo )
```
**描述**

定义操作请求处理结果回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| result | 操作请求处理结果。  | 
| extraInfo | 其他相关信息，如用户认证通过时用于返回执行器签发的认证令牌等。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
