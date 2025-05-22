# IExecutorCallback


## 概述

定义异步API接口回调。当执行器使用者调用异步函数时该回调需要被注册。使用细节见[IExecutor](interface_i_executor_fingerauth_v10.md)。

**起始版本：** 3.2

**相关模块：**[HdfFingerprintAuth](_hdf_fingerprint_auth_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnResult](#onresult) ([in] int result, [in] unsigned char[] extraInfo) | 定义操作结果回调函数。  | 
| [OnTip](#ontip) ([in] int tip, [in] unsigned char[] extraInfo) | 定义操作过程信息反馈回调函数。  | 


## 成员函数说明


### OnResult()

```
IExecutorCallback::OnResult ([in] int result, [in] unsigned char[] extraInfo )
```
**描述**

定义操作结果回调函数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| result | 操作请求处理结果。  | 
| extraInfo | 其他相关信息，如用户认证通过时用于返回执行器签发的认证令牌等。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### OnTip()

```
IExecutorCallback::OnTip ([in] int tip, [in] unsigned char[] extraInfo )
```
**描述**

定义操作过程信息反馈回调函数。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tip | 提示信息编码[FingerprintTipsCode](_hdf_fingerprint_auth_v10.md#fingerprinttipscode)。  | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
