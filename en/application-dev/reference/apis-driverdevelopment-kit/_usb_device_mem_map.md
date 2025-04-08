# UsbDeviceMemMap


## Overview

Device memory map created by calling [OH_Usb_CreateDeviceMemMap()](_usb_ddk.md#oh_usb_createdevicememmap). A buffer using the device memory map can provide better performance.

**Since**

10

**Related Modules**

[USB DDK](_usb_ddk.md)

**Header file**: [usb_ddk_types.h](usb__ddk__types_8h.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [address](#address) |  Buffer address.|
| [size](#size) | Buffer size.|
| [offset](#offset) | Offset of the used buffer. The default value is 0, indicating that there is no offset and the buffer starts from the specified address.|
| [bufferLength](#bufferlength) | Length of the used buffer. By default, the value is equal to the size, indicating that the entire buffer is used.|
| [transferedLength](#transferedlength) | Length of the transferred data.|


## Member Variable Description


### address


```
uint8_t* const UsbDeviceMemMap::address
```

**Description**

 Buffer address.


### bufferLength


```
uint32_t UsbDeviceMemMap::bufferLength
```

**Description**

Length of the used buffer. By default, the value is equal to the size, indicating that the entire buffer is used.


### offset


```
uint32_t UsbDeviceMemMap::offset
```

**Description**

Offset of the used buffer. The default value is 0, indicating that there is no offset and the buffer starts from the specified address.


### size


```
const size_t UsbDeviceMemMap::size
```

**Description**

Buffer size.


### transferedLength


```
uint32_t UsbDeviceMemMap::transferedLength
```

**Description**

Length of the transferred data.
