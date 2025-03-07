# IExecutorCallback


## 概述

定义异步API接口回调，用于返回异步接口的请求处理结果和信息。使用细节见[IExecutor](interface_i_executor_faceauth_v10.md)。

**起始版本：** 3.2

**相关模块：**[HdfFaceAuth](_hdf_face_auth_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnResult](#onresult) ([in] int result, [in] unsigned char[] extraInfo) | 定义操作结果回调函数。  | 
| [OnAcquireInfo](#onacquireinfo) ([in] int acquire, [in] unsigned char[] extraInfo) | 定义操作过程信息反馈回调函数。  | 


## 成员函数说明


### OnAcquireInfo()

```
IExecutorCallback::OnAcquireInfo ([in] int acquire, [in] unsigned char[] extraInfo )
```
**描述**

定义操作过程信息反馈回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| acquire | 提示信息编码。详细说明请参考[FaceTipsCode](_hdf_face_auth_v10.md#facetipscode)。  | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### OnResult()

```
IExecutorCallback::OnResult ([in] int result, [in] unsigned char[] extraInfo )
```
**描述**

定义操作结果回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| result | 操作请求处理结果。  | 
| extraInfo | 其他相关信息，如用户认证通过时用于返回执行器签发的认证令牌等。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
