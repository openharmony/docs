# UsbControlRequestSetup


## Overview

Setup data for control transfer. It corresponds to <b>Setup Data</b> in the USB protocol.

**Since**

10

**Related Modules**

[USB DDK](_usb_ddk.md)

**Header file**: [usb_ddk_types.h](usb__ddk__types_8h.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [bmRequestType](#bmrequesttype) | Request type.|
| [bRequest](#brequest) | Specific request.|
| [wValue](#wvalue) | Value corresponding to **wValue** in the USB protocol. Its meaning varies according to the request.|
| [wIndex](#windex) | Index corresponding to **wIndex** in the USB protocol. It is usually used to transfer the index or offset. Its meaning varies according to the request. |
| [wLength](#wlength) | Data length corresponding to **wLength** in the USB protocol. If data is transferred, this field indicates the number of transferred bytes.|


## Member Variable Description


### wIndex


```
uint16_t UsbControlRequestSetup::wIndex
```

**Description**

Index corresponding to **wIndex** in the USB protocol. It is usually used to transfer the index or offset. Its meaning varies according to the request. 


### wLength


```
uint16_t UsbControlRequestSetup::wLength
```

**Description**

Data length, corresponding to **wLength** in the USB protocol. If data is transferred, this field indicates the number of transferred bytes.


### bRequest


```
uint8_t UsbControlRequestSetup::bRequest
```

**Description**

Specific request.


### bmRequestType


```
uint8_t UsbControlRequestSetup::bmRequestType
```

**Description**

Request type.


### wValue


```
uint16_t UsbControlRequestSetup::wValue
```

**Description**

Value corresponding to **wValue** in the USB protocol. Its meaning varies according to the request.
