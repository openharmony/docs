# 输入设备错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 3900001 指定的设备不存在

**错误信息**

The specified device does not exist.

**错误描述**

指定的设备Id在多模设备列表中找不到，会产生此错误码。

**可能原因**

1. 输入设备的设备Id变更；
2. 输入设备的物理连接断开。

**处理步骤**

1. 可以通过[inputDevice.getDeviceList](js-apis-inputdevice.md)接口查询设备Id，然后使用正确的设备Id操作。
