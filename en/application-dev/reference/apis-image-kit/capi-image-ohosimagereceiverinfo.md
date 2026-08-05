# OhosImageReceiverInfo

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T04:03:24.319Z pushedAt=2026-08-04T02:54:48.635Z -->

```c
struct OhosImageReceiverInfo {...}
```

## Overview

The struct describes the information about an image receiver.

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_receiver_mdk.h](capi-image-receiver-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t width | Default width of the image received by the consumer, in pixels.|
| int32_t height | Default height of the image received by the consumer, in pixels.|
| int32_t format | Image format **OHOS_IMAGE_FORMAT_JPEG** created by using the receiver.|
| int32_t capicity | Maximum number of images that can be cached. This parameter is used only as an expected value. The actual capacity is determined by the device hardware.|