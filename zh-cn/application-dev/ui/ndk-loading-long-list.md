# 使用列表

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yylong-->
<!--SE: @yylong-->
<!--TSE: @liuzhenshuo-->

ArkUI开发框架在NDK接口提供了列表组件，使用列表可以轻松高效地显示结构化、可滚动的信息。列表组件支持控制滚动位置、支持分组显示内容、支持使用NodeAdapter实现懒加载以提升列表创建性能。

## 创建列表

参考[接入ArkTS页面章节](../ui/ndk-access-the-arkts-page.md)实现列表创建。 

## 监听滚动事件 

参考监听组件事件章节实现列表滚动事件监听。 

## 使用懒加载 

### NodeAdapter介绍 

NDK提供了[NodeAdapter](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nodeadapter8h.md)对象替代ArkTS侧的LazyForEach功能，用于按需生成子组件，NodeAdapter支持在List/ListItemGroup、Grid、WaterFlow、Swiper组件中使用。

- 设置了NodeAdapter属性的节点，不再支持addChild等直接添加子组件的接口。子组件完全由NodeAdapter管理，使用属性方法设置NodeAdapter时，会判断父组件是否已经存在子节点，如果父组件已经存在子节点，则设置NodeAdapter操作失败，返回错误码。

- NodeAdapter通过相关事件通知开发者按需生成组件，类似组件事件机制，开发者使用NodeAdapter时要注册[事件监听器](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeadapter_registereventreceiver)，在监听器事件中处理逻辑，相关事件通过[ArkUI_NodeAdapterEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeadaptereventtype)定义。另外NodeAdapter不会主动释放不在屏幕内显示的组件对象，开发者需要在[NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeadaptereventtype)事件中进行组件对象的释放，或者进行缓存复用。下图展示了典型列表滑动场景下的事件触发机制：
  ![zh-cn_image_0000001949769409](figures/zh-cn_image_0000001949769409.png)


### 实现懒加载适配器

使用ArkUListItemAdapter类来管理懒加载适配器，在类的构造中创建NodeAdapter对象，并给NodeAdapter对象设置事件监听器，在类的析构函数中，销毁NodeAdapter对象。

   ```c++
   // ArkUIListItemAdapter
   // 用于文本列表懒加载功能代码。
   
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
           : module_(NativeModuleInstance::GetInstance()->GetNativeNodeAPI()), handle_(OH_ArkUI_NodeAdapter_Create()) { // 使用NodeAdapter创建函数。
           // 初始化懒加载数据。
           for (int32_t i = 0; i < 1000; i++) {
               data_.emplace_back(std::to_string(i));
           }
           // 设置懒加载数据。
           OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
           // 设置懒加载回调事件。
           OH_ArkUI_NodeAdapter_RegisterEventReceiver(handle_, this, OnStaticAdapterEvent);
       }
   
       ~ArkUIListItemAdapter() {
           // 释放创建的组件。
           while (!cachedItems_.empty()) {
               cachedItems_.pop();
           }
           items_.clear();
           // 释放Adapter相关资源。
           OH_ArkUI_NodeAdapter_UnregisterEventReceiver(handle_);
           OH_ArkUI_NodeAdapter_Dispose(handle_);
       }
   
       ArkUI_NodeAdapterHandle GetHandle() const { return handle_; }
   
       void RemoveItem(int32_t index) {
           // 删除第index个数据。
           data_.erase(data_.begin() + index);
           // 如果index会导致可视区域元素发生可见性变化，则会回调NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER事件删除元素，
           // 根据是否有新增元素回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID和NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件。
           OH_ArkUI_NodeAdapter_RemoveItem(handle_, index, 1);
           // 更新新的数量。
           OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
       }
   
       void InsertItem(int32_t index, const std::string &value) {
           data_.insert(data_.begin() + index, value);
           // 如果index会导致可视区域元素发生可见性变化，则会回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID和NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件，
           // 根据是否有删除元素回调NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER事件。
           OH_ArkUI_NodeAdapter_InsertItem(handle_, index, 1);
           // 更新新的数量。
           OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size());
       }
   
       void MoveItem(int32_t oldIndex, int32_t newIndex) {
           auto temp = data_[oldIndex];
           data_.insert(data_.begin() + newIndex, temp);
           data_.erase(data_.begin() + oldIndex);
           // 移到位置如果未发生可视区域内元素的可见性变化，则不回调事件，反之根据新增和删除场景回调对应的事件。
           OH_ArkUI_NodeAdapter_MoveItem(handle_, oldIndex, newIndex);
       }
   
       void ReloadItem(int32_t index, const std::string &value) {
           data_[index] = value;
           // 如果index位于可视区域内，先回调NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER删除老元素，
           // 再回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID和NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件。
           OH_ArkUI_NodeAdapter_ReloadItem(handle_, index, 1);
       }
   
       void ReloadAllItem() {
           std::reverse(data_.begin(), data_.end());
           // 全部重新加载场景下，会回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID接口获取新的组件ID，
           // 根据新的组件ID进行对比，ID不发生变化的进行复用，
           // 针对新增ID的元素，调用NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件创建新的组件，
           // 然后判断老数据中遗留的未使用ID，调用NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER删除老元素。
           OH_ArkUI_NodeAdapter_ReloadAllItems(handle_);
       }
   
   private:
       static void OnStaticAdapterEvent(ArkUI_NodeAdapterEvent *event) {
           // 获取实例对象，回调实例事件。
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
   
       // 分配ID给需要显示的Item，用于ReloadAllItems场景的元素diff。
       void OnNewItemIdCreated(ArkUI_NodeAdapterEvent *event) {
           auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
           static std::hash<std::string> hashId = std::hash<std::string>();
           auto id = hashId(data_[index]);
           OH_ArkUI_NodeAdapterEvent_SetNodeId(event, id);
       }
   
       // 需要新的Item显示在可见区域。
       void OnNewItemAttached(ArkUI_NodeAdapterEvent *event) {
           auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
           ArkUI_NodeHandle handle = nullptr;
           if (!cachedItems_.empty()) {
               // 使用并更新回收复用的缓存。
               auto recycledItem = cachedItems_.top();
               auto textItem = std::dynamic_pointer_cast<ArkUITextNode>(recycledItem->GetChildren().back());
               textItem->SetTextContent(data_[index]);
               handle = recycledItem->GetHandle();
               // 释放缓存池的引用。
               cachedItems_.pop();
           } else {
               // 创建新的元素。
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
               // 保持文本列表项的引用。
               items_.emplace(handle, listItem);
           }
           // 设置需要展示的元素。
           OH_ArkUI_NodeAdapterEvent_SetItem(event, handle);
       }
   
       // Item从可见区域移除。
       void OnItemDetached(ArkUI_NodeAdapterEvent *event) {
           auto item = OH_ArkUI_NodeAdapterEvent_GetRemovedNode(event);
           // 放置到缓存池中进行回收复用。
           cachedItems_.emplace(items_[item]);
       }
   
   
       std::vector<std::string> data_;
       ArkUI_NativeNodeAPI_1 *module_ = nullptr;
       ArkUI_NodeAdapterHandle handle_ = nullptr;
   
       // 管理NodeAdapter生成的元素。
       std::unordered_map<ArkUI_NodeHandle, std::shared_ptr<ArkUIListItemNode>> items_;
   
       // 管理回收复用组件池。
       std::stack<std::shared_ptr<ArkUIListItemNode>> cachedItems_;
   };
   
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_ARKUILISTITEMADAPTER_H
   ```

