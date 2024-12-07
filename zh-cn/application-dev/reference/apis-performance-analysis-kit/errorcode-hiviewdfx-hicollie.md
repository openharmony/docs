# HiCollie错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 29800001 系统服务获取失败

**错误信息**

Wrong thread context.The function can not be called from main thread.

**错误描述**
调用接口线程错误。

**可能原因**

无法从主线程调用该接口服务。

**处理步骤**

在非主线程调用该接口服务。

## 29800002 远程调用失败

**错误信息**

Remote call failed.

**错误描述**
当前接口请求远程服务失败。

**可能原因**

服务未启动或崩溃。

