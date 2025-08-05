# Implementing a List Layout


The ArkUI development framework provides list components through NDK APIs, enabling efficient display of structured, scrollable content. List components allow you to control the scroll position, group display content, and use **NodeAdapter** for lazy loading to improve list creation performance.

## Creating a List

For details about how to create a list, see [Integrating with ArkTS Pages](../ui/ndk-access-the-arkts-page.md).

## Listening for Scroll Events

Implement list scroll event monitoring as instructed in the component event monitoring section.

## Implementing Lazy Loading

### NodeAdapter Overview

The NDK provides the [NodeAdapter](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeadapterhandle) object as an alternative to the LazyForEach functionality in ArkTS for on-demand generation of child components. **NodeAdapter** works with **List**, **ListItemGroup**, **Grid**, **WaterFlow**, and **Swiper** components.

- Nodes with **NodeAdapter** set do not support direct child addition APIs like **addChild**. Child components are managed entirely by **NodeAdapter**. If a parent component already has child nodes, setting **NodeAdapter** will fail and return an error code.

- **NodeAdapter** notifies you of on-demand generation of components through relevant events. Similar to the component event mechanism, you need to register an [event listener](../reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodeadapter_registereventreceiver) when using **NodeAdapter** and handle logic in the listener events. Relevant events are defined by [ArkUI_NodeAdapterEventType](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeadaptereventtype). **NodeAdapter** does not actively release off-screen component objects; you must release or cache and reuse component objects in the [NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER](../reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeadaptereventtype) event. The following image illustrates the event triggering mechanism in a typical list scrolling scenario.
  ![en-us_image_0000001949769409](figures/en-us_image_0000001949769409.png)


### Implementing a Lazy Loading Adapter

