# UsbConfigDescriptor


## Overview

Defines standard configuration descriptors, which correspond to **Standard Configuration Descriptor** in the USB protocol.

**Since**

10

**Related Modules**

[USB DDK](_usb_ddk.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [bLength](#blength) | Size of the descriptor, in bytes.|
| [bDescriptorType](#bdescriptortype) | Descriptor type.|
| [wTotalLength](#wtotallength) | Total length of the configuration descriptor, including the configuration, interface, endpoint, and class- or vendor-specific descriptors.|
| [bNumInterfaces](#bnuminterfaces) | Number of interfaces supported by the configuration.|
| [bConfigurationValue](#bconfigurationvalue) | Configuration index, which is used to select the configuration.|
| [iConfiguration](#iconfiguration) | Index of the string descriptor that describes the configuration.|
| [bmAttributes](#bmattributes) | Configuration attributes, including the power mode and remote wakeup.|
| [bMaxPower](#bmaxpower) | Maximum power consumption of the bus-powered USB device, in 2 mA.|


## Member Variable Description


### bConfigurationValue


```
uint8_t UsbConfigDescriptor::bConfigurationValue
```

**Description**

Configuration index, which is used to select the configuration.


### bDescriptorType


```
uint8_t UsbConfigDescriptor::bDescriptorType
```

**Description**

Descriptor type.


### bLength


```
uint8_t UsbConfigDescriptor::bLength
```

**Description**

Size of the descriptor, in bytes.


### bmAttributes


```
uint8_t UsbConfigDescriptor::bmAttributes
```

**Description**

Configuration attributes, including the power mode and remote wakeup.


### bMaxPower


```
uint8_t UsbConfigDescriptor::bMaxPower
```

**Description**

Maximum power consumption of the bus-powered USB device, in 2 mA.


### bNumInterfaces


```
uint8_t UsbConfigDescriptor::bNumInterfaces
```

**Description**

Number of interfaces supported by the configuration.


### iConfiguration


```
uint8_t UsbConfigDescriptor::iConfiguration
```

**Description**

Index of the string descriptor that describes the configuration.


### wTotalLength


```
uint16_t UsbConfigDescriptor::wTotalLength
```

**Description**

Total length of the configuration descriptor, including the configuration, interface, endpoint, and class- or vendor-specific descriptors.
