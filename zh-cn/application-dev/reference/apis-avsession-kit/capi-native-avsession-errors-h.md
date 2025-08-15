# native_avsession_errors.h
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

## 概述

提供播控错误码的定义。

**引用文件：** <multimedia/av_session/native_avsession_errors.h>

**库：** libohavsession.so

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**起始版本：** 13

**相关模块：** [OHAVSession](capi-ohavsession.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [AVSession_ErrCode](#avsession_errcode) | AVSession_ErrCode | 播控错误码。 |

## 枚举类型说明

### AVSession_ErrCode

```
enum AVSession_ErrCode
```

**描述**

播控错误码。

**起始版本：** 13

| 枚举项 | 描述 |
| -- | -- |
| AV_SESSION_ERR_SUCCESS = 0 | 操作成功。 |
| AV_SESSION_ERR_INVALID_PARAMETER = 401 | 参数检查失败。 |
| AV_SESSION_ERR_SERVICE_EXCEPTION = 6600101 | 会话服务端异常。 |
| AV_SESSION_ERR_CODE_SESSION_NOT_EXIST = 6600102 | 会话不存在。 |
| AV_SESSION_ERR_CODE_COMMAND_INVALID = 6600105 | 无效会话命令。 |
| AV_SESSION_ERR_CODE_SESSION_INACTIVE = 6600106 | 会话未激活。 |
| AV_SESSION_ERR_CODE_MESSAGE_OVERLOAD = 6600107 | 命令&消息过载。 |


