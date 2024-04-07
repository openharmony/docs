# IPinAuthInterface


## 概述

定义获取口令认证驱动的执行器列表接口，用于从口令认证驱动获取执行器对象列表。

**起始版本：** 3.2

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v20.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetExecutorList](#getexecutorlist) ([out] IAllInOneExecutor[] allInOneExecutors, [out] IVerifier[] verifiers, [out] ICollector[] collectors) | 获取执行器列表。 | 


## 成员函数说明


### GetExecutorList()

```
IExecutorCallback::GetExecutorList ([out] IAllInOneExecutor[] allInOneExecutors, [out] IVerifier[] verifiers, [out] ICollector[] collectors)
```
**描述**
获取执行器列表。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| allInOneExecutors | 返回全功能执行器列表。 | 
| verifiers | 返回认证器列表。 | 
| collectors | 返回采集器列表。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
