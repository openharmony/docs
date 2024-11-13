# IPinAuthInterface


## 概述

定义获取口令认证驱动的执行器列表接口。

**起始版本：** 3.2

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetExecutorList](#getexecutorlist) ([out] [IExecutor](interface_i_executor_pinauth_v10.md)[] executorList) | 获取执行器列表，口令认证服务进程启动进行初始化操作时通过该接口获取口令认证驱动支持的执行器列表。  | 


## 成员函数说明


### GetExecutorList()

```
IPinAuthInterface::GetExecutorList ([out] IExecutor[] executorList)
```
**描述**

获取执行器列表，口令认证服务进程启动进行初始化操作时通过该接口获取口令认证驱动支持的执行器列表。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executorList | 执行器对象列表[IExecutor](interface_i_executor_pinauth_v10.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
