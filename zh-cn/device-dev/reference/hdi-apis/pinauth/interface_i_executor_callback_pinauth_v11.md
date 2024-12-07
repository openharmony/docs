# IExecutorCallback


## 概述

定义异步API接口回调，用于返回异步接口的请求处理结果和获取信息。使用细节见[IExecutor](interface_i_executor_pinauth_v11.md)。

**起始版本：** 4.0

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnGetDataV1_1](#ongetdatav1_1) ([in] unsigned long scheduleId, [in] unsigned char[] algoParameter, [in] unsigned long authSubType, [in] unsigned int algoVersion) | 定义请求获取口令数据回调函数。  | 


## 成员函数说明


### OnGetDataV1_1()

```
IExecutorCallback::OnGetDataV1_1 ([in] unsigned long scheduleId, [in] unsigned char[] algoParameter, [in] unsigned long authSubType, [in] unsigned int algoVersion )
```
**描述**

定义请求获取口令数据回调函数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scheduleId | 调度ID，用于标识一次操作请求的口令调度过程。  | 
| algoParameter | 算法相关参数。  | 
| authSubType | 口令子类型，如六位数字PIN码等。  | 
| algoVersion | 算法版本。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
