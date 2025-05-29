# native_interface_focus.h


## Overview

Declares the APIs of **NativeFocus**.

**Library**: libace_ndk.z.so

**File to include**: <arkui/native_interface_focus.h>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 15

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary

### ArkUI_KeyProcessingMode

```
enum ArkUI_KeyProcessingMode
```
**Description**

Sets the mode for processing key events when a component cannot process them.

**Since**: 15

| Name         | Description       |
| ----------- | --------- |
| ARKUI_KEY_PROCESSING_MODE_FOCUS_NAVIGATION | Key events are used for focus navigation. Default value.|
| ARKUI_KEY_PROCESSING_MODE_FOCUS_ANCESTOR_EVENT |  Key events are propagated upwards to the ancestor components.|

### Functions

| Name| Description| 
| -------- | -------- |
|[ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode)  OH_ArkUI_FocusRequest([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node); | Requests focus for a specific node.|
| void OH_ArkUI_FocusClear([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) uiContext); | Clears the focus to the root container node.|
| void OH_ArkUI_FocusActivate([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) uiContext, bool isActive, bool isAutoInactive); | Sets the focus activation state for the current page. When activated, the focused node displays a focus box.|
| void OH_ArkUI_FocusSetAutoTransfer([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) uiContext, bool autoTransfer); | Configures the focus transfer behavior when pages are switched.| 
| void OH_ArkUI_FocusSetKeyProcessingMode([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) uiContext, [ArkUI_KeyProcessingMode](#arkui_keyprocessingmode) mode); | Configures the focus transfer behavior when pages are switched.| 
