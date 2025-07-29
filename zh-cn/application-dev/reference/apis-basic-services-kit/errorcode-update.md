# 升级错误码
<!--Kit: Basic Services Kit-->
<!--Subsystem: Update-->
<!--Owner: @RainyDay_005; @huangsiping3-->
<!--SE: @zhangzhengxue;@jackd320-->
<!--TSE: @mamba-ting-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 11500104 IPC通信异常

**错误信息**

IPC error.

**错误描述**

调用过程中出现异常。

**可能原因**

IPC 调用过程中出现异常，接口调用失败。

**处理步骤**

1. 检查升级 SA 是否启动，若未启动请启动升级 SA。
2. 检查 IPC 数据转换是否正常，若异常请检查转换流程。