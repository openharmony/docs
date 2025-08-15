# 使用瀑布流

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @fangyuhao-->
<!--Designer: @zcdqs-->
<!--Tester: @liuzhenshuo-->
<!--Adviser: @HelloCrease-->

ArkUI开发框架在NDK接口提供了瀑布流容器组件，通过瀑布流自身的排列规则，将不同大小的"项目"自上而下如瀑布般紧密布局。

## 接入ArkTS页面
为了使用NDK接口构建UI界面，参考[接入ArkTS页面章节](../ui/ndk-access-the-arkts-page.md)，在ArkTS页面上创建用于Native页面挂载的占位组件，并实现ArkTS侧的NativeNode模块接口。

## 使用懒加载
### NodeAdapter介绍 
NDK中提供了NodeAdapter对象替代ArkTS侧的LazyForeach功能，用于按需生成子组件。详情请参阅[NodeAdapter介绍](../ui/ndk-loading-long-list.md#nodeadapter介绍)。

### 实现懒加载适配器

使用FlowItemAdapter类管理懒加载适配器。在类的构造函数中创建NodeAdapter对象，并给NodeAdapter对象设置事件监听器，在类的析构函数中，销毁NodeAdapter对象。

```c++
// FlowItemAdapter.h
// 懒加载功能代码。

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
        
        // 初始化函数指针结构体
        OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nodeApi_);
        // 创建Adapter对象
        adapter_ = OH_ArkUI_NodeAdapter_Create();
        
        // 初始化懒加载数据。
        for (int32_t i = 0; i < 100; i++) {
            data_.emplace_back(std::to_string(i));
        }
        // 设置懒加载数据。
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(adapter_, data_.size());
        // 设置事件监听器。
        OH_ArkUI_NodeAdapter_RegisterEventReceiver(adapter_, this, OnStaticAdapterEvent);
    }

    ~FlowItemAdapter() {
        // 释放创建的组件。
        while (!cachedItems_.empty()) {
            cachedItems_.pop();
        }
        // 释放Adapter相关资源。
        OH_ArkUI_NodeAdapter_UnregisterEventReceiver(adapter_);
        OH_ArkUI_NodeAdapter_Dispose(adapter_);
    }

    ArkUI_NodeAdapterHandle GetAdapter() const { return adapter_; }

    void RemoveItem(int32_t index) {
        // 删除第index个数据。
        data_.erase(data_.begin() + index);
        // 如果index会导致可视区域元素发生可见性变化，则会回调NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER事件删除元素，
        // 根据是否有新增元素回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID和NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件。
        OH_ArkUI_NodeAdapter_RemoveItem(adapter_, index, 1);
        // 更新新的数量。
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(adapter_, data_.size());
    }

    void InsertItem(int32_t index, const std::string &value) {
        data_.insert(data_.begin() + index, value);
        // 如果index会导致可视区域元素发生可见性变化，则会回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID和NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件，
        // 根据是否有删除元素回调NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER事件。
        OH_ArkUI_NodeAdapter_InsertItem(adapter_, index, 1);
        // 更新新的数量。
        OH_ArkUI_NodeAdapter_SetTotalNodeCount(adapter_, data_.size());
    }

    void MoveItem(int32_t oldIndex, int32_t newIndex) {
        auto temp = data_[oldIndex];
        data_.insert(data_.begin() + newIndex, temp);
        data_.erase(data_.begin() + oldIndex);
        // 移到位置如果未发生可视区域内元素的可见性变化，则不回调事件，反之根据新增和删除场景回调对应的事件。
        OH_ArkUI_NodeAdapter_MoveItem(adapter_, oldIndex, newIndex);
    }

    void ReloadItem(int32_t index, const std::string &value) {
        data_[index] = value;
        // 如果index位于可视区域内，先回调NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER删除老元素，
        // 再回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID和NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件。
        OH_ArkUI_NodeAdapter_ReloadItem(adapter_, index, 1);
    }

    void ReloadAllItem() {
        std::reverse(data_.begin(), data_.end());
        // 全部重新加载场景下，会回调NODE_ADAPTER_EVENT_ON_GET_NODE_ID接口获取新的组件ID，
        // 根据新的组件ID进行对比，ID不发生变化的进行复用，
        // 针对新增ID的元素，调用NODE_ADAPTER_EVENT_ON_ADD_NODE_TO_ADAPTER事件创建新的组件，
        // 然后判断老数据中遗留的未使用ID，调用NODE_ADAPTER_EVENT_ON_REMOVE_NODE_FROM_ADAPTER删除老元素。
        OH_ArkUI_NodeAdapter_ReloadAllItems(adapter_);
    }

private:
    static void OnStaticAdapterEvent(ArkUI_NodeAdapterEvent *event) {
        // 获取实例对象，回调实例事件。
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
        // 设置生成组件的唯一标识符。
        auto hash = std::hash<std::string>();
        OH_ArkUI_NodeAdapterEvent_SetNodeId(event, hash(data_[index]));
    }
    
    void OnCreateNewChild(ArkUI_NodeAdapterEvent *event) {
        auto index = OH_ArkUI_NodeAdapterEvent_GetItemIndex(event);
        ArkUI_NodeHandle flowItem = nullptr;
        if (!cachedItems_.empty()) {
            // 复用缓存
            flowItem = cachedItems_.top();
            cachedItems_.pop();
            // 更新数据
            auto *text = nodeApi_->getFirstChild(flowItem);
            ArkUI_AttributeItem item{nullptr, 0, data_[index].c_str()};
            nodeApi_->setAttribute(text, NODE_TEXT_CONTENT, &item);
        } else {
            // 重新创建。
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
        // 缓存节点
        cachedItems_.emplace(node);
    }

    std::vector<std::string> data_;
    ArkUI_NativeNodeAPI_1 *nodeApi_ = nullptr;
    ArkUI_NodeAdapterHandle adapter_ = nullptr;

    // 管理回收复用组件池。
    std::stack<ArkUI_NodeHandle> cachedItems_;
};

} // namespace NativeModule

#endif //MYAPPLICATION_FLOWITEMADAPTER_H

```
## 创建分组
使用WaterflowSection类管理waterflow中的分组，其中SectionOption用于描述一个分段的各项配置信息。在类的构造函数中创建ArkUI_WaterFlowSectionOption对象，在析构函数中将其销毁。

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
    // {上外边距，右外边距，下外边距，左外边距}
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

## 创建瀑布流
使用ArkUIWaterflowNode类管理Waterflow。支持通过SetLazyAdapter为其设置一个FlowItemAdapter，通过SetSection为其设置分段。

```c++
//waterflow.h

#ifndef MYAPPLICATION_WATERFLOW_H
#define MYAPPLICATION_WATERFLOW_H

#include "FlowItemAdapter.h"
#include "WaterflowSection.h"

namespace NativeModule {
class ArkUIWaterflowNode {
public:
     
    ArkUIWaterflowNode() {
        
        OH_ArkUI_GetModuleInterface(ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, nodeApi_);
        // 创建Waterflow
        waterflow_ = nodeApi_->createNode(ARKUI_NODE_WATER_FLOW);
        
    }

    ~ArkUIWaterflowNode() {
        nodeApi_->disposeNode(waterflow_);

        // 销毁adapter
        adapter_.reset();
        
        // 销毁分段
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

#endif // MYAPPLICATION_WATERFLOW_H
```

## 使用瀑布流
创建一个ArkUIWaterflowNode类的实例，设置其宽高，并绑定NodeAdapter和分段。

```c++
// CreateWaterflowExample.h

#ifndef MYAPPLICATION_CREATEWATERFLOWEXAMPLE_H
#define MYAPPLICATION_CREATEWATERFLOWEXAMPLE_H
#include "waterflow.h"

namespace NativeModule {
std::shared_ptr<ArkUIWaterflowNode> CreateWaterflowExample() {
    // 创建Waterflow组件。
    auto waterflow = std::make_shared<ArkUIWaterflowNode>();
    waterflow->SetHeight(600);
    waterflow->SetWidth(400);
    
    // 绑定Adapter
    waterflow->SetLazyAdapter(std::make_shared<FlowItemAdapter>());
    
    // 设置分段
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