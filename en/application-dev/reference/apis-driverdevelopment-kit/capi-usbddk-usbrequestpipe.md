# UsbRequestPipe

<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=80a690690bb3dbcda24d03e53bc7c3a287326f14 translatedAt=2026-07-28T07:00:58.041Z pushedAt=2026-07-28T08:40:44.013Z -->

```c
typedef struct UsbRequestPipe {...} __attribute__((aligned(8))) UsbRequestPipe
```

## Overview

Defines a USB request pipe.

**Since**: 10

**Related module**: [UsbDdk](capi-usbddk.md)

**Header file:** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint64_t interfaceHandle | Interface operation handle.|
| uint32_t timeout | Timeout duration, in milliseconds. |
| uint8_t endpoint | Endpoint address.|