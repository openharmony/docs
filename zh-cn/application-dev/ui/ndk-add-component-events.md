# 添加事件监听
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

NDK接口为组件提供了事件监听能力。本文介绍组件事件监听、布局和绘制送显事件监听以及深浅色变更事件监听的使用方法。

## 监听组件事件

NDK接口支持监听UI组件自身状态变化和用户交互事件。

首先，可使用[addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver)函数添加组件事件的监听器，该监听器会监听该组件上发生的所有事件，例如：点击事件、焦点事件。然后，使用[registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent)函数声明组件需要监听的事件，NDK接口支持的事件范围可以查询[ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)枚举。 

> **说明：**
>
> - 事件注册需要声明[addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver)监听器注册和[registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent)事件类型，监听器只能监听已声明的事件。
>
> - 需要关注事件的反注册逻辑，如在组件销毁前调用[removeNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removenodeeventreceiver)移除事件监听器，[unregisterNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodeevent)通知ArkUI框架已监听的事件不再需要监听。
>
> - [addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver)可以添加多个函数指针，每个函数指针都会在对应事件触发时触发，对应的[removeNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removenodeeventreceiver)需要传递对应的函数指针用于移除监听。
>
> - [registerNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeeventreceiver)是全局监听函数，不同于[addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver)，[registerNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeeventreceiver)能够监听所有Native组件的事件触发，但只能传递一个函数指针，多次调用使用最后一次的函数指针进行回调，释放时使用[unregisterNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodeeventreceiver)进行释放。