Use the **ArkUListItemAdapter** class to manage the lazy loading adapter. Create a **NodeAdapter** object in the class constructor and set an event listener for the **NodeAdapter** object. In the class destructor, destroy the **NodeAdapter** object.

   ```c++
   // ArkUIListItemAdapter
   // Code for lazy loading functionality in a text list.
   
   #ifndef MYAPPLICATION_ARKUILISTITEMADAPTER_H
   #define MYAPPLICATION_ARKUILISTITEMADAPTER_H
   
   #include <arkui/native_node.h>
   #include <stack>
   #include <string>
   #include <unordered_set>
   
   #include "ArkUIListItemNode.h"
   #include "ArkUITextNode.h"
   #include "nativeModule.h"
   
   namespace NativeModule {
   
   class ArkUIListItemAdapter {
   public:
       ArkUIListItemAdapter()
           : module_(NativeModuleInstance::GetInstance()->GetNativeNodeAPI()), handle_(OH_ArkUI_NodeAdapter_Create()) { // Use the NodeAdapter creation function.
           // Initialize lazy loading data.
           for (int32_t i = 0; i < 1000; i++) {
               data_.emplace_back(std::to_string(i));
           }
           // Set lazy loading data.
           OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
           // Register the event receiver for lazy loading.
           OH_ArkUI_NodeAdapter_RegisterEventReceiver(handle_, this, OnStaticAdapterEvent);
       }
   
       ~ArkUIListItemAdapter() {
           // Release created components.
           while (!cachedItems_.empty()) {
               cachedItems_.pop();
           }
           items_.clear();
           // Release adapter resources.
           OH_ArkUI_NodeAdapter_UnregisterEventReceiver(handle_);
           OH_ArkUI_NodeAdapter_Dispose(handle_);
       }
   
       ArkUI_NodeAdapterHandle GetHandle() const { return handle_; }
   
       void RemoveItem(int32_t index) {
           // Remove the item at the specified index.
           data_.erase(data_.begin() + index);
           // If the index change affects the visibility of items in the visible area, the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event will be triggered to remove the element.
           // Depending on whether there are new elements, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID or NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER event will be triggered.
           OH_ArkUI_NodeAdapter_RemoveItem(handle_, index, 1);
           // Update the total count.
           OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
       }
   
       void InsertItem(int32_t index, const std::string &value) {
           data_.insert(data_.begin() + index, value);
           // If the index change affects the visibility of elements in the visible area, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID and NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER events will be triggered.
           // If items are removed, the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event will be triggered accordingly.
           OH_ArkUI_NodeAdapter_InsertItem(handle_, index, 1);
           // Update the total count.
           OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
       }
   
       void MoveItem(int32_t oldIndex, int32_t newIndex) {
           auto temp = data_[oldIndex];
           data_.insert(data_.begin() + newIndex, temp);
           data_.erase(data_.begin() + oldIndex);
           // If the move changes the visibility of items within the visible area, the corresponding events will be triggered. Otherwise, no event is triggered.
           OH_ArkUI_NodeAdapter_MoveItem(handle_, oldIndex, newIndex);
       }
   
       void ReloadItem(int32_t index, const std::string &value) {
           data_[index] = value;
           // If the index is within the visible area, first trigger the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event to remove the old item,
           // then trigger the NODE_ADAPTER_EVENT_ON_GET_NODE_ID and NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER events.
           OH_ArkUI_NodeAdapter_ReloadItem(handle_, index, 1);
       }
   
       void ReloadAllItem() {
           std::reverse(data_.begin(), data_.end());
           // In the scenario where all items are reloaded, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID event will be triggered to obtain new component IDs,
           // compare the new component IDs, and reuse those whose IDs have not changed,
           // for items with new IDs, trigger the NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER event to create new components,
           // then identify any unused IDs from the old data and call NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER to remove the old items.
           OH_ArkUI_NodeAdapter_ReloadAllItems(handle_);
       }
   
   private:
       static void OnStaticAdapterEvent(ArkUI_NodeAdapterEvent *event) {
           // Obtain the instance object and invoke the instance event callback.
           auto itemAdapter = reinterpret_cast<ArkUIListItemAdapter *>(OH_ArkUI_NodeAdapterEvent_GetUserData(event));
           itemAdapter->OnAdapterEvent(event);
       }
   
       void OnAdapterEvent(ArkUI_NodeAdapterEvent *event) {
           auto type = OH_ArkUI_NodeAdapterEvent_GetType(event);
           switch (type) {
           case NODE_ADAPTER_EVENT_ON_GET_NODE_ID:
               OnNewItemIdCreated(event);
               break;
           case NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER:
               OnNewItemAttached(event);
               break;
           case NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER:
               OnItemDetached(event);
               break;
           default:
               break;
           }
       }
   
       // Assign IDs to items that need to be displayed, used for element diffing in the ReloadAllItems scenario.
       void OnNewItemIdCreated(ArkUI_NodeAdapterEvent *event) {
           auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
           static std::hash<std::string> hashId = std::hash<std::string>();
           auto id = hashId(data_[index]);
           OH_ArkUI_NodeAdapterEvent_SetNodeId(event, id);
       }
   
       // Handle the display of new items in the visible area.
       void OnNewItemAttached(ArkUI_NodeAdapterEvent *event) {
           auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
           ArkUI_NodeHandle handle = nullptr;
           if (!cachedItems_.empty()) {
               // Use and update the recycled item from the cache.
               auto recycledItem = cachedItems_.top();
               auto textItem = std::dynamic_pointer_cast<ArkUITextNode>(recycledItem->GetChildren().back());
               textItem->SetTextContent(data_[index]);
               handle = recycledItem->GetHandle();
               // Release the reference in the cache pool.
               cachedItems_.pop();
           } else {
               // Create an element.
               auto listItem = std::make_shared<ArkUIListItemNode>();
               auto textNode = std::make_shared<ArkUITextNode>();
               textNode->SetTextContent(data_[index]);
               textNode->SetFontSize(16);
               textNode->SetPercentWidth(1);
               textNode->SetHeight(100);
               textNode->SetBackgroundColor(0xFFfffacd);
               textNode->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER);
               listItem->AddChild(textNode);
               listItem->RegisterOnClick([index]() { OH_LOG_INFO(LOG_APP, "on %{public}d list item click", index); });
               handle = listItem->GetHandle();
               // Maintain a reference to the text list item.
               items_.emplace(handle, listItem);
           }
           // Set the element to be displayed.
           OH_ArkUI_NodeAdapterEvent_SetItem(event, handle);
       }
   
       // Remove an item from the visible area.
       void OnItemDetached(ArkUI_NodeAdapterEvent *event) {
           auto item = OH_ArkUI_NodeAdapterEvent_GetRemovedNode(event);
           // Place the item in the cache pool for recycling and reuse.
           cachedItems_.emplace(items_[item]);
       }
   
   
       std::vector<std::string> data_;
       ArkUI_NativeNodeAPI_1 *module_ = nullptr;
       ArkUI_NodeAdapterHandle handle_ = nullptr;
   
       // Manage items generated by the NodeAdapter.
       std::unordered_map<ArkUI_NodeHandle, std::shared_ptr<ArkUIListItemNode>> items_;
   
       // Manage the component reuse pool.
       std::stack<std::shared_ptr<ArkUIListItemNode>> cachedItems_;
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUILISTITEMADAPTER_H
   ```

