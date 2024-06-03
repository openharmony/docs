# UsbDdkInterfaceDescriptor


## Overview

Defines interface descriptors.

**Since**

10

**Related Modules**

[UsbDdk](_usb_ddk.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [interfaceDescriptor](#interfacedescriptor) | Standard interface descriptor.|
| [endPoint](#endpoint) | Endpoint descriptor contained in the interface.|
| [extra](#extra) | Unresolved descriptor, including class- or vendor-specific descriptors.|
| [extraLength](#extralength) | Length of the unresolved descriptor.|


## Member Variable Description


### endPoint


```
struct UsbDdkEndpointDescriptor* UsbDdkInterfaceDescriptor::endPoint
```

**Description**

Endpoint descriptor contained in the interface.


### extra


```
const uint8_t* UsbDdkInterfaceDescriptor::extra
```

**Description**

Unresolved descriptor, including class- or vendor-specific descriptors.


### extraLength


```
uint32_t UsbDdkInterfaceDescriptor::extraLength
```

**Description**

Length of the unresolved descriptor.


### interfaceDescriptor


```
struct UsbInterfaceDescriptor UsbDdkInterfaceDescriptor::interfaceDescriptor
```

**Description**

Standard interface descriptor.
