# IPinAuthInterface


## 概述

定义获取口令认证驱动的执行器列表接口，用于从口令认证驱动获取执行器对象列表。

**起始版本：** 3.2

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v20.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetExecutorList](#getexecutorlist) ([out] [IAllInOneExecutor](interface_i_all_in_one_executor_v20.md)[] allInOneExecutors, [out] [IVerifier](interface_i_verifier_v20.md)[] verifiers, [out] [ICollector](interface_i_collector_v20.md)[] collectors) | 获取执行器列表，口令认证服务进程启动进行初始化操作时通过该接口获取口令认证驱动支持的执行器列表。 | 


## 成员函数说明


### GetExecutorList()

```
IPinAuthInterface::GetExecutorList ([out] IAllInOneExecutor[] allInOneExecutors, [out] IVerifier[] verifiers, [out] ICollector[] collectors )
```

**描述**

获取执行器列表，口令认证服务进程启动进行初始化操作时通过该接口获取口令认证驱动支持的执行器列表。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| allInOneExecutors | 标识驱动程序的全功能执行器列表[IAllInOneExecutor](interface_i_all_in_one_executor_v20.md)。 | 
| verifiers | 标识驱动程序的认证器列表[IVerifier](interface_i_verifier_v20.md)。 | 
| collectors | 标识驱动程序的采集器列表[ICollector](interface_i_collector_v20.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