### Applying the Lazy Loading Adapter in a List

1. Add the **SetLazyAdapter** function in **ArkUIListNode** to set the **NODE_LIST_NODE_ADAPTER** attribute for the list node and pass the **NodeAdapter** as an attribute parameter.
   ```c++
   // ArkUIListNode.h
   // List encapsulation object.
   
   #ifndef MYAPPLICATION_ARKUILISTNODE_H
   #define MYAPPLICATION_ARKUILISTNODE_H
   
   #include "ArkUIListItemAdapter.h"
   #include "ArkUINode.h"
   #include <hilog/log.h>
   
   namespace NativeModule {
   class ArkUIListNode : public ArkUINode {
   public:
       ArkUIListNode()
           : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_LIST)) {}
   
       ~ArkUIListNode() override {
           nativeModule_->unregisterNodeEvent(handle_, NODE_LIST_ON_SCROLL_INDEX);
           if (adapter_) {
               // Unload the UI components under the adapter during destruction.
               nativeModule_->resetAttribute(handle_, NODE_LIST_NODE_ADAPTER);
               adapter_.reset();
           }
       }
   
       void SetScrollBarState(bool isShow) {
           assert(handle_);
           ArkUI_ScrollBarDisplayMode displayMode =
               isShow ? ARKUI_SCROLL_BAR_DISPLAY_MODE_ON : ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF;
           ArkUI_NumberValue value[] = {{.i32 = displayMode}};
           ArkUI_AttributeItem item = {value, 1};
           nativeModule_->setAttribute(handle_, NODE_SCROLL_BAR_DISPLAY_MODE, &item);
       }
   
       void RegisterOnScrollIndex(const std::function<void(int32_t index)> &onScrollIndex) {
           assert(handle_);
           onScrollIndex_ = onScrollIndex;
           nativeModule_->registerNodeEvent(handle_, NODE_LIST_ON_SCROLL_INDEX, 0, nullptr);
       }
       // Import the lazy loading module.
       void SetLazyAdapter(const std::shared_ptr<ArkUIListItemAdapter> &adapter) {
           assert(handle_);
           ArkUI_AttributeItem item{nullptr, 0, nullptr, adapter->GetHandle()};
           nativeModule_->setAttribute(handle_, NODE_LIST_NODE_ADAPTER, &item);
           adapter_ = adapter;
       }
   
   protected:
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
   
       std::shared_ptr<ArkUIListItemAdapter> adapter_;
   };
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUILISTNODE_H
   ```

2. Create example code for a **List** using lazy loading and call the **SetLazyAdapter** API of the **List** node to set the lazy loading adapter.
   ```c++
   // LazyTextListExample
   // Example code for a lazy loading text list.
   
   #ifndef MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H
   #define MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H
   
   #include "ArkUIBaseNode.h"
   #include "ArkUIListNode.h"
   
   
   namespace NativeModule {
   
   std::shared_ptr<ArkUIBaseNode> CreateLazyTextListExample(napi_env env) {
       // Create and mount the component.
       // 1: Create a List component.
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(1);
       list->SetPercentHeight(1);
       // 2: Create a ListItem child component for lazy loading and mount it to the List component.
       auto adapter = std::make_shared<ArkUIListItemAdapter>();
       list->SetLazyAdapter(adapter);
       return list;
   }
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H
   ```

