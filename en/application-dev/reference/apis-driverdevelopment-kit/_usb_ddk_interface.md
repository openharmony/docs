# UsbDdkInterface


## Overview

Defines a USB DDK interface, which is a collection of alternate settings for a particular USB interface.

**Since**

10

**Related Modules**

[UsbDdk](_usb_ddk.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [numAltsetting](#numaltsetting) | Number of alternate settings of the interface.|
| [altsetting](#altsetting) | Alternate setting of the interface.|


## Member Variable Description


### altsetting


```
struct UsbDdkInterfaceDescriptor* UsbDdkInterface::altsetting
```

**Description**

Alternate setting of the interface.


### numAltsetting


```
uint8_t UsbDdkInterface::numAltsetting
```

**Description**

Number of alternate settings of the interface.
