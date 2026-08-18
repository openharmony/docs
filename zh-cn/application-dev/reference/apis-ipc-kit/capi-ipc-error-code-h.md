# ipc_error_code.h
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->

## 概述

提供IPC错误码定义，用于标识和处理IPC通信过程中可能发生的各类错误。开发者可根据返回的错误码快速定位问题原因，如参数错误、序列化失败、内存分配失败、远端对象死亡等场景，从而采取相应的错误处理措施。

**引用文件：** <IPCKit/ipc_error_code.h>

**库：** libipc_capi.so

**系统能力：** SystemCapability.Communication.IPC.Core

**支持设备类型：** 不区分设备类型，可通过系统能力SystemCapability.Communication.IPC.Core判断功能是否可用。

**起始版本：** 12

**相关模块：** [OHIPCErrorCode](capi-ohipcerrorcode.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| ---- | ------------- | ---- |
| [OH_IPC_ErrorCode](#oh_ipc_errorcode) | OH_IPC_ErrorCode | IPC错误码定义。 |

## 枚举类型说明

### OH_IPC_ErrorCode

```C
enum OH_IPC_ErrorCode
```

**描述：**

IPC错误码定义。

**起始版本：** 12

| 枚举项 | 描述 |
| ------ | ---- |
| OH_IPC_SUCCESS = 0 | 执行成功。 |
| OH_IPC_ERROR_CODE_BASE = 1901000 | 错误码区间起始值。 |
| OH_IPC_CHECK_PARAM_ERROR = OH_IPC_ERROR_CODE_BASE | 参数错误。当传入的参数为空指针、参数值超出有效范围或参数类型不匹配时返回此错误码。开发者应检查参数的有效性和合法性。 |
| OH_IPC_PARCEL_WRITE_ERROR = OH_IPC_ERROR_CODE_BASE + 1 | 序列化对象写入数据失败。当数据序列化时内存不足或数据格式不支持时可能发生此错误。开发者应检查数据大小和格式是否符合要求。 |
| OH_IPC_PARCEL_READ_ERROR = OH_IPC_ERROR_CODE_BASE + 2 | 序列化对象读取数据失败。当读取的数据长度超出实际数据长度或数据格式不匹配时可能发生此错误。开发者应检查数据读取顺序和数据格式是否正确。 |
| OH_IPC_MEM_ALLOCATOR_ERROR = OH_IPC_ERROR_CODE_BASE + 3 | 内存分配失败。当系统内存不足或内存分配器异常时返回此错误码。开发者应检查内存使用情况，释放不必要的资源后重试。 |
| OH_IPC_CODE_OUT_OF_RANGE = OH_IPC_ERROR_CODE_BASE + 4 | 命令字超出定义范围[0x01,0x00FFFFFF]。当IPC通信使用的命令字不在有效范围内时返回此错误码。开发者应检查命令字定义是否符合规范要求。 |
| OH_IPC_DEAD_REMOTE_OBJECT = OH_IPC_ERROR_CODE_BASE + 5 | 远端对象死亡。当IPC通信的对端进程已退出或远端对象已被销毁时返回此错误码。开发者应重新建立连接或使用替代服务。 |
| OH_IPC_INVALID_USER_ERROR_CODE = OH_IPC_ERROR_CODE_BASE + 6 | 用户自定义错误码超出范围[1909000, 1909999]。当开发者设置的自定义错误码不在允许范围内时返回此错误码。开发者应确保自定义错误码在有效范围内。 |
| OH_IPC_INNER_ERROR = OH_IPC_ERROR_CODE_BASE + 7 | IPC内部错误。当IPC系统内部发生未知错误时返回此错误码。开发者可记录日志并联系技术支持或稍后重试。 |
| OH_IPC_ERROR_CODE_MAX = OH_IPC_ERROR_CODE_BASE + 1000 | 错误码区间最大值。 |
| OH_IPC_USER_ERROR_CODE_MIN = 1909000 | 用户自定义错误码最小值。 |
| OH_IPC_USER_ERROR_CODE_MAX = 1909999 | 用户自定义错误码最大值。 |
