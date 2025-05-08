# UsbDdkEndpointDescriptor


## Overview

Defines endpoint descriptors.

**Since**

10

**Related Modules**

[USB DDK](_usb_ddk.md)

**Header file**: [usb_ddk_types.h](usb__ddk__types_8h.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [endpointDescriptor](#endpointdescriptor) | Standard endpoint descriptor.|
| [extra](#extra) | Unresolved descriptor, including class- or vendor-specific descriptors.|
| [extraLength](#extralength) | Length of the unresolved descriptor.|


## Member Variable Description


### endpointDescriptor


```
struct UsbEndpointDescriptor UsbDdkEndpointDescriptor::endpointDescriptor
```

**Description**

Standard endpoint descriptor.


### extra


```
const uint8_t* UsbDdkEndpointDescriptor::extra
```

**Description**

Unresolved descriptor, including class- or vendor-specific descriptors.


### extraLength


```
uint32_t UsbDdkEndpointDescriptor::extraLength
```

**Description**

Length of the unresolved descriptor.
