# Integrating Accessibility Through Custom Drawing
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyinhua-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

For third-party framework platforms that are accessed through [custom drawing](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/arkts-user-defined-draw), the NDK provides functions for interoperability with accessibility services, enabling third-party framework components to support basic accessibility features in ArkUI. These include focus acquisition, accessibility node retrieval, and operation response.

Since API version 13, the self-drawing integration method based on **XComponent** is supported.

Since API version 23, the self-drawing integration method that builds a rendering node tree based on **CustomNode** is supported.

A third-party framework obtains the [ArkUI_AccessibilityProvider](../reference/apis-arkui/capi-arkui-accessibility-arkui-accessibilityprovider.md) from the drawing container component, adapts to the operation [Action](../reference/apis-arkui/capi-native-interface-accessibility-h.md#arkui_accessibility_actiontype) sent by the accessibility system by implementing the callback function for accessibility interconnection, and sends the accessibility event [Event](../reference/apis-arkui/capi-native-interface-accessibility-h.md#arkui_accessibilityeventtype) to the accessibility subsystem based on the component interaction behavior. In this way, the interaction experience of the accessibility application is implemented.

In the self-drawing mode based on **XComponent**, use [OH_NativeXComponent_GetNativeAccessibilityProvider](../reference/apis-arkui/capi-native-interface-xcomponent-h.md#oh_nativexcomponent_getnativeaccessibilityprovider) to obtain [ArkUI_AccessibilityProvider](../reference/apis-arkui/capi-arkui-accessibility-arkui-accessibilityprovider.md) for accessibility integration.

If you build a rendering node tree based on **CustomNode**, use [OH_ArkUI_NativeModule_GetNativeAccessibilityProvider](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_nativemodule_getnativeaccessibilityprovider) to obtain [ArkUI_AccessibilityProvider](../reference/apis-arkui/capi-arkui-accessibility-arkui-accessibilityprovider.md) for accessibility integration.

To support a single instance, use [OH_ArkUI_AccessibilityProviderRegisterCallback](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_accessibilityproviderregistercallback) to register the necessary callback function [ArkUI_AccessibilityProviderCallbacks](../reference/apis-arkui/capi-arkui-accessibility-arkui-accessibilityprovidercallbacks.md) for accessibility integration.

For multi-instance scenarios, register callback functions [ArkUI_AccessibilityProviderCallbacksWithInstance](../reference/apis-arkui/capi-arkui-accessibility-arkui-accessibilityprovidercallbackswithinstance.md) using [OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_accessibilityproviderregistercallbackwithinstance).


> **NOTE**
>
> - Accessibility capability enables you to create accessible application UIs for users with visual, auditory, motor, and cognitive disabilities.
> - When implementing query APIs ([OH_ArkUI_AccessibilityProviderRegisterCallback](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_accessibilityproviderregistercallback) or [OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_accessibilityproviderregistercallbackwithinstance)), the information of each accessibility node queried should be used to allocate element memory via [OH_ArkUI_AddAndGetAccessibilityElementInfo](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_addandgetaccessibilityelementinfo), and then added to the specified **elementList**.
> - When sending events with [OH_ArkUI_SendAccessibilityAsyncEvent](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_sendaccessibilityasyncevent), create event and element info objects using the appropriate creation functions and destroy them after use. Specifically, create an [ArkUI_AccessibilityEventInfo](../reference/apis-arkui/capi-arkui-accessibility-arkui-accessibilityeventinfo.md) object using [OH_ArkUI_CreateAccessibilityEventInfo](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_createaccessibilityeventinfo) and an [ArkUI_AccessibilityElementInfo](../reference/apis-arkui/capi-arkui-accessibility-arkui-accessibilityelementinfo.md) object using [OH_ArkUI_CreateAccessibilityElementInfo](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_createaccessibilityelementinfo), and then destroy the objects after use with [OH_ArkUI_DestoryAccessibilityEventInfo](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_destoryaccessibilityeventinfo) and [OH_ArkUI_DestoryAccessibilityElementInfo](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_destoryaccessibilityelementinfo).
> - When logging within callback functions, include the provided **requestId** parameter to link logs to a specific interaction process. This practice facilitates indexing and querying and aids in troubleshooting and pinpointing issues.

## Integrating Accessibility Through Custom Drawing Based on XComponent
This example demonstrates accessibility integration. For the complete implementation, see [AccessibilityCapiSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/AccessibilityCapi). Once integrated, third-party framework components in **XComponent** will support accessibility interactions when accessibility features are enabled.

1. Create a project based on [OH_ArkUI_SurfaceHolder for surface lifecycle management](napi-xcomponent-guidelines.md#managing-the-lifecycle-of-the-surface-held-by-xcomponent) in custom rendering (XComponent).

2. Obtain the accessibility Provider and register callbacks (the following uses the multi-instance scenario as an example).

   <!-- @[abilitycap_one_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/AccessibilityCapi/entry/src/main/cpp/manager/AccessibilityManager.cpp) -->
   
   ``` C++
   #include <arkui/native_interface_accessibility.h>
   #include <string>
   #include "common/common.h"
   // For details about the complete implementation, see AccessibilityCapiSample.
   #include "fakenode/fake_node.h"
   // For details about the complete implementation, see AccessibilityCapiSample.
   #include "AccessibilityManager.h"
   
   // ...
   AccessibilityManager::AccessibilityManager()
   {
   // Multi-instance scenario
       accessibilityProviderCallbacksWithInstance_.findAccessibilityNodeInfosById = FindAccessibilityNodeInfosById;
       accessibilityProviderCallbacksWithInstance_.findAccessibilityNodeInfosByText = FindAccessibilityNodeInfosByText;
       accessibilityProviderCallbacksWithInstance_.findFocusedAccessibilityNode = FindFocusedAccessibilityNode;
       accessibilityProviderCallbacksWithInstance_.findNextFocusAccessibilityNode = FindNextFocusAccessibilityNode;
       accessibilityProviderCallbacksWithInstance_.executeAccessibilityAction = ExecuteAccessibilityAction;
       accessibilityProviderCallbacksWithInstance_.clearFocusedFocusAccessibilityNode = ClearFocusedFocusAccessibilityNode;
       accessibilityProviderCallbacksWithInstance_.getAccessibilityNodeCursorPosition = GetAccessibilityNodeCursorPosition;
   // Single-instance scenario
       accessibilityProviderCallbacks_.findAccessibilityNodeInfosById = FindAccessibilityNodeInfosById;
       accessibilityProviderCallbacks_.findAccessibilityNodeInfosByText = FindAccessibilityNodeInfosByText;
       accessibilityProviderCallbacks_.findFocusedAccessibilityNode = FindFocusedAccessibilityNode;
       accessibilityProviderCallbacks_.findNextFocusAccessibilityNode = FindNextFocusAccessibilityNode;
       accessibilityProviderCallbacks_.executeAccessibilityAction = ExecuteAccessibilityAction;
       accessibilityProviderCallbacks_.clearFocusedFocusAccessibilityNode = ClearFocusedFocusAccessibilityNode;
       accessibilityProviderCallbacks_.getAccessibilityNodeCursorPosition = GetAccessibilityNodeCursorPosition;
   }
   
   void AccessibilityManager::Initialize(const std::string &id, OH_NativeXComponent *nativeXComponent)
   {
       int32_t ret = OH_NativeXComponent_GetNativeAccessibilityProvider(nativeXComponent, &provider);
       if (provider == nullptr) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "get provider is null");
           return;
       }
       // 2. Register callbacks.
       ret = OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance(id.c_str(), provider,
           &accessibilityProviderCallbacksWithInstance_);
       if (ret != 0) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT,
                        "OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance failed");
           return;
       }
       g_provider = provider;
   }
   
   // ...
   ```

3. Third-party frameworks must implement the following callbacks:

- Find the information about an accessibility node based on the specified node ID.
  > **NOTE**
  >
  > - When the element ID passed by the accessibility system is **-1**, it represents the root node ID. The third-party framework must map this external ID to the ID of the unique root node in its internal node tree so that the accessibility system can correctly locate the root node of the framework.
  > - The third-party framework must provide only one root node.
  > - The [parentId](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_accessibilityelementinfosetparentid) attribute of the root node must be set to the special value **-2100000**. In the accessibility tree, the root node is the topmost node and does not have a parent element. The special value **-2100000** is hardcoded in the ArkUI accessibility framework and is used to explicitly indicate that "this node is the root node and has no parent." Using a special value instead of **0** or **-1** is to prevent conflicts with valid IDs within the third-party framework and ensure that the system can accurately identify the root node.
  > - The [enabled](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_accessibilityelementinfosetenabled) attribute of the root node must be set to **true**. If this attribute is set to **false**, the root node is disabled. In this case, the accessibility system considers the entire component tree non-interactive and ignores the queries and operations on all child nodes. As the entry point to the entire control tree, the root node must be enabled to ensure proper accessibility service functionality.
  > - The [visible](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_accessibilityelementinfosetvisible) attribute of the root node must be set to **true**. The accessibility system only traverses and interacts with visible nodes. If this attribute is set to **false**, the root node becomes invisible, and the entire component tree will be ignored by the accessibility service. As a result, the accessibility capabilities of the third-party framework become completely ineffective. This ensures that users can perceive all UI elements rendered by the third‑party framework when using accessibility features.

   <!-- @[abilitycap_two_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/AccessibilityCapi/entry/src/main/cpp/manager/AccessibilityManager.cpp) -->
   
   ``` C++
   int32_t AccessibilityManager::FindAccessibilityNodeInfosById(const char* instanceId, int64_t elementId,
       ArkUI_AccessibilitySearchMode mode, int32_t requestId, ArkUI_AccessibilityElementInfoList *elementList)
   {
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT,
                    "FindAccessibilityNodeInfosById start,instanceId %{public}s elementId: %{public}ld, "
                    "requestId: %{public}d, mode: %{public}d", instanceId,
                    elementId, requestId, static_cast<int32_t>(mode));
       if (elementList == nullptr) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT,
                        "FindAccessibilityNodeInfosById elementList is null");
           return OH_NATIVEXCOMPONENT_RESULT_FAILED;
       }
       int ret = 0;
       const int parentOfRoot = -2100000;
       if (elementId == -1) {
           elementId = 0;
       }
       
       if (mode == ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_RECURSIVE_CHILDREN) {
           // Third-party frameworks must implement custom search logic in this method and return accessibility node information to the accessibility service. The following implementation serves as a reference example only.
           // Special constant defined for ArkUI framework compatibility. Root node parent ID must be set to this specific value.
           auto rootNode = OH_ArkUI_AddAndGetAccessibilityElementInfo(elementList);
           if (!rootNode) {
               return OH_NATIVEXCOMPONENT_RESULT_FAILED;
           }
           // Set the root node information.
           OH_ArkUI_AccessibilityElementInfoSetElementId(rootNode, 0);
           OH_ArkUI_AccessibilityElementInfoSetParentId(rootNode, parentOfRoot);
           OH_ArkUI_AccessibilityElementInfoSetEnabled(rootNode, true);
           OH_ArkUI_AccessibilityElementInfoSetVisible(rootNode, true);
           FakeWidget::Instance().fillAccessibilityElement(rootNode);
   
           ArkUI_AccessibleRect rect;
           rect.leftTopX = NUMBER_ZERO;
           rect.leftTopY = NUMBER_ZERO;
           rect.rightBottomX = NUMBER_THIRD;
           rect.rightBottomY = NUMBER_THIRD;
           ret = OH_ArkUI_AccessibilityElementInfoSetScreenRect(rootNode, &rect);
           // Set the root node to be ignored by accessibility services.
           OH_ArkUI_AccessibilityElementInfoSetAccessibilityLevel(rootNode, "no");
           auto objects = FakeWidget::Instance().GetAllObjects(instanceId);
           int64_t childNodes[1024];
           for (int i = 0; i < objects.size(); i++) {
               int elementId = i + 1;
               childNodes[i] = elementId;
               auto child = OH_ArkUI_AddAndGetAccessibilityElementInfo(elementList);
               // Set the child node information.
               OH_ArkUI_AccessibilityElementInfoSetElementId(child, elementId);
               OH_ArkUI_AccessibilityElementInfoSetParentId(child, 0);
               // Set the current component to be accessible to accessibility services.
               OH_ArkUI_AccessibilityElementInfoSetAccessibilityLevel(child, "yes");
               objects[i]->fillAccessibilityElement(child);
   
               ArkUI_AccessibleRect rect;
               rect.leftTopX = i * NUMBER_FIRST;
               rect.leftTopY = NUMBER_FIRST;
               rect.rightBottomX = i * NUMBER_FIRST + NUMBER_FIRST;
               rect.rightBottomY = NUMBER_SECOND;
               OH_ArkUI_AccessibilityElementInfoSetScreenRect(child, &rect);
               if (objects[i]->ObjectType() == "FakeSlider") {
                   auto rangeInfo = objects[i]->GetRangeInfo();
                   OH_ArkUI_AccessibilityElementInfoSetRangeInfo(child, &rangeInfo);
               }
               if (objects[i]->ObjectType() == "FakeList") {
                   auto gridInfo = objects[i]->GetGridInfo();
                   OH_ArkUI_AccessibilityElementInfoSetGridInfo(child, &gridInfo);
               }
               if (objects[i]->ObjectType() == "FakeSwiper") {
                   auto gridItemInfo = objects[i]->GetGridItemInfo();
                   OH_ArkUI_AccessibilityElementInfoSetGridItemInfo(child, &gridItemInfo);
               }
           }
   
           ret = OH_ArkUI_AccessibilityElementInfoSetChildNodeIds(rootNode, objects.size(), childNodes);
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT,
                        "FindAccessibilityNodeInfosById child count: %{public}ld %{public}d",
                        objects.size(), ret);
       } else if (mode == ARKUI_ACCESSIBILITY_NATIVE_SEARCH_MODE_PREFETCH_CURRENT) {
           auto &widget = FakeWidget::Instance();
           AccessibleObject *obj = nullptr;
           if (elementId == 0) {
               obj = &widget;
           } else {
               obj = widget.GetChild(elementId);
           }
           if (!obj) {
               return OH_NATIVEXCOMPONENT_RESULT_FAILED;
           }
           auto node = OH_ArkUI_AddAndGetAccessibilityElementInfo(elementList);
           OH_ArkUI_AccessibilityElementInfoSetElementId(node, elementId);
           OH_ArkUI_AccessibilityElementInfoSetParentId(node, elementId == 0 ? parentOfRoot : 0);
           OH_ArkUI_AccessibilityElementInfoSetAccessibilityLevel(node, elementId == 0 ?  "no" : "yes");
           obj->fillAccessibilityElement(node);
           ArkUI_AccessibleRect rect;
           if (elementId == 0) {
               rect.leftTopX = NUMBER_ZERO;
               rect.leftTopY = NUMBER_ZERO;
               rect.rightBottomX = NUMBER_THIRD;
               rect.rightBottomY = NUMBER_THIRD;
           } else {
               int i = elementId - 1;
               rect.leftTopX = i * NUMBER_FIRST;
               rect.leftTopY = NUMBER_FIRST;
               rect.rightBottomX = i * NUMBER_FIRST + NUMBER_FIRST;
               rect.rightBottomY = NUMBER_SECOND;
           }
   
           OH_ArkUI_AccessibilityElementInfoSetScreenRect(node, &rect);
           if (elementId == 0) {
               auto objects = FakeWidget::Instance().GetAllObjects(instanceId);
               int64_t childNodes[1024];
   
               for (int i = 0; i < objects.size(); i++) {
                   int elementId = i + 1;
   
                   childNodes[i] = elementId;
                   auto child = OH_ArkUI_AddAndGetAccessibilityElementInfo(elementList);
                   OH_ArkUI_AccessibilityElementInfoSetElementId(child, elementId);
                   OH_ArkUI_AccessibilityElementInfoSetParentId(child, 0);
   
                   objects[i]->fillAccessibilityElement(child);
   
                   ArkUI_AccessibleRect rect;
                   rect.leftTopX = i * NUMBER_FIRST;
                   rect.leftTopY = NUMBER_ZERO;
                   rect.rightBottomX = i * NUMBER_FIRST + NUMBER_FIRST;
                   rect.rightBottomY = NUMBER_SECOND;
                   OH_ArkUI_AccessibilityElementInfoSetScreenRect(child, &rect);
               }
               ret = OH_ArkUI_AccessibilityElementInfoSetChildNodeIds(node, objects.size(), childNodes);
               OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT,
                            "FindAccessibilityNodeInfosById child2 count: %{public}ld", objects.size());
           }
       }
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "FindAccessibilityNodeInfosById end");
       return OH_NATIVEXCOMPONENT_RESULT_SUCCESS;
   }
   ```

- Queries the next focusable accessibility node based on the specified node.

   <!-- @[abilitycap_three_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/AccessibilityCapi/entry/src/main/cpp/manager/AccessibilityManager.cpp) -->
   
   ``` C++
   int32_t AccessibilityManager::FindNextFocusAccessibilityNode(const char* instanceId, int64_t elementId,
       ArkUI_AccessibilityFocusMoveDirection direction, int32_t requestId,
       ArkUI_AccessibilityElementInfo *elementInfo)
   {
       // Search for the next focusable accessibility node. The third-party framework needs to implement its own search policy in this method. The following logic is only an example.
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT,
                    "FindNextFocusAccessibilityNode instanceId %{public}s "
                    "elementId: %{public}ld, requestId: %{public}d, direction: %{public}d",
                    instanceId, elementId, requestId, static_cast<int32_t>(direction));
       auto objects = FakeWidget::Instance().GetAllObjects(instanceId);
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "objects.size() %{public}d", objects.size());
       // object.size does not contain the root node.
       if ((elementId < 0) || (elementId > objects.size())) {
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "elementId invalid");
           return OH_NATIVEXCOMPONENT_RESULT_FAILED;
       }
       int64_t nextElementId = -1;
       if (direction == ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_FORWARD) {
           nextElementId = elementId + 1;
       } else {
           nextElementId = elementId - 1;
       }
       
       // Screen reader constraint: If it is the root node and navigating backward, return to the last node.
       if ((nextElementId == -1) && (direction == ARKUI_ACCESSIBILITY_NATIVE_DIRECTION_BACKWARD)) {
           nextElementId = objects.size();
       }
       
       if (nextElementId >  objects.size()) {
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "nextElementId invalid");
           return OH_NATIVEXCOMPONENT_RESULT_FAILED;
       }
       
       if (nextElementId <=  0) {
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "nextElementId less than zero");
           return OH_NATIVEXCOMPONENT_RESULT_FAILED;
       }
       OH_ArkUI_AccessibilityElementInfoSetElementId(elementInfo, nextElementId);
       OH_ArkUI_AccessibilityElementInfoSetParentId(elementInfo, 0);
       // The ID is 1 greater than the object index.
       objects[nextElementId - 1]->fillAccessibilityElement(elementInfo);
       ArkUI_AccessibleRect rect;
       rect.leftTopX = nextElementId * NUMBER_FIRST;
       rect.leftTopY = NUMBER_ZERO;
       rect.rightBottomX = nextElementId * NUMBER_FIRST + NUMBER_FIRST;
       rect.rightBottomY = NUMBER_SECOND;
       OH_ArkUI_AccessibilityElementInfoSetScreenRect(elementInfo, &rect);
       auto eventInfo = OH_ArkUI_CreateAccessibilityEventInfo();
       OH_ArkUI_AccessibilityEventSetRequestFocusId(eventInfo, nextElementId);
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "%{public}ld", nextElementId);
       // This function is used only to create event information and does not send the event. If the event does not need to be sent, call **OH_ArkUI_DestoryAccessibilityEventInfo**.
       // Release the memory. If you need to send an event, call OH_ArkUI_SendAccessibilityAsyncEvent and release the memory in the callback.
       OH_ArkUI_DestoryAccessibilityEventInfo(eventInfo);
       return OH_NATIVEXCOMPONENT_RESULT_SUCCESS;
   }
   ```

- Find the node information matching the specified text content based on the specified node.

   <!-- @[abilitycap_four_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/AccessibilityCapi/entry/src/main/cpp/manager/AccessibilityManager.cpp) -->
   
   ``` C++
   int32_t AccessibilityManager::FindAccessibilityNodeInfosByText(const char* instanceId, int64_t elementId,
       const char *text, int32_t requestId, ArkUI_AccessibilityElementInfoList *elementList)
   {
       // Third-party frameworks need to implement the logic for querying accessibility nodes based on text content.
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT,
                    "FindAccessibilityNodeInfosByText start,instanceId %{public}s elementId: %{public}ld, "
                    "requestId: %{public}d, text: %{public}s.", instanceId,
                    elementId, requestId, text);
       return OH_NATIVEXCOMPONENT_RESULT_SUCCESS;
   }
   ```

- Find the information about the focused node based on the specified node ID.

   <!-- @[abilitycap_five_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/AccessibilityCapi/entry/src/main/cpp/manager/AccessibilityManager.cpp) -->
   
   ``` C++
   int32_t AccessibilityManager::FindFocusedAccessibilityNode(const char* instanceId, int64_t elementId,
       ArkUI_AccessibilityFocusType focusType, int32_t requestId, ArkUI_AccessibilityElementInfo *elementInfo)
   {
       // Third-party frameworks need to implement the logic for obtaining the focus element information based on a specified node.
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT,
                    "FindFocusedAccessibilityNode start instanceId %{public}s, "
                    "elementId: %{public}ld, requestId: %{public}d, focusType: %{public}d",
                    instanceId, elementId, requestId, static_cast<int32_t>(focusType));
       return OH_NATIVEXCOMPONENT_RESULT_SUCCESS;
   }
   ```

- Perform a specified action on the specified node.

   <!-- @[abilitycap_six_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/AccessibilityCapi/entry/src/main/cpp/manager/AccessibilityManager.cpp) -->
   
   ``` C++
   void FillEvent(ArkUI_AccessibilityEventInfo *eventInfo, ArkUI_AccessibilityElementInfo *elementInfo,
                  ArkUI_AccessibilityEventType eventType, std::string announcedText)
   {
       if (eventInfo == nullptr) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "FillEvent eventInfo is nullptr");
           return;
       }
       if (elementInfo == nullptr) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "FillEvent elementInfo is nullptr");
           return;
       }
       // Set the event type.
       OH_ArkUI_AccessibilityEventSetEventType(eventInfo, eventType);
       // Set the element information corresponding to the event.
       OH_ArkUI_AccessibilityEventSetElementInfo(eventInfo, elementInfo);
       
       if (eventType == ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ANNOUNCE_FOR_ACCESSIBILITY && announcedText.size() > 0) {
           // Set the prioritized accessibility text for the accessibility node.
           // The Set API is called in synchronous mode and copies the text. announcedText is a local object passed by value, whose lifetime covers this call, so it is safe to pass data() directly.
           OH_ArkUI_AccessibilityEventSetTextAnnouncedForAccessibility(eventInfo, announcedText.data());
       }
   }
   
   // ...
   
   void AccessibilityManager::SendAccessibilityAsyncEvent(ArkUI_AccessibilityElementInfo *elementInfo,
                                                          ArkUI_AccessibilityEventType eventType,
                                                          std::string announcedText)
   {
       auto eventInfo = OH_ArkUI_CreateAccessibilityEventInfo();
       // 1. Enter the event content.
       FillEvent(eventInfo, elementInfo, eventType, announcedText);
       // 2. Callback
       auto callback = [](int32_t errorCode) {
           OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT, "result: %{public}d", errorCode);
       };
       // 3. Call the API to send the event to the OpenHarmony side.
       OH_ArkUI_SendAccessibilityAsyncEvent(g_provider, eventInfo, callback);
       // Release the memory of eventInfo after the event is sent.
       OH_ArkUI_DestoryAccessibilityEventInfo(eventInfo);
   }
   // ...
   
   int32_t AccessibilityManager::ExecuteAccessibilityAction(const char* instanceId, int64_t elementId,
       ArkUI_Accessibility_ActionType action, ArkUI_AccessibilityActionArguments *actionArguments, int32_t requestId)
   {
       // The third-party framework needs to implement the logic for executing the accessibility node behavior.
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT,
                    "ExecuteAccessibilityAction instanceId %{public}s elementId: %{public}ld, "
                    "action: %{public}d, requestId: %{public}d",
                    instanceId, elementId, action, requestId);
       auto object = FakeWidget::Instance().GetChild(elementId);
       // The passed accessibility node object may be null. A null check is required.
       if (!object) {
           return 0;
       }
       // Obtain the accessibility node element.
       auto announcedText = object->GetAnnouncedForAccessibility();
       auto element = OH_ArkUI_CreateAccessibilityElementInfo();
       OH_ArkUI_AccessibilityElementInfoSetElementId(element, elementId);
       const char *actionKey = "some_key";
       char *actionValue = nullptr;
       OH_ArkUI_FindAccessibilityActionArgumentByKey(actionArguments, actionKey, &actionValue);
       // Execute the corresponding logic based on actionValue, or remove the query code that is not used.
       // Execute the corresponding behavior based on the action type.
       switch (action) {
           case ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLICK:
               object->OnClick();
               object->fillAccessibilityElement(element);
               // Send the specified event to the accessibility service.
               AccessibilityManager::SendAccessibilityAsyncEvent(element,
                   ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_CLICKED, announcedText);
               break;
           case ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_GAIN_ACCESSIBILITY_FOCUS:
               object->SetFocus(true);
   
               object->fillAccessibilityElement(element);
               // Send the specified event to the accessibility service.
               AccessibilityManager::SendAccessibilityAsyncEvent(element,
                   ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ACCESSIBILITY_FOCUSED,
                   announcedText);
               break;
           case ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_CLEAR_ACCESSIBILITY_FOCUS:
               object->SetFocus(false);
               object->fillAccessibilityElement(element);
               AccessibilityManager::SendAccessibilityAsyncEvent(
                   element, ARKUI_ACCESSIBILITY_NATIVE_EVENT_TYPE_ACCESSIBILITY_FOCUS_CLEARED,
                   announcedText);
               break;
           default:
               // Handle unsupported action types.
               break;
       }
       OH_ArkUI_DestoryAccessibilityElementInfo(element);
       return OH_NATIVEXCOMPONENT_RESULT_SUCCESS;
   }
   ```

- Remove focus from the node.

   <!-- @[abilitycap_seven_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/AccessibilityCapi/entry/src/main/cpp/manager/AccessibilityManager.cpp) -->
   
   ``` C++
   int32_t AccessibilityManager::ClearFocusedFocusAccessibilityNode(const char* instanceId)
   {
       // Third-party frameworks need to implement the logic for clearing the currently focused node.
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT,
                    "ClearFocusedFocusAccessibilityNode, instanceId %{public}s", instanceId);
       return OH_NATIVEXCOMPONENT_RESULT_SUCCESS;
   }
   ```

- Obtain the cursor position of the current text component based on the specified node.

   <!-- @[abilitycap_eight_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/AccessibilityCapi/entry/src/main/cpp/manager/AccessibilityManager.cpp) -->
   
   ``` C++
   int32_t AccessibilityManager::GetAccessibilityNodeCursorPosition(const char* instanceId, int64_t elementId,
       int32_t requestId, int32_t *index)
   {
       // Third-party frameworks need to implement the logic for obtaining the cursor position within the current text component.
       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, LOG_PRINT_TEXT,
                    "GetAccessibilityNodeCursorPosition, instanceId %{public}s "
                    "elementId: %{public}ld, requestId: %{public}d, index: %{public}d",
                    instanceId, elementId, requestId, *index);
       return OH_NATIVEXCOMPONENT_RESULT_SUCCESS;
   }
   ```

After the provider is successfully connected using the [OH_ArkUI_AccessibilityProviderRegisterCallback](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_accessibilityproviderregistercallback) or [OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance](../reference/apis-arkui/capi-native-interface-accessibility-h.md#oh_arkui_accessibilityproviderregistercallbackwithinstance) callback, the accessibility function can be enabled.

## Integrating Accessibility Through Custom Drawing Based on CustomNode

> **NOTE**
>
> - The custom drawing container component based on **CustomNode** only supports [ArkUI_Node](../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md) whose type is [ARKUI_NODE_CUSTOM](../reference/apis-arkui/capi-native-node-h.md#arkui_nodetype) and that have no other child nodes. The width and height of the drawing container component must not be **0**, to avoid being ignored by accessibility applications or causing incorrect handling of the child node tree.

This example demonstrates accessibility integration. For the complete implementation, see [AccessibilityCustomCapi](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/AccessibilityCustomCapi). For details about how to implement a callback, see [Integrating Accessibility Through Custom Drawing Based on XComponent](#integrating-accessibility-through-custom-drawing-based-on-xcomponent). After implementing the callback, enable the accessibility function. The third-party framework that builds the rendering node tree based on **CustomNode** can then integrate with the accessibility service to implement accessibility interaction and information query for the component tree.

1. Create a pre-integration project by referring to [Building a Rendering Node Based on CustomNode](ndk-embed-render-components.md).

2. Obtain the accessibility integration **Provider** instance, bind the callback to the **Provider** instance, and complete the registration.

    <!-- @[abilitycap_nine_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/AccessibilityCustomCapi/entry/src/main/cpp/AccessibilityMaker.cpp) -->
    
    ``` C++
    int32_t AccessibilityMaker::GetAccessibilityProvider(ArkUI_NodeHandle* customNode, const char* id)
    {
        AccessibilityMaker::accessibilityProviderCallbacksWithInstance_.findAccessibilityNodeInfosById =
            FindAccessibilityNodeInfosById;
        AccessibilityMaker::accessibilityProviderCallbacksWithInstance_.findAccessibilityNodeInfosByText =
            FindAccessibilityNodeInfosByText;
        AccessibilityMaker::accessibilityProviderCallbacksWithInstance_.findFocusedAccessibilityNode =
            FindFocusedAccessibilityNode;
        AccessibilityMaker::accessibilityProviderCallbacksWithInstance_.findNextFocusAccessibilityNode =
            FindNextFocusAccessibilityNode;
        AccessibilityMaker::accessibilityProviderCallbacksWithInstance_.executeAccessibilityAction =
            ExecuteAccessibilityAction;
        AccessibilityMaker::accessibilityProviderCallbacksWithInstance_.clearFocusedFocusAccessibilityNode =
            ClearFocusedFocusAccessibilityNode;
        AccessibilityMaker::accessibilityProviderCallbacksWithInstance_.getAccessibilityNodeCursorPosition =
            GetAccessibilityNodeCursorPosition;
    
        // Obtain the accessibility provider provided by the native layer and register the callback.
        OH_ArkUI_NativeModule_GetNativeAccessibilityProvider(customNode, &accessibilityProvider_);
        if (accessibilityProvider_ == nullptr) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "AccessibilityMaker", "accessibilityProvider_ is null");
            return -1;
        }
    
        int32_t ret = OH_ArkUI_AccessibilityProviderRegisterCallbackWithInstance(id, accessibilityProvider_,
            &AccessibilityMaker::accessibilityProviderCallbacksWithInstance_);
        if (ret != 0) {
            return ret;
        }
        return 0;
    }
    ```

3. A third-party framework must implement the callback. For details, see [Integrating Accessibility Through Custom Drawing Based on XComponent](#integrating-accessibility-through-custom-drawing-based-on-xcomponent).
