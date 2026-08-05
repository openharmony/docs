# Implementing a List Layout

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @rongShao-Z; @wind_-->
<!--Designer: @yangcan18-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->

The ArkUI development framework provides list components through NDK APIs, enabling efficient display of structured, scrollable content. List components allow you to control the scroll position, group display content, and use [NodeAdapter](#nodeadapter-overview) for lazy loading to improve list creation performance.

## Creating a List

For details about how to create a list, see [Integrating with ArkTS Pages](../ui/ndk-access-the-arkts-page.md).

## Listening for Scroll Events

For details about how to listen for list scrolling events, see [Adding an Event Listener](ndk-add-component-events.md).

## Implementing Lazy Loading

### NodeAdapter Overview
The NDK provides the **NodeAdapter** object as an alternative to [LazyForEach](../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md) in ArkTS for on-demand generation of child components. NodeAdapter works with [List](../reference/apis-arkui/arkui-ts/ts-container-list.md)/[ListItemGroup](../reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md), [Grid](../reference/apis-arkui/arkui-ts/ts-container-grid.md), [WaterFlow](../reference/apis-arkui/arkui-ts/ts-container-waterflow.md), and [Swiper](../reference/apis-arkui/arkui-ts/ts-container-swiper.md) components.

- Child components cannot be added to a node where **NodeAdapter** is set by using APIs such as [addChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addchild). Child components are managed entirely by **NodeAdapter**. If a parent component already has child nodes, setting **NodeAdapter** will fail and return an error code.

- **NodeAdapter** notifies you of on-demand generation of components through relevant events. Similar to the component event mechanism, you need to register an event listener via [OH_ArkUI_NodeAdapter_RegisterEventReceiver](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeadapter_registereventreceiver) when using **NodeAdapter** and handle logic in the listener events. Relevant events are defined by [ArkUI_NodeAdapterEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeadaptereventtype). **NodeAdapter** does not actively release off-screen component objects; you must release or cache and reuse component objects in the [NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeadaptereventtype) event. The following image illustrates the event triggering mechanism in a typical list scrolling scenario.

  ![en-us_image_0000001949769409](figures/NodeAdapter-Overview.png)

<!--RP1-->
This example demonstrates how to implement an adapter for lazy loading.
<!--RP1End-->

### Implementing a Lazy Loading Adapter

Use the **ArkUIListItemAdapter** class to manage the lazy loading adapter. Create a **NodeAdapter** object in the class constructor and set an event listener for the **NodeAdapter** object. In the class destructor, destroy the **NodeAdapter** object.

The **ArkUIListItemAdapter** class is a custom general template class. The template parameter types can be customized based on the service data and node model. This template provides the child component creation callback for external use, which is used to create and mount the child components corresponding to each **ListItem** as required. This template also provides the callback for reusing list items, which is used to reset the status and reuse logic after nodes are recycled.

<!-- @[Lazy_loading_of_text_list](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListItemAdapter.h) -->

``` C
// ArkUIListItemAdapter.h
// Code for lazy loading functionality in a text list.

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
    // Callback type for creating a list item node.
    using CreateChildCallback = std::function<std::shared_ptr<ArkUIListItemNode>(const ItemType &item, int32_t index)>;
    // Callback type for updating the content when a list item node is reused.
    using ReuseListItemCallback =
        std::function<void(const std::shared_ptr<ArkUIListItemNode> &listItem, const ItemType &item, int32_t index)>;
    // Callback type for generating a unique node ID.
    using NodeIdCallback = std::function<int64_t(const ItemType &item, int32_t index)>;

    // Create a NodeAdapter and initialize data and callbacks.
    explicit ArkUIListItemAdapterT(std::vector<ItemType> data, CreateChildCallback createChildCallback,
                                   ReuseListItemCallback reuseListItemCallback, NodeIdCallback nodeIdCallback = nullptr)
        : handle_(OH_ArkUI_NodeAdapter_Create()), data_(std::move(data)),
          createChildCallback_(std::move(createChildCallback)),
          reuseListItemCallback_(std::move(reuseListItemCallback)), nodeIdCallback_(std::move(nodeIdCallback)) {
        // Set lazy loading data.
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
        // Register the event receiver for lazy loading.
        OH_ArkUI_NodeAdapter_RegisterEventReceiver(handle_, this, OnStaticAdapterEvent);
    }

    ~ArkUIListItemAdapterT() override
    {
        // Release created components.
        while (!cachedItems_.empty()) {
            cachedItems_.pop();
        }
        items_.clear();
        // Release adapter resources.
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
        // Remove the item at the specified index.
        if (index >= data_.size()) {
            return;
        }
        data_.erase(data_.begin() + static_cast<std::ptrdiff_t>(index));
        // If the index change affects the visibility of items in the visible area, the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event will be triggered to remove the element.
        // Depending on whether there are new elements, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID or NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER event will be triggered.
        OH_ArkUI_NodeAdapter_RemoveItem(handle_, index, 1);
        // Update the total count.
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
    }

    void InsertItem(int32_t index, const ItemType &value)
    {
        int32_t safeIndex = std::max(0, std::min(index, static_cast<int32_t>(data_.size())));
        data_.insert(data_.begin() + safeIndex, value);
        // If the index change affects the visibility of elements in the visible area, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID and NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER events will be triggered.
        // If items are removed, the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event will be triggered accordingly.
        OH_ArkUI_NodeAdapter_InsertItem(handle_, safeIndex, 1);
        // Update the total count.
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
        // If the move changes the visibility of items within the visible area, the corresponding events will be triggered. Otherwise, no event is triggered.
        OH_ArkUI_NodeAdapter_MoveItem(handle_, oldIndex, newIndex);
    }

    void ReloadItem(int32_t index, const ItemType &value)
    {
        if (!IsValidIndex(index)) {
            return;
        }
        data_[index] = value;
        // If the index is within the visible area, first trigger the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event to remove the old item,
        // then trigger the NODE_ADAPTER_EVENT_ON_GET_NODE_ID and NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER events.
        OH_ArkUI_NodeAdapter_ReloadItem(handle_, index, 1);
    }

    void ReloadAllItem()
    {
        // In the scenario where all items are reloaded, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID event will be triggered to obtain new component IDs,
        // compare the new component IDs, and reuse those whose IDs have not changed,
        // for items with new IDs, trigger the NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER event to create new components,
        // then identify any unused IDs from the old data and call NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER to remove the old items.
        OH_ArkUI_NodeAdapter_ReloadAllItems(handle_);
    }

private:
    struct ItemEntry {
        std::shared_ptr<ArkUIListItemNode> listItem = nullptr;
    };

    static void OnStaticAdapterEvent(ArkUI_NodeAdapterEvent *event)
    {
        // Obtain the instance object and invoke the instance event callback.
        auto *itemAdapter = reinterpret_cast<ArkUIListItemAdapterT *>(OH_ArkUI_NodeAdapterEvent_GetUserData(event));
        if (itemAdapter != nullptr) {
            itemAdapter->OnAdapterEvent(event);
        }
    }

    void OnAdapterEvent(ArkUI_NodeAdapterEvent *event)
    {
        // Obtain the event type.
        auto type = OH_ArkUI_NodeAdapterEvent_GetType(event);
        switch (type) {
            // Obtain the unique ID of the new element to add.
            case NODE_ADAPTER_EVENT_ON_GET_NODE_ID:
                OnNewItemIdCreated(event);
                break;
            // Obtain the content of the new element to add.
            case NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER:
                OnNewItemAttached(event);
                break;
            // Remove elements from the adapter.
            case NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER:
                OnItemDetached(event);
                break;
            default:
                break;
        }
    }

    // Assign IDs to items that need to be displayed, used for element diffing in ReloadAllItems scenarios.
    void OnNewItemIdCreated(ArkUI_NodeAdapterEvent *event)
    {
        auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
        if (!IsValidIndex(index)) {
            return;
        }
        int64_t id = nodeIdCallback_ ? nodeIdCallback_(data_[index], index) : static_cast<int64_t>(index);
        OH_ArkUI_NodeAdapterEvent_SetNodeId(event, id);
    }

    // Handle the display of new items in the visible area.
    void OnNewItemAttached(ArkUI_NodeAdapterEvent *event)
    {
        auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
        if (!IsValidIndex(index)) {
            return;
        }

        ItemEntry itemEntry;
        if (!cachedItems_.empty()) {
            // Use and update the recycled item from the cache.
            itemEntry = cachedItems_.top();
            // Release the reference in the cache pool.
            cachedItems_.pop();
            reuseListItemCallback_(itemEntry.listItem, data_[index], index);
        } else {
            // Create an element.
            itemEntry.listItem = createChildCallback_(data_[index], index);
        }
        if (itemEntry.listItem == nullptr) {
            itemEntry.listItem = std::make_shared<ArkUIListItemNode>();
        }

        auto handle = itemEntry.listItem->GetHandle();
        items_[handle] = itemEntry;
        // Set the element to be displayed.
        OH_ArkUI_NodeAdapterEvent_SetItem(event, handle);
    }
    // Remove an item from the visible area.
    void OnItemDetached(ArkUI_NodeAdapterEvent *event)
    {
        auto item = OH_ArkUI_NodeAdapterEvent_GetRemovedNode(event);
        auto iter = items_.find(item);
        if (iter != items_.end()) {
            // Place the item in the cache pool for recycling and reuse.
            cachedItems_.push(iter->second);
            items_.erase(iter);
        }
    }

    bool IsValidIndex(int32_t index) const { return index >= 0 && index < static_cast<int32_t>(data_.size()); }

    // NodeAdapter instance handle.
    ArkUI_NodeAdapterHandle handle_ = nullptr;
    // List data source.
    std::vector<ItemType> data_;
    // Create a callback for the list item node.
    CreateChildCallback createChildCallback_ = nullptr;
    // Reuse the callback for the list item node.
    ReuseListItemCallback reuseListItemCallback_ = nullptr;
    // Callback for generating a node ID.
    NodeIdCallback nodeIdCallback_ = nullptr;
    // Manage items generated by the NodeAdapter.
    std::unordered_map<ArkUI_NodeHandle, ItemEntry> items_;

    // Manage the component reuse pool.
    std::stack<ItemEntry> cachedItems_;
};
} // namespace NativeModule

#endif // MYAPPLICATION_ARKUILISTITEMADAPTER_H
```

### Applying the Lazy Loading Adapter in a List

1. Add the **SetLazyAdapter** function to **ArkUIListNode**, set the [NODE_LIST_NODE_ADAPTER](../reference/apis-arkui/capi-native-node-h-nodeattributetype-scrollablecontainer.md#node_list_node_adapter) property for the list node, and pass **NodeAdapter** as the input parameter.
   <!-- @[List_encapsulated_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListNode.h) -->
   
   ``` C
   // ArkUIListNode.h
   // Provide encapsulation for the list component. 
   #ifndef MYAPPLICATION_ARKUILISTNODE_H
   #define MYAPPLICATION_ARKUILISTNODE_H
   
   #include "ArkUINode.h"
   #include "ArkUIListItemAdapter.h"
   namespace NativeModule {
   class ArkUIListNode : public ArkUINode {
   public:
       ArkUIListNode() // Create an ArkUI list component instance.
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_LIST)) {}
   
       ~ArkUIListNode() override
       {
           if (nativeModule_) {
               nativeModule_->unregisterNodeEvent(handle_, NODE_LIST_ON_SCROLL_INDEX);
               if (adapter_) {
               // Unload the UI components under the adapter during destruction.
                   nativeModule_->resetAttribute(handle_, NODE_LIST_NODE_ADAPTER);
                   adapter_.reset();
               }
           }
       }
       // List component's API encapsulation for attributes.
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
       // Import the lazy loading module.
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

2. Create example code for a **List** using lazy loading and call the **SetLazyAdapter** API of the **List** node to set the lazy loading adapter.
   <!-- @[Grouped_List_Interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/LazyTextListExample1.h) -->
   
   ``` C
   // LazyTextListExample
   // Example code for a lazy loading text list.
   
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
       // Create and mount the component to the parent node.
       // 1: Create a List component.
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(1); // 1: width
       list->SetPercentHeight(1); // 1: height
       auto data = BuildSampleData();
   
       auto adapterWeakHolder = std::make_shared<std::weak_ptr<StringAdapter>>();
       // 2: Callback for creating ListItem and its child components.
       auto createChildCallback = [adapterWeakHolder](const std::string &item,
                                                      int32_t index) -> std::shared_ptr<ArkUIListItemNode> {
           (void)index;
           return BuildListItemNode(item, adapterWeakHolder);
       };
       // 3. Callback for reusing ListItem.
       auto reuseListItemCallback = [adapterWeakHolder](const std::shared_ptr<ArkUIListItemNode> &listItem,
                                                        const std::string &item, int32_t index) {
           (void)index;
           ReuseListItemNode(listItem, item, adapterWeakHolder);
       };
   
       auto adapter = std::make_shared<StringAdapter>(data, createChildCallback, reuseListItemCallback);
       *adapterWeakHolder = adapter;
       // 4: Create a ListItem child component for lazy loading and mount it to the List component.
       list->SetLazyAdapter(adapter);
       return list;
   }
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_LAZYTEXTLISTEXAMPLE1_H
   ```

3. Call the **List** lazy loading example code in **NativeEntry.cpp**.
   <!-- @[Interface_entrance_mounting_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/NativeEntry.cpp) -->
   
   ``` C++
   // NDK API entry mounting file.
   
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
   
       // Obtain the NodeContent object.
       ArkUI_NodeContentHandle contentHandle;
       OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
       NativeEntry::GetInstance()->SetContentHandle(contentHandle);
   
       // Create a lazy loading text list.
       auto node = CreateLazyTextListExample();
   
       // Save the native-side object to the management class to maintain its lifecycle.
       NativeEntry::GetInstance()->SetRootNode(node);
       return nullptr;
   }
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info)
   {
       // Release the native-side object from the management class.
       NativeEntry::GetInstance()->DisposeRootNode();
       return nullptr;
   }
   
   } // namespace NativeModule
   ```
## Controlling the List Scroll Position

1. Control the list to scroll to a specified offset position.
   <!-- @[ScrollTo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListNode.h) -->
   
   ``` C
   // ArkUIListNode.h
   // Provide encapsulation for the list component. 
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
2. Control the list to scroll to a specified element.
   <!-- @[ScrollToIndex](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListNode.h) -->
   
   ``` C
   // ArkUIListNode.h
   // Provide encapsulation for the list component. 
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

3. Control the list to scroll by a specified offset.
   <!-- @[ScrollBy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListNode.h) -->
   
   ``` C
   // ArkUIListNode.h
   // Provide encapsulation for the list component. 
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
## Implementing Swipe-to-Delete for List Items

