# 键鼠穿越管理错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 20900001 操作输入设备失败

**错误信息**

Service exception. Possible causes: 1. A system error, such as null pointer, container-related exception, or IPC exception. 2. N-API invocation exception or invalid N-API status.

**错误描述**

当调用键鼠穿越接口时穿越状态异常，系统会产生此错误码。

**可能原因**

1. 发起键鼠穿越时，本机键鼠穿越为穿出状态。
2. 关闭键鼠穿越时，本机键鼠穿越为自由态。
3. 发起关闭键鼠穿越时，本机键鼠穿越状态正在切换中。
4. 系统错误，如空指针、容器相关异常、IPC异常等。
5. Native-API调用异常，Native-API状态无效。

**处理步骤**

1. 发起键鼠穿越时，请检查本机键鼠穿越状态是否为非穿出状态。
2. 关闭键鼠穿越时，请检查本机键鼠穿越状态是否为非自由态。
3. 发起关闭键鼠穿越时，请检查本机键鼠穿越状态是否在切换中。