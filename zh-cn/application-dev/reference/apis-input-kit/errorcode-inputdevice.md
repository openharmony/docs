# 输入设备错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 26500001 无效的windowId

**错误信息**

windowId is invalid.

**错误描述**

无效的窗口id。

**可能原因**

传入非当前应用的窗口id。

**处理步骤**

请检查并传入当前应用的窗口id，可通过windowClass.[getWindowProperties()](../apis-arkui/js-apis-window.md#getwindowproperties9)接口获取当前窗口属性，窗口属性中含有窗口id。