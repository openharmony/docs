# 输入设备错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 3900001 指定的设备不存在

**错误信息**

The specified device does not exist.

**错误描述**

指定的设备在多模设备列表中不存在。

**可能原因**

1. 输入设备的设备id变更。
2. 输入设备的物理连接断开。

**处理步骤**

1. 通过[inputDevice.getDeviceList](js-apis-inputdevice.md#inputdevicegetdevicelist9)查询设备id，并传入正确的设备id。
2. 检查设备的物理连接是否断开。

## 3900002 键盘设备没有连接

**错误信息**

There is currently no keyboard device connected.

**错误描述**

当前没有键盘设备插入连接。

**可能原因**

输入设备的物理连接断开。

**处理步骤**

检查设备的物理连接是否断开。

## 3900003 非输入法应用调用

**错误信息**

it is prohibited for non-input applications.

**错误描述**

禁止非输入法应用调用此接口。

**可能原因**

该接口不支持三方应用或者非输入法系统应用调用。

**处理步骤**

请使用输入法应用调用该接口。

## 26500001 无效的windowId

**错误信息**

windowId is invalid.

**错误描述**

无效的窗口id。

**可能原因**

传入非当前应用的窗口id。

**处理步骤**

请检查并传入当前应用的窗口id，可通过windowClass.[getWindowProperties()](../apis-arkui/js-apis-window.md#getwindowproperties9)接口获取当前窗口属性，窗口属性中含有窗口id。