1. Set the [NODE_LIST_ITEM_SWIPE_ACTION](../reference/apis-arkui/capi-native-node-h-nodeattributetype-scrollablecontainer.md#node_list_item_swipe_action) attribute of [ListItem](../reference/apis-arkui/arkui-ts/ts-container-listitem.md) and pass the [ArkUI_ListItemSwipeActionOption](../reference/apis-arkui/capi-arkui-nativemodule-arkui-listitemswipeactionoption.md) object as the attribute parameter.
   <!-- @[Provide_wrapper_class_list_items](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListItemNode.h) -->
   
   ``` C
   // ArkUIListItemNode.h
   // Provide an encapsulation class for list items
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
           // Dispose of a ListItemSwipeActionOption instance.
           if (swipeAction_) {
               OH_ArkUI_ListItemSwipeActionOption_Dispose(swipeAction_);
           }
           // Dispose of a ListItemSwipeActionItem instance.
           if (swipeItem_) {
               OH_ArkUI_ListItemSwipeActionItem_Dispose(swipeItem_);
           }
       }
       void SetSwiperAction(std::shared_ptr<ArkUINode> node)
       {
           swipeContent_ = node;
           // Create a ListItemSwipeActionItem instance.
           swipeItem_ = OH_ArkUI_ListItemSwipeActionItem_Create();
           // Set the layout content for the ListItemSwipeActionItem instance.
           OH_ArkUI_ListItemSwipeActionItem_SetContent(swipeItem_, node->GetHandle());
           // Create a ListItemSwipeActionOption instance.
           swipeAction_ = OH_ArkUI_ListItemSwipeActionOption_Create();
           // Set the layout content for the right edge (for a vertical layout) or bottom edge (for a horizontal layout) of the ListItemSwipeActionItem instance.
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
2. Set callbacks for creating and reusing a **ListItem**. When creating a [ListItem](../reference/apis-arkui/arkui-ts/ts-container-listitem.md), create the swipe action item for it and bind the click event. In the click event, delete the data source. When reusing a **ListItem**, update the binding event of the swipe action item.
    <!-- @[SetCallBack](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/LazyTextListExample1.h) -->

   ``` C
   // LazyTextListExample
   // Example code for a lazy loading text list.

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
       data.reserve(1000); // Pre-allocate space for 1000 data records in each group.
       for (int32_t i = 0; i < 1000; i++) { // 1000: 1000 data records.
           data.emplace_back(std::to_string(i));
       }
       return data;
   }

   void RegisterDeleteClick(const std::shared_ptr<ArkUINode> &target, const AdapterWeakHolder &adapterWeakHolder,
       const std::string &item)
   {
       // Register a click event for the deletion area. Obtain the adapter through a weak reference to avoid long-term strong reference holding in the callback.
       target->RegisterOnClick([adapterWeakHolder, item](ArkUI_NodeEvent *event) {
           (void)event;
           auto adapter = adapterWeakHolder->lock();
           if (!adapter) {
               return;
           }
           // Search for the current item based on the current data to ensure that the latest bound item is deleted in the reuse scenario.
           const auto &currentData = adapter->GetData();
           auto it = std::find(currentData.begin(), currentData.end(), item);
           if (it != currentData.end()) {
               // RemoveItem requires an index. Here, the iterator position is converted to size_t.
               auto removeIndex = static_cast<size_t>(std::distance(currentData.begin(), it));
               adapter->RemoveItem(removeIndex);
           }
       });
   }

   std::shared_ptr<ArkUIListItemNode> BuildListItemNode(const std::string &item,
       const AdapterWeakHolder &adapterWeakHolder)
   {
       // Build a ListItem: main text area + swipe-to-delete area.
       auto listItem = std::make_shared<ArkUIListItemNode>();

       // Main content text, which displays the current data item.
       auto textNode = std::make_shared<ArkUITextNode>();
       textNode->SetTextContent(item);
       // ...
       listItem->AddChild(textNode);

       // Text in the swipe-to-delete area. Clicking the text triggers the deletion of the current item.
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

3. When adding a new **ListItem**, preferentially reuse the cached [ListItem](../reference/apis-arkui/arkui-ts/ts-container-listitem.md) instance and update its content. If no cached instance is available, create a new **ListItem**. If the callback returns null, create a default **ListItem** as a fallback. Finally, the generated node handle is filled back to the [OH_ArkUI_NodeAdapterEvent_SetItem](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeadapterevent_setitem) event to complete the binding.
   <!-- @[Item_adapter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListItemAdapter.h) -->
   
   ``` C
   // ArkUIListItemAdapter.h
   // ...
   template <typename ItemType> class ArkUIListItemAdapterT : public IArkUIListItemAdapter {
       // ...
       // Handle the display of new items in the visible area.
       void OnNewItemAttached(ArkUI_NodeAdapterEvent *event)
       {
           auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
           if (!IsValidIndex(index)) {
               return;
           }
   
           ItemEntry itemEntry;
           if (!cachedItems_.empty()) {
               // Use and update the recycled item from the cache.
               itemEntry = cachedItems_.top();
               // Release the reference in the cache pool.
               cachedItems_.pop();
               reuseListItemCallback_(itemEntry.listItem, data_[index], index);
           } else {
               // Create an element.
               itemEntry.listItem = createChildCallback_(data_[index], index);
           }
           if (itemEntry.listItem == nullptr) {
               itemEntry.listItem = std::make_shared<ArkUIListItemNode>();
           }
   
           auto handle = itemEntry.listItem->GetHandle();
           items_[handle] = itemEntry;
           // Set the element to be displayed.
           OH_ArkUI_NodeAdapterEvent_SetItem(event, handle);
       }
       // ...
   };
   ```
4. Add **RemoveItem** to **ArkUIListItemAdapter** to delete data sources and call the [OH_ArkUI_NodeAdapter_RemoveItem](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeadapter_removeitem) API to instruct the framework to refresh the UI.
   <!-- @[Remove_Item](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListItemAdapter.h) -->
   
   ``` C
   // ArkUIListItemAdapter.h
   // ...
   template <typename ItemType> class ArkUIListItemAdapterT : public IArkUIListItemAdapter {
       // ...
       void RemoveItem(size_t index)
       {
           // Remove the item at the specified index.
           if (index >= data_.size()) {
               return;
           }
           data_.erase(data_.begin() + static_cast<std::ptrdiff_t>(index));
           // If the index change affects the visibility of items in the visible area, the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event will be triggered to remove the element.
           // Depending on whether there are new elements, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID or NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER event will be triggered.
           OH_ArkUI_NodeAdapter_RemoveItem(handle_, index, 1);
           // Update the total count.
           OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
       }
   
       // ...
   };
   ```
## Using a Grouped List
1. The [ListItemGroup](../reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md) component is used to implement a grouped list. **ListItemGroup** supports the functions to add the [header](../reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions) and [footer](../reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions), and supports lazy loading.
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
               // Create an attribute item, put the node handle into it, and set the header.
               ArkUI_AttributeItem item = {.object = node->GetHandle()};
               nativeModule_->setAttribute(handle_, NODE_LIST_ITEM_GROUP_SET_HEADER, &item);
               header_ = node;
           } else {
               // If a null pointer (nullptr) is passed, the existing header is to be removed.
               nativeModule_->resetAttribute(handle_, NODE_LIST_ITEM_GROUP_SET_HEADER);
               header_.reset();
           }
       }
   
       void SetFooter(const std::shared_ptr<ArkUINode> &node)
       {
           if (node) {
               // Create an attribute item, put the node handle into it, and set the footer.
               ArkUI_AttributeItem item = {.object = node->GetHandle()};
               nativeModule_->setAttribute(handle_, NODE_LIST_ITEM_GROUP_SET_FOOTER, &item);
               footer_ = node;
           } else {
               // If a null pointer (nullptr) is passed, the existing footer is to be removed.
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
   
       // Import the lazy loading module.
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
2. Set the sticky header for the [List](../reference/apis-arkui/arkui-ts/ts-container-list.md) component.
   <!-- @[SetSticky](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/ArkUIListNode.h) -->
   
   ``` C
   // ArkUIListNode.h
   // Provide encapsulation for the list component. 
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
3. Use [ListItemGroup](../reference/apis-arkui/arkui-ts/ts-container-listitemgroup.md) under the [List](../reference/apis-arkui/arkui-ts/ts-container-list.md) component to implement the grouped list.
   <!-- @[Grouped_List](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/NdkCreateList/entry/src/main/cpp/LazyTextListExample.h) -->
   
   ``` C
   // LazyTextListExample.h
   // Example code for a lazy loading text list.
   
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
       header->SetFontSize(16); // 16: font size
       header->SetPercentWidth(1); // 1: width
       header->SetHeight(50); // 50: height
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
       // Create and mount the component to the parent node.
       // 1: Create a List component.
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(1); // 1: width
       list->SetPercentHeight(1); // 1: height
       list->SetSticky(ARKUI_STICKY_STYLE_BOTH);
   
       // 2: Create a ListItemGroup and mount it to the List component.
       for (int32_t i = 0; i < 3; i++) { // 3: number of groups
           list->AddChild(CreateListItemGroup());
       }
       return list;
   }
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H
   ```
