# 监听组件事件


NDK接口针对UI组件的事件，提供了监听函数的方式。首先，可使用[addNodeEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#addnodeeventreceiver)函数添加组件事件的监听器，该监听器会监听该组件上发生的所有事件，例如：点击事件、焦点事件。然后，可使用[registerNodeEvent](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#registernodeevent)函数声明组件的哪些事件需要监听，NDK接口支持的事件范围通过[ArkUI_NodeEventType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype)枚举值定义。


> **说明：**
> - 事件注册需要声明[addNodeEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#addnodeeventreceiver)监听器注册和[registerNodeEvent](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#registernodeevent)事件类型，监听器只能监听已声明的事件。
> 
> - 需要关注事件的反注册逻辑，如在组件销毁前调用[removeNodeEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#removenodeeventreceiver)移除事件监听器，[unregisterNodeEvent](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#unregisternodeevent)通知ArkUI框架已监听的事件不再需要监听。
> 
> - [addNodeEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#addnodeeventreceiver)可以添加多个函数指针，每个函数指针都会在对应事件触发时触发，对应的[removeNodeEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#removenodeeventreceiver)需要传递对应的函数指针用于移除监听。
> 
> - [registerNodeEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#registernodeeventreceiver)是全局监听函数，不同于[addNodeEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#addnodeeventreceiver)，[registerNodeEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#registernodeeventreceiver)能够监听所有Native组件的事件触发，但只能传递一个函数指针，多次调用使用最后一次的函数指针进行回调，释放时使用[ungisterNodeEventReceiver](../reference/apis-arkui/_ark_u_i___native_node_a_p_i__1.md#unregisternodeeventreceiver)进行释放。


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
  详细的事件类型请参考[ArkUI_NodeEventType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype)。

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
           listItem->RegisterOnClick([i]() { OH_LOG_INFO(LOG_APP, "on %{public}d list item click", i); });
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
