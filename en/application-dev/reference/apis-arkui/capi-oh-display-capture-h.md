# oh_display_capture.h
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @oh_wangxk; @logn-->
<!--Designer: @hejunfei1991-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## Overview

The file declares the capability to take screenshots.

**File to include**: <window_manager/oh_display_capture.h>

**Library**: libnative_display_manager.so

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 14

**Related module**: [OH_DisplayManager](capi-oh-displaymanager.md)

## Summary

### Function

| Name| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CaptureScreenPixelmap(uint32_t displayId,OH_PixelmapNative **pixelMap)](#oh_nativedisplaymanager_capturescreenpixelmap) | Takes a screenshot of the entire screen. This function can be used to capture a full-screen screenshot on the specified display.|

## Function Description

### OH_NativeDisplayManager_CaptureScreenPixelmap()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CaptureScreenPixelmap(uint32_t displayId,OH_PixelmapNative **pixelMap)
```

**Description**

Takes a screenshot of the entire screen. This function can be used to capture a full-screen screenshot on the specified display.

**Required permissions**: ohos.permission.CUSTOM_SCREEN_CAPTURE

**Since**: 14

**Device behavior differences**: This API can be properly called on 2-in-1 devices and tablets. If it is called on other device types, error code 801 is returned.

**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t displayId | ID of the display. The value must be a non-negative integer.|
| [OH_PixelmapNative](../apis-image-kit/capi-image-nativemodule-oh-pixelmapnative.md) **pixelMap | Double pointer to an OH_PixelmapNative object, which is the screenshot taken.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|
