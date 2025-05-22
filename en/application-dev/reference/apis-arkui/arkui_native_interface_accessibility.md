# Native Accessibility

## Overview

Describes the APIs for third-party platforms to access the ArkUI accessibility framework through **XComponent**, that is, the APIs that third-party platforms need to implement, as well as related structs and enums.

> **NOTE**
>
> The APIs of this module are supported since API version 13. Updates will be marked with a superscript to indicate their earliest API version.

## Summary


### Files

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [native_interface_accessibility.h](native__interface__accessibility_8h.md) | Declares the APIs for accessing the native Accessibility.|

### Types

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [ArkUI_AccessibilityElementInfo](#arkui_accessibilityelementinfo) | Provides accessibility node information, which is used to transfer node information to accessibility services and applications. |
| [ArkUI_AccessibilityElementInfoList](#arkui_accessibilityelementinfolist) | Defines an accessibility node list, which contains required accessibility node information. |
| [ArkUI_AccessibilityEventInfo](#arkui_accessibilityeventinfo) | Provides accessibility event information. After a component completes an action requested by an accessibility service or application, it needs to send a success event to confirm the operation. Similarly, if the component needs to synchronize its state change with the accessibility service or application due to its own interactive behavior, it should actively trigger an event to communicate the change. |
| [ArkUI_AccessibilityProvider](#arkui_accessibilityprovider)  | Defines a third-party accessibility provider, which carries callback function implementations. |
| [ArkUI_AccessibilityProviderCallbacks](#arkui_accessibilityprovidercallbacks) | Defines a struct for third-party accessibility provider callback functions, which third-party platforms need to implement. These functions are registered with the system side through **OH_ArkUI_AccessibilityProviderRegisterCallback**. |
| [ArkUI_AccessibilityActionArguments](#arkui_accessibilityactionarguments) | Provides additional information of the action to be executed. |
| [ArkUI_AccessibleRect](#arkui_accessiblerect)                | Provides the coordinate position where the node is located.  |
| [ArkUI_AccessibleRangeInfo](#arkui_accessiblerangeinfo)      | Sets the current value, maximum value, and minimum value in the component attributes. Used by specific components, such as **Slider**, **Rating**, and **Progress**. |
| [ArkUI_AccessibleGridInfo](#arkui_accessiblegridinfo)        | Sets the number of rows, number of columns, and selection mode of the component. Used by specific components, such as **List**, **Flex**, **Select**, and **Swiper**. |
| [ArkUI_AccessibleGridItemInfo](#arkui_accessiblegriditeminfo) | Sets the attribute values of component items. Used by specific components, such as **List**, **Flex**, **Select**, and **Swiper**. |
| [ArkUI_AccessibleAction](#arkui_accessibleaction)            | Defines a struct for accessibility operation content.        |

### Enums

| Name                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)    | Enumerates the error codes.      |
| [ArkUI_AccessibilitySearchMode](#arkui_accessibilitysearchmode) | Enumerates the search modes.    |
| [ArkUI_AccessibilityFocusType](#arkui_accessibilityfocustype) | Enumerates the focus types.    |
| [ArkUI_Accessibility_ActionType](#arkui_accessibility_actiontype) | Enumerates the action types.    |
| [ArkUI_AccessibilityEventType](#arkui_accessibilityeventtype) | Enumerates the event types.    |
| [ArkUI_AccessibilityFocusMoveDirection](#arkui_accessibilityfocusmovedirection) | Enumerates the focus movement directions.|

## Type Description

### ArkUI_AccessibilityElementInfo

```
typedef struct ArkUI_AccessibilityElementInfo ArkUI_AccessibilityElementInfo
```

**Description**

Provides accessibility node information, which is used to transfer node information to accessibility services and applications.

**Since**

13

### ArkUI_AccessibilityElementInfoList

```
typedef struct ArkUI_AccessibilityElementInfoList ArkUI_AccessibilityElementInfoList
```

**Description**

Defines an accessibility node list, which contains required accessibility node information.

**Since**

13

### ArkUI_AccessibilityEventInfo 

```
typedef struct ArkUI_AccessibilityEventInfo ArkUI_AccessibilityEventInfo
```

**Description**

Provides accessibility event information. After a component completes an action requested by an accessibility service or application, it needs to send a success event to confirm the operation. Similarly, if the component needs to synchronize its state change with the accessibility service or application due to its own interactive behavior, it should actively trigger an event to communicate the change.

**Since**

13

### ArkUI_AccessibilityProvider

```
typedef struct ArkUI_AccessibilityProvider ArkUI_AccessibilityProvider
```

**Description**

Defines a third-party accessibility provider, which carries callback function implementations.

**Since**

13

### ArkUI_AccessibilityProviderCallbacks

```C
typedef struct ArkUI_AccessibilityProviderCallbacks {
    int32_t (*findAccessibilityNodeInfosById)(int64_t elementId, ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList);
    int32_t (*findAccessibilityNodeInfosByText)(int64_t elementId, const char* text, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList);
    int32_t (*findFocusedAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo* elementinfo);
    int32_t (*findNextFocusAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction, int32_t requestId, ArkUI_AccessibilityElementInfo* elementList);
    int32_t (*executeAccessibilityAction)(int64_t elementId, ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId);
    int32_t (*clearFocusedFocusAccessibilityNode)();
    int32_t (*getAccessibilityNodeCursorPosition)(int64_t elementId, int32_t requestId, int32_t* index);
} ArkUI_AccessibilityProviderCallbacks;
```

**Description**

Defines a struct for third-party accessibility provider callback functions, which third-party platforms need to implement. These functions are registered with the system side through **OH_ArkUI_AccessibilityProviderRegisterCallback**.

| Name                                                    | Description                            |
| ------------------------------------------------------------ | ------------------------------------ |
| [findAccessibilityNodeInfosById](#findaccessibilitynodeinfosbyid) | Finds the information about an accessibility node based on the specified node ID.|
| [findAccessibilityNodeInfosByText](#findaccessibilitynodeinfosbytext) | Finds the nodes that contain specific text content.    |
| [findFocusedAccessibilityNode](#findfocusedaccessibilitynode) | Finds the node that currently has focus within a given node.      |
| [findNextFocusAccessibilityNode](#findnextfocusaccessibilitynode) | Finds the next node in a specified direction from a given node.      |
| [executeAccessibilityAction](#executeaccessibilityaction)    | Performs a specified action on a specified node.|
| [clearFocusedFocusAccessibilityNode](#clearfocusedfocusaccessibilitynode) | Removes focus from the current node.                |
| [getAccessibilityNodeCursorPosition](#getaccessibilitynodecursorposition) | Obtains the cursor position within a text component of the current accessibility node.|

**Since**

13

### ArkUI_AccessibilityActionArguments

**Description**

Provides additional information of the action to be executed.

**Since**

13



### ArkUI_AccessibleRect

**Description**

Provides the coordinate position where the node is located.

**Parameters**

| Name        | Type | Description               |
| ------------ | ----- | ------------------- |
| leftTopX     | int32 | X coordinate of the upper left corner.|
| leftTopY     | int32 | Y coordinate of the upper left corner.|
| rightBottomX | int32 | X coordinate of the lower right corner.|
| rightBottomY | int32 | Y coordinate of the lower right corner.|

**Since**

13



### ArkUI_AccessibleRangeInfo

**Description**

Sets the current value, maximum value, and minimum value in the component attributes. Used by specific components, such as **Slider**, **Rating**, and **Progress**.

**Parameters**

| Name   | Type  | Description    |
| ------- | ------ | -------- |
| min     | double | Minimum value.|
| max     | double | Maximum value.|
| current | double | Current value.|

**Since**

13



### ArkUI_AccessibleGridInfo

**Description**

Sets the number of rows, number of columns, and selection mode of the component. Used by specific components, such as **List**, **Flex**, **Select**, and **Swiper**.

**Parameters**

| Name         | Type | Description      |
| ------------- | ----- | ---------- |
| rowCount      | int32 | Number of columns.    |
| columnCount   | int32 | Number of rows.    |
| selectionMode | int32 | Selection mode.|

**Since**

13



### ArkUI_AccessibleGridItemInfo

**Description**

Sets the attribute values of component items. Used by specific components, such as **List**, **Flex**, **Select**, and **Swiper**.

**Parameters**

| Name       | Type | Description        |
| ----------- | ----- | ------------ |
| heading     | bool  | Whether the item is a heading.|
| selected    | bool  | Whether the item is selected.|
| columnIndex | int32 | Column index of the item.    |
| rowIndex    | int32 | Row index of the item.    |
| columnSpan  | int32 | Number of columns that the item spans.    |
| rowSpan     | int32 | Number of rows that the item spans.    |

**Since**

13

### ArkUI_AccessibleAction

**Description**

Defines a struct for the accessibility action.

**Parameters**

| Name       | Type                                                        | Description            |
| ----------- | ------------------------------------------------------------ | ---------------- |
| actionType  | [ArkUI_Accessibility_ActionType](#arkui_accessibility_actiontype) | Accessibility action type.|
| description | char*                                                        | Description.      |

**Since**

13

## Function Description

### findAccessibilityNodeInfosById

```C
int32_t (*findAccessibilityNodeInfosById)(int64_t elementId, ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList);
```

**Description**

Finds the information about an accessibility node based on the specified node ID. This function should be implemented by the third-party platform and registered for the system to call.

**Since**: 13

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| elementId   | ID of the node from which to start the search. If the value is **-1**, the search starts from the root node of the component tree.|
| mode        | Search mode. The following are supported: [ArkUI_AccessibilitySearchMode](#arkui_accessibilitysearchmode).|
| requestId   | Request ID, which is used to identify the request process and facilitate fault locating. It is recommended that third-party platforms include this ID in their key log outputs for debugging purposes.|
| elementList | Search result, which the third-party platform returns based on the search.                    |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### findAccessibilityNodeInfosByText

```C
int32_t (*findAccessibilityNodeInfosByText)(int64_t elementId, const char* text, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList);
```

**Description**

This function should be implemented by the third-party platform and registered for the system to call. Finds the nodes that contain specific text content.

**Since**: 13

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| elementId   | ID of the node from which to start the search. If the value is **-1**, the search starts from the root node of the component tree.|
| text        | Text to match against the accessibility text content of the nodes.                  |
| requestId   | Request ID, which is used to identify the request process and facilitate fault locating. It is recommended that third-party platforms include this ID in their key log outputs for debugging purposes.|
| elementList | Search result, which the third-party platform returns based on the search.                    |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### findFocusedAccessibilityNode

```C
int32_t (*findFocusedAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo* elementinfo);
```

**Description**

This function should be implemented by the third-party platform and registered for the system to call. Finds the node that currently has focus within a given node.

**Since**: 13

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| elementId   | ID of the node from which to start the search. If the value is **-1**, the search starts from the root node of the component tree.|
| focusType   | Type of accessibility focus, as defined in [ArkUI_AccessibilityFocusType](#arkui_accessibilityfocustype).|
| requestId   | Request ID, which is used to identify the request process and facilitate fault locating. It is recommended that third-party platforms include this ID in their key log outputs for debugging purposes.|
| elementList | Search result, which the third-party platform returns based on the search.                    |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### findNextFocusAccessibilityNode

```C
int32_t (*findNextFocusAccessibilityNode)(int64_t elementId, ArkUI_AccessibilityFocusMoveDirection direction, int32_t requestId, ArkUI_AccessibilityElementInfo* elementList);
```

**Description**

This function should be implemented by the third-party platform and registered for the system to call. Finds the next node in a specified direction from a given node.

**Since**: 13

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| elementId   | ID of the node from which to start the search. If the value is **-1**, the search starts from the root node of the component tree.|
| focusType   | Type of accessibility focus, as defined in [ArkUI_AccessibilityFocusType](#arkui_accessibilityfocustype).|
| requestId   | Request ID, which is used to identify the request process and facilitate fault locating. It is recommended that third-party platforms include this ID in their key log outputs for debugging purposes.|
| elementList | Search result, which the third-party platform returns based on the search.                    |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### executeAccessibilityAction

```C
int32_t (*executeAccessibilityAction)(int64_t elementId, ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId);
```

**Description**

This function should be implemented by the third-party platform and registered for the system to call. Performs a specified action on a specified node.

**Since**: 13

**Parameters**

| Name           | Description                                                        |
| --------------- | ------------------------------------------------------------ |
| elementId       | ID of the specified node.                                              |
| action          | Type of action to be performed, as defined in [ArkUI_Accessibility_ActionType](#arkui_accessibility_actiontype).|
| requestId       | Request ID, which is used to identify the request process and facilitate fault locating. It is recommended that third-party platforms include this ID in their key log outputs for debugging purposes.|
| actionArguments | Additional information of the action.                                        |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### clearFocusedFocusAccessibilityNode

```C
int32_t (*clearFocusedFocusAccessibilityNode)();
```

**Description**

This function should be implemented by the third-party platform and registered for the system to call. Removes focus from this node.

**Since**: 13

**Input parameter**: none

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)

### getAccessibilityNodeCursorPosition

```C
int32_t (*getAccessibilityNodeCursorPosition)(int64_t elementId, int32_t requestId, int32_t* index);
```

**Description**

This function should be implemented by the third-party platform and registered for the system to call. Obtains the cursor position within a text component of the current accessibility node.

**Since**: 13

**Parameters**

| Name     | Description                                                        |
| --------- | ------------------------------------------------------------ |
| elementId | ID of the specified node.                                              |
| requestId | Request ID, which is used to identify the request process and facilitate fault locating. It is recommended that third-party platforms include this ID in their key log outputs for debugging purposes.|
| index     | Parameter where the cursor position result is returned.                                          |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityProviderRegisterCallback

```C
int32_t OH_ArkUI_AccessibilityProviderRegisterCallback(
    ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityProviderCallbacks* callbacks);
```

**Description**

Registers callback functions.

**Since**: 13

**Parameters**

| Name     | Description                      |
| --------- | -------------------------- |
| provider  | Handle to the provider of the third-party platform.|
| callbacks | Implementation of the callback functions.            |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_SendAccessibilityAsyncEvent

```C
void OH_ArkUI_SendAccessibilityAsyncEvent(
    ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityEventInfo* eventInfo, void (*callback)(int32_t errorCode));
```

**Description**

Proactively sends an event to notify the accessibility service.

**Since**: 13

**Parameters**

| Name     | Description                      |
| --------- | -------------------------- |
| provider  | Handle to the provider of the third-party platform.|
| eventInfo | Event to send.                |
| callback  | Callback for the returned result.            |

**Returns**: none



### OH_ArkUI_CreateAccessibilityElementInfo

```C
ArkUI_AccessibilityElementInfo* OH_ArkUI_CreateAccessibilityElementInfo(void);
```

**Description**

Creates an **ArkUI_AccessibilityElementInfo** struct. After creation, you must call [OH_ArkUI_DestoryAccessibilityElementInfo](#oh_arkui_destoryaccessibilityelementinfo) to release it.

**Since**: 13

**Returns**

Returns the pointer to the created **ArkUI_AccessibilityElementInfo** struct; returns **NULL** if creation fails.

### OH_ArkUI_DestoryAccessibilityElementInfo

```C
void OH_ArkUI_DestoryAccessibilityElementInfo(ArkUI_AccessibilityElementInfo* elementInfo);
```

**Description**

Destroys an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description                           |
| ----------- | ------------------------------- |
| elementInfo | Pointer to the **ArkUI_AccessibilityElementInfo** struct to be destroyed.|

**Returns**: none



### OH_ArkUI_AddAndGetAccessibilityElementInfo

```C
ArkUI_AccessibilityElementInfo* OH_ArkUI_AddAndGetAccessibilityElementInfo(ArkUI_AccessibilityElementInfoList* list);
```

**Description**

Adds an **ArkUI_AccessibilityElementInfo** member to the specified list and returns the **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name| Description                                                        |
| ---- | ------------------------------------------------------------ |
| list | **ArkUI_AccessibilityElementInfoList** struct to which the new **ArkUI_AccessibilityElementInfo** member is added and then returned to the function caller.|

**Returns**

Returns the pointer to the **ArkUI_AccessibilityElementInfo** struct; returns **NULL** if the operation fails.



### OH_ArkUI_AccessibilityElementInfoSetElementId

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetElementId(ArkUI_AccessibilityElementInfo* elementInfo, int32_t elementId);
```

**Description**

Sets the ID for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description         |
| ----------- | ------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.|
| elementId   | ID to set. |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetParentId

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetParentId(ArkUI_AccessibilityElementInfo* elementInfo, int32_t parentId);
```

**Description**

Sets the parent ID for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description          |
| ----------- | -------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct. |
| parentId    | Parent ID to set.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetComponentType

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetComponentType(ArkUI_AccessibilityElementInfo* elementInfo, const char* componentType);
```

**Description**

Sets the component type for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name         | Description          |
| ------------- | -------------- |
| elementInfo   | Pointer to an **ArkUI_AccessibilityElementInfo** struct. |
| componentType | Component type to set.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetContents

```c
int32_t OH_ArkUI_AccessibilityElementInfoSetContents(ArkUI_AccessibilityElementInfo* elementInfo, const char* contents);
```

**Description**

Sets the component content for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description          |
| ----------- | -------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct. |
| contents    | Component content to set.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetHintText

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetHintText(ArkUI_AccessibilityElementInfo* elementInfo, const char* hintText);
```

**Description**

Sets the hint text for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description         |
| ----------- | ------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.|
| hintText    | Hint text to set.   |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityText

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityText(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityText);
```

**Description**

Sets the accessibility text for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name             | Description                  |
| ----------------- | ---------------------- |
| elementInfo       | Pointer to an **ArkUI_AccessibilityElementInfo** struct.         |
| accessibilityText | Accessibility text to set.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityDescription

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityDescription(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityDescription);
```

**Description**

Sets the accessibility description for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name                    | Description            |
| ------------------------ | ---------------- |
| elementInfo              | Pointer to an **ArkUI_AccessibilityElementInfo** struct.   |
| accessibilityDescription | Accessibility description to set.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetChildNodeIds

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetChildNodeIds(ArkUI_AccessibilityElementInfo* elementInfo, int32_t childCount, int64_t* childNodeIds);
```

**Description**

Sets the number of child nodes and child node IDs for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name        | Description          |
| ------------ | -------------- |
| elementInfo  | Pointer to an **ArkUI_AccessibilityElementInfo** struct. |
| childCount   | Number of child nodes.  |
| childNodeIds | Array of child node IDs.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetOperationActions

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetOperationActions(ArkUI_AccessibilityElementInfo* elementInfo, int32_t operationCount, ArkUI_AccessibleAction* operationActions);
```

**Description**

Sets the number of actions and the actions themselves for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name            | Description                  |
| ---------------- | ---------------------- |
| elementInfo      | Pointer to an **ArkUI_AccessibilityElementInfo** struct.         |
| operationCount   | Number of actions supported by the component.|
| operationActions | Array of actions supported by the component.    |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetScreenRect

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetScreenRect(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleRect* screenRect);
```

**Description**

Sets the screen rectangle for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name            | Description              |
| ---------------- | ------------------ |
| elementInfo      | Pointer to an **ArkUI_AccessibilityElementInfo** struct.     |
| screenRect       | Screen rectangle to set.    |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetCheckable

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetCheckable(ArkUI_AccessibilityElementInfo* elementInfo, bool checkable);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is checkable.

**Since**: 13

**Parameters**

| Name       | Description          |
| ----------- | -------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct. |
| checkable   | Whether the element is checkable.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetChecked

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetChecked(ArkUI_AccessibilityElementInfo* elementInfo, bool checked);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is checked.

**Since**: 13

**Parameters**

| Name       | Description            |
| ----------- | ---------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.   |
| checked     | Whether the element is checked.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetFocusable

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetFocusable(ArkUI_AccessibilityElementInfo* elementInfo, bool focusable);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is focusable.

**Since**: 13

**Parameters**

| Name       | Description            |
| ----------- | ---------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.   |
| focusable   | Whether the element is focusable.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetFocused

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetFocused(ArkUI_AccessibilityElementInfo* elementInfo, bool isFocused);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is focused.

**Since**: 13

**Parameters**

| Name       | Description          |
| ----------- | -------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct. |
| isFocused   | Whether the element is focused.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetVisible

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetVisible(ArkUI_AccessibilityElementInfo* elementInfo, bool isVisible);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is visible.

**Since**: 13

**Parameters**

| Name       | Description          |
| ----------- | -------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct. |
| isVisible   | Whether the element is visible.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityFocused

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityFocused(ArkUI_AccessibilityElementInfo* elementInfo, bool accessibilityFocused);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is focused for accessibility purposes.

**Since**: 13

**Parameters**

| Name                | Description            |
| -------------------- | ---------------- |
| elementInfo          | Pointer to an **ArkUI_AccessibilityElementInfo** struct.   |
| accessibilityFocused | Whether the element is focused for accessibility purposes.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetSelected

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetSelected(ArkUI_AccessibilityElementInfo* elementInfo, bool selected);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is selected.

**Since**: 13

**Parameters**

| Name       | Description            |
| ----------- | ---------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.   |
| selected    | Whether the element is selected.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetClickable

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetClickable(ArkUI_AccessibilityElementInfo* elementInfo, bool clickable);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is clickable.

**Since**: 13

**Parameters**

| Name       | Description            |
| ----------- | ---------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.   |
| clickable   | Whether the element is clickable.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetLongClickable

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetLongClickable(ArkUI_AccessibilityElementInfo* elementInfo, bool longClickable);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is long-clickable.

**Since**: 13

**Parameters**

| Name         | Description              |
| ------------- | ------------------ |
| elementInfo   | Pointer to an **ArkUI_AccessibilityElementInfo** struct.     |
| longClickable | Whether the element is long-clickable.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetEnabled

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetEnabled(ArkUI_AccessibilityElementInfo* elementInfo, bool isEnabled);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is enabled.

**Since**: 13

**Parameters**

| Name       | Description          |
| ----------- | -------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct. |
| isEnabled   | Whether the element is enabled.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetIsPassword

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetIsPassword(ArkUI_AccessibilityElementInfo* elementInfo, bool isPassword);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is a password.

**Since**: 13

**Parameters**

| Name       | Description            |
| ----------- | ---------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.   |
| isPassword  | Whether the element is a password.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetScrollable

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetScrollable(ArkUI_AccessibilityElementInfo* elementInfo, bool scrollable);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is scrollable.

**Since**: 13

**Parameters**

| Name       | Description            |
| ----------- | ---------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.   |
| scrollable  | Whether the element is scrollable.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetEditable

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetEditable(ArkUI_AccessibilityElementInfo* elementInfo, bool editable);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is editable.

**Since**: 13

**Parameters**

| Name       | Description            |
| ----------- | ---------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.   |
| editable    | Whether the element is editable.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetIsHint

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetIsHint(ArkUI_AccessibilityElementInfo* elementInfo, bool isHint);
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** struct is a hint.

**Since**: 13

**Parameters**

| Name       | Description                |
| ----------- | -------------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.       |
| isHint      | Whether the element is a hint.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetRangeInfo

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetRangeInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleRangeInfo* rangeInfo);
```

**Description**

Sets the range information for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                                               |
| rangeInfo   | Current value, maximum value, and minimum value of the component attributes. Used by specific components, such as **Slider**, **Rating**, and **Progress**. |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetGridInfo

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetGridInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleGridInfo* gridInfo);
```

**Description**

Sets the grid information for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                                               |
| gridInfo    | Number of rows, number of columns, and selection mode. Used by specific components, such as **List**, **Flex**, **Select**, and **Swiper**. |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetGridItemInfo

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetGridItemInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleGridItemInfo* gridItem);
```

**Description**

Sets the grid item information for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description                                                |
| ----------- | ---------------------------------------------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                                       |
| gridItem    | Grid item to set. Used by specific components, such as **List**, **Flex**, **Select**, and **Swiper**.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetSelectedTextStart

```
int32_t OH_ArkUI_AccessibilityElementInfoSetSelectedTextStart(ArkUI_AccessibilityElementInfo* elementInfo, int32_t selectedTextStart);
```

**Description**

Sets the start position of the selected text for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name             | Description                              |
| ----------------- | ---------------------------------- |
| elementInfo       | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                     |
| selectedTextStart | Start position of the selected text. Used by text components.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetSelectedTextEnd

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetSelectedTextEnd(ArkUI_AccessibilityElementInfo* elementInfo, int32_t selectedTextEnd);
```

**Description**

Sets the end position of the selected text for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name           | Description                              |
| --------------- | ---------------------------------- |
| elementInfo     | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                     |
| selectedTextEnd | End position of the selected text. Used by text components.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetCurrentItemIndex

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetCurrentItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t currentItemIndex);
```

**Description**

Sets the index of the currently focused item for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| elementInfo      | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                                               |
| currentItemIndex | Index of the currently focused item. Used by specific components, such as **List**, **Select**, **Swiper**, and **TabContent**.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetStartItemIndex

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetStartItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t startItemIndex);
```

**Description**

Sets the index of the first item displayed on the screen for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| elementInfo    | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                                               |
| startItemIndex | Index of the first item displayed on the screen, that is, the index of the first visible component. Used by specific components, such as **List**, **Select**, **Swiper**, and **TabContent**.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetEndItemIndex

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetEndItemIndex(
    ArkUI_AccessibilityElementInfo* elementInfo, int32_t endItemIndex);
```

**Description**

Sets the index of the last item displayed on the screen for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name        | Description                                                        |
| ------------ | ------------------------------------------------------------ |
| elementInfo  | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                                               |
| endItemIndex | Index of the first item displayed on the screen, that is, the index of the last visible component. Used by specific components, such as **List**, **Select**, **Swiper**, and **TabContent**.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetItemCount

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetItemCount(
    ArkUI_AccessibilityElementInfo* elementInfo, int32_t itemCount);
```

**Description**

Sets the total number of items for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description                                                     |
| ----------- | --------------------------------------------------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                                            |
| itemCount   | Total number of items. Used by specific components, such as **List**, **Select**, **Swiper**, and **TabContent**.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityOffset

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityOffset(
    ArkUI_AccessibilityElementInfo* elementInfo, int32_t offset);
```

**Description**

Sets the offset for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                                               |
| offset      | Pixel offset of the content area relative to the top coordinate of a scrollable component, such as **List** and **Grid**.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityGroup

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityGroup(
    ArkUI_AccessibilityElementInfo* elementInfo, bool accessibilityGroup);
```

**Description**

Sets the accessibility group for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| elementInfo        | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                                               |
| accessibilityGroup | Accessibility group. If this attribute is set to **true**, the component and all its child components form an entire selectable component, and the accessibility service will no longer be available for the content of its child components.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityLevel

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityLevel(
    ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityLevel);
```

**Description**

Sets the accessibility level for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| elementInfo        | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                                               |
| accessibilityLevel | Accessibility level, which is used to decide whether a component can be identified by the accessibility service.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetZIndex

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetZIndex(
    ArkUI_AccessibilityElementInfo* elementInfo, int32_t zIndex);
```

**Description**

Sets the z-index for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description                                            |
| ----------- | ------------------------------------------------ |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                                   |
| zIndex      | Z-order of the component, used to control the position of the component along the z-axis perpendicular to the screen.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetAccessibilityOpacity

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityOpacity(
    ArkUI_AccessibilityElementInfo* elementInfo, float opacity);
```

**Description**

Sets the opacity for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                                               |
| opacity     | Opacity of the component. The value ranges from 0 to 1. The value **1** means opaque, and **0** means completely transparent. |

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetBackgroundColor

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetBackgroundColor(
    ArkUI_AccessibilityElementInfo* elementInfo, const char* backgroundColor);
```

**Description**

Sets the background color for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name           | Description            |
| --------------- | ---------------- |
| elementInfo     | Pointer to an **ArkUI_AccessibilityElementInfo** struct.   |
| backgroundColor | Background color of the component.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetBackgroundImage

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetBackgroundImage(
    ArkUI_AccessibilityElementInfo* elementInfo, const char* backgroundImage);
```

**Description**

Sets the background image for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name           | Description              |
| --------------- | ------------------ |
| elementInfo     | Pointer to an **ArkUI_AccessibilityElementInfo** struct.     |
| backgroundImage | Background image of the component.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetBlur

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetBlur(
    ArkUI_AccessibilityElementInfo* elementInfo, const char* blur);
```

**Description**

Sets the blur effect for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description            |
| ----------- | ---------------- |
| elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** struct.   |
| blur        | Blur effect information of the component.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityElementInfoSetHitTestBehavior

```C
int32_t OH_ArkUI_AccessibilityElementInfoSetHitTestBehavior(
    ArkUI_AccessibilityElementInfo* elementInfo, const char* hitTestBehavior);
```

**Description**

Sets the hit test mode for an **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13

**Parameters**

| Name           | Description                                                        |
| --------------- | ------------------------------------------------------------ |
| elementInfo     | Pointer to an **ArkUI_AccessibilityElementInfo** struct.                                               |
| hitTestBehavior | Hit test mode. The options are as follows:<br>**HitTestMode.Default**: default mode<br>**HitTestMode.Block**: block mode<br>**HitTestMode.Transparent**: transparent mode<br>**HitTestMode.None**: disabled|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_CreateAccessibilityEventInfo

```C
ArkUI_AccessibilityEventInfo* OH_ArkUI_CreateAccessibilityEventInfo(void);
```

**Description**

Creates an **ArkUI_AccessibilityEventInfo** struct, which must be released by calling **OH_ArkUI_DestroyAccessibilityEventInfo** after use.

**Since**: 13

**Returns**

Returns the pointer to the created **ArkUI_AccessibilityEventInfo** struct; returns **NULL** if creation fails.

### OH_ArkUI_DestoryAccessibilityEventInfo

```C
void OH_ArkUI_DestoryAccessibilityEventInfo(ArkUI_AccessibilityEventInfo* eventInfo);
```

**Description**

Destroys an **ArkUI_AccessibilityEventInfo** struct.

**Since**: 13

**Parameters**

| Name     | Description                             |
| --------- | --------------------------------- |
| eventInfo | Pointer to the **ArkUI_AccessibilityEventInfo** struct to be destroyed.|

**Returns**: none



### OH_ArkUI_AccessibilityEventSetEventType

```C
int32_t OH_ArkUI_AccessibilityEventSetEventType(
    ArkUI_AccessibilityEventInfo* eventInfo,  ArkUI_AccessibilityEventType eventType);
```

**Description**

Sets the event type for an **ArkUI_AccessibilityEventInfo** struct.

**Since**: 13

**Parameters**

| Name     | Description                                                        |
| --------- | ------------------------------------------------------------ |
| eventInfo | Pointer to an **ArkUI_AccessibilityEventInfo** struct.                                         |
| eventType | Type of event, as defined in [ArkUI_AccessibilityEventType](#arkui_accessibilityeventtype).|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityEventSetTextAnnouncedForAccessibility

```C
int32_t OH_ArkUI_AccessibilityEventSetTextAnnouncedForAccessibility(
    ArkUI_AccessibilityEventInfo* eventInfo, const char* textAnnouncedForAccessibility);
```

**Description**

Sets the text to be announced for accessibility in an **ArkUI_AccessibilityEventInfo** struct.

**Since**: 13

**Parameters**

| Name                         | Description                                                        |
| ----------------------------- | ------------------------------------------------------------ |
| eventInfo                     | Pointer to an **ArkUI_AccessibilityEventInfo** struct.                                         |
| textAnnouncedForAccessibility | Content to be announced when a proactive announcement event is sent. Applicable for event type ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_VIEW_ANNOUNCE_FOR_ACCESSIBILITY.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityEventSetRequestFocusId

```
int32_t OH_ArkUI_AccessibilityEventSetRequestFocusId(
    ArkUI_AccessibilityEventInfo* eventInfo, int32_t requestFocusId);
```

**Description**

Sets the ID of the node to focus on in an **ArkUI_AccessibilityEventInfo** struct.

**Since**: 13

**Parameters**

| Name          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| eventInfo      | Pointer to an **ArkUI_AccessibilityEventInfo** struct.                                         |
| requestFocusId | ID of the node to focus on when a proactive focus event is sent. The focus must be stable and not change. Applicable for event type ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_VIEW_REQUEST_FOCUS_FOR_ACCESSIBILITY.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_AccessibilityEventSetElementInfo

```C
int32_t OH_ArkUI_AccessibilityEventSetElementInfo(
    ArkUI_AccessibilityEventInfo* eventInfo,  ArkUI_AccessibilityElementInfo* elementInfo);
```

**Description**

Sets the component information in an **ArkUI_AccessibilityEventInfo** struct.

**Since**: 13

**Parameters**

| Name       | Description                    |
| ----------- | ------------------------ |
| eventInfo   | Pointer to an **ArkUI_AccessibilityEventInfo** struct.     |
| elementInfo | Component information for the event being sent.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



### OH_ArkUI_FindAccessibilityActionArgumentByKey

```
int32_t OH_ArkUI_FindAccessibilityActionArgumentByKey(
    ArkUI_AccessibilityActionArguments* arguments, const char* key, char** value);
```

**Description**

Obtains the value associated with a specified key in an **ArkUI_AccessibilityEventInfo** struct.

**Since**: 13

**Parameters**

| Name     | Description                  |
| --------- | ---------------------- |
| arguments | Parameters of the action.  |
| key       | Target key.             |
| value     | Value corresponding to the target key.|

**Returns**

 [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode)



## Enum Description

### ArkUI_AcessbilityErrorCode

**Description**

Enumerates the error codes used in the HiDebug module.

| Value                                         | Description      |
| ----------------------------------------------- | ---------- |
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESS       | Success.    |
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_FAILED        | Failed.    |
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER | Invalid parameter.|
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_OUT_OF_MEMORY | Insufficient memory.|

**Since**

13

### ArkUI_AccessibilitySearchMode

**Description**

Enumerates the search modes.

| Value                                                      | Description                                                    |
| ------------------------------------------------------------ | -------------------------------------------------------- |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_CURRENT      | Searches only for the information of the specified node.                                    |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_PREDECESSORS | Searches for the parent component. The search result includes the specified node information.                  |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_SIBLINGS     | Searches for sibling components. The search result includes the specified node information.            |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_CHILDREN     | Searches for the next level of child nodes of the current node. The search result includes the specified node information.|
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_RECURSIVE_CHILDREN | Searches for all child nodes of the current node. The search result includes the specified node information.  |

**Since**

13

### ArkUI_AccessibilityFocusType

**Description**

Enumerates the focus types.

| Value                                             | Description            |
| --------------------------------------------------- | ---------------- |
| ARKUI_ACCESSIBILITY_NATIVE_FOCUS_TYPE_INVALID       | Invalid value.        |
| ARKUI_ACCESSIBILITY_NATIVE_FOCUS_TYPE_INPUT         | Component focus.  |
| ARKUI_ACCESSIBILITY_NATIVE_FOCUS_TYPE_ACCESSIBILITY | Accessibility focus.|

**Since**

13

### ArkUI_Accessibility_ActionType

**Description**

Enumerates the action types.

| Value                                                     | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_INVALID                   | Invalid value.                                                    |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLICK                     | Performs a click action.                                                  |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_LONG_CLICK                | Performs a long-click action.                                                  |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_GAIN_ACCESSIBILITY_FOCUS  | Gains accessibility focus for an element.                                        |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLEAR_ACCESSIBILITY_FOCUS | Clears the accessibility focus state of an element.                                    |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_FORWARD            | Scrolls a scrollable component forward.                                    |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_BACKWARD           | Scrolls a scrollable component backward.                                    |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_COPY                      | Copies selected content in a text component.                            |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_PASTE                     | Pastes content at the cursor position in a text component.                            |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CUT                       | Cuts selected content in a text component.                            |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SELECT_TEXT               | Selects a range of text within an editable area in a text component. Used together with [ArkUI_AccessibilityActionArguments](#arkui_accessibilityactionarguments) to configure **selectTextStart**, **selectTextEnd**, and **selectTextInForWard**.  |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SET_TEXT                  | Sets the text content of a text component.                                  |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SET_CURSOR_POSITION       | Sets the cursor position in a text component. Used together with [ArkUI_AccessibilityActionArguments](#arkui_accessibilityactionarguments) to configure **offset**.|

**Since**

13

### ArkUI_AccessibilityEventType

**Description**

Enumerates the event types.

| Value                                                      | Description                                            |
| ------------------------------------------------------------ | ------------------------------------------------ |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_INVALID                | Invalid value.                                        |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_CLICKED                | Event when an item is clicked.                                    |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_LONG_CLICKED           | Event when an item is long-clicked.                                    |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_SELECTED               | Event when an item is selected.                                    |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_TEXT_UPDATE            | Event to be sent when text is updated.                          |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_STATE_UPDATE      | Event to be sent when page navigation, switching, resizing, or moving occurs.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_CONTENT_UPDATE    | Event to be sent when page content changes.              |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_SCROLLED               | Event to be sent when a scrollable component is scrolled.    |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ACCESSIBILITY_FOCUSED  | Event when an item gains accessibility focus.                              |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ACCESSIBILITY_FOCUS_CLEARED | Event when accessibility focus is cleared.                            |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_REQUEST_ACCESSIBILITY_FOCUS | Event to actively request focus on a specific node.                          |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_OPEN              | Event to be sent when a page is closed.                      |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_CLOSE             | Event to be sent when a page is opened.                      |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ANNOUNCE_FOR_ACCESSIBILITY | Event requesting proactive announcement of specific content.                    |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_FOCUS_NODE_UPDATE      | Event to be sent when the focused component's position or size changes.      |

**Since**

13

### ArkUI_AccessibilityFocusMoveDirection

**Description**

Enumerates the focus movement directions.

| Value                                       | Description                                |
| --------------------------------------------- | ------------------------------------ |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_INVALID  | Invalid value.                            |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_UP       | Move focus up.                      |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_DOWN     | Move focus down.                      |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_LEFT     | Move focus left.                      |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_RIGHT    | Move focus right.                      |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_FORWARD  | Move focus forward, based on the relationship in the search results.|
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_BACKWARD | Move focus backward, based on the relationship in the search results.|

**Since**

13
