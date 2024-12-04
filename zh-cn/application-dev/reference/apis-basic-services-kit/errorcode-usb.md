# USB服务错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 14400001 连接USB设备被拒绝

**错误信息**

Permission denied. Call requestRight to get the permission first.

**错误描述**

当调用USB模块部分接口时，如果没有相关权限，会报此错误码。

**可能原因**

没有获取到设备的使用权限。

**处理步骤**

调用requestRight方法申请设备的使用权限。

## 14400002 HDC功能被禁用

**错误信息**

Permission denied. The HDC is disabled by the system.

**错误描述**

HDC被系统禁用。

**可能原因**

没有申请USB调试权限。

**处理步骤**

申请USB调试权限。

## 14400003 不支持的端口角色切换

**错误信息**

Unsupported operation. The current device does not support port role switching.

**错误描述**

不支持的操作。当前设备不支持端口角色切换。

**可能原因**

不是正确的端口角色。

**处理步骤**

使用正确的端口角色。

## 14400004 服务异常

**错误信息**

Service exception. Possible causes: No accessory is plugged in.

**错误描述**

服务异常。

**可能原因：**

没有配件插入。

**处理步骤**

插入配件。

## 14400005 数据库操作异常

**错误信息**

Database operation exception.

**错误描述**

数据库操作异常。

**处理步骤**

尝试重新调用接口。

## 14401001 目标USB配件未匹配

**错误信息**

The target USBAccessory not matched.

**错误描述**

目标USB配件未匹配。

**处理步骤**

通过getAccessoryList获得配件列表，使用匹配的USBAccessory重新操作。

## 14401002 打开配件节点失败

**错误信息**

Failed to open the native accessory node.

**错误描述**

打开配件节点失败。

**处理步骤**

尝试重新调用接口。

## 14401003 不能重复打开配件

**错误信息**

Cannot reopen the accessory.

**错误描述**

不能重复打开配件。

**处理步骤**

配件已被打开，继续执行后续开发操作。
