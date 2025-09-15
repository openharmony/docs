# ArkWeb_BlanklessInfo
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @Shenxiaoliang1-->
<!--Designer: @ctqctq99-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

## Overview

Describes prediction information about blankless loading, including the first screen similarity, first screen loading duration, and error codes. The application determines whether to enable the blankless loading solution based on the prediction information.

**Since**: 20

**Related module**: [Web](capi-web.md)

**Header file**: [native_interface_arkweb.h](capi-native-interface-arkweb-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| ArkWeb_BlanklessErrorCode errCode | Error codes of blankless loading. For details, see [ArkWeb_BlanklessErrorCode](./capi-arkweb-error-code-h.md#arkweb_blanklesserrorcode).|
| double similarity | First screen similarity, which is calculated based on the historical first screen content. The value ranges from 0 to 1.0. 1.0 indicates that the content is the same. A value closer to 1 indicates a higher similarity. This value is lagging, and the similarity of the local loading is displayed in the next loading. You are advised not to enable the blankless loading frame insertion solution when the similarity is low.|
| int32_t loadingTime | Loading duration estimated based on the historical first screen loading durations, in milliseconds. The value must be greater than 0.|
