# Using Layout Components

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @camlostshi-->
<!--Designer: @camlostshi-->
<!--Tester: @weixin_45530366-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=087470085268b4c7968360a1498b1da15f27d467 translatedAt=2026-07-06T13:07:18.465Z pushedAt=2026-07-09T11:31:54.115Z -->

Starting from API version 12, ArkUI provides node types and attribute setting APIs in the NDK for common layout components: [Flex](../reference/apis-arkui/arkui-ts/ts-container-flex.md), [Row](../reference/apis-arkui/arkui-ts/ts-container-row.md), [Column](../reference/apis-arkui/arkui-ts/ts-container-column.md), and [Stack](../reference/apis-arkui/arkui-ts/ts-container-stack.md). **Flex** is used for flex layout, **Row** and **Column** for linear layout, and **Stack** for stacked layout. For the corresponding node types and attribute setting enums, refer to [ArkUI_NodeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodetype).

This document uses the flex component **Flex** as an example to provide development guidance for integrating layout components and setting attributes in the NDK. This example only shows the core function code. For the complete example, refer to <!--RP1-->[NDKFlexSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NDKFlexSample)<!--RP1End-->. Before implementation, you need to integrate the ArkTS page. For specific integration methods, refer to [Integrating with ArkTS Pages](../ui/ndk-access-the-arkts-page.md).

## Encapsulating the Container Component