### 在列表中应用懒加载适配器 

1. 在ArkUIListNode中添加SetLazyAdapter函数，给列表节点设置NODE_LIST_NODE_ADAPTER属性，并将NodeAdapter作为属性入参传入。
   ```c++
   // ArkUIListNode.h
   // 列表封装对象。
   
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
               // 析构的时候卸载adapter下的UI组件。
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
       // 引入懒加载模块。
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

2. 创建List使用懒加载的示例代码，调用List节点的SetLazyAdapter接口设置懒加载适配器。
   ```c++
   // LazyTextListExample
   // 懒加载列表示例代码。
   
   #ifndef MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H
   #define MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H
   
   #include "ArkUIBaseNode.h"
   #include "ArkUIListNode.h"
   
   
   namespace NativeModule {
   
   std::shared_ptr<ArkUIBaseNode> CreateLazyTextListExample(napi_env env) {
       // 创建组件并挂载
       // 1：创建List组件。
       auto list = std::make_shared<ArkUIListNode>();
       list->SetPercentWidth(1);
       list->SetPercentHeight(1);
       // 2：创建ListItem懒加载组件并挂载到List上。
       auto adapter = std::make_shared<ArkUIListItemAdapter>();
       list->SetLazyAdapter(adapter);
       return list;
   }
   } // namespace NativeModule
   
   #endif // MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H
   ```

3. 在NativeEntry.cpp中调用List使用懒加载的示例代码。
   ```c++
   // NDK接口入口挂载文件。
   
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
   
       // 获取NodeContent
       ArkUI_NodeContentHandle contentHandle;
       OH_ArkUI_GetNodeContentFromNapiValue(env, args[0], &contentHandle);
       NativeEntry::GetInstance()->SetContentHandle(contentHandle);
   
       // 创建懒加载文本列表
       auto node = CreateLazyTextListExample(env);
   
       // 保持Native侧对象到管理类中，维护生命周期。
       NativeEntry::GetInstance()->SetRootNode(node);
       g_env = env;
       return nullptr;
   }
   
   napi_value DestroyNativeRoot(napi_env env, napi_callback_info info) {
       // 从管理类中释放Native侧对象。
       NativeEntry::GetInstance()->DisposeRootNode();
       return nullptr;
   }
   
   } // namespace NativeModule
   ```
## 控制列表滚动位置

1. 控制列表滚动到指定偏移量位置。
    ```c++
    //ArkUIListNode.h
    //列表封装对象。
    class ArkUIListNode: public ArkUINode {
        //...
        void ScrollTo(float offset) {
            ArkUI_NumberValue value[] = {{.f32 =0},{.f32 = offset},{.f32 = 0}};
            ArkUI_AttributeItem Item = {.value = value,.size = 3};
            nativeModule_->setAttribute(handle_, NODE_SCROLL_OFFSET, &Item);
        }
    };
    ```
2. 控制列表滚动到指定元素。 
    ```c++
    //ArkUIListNode.h
    //列表封装对象。
    class ArkUIListNode : public ArkUINode {
        //...
        void ScrollToIndex(int32_t index) {
            ArkUI_NumberValue value[] = {{.i32 = index}};
            ArkUI_AttributeItem Item = {.value = value, .size = 1};
            nativeModule_->setAttribute(handle_, NODE_LIST_SCROLL_TO_INDEX, &Item);
        }
    };
    ```

3. 控制列表滚动指定偏移量。
    ```c++
   //ArkUIListNode.h
    //列表封装对象。
    class ArkUIListNode : public ArkUINode {
        void ScrollBy(float offset) {
            ArkUI_NumberValue value[] = {{.f32 =0},{.f32 = offset}};
            ArkUI_AttributeItem Item = {.value = value, .size = 2};
            nativeModule_->setAttribute(handle_, NODE_SCROLL_BY, &Item);
        }
    };
    ```
## ListItem横划删除 

1. ListItem设置NODE_LIST_ITEM_SWIPE_ACTION属性，将ArkUI_ListItemSwipeActionOption对象作为属性参数传入。
    ```c++
    // ArkUIListItemNode.h 
    //提供列表项的封装类。 
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

