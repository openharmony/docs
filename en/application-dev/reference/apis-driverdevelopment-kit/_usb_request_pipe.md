# UsbRequestPipe


## Overview

Defines a USB request pipe.

**Since**

10

**Related Modules**

[USB DDK](_usb_ddk.md)

**Header file**: [usb_ddk_types.h](usb__ddk__types_8h.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [interfaceHandle](#interfacehandle) | Interface operation handle.|
| [endpoint](#endpoint) | Endpoint address.|
| [timeout](#timeout) | Timeout duration, in milliseconds.|


## Member Variable Description


### endpoint


```
uint8_t UsbRequestPipe::endpoint
```

**Description**

Endpoint address.


### interfaceHandle


```
uint64_t UsbRequestPipe::interfaceHandle
```

**Description**

Interface operation handle.


### timeout


```
uint32_t UsbRequestPipe::timeout
```

**Description**

Timeout duration, in milliseconds.
