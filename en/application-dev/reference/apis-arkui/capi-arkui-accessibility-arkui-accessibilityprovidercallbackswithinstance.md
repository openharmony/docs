# ArkUI_AccessibilityProviderCallbacksWithInstance
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhanghangkai10241-->
<!--Designer: @lmleon-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @HelloCrease-->

## Overview

Defines the callback function struct for third-party operation providers in multi-instance scenarios. These functions should be implemented by third-party platforms and registered with the system using **OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance**.

**Since**: 15

**Related module**: [ArkUI_Accessibility](capi-arkui-accessibility.md)

**Header file**: [native_interface_accessibility.h](capi-native-interface-accessibility-h.md)

## Summary

### Member Functions

| Name| Description|
| -- | -- |
| [int32_t (\*findAccessibilityNodeInfosById)(const char* instanceId, int64_t elementId,ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)](#findaccessibilitynodeinfosbyid) | Callback function implemented by the third-party platform and registered with the system. Finds the information about an accessibility node based on the specified node ID. Multi-instance scenarios are supported.|
| [int32_t (\*findAccessibilityNodeInfosByText)(const char* instanceId, int64_t elementId, const char* text,int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)](#findaccessibilitynodeinfosbytext) | Callback function implemented by the third-party platform and registered with the system. Finds the node information matching the specified text content. Multi-instance scenarios are supported.|
| [int32_t (\*findFocusedAccessibilityNode)(const char* instanceId, int64_t elementId,ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)](#findfocusedaccessibilitynode) | Callback function implemented by the third-party platform and registered with the system. Finds the node that currently has focus within a given node. Multi-instance scenarios are supported.|
| [int32_t (\*findNextFocusAccessibilityNode)(const char* instanceId, int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction,int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)](#findnextfocusaccessibilitynode) | Callback function implemented by the third-party platform and registered with the system. Finds the next node in a specified direction from a given node. Multi-instance scenarios are supported.|
| [int32_t (\*executeAccessibilityAction)(const char* instanceId, int64_t elementId,ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId)](#executeaccessibilityaction) | Callback function implemented by the third-party platform and registered with the system. Performs a specified action on a specified node. Multi-instance scenarios are supported.|
| [int32_t (\*clearFocusedFocusAccessibilityNode)(const char* instanceId)](#clearfocusedfocusaccessibilitynode) | Callback function implemented by the third-party platform and registered with the system. Removes focus from the current node. Multi-instance scenarios are supported.|
| [int32_t (\*getAccessibilityNodeCursorPosition)(const char* instanceId, int64_t elementId,int32_t requestId, int32_t* index)](#getaccessibilitynodecursorposition) | Callback function implemented by the third-party platform and registered with the system. Obtains the cursor position within a text component of the current accessibility node. Multi-instance scenarios are supported.|

## Member Function Description

### findAccessibilityNodeInfosById()

```
int32_t (*findAccessibilityNodeInfosById)(const char* instanceId, int64_t elementId,ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)
```

**Description**

Callback function implemented by the third-party platform and registered with the system. Finds the information about an accessibility node based on the specified node ID. Multi-instance scenarios are supported.

**Since**: 15

**Parameters**

| Name                                                                           | Description|
|--------------------------------------------------------------------------------| -- |
| const char* instanceId                                                         | Instance ID of the third-party framework.|
| int64_t elementId                                                              | Unique ID of the accessibility element.|
| [ArkUI_AccessibilitySearchMode](capi-native-interface-accessibility-h.md) mode | Search mode for accessibility services.|
| int32_t requestId                                                              | Request ID for identifying the request process. It is recommended for logging to aid troubleshooting.|
| [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md)* elementList                            | List of all accessibility elements found.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>            Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### findAccessibilityNodeInfosByText()

```
int32_t (*findAccessibilityNodeInfosByText)(const char* instanceId, int64_t elementId, const char* text,int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)
```

**Description**

Callback function implemented by the third-party platform and registered with the system. Finds the node information matching the specified text content. Multi-instance scenarios are supported.

**Since**: 15

**Parameters**

| Name| Description|
| -- | -- |
| const char* instanceId | Instance ID of the third-party framework.|
|  int64_t elementId | Unique ID of the accessibility element.|
|  const char* text | Text content to match in the component.|
| int32_t requestId | Request ID for identifying the request process. It is recommended for logging to aid troubleshooting.|
|  [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md)* elementList | List of all accessibility elements found.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>            Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### findFocusedAccessibilityNode()

```
int32_t (*findFocusedAccessibilityNode)(const char* instanceId, int64_t elementId,ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)
```

**Description**

Callback function implemented by the third-party platform and registered with the system. Finds the node that currently has focus within a given node. Multi-instance scenarios are supported.

**Since**: 15

**Parameters**

| Name                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| const char* instanceId                                                             | Instance ID of the third-party framework.|
| int64_t elementId                                                                  | Unique ID of the accessibility element.|
| [ArkUI_AccessibilityFocusType](capi-native-interface-accessibility-h.md#arkui_accessibilityfocustype) focusType | Focus type.|
| int32_t requestId                                                                  | Request ID for identifying the request process. It is recommended for logging to aid troubleshooting.|
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo                                    | List of all accessibility elements found.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>            Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### findNextFocusAccessibilityNode()

```
int32_t (*findNextFocusAccessibilityNode)(const char* instanceId, int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction,int32_t requestId, ArkUI_AccessibilityElementInfo* elementInfo)
```

**Description**

Callback function implemented by the third-party platform and registered with the system. Finds the next node in a specified direction from a given node. Multi-instance scenarios are supported.

**Since**: 15

**Parameters**

| Name                                                                                                                              | Description|
|-----------------------------------------------------------------------------------------------------------------------------------| -- |
| const char* instanceId                                                                                                            | Instance ID of the third-party framework.|
| int64_t elementId                                                                                                                 | Unique ID of the accessibility element.|
| [ArkUI_AccessibilityFocusMoveDirection](capi-native-interface-accessibility-h.md#arkui_accessibilityfocusmovedirection) direction | Search direction.|
| int32_t requestId                                                                                                                 | Request ID for identifying the request process. It is recommended for logging to aid troubleshooting.|
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo                         | List of all accessibility elements found.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### executeAccessibilityAction()

```
int32_t (*executeAccessibilityAction)(const char* instanceId, int64_t elementId,ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId)
```

**Description**

Callback function implemented by the third-party platform and registered with the system. Performs a specified action on a specified node. Multi-instance scenarios are supported.

**Since**: 15

**Parameters**

| Name                                                                                                             | Description|
|------------------------------------------------------------------------------------------------------------------| -- |
| const char* instanceId                                                                                           | Instance ID of the third-party framework.|
| int64_t elementId                                                                                                | Unique ID of the accessibility element.|
| [ArkUI_Accessibility_ActionType](capi-native-interface-accessibility-h.md#arkui_accessibility_actiontype) action | Action to perform, such as focus, click, or long press.|
| [ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md) *actionArguments                                                          | Parameters controlling the action.|
| int32_t requestId                                                                                                | Request ID for identifying the request process. It is recommended for logging to aid troubleshooting.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### clearFocusedFocusAccessibilityNode()

```
int32_t (*clearFocusedFocusAccessibilityNode)(const char* instanceId)
```

**Description**

Callback function implemented by the third-party platform and registered with the system. Removes focus from the current node. Multi-instance scenarios are supported.

**Since**: 15

**Parameters**

| Name| Description|
| -- | -- |
| const char* instanceId | Instance ID of the third-party framework.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### getAccessibilityNodeCursorPosition()

```
int32_t (*getAccessibilityNodeCursorPosition)(const char* instanceId, int64_t elementId,int32_t requestId, int32_t* index)
```

**Description**

Callback function implemented by the third-party platform and registered with the system. Obtains the cursor position within a text component of the current accessibility node. Multi-instance scenarios are supported.

**Since**: 15

**Parameters**

| Name| Description|
| -- | -- |
| const char* instanceId | Instance ID of the third-party framework.|
|  int64_t elementId | Unique ID of the accessibility element.|
| int32_t requestId | Request ID for identifying the request process. It is recommended for logging to aid troubleshooting.|
|  int32_t* index | Cursor position result.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|
