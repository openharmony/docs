# ArkUI_AccessibilityProviderCallbacks
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhanghangkai10241-->
<!--Designer: @lmleon-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @HelloCrease-->

## Overview

Defines a struct for third-party accessibility provider callback functions, which third-party platforms need to implement. These functions are registered with the system side through **OH_ArkUI_AccessibilityProviderRegisterCallback**.

**Since**: 13

**Related module**: [ArkUI_Accessibility](capi-arkui-accessibility.md)

**Header file**: [native_interface_accessibility.h](capi-native-interface-accessibility-h.md)

## Summary

### Member Functions

| Name| Description|
| -- | -- |
| [int32_t (\*findAccessibilityNodeInfosById)(int64_t elementId, ArkUI_AccessibilitySearchMode mode,int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)](#findaccessibilitynodeinfosbyid) | Callback function implemented by the third-party platform and registered with the system. Finds node information for the specified node. Multi-instance scenarios are supported.|
| [int32_t (\*findAccessibilityNodeInfosByText)(int64_t elementId, const char* text, int32_t requestId,ArkUI_AccessibilityElementInfoList* elementList)](#findaccessibilitynodeinfosbytext) | Callback function implemented by the third-party platform and registered with the system. Finds the nodes that contain specific text content.|
| [int32_t (\*findFocusedAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusType focusType,int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)](#findfocusedaccessibilitynode) | Called to obtain focused element information based on a specified node.|
| [int32_t (\*findNextFocusAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction,int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)](#findnextfocusaccessibilitynode) | Called to find the next focusable node based on the reference node, in the specified mode and direction.|
| [int32_t (\*executeAccessibilityAction)(int64_t elementId, ArkUI_Accessibility_ActionType action,ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId)](#executeaccessibilityaction) | Called to execute a specified action on a specified node.|
| [int32_t (\*clearFocusedFocusAccessibilityNode)()](#clearfocusedfocusaccessibilitynode) | Called to clear the focus state of the current focused node.|
| [int32_t (\*getAccessibilityNodeCursorPosition)(int64_t elementId, int32_t requestId, int32_t* index)](#getaccessibilitynodecursorposition) | Called to query the current cursor position of the specified node.|

## Member Function Description

### findAccessibilityNodeInfosById()

```
int32_t (*findAccessibilityNodeInfosById)(int64_t elementId, ArkUI_AccessibilitySearchMode mode,int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)
```

**Description**


Callback function implemented by the third-party platform and registered with the system. Finds node information for the specified node. Multi-instance scenarios are supported.

**Since**: 13

**Parameters**

| Name                                                                           | Description|
|--------------------------------------------------------------------------------| -- |
| int64_t elementId                                                              | Unique ID of the accessibility element.|
| [ArkUI_AccessibilitySearchMode](capi-native-interface-accessibility-h.md) mode | Accessibility search mode.|
| int32_t requestId                                                              | Request ID.|
| [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md)* elementList                            | Accessibility element information list.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### findAccessibilityNodeInfosByText()

```
int32_t (*findAccessibilityNodeInfosByText)(int64_t elementId, const char* text, int32_t requestId,ArkUI_AccessibilityElementInfoList* elementList)
```

**Description**

Callback function implemented by the third-party platform and registered with the system. Finds the nodes that contain specific text content.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| int64_t elementId | Unique ID of the accessibility element.|
|  const char* text | Accessibility text.|
|  int32_t requestId | Request ID.|
| [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md)* elementList | Accessibility element information list.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### findFocusedAccessibilityNode()

```
int32_t (*findFocusedAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusType focusType,int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)
```

**Description**

Called to obtain focused element information based on a specified node.

**Since**: 13

**Parameters**

| Name                                                                                                            | Description|
|-----------------------------------------------------------------------------------------------------------------| -- |
| int64_t elementId                                                                                               | Unique ID of the accessibility element.|
| [ArkUI_AccessibilityFocusType](capi-native-interface-accessibility-h.md#arkui_accessibilityfocustype) focusType | Focus type.|
| int32_t requestId                                                                                               | Request ID.|
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo                                                                 | Accessibility element information.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### findNextFocusAccessibilityNode()

```
int32_t (*findNextFocusAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction,int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)
```

**Description**

Called to find the next focusable node based on the reference node, in the specified mode and direction.

**Since**: 13

**Parameters**

| Name                                                                                                                              | Description|
|-----------------------------------------------------------------------------------------------------------------------------------| -- |
| int64_t elementId                                                                                                                 | Unique ID of the accessibility element.|
| [ArkUI_AccessibilityFocusMoveDirection](capi-native-interface-accessibility-h.md#arkui_accessibilityfocusmovedirection) direction | Search direction.|
| int32_t requestId                                                                                                                 | Request ID.|
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo                                                                                       | Accessibility element information.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### executeAccessibilityAction()

```
int32_t (*executeAccessibilityAction)(int64_t elementId, ArkUI_Accessibility_ActionType action,ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId)
```

**Description**

Called to execute a specified action on a specified node.

**Since**: 13

**Parameters**

| Name                                                                                                             | Description|
|------------------------------------------------------------------------------------------------------------------| -- |
| int64_t elementId                                                                                                | Unique ID of the accessibility element.|
| [ArkUI_Accessibility_ActionType](capi-native-interface-accessibility-h.md#arkui_accessibility_actiontype) action | Action to execute.|
| [ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md) *actionArguments                                                          | Action parameters.|
| int32_t requestId                                                                                                | Request ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### clearFocusedFocusAccessibilityNode()

```
int32_t (*clearFocusedFocusAccessibilityNode)()
```

**Description**

Called to clear the focus state of the current focused node.

**Since**: 13

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### getAccessibilityNodeCursorPosition()

```
int32_t (*getAccessibilityNodeCursorPosition)(int64_t elementId, int32_t requestId, int32_t* index)
```

**Description**

Called to query the current cursor position of the specified node.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| int64_t elementId | Unique ID of the accessibility element.|
|  int32_t requestId | Request ID.|
|  int32_t* index | Index of the cursor position.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|
