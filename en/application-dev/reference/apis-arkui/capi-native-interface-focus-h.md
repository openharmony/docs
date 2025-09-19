# native_interface_focus.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

## Overview

Declares APIs for focus management, mainly used for actively transferring focus, managing the default focus transfer behavior, and controlling the focus activation state.

**File to include**: <arkui/native_interface_focus.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 15

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_KeyProcessingMode](#arkui_keyprocessingmode) | ArkUI_KeyProcessingMode | Enumerates the key event processing priority modes.|

### Functions

| Name| Description|
| -- | -- |
| [ArkUI_ErrorCode OH_ArkUI_FocusRequest(ArkUI_NodeHandle node)](#oh_arkui_focusrequest) | Requests focus for a specific node.|
| [void OH_ArkUI_FocusClear(ArkUI_ContextHandle uiContext)](#oh_arkui_focusclear) | Clears the focus to the root container node.|
| [void OH_ArkUI_FocusActivate(ArkUI_ContextHandle uiContext, bool isActive, bool isAutoInactive)](#oh_arkui_focusactivate) | Sets the focus activation state for the current page. When activated, the focused node displays a focus box.|
| [void OH_ArkUI_FocusSetAutoTransfer(ArkUI_ContextHandle uiContext, bool autoTransfer)](#oh_arkui_focussetautotransfer) | Configures the focus transfer behavior when pages are switched.|
| [void OH_ArkUI_FocusSetKeyProcessingMode(ArkUI_ContextHandle uiContext, ArkUI_KeyProcessingMode mode)](#oh_arkui_focussetkeyprocessingmode) | Sets the mode for processing key events.|

## Enum Description

### ArkUI_KeyProcessingMode

```
enum ArkUI_KeyProcessingMode
```

**Description**


Enumerates the key event processing priority modes.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_KEY_PROCESSING_MODE_FOCUS_NAVIGATION = 0 | Key events are used for focus navigation.|
| ARKUI_KEY_PROCESSING_MODE_FOCUS_ANCESTOR_EVENT | Key events are passed up to ancestor components.|


## Function Description

### OH_ArkUI_FocusRequest()

```
ArkUI_ErrorCode OH_ArkUI_FocusRequest(ArkUI_NodeHandle node)
```

**Description**


Requests focus for a specific node.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Node.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE](capi-native-type-h.md#arkui_errorcode) if the node cannot receive focus.<br>         Returns [ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE_ANCESTOR](capi-native-type-h.md#arkui_errorcode) if the ancestor node cannot receive focus.<br>         Returns [ARKUI_ERROR_CODE_FOCUS_NON_EXISTENT](capi-native-type-h.md#arkui_errorcode) if the node does not exist.|

### OH_ArkUI_FocusClear()

```
void OH_ArkUI_FocusClear(ArkUI_ContextHandle uiContext)
```

**Description**


Clears the focus to the root container node.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | UI instance object pointer.|

### OH_ArkUI_FocusActivate()

```
void OH_ArkUI_FocusActivate(ArkUI_ContextHandle uiContext, bool isActive, bool isAutoInactive)
```

**Description**


Sets the focus activation state for the current page. When activated, the focused node displays a focus box.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | UI instance object pointer.|
| bool isActive | Whether to enter or exit the focus activation state. The value **true** means to enter the focus activation state, and **false** means to exit the focus activation state.|
| bool isAutoInactive | Whether to automatically exit the focus active state on touch or mouse down events. **true**: Automatically exit the focus active state. **false**: Maintain the current state until the corresponding setting API is called.|

### OH_ArkUI_FocusSetAutoTransfer()

```
void OH_ArkUI_FocusSetAutoTransfer(ArkUI_ContextHandle uiContext, bool autoTransfer)
```

**Description**


Configures the focus transfer behavior when pages are switched.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | UI instance object pointer.|
| bool autoTransfer | Whether to automatically transfer focus when pages are switched. The value **true** means to automatically transfer focus when pages are switched, and **false** means the opposite.|

### OH_ArkUI_FocusSetKeyProcessingMode()

```
void OH_ArkUI_FocusSetKeyProcessingMode(ArkUI_ContextHandle uiContext, ArkUI_KeyProcessingMode mode)
```

**Description**


Sets the mode for processing key events.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md) uiContext | UI instance object pointer.|
| [ArkUI_KeyProcessingMode](capi-native-interface-focus-h.md#arkui_keyprocessingmode) mode | Key event processing priority mode.|
