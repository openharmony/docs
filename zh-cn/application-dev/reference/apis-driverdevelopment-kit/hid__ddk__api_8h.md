# hid_ddk_api.h


## 概述

声明主机侧访问输入设备的HID DDK接口。

引用文件：&lt;[hid/hid_ddk_api.h](zh-cn_topic_0000002188217729.xml)&gt;

**起始版本：** 11

**相关模块：**[HidDdk](_hid_ddk.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_Hid_CreateDevice](_hid_ddk.md#oh_hid_createdevice) ([Hid_Device](_hid___device.md) \*hidDevice, [Hid_EventProperties](_hid___event_properties.md) \*hidEventProperties) | 创建设备。  | 
| int32_t [OH_Hid_EmitEvent](_hid_ddk.md#oh_hid_emitevent) (int32_t deviceId, const [Hid_EmitItem](_hid___emit_item.md) items[], uint16_t length) | 向指定设备发送事件列表。  | 
| int32_t [OH_Hid_DestroyDevice](_hid_ddk.md#oh_hid_destroydevice) (int32_t deviceId) | 销毁设备。  | 
| int32_t [OH_Hid_Init](_hid_ddk.md#oh_hid_init) (void) | 初始化HID DDK。  | 
| int32_t [OH_Hid_Release](_hid_ddk.md#oh_hid_release) (void) | 释放HID DDK。  | 
| int32_t [OH_Hid_Open](_hid_ddk.md#oh_hid_open) (uint64_t deviceId, uint8_t interfaceIndex, [Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*\*dev) | 打开deviceId和interfaceIndex指定的设备。  | 
| int32_t [OH_Hid_Close](_hid_ddk.md#oh_hid_close) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*\*dev) | 关闭设备。  | 
| int32_t [OH_Hid_Write](_hid_ddk.md#oh_hid_write) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, uint8_t \*data, uint32_t length, uint32_t \*bytesWritten) | 向设备写入报告。  | 
| int32_t [OH_Hid_ReadTimeout](_hid_ddk.md#oh_hid_readtimeout) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, uint8_t \*data, uint32_t bufSize, int timeout, uint32_t \*bytesRead) | 在指定的超时时间内从设备读取报告。  | 
| int32_t [OH_Hid_Read](_hid_ddk.md#oh_hid_read) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, uint8_t \*data, uint32_t bufSize, uint32_t \*bytesRead) | 从设备读取报告，默认为阻塞模式（阻塞等待直到有数据可读取），可以调用[OH_Hid_SetNonBlocking](_hid_ddk.md#oh_hid_setnonblocking)改变模式。  | 
| int32_t [OH_Hid_SetNonBlocking](_hid_ddk.md#oh_hid_setnonblocking) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, int nonBlock) | 设置设备读取模式为非阻塞。  | 
| int32_t [OH_Hid_GetRawInfo](_hid_ddk.md#oh_hid_getrawinfo) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, [Hid_RawDevInfo](_hid___raw_dev_info.md) \*rawDevInfo) | 获取设备原始信息。  | 
| int32_t [OH_Hid_GetRawName](_hid_ddk.md#oh_hid_getrawname) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, char \*data, uint32_t bufSize) | 获取设备原始名称。  | 
| int32_t [OH_Hid_GetPhysicalAddress](_hid_ddk.md#oh_hid_getphysicaladdress) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, char \*data, uint32_t bufSize) | 获取设备物理地址。  | 
| int32_t [OH_Hid_GetRawUniqueId](_hid_ddk.md#oh_hid_getrawuniqueid) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, uint8_t \*data, uint32_t bufSize) | 获取设备原始唯一标识符。  | 
| int32_t [OH_Hid_SendReport](_hid_ddk.md#oh_hid_sendreport) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, [Hid_ReportType](_hid_ddk.md#hid_reporttype) reportType, const uint8_t \*data, uint32_t length) | 向设备发送报告。  | 
| int32_t [OH_Hid_GetReport](_hid_ddk.md#oh_hid_getreport) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, [Hid_ReportType](_hid_ddk.md#hid_reporttype) reportType, uint8_t \*data, uint32_t bufSize) | 获取设备报告。  | 
| int32_t [OH_Hid_GetReportDescriptor](_hid_ddk.md#oh_hid_getreportdescriptor) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, uint8_t \*buf, uint32_t bufSize, uint32_t \*bytesRead) | 获取设备报告描述符。  | 
