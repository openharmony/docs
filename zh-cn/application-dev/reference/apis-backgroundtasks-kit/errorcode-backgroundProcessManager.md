# backgroundProcessManager错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 31800001 服务端异常

**错误信息**

remote error. Possible causes: remote is not work.

**错误描述**

客户端进程请求系统服务进程，获取系统服务操作失败。

**可能原因**

1. 系统服务还未启动。
2. 系统服务异常。

**处理步骤**

请1s后重试，或重启设备。