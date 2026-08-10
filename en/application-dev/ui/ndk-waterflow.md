# Implementing a Waterfall Flow Layout

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @rongShao-Z; @guozejun-->
<!--Designer: @guozejun-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=ff57662bf139c28533f638cb6ca96282ab069c0d translatedAt=2026-08-05T10:09:11.032Z pushedAt=2026-08-06T06:14:23.357Z -->

The ArkUI framework provides a waterfall flow container component through NDK APIs. This component arranges items of different sizes in a waterfall-like manner from top to bottom.

## Integrating with ArkTS Pages

To use the NDK APIs for building UIs, follow the instructions in [Integrating with ArkTS Pages](../ui/ndk-access-the-arkts-page.md). This involves creating a placeholder component on the ArkTS page for mounting the native page and implementing the **NativeNode** module APIs on the ArkTS side.

## Implementing Lazy Loading

### NodeAdapter Overview

The NDK provides the **NodeAdapter** object to replace the [LazyForEach](../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md) function on the ArkTS side for generating child components as needed. For details, see [NodeAdapter Overview](../ui/ndk-loading-long-list.md#nodeadapter-overview).

### Lazy Loading Adapter Implementation

Use the **FlowItemAdapter** class to manage the lazy loading adapter. Create a **NodeAdapter** object in the class constructor with event listeners, and destroy it in the class destructor.

<!-- @[flow_item_adapter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKWaterFlowSample/entry/src/main/cpp/FlowItemAdapter.h) -->

``` C
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
const int NUM = 100;
class FlowItemAdapter {
public:
    FlowItemAdapter()
    {
        // Initialize the function pointer structure.
        OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nodeApi_);
        // Create a NodeAdapter object.
        adapter_ = OH_ArkUI_NodeAdapter_Create();
        
        // Initialize lazy loading data.
        for (int32_t i = 0; i < NUM; i++) {
            data_.emplace_back(std::to_string(i));
        }
        // Set the total number of items for lazy loading.
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(adapter_, data_.size());
        // Set the event listener.
        OH_ArkUI_NodeAdapter_RegisterEventReceiver(adapter_, this, OnStaticAdapterEvent);
    }

    ~FlowItemAdapter()
    {
        // Release created components.
        while (!cachedItems_.empty()) {
            nodeApi_->disposeNode(cachedItems_.top());
            cachedItems_.pop();
        }
        // Release adapter resources.
        OH_ArkUI_NodeAdapter_UnregisterEventReceiver(adapter_);
        OH_ArkUI_NodeAdapter_Dispose(adapter_);
    }

    ArkUI_NodeAdapterHandle GetAdapter() const { return adapter_; }

    void RemoveItem(int32_t index)
    {
        // Remove the item at the specified index.
        data_.erase(data_.begin() + index);
        // If the index change affects the visibility of items in the visible area, the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event will be triggered to remove the element.
        // If items are added, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID and NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER events will be triggered accordingly.
        OH_ArkUI_NodeAdapter_RemoveItem(adapter_, index, 1);
        // Update the total count.
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(adapter_, data_.size());
    }

    void InsertItem(int32_t index, const std::string &value)
    {
        data_.insert(data_.begin() + index, value);
        // If the index change affects the visibility of elements in the visible area, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID and NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER events will be triggered.
        // If items are removed, the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event will be triggered accordingly.
        OH_ArkUI_NodeAdapter_InsertItem(adapter_, index, 1);
        // Update the total count.
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(adapter_, data_.size());
    }

    void MoveItem(int32_t oldIndex, int32_t newIndex)
    {
        auto temp = data_[oldIndex];
        data_.insert(data_.begin() + newIndex, temp);
        data_.erase(data_.begin() + oldIndex);
        // If the move changes the visibility of items within the visible area, the corresponding events will be triggered.
        OH_ArkUI_NodeAdapter_MoveItem(adapter_, oldIndex, newIndex);
    }

    void ReloadItem(int32_t index, const std::string &value)
    {
        data_[index] = value;
        // If the index is within the visible area, first trigger the NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER event to remove the old item,
        // then trigger the NODE_ADAPTER_EVENT_ON_GET_NODE_ID and NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER events.
        OH_ArkUI_NodeAdapter_ReloadItem(adapter_, index, 1);
    }

    void ReloadAllItem()
    {
        std::reverse(data_.begin(), data_.end());
        // In the scenario where all items are reloaded, the NODE_ADAPTER_EVENT_ON_GET_NODE_ID event will be triggered to obtain new component IDs,
        // compare the new component IDs, and reuse those whose IDs have not changed;
        // for items with new IDs, trigger the NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER event to create new components,
        // then identify any unused IDs from the old data and call NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER to remove the old items.
        OH_ArkUI_NodeAdapter_ReloadAllItems(adapter_);
    }

private:
    static void OnStaticAdapterEvent(ArkUI_NodeAdapterEvent *event)
    {
        // Obtain the instance object and invoke the instance event callback.
        auto itemAdapter = reinterpret_cast<FlowItemAdapter *>(OH_ArkUI_NodeAdapterEvent_GetUserData(event));
        itemAdapter->OnAdapterEvent(event);
    }

    void OnAdapterEvent(ArkUI_NodeAdapterEvent *event)
    {
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
    
    void OnGetChildId(ArkUI_NodeAdapterEvent *event)
    {
        auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
        // Set the unique identifier for the generated component.
        auto hash = std::hash<std::string>();
        OH_ArkUI_NodeAdapterEvent_SetNodeId(event, hash(data_[index]));
    }
    
    void OnCreateNewChild(ArkUI_NodeAdapterEvent *event)
    {
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
            value[0] = {.u32 = 0xFFD3D3D3};
            ArkUI_AttributeItem backgroundColor{value, 1};

            nodeApi_->setAttribute(flowItem, NODE_BACKGROUND_COLOR, &backgroundColor);
            nodeApi_->addChild(flowItem, text);
        }
        OH_ArkUI_NodeAdapterEvent_SetItem(event, flowItem);
    }
    
    void OnDisposeChild(ArkUI_NodeAdapterEvent *event)
    {
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

#endif // MYAPPLICATION_FLOWITEMADAPTER_H
```

### Updating and Reusing FlowItem

When reusing **FlowItem** through **NodeAdapter**, keep the node structure of **FlowItem** and its direct child components stable, and update the content or style of existing child components through [setAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute). In the example above, only the text content of the existing **Text** component is updated when **FlowItem** is reused.

> **NOTE**
>
> For a **FlowItem** that is already displayed and has a fixed size, do not call [removeChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#removechild) to remove its direct child components and then call [addChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addchild) to mount new direct child components during **WaterFlow** scrolling. This approach may cause the newly mounted child components to not participate in layout in time, resulting in display anomalies.
>
> To update complex content, use one of the following approaches:
>
> - Keep the direct container of FlowItem (such as [Stack](../reference/apis-arkui/arkui-ts/ts-container-stack.md) or [Column](../reference/apis-arkui/arkui-ts/ts-container-column.md)) unchanged, and update only the content inside the container.
> - Create a new **FlowItem** with its complete subtree, and call [OH_ArkUI_NodeAdapter_ReloadItem](../reference/apis-arkui/capi-native-node-h.md#oh_arkui_nodeadapter_reloaditem) to notify **NodeAdapter** to update the corresponding data item.

## Creating a Section

Use the **WaterflowSection** class to manage groups in [WaterFlow](../reference/apis-arkui/arkui-ts/ts-container-waterflow.md). **SectionOption** is used to describe the configuration information of a section. Create a [ArkUI_WaterFlowSectionOption](../reference/apis-arkui/capi-arkui-nativemodule-arkui-waterflowsectionoption.md) object in the constructor of the class and destroy it in the destructor.

<!-- @[waterflow_section](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKWaterFlowSample/entry/src/main/cpp/WaterflowSection.h) -->

``` C
// WaterflowSection.h

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
    // {Top margin, right margin, bottom margin, left margin}
    ArkUI_Margin margin{0, 0, 0, 0};
    float (*onGetItemMainSizeByIndex)(int32_t itemIndex);
    void *userData;
};

class WaterflowSection {
public:
    WaterflowSection() : sectionOptions_(OH_ArkUI_WaterFlowSectionOption_Create()){};
    
    ~WaterflowSection()
    {
        OH_ArkUI_WaterFlowSectionOption_Dispose(sectionOptions_);
    }

    void SetSection(ArkUI_WaterFlowSectionOption *sectionOptions, int32_t index, SectionOption section)
    {
        OH_ArkUI_WaterFlowSectionOption_SetItemCount(sectionOptions, index, section.itemsCount);
        OH_ArkUI_WaterFlowSectionOption_SetCrossCount(sectionOptions, index, section.crossCount);
        OH_ArkUI_WaterFlowSectionOption_SetColumnGap(sectionOptions, index, section.columnsGap);
        OH_ArkUI_WaterFlowSectionOption_SetRowGap(sectionOptions, index, section.rowsGap);
        OH_ArkUI_WaterFlowSectionOption_SetMargin(sectionOptions, index, section.margin.top, section.margin.right,
                                                  section.margin.bottom, section.margin.left);
        OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex(sectionOptions, index,
                                                                               section.onGetItemMainSizeByIndex);
    }
    
    ArkUI_WaterFlowSectionOption *GetSectionOptions() const
    {
        return sectionOptions_;
    }
    
    void PrintSectionOptions()
    {
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

<!-- @[waterflow_define](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKWaterFlowSample/entry/src/main/cpp/waterflow.h) -->

``` C
// waterflow.h
#ifndef MYAPPLICATION_WATERFLOW_H
#define MYAPPLICATION_WATERFLOW_H
  
#include "FlowItemAdapter.h"
#include "WaterflowSection.h"
#include "ArkUINode.h"
  
namespace NativeModule {
  
class ArkUIWaterflowNode : public ArkUINode {
public:
    ArkUIWaterflowNode()
        : ArkUINode(CreateWaterflowNode()) {}
  
    ~ArkUIWaterflowNode() override
    {
        // First unregister the adapter.
        if (adapter_ && nativeModule_) {
            nativeModule_->resetAttribute(handle_, NODE_WATER_FLOW_NODE_ADAPTER);
            adapter_.reset();
        }
        // Destroy sections.
        section_.reset();
        // The base class automatically handles handle_ disposal.
    }

    void SetLazyAdapter(const std::shared_ptr<FlowItemAdapter> &adapter)
    {
        ArkUI_AttributeItem item{nullptr, 0, nullptr, adapter->GetAdapter()};
        nativeModule_->setAttribute(handle_, NODE_WATER_FLOW_NODE_ADAPTER, &item);
        adapter_ = adapter;
    }
  
    void SetSection(const std::shared_ptr<WaterflowSection> &section)
    {
        if (!section->GetSectionOptions()) {
            return;
        }
        ArkUI_NumberValue start[] = {{.i32 = 0}};
        ArkUI_AttributeItem optionsItem = {start, 1, nullptr, section->GetSectionOptions()};
        nativeModule_->setAttribute(handle_, NODE_WATER_FLOW_SECTION_OPTION, &optionsItem);
        section_ = section;
    }
  
    std::shared_ptr<WaterflowSection> GetWaterflowSection() { return section_; }
  
private:
    static ArkUI_NodeHandle CreateWaterflowNode()
    {
        ArkUI_NativeNodeAPI_1* api = nullptr;
        OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, api);
        if (!api) {
            return nullptr;
        }
        return api->createNode(ARKUI_NODE_WATER_FLOW);
    }
  
    std::shared_ptr<WaterflowSection> section_ = nullptr;
    std::shared_ptr<FlowItemAdapter> adapter_;
};
  
} // namespace NativeModule
  
#endif // MYAPPLICATION_WATERFLOW_H
```

## Implementing a WaterFlow Component

Create an instance of the **ArkUIWaterflowNode** class, set its width and height, and bind the **NodeAdapter** and sections.

<!-- @[create_waterflow_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKWaterFlowSample/entry/src/main/cpp/CreateWaterflowExample.h) -->

``` C
// CreateWaterflowExample.h

#ifndef MYAPPLICATION_CREATEWATERFLOWEXAMPLE_H
#define MYAPPLICATION_CREATEWATERFLOWEXAMPLE_H
#include "waterflow.h"

namespace NativeModule {
const int UI_WIDTH = 400;
const int UI_HEIGHT = 600;
const int SECTION_COUNT = 10;
const int SECTION_2_ID = 2;

inline void SetupSections(std::shared_ptr<WaterflowSection> sections)
{
    SectionOption MARGIN_GAP_SECTION_1 = {10, 2, 10, 10, {20, 30, 40, 50}, nullptr, nullptr};
    SectionOption MARGIN_GAP_SECTION_2 = {10, 4, 10, 10, {20, 30, 40, 50}, nullptr, nullptr};
    for (int i = 0; i < SECTION_COUNT; i++) {
        sections->SetSection(sections->GetSectionOptions(), i,
                             i % SECTION_2_ID ? MARGIN_GAP_SECTION_1 : MARGIN_GAP_SECTION_2);
    }
}

inline std::shared_ptr<ArkUIWaterflowNode> CreateWaterflowExample(napi_env env)
{
    auto waterflow = std::make_shared<ArkUIWaterflowNode>();
    waterflow->SetHeight(UI_HEIGHT);
    waterflow->SetWidth(UI_WIDTH);
    waterflow->SetLazyAdapter(std::make_shared<FlowItemAdapter>());
    auto sections = std::make_shared<WaterflowSection>();
    SetupSections(sections);
    waterflow->SetSection(sections);
    return waterflow;
}
} // namespace NativeModule

#endif // MYAPPLICATION_CREATEWATERFLOWEXAMPLE_H
```

![image](figures/UIWaterflow.gif)