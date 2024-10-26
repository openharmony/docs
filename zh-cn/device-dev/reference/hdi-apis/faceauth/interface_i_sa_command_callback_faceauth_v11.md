# ISaCommandCallback


## 概述

定义异步 API 的回调，该回调可用于向 SA 发送命令。详细说明请参考[IExecutor](interface_i_executor_faceauth_v11.md).

**起始版本：** 4.0

**相关模块：**[HdfFaceAuth](_hdf_face_auth_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnSaCommands](#onsacommands) ([in] struct [SaCommand](_sa_command_faceauth_v11.md)[] commands) | 定义进程中sa命令的函数。  | 


## 成员函数说明


### OnSaCommands()

```
ISaCommandCallback::OnSaCommands ([in] struct SaCommand[] commands)
```
**描述**

定义进程中sa命令的函数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| commands | 表示SA命令。详细说明请参考[SaCommand](_sa_command_faceauth_v11.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
