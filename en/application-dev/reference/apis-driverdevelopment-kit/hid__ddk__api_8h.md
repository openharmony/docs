# hid_ddk_api.h


## Overview

Declares the HID DDK functions for accessing an input device from the host.

**File to include**: &lt;hid/hid_ddk_api.h&gt;

**Since**: 11

**Related module**: [HID DDk](_hid_ddk.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_Hid_CreateDevice](_hid_ddk.md#oh_hid_createdevice) ([Hid_Device](_hid___device.md) \*hidDevice, [Hid_EventProperties](_hid___event_properties.md) \*hidEventProperties) | Creates a device. | 
| int32_t [OH_Hid_EmitEvent](_hid_ddk.md#oh_hid_emitevent) (int32_t deviceId, const [Hid_EmitItem](_hid___emit_item.md) items[], uint16_t length) | Sends an event list to a device. | 
| int32_t [OH_Hid_DestroyDevice](_hid_ddk.md#oh_hid_destroydevice) (int32_t deviceId) | Destroys a device. | 
| int32_t [OH_Hid_Init](_hid_ddk.md#oh_hid_init) (void) | Initializes the HID DDK. | 
| int32_t [OH_Hid_Release](_hid_ddk.md#oh_hid_release) (void) | Releases the HID DDK. | 
| int32_t [OH_Hid_Open](_hid_ddk.md#oh_hid_open) (uint64_t deviceId, uint8_t interfaceIndex, [Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*\*dev) | Opens the device specified by **deviceId** and **interfaceIndex**. | 
| int32_t [OH_Hid_Close](_hid_ddk.md#oh_hid_close) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*\*dev) | Closes a HID device. | 
| int32_t [OH_Hid_Write](_hid_ddk.md#oh_hid_write) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, uint8_t \*data, uint32_t length, uint32_t \*bytesWritten) | Writes a report to a HID device. | 
| int32_t [OH_Hid_ReadTimeout](_hid_ddk.md#oh_hid_readtimeout) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, uint8_t \*data, uint32_t bufSize, int timeout, uint32_t \*bytesRead) | Reads a report from a HID device within the specified time. | 
| int32_t [OH_Hid_Read](_hid_ddk.md#oh_hid_read) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, uint8_t \*data, uint32_t bufSize, uint32_t \*bytesRead) | Reads reports from the HID device. The blocking mode (that is, blocking remains active until data can be read) is used by default. You can call [OH_Hid_SetNonBlocking](_hid_ddk.md#oh_hid_setnonblocking) to change the mode. | 
| int32_t [OH_Hid_SetNonBlocking](_hid_ddk.md#oh_hid_setnonblocking) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, int nonBlock) | Sets the device read mode to non-blocking mode. | 
| int32_t [OH_Hid_GetRawInfo](_hid_ddk.md#oh_hid_getrawinfo) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, [Hid_RawDevInfo](_hid___raw_dev_info.md) \*rawDevInfo) | Obtains the raw information of a HID device. | 
| int32_t [OH_Hid_GetRawName](_hid_ddk.md#oh_hid_getrawname) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, char \*data, uint32_t bufSize) | Obtains the raw name of a HID device. | 
| int32_t [OH_Hid_GetPhysicalAddress](_hid_ddk.md#oh_hid_getphysicaladdress) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, char \*data, uint32_t bufSize) | Obtains the physical address of a HID device. | 
| int32_t [OH_Hid_GetRawUniqueId](_hid_ddk.md#oh_hid_getrawuniqueid) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, uint8_t \*data, uint32_t bufSize) | Obtains the raw unique identifier of a HID device. | 
|<!--DelRow--> int32_t [OH_Hid_SendReport](_hid_ddk.md#oh_hid_sendreport) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, [Hid_ReportType](_hid_ddk.md#hid_reporttype) reportType, const uint8_t \*data, uint32_t length) | Sends a report to a HID device. | 
|<!--DelRow--> int32_t [OH_Hid_GetReport](_hid_ddk.md#oh_hid_getreport) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, [Hid_ReportType](_hid_ddk.md#hid_reporttype) reportType, uint8_t \*data, uint32_t bufSize) | Obtains a report from a HID device. | 
| int32_t [OH_Hid_GetReportDescriptor](_hid_ddk.md#oh_hid_getreportdescriptor) ([Hid_DeviceHandle](_hid_ddk.md#hid_devicehandle) \*dev, uint8_t \*buf, uint32_t bufSize, uint32_t \*bytesRead) | Obtains the report descriptor of a HID device. | 
