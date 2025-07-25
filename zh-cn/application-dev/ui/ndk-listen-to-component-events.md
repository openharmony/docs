# 监听组件事件


NDK接口针对UI组件的事件，提供了监听函数的方式。首先，可使用[addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver)函数添加组件事件的监听器，该监听器会监听该组件上发生的所有事件，例如：点击事件、焦点事件。然后，可使用[registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent)函数声明组件的哪些事件需要监听，NDK接口支持的事件范围通过[ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)枚举值定义。


> **说明：**
> - 事件注册需要声明[addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver)监听器注册和[registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent)事件类型，监听器只能监听已声明的事件。
> 
> - 需要关注事件的反注册逻辑，如在组件销毁前调用[removeNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removenodeeventreceiver)移除事件监听器，[unregisterNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodeevent)通知ArkUI框架已监听的事件不再需要监听。
> 
> - [addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver)可以添加多个函数指针，每个函数指针都会在对应事件触发时触发，对应的[removeNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removenodeeventreceiver)需要传递对应的函数指针用于移除监听。
> 
> - [registerNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeeventreceiver)是全局监听函数，不同于[addNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addnodeeventreceiver)，[registerNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeeventreceiver)能够监听所有Native组件的事件触发，但只能传递一个函数指针，多次调用使用最后一次的函数指针进行回调，释放时使用[ungisterNodeEventReceiver](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#unregisternodeeventreceiver)进行释放。


以下示例基于[接入ArkTS页面](ndk-access-the-arkts-page.md)章节，补充相关事件监听。


- 事件注册和事件解注册

  通过addNodeEventReceiver对节点绑定事件处理函数，接着通过调用registerNodeEvent注册对应的事件。

  > 说明：
  > 
  > 事件监听函数的入参ArkUI_NodeEvent* event的生命周期只在函数回调周期内生效，不推荐对该指针进行缓存或者进行异步处理。

  ```
  ArkUI_NativeNodeAPI_1 *nodeAPI = nullptr;
  OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nodeAPI);
  void NodeEventReceiver(ArkUI_NodeEvent *event) {
    // 设置对应的事件类型触发时进行的操作，如NODE_ON_CLICK
  };
  auto button = nodeAPI->createNode(ARKUI_NODE_BUTTON);
  nodeAPI->addNodeEventReceiver(button, NodeEventReceiver);
  nodeAPI->registerNodeEvent(button, NODE_ON_CLICK, 0, nullptr);
  ```
  详细的事件类型请参考[ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype)。

  通过unregisterNodeEvent解注册对应的事件类型，再通过removeNodeEventReceiver卸载事件处理函数。

  ```
  nodeAPI->unregisterNodeEvent(button, NODE_ON_CLICK);
  nodeAPI->removeNodeEventReceiver(button, NodeEventReceiver);
  ```

- 全局事件监听

  使用registerNodeEventReceiver注册全局的事件处理函数，对事件进行统一的处理，结束后可使用ungisterNodeEventReceiver进行释放。

  ```
  nodeAPI->registerNodeEventReceiver([](ArkUI_NodeEvent *event){
    auto *inputEvent = OH_ArkUI_NodeEvent_GetInputEvent(event);
    auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
    case NODE_ON_CLICK: {
        // 触发点击事件所进行的操作
    }
    default: {
        break;
    }
  })
  nodeAPI->unregisterNodeEventReceiver();
  ```

- 获取事件信息

  ArkUI框架提供了[OH_ArkUI_NodeEvent_GetInputEvent()](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeevent_getinputevent)接口，用于从输入交互相关的组件事件（如NODE_ON_CLICK、NODE_TOUCH_EVENT等，具体可参见每个枚举定义的说明）中获取基础事件对象。然后，可通过调用[OH_ArkUI_PointerEvent_GetDisplayX()](../reference/apis-arkui/capi-ui-input-event-h.md#oh_arkui_pointerevent_getdisplayx)、[OH_ArkUI_PointerEvent_GetDisplayXByIndex()](../reference/apis-arkui/capi-ui-input-event-h.md#oh_arkui_pointerevent_getdisplayxbyindex)、[OH_ArkUI_UIInputEvent_GetAction()](../reference/apis-arkui/capi-ui-input-event-h.md#oh_arkui_uiinputevent_getaction)和[OH_ArkUI_UIInputEvent_GetEventTime()](../reference/apis-arkui/capi-ui-input-event-h.md#oh_arkui_uiinputevent_geteventtime)等接口，从基础事件中获取更多信息。应用根据获取的事件信息，在事件执行过程中实现差异化交互逻辑。

  ```cpp
  // 注册click事件
  nodeAPI->registerNodeEvent(button, NODE_ON_CLICK, 0, nullptr);
  // 设置组件事件的全局监听
  nodeAPI->registerNodeEventReceiver([](ArkUI_NodeEvent *event) {
      // 从组件事件中获取基础事件对象
      auto *inputEvent = OH_ArkUI_NodeEvent_GetInputEvent(event);
      // 从组件事件获取事件类型
      auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
      OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "eventInfo", "inputEvent = %{public}p", inputEvent);
      OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "eventInfo", "eventType = %{public}d", eventType);
      auto componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
      // 获取组件事件中的数字类型数据
      OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "eventInfo", "componentEvent = %{public}p",
                    componentEvent);
      // 获取触发该事件的组件对象
      auto nodeHandle = OH_ArkUI_NodeEvent_GetNodeHandle(event);
      OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "eventInfo", "nodeHandle = %{public}p", nodeHandle);
      // 根据eventType来区分事件类型，进行差异化处理，其他获取事件信息的接口也可类似方式来进行差异化的处理
      switch (eventType) {
      case NODE_ON_CLICK: {
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
          OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "eventInfoOfCommonEvent", "eventInfo = %{public}s",
                       eventInfo.c_str());
      }
      default: {
          break;
      }
      }
  });
  nodeAPI->unregisterNodeEventReceiver();
  nodeAPI->unregisterNodeEvent(button, NODE_ON_CLICK);
  ```


- 深浅色变更事件

  ArkUI开发框架在NDK接口提供了以组件为注册单位的系统深浅色变更事件，系统通过在深浅色变更时通知注册在组件上的回调，实现NDK侧的深浅色变更能力。

  > **说明：**
  > - 一个回调内可以自行设计多个组件的深浅色变更。
  > - 同一组件仅能注册一个系统深浅变更回调。
  > - 建议注册在页面内不会被销毁的节点，防止因节点销毁导致的回调失效。

    ```cpp
    struct ColorModeInfo {
        const char* lightMsg;
        const char* darkMsg;
    };

    //注册回调函数
    void onColorModeChange(ArkUI_SystemColorMode colorMode, void *userData)
    {
        ColorModeInfo* info = static_cast<ColorModeInfo*>(userData);
        if (colorMode == ARKUI_SYSTEM_COLOR_MODE_LIGHT) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "Light mode: ", info->lightMsg);
        } else if (colorMode == ARKUI_SYSTEM_COLOR_MODE_DARK) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "Manager", "Dark mode: ", info->darkMsg);
        }
    }

    ArkUI_NodeHandle testColorModeChange(ArkUI_NativeNodeAPI_1 *nodeAPI) {
        ArkUI_NodeHandle text = nodeAPI->createNode(ARKUI_NODE_TEXT);
        static ColorModeInfo info = {"现在是浅色模式", "现在是深色模式"};
        OH_ArkUI_RegisterSystemColorModeChangeEvent(text, &info, onColorModeChange);

        ArkUI_AttributeItem itemstring = {nullptr, 0, ("人生得意须尽欢")};
        nodeAPI->setAttribute(text, NODE_TEXT_CONTENT, &itemstring);

        return text;
    }
    ```

**完整示例：**

1. 在ArkUINode基类对象中实现通用事件注册逻辑。

   ```c
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
       explicit ArkUINode(ArkUI_NodeHandle handle) : ArkUIBaseNode(handle) {
           nativeModule_ = NativeModuleInstance::GetInstance()->GetNativeNodeAPI();
           // 事件触发时需要通过函数获取对应的事件对象，这边通过设置节点自定义数据将封装类指针保持在组件上，方便后续事件分发。
           nativeModule_->setUserData(handle_, this);
           // 注册节点监听事件接受器。
           nativeModule_->addNodeEventReceiver(handle_, ArkUINode::NodeEventReceiver);
       }
   
       ~ArkUINode() override {
           if (onClick_) {
               nativeModule_->unregisterNodeEvent(handle_, NODE_ON_CLICK);
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
       // 处理通用事件。
       void RegisterOnClick(const std::function<void()> &onClick) {
           assert(handle_);
           onClick_ = onClick;
           // 注册点击事件。
           nativeModule_->registerNodeEvent(handle_, NODE_ON_CLICK, 0, nullptr);
       }
   
       void RegisterOnTouch(const std::function<void(int32_t type, float x, float y)> &onTouch) {
           assert(handle_);
           onTouch_ = onTouch;
           // 注册触碰事件。
           nativeModule_->registerNodeEvent(handle_, NODE_TOUCH_EVENT, 0, nullptr);
       }
   
       void RegisterOnDisappear(const std::function<void()> &onDisappear) {
           assert(handle_);
           onDisappear_ = onDisappear;
           // 注册卸载事件。
           nativeModule_->registerNodeEvent(handle_, NODE_EVENT_ON_DISAPPEAR, 0, nullptr);
       }
   
       void RegisterOnAppear(const std::function<void()> &onAppear) {
           assert(handle_);
           onAppear_ = onAppear;
           // 注册挂载事件。
           nativeModule_->registerNodeEvent(handle_, NODE_EVENT_ON_APPEAR, 0, nullptr);
       }
   
   protected:
       // 事件监听器函数指针。
       static void NodeEventReceiver(ArkUI_NodeEvent *event) {
           // 获取事件发生的UI组件对象。
           auto nodeHandle = OH_ArkUI_NodeEvent_GetNodeHandle(event);
           // 获取保持在UI组件对象中的自定义数据，返回封装类指针。
           auto *node = reinterpret_cast<ArkUINode *>(
               NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->getUserData(nodeHandle));
           // 基于封装类实例对象处理事件。
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
               // 组件特有事件交给子类处理
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

2. 在ArkUIListNode对象中实现列表事件注册逻辑。
   ```c
   // ArkUIListNode.h
   // 列表封装类对象
   
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
   
       // 注册列表相关事件。
       void RegisterOnScrollIndex(const std::function<void(int32_t index)> &onScrollIndex) {
           assert(handle_);
           onScrollIndex_ = onScrollIndex;
           nativeModule_->registerNodeEvent(handle_, NODE_LIST_ON_SCROLL_INDEX, 0, nullptr);
       }
   
   protected:
      // 处理List相关事件。
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

3. 添加相关事件。
   ```c
   // TextListExample.h
   // 文本列表示例。
   
   #ifndef MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   #define MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   
   #include "ArkUIBaseNode.h"
   #include "ArkUIListItemNode.h"
   #include "ArkUIListNode.h"
   #include "ArkUITextNode.h"
   #include <hilog/log.h>
   
   namespace NativeModule {
   
   std::shared_ptr<ArkUIBaseNode> CreateTextListExample() {
       // 创建组件并挂载
       // 1：创建List组件。
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(1);
       list->SetPercentHeight(1);
       // 2：创建ListItem子组件并挂载到List上。
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
           // 列表项注册点击事件。
           auto onClick = [](ArkUI_NodeEvent *event) {
               // 从组件事件中获取基础事件对象
               auto *inputEvent = OH_ArkUI_NodeEvent_GetInputEvent(event);
               // 从组件事件获取事件类型
               auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
               OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "eventInfo", "inputEvent = %{public}p", inputEvent);
               OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "eventInfo", "eventType = %{public}d", eventType);
               auto componentEvent = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event);
               // 获取组件事件中的数字类型数据
               OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "eventInfo", "componentEvent = %{public}p",
                            componentEvent);
               // 获取触发该事件的组件对象
               auto nodeHandle = OH_ArkUI_NodeEvent_GetNodeHandle(event);
               OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "eventInfo", "nodeHandle = %{public}p", nodeHandle);
               // 根据eventType来区分事件类型，进行差异化处理，其他获取事件信息的接口也可类似方式来进行差异化的处理
               switch (eventType) {
               case NODE_ON_CLICK: {
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
                   OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "eventInfoOfCommonEvent",
                                "eventInfo = %{public}s", eventInfo.c_str());
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
       // 4: 注册卸载事件。
       list->RegisterOnDisappear([]() { OH_LOG_INFO(LOG_APP, "on list unmount from tree"); });
       return list;
   }
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_NORMALTEXTLISTEXAMPLE_H
   
   ```
