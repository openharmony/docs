# Listening for Component Events


The NDK API provides a way to listen for UI component events through listener functions. First, you can use the [addNodeEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#addnodeeventreceiver) function to add an event listener for the component, which will listen for all events that occur on that component, such as click events and focus events. Then, you can use the [registerNodeEvent](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#registernodeevent) function to declare which events of the component need to be listened for. The range of events supported by the NDK API is defined through the [ArkUI_NodeEventType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype) enumeration values.


> **NOTE**
> - Event registration requires the declaration of **addNodeEventReceiver** listener registration and **registerNodeEvent** event types. The listener can only listen for declared events.
> 
> - Pay attention to the logic of event deregistration. For example, before the component is destroyed, call [removeNodeEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#removenodeeventreceiver) to remove the event listener and [unregisterNodeEvent](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#unregisternodeevent) to notify the ArkUI framework that the listened events no longer need to be listened for.
> 
> - **addNodeEventReceiver** can add multiple function pointers, each of which is triggered when the corresponding event occurs. To remove a listener, the corresponding **removeNodeEventReceiver** function must be called with the exact function pointer used for adding the listener.
> 
> - [registerNodeEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#registernodeeventreceiver) is a global event listener function. Unlike **addNodeEventReceiver**, **registerNodeEventReceiver** can listen for the event triggers of all native components, but it can only accept a single function pointer. If it is called multiple times, only the last function pointer provided will be used for callbacks. To release the listener, use the [ungisterNodeEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#unregisternodeeventreceiver) function.


The following example is based on the [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md) section, supplementing related event listening.


1. Implement common event registration logic in the **ArkUINode** base class object.
   ```c
   // ArkUINode.h
   // Provide encapsulation of common properties and events.
   
   #ifndef MYAPPLICATION_ARKUINODE_H
   #define MYAPPLICATION_ARKUINODE_H
   
   #include "ArkUIBaseNode.h"
   #include "NativeModule.h"
   
   #include <arkui/native_node.h>
   #include <arkui/native_type.h>
   
   namespace NativeModule {
   
   class ArkUINode : public ArkUIBaseNode {
   public:
       explicit ArkUINode(ArkUI_NodeHandle handle) : ArkUIBaseNode(handle) {
           nativeModule_ = NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
           // When an event is triggered, you need to get the corresponding event object through a function. Here, by setting the node's custom data, the encapsulated class pointer is kept on the component for subsequent event distribution.
           nativeModule_->setUserData(handle_, this);
           // Register the node event receiver.
           nativeModule_->addNodeEventReceiver(handle_, ArkUINode::NodeEventReceiver);
       }
   
       ~ArkUINode() override {
           if (onClick_) {
               nativeModule_->unregisterNodeEvent(handle_, NODE_ON_CLICK);
           }
           if (onTouch_) {
               nativeModule_->unregisterNodeEvent(handle_, NODE_TOUCH_EVENT);
           }
           if (onDisappear) {
               nativeModule_->unregisterNodeEvent(handle_, NODE_EVENT_ON_DISAPPEAR);
           }
           if (onAppear) {
               nativeModule_->unregisterNodeEvent(handle_, NODE_EVENT_ON_APPEAR);
           }
           nativeModule_->removeNodeEventReceiver(handle_, ArkUINode::NodeEventReceiver);
       }
   
       void SetWidth(float width) {
           assert(handle_);
           ArkUI_NumberValue value[] = {{.f32 = width}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_WIDTH, &item);
       }
       void SetPercentWidth(float percent) {
           assert(handle_);
           ArkUI_NumberValue value[] = {{.f32 = percent}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_WIDTH_PERCENT, &item);
       }
       void SetHeight(float height) {
           assert(handle_);
           ArkUI_NumberValue value[] = {{.f32 = height}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_HEIGHT, &item);
       }
       void SetPercentHeight(float percent) {
           assert(handle_);
           ArkUI_NumberValue value[] = {{.f32 = percent}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_HEIGHT_PERCENT, &item);
       }
       void SetBackgroundColor(uint32_t color) {
           assert(handle_);
           ArkUI_NumberValue value[] = {{.u32 = color}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_BACKGROUND_COLOR, &item);
       }
       // Process common events.
       void RegisterOnClick(const std::function<void()> &onClick) {
           assert(handle_);
           onClick_ = onClick;
           // Register the click event.
           nativeModule_->registerNodeEvent(handle_, NODE_ON_CLICK, 0, nullptr);
       }
   
       void RegisterOnTouch(const std::function<void(int32_t type, float x, float y)> &onTouch) {
           assert(handle_);
           onTouch_ = onTouch;
           // Register the touch event.
           nativeModule_->registerNodeEvent(handle_, NODE_TOUCH_EVENT, 0, nullptr);
       }
   
       void RegisterOnDisappear(const std::function<void()> &onDisappear) {
           assert(handle_);
           onDisappear_ = onDisappear;
           // Register the disappear event.
           nativeModule_->registerNodeEvent(handle_, NODE_EVENT_ON_DISAPPEAR, 0, nullptr);
       }
   
       void RegisterOnAppear(const std::function<void()> &onAppear) {
           assert(handle_);
           onAppear_ = onAppear;
           // Register the appear event.
           nativeModule_->registerNodeEvent(handle_, NODE_EVENT_ON_APPEAR, 0, nullptr);
       }
   
   protected:
       // Event listener function pointer.
       static void NodeEventReceiver(ArkUI_NodeEvent *event) {
           // Obtain the UI component object where the event occurs.
           auto nodeHandle = OH_ArkUI_NodeEvent_GetNodeHandle(event);
           // Obtain the custom data kept in the UI component object, and return the encapsulated class pointer.
           auto *node = reinterpret_cast<ArkUINode *>(
               NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->getUserData(nodeHandle));
           // Process the event based on the encapsulated class instance object.
           node->ProcessNodeEvent(event);
       }
       void ProcessNodeEvent(ArkUI_NodeEvent *event) {
           auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
           switch (eventType) {
           case NODE_ON_CLICK: {
               if (onClick_) {
                   onClick_();
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
               // Component-specific events are processed by subclasses.
               OnNodeEvent(event);
           }
           }
       }
   
       virtual void OnNodeEvent(ArkUI_NodeEvent *event) {}
   
       void OnAddChild(const std::shared_ptr<ArkUIBaseNode> &child) override {
           nativeModule_->addChild(handle_, child->GetHandle());
       }
   
       void OnRemoveChild(const std::shared_ptr<ArkUIBaseNode> &child) override {
           nativeModule_->removeChild(handle_, child->GetHandle());
       }
   
       void OnInsertChild(const std::shared_ptr<ArkUIBaseNode> &child, int32_t index) override {
           nativeModule_->insertChildAt(handle_, child->GetHandle(), index);
       }
   
   private:
       std::function<void()> onClick_;
       std::function<void()> onDisappear_;
       std::function<void()> onAppear_;
       std::function<void(int32_t type, float x, float y)> onTouch_;
   };
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUINODE_H
   
   ```

2. Implement list event registration logic in the **ArkUIListNode** object.
   ```c
   // ArkUIListNode.h
   // List encapsulation class object
   
   #ifndef MYAPPLICATION_ARKUILISTNODE_H
   #define MYAPPLICATION_ARKUILISTNODE_H
   
   #include "ArkUINode.h"
   #include <hilog/log.h>
   
   namespace NativeModule {
   class ArkUIListNode : public ArkUINode {
   public:
       ArkUIListNode()
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_LIST)) {}
   
       ~ArkUIListNode() override { nativeModule_->unregisterNodeEvent(handle_, NODE_LIST_ON_SCROLL_INDEX); }
   
       void SetScrollBarState(bool isShow) {
           assert(handle_);
           ArkUI_ScrollBarDisplayMode displayMode =
               isShow ? ARKUI_SCROLL_BAR_DISPLAY_MODE_ON : ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF;
           ArkUI_NumberValue value[] = {{.i32 = displayMode}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_SCROLL_BAR_DISPLAY_MODE, &item);
       }
   
       // Register list-related events.
       void RegisterOnScrollIndex(const std::function<void(int32_t index)> &onScrollIndex) {
           assert(handle_);
           onScrollIndex_ = onScrollIndex;
           nativeModule_->registerNodeEvent(handle_, NODE_LIST_ON_SCROLL_INDEX, 0, nullptr);
       }
   
   protected:
      // Process list-related events.
       void OnNodeEvent(ArkUI_NodeEvent *event) override {
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

3. Add related events.
   ```c
   // TextListExample.h
   // Text list example.
   
   #ifndef MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   #define MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   
   #include "ArkUIBaseNode.h"
   #include "ArkUIListItemNode.h"
   #include "ArkUIListNode.h"
   #include "ArkUITextNode.h"
   #include <hilog/log.h>
   
   namespace NativeModule {
   
   std::shared_ptr<ArkUIBaseNode> CreateTextListExample() {
       // Create components and mount them.
       // 1: Create a List component.
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(1);
       list->SetPercentHeight(1);
       // 2: Create a ListItem child component and mount it to the List component.
       for (int32_t i = 0; i < 30; ++i) {
           auto listItem = std::make_shared<ArkUIListItemNode>();
           auto textNode = std::make_shared<ArkUITextNode>();
           textNode->SetTextContent(std::to_string(i));
           textNode->SetFontSize(16);
           textNode->SetPercentWidth(1);
           textNode->SetHeight(100);
           textNode->SetBackgroundColor(0xFFfffacd);
           textNode->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER);
           listItem->AddChild(textNode);
           // Register the click event for the list item.
           listItem->RegisterOnClick([i]() { OH_LOG_INFO(LOG_APP, "on %{public}d list item click", i); });
           list->AddChild(listItem);
       }
       // 3: Register list-related listening events.
       list->RegisterOnScrollIndex([](int32_t index) { OH_LOG_INFO(LOG_APP, "on list scroll index: %{public}d", index); });
       // 4: Register the appear event.
       list->RegisterOnAppear([]() { OH_LOG_INFO(LOG_APP, "on list mount to tree"); });
       // 4: Register the disappear event.
       list->RegisterOnDisappear([]() { OH_LOG_INFO(LOG_APP, "on list unmount from tree"); });
       return list;
   }
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   
   ```
