# Usb_DeviceArray


## Overview

Defines the device ID list, which is used to store the device IDs and device quantity obtained using [OH_Usb_GetDevices()](_usb_ddk.md#oh_usb_getdevices16).

**Since**

16

**Related Modules**

[USB DDK](_usb_ddk.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [deviceIds](#deviceids) | Start address of the device ID array.|
| [num](#num) | Device quantity.|

## Member Variable Description


### deviceIds


```
uint64_t* Usb_DeviceArray::deviceIds
```

**Description**

Defines the start address of the device ID array. The number of device IDs cannot exceed 128.
### num


```
uint32_t Usb_DeviceArray::num
```

**Description**

Defines the device quantity. Device IDs are obtained by traversing **deviceIds** based on the value of this parameter. If the value is **0**, there is no USB device.
