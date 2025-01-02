# 证书管理对话框错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 29700001 内部错误

**错误信息**

Internal error.

**可能原因**

调用API时发生内部错误。

**处理步骤**

检查内部运行情况是否正常。

## 29700002 操作取消

**错误信息**

The user cancels the installation operation.

**可能原因**

调用API时用户取消操作。

**处理步骤**

无需处理。

## 29700003 证书安装失败错误

**错误信息**

The user install certificate failed in the certificate manager dialog.

**可能原因**

调用API时发生证书安装失败。

**处理步骤**

检查证书格式，数据等是否正常。

## 29700004 设备类型不支持

**错误信息**

The API is not supported on this device.

**可能原因**

调用API时当前设备非PC设备。

**处理步骤**

更换PC设备调用此API。