Create a **Flex** node by calling the [createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) API and passing in `ARKUI_NODE_FLEX` from `ArkUI_NodeType`. The following example encapsulates this node as `ArkUIFlexNode` and uses the [setAttribute](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#setattribute) API with `NODE_FLEX_OPTION` to set the main axis direction, wrapping, and alignment. The five parameters in `ArkUI_NumberValue` are used to control different flex layout behaviors. For details, refer to [FlexOptions Object Description](../reference/apis-arkui/arkui-ts/ts-container-flex.md#flexoptions).

<!-- @[flex_flex_node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKFlexSample/entry/src/main/cpp/ArkUIFlexNode.h) -->

``` C
class ArkUIFlexNode : public ArkUINode {
public:
    ArkUIFlexNode()
        : ArkUINode((NativeModuleInstance::GetInstance()->GetNativeNodeAPI())->createNode(ARKUI_NODE_FLEX)) {}

    ~ArkUIFlexNode() override = default;

    void SetFlexOption(ArkUI_FlexDirection direction, ArkUI_FlexWrap wrap, ArkUI_FlexAlignment justifyContent,
        ArkUI_ItemAlignment alignItems, ArkUI_FlexAlignment alignContent)
    {
        ArkUI_NumberValue value[] = {
            {.i32 = direction},
            {.i32 = wrap},
            {.i32 = justifyContent},
            {.i32 = alignItems},
            {.i32 = alignContent}
        };
        ArkUI_AttributeItem item = {value, 5};
        nativeModule_->setAttribute(handle_, NODE_FLEX_OPTION, &item);
    }
};
```

After the node is created, a Flex component with a preset style is constructed using the pre-implemented common attributes and the SetFlexOption implemented above. The following code shows how to set the container to arrange child components in rows, automatically wrap when child components exceed the width, and start layout from the beginning of each row by default.

<!-- @[flex_container_helper](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKFlexSample/entry/src/main/cpp/FlexLayoutExample.h) -->

``` C
inline std::shared_ptr<ArkUIFlexNode> CreateFlexContainer()
{
    auto flex = std::make_shared<ArkUIFlexNode>();
    flex->SetPercentWidth(FULL_SIZE);
    flex->SetHeight(SECTION_HEIGHT_LARGE);
    flex->SetBackgroundColor(SECTION_BACKGROUND_COLOR);
    flex->SetFlexOption(ARKUI_FLEX_DIRECTION_ROW, ARKUI_FLEX_WRAP_WRAP, ARKUI_FLEX_ALIGNMENT_START,
        ARKUI_ITEM_ALIGNMENT_CENTER, ARKUI_FLEX_ALIGNMENT_START);
    return flex;
}
```

## Adding a Child Component

The following example adds a group of child components to the flex container. To demonstrate the wrapping and cross-axis alignment effects, a separate height and [alignSelf](../reference/apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#alignself) are set for the third child component. **alignSelf** is a common component attribute that takes effect within a flex container. By encapsulating this attribute setting into the custom API **SetAlignSelf** and applying it to a specified component via **NODE_ALIGN_SELF**, you can control the alignment format of a single child component on the parent container's cross axis, and its priority is higher than the container's [alignItems](../reference/apis-arkui/arkui-ts/ts-container-flex.md#flexoptions) attribute.

<!-- @[flex_align_self_helper](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKFlexSample/entry/src/main/cpp/FlexLayoutExample.h) -->

``` C
inline void SetAlignSelf(const std::shared_ptr<ArkUIBaseNode> &node, ArkUI_ItemAlignment align)
{
    ArkUI_NumberValue value[] = {{.i32 = align}};
    ArkUI_AttributeItem item = {value, 1};
    NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->setAttribute(node->GetHandle(), NODE_ALIGN_SELF, &item);
}
```

<!-- @[flex_align_self_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKFlexSample/entry/src/main/cpp/FlexLayoutExample.h) -->

``` C
inline std::shared_ptr<ArkUITextNode> CreateFlexExampleItem(int32_t index, uint32_t bgColor)
{
    auto item = CreateFixedItem("Flex " + std::to_string(index + 1), bgColor);
    if (index == ALIGN_SELF_ITEM_INDEX) { item->SetHeight(ALIGN_SELF_ITEM_HEIGHT); }
    if (index == ALIGN_SELF_ITEM_INDEX) { SetAlignSelf(item, ARKUI_ITEM_ALIGNMENT_END); }
    return item;
}
```

On this basis, create six child components and add them to the same **Flex** component.

<!-- @[flex_container_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKFlexSample/entry/src/main/cpp/FlexLayoutExample.h) -->

``` C
inline std::array<uint32_t, FLEX_ITEM_COUNT> CreateFlexColorSet()
{
    return {FLEX_ITEM_BLUE, FLEX_ITEM_GREEN, FLEX_ITEM_ORANGE, FLEX_ITEM_PINK, FLEX_ITEM_PURPLE, FLEX_ITEM_TEAL};
}

inline std::shared_ptr<ArkUIFlexNode> CreateFlexWrapExample()
{
    auto flex = CreateFlexContainer();
    const auto flexColors = CreateFlexColorSet();
    for (int32_t index = 0; index < static_cast<int32_t>(flexColors.size()); ++index) { // Loop through the array and add a group of child nodes
        flex->AddChild(CreateFlexExampleItem(index, flexColors[index]));
    }
    return flex;
}
```

At this point, **CreateFlexContainer()** has set the flex component's wrap behavior to **ARKUI_FLEX_WRAP_WRAP**, so when the total width of child components exceeds the container width, the layout automatically wraps; and after the third child component calls **SetAlignSelf()**, it will be positioned according to its own cross-axis alignment rule, rather than using the container's **ARKUI_ITEM_ALIGNMENT_CENTER** setting.

![wrap_alignself](figures/layout_container_wrap_alignself.jpg)

If you want to change the layout direction to vertical, you can change direction to **ARKUI_FLEX_DIRECTION_COLUMN**. In this case, the code structure remains unchanged, and the positioning logic on the main axis and cross axis also remains consistent.

## Using flexBasis, flexGrow, and flexShrink to Control Stretch Behavior

**Flex** can not only control the arrangement direction of child components, but also control the distribution of remaining space on the main axis. Through the three attributes [flexBasis](../reference/apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexbasis), [flexGrow](../reference/apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexgrow), and [flexShrink](../reference/apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexshrink), you can control the stretch behavior of child components within a **Flex** container.

<!-- @[flex_grow_helper](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKFlexSample/entry/src/main/cpp/FlexLayoutExample.h) -->

``` C
inline void SetFlexGrow(const std::shared_ptr<ArkUIBaseNode> &node, float grow)
{
    ArkUI_NumberValue value[] = {{.f32 = grow}};
    ArkUI_AttributeItem item = {value, 1};
    NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->setAttribute(node->GetHandle(), NODE_FLEX_GROW, &item);
}

inline void SetFlexShrink(const std::shared_ptr<ArkUIBaseNode> &node, float shrink)
{
    ArkUI_NumberValue value[] = {{.f32 = shrink}};
    ArkUI_AttributeItem item = {value, 1};
    NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->setAttribute(
        node->GetHandle(), NODE_FLEX_SHRINK, &item);
}

inline void SetFlexBasis(const std::shared_ptr<ArkUIBaseNode> &node, float basis)
{
    ArkUI_NumberValue value[] = {{.f32 = basis}};
    ArkUI_AttributeItem item = {value, 1};
    NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->setAttribute(node->GetHandle(), NODE_FLEX_BASIS, &item);
}
```

<!-- @[flex_grow_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKFlexSample/entry/src/main/cpp/FlexLayoutExample.h) -->

``` C
inline std::shared_ptr<ArkUITextNode> CreateGrowItem(
    const std::string &text, uint32_t bgColor, float grow, float shrink = 0.0F)
{
    auto item = CreateFlexibleItem(text, bgColor);
    SetFlexBasis(item, FLEX_BASIS);
    SetFlexGrow(item, grow);
    SetFlexShrink(item, shrink);
    return item;
}

inline std::shared_ptr<ArkUIRowNode> CreateFlexGrowExample()
{
    auto growRow = CreateRowContainer();
    growRow->AddChild(CreateGrowItem("1", COLUMN_ITEM_BLUE, DEFAULT_FLEX_GROW));
    growRow->AddChild(CreateGrowItem("2", COLUMN_ITEM_GREEN, EMPHASIZED_FLEX_GROW, EMPHASIZED_FLEX_SHRINK));
    growRow->AddChild(CreateGrowItem("1", COLUMN_ITEM_PINK, DEFAULT_FLEX_GROW));
    return growRow;
}
```

First, use **SetFlexBasis()** to set the base size of the child component on the main axis, then use **SetFlexGrow()** to specify the allocation ratio of remaining space, and finally use **SetFlexShrink()** to define the compression ratio when space is insufficient.

In the example, the **flexGrow** values of the three child components are **1**, **2**, and **1** respectively. Therefore, when there is remaining space in the container, the middle child component will occupy more width.

![grow_basis](figures/layout_container_grow_basis.jpg)

## Allocating Space Proportionally Using layoutWeight

When the main axis size of the parent container is determined, you can use [layoutWeight](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#layoutweight) to allocate remaining space by weight. This attribute takes effect in **Row**, **Column**, and **Flex**. When the **layoutWeight** value set for a child component is greater than **0**, the remaining space on the main axis will be allocated according to the weight ratio, and the child component will no longer participate in the allocation of **flexGrow** and **flexShrink**.

<!-- @[flex_layout_weight_helper](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKFlexSample/entry/src/main/cpp/FlexLayoutExample.h) -->

``` C
inline void SetLayoutWeight(const std::shared_ptr<ArkUIBaseNode> &node, uint32_t weight)
{
    ArkUI_NumberValue value[] = {{.u32 = weight}};
    ArkUI_AttributeItem item = {value, 1};
    NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->setAttribute(
        node->GetHandle(), NODE_LAYOUT_WEIGHT, &item);
}
```

<!-- @[flex_layout_weight_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKFlexSample/entry/src/main/cpp/FlexLayoutExample.h) -->

``` C
inline std::shared_ptr<ArkUITextNode> CreateWeightedItem(const std::string &text, uint32_t bgColor, uint32_t weight)
{
    auto item = CreateFlexibleItem(text, bgColor);
    SetLayoutWeight(item, weight);
    return item;
}

inline std::shared_ptr<ArkUIRowNode> CreateLayoutWeightExample()
{
    auto weightRow = CreateRowContainer();
    weightRow->AddChild(CreateWeightedItem("Weight 1", COLUMN_ITEM_BLUE, DEFAULT_LAYOUT_WEIGHT));
    weightRow->AddChild(CreateWeightedItem("Weight 2", COLUMN_ITEM_GREEN, EMPHASIZED_LAYOUT_WEIGHT));
    weightRow->AddChild(CreateWeightedItem("Weight 1", COLUMN_ITEM_PINK, DEFAULT_LAYOUT_WEIGHT));
    return weightRow;
}
```

In the example, the **layoutWeight** values of the three child components are **1**, **2**, and **1** respectively, so the middle child component will be allocated more space on the main axis.

![layout_weight](figures/layout_container_layout_weight.jpg)

## Using displayPriority to Control Display Priority

In a single-line layout scenario, you can use [displayPriority](../reference/apis-arkui/arkui-ts/ts-universal-attributes-layout-constraints.md#displaypriority) to control the display priority of child components. This attribute takes effect in **Row**, **Column**, and single-line **Flex**. When the parent container runs out of space, child components with lower priority are hidden first.

<!-- @[flex_display_priority_helper](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKFlexSample/entry/src/main/cpp/FlexLayoutExample.h) -->

``` C
inline void SetDisplayPriority(const std::shared_ptr<ArkUIBaseNode> &node, uint32_t priority)
{
    ArkUI_NumberValue value[] = {{.u32 = priority}};
    ArkUI_AttributeItem item = {value, 1};
    NativeModuleInstance::GetInstance()->GetNativeNodeAPI()->setAttribute(
        node->GetHandle(), NODE_DISPLAY_PRIORITY, &item);
}
```

<!-- @[flex_display_priority_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NDKFlexSample/entry/src/main/cpp/FlexLayoutExample.h) -->

``` C
inline std::shared_ptr<ArkUITextNode> CreatePriorityItem(
    const std::string &text, uint32_t bgColor, uint32_t priority)
{
    auto item = CreateFixedItem(text, bgColor);
    SetDisplayPriority(item, priority);
    return item;
}

inline std::shared_ptr<ArkUIRowNode> CreateDisplayPriorityExample()
{
    auto priorityRow = CreateRowContainer();
    priorityRow->SetWidth(DISPLAY_PRIORITY_ROW_WIDTH);
    priorityRow->SetJustifyContent(ARKUI_FLEX_ALIGNMENT_START);
    priorityRow->AddChild(CreatePriorityItem("High", COLUMN_ITEM_BLUE, HIGH_DISPLAY_PRIORITY));
    priorityRow->AddChild(CreatePriorityItem("Mid", COLUMN_ITEM_GREEN, MEDIUM_DISPLAY_PRIORITY));
    priorityRow->AddChild(CreatePriorityItem("Low", COLUMN_ITEM_PINK, LOW_DISPLAY_PRIORITY));
    return priorityRow;
}
```

The example first sets a narrower width for the **Row** container, and then sets three priorities: **3**, **2**, and **1**. When space is insufficient, the third child component with the lowest priority is hidden first.

![display_priority](figures/layout_container_display_priority.jpg)