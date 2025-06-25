# 用户感知错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 33500001 服务异常

**错误信息**

Service exception. Possible causes:
<br>&emsp;1. System error, such as a null pointer and container-related exception. 
<br>&emsp;2. Node-API invocation exception, such as invalid Node-API status.

**错误描述**

当调用userStatus模块on、off接口时，若服务异常，会报此错误码。

**可能原因**

服务状态异常。

**处理步骤**

1. 定时重试操作，如间隔1s或者按照指数增长间隔重试。
2. 连续重试3次不可用则停止尝试，期间可优先尝试获取器件列表方式进一步获取设备可用性。



## 33500002 订阅失败

**错误信息**

Subscription failed. Possible causes: 
<br>&emsp;1. Callback registration failed.
<br>&emsp;2. Failed to bind the native object to the JS wrapper.
<br>&emsp;3. Node-API invocation exception, such as invalid Node-API status.
<br>&emsp;4. IPC request exception.

**错误描述**

当调用userStatus模块on接口时，若订阅失败，会报此错误码。

**可能原因**

订阅异常。

**处理步骤**

1. 定时重试操作，如间隔1s或者按照指数增长间隔重试。
2. 连续重试3次不可用则停止尝试。



## 33500003 取消订阅失败

**错误信息**

Unsubscription failed. Possible causes: 
<br>&emsp;1. Callback failure.
<br>&emsp;2. Node-API invocation exception, such as invalid Node-API status.
<br>&emsp;3. IPC request exception.

**错误描述**

当调用userStatus模块off接口时，若取消订阅失败，会报此错误码。

**可能原因**

取消订阅异常。

**处理步骤**

1. 定时重试操作，如间隔1s或者按照指数增长间隔重试。
2. 连续重试3次不可用则停止尝试。