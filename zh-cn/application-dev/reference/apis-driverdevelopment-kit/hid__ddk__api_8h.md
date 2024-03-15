# hid_ddk_api.h


## 概述

声明主机侧访问输入设备的HID DDK接口。

引用文件：&lt;hid/hid_ddk_api.h&gt;

**起始版本：** 11

**相关模块：**[HID DDK](_hid_ddk.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Hid_CreateDevice](_hid_ddk.md#oh_hid_createdevice) ([Hid_Device](_hid___device.md) \*hidDevice, [Hid_EventProperties](_hid___event_properties.md) \*hidEventProperties) | 创建设备。  | 
| [OH_Hid_EmitEvent](_hid_ddk.md#oh_hid_emitevent) (int32_t deviceId, const [Hid_EmitItem](_hid___emit_item.md) items[], uint16_t length) | 向指定设备发送事件列表。  | 
| [OH_Hid_DestroyDevice](_hid_ddk.md#oh_hid_destroydevice) (int32_t deviceId) | 销毁设备。  | 