2. 创建ListItem时，创建ListItem的划出组件，并绑定点击事件，在点击事件中执行删除数据源操作。ListItem复用时，更新划出组件的绑定事件。
    ```c++
    // ArkUIListItemAdapter.h 
    class ArkUIListItemAdapter { 
        //...
        //需要新的Item显示在可见区域。 
        void OnNewItemAttached(ArkUI_NodeAdapterEvent *event) { 
            auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event); 
            ArkUI_NodeHandle handle = nullptr; 
            if (!cachedItems_.empty()) { 
                //使用并更新回收复用的缓存。 
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
                //释放缓存池的引用。 
                cachedItems_.pop(); 
            } else { 
                //创建新的元素。 
                auto listItem = std::make_shared<ArkUIListItemNode>(); 
                auto textNode = std::make_shared<ArkUITextNode>();
                textNode->SetTextContent(data_[index]); 
                textNode->SetFontSize(16); 
                textNode->SetPercentWidth(1); 
                textNode->SetHeight(100); 
                textNode->SetBackgroundColor(0xFFfffacd); 
                textNode->SetTextAlign(ARKUI_TEXT_ALIGNMENT_CENTER);
                listItem->AddChild(textNode); 
                //创建ListItem划出菜单。 
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
                //保持文本列表项的引用。 
                items_.emplace(handle, listItem); 
            }
            //设置需要展示的元素。 
            OH_ArkUI_NodeAdapterEvent_SetItem(event, handle); 
        } 
    }
    ```
3. ArkUIListItemAdapter中新增RemoveItem，用于删除数据源并且调用OH_ArkUI_NodeAdapter_RemoveItem接口通知框架刷新UI。
    ```c++
    // ArkUIListItemAdapter.h 
    class ArkUIListItemAdapter { 
        //...
        void RemoveItem(size_t index) { 
            //删除第index个数据。 
            data_.erase(data_.begin() + index); 
            //如果index会导致可视区域元素发生可见性变化，则会回调NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER事件删除元素， 
            //根据是否有新增元素回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID和NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件。 
            OH_ArkUI_NodeAdapter_RemoveItem(handle_, index, 1); 
            //更新新的数量。 
            OH_ArkUI_NodeAdapter_SetTotalNodeCount(handle_, data_.size()); 
        } 
    };
    ```
## 使用分组列表 
1. 分组列表使用ListItemGroup组件实现，ListItemGroup支持添加header、footer设置函数，支持使用懒加载。
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
        //引入懒加载模块。 
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
2. List组件设置吸顶。
    ```c++
    // ArkUIListNode.h 
    //列表封装对象。 
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
3. List组件下使用ListItemGroup实现分组列表界面。
    ```c++
    // LazyTextListExample.h 
    //懒加载列表示例代码。 
    #ifndef MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H
    #define MYAPPLICATION_LAZYTEXTLISTEXAMPLE_H 
    #include "ArkUIBaseNode.h" 
    #include "ArkUIListNode.h" 
    #include "ArkUIListItemGroupNode.h" 
    namespace NativeModule { 
    std::shared_ptr<ArkUIBaseNode> CreateLazyTextListExample() { 
    //创建组件并挂载 
    //1: 创建List组件。 
        auto list = std::make_shared<ArkUIListNode>(); 
        list->SetPercentWidth(1); 
        list->SetPercentHeight(1); 
        //设置吸顶 
        list->SetSticky(ARKUI_STICKY_STYLE_BOTH); 
        //2: 创建ListItemGroup并挂载到List上。 
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


