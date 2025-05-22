# ISaCommandCallback


## 概述

定义异步API接口回调，可以发送命令给SA。见[IExecutor](interface_i_executor_fingerauth_v11.md)。

**起始版本：** 4.0

**相关模块：**[HdfFingerprintAuth](_hdf_fingerprint_auth_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnSaCommands](#onsacommands) ([in] struct [SaCommand](_sa_command_fingerauth_v11.md)[] commands) | 定义SA命令过程回调函数。  | 


## 成员函数说明


### OnSaCommands()

```
ISaCommandCallback::OnSaCommands ([in] struct SaCommand[] commands)
```
**描述**

定义SA命令过程回调函数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| commands | SA命令见 [SaCommand](_sa_command_fingerauth_v11.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
