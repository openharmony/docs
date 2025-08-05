# Implementing a Waterfall Flow Layout

The ArkUI framework provides a waterfall flow container component through NDK APIs. This component arranges items of different sizes in a waterfall-like manner from top to bottom.

## Integrating with ArkTS Pages
To use the NDK APIs for building UIs, follow the instructions in [Integrating with ArkTS Pages](../ui/ndk-access-the-arkts-page.md). This involves creating a placeholder component on the ArkTS page for mounting the native page and implementing the **NativeNode** module APIs on the ArkTS side.

## Implementing Lazy Loading
### NodeAdapter Overview
The NDK provides the **NodeAdapter** object as an alternative to the **LazyForEach** functionality in ArkTS for on-demand generation of child components. For details, see [NodeAdapter Overview](../ui/ndk-loading-long-list.md#nodeadapter-overview).

### Lazy Loading Adapter Implementation

Use the **FlowItemAdapter** class to manage the lazy loading adapter. Create a **NodeAdapter** object in the class constructor with event listeners, and destroy it in the class destructor.

```c++
// FlowItemAdapter.h
// Lazy loading implementation

#ifndef MYAPPLICATION_FLOWITEMADAPTER_H
#define MYAPPLICATION_FLOWITEMADAPTER_H

#include <arkui/native_node.h>
#include <stack>
#include <string>
#include <unordered_set>
#include <arkui/native_interface.h>

namespace NativeModule {

class FlowItemAdapter {
public:
    FlowItemAdapter(){
        
        // Initialize the function pointer structure.
        OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nodeApi_);
        // Create a NodeAdapter object.
        adapter_ = OH_ArkUI_NodeAdapter_Create();
        
        // Initialize lazy loading data.
        for (int32_t i = 0; i < 100; i++) {
            data_.emplace_back(std::to_string(i));
        }
        // Set the total number of items for lazy loading.
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(adapter_, data_.size());
        // Set the event listener.
        OH_ArkUI_NodeAdapter_RegisterEventReceiver(adapter_, this, OnStaticAdapterEvent);
    }

    ~FlowItemAdapter() {
        // Release created components.
        while (!cachedItems_.empty()) {
            cachedItems_.pop();
        }
        // Release adapter resources.
        OH_ArkUI_NodeAdapter_UnregisterEventReceiver(adapter_);
        OH_ArkUI_NodeAdapter_Dispose(adapter_);
    }

    ArkUI_NodeAdapterHandle GetAdapter() const { return adapter_; }

    void RemoveItem(int32_t index) {
        // Remove the item at the specified index.
        data_.erase(data_.begin() + index);
        // If the index change affects the visibility of items in the visible area, the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event will be triggered to remove the element.
        // If items are added, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID and NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER events will be triggered accordingly.
        OH_ArkUI_NodeAdapter_RemoveItem(adapter_, index, 1);
        // Update the total count.
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(adapter_, data_.size());
    }

    void InsertItem(int32_t index, const std::string &value) {
        data_.insert(data_.begin() + index, value);
        // If the index change affects the visibility of elements in the visible area, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID and NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER events will be triggered.
        // If items are removed, the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event will be triggered accordingly.
        OH_ArkUI_NodeAdapter_InsertItem(adapter_, index, 1);
        // Update the total count.
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(adapter_, data_.size());
    }

    void MoveItem(int32_t oldIndex, int32_t newIndex) {
        auto temp = data_[oldIndex];
        data_.insert(data_.begin() + newIndex, temp);
        data_.erase(data_.begin() + oldIndex);
        // If the move changes the visibility of items within the visible area, the corresponding events will be triggered.
        OH_ArkUI_NodeAdapter_MoveItem(adapter_, oldIndex, newIndex);
    }

    void ReloadItem(int32_t index, const std::string &value) {
        data_[index] = value;
        // If the index is within the visible area, first trigger the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event to remove the old item,
        // then trigger the NODE_ADAPTER_EVENT_ON_GET_NODE_ID and NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER events.
        OH_ArkUI_NodeAdapter_ReloadItem(adapter_, index, 1);
    }

    void ReloadAllItem() {
        std::reverse(data_.begin(), data_.end());
        // In the scenario where all items are reloaded, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID event will be triggered to obtain new component IDs,
        // compare the new component IDs, and reuse those whose IDs have not changed;
        // for items with new IDs, trigger the NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER event to create new components,
        // then identify any unused IDs from the old data and call NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER to remove the old items.
        OH_ArkUI_NodeAdapter_ReloadAllItems(adapter_);
    }

private:
    static void OnStaticAdapterEvent(ArkUI_NodeAdapterEvent *event) {
        // Obtain the instance object and invoke the instance event callback.
        auto itemAdapter = reinterpret_cast<FlowItemAdapter *>(OH_ArkUI_NodeAdapterEvent_GetUserData(event));
        itemAdapter->OnAdapterEvent(event);
    }

    void OnAdapterEvent(ArkUI_NodeAdapterEvent *event) {
        auto type = OH_ArkUI_NodeAdapterEvent_GetType(event);
        switch (type) {
        case NODE_ADAPTER_EVENT_ON_GET_NODE_ID:
            OnGetChildId(event);
            break;
        case NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER:
            OnCreateNewChild(event);
            break;
        case NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER:
            OnDisposeChild(event);
            break;
        default:
            break;
        }
    }
    
    void OnGetChildId(ArkUI_NodeAdapterEvent *event) {
        auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
        // Set the unique identifier for the generated component.
        auto hash = std::hash<std::string>();
        OH_ArkUI_NodeAdapterEvent_SetNodeId(event, hash(data_[index]));
    }
    
    void OnCreateNewChild(ArkUI_NodeAdapterEvent *event) {
        auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
        ArkUI_NodeHandle flowItem = nullptr;
        if (!cachedItems_.empty()) {
            // Reuse cached items.
            flowItem = cachedItems_.top();
            cachedItems_.pop();
            // Update data.
            auto *text = nodeApi_->getFirstChild(flowItem);
            ArkUI_AttributeItem item{nullptr, 0, data_[index].c_str()};
            nodeApi_->setAttribute(text, NODE_TEXT_CONTENT, &item);
        } else {
            // Create an item.
            auto *text = nodeApi_->createNode(ARKUI_NODE_TEXT);
            ArkUI_AttributeItem item{nullptr, 0, data_[index].c_str()};
            nodeApi_->setAttribute(text, NODE_TEXT_CONTENT, &item);
            flowItem = nodeApi_->createNode(ARKUI_NODE_FLOW_ITEM);
            ArkUI_NumberValue value[] = {100};
            ArkUI_AttributeItem height{value, 1};
            nodeApi_->setAttribute(flowItem, NODE_HEIGHT, &height);
            value[0] = {1};
            ArkUI_AttributeItem width{value, 1};
            nodeApi_->setAttribute(flowItem, NODE_WIDTH_PERCENT, &width);
            value[0] = {.u32 = 0xFFFF0000};
            ArkUI_AttributeItem backgroundColor{value, 1};

            nodeApi_->setAttribute(flowItem, NODE_BACKGROUND_COLOR, &backgroundColor);
            nodeApi_->addChild(flowItem, text);
        }
        OH_ArkUI_NodeAdapterEvent_SetItem(event, flowItem);
    }
    
    void OnDisposeChild(ArkUI_NodeAdapterEvent *event) {
        auto *node = OH_ArkUI_NodeAdapterEvent_GetRemovedNode(event);
        // Cache the node.
        cachedItems_.emplace(node);
    }

    std::vector<std::string> data_;
    ArkUI_NativeNodeAPI_1 *nodeApi_ = nullptr;
    ArkUI_NodeAdapterHandle adapter_ = nullptr;

    // Manage the component reuse pool.
    std::stack<ArkUI_NodeHandle> cachedItems_;
};

} // namespace NativeModule

#endif //MYAPPLICATION_FLOWITEMADAPTER_H

```
## Creating a Section
Implement the **WaterflowSection** class to manage grouping within WaterFlow components, where **SectionOption** describes the configuration parameters for each section. In the class constructor, create an **ArkUI_WaterFlowSectionOption** object, which is destroyed in the destructor.

```c++
//WaterflowSection.h

#ifndef MYAPPLICATION_WATERFLOWSECTION_H
#define MYAPPLICATION_WATERFLOWSECTION_H

#include <arkui/native_node.h>
#include <hilog/log.h>

namespace NativeModule {

struct SectionOption {
    int32_t itemsCount = 0;
    int32_t crossCount;
    float columnsGap;
    float rowsGap;
    // top right bottom left
    ArkUI_Margin margin{0, 0, 0, 0};
    float (*onGetItemMainSizeByIndex)(int32_t itemIndex);
    void *userData;
};

class WaterflowSection {
public:
    WaterflowSection() : sectionOptions_(OH_ArkUI_WaterFlowSectionOption_Create()){};
    
    ~WaterflowSection(){
        OH_ArkUI_WaterFlowSectionOption_Dispose(sectionOptions_);
    }

    void SetSection(ArkUI_WaterFlowSectionOption *sectionOptions, int32_t index, SectionOption section) {
        OH_ArkUI_WaterFlowSectionOption_SetItemCount(sectionOptions, index, section.itemsCount);
        OH_ArkUI_WaterFlowSectionOption_SetCrossCount(sectionOptions, index, section.crossCount);
        OH_ArkUI_WaterFlowSectionOption_SetColumnGap(sectionOptions, index, section.columnsGap);
        OH_ArkUI_WaterFlowSectionOption_SetRowGap(sectionOptions, index, section.rowsGap);
        OH_ArkUI_WaterFlowSectionOption_SetMargin(sectionOptions, index, section.margin.top, section.margin.right,
                                                  section.margin.bottom, section.margin.left);
        OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex(sectionOptions, index,
                                                                               section.onGetItemMainSizeByIndex);
    }
    
    ArkUI_WaterFlowSectionOption *GetSectionOptions() const {
        return sectionOptions_;
    }
    
    void PrintSectionOptions() {
        int32_t sectionCnt = OH_ArkUI_WaterFlowSectionOption_GetSize(sectionOptions_);
        for (int32_t i = 0; i < sectionCnt; i++) {
            ArkUI_Margin margin = OH_ArkUI_WaterFlowSectionOption_GetMargin(sectionOptions_, i);
            OH_LOG_Print(LOG_APP, LOG_INFO, LOG_DOMAIN, "CreateWaterflowExample",
                        "Section[%{public}d].margin:{%{public}f, %{public}f, %{public}f, %{public}f}", i, margin.top,
                        margin.right, margin.bottom, margin.left);
        }
    }

private:
    ArkUI_WaterFlowSectionOption *sectionOptions_ = nullptr;
};
} // namespace NativeModule

#endif // MYAPPLICATION_WATERFLOWSECTION_H

```

## Creating a WaterFlow Component
Implement the **ArkUIWaterflowNode** class to manage **WaterFlow** components. This class supports configuration through **SetLazyAdapter** for assigning a **FlowItemAdapter** and **SetSection** for defining sections.

```c++
//Waterflow.h

#ifndef MYAPPLICATION_WATERFLOWE_H
#define MYAPPLICATION_WATERFLOWE_H

#include "FlowItemAdapter.h"
#include "WaterflowSection.h"

namespace NativeModule {
class ArkUIWaterflowNode {
public:
     
    ArkUIWaterflowNode() {
        
        OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nodeApi_);
        // Create a Waterflow component.
        waterflow_ = nodeApi_->createNode(ARKUI_NODE_WATER_FLOW);
        
    }

    ~ArkUIWaterflowNode() {
        nodeApi_->disposeNode(waterflow_);

        // Destroy the adapter.
        adapter_.reset();
        
        // Destroy sections.
        section_.reset();
    }
    
    void SetWidth(float width) {
        ArkUI_NumberValue value[] = {{.f32 = width}};
        ArkUI_AttributeItem item = {value, 1};
        nodeApi_->setAttribute(waterflow_, NODE_WIDTH, &item);
    }
    
    void SetHeight(float height) {
        ArkUI_NumberValue value[] = {{.f32 = height}};
        ArkUI_AttributeItem item = {value, 1};
        nodeApi_->setAttribute(waterflow_, NODE_HEIGHT, &item);
    }
    
    void SetLazyAdapter(const std::shared_ptr<FlowItemAdapter> &adapter) {
        ArkUI_AttributeItem item{nullptr,0, nullptr, adapter->GetAdapter()}; 
        nodeApi_->setAttribute(waterflow_, NODE_WATER_FLOW_NODE_ADAPTER, &item); 
        adapter_ = adapter; 
    } 
    
    void SetSection(const std::shared_ptr<WaterflowSection> &section) {
        ArkUI_NumberValue start[] = {{.i32 = 0}};
        ArkUI_AttributeItem optionsItem = {start, 1, nullptr, section->GetSectionOptions()};
        if(!section->GetSectionOptions()){
            return;
        }
        nodeApi_->setAttribute(waterflow_, NODE_WATER_FLOW_SECTION_OPTION, &optionsItem);
        section_ = section;
    } 

    ArkUI_NodeHandle GetWaterflow() { return waterflow_; }

    std::shared_ptr<WaterflowSection> GetWaterflowSection() { return section_; }

public:
    ArkUI_NativeNodeAPI_1 *nodeApi_ = nullptr;
    ArkUI_NodeHandle waterflow_ = nullptr;
    
    std::shared_ptr<WaterflowSection> section_ = nullptr;
    
    std::shared_ptr<FlowItemAdapter> adapter_;
};
}// namespace NativeModule

#endif // MYAPPLICATION_WATERFLOWE_H
```

## Implementing a WaterFlow Component
Create an instance of the **ArkUIWaterflowNode** class, set its width and height, and bind the **NodeAdapter** and sections.

```c++
// CreateWaterflowExample.h

#ifndef MYAPPLICATION_CREATEWATERFLOWEXAMPLE_H
#define MYAPPLICATION_CREATEWATERFLOWEXAMPLE_H
#include "waterflow.h"

namespace NativeModule {
std::shared_ptr<ArkUIWaterflowNode> CreateWaterflowExample() {
    // Create a WaterFlow component.
    auto waterflow = std::make_shared<ArkUIWaterflowNode>();
    waterflow->SetHeight(600);
    waterflow->SetWidth(400);
    
    // Configure the adapter.
    waterflow->SetLazyAdapter(std::make_shared<FlowItemAdapter>());
    
    // Set sections.
    auto sections = std::make_shared<WaterflowSection>();
    SectionOption MARGIN_GAP_SECTION_1 = {10, 2, 10, 10, margin : {20, 30, 40, 50}, nullptr, nullptr};
    SectionOption MARGIN_GAP_SECTION_2 = {10, 4, 10, 10, margin : {20, 30, 40, 50}, nullptr, nullptr};
    for (int i = 0; i < 10; i++) {
        sections->SetSection(sections->GetSectionOptions(), i, i % 2 ? MARGIN_GAP_SECTION_1 : MARGIN_GAP_SECTION_2);
    }
    waterflow->SetSection(sections);

    return waterflow;
}
} // namespace NativeModule

#endif // MYAPPLICATION_CREATEWATERFLOWEXAMPLE_H

```
