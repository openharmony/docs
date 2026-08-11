# Adding an Event Listener

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=39f66a31c4cd77f8015af575d95ace022de7992b translatedAt=2026-08-05T01:26:37.868Z pushedAt=2026-08-05T06:07:31.459Z -->

NDK APIs provide the event listening capability for components. This section describes how to listen for component events, layout and drawing events, and light/dark mode change events.

## Listening for Component Events

NDK APIs can listen for the status changes of UI components and user interaction events.

First, you can use the [addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver) function to add an event listener for the component, which will listen for all events that occur on that component, such as click events and focus events. Then, use the [registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent) function to declare the events that the component needs to listen for. For details about the events supported by the NDK API, see [ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype).

> **NOTE**
>
> - Event registration requires the declaration of [addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver) listener registration and [registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent) event types. The listener can only listen for declared events.
>
> - Pay attention to the logic of event deregistration. For example, before the component is destroyed, call [removeNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removenodeeventreceiver) to remove the event listener and [unregisterNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodeevent) to notify the ArkUI framework that the listened events no longer need to be listened for.
>
> - [addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver) can add multiple function pointers, each of which is triggered when the corresponding event occurs. To remove a listener, the corresponding [removeNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removenodeeventreceiver) function must be called with the exact function pointer used for adding the listener.
>
> - [registerNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeeventreceiver) is a global event listener function. Unlike [addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver), [registerNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeeventreceiver) can listen for the event triggers of all native components, but it can only accept a single function pointer. If it is called multiple times, only the last function pointer provided will be used for callbacks. To release the listener, use the [unregisterNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodeeventreceiver) function.

