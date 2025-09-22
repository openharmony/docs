# ArkUI_AnimateCompleteCallback
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

## Overview

Defines the callback type for when the animation playback is complete.

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Header file**: [native_animate.h](capi-native-animate-h.md)

## Summary

### Member Variables

| Name                                                                             | Description|
|---------------------------------------------------------------------------------| -- |
| [ArkUI_FinishCallbackType](capi-native-type-h.md#arkui_finishcallbacktype) type | Type of the **onFinish** callback.|
| void* userData                                                                  | Custom type.|


### Member Functions

| Name| Description|
| -- | -- |
| [void (\*callback)(void* userData)](#callback) | Callback invoked when the animation playback is complete.|

## Member Function Description

### callback()

```
void (*callback)(void* userData)
```

**Description**


Callback invoked when the animation playback is complete.