3. Call the **List** lazy loading example code in **NativeEntry.cpp**.
   ```c++
   // NDK API entry mounting file.
   
   #include "NativeEntry.h"
   
   #include "ArkUIMixedRefresh.h"
   #include "LazyTextListExample.h"
   #include "MixedRefreshExample.h"
   #include "TextListExample.h"
   
   #include <arkui/native_node_napi.h>
   #include <arkui/native_type.h>
   #include <js_native_api.h>
   #include <uv.h>
   
   namespace NativeModule {
   
   
   napi_value CreateNativeRoot(napi_env env, napi_callback_info info) {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
       // Obtain NodeContent.
       ArkUI_NodeContentHandle contentHandle;
       OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
       NativeEntry::GetInstance()->SetContentHandle(contentHandle);
   
       // Create a lazy loading text list.
       auto node = CreateLazyTextListExample(env);
   
       // Keep the native-side object in the management class to maintain its lifecycle.
       NativeEntry::GetInstance()->SetRootNode(node);
       g_env = env;
       return nullptr;
   }
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info) {
       // Release the native-side object from the management class.
       NativeEntry::GetInstance()->DisposeRootNode();
       return nullptr;
   }
   
   } // namespace NativeModule
   ```
## Controlling the List Scroll Position

1. Control the list to scroll to a specified offset position.
    ```c++
    //ArkUIListNode.h
    // List encapsulation object.
    class ArkUIListNode: public ArkUINode {
        //...
        void ScrollTo(float offset) {
            ArkUI_NumberValue value[] = {{.f32 =0},{.f32 = offset},{.f32 = 0}};
            ArkUI_AttributeItem Item = {.value = value,.size = 3};
            nativeModule_->setAttribute(handle_, NODE_SCROLL_OFFSET, &Item);
        }
    };
    ```
2. Control the list to scroll to a specified element.
    ```c++
    //ArkUIListNode.h
    // List encapsulation object.
    class ArkUIListNode : public ArkUINode {
        //...
        void ScrollToIndex(int32_t index) {
            ArkUI_NumberValue value[] = {{.i32 = index}};
            ArkUI_AttributeItem Item = {.value = value, .size = 1};
            nativeModule_->setAttribute(handle_, NODE_LIST_SCROLL_TO_INDEX, &Item);
        }
    };
    ```

3. Control the list to scroll by a specified offset.
    ```c++
   //ArkUIListNode.h
    // List encapsulation object.
    class ArkUIListNode : public ArkUINode {
        void ScrollBy(float offset) {
            ArkUI_NumberValue value[] = {{.f32 =0},{.f32 = offset}};
            ArkUI_AttributeItem Item = {.value = value, .size = 2};
            nativeModule_->setAttribute(handle_, NODE_SCROLL_BY, &Item);
        }
    };
    ```
## Implementing Swipe-to-Delete for List Items

1. Set the **NODE_LIST_ITEM_SWIPE_ACTION** attribute for **ListItem** and pass the **ArkUI_ListItemSwipeActionOption** object as an attribute parameter.
    ```c++
    // ArkUIListItemNode.h 
    // Encapsulation class for list items.
    #ifndef MYAPPLICATION_ARKUILISTITEMNODE_H 
    #define MYAPPLICATION_ARKUILISTITEMNODE_H 
    #include "ArkUINode.h" 
    namespace NativeModule{ 
    class ArkUIListItemNode : public ArkUINode { 
    public: 
        ArkUIListItemNode() 
            : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_LIST_ITEM)) {}
        ~ArkUIListItemNode() { 
            if(swipeAction_) { 
                OH_ArkUI_ListItemSwipeActionOption_Dispose(swipeAction_); 
            }
            if (swipeItem_) { 
                OH_ArkUI_ListItemSwipeActionItem_Dispose(swipeItem_); 
            }
        } 
        void SetSwiperAction(std::shared_ptr<ArkUINode> node) { 
            swipeContent_ = node; 
            swipeItem_ = OH_ArkUI_ListItemSwipeActionItem_Create(); 
            OH_ArkUI_ListItemSwipeActionItem_SetContent(swipeItem_, node->GetHandle()); 
            swipeAction_ = OH_ArkUI_ListItemSwipeActionOption_Create(); 
            OH_ArkUI_ListItemSwipeActionOption_SetEnd(swipeAction_, swipeItem_); 
            ArkUI_AttributeItem Item = {.object= swipeAction_ }; 
            nativeModule_->setAttribute(handle_,NODE_LIST_ITEM_SWIPE_ACTION, &Item); 
        } 
        std::shared_ptr<ArkUINode> GetSwipeContent() const { 
            return swipeContent_; 
        }
    private: 
        ArkUI_ListItemSwipeActionOption* swipeAction_ = nullptr; 
        ArkUI_ListItemSwipeActionItem* swipeItem_ = nullptr;
        std::shared_ptr<ArkUINode> swipeContent_ = nullptr; 
    }; 
    }// namespace NativeModule 
    #endif// MYAPPLICATION_ARKUILISTITEMNODE_H
    ```

