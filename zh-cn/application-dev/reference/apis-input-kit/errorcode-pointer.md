# 鼠标指针错误码

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @Brilliantry_Rui-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 26500001 无效的windowId

**错误信息**

Invalid windowId. Possible causes: The window id does not belong to the current process.

**错误描述**

无效的窗口id。

**可能原因**

窗口id不属于当前进程。

**处理步骤**

请检查并传入当前进程的窗口id，可通过windowClass.[getWindowProperties()](../apis-arkui/arkts-apis-window-Window.md#getwindowproperties9)接口获取当前窗口属性，窗口属性中含有窗口id。