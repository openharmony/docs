# OhosImageReceiverInfo
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## Overview

The OhosImageReceiverInfo struct describes the information about an image receiver.

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
| int32_t capicity | Maximum number of images that can be cached.|
