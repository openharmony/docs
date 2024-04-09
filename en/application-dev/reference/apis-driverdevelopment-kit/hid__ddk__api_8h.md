# hid_ddk_api.h


## Overview

Declares the HID DDK functions for accessing an input device from the host.

File to include: &lt;hid/hid_ddk_api.h&gt;

**Since**: 11

**Related module**: [HID DDK](_hid_ddk.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Hid_CreateDevice](_hid_ddk.md#oh_hid_createdevice) ([Hid_Device](_hid___device.md) \*hidDevice, [Hid_EventProperties](_hid___event_properties.md) \*hidEventProperties) | Creates a device. | 
| [OH_Hid_EmitEvent](_hid_ddk.md#oh_hid_emitevent) (int32_t deviceId, const [Hid_EmitItem](_hid___emit_item.md) items[], uint16_t length) | Sends an event list to a device. | 
| [OH_Hid_DestroyDevice](_hid_ddk.md#oh_hid_destroydevice) (int32_t deviceId) | Destroys a device. | 