以下示例均需基于[接入ArkTS页面](ndk-access-the-arkts-page.md)，详细代码请参考[完整示例](#完整示例)。

### 监听节点事件

通过addNodeEventReceiver对节点绑定事件处理函数，接着通过调用registerNodeEvent注册对应的事件监听。

定义[ArkUI_NativeNodeAPI_1](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md)类型的指针。
<!-- @[define_node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Common.h) -->

``` C
ArkUI_NativeNodeAPI_1 *nodeAPI = nullptr;
```

调用[OH_ArkUI_GetModuleInterface](../reference/apis-arkui/capi-native-interface-h.md#oh_arkui_getmoduleinterface)接口给定义的指针赋值。
<!-- @[get_module_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/NativeEntry.cpp) -->

``` C++
OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nodeAPI);
```

定义事件触发回调函数。
<!-- @[node_event_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
void NodeEventReceiver(ArkUI_NodeEvent *event) {
  // 设置对应的事件类型触发时进行的操作，如NODE_ON_CLICK_EVENT
};
```

创建一个节点，将事件触发回调函数绑定到该节点并进行事件注册。
<!-- @[create_and_register_node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
auto button = nodeAPI->createNode(ARKUI_NODE_BUTTON);
nodeAPI->addNodeEventReceiver(button, NodeEventReceiver);
nodeAPI->registerNodeEvent(button, NODE_ON_CLICK_EVENT, 0, nullptr);
```

详细的事件类型请参考[ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)。

通过unregisterNodeEvent解注册对应的事件类型，再通过removeNodeEventReceiver卸载事件处理函数。

解注册对应的事件类型。
<!-- @[unregister_node_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
nodeAPI->unregisterNodeEvent(button, NODE_ON_CLICK_EVENT);
```

卸载事件处理函数。
<!-- @[remove_node_event_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
nodeAPI->removeNodeEventReceiver(button, NodeEventReceiver);
```

### 监听全局事件

使用registerNodeEventReceiver注册全局的事件处理函数，对事件进行统一的监听，结束后可使用unregisterNodeEventReceiver进行释放。

注册全局的事件处理函数。
<!-- @[register_global_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
nodeAPI->registerNodeEventReceiver([](ArkUI_NodeEvent *event) {
    // 从组件事件中获取基础事件对象
    auto *inputEvent = OH_ArkUI_NodeEvent_GetInputEvent(event);
    // 从组件事件获取事件类型
    auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
    // ...
    switch (eventType) {
        case NODE_ON_CLICK_EVENT: {
            // 触发点击事件所进行的操作，从基础事件获取事件信息
            // ...
        }
        default: {
            break;
        }
    }
});
```

解注册全局的事件处理函数。
<!-- @[unregister_node_event_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
nodeAPI->unregisterNodeEventReceiver();
```

### 完整示例

1. 在ArkUINode基类对象中封装事件注册及监听接口调用的方法。

   <!-- @[arkui_node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/ArkUINode.h) -->
   
   ``` C
   // ArkUINode.h
   // 提供通用属性和事件的封装。
   
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
           // 事件触发时需要通过函数获取对应的事件对象，这边通过设置节点自定义数据将封装类指针保持在组件上，方便后续事件分发。
           nativeModule_->setUserData(handle_, this);
           // 注册节点监听事件接收器。
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
       // 设置节点宽度
       void SetWidth(float width)
       {
           if (!handle_) {
               return;
           }
           ArkUI_NumberValue value[] = {{.f32 = width}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_WIDTH, &item);
       }
       // 设置节点宽度（百分比形式）
       void SetPercentWidth(float percent)
       {
           if (!handle_) {
               return;
           }
           ArkUI_NumberValue value[] = {{.f32 = percent}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_WIDTH_PERCENT, &item);
       }
       // 设置节点高度
       void SetHeight(float height)
       {
           if (!handle_) {
               return;
           }
           ArkUI_NumberValue value[] = {{.f32 = height}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_HEIGHT, &item);
       }
       // 设置节点高度（百分比形式）
       void SetPercentHeight(float percent)
       {
           if (!handle_) {
               return;
           }
           ArkUI_NumberValue value[] = {{.f32 = percent}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_HEIGHT_PERCENT, &item);
       }
       // 设置节点背景颜色
       void SetBackgroundColor(uint32_t color)
       {
           if (!handle_) {
               return;
           }
           ArkUI_NumberValue value[] = {{.u32 = color}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_BACKGROUND_COLOR, &item);
       }
       // 处理通用事件。
       void RegisterOnClick(const std::function<void(ArkUI_NodeEvent *event)> &onClick)
       {
           if (!handle_) {
               return;
           }
           onClick_ = onClick;
           // 注册点击事件。
           nativeModule_->registerNodeEvent(handle_, NODE_ON_CLICK_EVENT, 0, nullptr);
       }
   
       void RegisterOnTouch(const std::function<void(int32_t type, float x, float y)> &onTouch)
       {
           if (!handle_) {
               return;
           }
           onTouch_ = onTouch;
           // 注册触碰事件。
           nativeModule_->registerNodeEvent(handle_, NODE_TOUCH_EVENT, 0, nullptr);
       }
   
       void RegisterOnDisappear(const std::function<void()> &onDisappear)
       {
           if (!handle_) {
               return;
           }
           onDisappear_ = onDisappear;
           // 注册卸载事件。
           nativeModule_->registerNodeEvent(handle_, NODE_EVENT_ON_DISAPPEAR, 0, nullptr);
       }
   
       void RegisterOnAppear(const std::function<void()> &onAppear)
       {
           if (!handle_) {
               return;
           }
           onAppear_ = onAppear;
           // 注册挂载事件。
           nativeModule_->registerNodeEvent(handle_, NODE_EVENT_ON_APPEAR, 0, nullptr);
       }
   
   protected:
       // 事件监听器函数指针。
       static void NodeEventReceiver(ArkUI_NodeEvent *event)
       {
           // 获取事件发生的UI组件对象。
           auto nodeHandle = OH_ArkUI_NodeEvent_GetNodeHandle(event);
           // 获取保持在UI组件对象中的自定义数据，返回封装类指针。
           auto *node = reinterpret_cast<ArkUINode *>(
               NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->getUserData(nodeHandle));
           // 基于封装类实例对象处理事件。
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
                   // 组件特有事件交给子类处理
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

2. 在ArkUIListNode对象中注册列表事件[NODE_LIST_ON_SCROLL_INDEX](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)。
   <!-- @[arkui_list_node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/ArkUIListNode.h) -->
   
   ``` C
   // ArkUIListNode.h
   // 列表封装类对象
   
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
   
       // 注册列表相关事件。
       void RegisterOnScrollIndex(const std::function<void(int32_t index)> &onScrollIndex)
       {
           if (!handle_) {
               return;
           }
           onScrollIndex_ = onScrollIndex;
           nativeModule_->registerNodeEvent(handle_, NODE_LIST_ON_SCROLL_INDEX, 0, nullptr);
       }
   
   protected:
      // 处理List相关事件。
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


3. 在文本列表项中添加事件监听函数，本示例以点击事件（[NODE_ON_CLICK_EVENT](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)）为例，添加事件响应的具体信息。
   <!-- @[normal_text_list_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/NormalTextListExample.h) -->
   
   ``` C
   // NormalTextListExample.h
   // 文本列表示例。
   
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
       // 创建组件并挂载
       // 1：创建List组件。
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(PERCENT_WIDTH_1);
       list->SetPercentHeight(PERCENT_HEIGHT_1);
       // 2：创建ListItem子组件并挂载到List上。
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
           // 列表项注册点击事件。
           auto onClick = [](ArkUI_NodeEvent *event) {
               // 从组件事件中获取基础事件对象
               auto *inputEvent = OH_ArkUI_NodeEvent_GetInputEvent(event);
               if (inputEvent == nullptr) {
                   return;
               }
               // 从组件事件获取事件类型
               auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
               OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                            "NdkAddInteractionEvent_eventInfo inputEvent = %{public}p", inputEvent);
               OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                            "NdkAddInteractionEvent_eventInfo eventType = %{public}d", eventType);
               auto componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
               // 获取组件事件中的数字类型数据
               OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                            "NdkAddInteractionEvent_eventInfo componentEvent = %{public}p", componentEvent);
               // 获取触发该事件的组件对象
               auto nodeHandle = OH_ArkUI_NodeEvent_GetNodeHandle(event);
               if (nodeHandle == nullptr) {
                   return;
               }
               OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "[Sample_NdkAddInteractionEvent]",
                            "NdkAddInteractionEvent_eventInfo nodeHandle = %{public}p", nodeHandle);
               // 根据eventType来区分事件类型，进行差异化处理，其他获取事件信息的接口也可类似方式来进行差异化的处理
               switch (eventType) {
                   case NODE_ON_CLICK_EVENT: {
                       // 触发点击事件所进行的操作，从基础事件获取事件信息
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
       // 3：注册List相关监听事件.
       list->RegisterOnScrollIndex([](int32_t index) { OH_LOG_INFO(LOG_APP, "on list scroll index: %{public}d", index); });
       // 4: 注册挂载事件。
       list->RegisterOnAppear([]() { OH_LOG_INFO(LOG_APP, "on list mount to tree"); });
       // 5: 注册卸载事件。
       list->RegisterOnDisappear([]() { OH_LOG_INFO(LOG_APP, "on list unmount from tree"); });
       return list;
   }
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   ```

   由于使用了日志打印接口[OH_LOG_Print](../reference/apis-performance-analysis-kit/capi-log-h.md#oh_log_print)和[OH_LOG_INFO](../reference/apis-performance-analysis-kit/capi-log-h.md#oh_log_info)，需要在CMakeLists.txt中添加对libhilog_ndk.z.so的引用。

   ```text
   add_library(entry SHARED napi_init.cpp NativeEntry.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libace_ndk.z.so libhilog_ndk.z.so)
   ```


## 监听组件布局和绘制送显事件

从API version 16开始，NDK接口针对UI组件的布局或绘制送显完成，提供了注册与取消监听函数的方式。开发者可使用如下接口监听指定节点布局完成或者绘制送显完成的时机，并注册相应的回调函数。

可使用[OH_ArkUI_RegisterLayoutCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registerlayoutcallbackonnodehandle)注册组件布局完成的回调方法。

可使用[OH_ArkUI_RegisterDrawCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registerdrawcallbackonnodehandle)注册绘制送显完成的回调方法。

可使用[OH_ArkUI_UnregisterLayoutCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_unregisterlayoutcallbackonnodehandle)取消组件布局完成的回调方法注册。

可使用[OH_ArkUI_UnregisterDrawCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_unregisterdrawcallbackonnodehandle)取消绘制送显完成的回调方法注册。 


> **说明：**
>
> [OH_ArkUI_RegisterLayoutCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registerlayoutcallbackonnodehandle)和[OH_ArkUI_RegisterDrawCallbackOnNodeHandle](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registerdrawcallbackonnodehandle)能够监听组件的布局完成或者绘制送显完成事件触发，但只能传递一个函数指针，多次调用使用最后一次的函数指针进行回调。


以下示例基于[接入ArkTS页面](ndk-access-the-arkts-page.md)章节，提供组件布局和绘制送显事件监听的开发指导。

在ArkUITextNode对象中封装上述监听组件布局和绘制送显事件接口的调用方法。

<!-- @[arkUITestNode_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NativeNodeUtilsSample/entry/src/main/cpp/ArkUITextNode.h) -->

``` C
// ArkUITextNode.h
// 实现文本组件的封装类。
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
// 布局完成的回调方法
void OnLayoutCompleted(void *userData)
{
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "the text_node is layout completed");
}
// 绘制送显完成的回调方法
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
        // 注册布局完成的回调方法
        OH_ArkUI_RegisterLayoutCallbackOnNodeHandle(handle_, handle_, OnLayoutCompleted);
    }
    void ResetLayoutCallBack()
    {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "reset layout callback");
        // 取消注册布局完成的回调方法
        OH_ArkUI_UnregisterLayoutCallbackOnNodeHandle(handle_);
    }
    void SetDrawCallBack(int32_t nodeId)
    {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "set draw callback");
        // 注册绘制送显完成的回调方法
        OH_ArkUI_RegisterDrawCallbackOnNodeHandle(handle_, handle_, OnDrawCompleted);
    }
    void ResetDrawCallBack()
    {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "Callback", "reset draw callback");
        // 取消注册绘制送显完成的回调方法
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
// 自定义接入入口函数

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
    // 创建组件并挂载
    // 1：使用智能指针创建List组件。
    auto list = std::make_shared<ArkUIListNode>();
    list->SetPercentWidth(1);
    list->SetPercentHeight(1);
    // 2：创建ListItem子组件并挂载到List上。
    for (int32_t i = 0; i < 1; ++i) {
        auto listItem = std::make_shared<ArkUIListItemNode>();
        auto textNode = std::make_shared<ArkUITextNode>();
        textNode->SetTextContent(std::to_string(i));
        textNode->SetFontSize(SIZE_16);
        textNode->SetPercentWidth(1);
        textNode->SetHeight(SIZE_100);
        textNode->SetBackgroundColor(COLOR_BACKGROUND);
        textNode->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER);
        // 在当前节点注册布局回调
        textNode->SetLayoutCallBack(i);
        // 在当前节点注册绘制送显回调
        textNode->SetDrawCallBack(i);
        listItem->AddChild(textNode);
        list->AddChild(listItem);
    }
    return list;
}
} // namespace NativeModule

#endif // MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
```


## 监听深浅色变更事件

ArkUI开发框架在NDK接口提供了以组件为注册单位的系统深浅色变更事件。开发者可使用[OH_ArkUI_RegisterSystemColorModeChangeEvent](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_registersystemcolormodechangeevent)注册回调函数，当系统深浅色发生变更时，会通知注册在组件上的回调，从而实现NDK侧的深浅色变更事件监听。

> **说明：**
>
> - 一个回调内可以自行设计多个组件的深浅色变更。
>
> - 同一组件仅能注册一个系统深浅色变更回调。
>
> - 建议将注册操作放置于页面生命周期中不会被销毁的节点上，以避免因节点销毁导致回调失效的问题。

<!-- @[shade_change_event](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NdkAddInteractionEvent/entry/src/main/cpp/Function.h) -->

``` C
struct ColorModeInfo {
    const char* lightMsg;
    const char* darkMsg;
};

// 注册回调函数
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