The following examples are based on [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md). For details, see [Sample Code](#sample-code).

### Listening for Node Events

Bind event handlers to nodes using **addNodeEventReceiver**, and then register specific event listeners via **registerNodeEvent**.

Define a pointer of type [ArkUI_NativeNodeAPI_1](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md):

<!-- @[define_node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Common.h) -->

``` C
ArkUI_NativeNodeAPI_1 *nodeAPI = nullptr;
```

Call the [OH_ArkUI_GetModuleInterface](../reference/apis-arkui/capi-native-interface-h.md#oh_arkui_getmoduleinterface) API to assign a value to the defined pointer:

<!-- @[get_module_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/NativeEntry.cpp) -->

``` C++
OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nodeAPI);
```

Define an event trigger callback:

<!-- @[node_event_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
void NodeEventReceiver(ArkUI_NodeEvent *event) {
  // Handle specific event types, such as NODE_ON_CLICK_EVENT.
};
```

Create a node, bind the event trigger callback to the node, and register the event for the node:

<!-- @[create_and_register_node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
auto button = nodeAPI->createNode(ARKUI_NODE_BUTTON);
nodeAPI->addNodeEventReceiver(button, NodeEventReceiver);
nodeAPI->registerNodeEvent(button, NODE_ON_CLICK_EVENT, 0, nullptr);
```

For details about event types, see [ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype).

Deregister events using **unregisterNodeEvent** and remove handlers with **removeNodeEventReceiver**.

Unregister the specified event type for the node:

<!-- @[unregister_node_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
nodeAPI->unregisterNodeEvent(button, NODE_ON_CLICK_EVENT);
```

Remove the event handler:

<!-- @[remove_node_event_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
nodeAPI->removeNodeEventReceiver(button, NodeEventReceiver);
```

### Listening for Global Events

Register a global event handler via **registerNodeEventReceiver** for centralized event listening. Release it via **unregisterNodeEventReceiver** when it is no longer needed.

Register a global event handler:

<!-- @[register_global_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
nodeAPI->registerNodeEventReceiver([](ArkUI_NodeEvent *event) {
    // Obtain the basic event object from the component event.
    auto *inputEvent = OH_ArkUI_NodeEvent_GetInputEvent(event);
    // Obtain the event type from the component event.
    auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
    // ...
    switch (eventType) {
        case NODE_ON_CLICK_EVENT: {
            // Perform operations when the click event is triggered. Obtain event information from the base input event.
            // ...
        }
        default: {
            break;
        }
    }
});
```

Unregister the registered global event handler:

<!-- @[unregister_node_event_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
nodeAPI->unregisterNodeEventReceiver();
```

### Sample Code

1. Encapsulate methods for event registration and listener calling in the ArkUINode base class object.

   <!-- @[arkui_node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/ArkUINode.h) -->

   ``` C
   // ArkUINode.h
   // Provide encapsulation of universal attributes and events.
   
   #ifndef MYAPPLICATION_ARKUINODE_H
   #define MYAPPLICATION_ARKUINODE_H
   
   #include "ArkUIBaseNode.h"
   #include "NativeModule.h"
   
   #include <arkui/native_node.h>
   #include <arkui/native_type.h>
   
   namespace NativeModule {
   
   class ArkUINode : public ArkUIBaseNode {
   public:
       explicit ArkUINode(ArkUI_NodeHandle handle) : ArkUIBaseNode(handle)
       {
           nativeModule_ = NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
           // When an event is triggered, you need to get the corresponding event object through a function. Here, by setting the node's custom data, the encapsulated class pointer is kept on the component for subsequent event distribution.
           nativeModule_->setUserData(handle_, this);
           // Register the node event receiver.
           nativeModule_->addNodeEventReceiver(handle_, ArkUINode::NodeEventReceiver);
       }
   
       ~ArkUINode() override
       {
           if (onClick_) {
               nativeModule_->unregisterNodeEvent(handle_, NODE_ON_CLICK_EVENT);
           }
           if (onTouch_) {
               nativeModule_->unregisterNodeEvent(handle_, NODE_TOUCH_EVENT);
           }
           if (onDisappear_) {
               nativeModule_->unregisterNodeEvent(handle_, NODE_EVENT_ON_DISAPPEAR);
           }
           if (onAppear_) {
               nativeModule_->unregisterNodeEvent(handle_, NODE_EVENT_ON_APPEAR);
           }
           nativeModule_->removeNodeEventReceiver(handle_, ArkUINode::NodeEventReceiver);
       }
       // Set the node brightness.
       void SetWidth(float width)
       {
           if (!handle_) {
               return;
           }
           ArkUI_NumberValue value[] = {{.f32 = width}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_WIDTH, &item);
       }
       // Set the node width (in percentage).
       void SetPercentWidth(float percent)
       {
           if (!handle_) {
               return;
           }
           ArkUI_NumberValue value[] = {{.f32 = percent}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_WIDTH_PERCENT, &item);
       }
       // Set the node height.
       void SetHeight(float height)
       {
           if (!handle_) {
               return;
           }
           ArkUI_NumberValue value[] = {{.f32 = height}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_HEIGHT, &item);
       }
       // Set the node height (in percentage).
       void SetPercentHeight(float percent)
       {
           if (!handle_) {
               return;
           }
           ArkUI_NumberValue value[] = {{.f32 = percent}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_HEIGHT_PERCENT, &item);
       }
       // Set the background color of the node.
       void SetBackgroundColor(uint32_t color)
       {
           if (!handle_) {
               return;
           }
           ArkUI_NumberValue value[] = {{.u32 = color}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_BACKGROUND_COLOR, &item);
       }
       // Process common events.
       void RegisterOnClick(const std::function<void(ArkUI_NodeEvent *event)> &onClick)
       {
           if (!handle_) {
               return;
           }
           onClick_ = onClick;
           // Register the click event.
           nativeModule_->registerNodeEvent(handle_, NODE_ON_CLICK_EVENT, 0, nullptr);
       }
   
       void RegisterOnTouch(const std::function<void(int32_t type, float x, float y)> &onTouch)
       {
           if (!handle_) {
               return;
           }
           onTouch_ = onTouch;
           // Register the touch event.
           nativeModule_->registerNodeEvent(handle_, NODE_TOUCH_EVENT, 0, nullptr);
       }
   
       void RegisterOnDisappear(const std::function<void()> &onDisappear)
       {
           if (!handle_) {
               return;
           }
           onDisappear_ = onDisappear;
           // Register the disappear event.
           nativeModule_->registerNodeEvent(handle_, NODE_EVENT_ON_DISAPPEAR, 0, nullptr);
       }
   
       void RegisterOnAppear(const std::function<void()> &onAppear)
       {
           if (!handle_) {
               return;
           }
           onAppear_ = onAppear;
           // Register the appear event.
           nativeModule_->registerNodeEvent(handle_, NODE_EVENT_ON_APPEAR, 0, nullptr);
       }
   
   protected:
       // Event listener function pointer.
       static void NodeEventReceiver(ArkUI_NodeEvent *event)
       {
           // Obtain the UI component object where the event occurs.
           auto nodeHandle = OH_ArkUI_NodeEvent_GetNodeHandle(event);
           // Obtain the custom data kept in the UI component object, and return the encapsulated class pointer.
           auto *node = reinterpret_cast<ArkUINode *>(
               NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->getUserData(nodeHandle));
           // Process the event based on the encapsulated class instance object.
           node->ProcessNodeEvent(event);
       }
       void ProcessNodeEvent(ArkUI_NodeEvent *event)
       {
           auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
           switch (eventType) {
               case NODE_ON_CLICK_EVENT: {
                   if (onClick_) {
                       onClick_(event);
                   }
                   break;
               }
               case NODE_TOUCH_EVENT: {
                   if (onTouch_) {
                       auto *uiInputEvent = OH_ArkUI_NodeEvent_GetInputEvent(event);
                       float x = OH_ArkUI_PointerEvent_GetX(uiInputEvent);
                       float y = OH_ArkUI_PointerEvent_GetY(uiInputEvent);
                       auto type = OH_ArkUI_UIInputEvent_GetAction(uiInputEvent);
                       onTouch_(type, x, y);
                   }
               }
               case NODE_EVENT_ON_DISAPPEAR: {
                   if (onDisappear_) {
                       onDisappear_();
                   }
                   break;
               }
               case NODE_EVENT_ON_APPEAR: {
                   if (onAppear_) {
                       onAppear_();
                   }
                   break;
               }
               default: {
                   // Component-specific events are processed by child classes.
                   OnNodeEvent(event);
               }
           }
       }
   
       virtual void OnNodeEvent(ArkUI_NodeEvent *event) {}
   
       void OnAddChild(const std::shared_ptr<ArkUIBaseNode> &child) override
       {
           nativeModule_->addChild(handle_, child->GetHandle());
       }
   
       void OnRemoveChild(const std::shared_ptr<ArkUIBaseNode> &child) override
       {
           nativeModule_->removeChild(handle_, child->GetHandle());
       }
   
       void OnInsertChild(const std::shared_ptr<ArkUIBaseNode> &child, int32_t index) override
       {
           nativeModule_->insertChildAt(handle_, child->GetHandle(), index);
       }
   
   private:
       std::function<void(ArkUI_NodeEvent *event)> onClick_;
       std::function<void()> onDisappear_;
       std::function<void()> onAppear_;
       std::function<void(int32_t type, float x, float y)> onTouch_;
   };
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUINODE_H
   ```

2. Register the list event [NODE_LIST_ON_SCROLL_INDEX](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) in the **ArkUIListNode** object.

   <!-- @[arkui_list_node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/ArkUIListNode.h) -->

   ``` C
   // ArkUIListNode.h
   // List encapsulation class object
   
   #ifndef MYAPPLICATION_ARKUILISTNODE_H
   #define MYAPPLICATION_ARKUILISTNODE_H
   
   #include "ArkUINode.h"
   
   namespace NativeModule {
   class ArkUIListNode : public ArkUINode {
   public:
       ArkUIListNode()
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_LIST)) {}
   
       ~ArkUIListNode() override { nativeModule_->unregisterNodeEvent(handle_, NODE_LIST_ON_SCROLL_INDEX); }
   
       void SetScrollBarState(bool isShow)
       {
           if (!handle_) {
               return;
           }
           ArkUI_ScrollBarDisplayMode displayMode =
               isShow ? ARKUI_SCROLL_BAR_DISPLAY_MODE_ON : ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF;
           ArkUI_NumberValue value[] = {{.i32 = displayMode}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_SCROLL_BAR_DISPLAY_MODE, &item);
       }
   
       // Register list-related events.
       void RegisterOnScrollIndex(const std::function<void(int32_t index)> &onScrollIndex)
       {
           if (!handle_) {
               return;
           }
           onScrollIndex_ = onScrollIndex;
           nativeModule_->registerNodeEvent(handle_, NODE_LIST_ON_SCROLL_INDEX, 0, nullptr);
       }
   
   protected:
      // Process list-related events.
       void OnNodeEvent(ArkUI_NodeEvent *event) override
       {
           auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
           switch (eventType) {
               case NODE_LIST_ON_SCROLL_INDEX: {
                   auto index = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event)->data[0];
                   if (onScrollIndex_) {
                       onScrollIndex_(index.i32);
                   }
               }
               default: {
               }
           }
       }
   
   private:
       std::function<void(int32_t index)> onScrollIndex_;
   };
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUILISTNODE_H
   ```

3. Add an event listener to the text list item. In this example, the [NODE_ON_CLICK_EVENT](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype) event is used as an example to illustrate how to add event response information.

   <!-- @[normal_text_list_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/NormalTextListExample.h) -->

   ``` C
   // NormalTextListExample.h
   // Text list example.
   
   #ifndef MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   #define MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   
   #include "ArkUIBaseNode.h"
   #include "ArkUIListItemNode.h"
   #include "ArkUIListNode.h"
   #include "ArkUITextNode.h"
   #include <hilog/log.h>
   
   const unsigned int LOG_PRINT_DOMAIN = 0xF811;
   const unsigned int LOOP_SIZE = 30;
   const unsigned int FONT_SIZE = 16;
   const unsigned int HEIGHT_SIZE = 200;
   const float PERCENT_WIDTH_1 = 1;
   const float PERCENT_HEIGHT_1 = 1;
   
   namespace NativeModule {
   
   std::shared_ptr<ArkUIBaseNode> CreateTextListExample()
   {
       // Create components and mount them.
       // 1: Create a List component.
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(PERCENT_WIDTH_1);
       list->SetPercentHeight(PERCENT_HEIGHT_1);
       // 2: Create a ListItem child component and mount it to the List component.
       for (int32_t i = 0; i < LOOP_SIZE; ++i) {
           auto listItem = std::make_shared<ArkUIListItemNode>();
           auto textNode = std::make_shared<ArkUITextNode>();
           textNode->SetTextContent(std::to_string(i));
           textNode->SetFontSize(FONT_SIZE);
           textNode->SetPercentWidth(PERCENT_WIDTH_1);
           textNode->SetHeight(HEIGHT_SIZE);
           textNode->SetBackgroundColor(0xFFfffacd);
           textNode->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER);
           listItem->AddChild(textNode);
           // Register the click event for the list item.
           auto onClick = [](ArkUI_NodeEvent *event) {
               // Obtain the basic event object from the component event.
               auto *inputEvent = OH_ArkUI_NodeEvent_GetInputEvent(event);
               if (inputEvent == nullptr) {
                   return;
               }
               // Obtain the event type from the component event.
               auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
               OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                            "NdkAddInteractionEvent_eventInfo inputEvent = %{public}p", inputEvent);
               OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                            "NdkAddInteractionEvent_eventInfo eventType = %{public}d", eventType);
               auto componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
               // Obtain the numerical data from the component event.
               OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                            "NdkAddInteractionEvent_eventInfo componentEvent = %{public}p", componentEvent);
               // Obtain the component object that triggers the event.
               auto nodeHandle = OH_ArkUI_NodeEvent_GetNodeHandle(event);
               if (nodeHandle == nullptr) {
                   return;
               }
               OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                            "NdkAddInteractionEvent_eventInfo nodeHandle = %{public}p", nodeHandle);
               // Differentiate event types and handle them accordingly. Other event information APIs follow similar usage patterns.
               switch (eventType) {
                   case NODE_ON_CLICK_EVENT: {
                       // Perform operations when the click event is triggered. Obtain event information from the base input event.
                       auto x = OH_ArkUI_PointerEvent_GetX(inputEvent);
                       auto y = OH_ArkUI_PointerEvent_GetY(inputEvent);
                       auto displayX = OH_ArkUI_PointerEvent_GetDisplayX(inputEvent);
                       auto displayY = OH_ArkUI_PointerEvent_GetDisplayY(inputEvent);
                       auto windowX = OH_ArkUI_PointerEvent_GetWindowX(inputEvent);
                       auto windowY = OH_ArkUI_PointerEvent_GetWindowY(inputEvent);
                       auto pointerCount = OH_ArkUI_PointerEvent_GetPointerCount(inputEvent);
                       auto xByIndex = OH_ArkUI_PointerEvent_GetXByIndex(inputEvent, 0);
                       auto yByIndex = OH_ArkUI_PointerEvent_GetYByIndex(inputEvent, 0);
                       auto displayXByIndex = OH_ArkUI_PointerEvent_GetDisplayXByIndex(inputEvent, 0);
                       auto displayYByIndex = OH_ArkUI_PointerEvent_GetDisplayYByIndex(inputEvent, 0);
                       auto windowXByIndex = OH_ArkUI_PointerEvent_GetWindowXByIndex(inputEvent, 0);
                       auto windowYByIndex = OH_ArkUI_PointerEvent_GetWindowYByIndex(inputEvent, 0);
                       auto pointerId = OH_ArkUI_PointerEvent_GetPointerId(inputEvent, 0);
                       auto pressure = OH_ArkUI_PointerEvent_GetPressure(inputEvent, 0);
                       auto action = OH_ArkUI_UIInputEvent_GetAction(inputEvent);
                       auto eventTime = OH_ArkUI_UIInputEvent_GetEventTime(inputEvent);
                       auto sourceType = OH_ArkUI_UIInputEvent_GetSourceType(inputEvent);
                       auto type = OH_ArkUI_UIInputEvent_GetType(inputEvent);
                       std::string eventInfo =
                           "x: " + std::to_string(x) + ", y: " + std::to_string(y) +
                           ", displayX: " + std::to_string(displayX) + ", displayY: " + std::to_string(displayY) +
                           ", windowX: " + std::to_string(windowX) + ", windowY: " + std::to_string(windowY) +
                           ", pointerCount: " + std::to_string(pointerCount) + ", xByIndex: " + std::to_string(xByIndex) +
                           ", yByIndex: " + std::to_string(yByIndex) +
                           ", displayXByIndex: " + std::to_string(displayXByIndex) +
                           ", displayYByIndex: " + std::to_string(displayYByIndex) +
                           ", windowXByIndex: " + std::to_string(windowXByIndex) +
                           ", windowYByIndex: " + std::to_string(windowYByIndex) +
                           ", pointerId: " + std::to_string(pointerId) + ", pressure: " + std::to_string(pressure) +
                           ", action: " + std::to_string(action) + ", eventTime: " + std::to_string(eventTime) +
                           ", sourceType: " + std::to_string(sourceType) + ", type: " + std::to_string(type);
                       OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                                    "NdkAddInteractionEvent_eventInfoOfCommonEvent eventInfo = %{public}s",
                                    eventInfo.c_str());
                   }
                   default: {
                       break;
                   }
               }
           };
           listItem->RegisterOnClick(onClick);
           list->AddChild(listItem);
       }
       // 3: Register list-related listening events.
       list->RegisterOnScrollIndex([](int32_t index) { OH_LOG_INFO(LOG_APP, "on list scroll index: %{public}d", index); });
       // 4: Register the appear event.
       list->RegisterOnAppear([]() { OH_LOG_INFO(LOG_APP, "on list mount to tree"); });
       // 5: Register the disappear event.
       list->RegisterOnDisappear([]() { OH_LOG_INFO(LOG_APP, "on list unmount from tree"); });
       return list;
   }
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   ```

   The log printing APIs [OH_LOG_Print](../reference/apis-performance-analysis-kit/capi-log-h.md#oh_log_print) and [OH_LOG_INFO](../reference/apis-performance-analysis-kit/capi-log-h.md#oh_log_info) are used, so you need to add the reference to **libhilog_ndk.z.so** in the **CMakeLists.txt** file.

   ```text
   add_library(entry SHARED napi_init.cpp NativeEntry.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libace_ndk.z.so libhilog_ndk.z.so)
   ```

## Listening for Component Layout and Drawing Events

Since API version 16, NDK APIs provide functions for registering and unregistering callbacks for UI component layout completion and drawing completion events. You can use the following APIs to listen for when specific node layouts are completed or when drawing is finished, and register corresponding callbacks:

Use [OH_ArkUI_RegisterLayoutCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registerlayoutcallbackonnodehandle) to register a layout completion callback.

Use [OH_ArkUI_RegisterDrawCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registerdrawcallbackonnodehandle) to register a drawing completion callback.

Use [OH_ArkUI_UnregisterLayoutCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_unregisterlayoutcallbackonnodehandle) to unregister a layout completion callback.

Use [OH_ArkUI_UnregisterDrawCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_unregisterdrawcallbackonnodehandle) to unregister a drawing completion callback.

> **NOTE**
>
> [OH_ArkUI_RegisterLayoutCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registerlayoutcallbackonnodehandle) and [OH_ArkUI_RegisterDrawCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registerdrawcallbackonnodehandle) can be used to listen for component layout completion or drawing completion events, but only one function pointer can be registered, which means subsequent calls will overwrite the previous callbacks.

The following example is based on the [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md) section and provides the development guidelines for listening to component layout and drawing events.

In the **ArkUITextNode** object, encapsulate the methods for calling the APIs for listening to component layout and drawing events.

<!-- @[arkUITestNode_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NativeNodeUtilsSample/entry/src/main/cpp/ArkUITextNode.h) -->

``` C
// ArkUITextNode.h
// Implement an encapsulation class for the text component.
#ifndef MYAPPLICATION_ARKUITEXTNODE_H
#define MYAPPLICATION_ARKUITEXTNODE_H

#include <arkui/native_type.h>
#include <arkui/native_node.h>
#include <hilog/log.h>
#include "ArkUINode.h"
#include <string>

// ...
namespace NativeModule {
const unsigned int LOG_PRINT_DOMAIN = 0xFF00;
// Layout completion callback
void OnLayoutCompleted(void *userData)
{
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "the text_node is layout completed");
}
// Drawing completion callback
void OnDrawCompleted(void *userData)
{
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "the text_node is draw completed");
}
// ...
class ArkUITextNode : public ArkUINode {
public:
    ArkUITextNode()
        : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_TEXT)) {}
    void SetFontSize(float fontSize)
    {
        ArkUI_NumberValue value[] = {{.f32 = fontSize}};
        ArkUI_AttributeItem item = {value, 1};
        nativeModule_->setAttribute(handle_, NODE_FONT_SIZE, &item);
    }
    void SetFontColor(uint32_t color)
    {
        ArkUI_NumberValue value[] = {{.u32 = color}};
        ArkUI_AttributeItem item = {value, 1};
        nativeModule_->setAttribute(handle_, NODE_FONT_COLOR, &item);
    }
    void SetTextContent(const std::string &content)
    {
        ArkUI_AttributeItem item = {nullptr, 0, content.c_str()};
        nativeModule_->setAttribute(handle_, NODE_TEXT_CONTENT, &item);
    }
    void SetTextAlign(ArkUI_TextAlignment align)
    {
        ArkUI_NumberValue value[] = {{.i32 = align}};
        ArkUI_AttributeItem item = {value, 1};
        nativeModule_->setAttribute(handle_, NODE_TEXT_ALIGN, &item);
    }
    void SetLayoutCallBack(int32_t nodeId)
    {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "set layout callback");
        // Register a layout completion callback.
        OH_ArkUI_RegisterLayoutCallbackOnNodeHandle(handle_, handle_, OnLayoutCompleted);
    }
    void ResetLayoutCallBack()
    {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "reset layout callback");
        // Unregister the layout completion callback.
        OH_ArkUI_UnregisterLayoutCallbackOnNodeHandle(handle_);
    }
    void SetDrawCallBack(int32_t nodeId)
    {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "set draw callback");
        // Register a drawing completion callback.
        OH_ArkUI_RegisterDrawCallbackOnNodeHandle(handle_, handle_, OnDrawCompleted);
    }
    void ResetDrawCallBack()
    {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "reset draw callback");
        // Unregister the drawing completion callback.
        OH_ArkUI_UnregisterDrawCallbackOnNodeHandle(handle_);
    }
    void SetInspectorId(std::string inspectorId)
    {
        ArkUI_AttributeItem item = {nullptr, 0, inspectorId.c_str()};
        nativeModule_->setAttribute(handle_, NODE_ID, &item);
    }
    // ...
};
} // namespace NativeModule

#endif // MYAPPLICATION_ARKUITEXTNODE_H
```

<!-- @[normalTextListExample_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NativeNodeUtilsSample/entry/src/main/cpp/NormalTextListExample.h) -->

``` C
// NormalTextListExample.h
// Define custom entry functions.

#ifndef MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
#define MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H

#include "ArkUIBaseNode.h"
#include "ArkUIListItemNode.h"
#include "ArkUIListNode.h"
#include "ArkUITextNode.h"
#include <hilog/log.h>
#define SIZE_16 16
#define SIZE_100 100
#define COLOR_BACKGROUND 0xFFfffacd

namespace NativeModule {

std::shared_ptr<ArkUIBaseNode> CreateTextListExample()
{
    // Create components and mount them.
    // 1: Use smart pointers to create a List component.
    auto list = std::make_shared<ArkUIListNode>();
    list->SetPercentWidth(1);
    list->SetPercentHeight(1);
    // 2: Create a ListItem child component and mount it to the List component.
    for (int32_t i = 0; i < 1; ++i) {
        auto listItem = std::make_shared<ArkUIListItemNode>();
        auto textNode = std::make_shared<ArkUITextNode>();
        textNode->SetTextContent(std::to_string(i));
        textNode->SetFontSize(SIZE_16);
        textNode->SetPercentWidth(1);
        textNode->SetHeight(SIZE_100);
        textNode->SetBackgroundColor(COLOR_BACKGROUND);
        textNode->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER);
        // Register a layout callback for the current node.
        textNode->SetLayoutCallBack(i);
        // Register drawing callback for the current node.
        textNode->SetDrawCallBack(i);
        listItem->AddChild(textNode);
        list->AddChild(listItem);
    }
    return list;
}
} // namespace NativeModule

#endif // MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
```

## Listening for the Color Mode Change Event

The ArkUI development framework provides system color mode (dark/light) change events through NDK APIs at the component level. You can use [OH_ArkUI_RegisterSystemColorModeChangeEvent](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registersystemcolormodechangeevent) to register a callback with a component. System color mode changes on this component will notify the callback, implementing the listening for the color mode change event on the NDK side.

> **NOTE**
>
> - Multiple components can share the same callback for color mode changes.
>
> - A single component can only register one callback for system color mode changes.
>
> - It is recommended that you place the registration operation on a node that will not be destroyed during the page lifecycle to prevent callback failures due to node destruction.

<!-- @[shade_change_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
struct ColorModeInfo {
    const char* lightMsg;
    const char* darkMsg;
};

// Register a callback.
void onColorModeChange(ArkUI_SystemColorMode colorMode, void *userData)
{
    ColorModeInfo* info = static_cast<ColorModeInfo*>(userData);
    if (colorMode == ARKUI_SYSTEM_COLOR_MODE_LIGHT) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_Light mode: ", info->lightMsg);
    } else if (colorMode == ARKUI_SYSTEM_COLOR_MODE_DARK) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                     "NdkAddInteractionEvent_Dark mode: ", info->darkMsg);
    }
}

ArkUI_NodeHandle testColorModeChange(ArkUI_NativeNodeAPI_1 *nodeAPI) {
    ArkUI_NodeHandle text = nodeAPI->createNode(ARKUI_NODE_TEXT);
    static ColorModeInfo info = {"Light mode", "Dark mode"};
    OH_ArkUI_RegisterSystemColorModeChangeEvent(text, &info, onColorModeChange);

    ArkUI_AttributeItem itemstring = {nullptr, 0, ("test_light_dark")};
    nodeAPI->setAttribute(text, NODE_TEXT_CONTENT, &itemstring);

    return text;
}
```