2. When creating a **ListItem**, create the swipe action item for the **ListItem** and bind a click event to perform the data source deletion operation in the click event. When reusing a **ListItem**, update the binding event of the swipe action item.
    ```c++
    // ArkUIListItemAdapter.h 
    class ArkUIListItemAdapter { 
        //...
        // Handle the display of new items in the visible area.
        void OnNewItemAttached(ArkUI_NodeAdapterEvent *event) { 
            auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event); 
            ArkUI_NodeHandle handle = nullptr; 
            if (!cachedItems_.empty()) { 
                // Use and update the recycled cache.
                auto recycledItem = cachedItems_.top(); 
                auto textItem = std::dynamic_pointer_cast<ArkUITextNode>(recycledItem->GetChildren().back()); 
                textItem->SetTextContent(data_[index]); 
                handle = recycledItem->GetHandle(); 
                auto swipeContent = recycledItem->GetSwipeContent(); 
                swipeContent->RegisterOnClick([this, data = data_[index]]() { 
                    auto it = std::find(data_.begin(), data_.end(), data); 
                    if (it != data_.end()) { 
                        auto index = std::distance(data_.begin(), it); 
                        RemoveItem(index); 
                    } 
                }); 
                // Release the reference in the cache pool.
                cachedItems_.pop(); 
            } else { 
                // Create an element.
                auto listItem = std::make_shared<ArkUIListItemNode>(); 
                auto textNode = std::make_shared<ArkUITextNode>();
                textNode->SetTextContent(data_[index]); 
                textNode->SetFontSize(16); 
                textNode->SetPercentWidth(1); 
                textNode->SetHeight(100); 
                textNode->SetBackgroundColor(0xFFfffacd); 
                textNode->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER);
                listItem->AddChild(textNode); 
                // Create the swipe action item for the ListItem.
                auto swipeNode = std::make_shared<ArkUITextNode>(); 
                swipeNode->SetTextContent("del"); 
                swipeNode->SetFontSize(16); 
                swipeNode->SetFontColor(0xFFFFFFFF); 
                swipeNode->SetWidth(100); 
                swipeNode->SetHeight(100); 
                swipeNode->SetBackgroundColor(0xFFFF0000); 
                swipeNode->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER); 
                swipeNode->RegisterOnClick([this, data = data_[index]]() { 
                    auto it = std::find(data_.begin(), data_.end(), data); 
                    if (it != data_.end()) { 
                        auto index = std::distance(data_.begin(), it); 
                        RemoveItem(index); 
                    } 
                }); 
                listItem->SetSwiperAction(swipeNode); 
                handle = listItem->GetHandle(); 
                // Maintain a reference to the text list item.
                items_.emplace(handle, listItem); 
            }
            // Set the element to be displayed.
            OH_ArkUI_NodeAdapterEvent_SetItem(event, handle); 
        } 
    }
    ```
3. Add **RemoveItem** in **ArkUIListItemAdapter** to delete the data source and call the **OH_ArkUI_NodeAdapter_RemoveItem** API to instruct the framework to update the UI.
    ```c++
    // ArkUIListItemAdapter.h 
    class ArkUIListItemAdapter { 
        //...
        void RemoveItem(size_t index) { 
            // Remove the item at the specified index.
            data_.erase(data_.begin() + index); 
            // If the index change affects the visibility of items in the visible area, the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event will be triggered to remove the element.
            // Depending on whether there are new elements, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID or NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER event will be triggered.
            OH_ArkUI_NodeAdapter_RemoveItem(handle_, index, 1); 
            // Update the total count.
            OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size()); 
        } 
    };
    ```
