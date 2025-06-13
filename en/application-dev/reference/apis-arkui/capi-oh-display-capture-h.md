# oh_display_capture.h

## Overview

The **oh_display_capture.h** file declares the capability to take screenshots.

**File to include**: <window_manager/oh_display_capture.h>

**Library**: libnative_display_manager.so

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 14

**Related module**: [OH_DisplayManager](capi-oh-displaymanager.md)

## Summary

### Function

| Name| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CaptureScreenPixelmap(uint32_t displayId,OH_PixelmapNative **pixelMap)](#oh_nativedisplaymanager_capturescreenpixelmap) | Takes a screenshot of the entire screen. This function can be used only on tablets and 2-in-1 devices. It can be used to capture a full-screen screenshot on the specified display.|

## Function Description

### OH_NativeDisplayManager_CaptureScreenPixelmap()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CaptureScreenPixelmap(uint32_t displayId,OH_PixelmapNative **pixelMap)
```

**Description**

Takes a screenshot of the entire screen. This function can be used only on tablets and 2-in-1 devices. It can be used to capture a full-screen screenshot on the specified display.

**System capability**: SystemCapability.Window.SessionManager.Core

**Required permissions**: ohos.permission.CUSTOM_SCREEN_CAPTURE

**Since**: 14

**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t displayId | ID of the display. The value must be a non-negative integer.|
| [OH_PixelmapNative](../apis-image-kit/capi-oh-pixelmapnative.md **pixelMap | Double pointer to an **OH_PixelmapNative** object, which is the screenshot taken.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|
