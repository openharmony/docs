# IExecutorCallback


## 概述

定义异步API接口回调，用于返回异步接口的请求处理结果和获取信息。

**起始版本：** 3.2

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v20.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnResult](#onresult) ([in] int result, [in] unsigned char[] extraInfo) | 回调函数，返回认证结果。 | 
| [OnTip](#ontip) ([in] int tip, [in] unsigned char[] extraInfo) | 返回操作的过程提示信息。 | 
| [OnGetData](#ongetdata) ([in] unsigned char[] algoParameter, [in] unsigned long authSubType, [in] unsigned int algoVersion, [in] unsigned char[] challenge) | 定义请求获取口令数据回调函数。 | 
| [OnMessage](#onmessage) ([in] int destRole, [in] unsigned char[] msg) | 返回操作的过程交互消息。 | 


## 成员函数说明


### OnGetData()

```
IExecutorCallback::OnGetData ([in] unsigned char[] algoParameter, [in] unsigned long authSubType, [in] unsigned int algoVersion, [in] unsigned char[] challenge )
```

**描述**

定义请求获取口令数据回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| algoParameter | 算法相关参数。 | 
| authSubType | 口令子类型，如六位数字PIN码等[PinAuthTypes](_pin_auth_types_8idl_v20.md)。 | 
| algoVersion | 算法版本。 | 
| challenge | 用于防重放。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### OnMessage()

```
IExecutorCallback::OnMessage ([in] int destRole, [in] unsigned char[] msg )
```

**描述**

返回操作的过程交互消息。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| destRole | 目标执行器角色[ExecutorRole](_hdf_pin_auth_v20.md#executorrole)。 | 
| msg | 消息。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### OnResult()

```
IExecutorCallback::OnResult ([in] int result, [in] unsigned char[] extraInfo )
```

**描述**

回调函数，返回认证结果。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| result | 操作请求处理结果。 | 
| extraInfo | 其他相关信息，如用户认证通过时用于返回执行器签发的认证令牌等。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### OnTip()

```
IExecutorCallback::OnTip ([in] int tip, [in] unsigned char[] extraInfo )
```

**描述**

返回操作的过程提示信息。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tip | 提示码。 | 
| extraInfo | 其他相关信息。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