## Using a Grouped List
1. Implement a grouped list using the **ListItemGroup** component, which supports features to add headers and footers and use lazy loading.
    ```c++
    // ArkUIListItemGroupNode.h 

    #ifndef MYAPPLICATION_ARKUILISTITEMGROUPNODE_H 
    #define MYAPPLICATION_ARKUILISTITEMGROUPNODE_H 
    #include "ArkUINode.h" 
    #include "ArkUIListItemAdapter.h" 
    namespace NativeModule{ 
    class ArkUIListItemGroupNode : public ArkUINode { 
    public: 
        ArkUIListItemGroupNode() 
            : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_LIST_ITEM_GROUP)) {} 
        void SetHeader(std::shared_ptr<ArkUINode> node) { 
            if (node) { 
                ArkUI_AttributeItem Item = {.object = node->GetHandle()}; 
                nativeModule_->setAttribute(handle_, NODE_LIST_ITEM_GROUP_SET_HEADER, &Item); 
            } else { 
                nativeModule_->resetAttribute(handle_, NODE_LIST_ITEM_GROUP_SET_HEADER); 
            } 
        } 
        void SetFooter(std::shared_ptr<ArkUINode> node) { 
            if (node) { 
                ArkUI_AttributeItem Item = {.object= node->GetHandle()}; 
                nativeModule_->setAttribute(handle_, NODE_LIST_ITEM_GROUP_SET_FOOTER, &Item); 
            } else { 
                nativeModule_->resetAttribute(handle_, NODE_LIST_ITEM_GROUP_SET_FOOTER); 
            } 
        } 
        std::shared_ptr<ArkUINode> GetHeader() const { 
            return header_; 
        }
        std::shared_ptr<ArkUINode> GetFooter() const { 
            return footer_; 
        }
        // Import the lazy loading module.
        void SetLazyAdapter(const std::shared_ptr<ArkUIListItemAdapter> &adapter) { 
            assert(handle_); 
            ArkUI_AttributeItem item{nullptr,0, nullptr, adapter->GetHandle()}; 
            nativeModule_->setAttribute(handle_, NODE_LIST_ITEM_GROUP_NODE_ADAPTER, &item); 
            adapter_ = adapter; 
        } 
    private: 
        std::shared_ptr<ArkUINode> header_; 
        std::shared_ptr<ArkUINode> footer_; 
        std::shared_ptr<ArkUIListItemAdapter> adapter_; 
    }; 
    }// namespace NativeModule 
    #endif//MYAPPLICATION_ARKUILISTITEMGROUPNODE_H
    ```
2. Set the sticky header for the **List** component.
    ```c++
    // ArkUIListNode.h 
    // List encapsulation object.
    class ArkUIListNode : public ArkUINode{ 
        //...
        void SetSticky(ArkUI_StickyStyle style) { 
            assert(handle_); 
            ArkUI_NumberValue value[] = {{.i32 = style}}; 
            ArkUI_AttributeItem item = {value, 1}; 
            nativeModule_->setAttribute(handle_, NODE_LIST_STICKY, &item); 
        }
    };
    ```
3. Implement a grouped list UI using **ListItemGroup** under the **List** component.
    ```c++
    // LazyTextListExample.h 
    // Example code for a lazy loading text list.
    #ifndef MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H
    #define MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H 
    #include "ArkUIBaseNode.h" 
    #include "ArkUIListNode.h" 
    #include "ArkUIListItemGroupNode.h" 
    namespace NativeModule { 
    std::shared_ptr<ArkUIBaseNode> CreateLazyTextListExample() { 
    // Create and mount the component.
    // 1: Create a List component.
        auto list = std::make_shared<ArkUIListNode>(); 
        list->SetPercentWidth(1); 
        list->SetPercentHeight(1); 
        // Set the sticky header.
        list->SetSticky(ARKUI_STICKY_STYLE_BOTH); 
        // 2: Create a ListItemGroup and mount it to the List.
        for (int32_t i = 0; i < 3; i++) { 
            auto header = std::make_shared<ArkUITextNode>(); 
            header->SetTextContent("header"); 
            header->SetFontSize(16); 
            header->SetPercentWidth(1); 
            header->SetHeight(50); 
            header->SetBackgroundColor(0xFFDCDCDC); 
            header->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER);
            auto listItemGroup = std::make_shared<ArkUIListItemGroupNode>(); 
            listItemGroup->SetHeader(header); 
            auto adapter = std::make_shared<ArkUIListItemAdapter>(4); 
            listItemGroup->SetLazyAdapter(adapter); 
            list->AddChild(listItemGroup); 
        }
        return list; 
    }
    }// namespace NativeModule 
    #endif// MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H
    ```
