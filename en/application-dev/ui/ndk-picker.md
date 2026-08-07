# Using the Sliding Selector (Picker)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @luoying_ace_admin-->
<!--Designer: @weixin_52725220-->
<!--Tester: @xiong0104-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=83e5cb8e07a56e004440db21134aff2f734ecd8f translatedAt=2026-08-05T10:07:36.337Z pushedAt=2026-08-06T06:19:01.532Z -->

## Overview

Starting from API version 23, the ArkUI development framework provides the **Picker** container component in the NDK APIs. The **Picker** container component is used to implement user-defined option selection, supporting features such as scrolling selection, haptic feedback, and circular scrolling. By setting the selection indicator style, the **Picker** component can customize the display effect of selected items, making it suitable for scenarios such as date, time, and text selection. Starting from API version 26.0.0, the number of visible option rows and the height of each row can be configured through **NODE_PICKER_DISPLAYED_ITEM_COUNT** and **NODE_PICKER_ITEM_HEIGHT**. The semantics are consistent with [displayedItemCount](../reference/apis-arkui/arkui-ts/ts-container-ui-picker-component.md#displayeditemcount) and [itemHeight](../reference/apis-arkui/arkui-ts/ts-container-ui-picker-component.md#itemheight) on the ArkTS side [UIPickerComponent](../reference/apis-arkui/arkui-ts/ts-container-ui-picker-component.md). For detailed parameter formats, see [Information Selection Component Attribute](../reference/apis-arkui/capi-native-node-h-nodeattributetype-informationselection.md).

After [creating a picker](#creating-a-picker), you can [set picker attributes](#setting-picker-attributes) and [listen for picker events](#listening-for-picker-events).

For building UI interfaces using the NDK APIs and basic NDK usage, refer to [Integrating with ArkTS Pages](ndk-access-the-arkts-page.md).

## Creating a Picker

Create a **Picker** container component by calling [createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode)() to obtain a component object pointer with the node type `ARKUI_NODE_PICKER`, and then setting the relevant attributes in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

### Basic Creation Method

The following example demonstrates how to create a **Picker** component and set its basic attributes.

<!-- @[create_picker](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerIndexMaker.cpp) -->

``` C++
static ArkUI_NodeHandle CreatePicker(ArkUI_NativeNodeAPI_1 *api)
{
    ArkUI_NodeHandle picker = api->createNode(ARKUI_NODE_PICKER);
    if (picker == nullptr) {
        return nullptr;
    }
    if (g_state) {
        g_state->pickerNode = picker;
    }
    ArkUI_NumberValue widthValue = {.f32 = K_PICKER_WIDTH_RATIO};
    ArkUI_AttributeItem widthItem = {&widthValue, sizeof(widthValue) / sizeof(ArkUI_NumberValue)};
    api->setAttribute(picker, NODE_WIDTH_PERCENT, &widthItem);
    UpdatePickerSelectedIndex();
    SetDisplayedItemCount(K_VISIBLE_COUNT);
    SetItemHeight(K_ITEM_HEIGHT);
    api->registerNodeEvent(picker, NODE_PICKER_EVENT_ON_CHANGE, K_ON_CHANGE_EVENT_ID, nullptr);
    api->registerNodeEvent(picker, NODE_PICKER_EVENT_ON_SCROLL_STOP, K_ON_SCROLL_STOP_EVENT_ID, nullptr);
    if (g_state) {
        for (const auto &item : g_state->dataArray) {
            ArkUI_NodeHandle optionNode = CreatePickerOption(api, item);
            if (optionNode != nullptr) {
                api->addChild(picker, optionNode);
            }
        }
    }
    return picker;
}
```

### Encapsulation into a Utility Class

Refer to the implementation of the list component in the [example](ndk-access-the-arkts-page.md#example). You can encapsulate commonly used property settings of the **Picker** component into a custom utility class for subsequent use.

<!-- @[container_picker_can_loop_maker_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerCanLoopMaker.h) -->

``` C
class ContainerPickerCanLoopMaker : public BaseNode {
public:
    static ArkUI_NodeHandle CreateNativeNode();

    ContainerPickerCanLoopMaker()
        : BaseNode(NodeApiInstance::GetInstance()->GetNativeNodeAPI()->createNode(ARKUI_NODE_PICKER)),
          nodeApi_(NodeApiInstance::GetInstance()->GetNativeNodeAPI())
    {
        if (!IsNotNull(nodeApi_) || !IsNotNull(GetHandle())) {
            return;
        }
    }

    ~ContainerPickerCanLoopMaker() override = default;

    // ========================================
    // Basic size setting API.
    // ========================================
    void SetPickerSize(float width, float height) { SetSize(width, height); }

    void SetPickerSizePercent(float widthPercent, float heightPercent) { SetSizePercent(widthPercent, heightPercent); }

    void SetPickerWidthPercent(float widthPercent)
    {
        SetAttributeFloat32(nodeApi_, GetHandle(), NODE_WIDTH_PERCENT, widthPercent);
    }

    void SetPickerHeightPercent(float heightPercent)
    {
        SetAttributeFloat32(nodeApi_, GetHandle(), NODE_HEIGHT_PERCENT, heightPercent);
    }

    // ========================================
    // Picker-specific attribute setting API.
    // ========================================
    void SetSelectedIndex(uint32_t index)
    {
        if (!IsNotNull(nodeApi_) || !IsNotNull(GetHandle())) {
            return;
        }
        ArkUI_NumberValue selectedIndexValue = {.u32 = index};
        ArkUI_AttributeItem selectedIndexItem = {&selectedIndexValue,
                                                 sizeof(selectedIndexValue) / sizeof(ArkUI_NumberValue)};
        nodeApi_->setAttribute(GetHandle(), NODE_PICKER_OPTION_SELECTED_INDEX, &selectedIndexItem);
    }

    void SetCanLoop(bool canLoop)
    {
        if (!IsNotNull(nodeApi_) || !IsNotNull(GetHandle())) {
            return;
        }
        ArkUI_NumberValue canLoopValue = {.i32 = canLoop ? 1 : 0};
        ArkUI_AttributeItem canLoopItem = {&canLoopValue, sizeof(canLoopValue) / sizeof(ArkUI_NumberValue)};
        nodeApi_->setAttribute(GetHandle(), NODE_PICKER_CAN_LOOP, &canLoopItem);
    }

    void SetHapticFeedback(bool enabled)
    {
        if (!IsNotNull(nodeApi_) || !IsNotNull(GetHandle())) {
            return;
        }
        ArkUI_NumberValue enableHapticFeedbackValue = {.i32 = enabled ? 1 : 0};
        ArkUI_AttributeItem enableHapticFeedbackItem = {&enableHapticFeedbackValue,
                                                        sizeof(enableHapticFeedbackValue) / sizeof(ArkUI_NumberValue)};
        nodeApi_->setAttribute(GetHandle(), NODE_PICKER_ENABLE_HAPTIC_FEEDBACK, &enableHapticFeedbackItem);
    }

    void SetSelectionIndicatorBackground(uint32_t backgroundColor, float cornerRadius = 10.0f)
    {
        if (!IsNotNull(nodeApi_) || !IsNotNull(GetHandle())) {
            return;
        }
        ArkUI_PickerIndicatorStyle *indicatorStyle =
            OH_ArkUI_PickerIndicatorStyle_Create(ARKUI_PICKER_INDICATOR_BACKGROUND);
        if (indicatorStyle == nullptr) {
            return;
        }
        ArkUI_PickerIndicatorBackground background = {.backgroundColor = backgroundColor,
                                                      .topLeftRadius = cornerRadius,
                                                      .topRightRadius = cornerRadius,
                                                      .bottomLeftRadius = cornerRadius,
                                                      .bottomRightRadius = cornerRadius};
        OH_ArkUI_PickerIndicatorStyle_ConfigureBackground(indicatorStyle, &background);
        ArkUI_AttributeItem selectionIndicatorItem = {.object = indicatorStyle};
        nodeApi_->setAttribute(GetHandle(), NODE_PICKER_SELECTION_INDICATOR, &selectionIndicatorItem);
    }

    void SetSelectionIndicatorDivider(uint32_t dividerColor, float strokeWidth = 2.0f, float startMargin = 20.0f,
                                      float endMargin = 20.0f)
    {
        if (!IsNotNull(nodeApi_) || !IsNotNull(GetHandle())) {
            return;
        }
        ArkUI_PickerIndicatorStyle *indicatorStyle =
            OH_ArkUI_PickerIndicatorStyle_Create(ARKUI_PICKER_INDICATOR_DIVIDER);
        if (indicatorStyle == nullptr) {
            return;
        }
        ArkUI_PickerIndicatorDivider divider = {.strokeWidth = strokeWidth,
                                                .dividerColor = dividerColor,
                                                .startMargin = startMargin,
                                                .endMargin = endMargin};
        OH_ArkUI_PickerIndicatorStyle_ConfigureDivider(indicatorStyle, &divider);
        ArkUI_AttributeItem selectionIndicatorItem = {.object = indicatorStyle};
        nodeApi_->setAttribute(GetHandle(), NODE_PICKER_SELECTION_INDICATOR, &selectionIndicatorItem);
    }

    // ========================================
    // Public helper methods.
    // ========================================
    ArkUI_NativeNodeAPI_1 *GetNodeAPI() const { return nodeApi_; }

protected:
    void OnNodeEvent(ArkUI_NodeEvent *event) override { BaseNode::OnNodeEvent(event); }

private:
    ArkUI_NativeNodeAPI_1 *nodeApi_ = nullptr;
};
```

## Setting Picker Attributes

### Setting the Default Selected Item

By setting the `NODE_PICKER_OPTION_SELECTED_INDEX` attribute in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype), you can set the default selected item index for the **Picker** component.

<!-- @[selected_index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerEventsMaker.h) -->

``` C
ArkUI_NumberValue selectedIndexValue = {.u32 = index};
ArkUI_AttributeItem selectedIndexItem = {&selectedIndexValue,
                                         sizeof(selectedIndexValue) / sizeof(ArkUI_NumberValue)};
nodeApi_->setAttribute(GetHandle(), NODE_PICKER_OPTION_SELECTED_INDEX, &selectedIndexItem);
```

### Setting Haptic Feedback

By setting the `NODE_PICKER_ENABLE_HAPTIC_FEEDBACK` attribute, you can control whether the **Picker** component enables haptic feedback. When enabled, if the system hardware supports it, tactile feedback is generated when the user scrolls the selector.

When using [ArkUI_NativeNodeAPI_1](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md), you can directly call `setAttribute`.

<!-- @[enable_haptic_feedback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerEventsMaker.h) -->

``` C
ArkUI_NumberValue enableHapticFeedbackValue = {.i32 = enabled ? 1 : 0};
ArkUI_AttributeItem enableHapticFeedbackItem = {&enableHapticFeedbackValue,
                                                sizeof(enableHapticFeedbackValue) / sizeof(ArkUI_NumberValue)};
nodeApi_->setAttribute(GetHandle(), NODE_PICKER_ENABLE_HAPTIC_FEEDBACK, &enableHapticFeedbackItem);
```

If using the `ContainerPickerCanLoopMaker` encapsulated above, you can call the encapsulated API.

<!-- @[set_haptic_feedback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerIndicatorMaker.cpp) -->

``` C++
picker->SetHapticFeedback(K_HAPTIC_FEEDBACK);
```

### Setting Circular Scrolling

By setting the `NODE_PICKER_CAN_LOOP` attribute, you can control whether the **Picker** component supports circular scrolling. When set to **true**, the selector can scroll infinitely in a loop; when set to **false**, scrolling stops when reaching the beginning or end.

> **NOTE**
>
> If the number of child components is less than or equal to the number of visible option rows (set by `NODE_PICKER_DISPLAYED_ITEM_COUNT`, which defaults to **7**), circular scrolling will not occur regardless of whether it is set to **true** or **false**.

When using [ArkUI_NativeNodeAPI_1](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md), you can directly call `setAttribute`.

<!-- @[can_loop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerEventsMaker.h) -->

``` C
ArkUI_NumberValue canLoopValue = {.i32 = canLoop ? 1 : 0};
ArkUI_AttributeItem canLoopItem = {&canLoopValue, sizeof(canLoopValue) / sizeof(ArkUI_NumberValue)};
nodeApi_->setAttribute(GetHandle(), NODE_PICKER_CAN_LOOP, &canLoopItem);
```

If using the `ContainerPickerCanLoopMaker` encapsulated above, you can call the encapsulated API.

<!-- @[set_can_loop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerIndicatorMaker.cpp) -->

``` C++
picker->SetCanLoop(K_CAN_LOOP);
```

### Setting the Number of Visible Options and Option Row Height

Starting from API version 26.0.0, you can set the number of visible option rows via [NODE_PICKER_DISPLAYED_ITEM_COUNT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-informationselection.md#node_picker_displayed_item_count) and set the height of each row (vp) via [NODE_PICKER_ITEM_HEIGHT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-informationselection.md#node_picker_item_height). When not set, the defaults are 7 rows and 40 vp respectively; the value range, even-numbered row specification, and out-of-bounds behavior are consistent with [displayedItemCount](../reference/apis-arkui/arkui-ts/ts-container-ui-picker-component.md#displayeditemcount) and [itemHeight](../reference/apis-arkui/arkui-ts/ts-container-ui-picker-component.md#itemheight) of [UIPickerComponent](../reference/apis-arkui/arkui-ts/ts-container-ui-picker-component.md). In the 3D wheel style, the visible height is affected by rotation. If you increase the number of rows or row height, increase the **Picker** container height accordingly.

When using [ArkUI_NativeNodeAPI_1](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md), you can directly call `setAttribute`.

<!-- @[display_item_count](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerIndexMaker.cpp) -->

``` C++
ArkUI_NumberValue itemCountValue = {.i32 = count};
ArkUI_AttributeItem itemCountItem = {&itemCountValue, sizeof(itemCountValue) / sizeof(ArkUI_NumberValue)};
g_state->api->setAttribute(g_state->pickerNode, NODE_PICKER_DISPLAYED_ITEM_COUNT, &itemCountItem);
```

<!-- @[item_height](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerIndexMaker.cpp) -->

``` C++
ArkUI_NumberValue itemHeightValue = {.f32 = heightVp};
ArkUI_AttributeItem itemHeightItem = {&itemHeightValue, sizeof(itemHeightValue) / sizeof(ArkUI_NumberValue)};
g_state->api->setAttribute(g_state->pickerNode, NODE_PICKER_ITEM_HEIGHT, &itemHeightItem);
```

### Setting the Selection Indicator Style

By setting the `NODE_PICKER_SELECTION_INDICATOR` attribute, you can customize the selection indicator style of the **Picker** component. The selection indicator consists of two parts: background style and divider line style.

The background style of the selection indicator is set through the [ArkUI_PickerIndicatorBackground](../reference/apis-arkui/capi-arkui-nativemodule-arkui-pickerindicatorbackground.md) structure, including the background color and corner radius.

<!-- @[set_indicator_background](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerIndicatorMaker.h) -->

``` C
void SetSelectionIndicatorBackground(uint32_t backgroundColor, float cornerRadius = 10.0f)
{
    if (!IsNotNull(nodeApi_) || !IsNotNull(GetHandle())) {
        return;
    }
    ArkUI_PickerIndicatorStyle *indicatorStyle =
        OH_ArkUI_PickerIndicatorStyle_Create(ARKUI_PICKER_INDICATOR_BACKGROUND);
    if (indicatorStyle == nullptr) {
        return;
    }
    ArkUI_PickerIndicatorBackground background = {.backgroundColor = backgroundColor,
                                                  .topLeftRadius = cornerRadius,
                                                  .topRightRadius = cornerRadius,
                                                  .bottomLeftRadius = cornerRadius,
                                                  .bottomRightRadius = cornerRadius};
    OH_ArkUI_PickerIndicatorStyle_ConfigureBackground(indicatorStyle, &background);
    ArkUI_AttributeItem selectionIndicatorItem = {.object = indicatorStyle};
    nodeApi_->setAttribute(GetHandle(), NODE_PICKER_SELECTION_INDICATOR, &selectionIndicatorItem);
}
```

The divider style of the selection indicator is set through the [ArkUI_PickerIndicatorDivider](../reference/apis-arkui/capi-arkui-nativemodule-arkui-pickerindicatordivider.md) structure, including the line width, color, and margin.

<!-- @[set_indicator_divider](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerIndicatorMaker.h) -->

``` C
void SetSelectionIndicatorDivider(uint32_t dividerColor, float strokeWidth = 2.0f, float startMargin = 20.0f,
                                  float endMargin = 20.0f)
{
    if (!IsNotNull(nodeApi_) || !IsNotNull(GetHandle())) {
        return;
    }
    ArkUI_PickerIndicatorStyle *indicatorStyle =
        OH_ArkUI_PickerIndicatorStyle_Create(ARKUI_PICKER_INDICATOR_DIVIDER);
    if (indicatorStyle == nullptr) {
        return;
    }
    ArkUI_PickerIndicatorDivider divider = {.strokeWidth = strokeWidth,
                                            .dividerColor = dividerColor,
                                            .startMargin = startMargin,
                                            .endMargin = endMargin};
    OH_ArkUI_PickerIndicatorStyle_ConfigureDivider(indicatorStyle, &divider);
    ArkUI_AttributeItem selectionIndicatorItem = {.object = indicatorStyle};
    nodeApi_->setAttribute(GetHandle(), NODE_PICKER_SELECTION_INDICATOR, &selectionIndicatorItem);
}
```

Combine the background style or divider style into the [ArkUI_PickerIndicatorStyle](../reference/apis-arkui/capi-arkui-nativemodule-arkui-pickerindicatorstyle.md) struct and set it to the **Picker** component.

If using the `ContainerPickerCanLoopMaker` encapsulated above, you can call the encapsulated API.

<!-- @[set_selection_indicator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerMonthMaker.cpp) -->

``` C++
picker->SetSelectionIndicatorDivider(0xFF0000FF, 2.0f, 20.0f, 20.0f);
```

## Listening for Picker Events

This example registers the event types of the **Picker** component through [registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent) with [ArkUI_NodeEventType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeeventtype), and uses the `ArkUI_NodeEventItem` structure to specify an independent callback function for each event. You do not need to register an additional global callback function; each event item is directly bound to a callback function. The events supported by the **Picker** component are as follows:

| Enumeration | Description | Since |
|------|------|---------|
| NODE_PICKER_EVENT_ON_CHANGE | Event triggered when an item is selected in the Picker component. | 23 |
| NODE_PICKER_EVENT_ON_SCROLL_STOP | Event triggered when an item is selected in the Picker component and scrolling stops. | 23 |

### Listening for Selection Change Events

Register the `NODE_PICKER_EVENT_ON_CHANGE` event through [registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent), and use the `ArkUI_NodeEventItem` structure to specify a callback function to listen for selection changes in the **Picker** component. The index value of the selected item is returned in the event callback.

<!-- @[on_picker_change](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerEventsMaker.cpp) -->

``` C++
api->registerNodeEvent(picker, NODE_PICKER_EVENT_ON_CHANGE, K_ON_CHANGE_EVENT_ID, nullptr);
```

### Listening for Scroll Stop Events

Register the `NODE_PICKER_EVENT_ON_SCROLL_STOP` event through [registerNodeEvent](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#registernodeevent), and use the `ArkUI_NodeEventItem` structure to specify a callback function to listen for selection changes when the **Picker** component stops scrolling. Compared with the `NODE_PICKER_EVENT_ON_CHANGE` event, this event is triggered only when scrolling stops, making it suitable for scenarios where the selection needs to be processed after scrolling is complete.

<!-- @[on_scroll_stop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeType/native_type_sample/entry/src/main/cpp/ContainerPickerEventsMaker.cpp) -->

``` C++
api->registerNodeEvent(picker, NODE_PICKER_EVENT_ON_SCROLL_STOP, K_ON_SCROLL_STOP_EVENT_ID, nullptr);
```

## Complete Example

<!--RP1-->

[Native_Type_Sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

<!--no_check-->
