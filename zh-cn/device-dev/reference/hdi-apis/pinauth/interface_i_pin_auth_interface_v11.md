# IPinAuthInterface


## 概述

定义获取口令认证驱动的执行器列表接口。

**起始版本：** 4.0

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetExecutorListV1_1](#getexecutorlistv1_1) ([out] [IExecutor](interface_i_executor_pinauth_v11.md)[] executorList) | 获取执行器列表，口令认证服务进程启动进行初始化操作时通过该接口获取口令认证驱动支持的执行器列表。  | 


## 成员函数说明


### GetExecutorListV1_1()

```
IPinAuthInterface::GetExecutorListV1_1 ([out] IExecutor[] executorList)
```
**描述**


获取执行器列表，口令认证服务进程启动进行初始化操作时通过该接口获取口令认证驱动支持的执行器列表。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executorList | 执行器对象列表[IExecutor](interface_i_executor_pinauth_v11.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
