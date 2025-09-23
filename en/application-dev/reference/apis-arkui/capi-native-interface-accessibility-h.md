# native_interface_accessibility.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhanghangkai10241-->
<!--Designer: @lmleon-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @HelloCrease-->

## Overview

Declares the APIs for accessing Native Accessibility features.

**File to include**: <arkui/native_interface_accessibility.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 13

**Related module**: [ArkUI_Accessibility](capi-arkui-accessibility.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_AccessibleAction](capi-arkui-accessibility-arkui-accessibleaction.md) | ArkUI_AccessibleAction | Defines a struct for accessibility actions.|
| [ArkUI_AccessibleRect](capi-arkui-accessibility-arkui-accessiblerect.md) | ArkUI_AccessibleRect | Provides the bounding rectangle coordinates of the node.|
| [ArkUI_AccessibleRangeInfo](capi-arkui-accessibility-arkui-accessiblerangeinfo.md) | ArkUI_AccessibleRangeInfo | Configures the current value, minimum value, and maximum value for specific components including **Slider**, **Rating**, and **Progress**.|
| [ArkUI_AccessibleGridInfo](capi-arkui-accessibility-arkui-accessiblegridinfo.md) | ArkUI_AccessibleGridInfo | Configures the number of rows, number of columns, and selection mode for specific components including **List**, **Flex**, **Select**, and **Swiper**.|
| [ArkUI_AccessibleGridItemInfo](capi-arkui-accessibility-arkui-accessiblegriditeminfo.md) | ArkUI_AccessibleGridItemInfo | Configures attributes for specific components including **List**, **Flex**, **Select**, and **Swiper**.|
| [ArkUI_AccessibilityProviderCallbacks](capi-arkui-accessibility-arkui-accessibilityprovidercallbacks.md) | ArkUI_AccessibilityProviderCallbacks | Defines a struct for third-party accessibility provider callback functions, which third-party platforms need to implement. These functions are registered with the system side through **OH_ArkUI_AccessibilityProviderRegisterCallback**.|
| [ArkUI_AccessibilityProviderCallbacksWithInstance](capi-arkui-accessibility-arkui-accessibilityprovidercallbackswithinstance.md) | ArkUI_AccessibilityProviderCallbacksWithInstance | Defines the callback function struct for third-party operation providers in multi-instance scenarios. These functions should be implemented by third-party platforms and registered with the system using **OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance**.|
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md) | ArkUI_AccessibilityElementInfo | Provides accessibility node information for accessibility services and assistive applications (such as screen readers).|
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md) | ArkUI_AccessibilityEventInfo | Provides accessibility event information. After a component completes an action requested by an accessibility service or application, it needs to send a success event to confirm the operation.|
| [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md) | ArkUI_AccessibilityProvider |  Defines a third-party accessibility provider, which implements callback functions for accessibility services.|
| [ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md) | ArkUI_AccessibilityActionArguments | Provides additional information of the action to be executed.|
| [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md) | ArkUI_AccessibilityElementInfoList | Provides an encapsulated **ArkUI_AccessibilityElementInfoList** instance.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_Accessibility_ActionType](#arkui_accessibility_actiontype) | ArkUI_Accessibility_ActionType | Enumerates accessibility action types.|
| [ArkUI_AccessibilityEventType](#arkui_accessibilityeventtype) | ArkUI_AccessibilityEventType | Enumerates accessibility event types.|
| [ArkUI_AcessbilityErrorCode](#arkui_acessbilityerrorcode) | ArkUI_AcessbilityErrorCode | Enumerates accessibility error codes.|
| [ArkUI_AccessibilitySearchMode](#arkui_accessibilitysearchmode) | ArkUI_AccessibilitySearchMode | Enumerates accessibility search modes.|
| [ArkUI_AccessibilityFocusType](#arkui_accessibilityfocustype) | ArkUI_AccessibilityFocusType | Enumerates accessibility focus types.|
| [ArkUI_AccessibilityFocusMoveDirection](#arkui_accessibilityfocusmovedirection) | ArkUI_AccessibilityFocusMoveDirection | Enumerates accessibility focus movement directions.|

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_ArkUI_AccessibilityProviderRegisterCallback(ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityProviderCallbacks* callbacks)](#oh_arkui_accessibilityproviderregistercallback) | Registers third-party accessibility provider callback functions with the system.|
| [int32_t OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance(const char* instanceId,ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityProviderCallbacksWithInstance* callbacks)](#oh_arkui_accessibilityproviderregistercallbackwithinstance) | Registers third-party accessibility provider callback functions for multi-instance scenarios.|
| [void OH_ArkUI_SendAccessibilityAsyncEvent(ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityEventInfo* eventInfo,void (\*callback)(int32_t errorCode))](#oh_arkui_sendaccessibilityasyncevent) | Proactively reports an event to notify the accessibility service.|
| [ArkUI_AccessibilityElementInfo* OH_ArkUI_AddAndGetAccessibilityElementInfo(ArkUI_AccessibilityElementInfoList* list)](#oh_arkui_addandgetaccessibilityelementinfo) | Adds an **ArkUI_AccessibilityElementInfo** member to the specified list and returns the **ArkUI_AccessibilityElementInfo** struct.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetElementId(ArkUI_AccessibilityElementInfo* elementInfo, int32_t elementId)](#oh_arkui_accessibilityelementinfosetelementid) | Sets the component ID for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetParentId(ArkUI_AccessibilityElementInfo* elementInfo, int32_t parentId)](#oh_arkui_accessibilityelementinfosetparentid) | Sets the parent ID for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetComponentType(ArkUI_AccessibilityElementInfo* elementInfo, const char* componentType)](#oh_arkui_accessibilityelementinfosetcomponenttype) | Sets the component type for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetContents(ArkUI_AccessibilityElementInfo* elementInfo, const char* contents)](#oh_arkui_accessibilityelementinfosetcontents) | Sets the component content for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetHintText(ArkUI_AccessibilityElementInfo* elementInfo, const char* hintText)](#oh_arkui_accessibilityelementinfosethinttext) | Sets the hint text for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityText(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityText)](#oh_arkui_accessibilityelementinfosetaccessibilitytext) | Sets the accessibility text for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityDescription(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityDescription)](#oh_arkui_accessibilityelementinfosetaccessibilitydescription) | Sets the accessibility description for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetChildNodeIds(ArkUI_AccessibilityElementInfo* elementInfo, int32_t childCount, int64_t* childNodeIds)](#oh_arkui_accessibilityelementinfosetchildnodeids) | Sets the child node count and IDs for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetOperationActions(ArkUI_AccessibilityElementInfo* elementInfo,int32_t operationCount, ArkUI_AccessibleAction* operationActions)](#oh_arkui_accessibilityelementinfosetoperationactions) | Sets the supported operations for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetScreenRect(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleRect* screenRect)](#oh_arkui_accessibilityelementinfosetscreenrect) | Sets the screen coordinates for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetCheckable(ArkUI_AccessibilityElementInfo* elementInfo, bool checkable)](#oh_arkui_accessibilityelementinfosetcheckable) | Sets whether an **ArkUI_AccessibilityElementInfo** object is checkable.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetChecked(ArkUI_AccessibilityElementInfo* elementInfo, bool checked)](#oh_arkui_accessibilityelementinfosetchecked) | Sets the checked state of an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetFocusable(ArkUI_AccessibilityElementInfo* elementInfo, bool focusable)](#oh_arkui_accessibilityelementinfosetfocusable) | Sets whether an **ArkUI_AccessibilityElementInfo** object is focusable.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetFocused(ArkUI_AccessibilityElementInfo* elementInfo, bool isFocused)](#oh_arkui_accessibilityelementinfosetfocused) | Sets the focused state of an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetVisible(ArkUI_AccessibilityElementInfo* elementInfo, bool isVisible)](#oh_arkui_accessibilityelementinfosetvisible) | Sets whether an **ArkUI_AccessibilityElementInfo** object is visible.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityFocused(ArkUI_AccessibilityElementInfo* elementInfo, bool accessibilityFocused)](#oh_arkui_accessibilityelementinfosetaccessibilityfocused) | Sets the accessibility focus state of an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetSelected(ArkUI_AccessibilityElementInfo* elementInfo, bool selected)](#oh_arkui_accessibilityelementinfosetselected) | Sets the selected state of an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetClickable(ArkUI_AccessibilityElementInfo* elementInfo, bool clickable)](#oh_arkui_accessibilityelementinfosetclickable) | Sets whether an **ArkUI_AccessibilityElementInfo** object is clickable.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetLongClickable(ArkUI_AccessibilityElementInfo* elementInfo, bool longClickable)](#oh_arkui_accessibilityelementinfosetlongclickable) | Sets whether an **ArkUI_AccessibilityElementInfo** object is long-clickable.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetEnabled(ArkUI_AccessibilityElementInfo* elementInfo, bool isEnabled)](#oh_arkui_accessibilityelementinfosetenabled) | Sets whether an **ArkUI_AccessibilityElementInfo** object is enabled.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetIsPassword(ArkUI_AccessibilityElementInfo* elementInfo, bool isPassword)](#oh_arkui_accessibilityelementinfosetispassword) | Sets whether an **ArkUI_AccessibilityElementInfo** object contains password text.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetScrollable(ArkUI_AccessibilityElementInfo* elementInfo, bool scrollable)](#oh_arkui_accessibilityelementinfosetscrollable) | Sets whether an **ArkUI_AccessibilityElementInfo** object is scrollable.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetEditable(ArkUI_AccessibilityElementInfo* elementInfo, bool editable)](#oh_arkui_accessibilityelementinfoseteditable) | Sets whether an **ArkUI_AccessibilityElementInfo** object is editable.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetIsHint(ArkUI_AccessibilityElementInfo* elementInfo, bool isHint)](#oh_arkui_accessibilityelementinfosetishint) | Sets whether an **ArkUI_AccessibilityElementInfo** object represents a hint.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetRangeInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleRangeInfo* rangeInfo)](#oh_arkui_accessibilityelementinfosetrangeinfo) | Sets the range information for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetGridInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleGridInfo* gridInfo)](#oh_arkui_accessibilityelementinfosetgridinfo) | Sets the grid layout information for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetGridItemInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleGridItemInfo* gridItem)](#oh_arkui_accessibilityelementinfosetgriditeminfo) | Sets the grid item information for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetSelectedTextStart(ArkUI_AccessibilityElementInfo* elementInfo, int32_t selectedTextStart)](#oh_arkui_accessibilityelementinfosetselectedtextstart) | Sets the start position of selected text for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetSelectedTextEnd(ArkUI_AccessibilityElementInfo* elementInfo, int32_t selectedTextEnd)](#oh_arkui_accessibilityelementinfosetselectedtextend) | Sets the end position of selected text for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetCurrentItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t currentItemIndex)](#oh_arkui_accessibilityelementinfosetcurrentitemindex) | Sets the current item index for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetStartItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t startItemIndex)](#oh_arkui_accessibilityelementinfosetstartitemindex) | Sets the start item index for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetEndItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t endItemIndex)](#oh_arkui_accessibilityelementinfosetenditemindex) | Sets the end item index for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetItemCount(ArkUI_AccessibilityElementInfo* elementInfo, int32_t itemCount)](#oh_arkui_accessibilityelementinfosetitemcount) | Sets the total count of items for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityOffset(ArkUI_AccessibilityElementInfo* elementInfo, int32_t offset)](#oh_arkui_accessibilityelementinfosetaccessibilityoffset) | Sets the offset for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityGroup(ArkUI_AccessibilityElementInfo* elementInfo, bool accessibilityGroup)](#oh_arkui_accessibilityelementinfosetaccessibilitygroup) | Sets the accessibility group for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityLevel(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityLevel)](#oh_arkui_accessibilityelementinfosetaccessibilitylevel) | Sets the accessibility level for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetZIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t zIndex)](#oh_arkui_accessibilityelementinfosetzindex) | Sets the z-index for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityOpacity(ArkUI_AccessibilityElementInfo* elementInfo, float opacity)](#oh_arkui_accessibilityelementinfosetaccessibilityopacity) | Sets the opacity for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetBackgroundColor(ArkUI_AccessibilityElementInfo* elementInfo, const char* backgroundColor)](#oh_arkui_accessibilityelementinfosetbackgroundcolor) | Sets the background color for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetBackgroundImage(ArkUI_AccessibilityElementInfo* elementInfo, const char* backgroundImage)](#oh_arkui_accessibilityelementinfosetbackgroundimage) | Sets the background image for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetBlur(ArkUI_AccessibilityElementInfo* elementInfo, const char* blur)](#oh_arkui_accessibilityelementinfosetblur) | Sets the blur effect for an **ArkUI_AccessibilityElementInfo** object.|
| [int32_t OH_ArkUI_AccessibilityElementInfoSetHitTestBehavior(ArkUI_AccessibilityElementInfo* elementInfo, const char* hitTestBehavior)](#oh_arkui_accessibilityelementinfosethittestbehavior) | Sets the hit test behavior for an **ArkUI_AccessibilityElementInfo** object.|
| [ArkUI_AccessibilityElementInfo* OH_ArkUI_CreateAccessibilityElementInfo(void)](#oh_arkui_createaccessibilityelementinfo) | Creates an **ArkUI_AccessibilityElementInfo** object, which must be destroyed with **OH_ArkUI_DestroyAccessibilityElementInfo**.|
| [void OH_ArkUI_DestoryAccessibilityElementInfo(ArkUI_AccessibilityElementInfo* elementInfo)](#oh_arkui_destoryaccessibilityelementinfo) | Destroys an **ArkUI_AccessibilityElementInfo** object.|
| [ArkUI_AccessibilityEventInfo* OH_ArkUI_CreateAccessibilityEventInfo(void)](#oh_arkui_createaccessibilityeventinfo) | Creates an **ArkUI_AccessibilityEventInfo** object, which must be destroyed with **OH_ArkUI_DestoryAccessibilityEventInfo**.|
| [void OH_ArkUI_DestoryAccessibilityEventInfo(ArkUI_AccessibilityEventInfo* eventInfo)](#oh_arkui_destoryaccessibilityeventinfo) | Destroys an **ArkUI_AccessibilityEventInfo** object.|
| [int32_t OH_ArkUI_AccessibilityEventSetEventType(ArkUI_AccessibilityEventInfo* eventInfo,  ArkUI_AccessibilityEventType eventType)](#oh_arkui_accessibilityeventseteventtype) | Sets the event type for an **ArkUI_AccessibilityEventInfo** object.|
| [int32_t OH_ArkUI_AccessibilityEventSetTextAnnouncedForAccessibility(ArkUI_AccessibilityEventInfo* eventInfo,  const char* textAnnouncedForAccessibility)](#oh_arkui_accessibilityeventsettextannouncedforaccessibility) | Sets the announcement text for an **ArkUI_AccessibilityEventInfo** object.|
| [int32_t OH_ArkUI_AccessibilityEventSetRequestFocusId(ArkUI_AccessibilityEventInfo* eventInfo,  int32_t requestFocusId)](#oh_arkui_accessibilityeventsetrequestfocusid) | Sets the focus request ID for an **ArkUI_AccessibilityEventInfo** object.|
| [int32_t OH_ArkUI_AccessibilityEventSetElementInfo(ArkUI_AccessibilityEventInfo* eventInfo,  ArkUI_AccessibilityElementInfo* elementInfo)](#oh_arkui_accessibilityeventsetelementinfo) | Sets the element information for an **ArkUI_AccessibilityEventInfo** object.|
| [int32_t OH_ArkUI_FindAccessibilityActionArgumentByKey(ArkUI_AccessibilityActionArguments* arguments, const char* key, char** value)](#oh_arkui_findaccessibilityactionargumentbykey) | Obtains the value associated with the specified key in **ArkUI_AccessibilityActionArguments**.|

## Enum Description

### ArkUI_Accessibility_ActionType

```
enum ArkUI_Accessibility_ActionType
```

**Description**


Enumerates accessibility action types.

**Since**: 13

| Value| Description                                                                                                                               |
| -- |-----------------------------------------------------------------------------------------------------------------------------------|
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_INVALID = 0 | Invalid value.                                                                                                                              |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLICK = 0x00000010 | Triggers the component's click event handling.                                                                                                               |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_LONG_CLICK = 0x00000020 | Triggers the component's long-click event handling.                                                                                                              |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_GAIN_ACCESSIBILITY_FOCUS = 0x00000040 | Requests accessibility focus for the component.                                                                                                           |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLEAR_ACCESSIBILITY_FOCUS = 0x00000080 | Clears accessibility focus from the component.                                                                                                                   |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_FORWARD = 0x00000100 | Initiates forward scrolling in scrollable containers.                                                                                                                    |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SCROLL_BACKWARD = 0x00000200 | Initiates backward scrolling in scrollable containers.                                                                                                                    |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_COPY = 0x00000400 | Copies the current text selection.                                                                                                                     |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_PASTE = 0x00000800 | Pastes content to the text component.                                                                                                                     |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CUT = 0x00001000 | Cuts the current text selection to the pasteboard.                                                                                                                     |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SELECT_TEXT = 0x00002000 | Selects a range of text within an editable area in a text component. Used together with **ArkUI_AccessibilityActionArguments** to configure **selectTextStart**, **selectTextEnd**, and **selectTextInForWard**.                                                                     |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SET_TEXT = 0x00004000 | Sets the text content of the text component.                                                                                                                     |
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_SET_CURSOR_POSITION = 0x00100000 | Sets the text cursor position. Used together with **ArkUI_AccessibilityActionArguments** to configure **offset**.|
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_NEXT_HTML_ITEM = 0x02000000 | Moves focus to the next focusable component. Note: "HTML" indicates the web-like navigation capability, not actual web elements. This API requires implementation of **findNextFocusAccessibilityNode**.<br>**Since**: 15|
| ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_PREVIOUS_HTML_ITEM = 0x04000000 | Moves focus to the previous focusable component. Note: "HTML" indicates the web-like navigation capability, not actual web elements. This API requires implementation of **findNextFocusAccessibilityNode**.<br>**Since**: 15    |

### ArkUI_AccessibilityEventType

```
enum ArkUI_AccessibilityEventType
```

**Description**


Enumerates accessibility event types.

**Since**: 13

| Value| Description|
| -- | -- |
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_INVALID = 0 | Invalid value.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_CLICKED = 0x00000001 | Click event, sent after the UI component responds.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_LONG_CLICKED = 0x00000002 | Long-click event, sent after the UI component responds.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_SELECTED = 0x00000004 | Selection event, sent after the UI component responds.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_TEXT_UPDATE = 0x00000010 | Text update event, sent when text is updated.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_STATE_UPDATE = 0x00000020 | Page state update event, sent on page navigation, switching, resizing, or movement.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_CONTENT_UPDATE = 0x00000800 | Page content update event, sent when the page content changes.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_SCROLLED = 0x000001000 | Scroll event, sent when scrolling occurs on scrollable components.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ACCESSIBILITY_FOCUSED = 0x00008000 | Accessibility focus event, sent after the UI component receives focus.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ACCESSIBILITY_FOCUS_CLEARED = 0x00010000 | Accessibility focus cleared event, sent after the UI component loses focus.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_REQUEST_ACCESSIBILITY_FOCUS = 0x02000000 | Event to actively requests focus for the specified node.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_OPEN = 0x20000000 | Page open event reported by the UI component.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_CLOSE = 0x08000000 | Page close event reported by the UI component.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ANNOUNCE_FOR_ACCESSIBILITY = 0x10000000 | Announcement event, indicating a request to proactively announce specified content.|
| ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_FOCUS_NODE_UPDATE = 0x10000001 | Focus update event, used in the focus update scenarios.|

### ArkUI_AcessbilityErrorCode

```
enum ArkUI_AcessbilityErrorCode
```

**Description**


Enumerates accessibility error codes.

**Since**: 13

| Value| Description|
| -- | -- |
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL = 0 | The operation is successful.|
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_FAILED = -1 | The operation failed.|
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER = -2 | Invalid parameter.|
| ARKUI_ACCESSIBILITY_NATIVE_RESULT_OUT_OF_MEMORY = -3 | Insufficient memory.|

### ArkUI_AccessibilitySearchMode

```
enum ArkUI_AccessibilitySearchMode
```

**Description**


Enumerates accessibility search modes.

**Since**: 13

| Value| Description|
| -- | -- |
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_CURRENT = 0 | Searches the current node.|
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_PREDECESSORS = 1 << 0 | Searches parent nodes.|
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_SIBLINGS = 1 << 1 | Searches sibling nodes.|
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_CHILDREN = 1 << 2 | Searches immediate child nodes.|
| ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_RECURSIVE_CHILDREN = 1 << 3 | Searches all child nodes.|

### ArkUI_AccessibilityFocusType

```
enum ArkUI_AccessibilityFocusType
```

**Description**


Enumerates accessibility focus types.

**Since**: 13

| Value| Description|
| -- | -- |
| ARKUI_ACCESSIBILITY_NATIVE_FOCUS_TYPE_INVALID = -1 | Invalid value.|
| ARKUI_ACCESSIBILITY_NATIVE_FOCUS_TYPE_INPUT = 1 << 0 | Input focus type.|
| ARKUI_ACCESSIBILITY_NATIVE_FOCUS_TYPE_ACCESSIBILITY = 1 << 1 | Accessibility focus type.|

### ArkUI_AccessibilityFocusMoveDirection

```
enum ArkUI_AccessibilityFocusMoveDirection
```

**Description**


Enumerates accessibility focus movement directions.

**Since**: 13

| Value| Description|
| -- | -- |
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_INVALID = 0 | Invalid value.|
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_UP = 0x00000001 | Moves focus up.|
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_DOWN = 0x00000002 | Moves focus down.|
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_LEFT = 0x00000004 | Moves focus left.|
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_RIGHT = 0x00000008 | Moves focus right.|
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_FORWARD = 0x00000010 | Moves focus to the next focusable node (relative to the reference node in query).|
| ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_BACKWARD = 0x00000020 | Moves focus to the previous focusable node (relative to the reference node in query).|


## Function Description

### OH_ArkUI_AccessibilityProviderRegisterCallback()

```
int32_t OH_ArkUI_AccessibilityProviderRegisterCallback(ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityProviderCallbacks* callbacks)
```

**Description**


Defines a struct for third-party accessibility provider callback functions, which third-party platforms need to implement. These functions are registered with the system side through **OH_ArkUI_AccessibilityProviderRegisterCallback**.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)* provider | Pointer to an **ArkUI_AccessibilityProvider** instance.|
| [ArkUI_AccessibilityProviderCallbacks](capi-arkui-accessibility-arkui-accessibilityprovidercallbacks.md)* callbacks | Pointer to the callback.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance()

```
int32_t OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance(const char* instanceId,ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityProviderCallbacksWithInstance* callbacks)
```

**Description**


Registers third-party accessibility provider callback functions for multi-instance scenarios.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| const char* instanceId | Instance ID for third-party platform integration, used to distinguish between different instances in multi-instance scenarios. The ID is assigned and maintained by the third-party platform.|
| [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)* provider | Handle to the third-party platform provider.|
| [ArkUI_AccessibilityProviderCallbacksWithInstance](capi-arkui-accessibility-arkui-accessibilityprovidercallbackswithinstance.md)* callbacks | Pointer to an **ArkUI_AccessibilityProviderCallbacksWithInstance** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_SendAccessibilityAsyncEvent()

```
void OH_ArkUI_SendAccessibilityAsyncEvent(ArkUI_AccessibilityProvider* provider, ArkUI_AccessibilityEventInfo* eventInfo,void (*callback)(int32_t errorCode))
```

**Description**


Proactively sends an event to notify the accessibility service.

**Since**: 13


**Parameters**

| Name                                                                                             | Description|
|--------------------------------------------------------------------------------------------------| -- |
| [ArkUI_AccessibilityProvider](capi-arkui-accessibility-arkui-accessibilityprovider.md)* provider | Handle to the third-party platform provider.|
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* eventInfo                                                      | Pointer to the accessibility event information.|
| callback                                                                                         | Callback that receives the asynchronous operation result.|

### OH_ArkUI_AddAndGetAccessibilityElementInfo()

```
ArkUI_AccessibilityElementInfo* OH_ArkUI_AddAndGetAccessibilityElementInfo(ArkUI_AccessibilityElementInfoList* list)
```

**Description**


Adds an **ArkUI_AccessibilityElementInfo** member to the specified list and returns the **ArkUI_AccessibilityElementInfo** struct.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfoList](capi-arkui-accessibility-arkui-accessibilityelementinfolist.md)* list | **ArkUI_AccessibilityElementInfoList** struct to which the newly created **ArkUI_AccessibilityElementInfo** member is added and then returned to the function caller.|

**Returns**

| Type                                 | Description|
|-------------------------------------| -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* | Returns the pointer to the created **ArkUI_AccessibilityElementInfo** struct; returns **NULL** if creation fails.|

### OH_ArkUI_AccessibilityElementInfoSetElementId()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetElementId(ArkUI_AccessibilityElementInfo* elementInfo, int32_t elementId)
```

**Description**


Sets the component ID for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| int32_t elementId | Element ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetParentId()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetParentId(ArkUI_AccessibilityElementInfo* elementInfo, int32_t parentId)
```

**Description**


Sets the parent ID for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| int32_t parentId | Parent ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetComponentType()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetComponentType(ArkUI_AccessibilityElementInfo* elementInfo, const char* componentType)
```

**Description**


Sets the component type for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| const char* componentType | Component type.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetContents()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetContents(ArkUI_AccessibilityElementInfo* elementInfo, const char* contents)
```

**Description**


Sets the component content for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| const char* contents | Component content.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetHintText()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetHintText(ArkUI_AccessibilityElementInfo* elementInfo, const char* hintText)
```

**Description**


Sets the hint text for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| const char* hintText | Hint text.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityText()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityText(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityText)
```

**Description**


Sets the accessibility text for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| const char* accessibilityText | Accessibility text.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityDescription()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityDescription(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityDescription)
```

**Description**

Sets the accessibility description for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| const char* accessibilityDescription | Accessibility description.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetChildNodeIds()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetChildNodeIds(ArkUI_AccessibilityElementInfo* elementInfo, int32_t childCount, int64_t* childNodeIds)
```

**Description**

Sets the child node count and IDs for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| int32_t childCount | Child node count.|
| int64_t* childNodeIds | Array of child node IDs.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetOperationActions()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetOperationActions(ArkUI_AccessibilityElementInfo* elementInfo,int32_t operationCount, ArkUI_AccessibleAction* operationActions)
```

**Description**


Sets the supported operations for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| int32_t* operationCount | Number of actions supported by the component.|
| [ArkUI_AccessibleAction](capi-arkui-accessibility-arkui-accessibleaction.md)* operationActions | Array of actions supported by the component.|


**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetScreenRect()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetScreenRect(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleRect* screenRect)
```

**Description**


Sets the screen coordinates for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| [ArkUI_AccessibleRect](capi-arkui-accessibility-arkui-accessiblerect.md)* screenRect | Screen coordinates.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetCheckable()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetCheckable(ArkUI_AccessibilityElementInfo* elementInfo, bool checkable)
```

**Description**


Sets whether an **ArkUI_AccessibilityElementInfo** object is checkable.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool checkable | Whether the element is checkable.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetChecked()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetChecked(ArkUI_AccessibilityElementInfo* elementInfo, bool checked)
```

**Description**


Sets the checked state of an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool checked | Checked state.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetFocusable()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetFocusable(ArkUI_AccessibilityElementInfo* elementInfo, bool focusable)
```

**Description**


Sets whether an **ArkUI_AccessibilityElementInfo** object is focusable.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool focusable | Whether the element is focusable.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetFocused()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetFocused(ArkUI_AccessibilityElementInfo* elementInfo, bool isFocused)
```

**Description**


Sets the focused state of an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool isFocused | Focused state.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetVisible()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetVisible(ArkUI_AccessibilityElementInfo* elementInfo, bool isVisible)
```

**Description**

Sets whether an **ArkUI_AccessibilityElementInfo** object is visible.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool isVisible | Whether the element is visible.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityFocused()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityFocused(ArkUI_AccessibilityElementInfo* elementInfo, bool accessibilityFocused)
```

**Description**

Sets the accessibility focus state of an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool accessibilityFocused | Accessibility focus state.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetSelected()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetSelected(ArkUI_AccessibilityElementInfo* elementInfo, bool selected)
```

**Description**


Sets the selected state of an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool selected | Selected state.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetClickable()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetClickable(ArkUI_AccessibilityElementInfo* elementInfo, bool clickable)
```

**Description**


Sets whether an **ArkUI_AccessibilityElementInfo** object is clickable.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool clickable | Whether the element is clickable.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetLongClickable()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetLongClickable(ArkUI_AccessibilityElementInfo* elementInfo, bool longClickable)
```

**Description**


Sets whether an **ArkUI_AccessibilityElementInfo** object is long-clickable.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool longClickable | Whether the element is long-clickable.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetEnabled()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetEnabled(ArkUI_AccessibilityElementInfo* elementInfo, bool isEnabled)
```

**Description**


Sets whether an **ArkUI_AccessibilityElementInfo** object is enabled.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool isEnabled | Whether the element is enabled.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetIsPassword()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetIsPassword(ArkUI_AccessibilityElementInfo* elementInfo, bool isPassword)
```

**Description**


Sets whether an **ArkUI_AccessibilityElementInfo** object contains password text.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool isPassword | Whether the element contains password text.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetScrollable()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetScrollable(ArkUI_AccessibilityElementInfo* elementInfo, bool scrollable)
```

**Description**


Sets whether an **ArkUI_AccessibilityElementInfo** object is scrollable.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool scrollable | Whether the element is scrollable.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetEditable()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetEditable(ArkUI_AccessibilityElementInfo* elementInfo, bool editable)
```

**Description**


Sets whether an **ArkUI_AccessibilityElementInfo** object is editable.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool editable | Whether the element is editable.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetIsHint()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetIsHint(ArkUI_AccessibilityElementInfo* elementInfo, bool isHint)
```

**Description**


Sets whether an **ArkUI_AccessibilityElementInfo** object represents a hint.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool isHint | Whether the element represents a hint.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetRangeInfo()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetRangeInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleRangeInfo* rangeInfo)
```

**Description**


Sets the range information for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| [ArkUI_AccessibleRangeInfo](capi-arkui-accessibility-arkui-accessiblerangeinfo.md)* rangeInfo | Range information.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetGridInfo()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetGridInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleGridInfo* gridInfo)
```

**Description**


Sets the grid layout information for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| [ArkUI_AccessibleGridInfo](capi-arkui-accessibility-arkui-accessiblegridinfo.md)* gridInfo | Grid layout information.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetGridItemInfo()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetGridItemInfo(ArkUI_AccessibilityElementInfo* elementInfo, ArkUI_AccessibleGridItemInfo* gridItem)
```

**Description**


Sets the grid item information for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| [ArkUI_AccessibleGridItemInfo](capi-arkui-accessibility-arkui-accessiblegriditeminfo.md)* gridItem | Grid item information.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetSelectedTextStart()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetSelectedTextStart(ArkUI_AccessibilityElementInfo* elementInfo, int32_t selectedTextStart)
```

**Description**


Sets the start position of selected text for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| int32_t selectedTextStart | Start position of selected text.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetSelectedTextEnd()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetSelectedTextEnd(ArkUI_AccessibilityElementInfo* elementInfo, int32_t selectedTextEnd)
```

**Description**


Sets the end position of selected text for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| int32_t selectedTextEnd | End position of selected text.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetCurrentItemIndex()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetCurrentItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t currentItemIndex)
```

**Description**


Sets the current item index for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| int32_t currentItemIndex | Current item index.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetStartItemIndex()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetStartItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t startItemIndex)
```

**Description**


Sets the start item index for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| int32_t startItemIndex | Start item index.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetEndItemIndex()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetEndItemIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t endItemIndex)
```

**Description**


Sets the end item index for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| int32_t endItemIndex | End item index.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **OH_ARKUI_ACCESSIBILITY_RESULT_SUCCESS** if the operation is successful.<br>Returns **OH_ARKUI_ACCESSIBILITY_RESULT_BAD_PARAMETER** if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetItemCount()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetItemCount(ArkUI_AccessibilityElementInfo* elementInfo, int32_t itemCount)
```

**Description**


Sets the total count of items for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| int32_t itemCount | Total count of items.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityOffset()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityOffset(ArkUI_AccessibilityElementInfo* elementInfo, int32_t offset)
```

**Description**


Sets the offset for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| int32_t offset | Scroll pixel offset relative to the top of the element.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityGroup()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityGroup(ArkUI_AccessibilityElementInfo* elementInfo, bool accessibilityGroup)
```

**Description**


Sets the accessibility group for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| bool accessibilityGroup | Accessibility group.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityLevel()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityLevel(ArkUI_AccessibilityElementInfo* elementInfo, const char* accessibilityLevel)
```

**Description**


Sets the accessibility level for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| const char* accessibilityLevel | Accessibility level.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetZIndex()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetZIndex(ArkUI_AccessibilityElementInfo* elementInfo, int32_t zIndex)
```

**Description**


Sets the z-index for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| int32_t zIndex | Z-index.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetAccessibilityOpacity()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetAccessibilityOpacity(ArkUI_AccessibilityElementInfo* elementInfo, float opacity)
```

**Description**


Sets the opacity for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| float opacity | Opacity.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetBackgroundColor()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetBackgroundColor(ArkUI_AccessibilityElementInfo* elementInfo, const char* backgroundColor)
```

**Description**


Sets the background color for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| const char* backgroundColor | Background color.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetBackgroundImage()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetBackgroundImage(ArkUI_AccessibilityElementInfo* elementInfo, const char* backgroundImage)
```

**Description**


Sets the background image for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| const char* backgroundImage | Background image.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetBlur()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetBlur(ArkUI_AccessibilityElementInfo* elementInfo, const char* blur)
```

**Description**


Sets the blur effect for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| const char* blur | Blur effect.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityElementInfoSetHitTestBehavior()

```
int32_t OH_ArkUI_AccessibilityElementInfoSetHitTestBehavior(ArkUI_AccessibilityElementInfo* elementInfo, const char* hitTestBehavior)
```

**Description**


Sets the hit test behavior for an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|
| const char* hitTestBehavior | Hit test behavior.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_CreateAccessibilityElementInfo()

```
ArkUI_AccessibilityElementInfo* OH_ArkUI_CreateAccessibilityElementInfo(void)
```

**Description**


Creates an **ArkUI_AccessibilityElementInfo** object, which must be destroyed with **OH_ArkUI_DestroyAccessibilityElementInfo**.

**Since**: 13

**Returns**

| Type                                 | Description|
|-------------------------------------| -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* | **ArkUI_AccessibilityElementInfo** object.|

### OH_ArkUI_DestoryAccessibilityElementInfo()

```
void OH_ArkUI_DestoryAccessibilityElementInfo(ArkUI_AccessibilityElementInfo* elementInfo)
```

**Description**


Destroys an **ArkUI_AccessibilityElementInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** instance.|

### OH_ArkUI_CreateAccessibilityEventInfo()

```
ArkUI_AccessibilityEventInfo* OH_ArkUI_CreateAccessibilityEventInfo(void)
```

**Description**


Creates an **ArkUI_AccessibilityEventInfo** object, which must be destroyed with **OH_ArkUI_DestoryAccessibilityEventInfo**.

**Since**: 13

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* | **ArkUI_AccessibilityEventInfo** object.|

### OH_ArkUI_DestoryAccessibilityEventInfo()

```
void OH_ArkUI_DestoryAccessibilityEventInfo(ArkUI_AccessibilityEventInfo* eventInfo)
```

**Description**


Destroys an **ArkUI_AccessibilityEventInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* eventInfo | **ArkUI_AccessibilityEventInfo** object to destroy.|

### OH_ArkUI_AccessibilityEventSetEventType()

```
int32_t OH_ArkUI_AccessibilityEventSetEventType(ArkUI_AccessibilityEventInfo* eventInfo,  ArkUI_AccessibilityEventType eventType)
```

**Description**


Sets the event type for an **ArkUI_AccessibilityEventInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* eventInfo | Pointer to an **ArkUI_AccessibilityEventInfo** object.|
| [ArkUI_AccessibilityEventType](capi-native-interface-accessibility-h.md#arkui_accessibilityeventtype) eventType | Event type.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityEventSetTextAnnouncedForAccessibility()

```
int32_t OH_ArkUI_AccessibilityEventSetTextAnnouncedForAccessibility(ArkUI_AccessibilityEventInfo* eventInfo,  const char* textAnnouncedForAccessibility)
```

**Description**


Sets the announcement text for an **ArkUI_AccessibilityEventInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* eventInfo | Pointer to an **ArkUI_AccessibilityEventInfo** object.|
| const char* textAnnouncedForAccessibility | Announcement text.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityEventSetRequestFocusId()

```
int32_t OH_ArkUI_AccessibilityEventSetRequestFocusId(ArkUI_AccessibilityEventInfo* eventInfo,  int32_t requestFocusId)
```

**Description**


Sets the focus request ID for an **ArkUI_AccessibilityEventInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* eventInfo | Pointer to an **ArkUI_AccessibilityEventInfo** object.|
| int32_t requestFocusId | Focus request ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_AccessibilityEventSetElementInfo()

```
int32_t OH_ArkUI_AccessibilityEventSetElementInfo(ArkUI_AccessibilityEventInfo* eventInfo,  ArkUI_AccessibilityElementInfo* elementInfo)
```

**Description**


Sets the element information for an **ArkUI_AccessibilityEventInfo** object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityEventInfo](capi-arkui-accessibility-arkui-accessibilityeventinfo.md)* eventInfo | Pointer to an **ArkUI_AccessibilityEventInfo** object.|
| [ArkUI_AccessibilityElementInfo](capi-arkui-accessibility-arkui-accessibilityelementinfo.md)* elementInfo | Pointer to an **ArkUI_AccessibilityElementInfo** object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|

### OH_ArkUI_FindAccessibilityActionArgumentByKey()

```
int32_t OH_ArkUI_FindAccessibilityActionArgumentByKey(ArkUI_AccessibilityActionArguments* arguments, const char* key, char** value)
```

**Description**


Obtains the value associated with a specified key in an **ArkUI_AccessibilityEventInfo** struct.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityActionArguments](capi-arkui-accessibility-arkui-accessibilityactionarguments.md)* arguments | Pointer to an **ArkUI_AccessibilityActionArguments** object.|
| const char* key | Key.|
| char** value | Value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_SUCCESSFUL](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if the operation is successful.<br>Returns [ARKUI_ACCESSIBILITY_NATIVE_RESULT_BAD_PARAMETER](capi-native-interface-accessibility-h.md#arkui_acessbilityerrorcode) if a parameter error occurs.|
