# 使用列表

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @rongShao-Z; @wind_-->
<!--Designer: @yangcan18-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->

ArkUI开发框架在NDK接口提供了列表组件，使用列表可以轻松高效地显示结构化、可滚动的信息。列表组件支持控制滚动位置、支持分组显示内容、支持使用[NodeAdapter](#nodeadapter介绍)实现懒加载以提升列表创建性能。

## 创建列表

参考[接入ArkTS页面](../ui/ndk-access-the-arkts-page.md)章节实现列表创建。 

## 监听滚动事件 

参考[添加事件监听](ndk-add-component-events.md)章节实现列表滚动事件监听。 

## 使用懒加载 

### NodeAdapter介绍 
NDK提供了NodeAdapter对象替代ArkTS侧的[LazyForEach](../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md)功能，用于按需生成子组件，NodeAdapter支持在[List](../reference/apis-arkui/arkui-ts/ts-container-list.md)/[ListItemGroup](../reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md)、[Grid](../reference/apis-arkui/arkui-ts/ts-container-grid.md)、[WaterFlow](../reference/apis-arkui/arkui-ts/ts-container-waterflow.md)、[Swiper](../reference/apis-arkui/arkui-ts/ts-container-swiper.md)组件中使用。

- 设置了NodeAdapter属性的节点，不支持直接通过[addChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addchild)等接口添加子组件。子组件完全由NodeAdapter管理，使用属性方法设置NodeAdapter时，会判断父组件是否已经存在子节点，如果父组件已经存在子节点，则设置NodeAdapter操作失败，返回错误码。

- NodeAdapter通过相关事件通知开发者按需生成组件，类似组件事件机制，开发者使用NodeAdapter时要通过[OH_ArkUI_NodeAdapter_RegisterEventReceiver](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeadapter_registereventreceiver)注册事件监听器，在监听器事件中处理逻辑，相关事件通过[ArkUI_NodeAdapterEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeadaptereventtype)定义。另外NodeAdapter不会主动释放不在屏幕内显示的组件对象，开发者需要在[NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeadaptereventtype)事件中进行组件对象的释放，或者进行缓存复用。下图展示了典型列表滑动场景下的事件触发机制：

  ![zh-cn_image_0000001949769409](figures/NodeAdapter-Overview.png)

<!--RP1-->
以下示例提供了懒加载适配器的实现方法，仅包含主要步骤，完整代码请参考[NdkCreateList](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList)。
<!--RP1End-->

### 实现懒加载适配器

使用ArkUIListItemAdapter类来管理懒加载适配器，在类的构造中创建NodeAdapter对象，并给NodeAdapter对象设置事件监听器，在类的析构函数中，销毁NodeAdapter对象。

ArkUIListItemAdapter类为自定义的通用模板类，模板参数类型可按业务数据和节点模型进行自定义。该模板对外开放“创建子组件”回调，用于按需创建并挂载每个ListItem对应的子组件。该模板还提供“复用ListItem”回调，用于在节点回收后执行状态重置与复用逻辑。

<!-- @[Lazy_loading_of_text_list](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListItemAdapter.h) -->

``` C
// ArkUIListItemAdapter.h
// 用于文本列表懒加载功能代码。

#ifndef MYAPPLICATION_ARKUILISTITEMADAPTER_H
#define MYAPPLICATION_ARKUILISTITEMADAPTER_H

#include <algorithm>
#include <arkui/native_node.h>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "ArkUIListItemNode.h"
#include "ArkUITextNode.h"
#include "NativeModule.h"

namespace NativeModule {

class IArkUIListItemAdapter {
public:
    virtual ~IArkUIListItemAdapter() = default;
    virtual ArkUI_NodeAdapterHandle GetHandle() const = 0;
};
template <typename ItemType> class ArkUIListItemAdapterT : public IArkUIListItemAdapter {
public:
    // 创建列表项节点的回调类型。
    using CreateChildCallback = std::function<std::shared_ptr<ArkUIListItemNode>(const ItemType &item, int32_t index)>;
    // 复用列表项节点时更新内容的回调类型。
    using ReuseListItemCallback =
        std::function<void(const std::shared_ptr<ArkUIListItemNode> &listItem, const ItemType &item, int32_t index)>;
    // 生成节点唯一标识的回调类型。
    using NodeIdCallback = std::function<int64_t(const ItemType &item, int32_t index)>;

    // 创建NodeAdapter并初始化数据及各类回调。
    explicit ArkUIListItemAdapterT(std::vector<ItemType> data, CreateChildCallback createChildCallback,
                                   ReuseListItemCallback reuseListItemCallback, NodeIdCallback nodeIdCallback = nullptr)
        : handle_(OH_ArkUI_NodeAdapter_Create()), data_(std::move(data)),
          createChildCallback_(std::move(createChildCallback)),
          reuseListItemCallback_(std::move(reuseListItemCallback)), nodeIdCallback_(std::move(nodeIdCallback)) {
        // 设置懒加载数据。
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
        // 设置懒加载回调事件。
        OH_ArkUI_NodeAdapter_RegisterEventReceiver(handle_, this, OnStaticAdapterEvent);
    }

    ~ArkUIListItemAdapterT() override
    {
        // 释放创建的组件。
        while (!cachedItems_.empty()) {
            cachedItems_.pop();
        }
        items_.clear();
        // 释放Adapter相关资源。
        OH_ArkUI_NodeAdapter_UnregisterEventReceiver(handle_);
        OH_ArkUI_NodeAdapter_Dispose(handle_);
    }

    ArkUI_NodeAdapterHandle GetHandle() const override { return handle_; }

    const std::vector<ItemType> &GetData() const { return data_; }

    void SetData(std::vector<ItemType> data)
    {
        data_ = std::move(data);
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
        OH_ArkUI_NodeAdapter_ReloadAllItems(handle_);
    }

    void SetNodeIdCallback(NodeIdCallback callback) { nodeIdCallback_ = std::move(callback); }

    void RemoveItem(size_t index)
    {
        // 删除第index个数据。
        if (index >= data_.size()) {
            return;
        }
        data_.erase(data_.begin() + static_cast<std::ptrdiff_t>(index));
        // 如果index会导致可视区域元素发生可见性变化，则会回调NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER事件删除元素，
        // 根据是否有新增元素回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID和NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件。
        OH_ArkUI_NodeAdapter_RemoveItem(handle_, index, 1);
        // 更新新的数量。
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
    }

    void InsertItem(int32_t index, const ItemType &value)
    {
        int32_t safeIndex = std::max(0, std::min(index, static_cast<int32_t>(data_.size())));
        data_.insert(data_.begin() + safeIndex, value);
        // 如果index会导致可视区域元素发生可见性变化，则会回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID和NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件，
        // 根据是否有删除元素回调NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER事件。
        OH_ArkUI_NodeAdapter_InsertItem(handle_, safeIndex, 1);
        // 更新新的数量。
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
    }

    void MoveItem(int32_t oldIndex, int32_t newIndex)
    {
        if (!IsValidIndex(oldIndex) || !IsValidIndex(newIndex) || oldIndex == newIndex) {
            return;
        }
        auto temp = data_[oldIndex];
        data_.insert(data_.begin() + newIndex, temp);
        int32_t removeIndex = oldIndex;
        if (newIndex < oldIndex) {
            removeIndex += 1;
        }
        data_.erase(data_.begin() + removeIndex);
        // 移到位置如果未发生可视区域内元素的可见性变化，则不回调事件，反之根据新增和删除场景回调对应的事件。
        OH_ArkUI_NodeAdapter_MoveItem(handle_, oldIndex, newIndex);
    }

    void ReloadItem(int32_t index, const ItemType &value)
    {
        if (!IsValidIndex(index)) {
            return;
        }
        data_[index] = value;
        // 如果index位于可视区域内，先回调NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER删除老元素，
        // 再回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID和NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件。
        OH_ArkUI_NodeAdapter_ReloadItem(handle_, index, 1);
    }

    void ReloadAllItem()
    {
        // 全部重新加载场景下，会回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID接口获取新的组件ID，
        // 根据新的组件ID进行对比，ID不发生变化的进行复用，
        // 针对新增ID的元素，调用NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件创建新的组件，
        // 然后判断老数据中遗留的未使用ID，调用NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER删除老元素。
        OH_ArkUI_NodeAdapter_ReloadAllItems(handle_);
    }

private:
    struct ItemEntry {
        std::shared_ptr<ArkUIListItemNode> listItem = nullptr;
    };

    static void OnStaticAdapterEvent(ArkUI_NodeAdapterEvent *event)
    {
        // 获取实例对象，回调实例事件。
        auto *itemAdapter = reinterpret_cast<ArkUIListItemAdapterT *>(OH_ArkUI_NodeAdapterEvent_GetUserData(event));
        if (itemAdapter != nullptr) {
            itemAdapter->OnAdapterEvent(event);
        }
    }

    void OnAdapterEvent(ArkUI_NodeAdapterEvent *event)
    {
        // 获取事件类型
        auto type = OH_ArkUI_NodeAdapterEvent_GetType(event);
        switch (type) {
            // Adapter需要添加新元素时获取新元素的唯一标识符
            case NODE_ADAPTER_EVENT_ON_GET_NODE_ID:
                OnNewItemIdCreated(event);
                break;
            // Adapter需要添加新元素时获取新元素的内容
            case NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER:
                OnNewItemAttached(event);
                break;
            // Adapter将元素移除
            case NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER:
                OnItemDetached(event);
                break;
            default:
                break;
        }
    }

    // 分配ID给需要显示的Item，用于ReloadAllItems场景的元素diff。
    void OnNewItemIdCreated(ArkUI_NodeAdapterEvent *event)
    {
        auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
        if (!IsValidIndex(index)) {
            return;
        }
        int64_t id = nodeIdCallback_ ? nodeIdCallback_(data_[index], index) : static_cast<int64_t>(index);
        OH_ArkUI_NodeAdapterEvent_SetNodeId(event, id);
    }

    // 需要新的Item显示在可见区域。
    void OnNewItemAttached(ArkUI_NodeAdapterEvent *event)
    {
        auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
        if (!IsValidIndex(index)) {
            return;
        }

        ItemEntry itemEntry;
        if (!cachedItems_.empty()) {
            // 使用并更新回收复用的缓存。
            itemEntry = cachedItems_.top();
            // 释放缓存池的引用。
            cachedItems_.pop();
            reuseListItemCallback_(itemEntry.listItem, data_[index], index);
        } else {
            // 创建新的元素。
            itemEntry.listItem = createChildCallback_(data_[index], index);
        }
        if (itemEntry.listItem == nullptr) {
            itemEntry.listItem = std::make_shared<ArkUIListItemNode>();
        }

        auto handle = itemEntry.listItem->GetHandle();
        items_[handle] = itemEntry;
        // 设置需要展示的元素。
        OH_ArkUI_NodeAdapterEvent_SetItem(event, handle);
    }
    // Item从可见区域移除。
    void OnItemDetached(ArkUI_NodeAdapterEvent *event)
    {
        auto item = OH_ArkUI_NodeAdapterEvent_GetRemovedNode(event);
        auto iter = items_.find(item);
        if (iter != items_.end()) {
            // 放置到缓存池中进行回收复用。
            cachedItems_.push(iter->second);
            items_.erase(iter);
        }
    }

    bool IsValidIndex(int32_t index) const { return index >= 0 && index < static_cast<int32_t>(data_.size()); }

    // NodeAdapter实例句柄。
    ArkUI_NodeAdapterHandle handle_ = nullptr;
    // 列表数据源。
    std::vector<ItemType> data_;
    // 创建列表项节点回调。
    CreateChildCallback createChildCallback_ = nullptr;
    // 复用列表项节点回调。
    ReuseListItemCallback reuseListItemCallback_ = nullptr;
    // 节点ID生成回调。
    NodeIdCallback nodeIdCallback_ = nullptr;
    // 管理NodeAdapter生成的元素。
    std::unordered_map<ArkUI_NodeHandle, ItemEntry> items_;

    // 管理回收复用组件池。
    std::stack<ItemEntry> cachedItems_;
};
} // namespace NativeModule

#endif // MYAPPLICATION_ARKUILISTITEMADAPTER_H
```

### 在列表中应用懒加载适配器 

1. 在ArkUIListNode中添加SetLazyAdapter函数，给列表节点设置[NODE_LIST_NODE_ADAPTER](../reference/apis-arkui/capi-native-node-h-nodeattributetype-scrollablecontainer.md#node_list_node_adapter)属性，并将NodeAdapter作为属性入参传入。
   <!-- @[List_encapsulated_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListNode.h) -->
   
   ``` C
   // ArkUIListNode.h
   // 提供列表组件的封装。
   #ifndef MYAPPLICATION_ARKUILISTNODE_H
   #define MYAPPLICATION_ARKUILISTNODE_H
   
   #include "ArkUINode.h"
   #include "ArkUIListItemAdapter.h"
   namespace NativeModule {
   class ArkUIListNode : public ArkUINode {
   public:
       ArkUIListNode() // 创建ArkUI的列表组件。
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_LIST)) {}
   
       ~ArkUIListNode() override
       {
           if (nativeModule_) {
               nativeModule_->unregisterNodeEvent(handle_, NODE_LIST_ON_SCROLL_INDEX);
               if (adapter_) {
               // 析构的时候卸载adapter下的UI组件。
                   nativeModule_->resetAttribute(handle_, NODE_LIST_NODE_ADAPTER);
                   adapter_.reset();
               }
           }
       }
       // List组件的属性接口封装。
       void SetScrollBarState(bool isShow)
       {
           ArkUI_ScrollBarDisplayMode displayMode =
               isShow ? ARKUI_SCROLL_BAR_DISPLAY_MODE_ON : ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF;
           ArkUI_NumberValue value[] = {{.i32 = displayMode}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_SCROLL_BAR_DISPLAY_MODE, &item);
       }
   
       void RegisterOnScrollIndex(const std::function<void(int32_t index)> &onScrollIndex)
       {
           onScrollIndex_ = onScrollIndex;
           nativeModule_->registerNodeEvent(handle_, NODE_LIST_ON_SCROLL_INDEX, 0, nullptr);
       }
       // 引入懒加载模块。
       void SetLazyAdapter(const std::shared_ptr<IArkUIListItemAdapter> &adapter)
       {
           if (!adapter) {
               nativeModule_->resetAttribute(handle_, NODE_LIST_NODE_ADAPTER);
               adapter_.reset();
               return;
           }
           ArkUI_AttributeItem item{nullptr, 0, nullptr, adapter->GetHandle()};
           nativeModule_->setAttribute(handle_, NODE_LIST_NODE_ADAPTER, &item);
           adapter_ = adapter;
       }
       // ...
   protected:
       void OnNodeEvent(ArkUI_NodeEvent *event) override
       {
           auto eventType = OH_ArkUI_NodeEvent_GetEventType(event);
           switch (eventType) {
               case NODE_LIST_ON_SCROLL_INDEX: {
                   auto index = OH_ArkUI_NodeEvent_GetNodeComponentEvent(event)->data[0];
                   if (onScrollIndex_) {
                       onScrollIndex_(index.i32);
                   }
                   break;
               }
               default: {
                   break;
               }
           }
       }
   
   private:
       std::function<void(int32_t index)> onScrollIndex_;
   
       std::shared_ptr<IArkUIListItemAdapter> adapter_;
   };
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUILISTNODE_H
   ```

2. 创建List使用懒加载的示例代码，调用List节点的SetLazyAdapter接口设置懒加载适配器。
   <!-- @[Grouped_List_Interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/LazyTextListExample1.h) -->
   
   ``` C
   // LazyTextListExample
   // 懒加载列表示例代码。
   
   #ifndef MYAPPLICATION_LAZYTEXTLISTEXAMPLE1_H
   #define MYAPPLICATION_LAZYTEXTLISTEXAMPLE1_H
   
   #include "ArkUIBaseNode.h"
   #include "ArkUIListNode.h"
   #include "ArkUITextNode.h"
   
   #include <algorithm>
   #include <memory>
   #include <string>
   #include <vector>
   
   namespace NativeModule {
   // ...
   std::shared_ptr<ArkUIBaseNode> CreateLazyTextListExample1()
   {
       // 创建组件并挂载。
       // 1：创建List组件。
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(1); // 1：宽度
       list->SetPercentHeight(1); // 1：高度
       auto data = BuildSampleData();
   
       auto adapterWeakHolder = std::make_shared<std::weak_ptr<StringAdapter>>();
       // 2：创建ListItem及其子组件的回调。
       auto createChildCallback = [adapterWeakHolder](const std::string &item,
                                                      int32_t index) -> std::shared_ptr<ArkUIListItemNode> {
           (void)index;
           return BuildListItemNode(item, adapterWeakHolder);
       };
       // 3：复用ListItem的回调。
       auto reuseListItemCallback = [adapterWeakHolder](const std::shared_ptr<ArkUIListItemNode> &listItem,
                                                        const std::string &item, int32_t index) {
           (void)index;
           ReuseListItemNode(listItem, item, adapterWeakHolder);
       };
   
       auto adapter = std::make_shared<StringAdapter>(data, createChildCallback, reuseListItemCallback);
       *adapterWeakHolder = adapter;
       // 4：创建ListItem懒加载组件并挂载到List中。
       list->SetLazyAdapter(adapter);
       return list;
   }
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_LAZYTEXTLISTEXAMPLE1_H
   ```

3. 在NativeEntry.cpp中调用List使用懒加载的示例代码。
   <!-- @[Interface_entrance_mounting_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/NativeEntry.cpp) -->
   
   ``` C++
   // NDK接口入口挂载文件。
   
   #include "NativeEntry.h"
   
   #include "LazyTextListExample.h"
   #include "LazyTextListExample1.h"
   
   #include <arkui/native_node_napi.h>
   #include <arkui/native_type.h>
   #include <js_native_api.h>
   #include <algorithm>
   #include <memory>
   #include <string>
   #include <uv.h>
   #include <vector>
   
   namespace NativeModule {
   
   // ...
   
   napi_value CreateNativeRoot(napi_env env, napi_callback_info info)
   {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       // 获取NodeContent。
       ArkUI_NodeContentHandle contentHandle;
       OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
       NativeEntry::GetInstance()->SetContentHandle(contentHandle);
   
       // 创建懒加载文本列表。
       auto node = CreateLazyTextListExample();
   
       // 保存Native侧对象到管理类中，维护生命周期。
       NativeEntry::GetInstance()->SetRootNode(node);
       return nullptr;
   }
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info)
   {
       // 从管理类中释放Native侧对象。
       NativeEntry::GetInstance()->DisposeRootNode();
       return nullptr;
   }
   
   } // namespace NativeModule
   ```
## 控制列表滚动位置

1. 控制列表滚动到指定偏移量位置。
   <!-- @[ScrollTo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListNode.h) -->
   
   ``` C
   // ArkUIListNode.h
   // 提供列表组件的封装。
   // ...
   class ArkUIListNode : public ArkUINode {
   public:
       // ...
       void ScrollTo(float offset)
       {
           ArkUI_NumberValue value[] = {{.f32 = 0}, {.f32 = offset}, {.f32 = 0}};
           ArkUI_AttributeItem item = {.value = value, .size = 3};
           nativeModule_->setAttribute(handle_, NODE_SCROLL_OFFSET, &item);
       }
       // ...
   };
   ```
2. 控制列表滚动到指定元素。 
   <!-- @[ScrollToIndex](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListNode.h) -->
   
   ``` C
   // ArkUIListNode.h
   // 提供列表组件的封装。
   // ...
   class ArkUIListNode : public ArkUINode {
   public:
       // ...
       void ScrollToIndex(int32_t index)
       {
           ArkUI_NumberValue value[] = {{.i32 = index}};
           ArkUI_AttributeItem item = {.value = value, .size = 1};
           nativeModule_->setAttribute(handle_, NODE_LIST_SCROLL_TO_INDEX, &item);
       }
       // ...
   };
   ```

3. 控制列表滚动指定偏移量。
   <!-- @[ScrollBy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListNode.h) -->
   
   ``` C
   // ArkUIListNode.h
   // 提供列表组件的封装。
   // ...
   class ArkUIListNode : public ArkUINode {
   public:
       // ...
       void ScrollBy(float offset)
       {
           ArkUI_NumberValue value[] = {{.f32 = 0}, {.f32 = offset}};
           ArkUI_AttributeItem item = {.value = value, .size = 2};
           nativeModule_->setAttribute(handle_, NODE_SCROLL_BY, &item);
       }
       // ...
   };
   ```
## ListItem横划删除 

1. [ListItem](../reference/apis-arkui/arkui-ts/ts-container-listitem.md)设置[NODE_LIST_ITEM_SWIPE_ACTION](../reference/apis-arkui/capi-native-node-h-nodeattributetype-scrollablecontainer.md#node_list_item_swipe_action)属性，将[ArkUI_ListItemSwipeActionOption](../reference/apis-arkui/capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)对象作为属性参数传入。
   <!-- @[Provide_wrapper_class_list_items](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListItemNode.h) -->
   
   ``` C
   // ArkUIListItemNode.h
   // 提供列表项的封装类。
   #ifndef MYAPPLICATION_ARKUILISTITEMNODE_H
   #define MYAPPLICATION_ARKUILISTITEMNODE_H
   #include "ArkUINode.h"
   namespace NativeModule {
   class ArkUIListItemNode : public ArkUINode {
   public:
       ArkUIListItemNode()
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_LIST_ITEM)) {}
       ~ArkUIListItemNode() override
       {
           // 销毁ListItemSwipeActionOption实例
           if (swipeAction_) {
               OH_ArkUI_ListItemSwipeActionOption_Dispose(swipeAction_);
           }
           // 销毁ListItemSwipeActionItem实例
           if (swipeItem_) {
               OH_ArkUI_ListItemSwipeActionItem_Dispose(swipeItem_);
           }
       }
       void SetSwiperAction(std::shared_ptr<ArkUINode> node)
       {
           swipeContent_ = node;
           // 创建ListItemSwipeActionItem接口设置的配置项
           swipeItem_ = OH_ArkUI_ListItemSwipeActionItem_Create();
           // 设置ListItemSwipeActionItem的布局内容
           OH_ArkUI_ListItemSwipeActionItem_SetContent(swipeItem_, node->GetHandle());
           // 创建ListItemSwipeActionOption接口设置的配置项
           swipeAction_ = OH_ArkUI_ListItemSwipeActionOption_Create();
           // 设置ListItemSwipeActionItem的右侧（垂直布局）或下方（横向布局）布局内容
           OH_ArkUI_ListItemSwipeActionOption_SetEnd(swipeAction_, swipeItem_);
           ArkUI_AttributeItem Item = {.object = swipeAction_};
           nativeModule_->setAttribute(handle_, NODE_LIST_ITEM_SWIPE_ACTION, &Item);
       }
       std::shared_ptr<ArkUINode> GetSwipeContent() const { return swipeContent_; }
   
   private:
       ArkUI_ListItemSwipeActionOption *swipeAction_ = nullptr;
       ArkUI_ListItemSwipeActionItem *swipeItem_ = nullptr;
       std::shared_ptr<ArkUINode> swipeContent_ = nullptr;
   };
   } // namespace NativeModule
   #endif // MYAPPLICATION_ARKUILISTITEMNODE_H
   ```
2. 设置创建ListItem和复用ListItem的回调函数。当创建[ListItem](../reference/apis-arkui/arkui-ts/ts-container-listitem.md)时，创建ListItem的划出组件，并绑定点击事件，在点击事件中执行删除数据源操作。ListItem复用时，更新划出组件的绑定事件。
    <!-- @[SetCallBack](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/LazyTextListExample1.h) -->

   ``` C
   // LazyTextListExample
   // 懒加载列表示例代码。

   #ifndef MYAPPLICATION_LAZYTEXTLISTEXAMPLE1_H
   #define MYAPPLICATION_LAZYTEXTLISTEXAMPLE1_H

   #include "ArkUIBaseNode.h"
   #include "ArkUIListNode.h"
   #include "ArkUITextNode.h"

   #include <algorithm>
   #include <memory>
   #include <string>
   #include <vector>

   namespace NativeModule {
   using StringAdapter = ArkUIListItemAdapterT<std::string>;
   using AdapterWeakHolder = std::shared_ptr<std::weak_ptr<StringAdapter>>;

   std::vector<std::string> BuildSampleData()
   {
       std::vector<std::string> data;
       data.reserve(1000); // 每个分组预分配1000条数据空间。
       for (int32_t i = 0; i < 1000; i++) { // 1000：1000条数据空间
           data.emplace_back(std::to_string(i));
       }
       return data;
   }

   void RegisterDeleteClick(const std::shared_ptr<ArkUINode> &target, const AdapterWeakHolder &adapterWeakHolder,
       const std::string &item)
   {
       // 为删除区域注册点击事件：通过弱引用获取适配器，避免回调长期持有强引用。
       target->RegisterOnClick([adapterWeakHolder, item](ArkUI_NodeEvent *event) {
           (void)event;
           auto adapter = adapterWeakHolder->lock();
           if (!adapter) {
               return;
           }
           // 基于当前数据查找当前 item，确保复用场景下删除的是最新绑定项。
           const auto &currentData = adapter->GetData();
           auto it = std::find(currentData.begin(), currentData.end(), item);
           if (it != currentData.end()) {
               // RemoveItem 需要索引，这里把迭代器位置转换为 size_t。
               auto removeIndex = static_cast<size_t>(std::distance(currentData.begin(), it));
               adapter->RemoveItem(removeIndex);
           }
       });
   }

   std::shared_ptr<ArkUIListItemNode> BuildListItemNode(const std::string &item,
       const AdapterWeakHolder &adapterWeakHolder)
   {
       // 构建一个 ListItem：主文本区域 + 右滑删除操作区。
       auto listItem = std::make_shared<ArkUIListItemNode>();

       // 主内容文本，展示当前数据项。
       auto textNode = std::make_shared<ArkUITextNode>();
       textNode->SetTextContent(item);
       // ...
       listItem->AddChild(textNode);

       // 右滑动作区文本，点击后触发删除当前 item。
       auto swipeNode = std::make_shared<ArkUITextNode>();
       swipeNode->SetTextContent("del");
       // ...
       RegisterDeleteClick(swipeNode, adapterWeakHolder, item);
       listItem->SetSwiperAction(swipeNode);
       return listItem;
   }

   void ReuseListItemNode(const std::shared_ptr<ArkUIListItemNode> &listItem, const std::string &item,
       const AdapterWeakHolder &adapterWeakHolder)
   {
       auto &children = listItem->GetChildren();
       if (children.empty()) {
           return;
       }
       auto textNode = std::dynamic_pointer_cast<ArkUITextNode>(children.front());
       if (textNode) {
           textNode->SetTextContent(item);
           textNode->SetBackgroundColor(0xFFfffacd);
       }
       auto swipeContent = listItem->GetSwipeContent();
       if (swipeContent) {
           RegisterDeleteClick(swipeContent, adapterWeakHolder, item);
       }
   }

   // ...

   } // namespace NativeModule

   #endif // MYAPPLICATION_LAZYTEXTLISTEXAMPLE1_H
   ```

3. 添加新的ListItem时，优先复用已缓存的[ListItem](../reference/apis-arkui/arkui-ts/ts-container-listitem.md)实例，并更新其内容；若无可用缓存，则创建新的ListItem。当回调返回空时，创建一个默认的ListItem作为兜底方案。最后，通过[OH_ArkUI_NodeAdapterEvent_SetItem](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeadapterevent_setitem)接口将生成的节点句柄回填至事件中，完成绑定。
   <!-- @[Item_adapter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListItemAdapter.h) -->
   
   ``` C
   // ArkUIListItemAdapter.h
   // ...
   template <typename ItemType> class ArkUIListItemAdapterT : public IArkUIListItemAdapter {
       // ...
       // 需要新的Item显示在可见区域。
       void OnNewItemAttached(ArkUI_NodeAdapterEvent *event)
       {
           auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
           if (!IsValidIndex(index)) {
               return;
           }
   
           ItemEntry itemEntry;
           if (!cachedItems_.empty()) {
               // 使用并更新回收复用的缓存。
               itemEntry = cachedItems_.top();
               // 释放缓存池的引用。
               cachedItems_.pop();
               reuseListItemCallback_(itemEntry.listItem, data_[index], index);
           } else {
               // 创建新的元素。
               itemEntry.listItem = createChildCallback_(data_[index], index);
           }
           if (itemEntry.listItem == nullptr) {
               itemEntry.listItem = std::make_shared<ArkUIListItemNode>();
           }
   
           auto handle = itemEntry.listItem->GetHandle();
           items_[handle] = itemEntry;
           // 设置需要展示的元素。
           OH_ArkUI_NodeAdapterEvent_SetItem(event, handle);
       }
       // ...
   };
   ```
4. ArkUIListItemAdapter中新增RemoveItem，用于删除数据源并且调用[OH_ArkUI_NodeAdapter_RemoveItem](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeadapter_removeitem)接口通知框架刷新UI。
   <!-- @[Remove_Item](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListItemAdapter.h) -->
   
   ``` C
   // ArkUIListItemAdapter.h
   // ...
   template <typename ItemType> class ArkUIListItemAdapterT : public IArkUIListItemAdapter {
       // ...
       void RemoveItem(size_t index)
       {
           // 删除第index个数据。
           if (index >= data_.size()) {
               return;
           }
           data_.erase(data_.begin() + static_cast<std::ptrdiff_t>(index));
           // 如果index会导致可视区域元素发生可见性变化，则会回调NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER事件删除元素，
           // 根据是否有新增元素回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID和NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件。
           OH_ArkUI_NodeAdapter_RemoveItem(handle_, index, 1);
           // 更新新的数量。
           OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
       }
   
       // ...
   };
   ```
## 使用分组列表 
1. 分组列表使用[ListItemGroup](../reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md)组件实现，ListItemGroup支持添加[header](../reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions对象说明)、[footer](../reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions对象说明)设置函数，支持使用懒加载。
   <!-- @[Use_grouped_lists](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListItemGroupNode.h) -->
   
   ``` C
   // ArkUIListItemGroupNode.h
   
   #ifndef MYAPPLICATION_ARKUILISTITEMGROUPNODE_H
   #define MYAPPLICATION_ARKUILISTITEMGROUPNODE_H
   
   #include "ArkUINode.h"
   #include "ArkUIListItemAdapter.h"
   
   namespace NativeModule {
   
   class ArkUIListItemGroupNode : public ArkUINode {
   public:
       ArkUIListItemGroupNode()
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_LIST_ITEM_GROUP))
       {
       }
   
       void SetHeader(const std::shared_ptr<ArkUINode> &node)
       {
           if (node) {
               // 创建一个属性项，把节点的句柄放进去，并设置头部
               ArkUI_AttributeItem item = {.object = node->GetHandle()};
               nativeModule_->setAttribute(handle_, NODE_LIST_ITEM_GROUP_SET_HEADER, &item);
               header_ = node;
           } else {
               // 如果传入的是空指针（nullptr），说明要移除已有的头部
               nativeModule_->resetAttribute(handle_, NODE_LIST_ITEM_GROUP_SET_HEADER);
               header_.reset();
           }
       }
   
       void SetFooter(const std::shared_ptr<ArkUINode> &node)
       {
           if (node) {
               // 创建一个属性项，把节点的句柄放进去，并设置尾部
               ArkUI_AttributeItem item = {.object = node->GetHandle()};
               nativeModule_->setAttribute(handle_, NODE_LIST_ITEM_GROUP_SET_FOOTER, &item);
               footer_ = node;
           } else {
               // 如果传入的是空指针（nullptr），说明要移除已有的尾部
               nativeModule_->resetAttribute(handle_, NODE_LIST_ITEM_GROUP_SET_FOOTER);
               footer_.reset();
           }
       }
   
       std::shared_ptr<ArkUINode> GetHeader() const
       {
           return header_;
       }
   
       std::shared_ptr<ArkUINode> GetFooter() const
       {
           return footer_;
       }
   
       // 引入懒加载模块。
       void SetLazyAdapter(const std::shared_ptr<IArkUIListItemAdapter> &adapter)
       {
           if (!adapter) {
               nativeModule_->resetAttribute(handle_, NODE_LIST_ITEM_GROUP_NODE_ADAPTER);
               adapter_.reset();
               return;
           }
           ArkUI_AttributeItem item{nullptr, 0, nullptr, adapter->GetHandle()};
           nativeModule_->setAttribute(handle_, NODE_LIST_ITEM_GROUP_NODE_ADAPTER, &item);
           adapter_ = adapter;
       }
   private:
       std::shared_ptr<ArkUINode> header_;
       std::shared_ptr<ArkUINode> footer_;
       std::shared_ptr<IArkUIListItemAdapter> adapter_;
   };
   }
   #endif // MYAPPLICATION_ARKUILISTITEMGROUPNODE_H
   ```
2. [List](../reference/apis-arkui/arkui-ts/ts-container-list.md)组件设置吸顶。
   <!-- @[SetSticky](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListNode.h) -->
   
   ``` C
   // ArkUIListNode.h
   // 提供列表组件的封装。
   // ...
   class ArkUIListNode : public ArkUINode {
       // ...
       void SetSticky(ArkUI_StickyStyle style)
       {
           ArkUI_NumberValue value[] = {{.i32 = style}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_LIST_STICKY, &item);
       }
       // ...
   };
   ```
3. [List](../reference/apis-arkui/arkui-ts/ts-container-list.md)组件下使用[ListItemGroup](../reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md)实现分组列表界面。
   <!-- @[Grouped_List](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/LazyTextListExample.h) -->
   
   ``` C
   // LazyTextListExample.h
   // 懒加载列表示例代码。
   
   #ifndef MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H
   #define MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H
   
   #include "ArkUIBaseNode.h"
   #include "ArkUIListItemAdapter.h"
   #include "ArkUIListItemGroupNode.h"
   #include "ArkUIListNode.h"
   #include "ArkUITextNode.h"
   
   #include <string>
   #include <vector>
   
   namespace NativeModule {
   // ...
   std::shared_ptr<ArkUIListItemGroupNode> CreateListItemGroup()
   {
       auto header = std::make_shared<ArkUITextNode>();
       header->SetTextContent("header");
       header->SetFontSize(16); // 16：字体大小
       header->SetPercentWidth(1); // 1：宽度
       header->SetHeight(50); // 50：高度
       header->SetBackgroundColor(0xFFDCDCDC);
       header->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER);
   
       auto listItemGroup = std::make_shared<ArkUIListItemGroupNode>();
       listItemGroup->SetHeader(header);
   
       auto groupData = BuildGroupData();
       auto createChildCallback = [](const std::string &item, int32_t index) -> std::shared_ptr<ArkUIListItemNode> {
           return BuildListItemNode(item, index);
       };
       auto reuseListItemCallback = [](const std::shared_ptr<ArkUIListItemNode> &listItem, const std::string &item,
                                       int32_t index) {
           ReuseListItemNode(listItem, item, index);
       };
   
       auto adapter = std::make_shared<ArkUIListItemAdapterT<std::string>>(groupData, createChildCallback,
                                                                            reuseListItemCallback);
       listItemGroup->SetLazyAdapter(adapter);
       return listItemGroup;
   }
   
   std::shared_ptr<ArkUIBaseNode> CreateLazyTextListExample()
   {
       // 创建组件并挂载。
       // 1：创建List组件。
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(1); // 1：宽度
       list->SetPercentHeight(1); // 1：高度
       list->SetSticky(ARKUI_STICKY_STYLE_BOTH);
   
       // 2：创建ListItemGroup并挂载到List上。
       for (int32_t i = 0; i < 3; i++) { // 3：分组数
           list->AddChild(CreateListItemGroup());
       }
       return list;
   }
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H
   ```

