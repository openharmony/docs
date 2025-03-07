# UsbEndpointDescriptor


## Overview

Defines standard endpoint descriptors, which correspond to **Standard Endpoint Descriptor** in the USB protocol.

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
| [bEndpointAddress](#bendpointaddress) | Endpoint address, including the endpoint number and endpoint direction.|
| [bmAttributes](#bmattributes) | Endpoint attributes, including the transfer type, synchronization type, and usage type.|
| [wMaxPacketSize](#wmaxpacketsize) | Maximum packet size supported by an endpoint.|
| [bInterval](#binterval) | Interval for polling endpoints for data transfer.|
| [bRefresh](#brefresh) | Refresh rate for audio devices.|
| [bSynchAddress](#bsynchaddress) | Endpoint synchronization address for audio devices.|


## Member Variable Description


### bDescriptorType


```
uint8_t UsbEndpointDescriptor::bDescriptorType
```

**Description**

Descriptor type.


### bEndpointAddress


```
uint8_t UsbEndpointDescriptor::bEndpointAddress
```

**Description**

Endpoint address, including the endpoint number and endpoint direction.


### bInterval


```
uint8_t UsbEndpointDescriptor::bInterval
```

**Description**

Interval for polling endpoints for data transfer.


### bLength


```
uint8_t UsbEndpointDescriptor::bLength
```

**Description**

Size of the descriptor, in bytes.


### bmAttributes


```
uint8_t UsbEndpointDescriptor::bmAttributes
```

**Description**

Endpoint attributes, including the transfer type, synchronization type, and usage type.


### bRefresh


```
uint8_t UsbEndpointDescriptor::bRefresh
```

**Description**

Refresh rate for audio devices.


### bSynchAddress


```
uint8_t UsbEndpointDescriptor::bSynchAddress
```

**Description**

Endpoint synchronization address for audio devices.


### wMaxPacketSize


```
uint16_t UsbEndpointDescriptor::wMaxPacketSize
```

**Description**

Maximum packet size supported by an endpoint.
