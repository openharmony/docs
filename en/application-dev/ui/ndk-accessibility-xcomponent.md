# Integrating Accessibility Through XComponent

The NDK provides third-party platforms accessed through **XComponent** with APIs for integrating accessibility, allowing components of these platforms to be accessible within ArkUI.

First, you need to use the [OH_NativeXComponent_GetNativeAccessibilityProvider](../reference/apis-arkui/_o_h___native_x_component.md#oh_nativexcomponent_getnativeaccessibilityprovider) API of the **XComponent** to obtain the accessibility provider. Then, call [OH_ArkUI_AccessibilityProviderRegisterCallback](../reference/apis-arkui/arkui_native_interface_accessibility.md#oh_arkui_accessibilityproviderregistercallback) to register the required callback functions for accessibility: [ArkUI_AccessibilityProviderCallbacks](../reference/apis-arkui/arkui_native_interface_accessibility.md#arkui_accessibilityprovidercallbacks).

To deliver a smooth accessibility service experience, third-party applications must adapt to the [actions](../reference/apis-arkui/arkui_native_interface_accessibility.md#arkui_accessibility_actiontype) sent by the accessibility subsystem and send [accessibility events](../reference/apis-arkui/arkui_native_interface_accessibility.md#arkui_accessibilityeventtype) to the accessibility subsystem in response to component interactions.

> **NOTE**
>
> - When implementing the callback query API of [OH_ArkUI_AccessibilityProviderRegisterCallback](../reference/apis-arkui/arkui_native_interface_accessibility.md#oh_arkui_accessibilityproviderregistercallback), each accessibility node information found is created and allocated memory with [OH_ArkUI_AddAndGetAccessibilityElementInfo](../reference/apis-arkui/arkui_native_interface_accessibility.md#oh_arkui_addandgetaccessibilityelementinfo) and added to the specified element list.
> - When sending events with [OH_ArkUI_SendAccessibilityAsyncEvent](../reference/apis-arkui/arkui_native_interface_accessibility.md#oh_arkui_sendaccessibilityasyncevent), you need to create [ArkUI_AccessibilityEventInfo](../reference/apis-arkui/arkui_native_interface_accessibility.md#arkui_accessibilityeventinfo) with [OH_ArkUI_CreateAccessibilityEventInfo](../reference/apis-arkui/arkui_native_interface_accessibility.md#oh_arkui_createaccessibilityeventinfo) and [ArkUI_AccessibilityElementInfo](../reference/apis-arkui/arkui_native_interface_accessibility.md#arkui_accessibilityelementinfo) with [OH_ArkUI_CreateAccessibilityElementInfo](../reference/apis-arkui/arkui_native_interface_accessibility.md#oh_arkui_createaccessibilityelementinfo). After usage, you must call [OH_ArkUI_DestoryAccessibilityEventInfo](../reference/apis-arkui/arkui_native_interface_accessibility.md#oh_arkui_destoryaccessibilityeventinfo) and [OH_ArkUI_DestoryAccessibilityElementInfo](../reference/apis-arkui/arkui_native_interface_accessibility.md#oh_arkui_destoryaccessibilityelementinfo) to release memory.
> - When logging within callback functions, include the provided **requestId** parameter to link logs to a specific interaction process. This practice facilitates indexing and querying and aids in troubleshooting and pinpointing issues.

## Integrating Accessibility

The following example shows how to integrate accessibility capabilities. After integration, when accessibility features are enabled, third-party rendering components of the **XComponent** can be integrated to achieve accessible interactions.

1. Follow the instructions in [Custom Rendering (XComponent)](napi-xcomponent-guidelines.md) to create the prerequisite project.

2. Implement callback functions based on the API definition.

```c
int32_t FindAccessibilityNodeInfosById(int64_t elementId, ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)
{
    // Query the element information list based on mode.
	if (elementList == nullptr) {
        return OH_NATIVEXCOMPONENT_RESULT_FAILED;
    }
	
    // Call the API of the third-party platform to search for the nodes that meet the mode requirements.
    //...
    // nodes is the search result.
    int size = sizeof(nodes) / sizeof(nodes[0]);
    for (int i = 0; i < size; i++) {
        // Obtain the element structure.
        element = OH_ArkUI_AddAndGetAccessibilityElementInfo(elementList);
        // Set the element member content.
        OH_ArkUI_AccessibilityElementInfoSetElementId(element, nodes[i].id);
        OH_ArkUI_AccessibilityElementInfoSetComponentType(element, nodes[i].type);
        // ...
    }
	// ...
}
```



```c
int32_t FindNextFocusAccessibilityNode(int64_t elementId, ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo* elementinfo)
{
    // Query the element information list based on mode. For details, see the API description.
	if (elementinfo == nullptr) {
        return OH_NATIVEXCOMPONENT_RESULT_FAILED;
    }
	
    // Call the API of the third-party platform to search for the nodes that meet the search criteria.
    //...
    // nodes is the search result.
    // Set the element member content.
    OH_ArkUI_AccessibilityElementInfoSetElementId(element, nodes[i].id);
    OH_ArkUI_AccessibilityElementInfoSetComponentType(element, nodes[i].type);
    // ...
}
```



```c
int32_t FindAccessibilityNodeInfosByText(int64_t elementId, const char *text, int32_t requestId, ArkUI_AccessibilityElementInfoList* elementList)
{
    if (elementList == nullptr) {
        return OH_NATIVEXCOMPONENT_RESULT_FAILED;
    }
    
    ArkUI_AccessibilityElementInfo *elementInfo = OH_ArkUI_AddAndGetAccessibilityElementInfo(elementList);
    
    // The third-party platform needs to set elementInfo.
    
    if (elementInfo == nullptr) {
        return OH_NATIVEXCOMPONENT_RESULT_FAILED;
    }
    return OH_NATIVEXCOMPONENT_RESULT_SUCCESS;
}
```



```c
int32_t FindFocusedAccessibilityNode(int64_t elementId, ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo *elementInfo)
{   
    if (elementInfo == nullptr) {
        return OH_NATIVEXCOMPONENT_RESULT_FAILED;
    }
    
    // The third-party platform needs to set elementInfo.
    
    return OH_NATIVEXCOMPONENT_RESULT_SUCCESS;
}
```



```C
int32_t ExecuteAccessibilityAction(int64_t elementId, ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId)
{
    // ...
    // Obtain action argument content and combine it with action to determine the operation to be processed.
    char* actionArgumentValue;
    OH_ArkUI_FindAccessibilityActionArgumentByKey(actionArguments, key.c_str(), &actionArgumentValue);
    
    // Perform operations on the specified component node.
    ret = doAction(elementId, action, actionArgumentValue);
    if (ret != 0) {
        return;
    }
    // Determine the current operation type and return the corresponding event result. Each operation corresponds to a unique event. For details, see the ArkUI_AccessibilityEventType description.
    // ...
    // Specify that the component node that reports the event is node.
    // 1. Call OH_ArkUI_CreateAccessibilityEventInfo to create an ArkUI_AccessibilityEventInfo instance.
    ArkUI_AccessibilityEventInfo *eventInfo = OH_ArkUI_CreateAccessibilityEventInfo();
    if (eventInfo == nullptr) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "[requestId: %{public}d]DispatchTouchEventCB: Unable to create accessibility eventInfo", requestId);
        return;
    }
    // 2. Call OH_ArkUI_CreateAccessibilityElementInfo to create an ArkUI_AccessibilityElementInfo instance.
    ArkUI_AccessibilityElementInfo *elementInfo = OH_ArkUI_CreateAccessibilityElementInfo();
    if (elementInfo == nullptr) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "[requestId: %{public}d]DispatchTouchEventCB: Unable to create accessibility elementInfo", requestId);
        return;
    }
    // 3. Enter the element content.
    // Set the element member content.
    OH_ArkUI_AccessibilityElementInfoSetElementId(element, nodes[i].id);
    OH_ArkUI_AccessibilityElementInfoSetComponentType(element, nodes[i].type);
 
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "[requestId: %{public}d]DispatchTouchEventCB: send accessibility event", requestId);
    // 4. Set eventType based on the current action.
    // ...
    SendAccessibilityAsyncEvent(eventInfo, elementInfo, eventType);
    // 5. Destroy the memory for eventInfo and elementInfo.
    OH_ArkUI_DestoryAccessibilityElementInfo(elementInfo);
    OH_ArkUI_DestoryAccessibilityEventInfo(eventInfo);
    // ...
}
void FillEvent(ArkUI_AccessibilityEventInfo *eventInfo, ArkUI_AccessibilityElementInfo *elementInfo, ArkUI_AccessibilityEventType eventType) 
{
    if (eventInfo == nullptr) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_TEXT, "eventInfo is null");
        return;
    }
    if (elementInfo == nullptr) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_TEXT, "elementInfo is null");
        return;
    }
    OH_ArkUI_AccessibilityEventSetEventType(eventInfo, eventType);
    
    OH_ArkUI_AccessibilityEventSetElementInfo(eventInfo, elementInfo);
    
}
void SendAccessibilityAsyncEvent(ArkUI_AccessibilityEventInfo *eventInfo, ArkUI_AccessibilityElementInfo *elementInfo, ArkUI_AccessibilityEventType eventType)
{
    // 1. Enter the event content.
    FillEvent(eventInfo, elementInfo, ArkUI_AccessibilityEventType::ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_STATE_UPDATE);
    // 2. Callback
    auto callback = [](int32_t errorCode){
         OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "result: %{public}d", errorCode);
    }
    // 3. Call the API to send the event to the OpenHarmony side.
    OH_ArkUI_SendAccessibilityAsyncEvent(provider_, eventInfo, callback)
}
```



```C
int32_t ClearFocusedFocusAccessibilityNode()
{
	// Find the currently focused component and clear its focus state.
    // ...
    // Accessibility focus state
    node.accessibilityFocused = false;
    // Component focus state
    node.foucsed = false;
    // ...
}
```



```C
int32_t GetAccessibilityNodeCursorPosition(int64_t elementId, int32_t requestId, int32_t* index)
{	
	// Obtain the cursor position of the text component and return it.
    // Search for the corresponding component node.
    // ...
    *index = node.cursorPosition;
    // ...
}
```



3. Register the accessibility callback functions using the **XComponent** handle.

```C
void PluginRender::RegisterAccessibility(OH_NativeXComponent* nativeXComponent)
{
	//...
    // 1. Obtain the provider instance and provide it to the function for return.
    int32_t ret = OH_NativeXComponent_GetNativeAccessibilityProvider(nativeXComponent, &provider_);
    if (provider_ == nullptr) {
        return;
    }
    // 2. Register the callback functions, such as FindAccessibilityNodeInfosById, which need to be implemented by the third party.
    accessibilityProviderCallbacks_ = new ArkUI_AccessibilityProviderCallbacks();
    accessibilityProviderCallbacks_->findAccessibilityNodeInfosById = FindAccessibilityNodeInfosById;
    accessibilityProviderCallbacks_->findAccessibilityNodeInfosByText = FindAccessibilityNodeInfosByText;
    accessibilityProviderCallbacks_->findFocusedAccessibilityNode = FindFocusedAccessibilityNode;
    accessibilityProviderCallbacks_->findNextFocusAccessibilityNode = FindNextFocusAccessibilityNode;
    accessibilityProviderCallbacks_->executeAccessibilityAction = ExecuteAccessibilityAction;
    accessibilityProviderCallbacks_->clearFocusedFocusAccessibilityNode = ClearFocusedFocusAccessibilityNode;
    accessibilityProviderCallbacks_->getAccessibilityNodeCursorPosition = GetAccessibilityNodeCursorPosition;
    ret = OH_ArkUI_AccessibilityProviderRegisterCallback(provider_, accessibilityProviderCallbacks_);
    if (ret != 0) {
        return;
    }
}
```



4. When components change, proactively send events. For details, see [ArkUI_AccessibilityEventType](../reference/apis-arkui/arkui_native_interface_accessibility.md#arkui_accessibilityeventtype).

If a touch event causes a page change, send the following events: **ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_STATE_UPDATE** (page change event) and **ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_FOCUS_NODE_UPDATE** (focus position change event).

```C
// Define the DispatchTouchEventCB() function, which is triggered to respond to a touch event.
void DispatchTouchEventCB(OH_NativeXComponent *component, void *window)
{
	// ...
	// Obtain the ID of the XComponent.
	char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = { '\0' };
	uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
	if (OH_NativeXComponent_GetXComponentId(component, idStr, &idSize) != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
		OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Callback",
			"DispatchTouchEventCB: Unable to get XComponent id");
		return;
	}

    // Check whether an accessibility provider has been registered.
    if (provider_ != nullptr) {
        
        // Check whether the current touch event causes any change in the page and the position of the focused component. If changes occur, report accessibility events to notify accessibility services and applications.
        // ...
        // Specify that the component node that reports the event is node.
        // 1. Call OH_ArkUI_CreateAccessibilityEventInfo to create an ArkUI_AccessibilityEventInfo instance.
        ArkUI_AccessibilityEventInfo *eventInfo = OH_ArkUI_CreateAccessibilityEventInfo();
        if (eventInfo == nullptr) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Callback",
			"DispatchTouchEventCB: Unable to create accessibility eventInfo");
            return;
        }
        // 2. Call OH_ArkUI_CreateAccessibilityElementInfo to create an ArkUI_AccessibilityElementInfo instance.
        ArkUI_AccessibilityElementInfo *elementInfo = OH_ArkUI_CreateAccessibilityElementInfo();
        if (elementInfo == nullptr) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Callback",
			"DispatchTouchEventCB: Unable to create accessibility elementInfo");
            return;
        }
        // 3. Enter the element content.
        // Set the element member content.
    	OH_ArkUI_AccessibilityElementInfoSetElementId(element, nodes[i].id);
    	OH_ArkUI_AccessibilityElementInfoSetComponentType(element, nodes[i].type);
        // ...
        
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback",
			"DispatchTouchEventCB: send accessibility event");
        // 4. Send the page update event.
        SendAccessibilityAsyncEvent(eventInfo, elementInfo, ArkUI_AccessibilityEventType::ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_STATE_UPDATE);
        // 5. If the current processing has caused a change in the position of the focused component, send the focus position change event.
        SendAccessibilityAsyncEvent(eventInfo, elementInfo, ArkUI_AccessibilityEventType::ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_FOCUS_NODE_UPDATE);
        // 6. Destroy the memory for eventInfo and elementInfo.
        OH_ArkUI_DestoryAccessibilityElementInfo(elementInfo);
        OH_ArkUI_DestoryAccessibilityEventInfo(eventInfo);
    }
    
	std::string id(idStr);
	PluginRender *render = PluginRender::GetInstance(id);
	if (render != nullptr) {
		// Encapsulate the OnTouchEvent method.
		render->OnTouchEvent(component, window);
	}
}

void FillEvent(ArkUI_AccessibilityEventInfo *eventInfo, ArkUI_AccessibilityElementInfo *elementInfo, ArkUI_AccessibilityEventType eventType) 
{
    if (eventInfo == nullptr) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_TEXT, "eventInfo is null");
        return;
    }
    if (elementInfo == nullptr) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_TEXT, "elementInfo is null");
        return;
    }
    // 1. Set the event type.
    OH_ArkUI_AccessibilityEventSetEventType(eventInfo, eventType);
    // 2. Set the node component information for the event being sent.
    OH_ArkUI_AccessibilityEventSetElementInfo(eventInfo, elementInfo);
    
}
void SendAccessibilityAsyncEvent(ArkUI_AccessibilityEventInfo *eventInfo, ArkUI_AccessibilityElementInfo *elementInfo, ArkUI_AccessibilityEventType eventType)
{
    // 1. Enter the event content.
    FillEvent(eventInfo, elementInfo, ArkUI_AccessibilityEventType::ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_PAGE_STATE_UPDATE);
    // 2. Create a callback function to obtain the event sending result.
    auto callback = [](int32_t errorCode){
         OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "result: %{public}d", errorCode);
    }
    // 3. Call the API to send the event to the accessibility subsystem.
    OH_ArkUI_SendAccessibilityAsyncEvent(provider_, eventInfo, callback)
}
```

5. When the integration is successful, the accessibility features can be enabled.

![accessibility](./figures/accessibility-pic.png)
