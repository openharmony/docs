# Building Form Components

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liyi0309-->
<!--Designer: @liyi0309-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=b8421fa94775fa4bceb1b522857b705478302935 translatedAt=2026-08-05T01:28:04.169Z pushedAt=2026-08-05T06:51:06.748Z -->

ArkUI NDK provides multiple form components, including [Button](./arkts-common-components-button.md), [Slider](../reference/apis-arkui/arkui-ts/ts-basic-components-slider.md), [Toggle](./arkts-common-components-switch.md), [Checkbox](../reference/apis-arkui/arkui-ts/ts-basic-components-checkbox.md), [CheckboxGroup](../reference/apis-arkui/arkui-ts/ts-basic-components-checkboxgroup.md), and [Radio Button (Radio)](./arkts-common-components-radio-button.md). These components are basic elements for user interaction and can be used to build diverse form UIs.

For APIs related to form components, see [native_node.h](../reference/apis-arkui/capi-native-node-h.md).

This document provides guidance for NDK development of form components. Before the query, you need to access the ArkTS pages. For details, see [Integrating with ArkTS Pages](./ndk-access-the-arkts-page.md).

## Button Component

The **Button** component is used to create a button that can be clicked. Multiple button types and styles are supported.

### Creating the Button Component

The [createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) API creates the **Button** component. The node type is **ARKUI_NODE_BUTTON**.

 <!-- @[button_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeFormExample/entry/src/main/cpp/demo/formTest.cpp) -->   

 ``` C++
 std::shared_ptr<NativeModule::ArkUIBaseNode> CreateButtonExample()
 {
     auto column = std::make_shared<NativeModule::ArkUIColumnNode>();
     column->SetWidth(1, true);
     column->SetHeight(1, true);
     column->SetBackgroundColor(0x33ff0000);
     column->SetPadding(PARAM_20, false);
     auto button = std::make_shared<NativeModule::ArkUIButtonNode>();
     button->SetButtonLabel("This is a Button");
     button->SetMaxFontScale(1.0);
     auto circleBtn = std::make_shared<NativeModule::ArkUIButtonNode>();
     circleBtn->SetButtonLabel("Circle");
     circleBtn->SetButtonType(ARKUI_BUTTON_TYPE_CIRCLE);
     circleBtn->SetMargin(PARAM_20, false);
     column->AddChild(button);
     column->AddChild(circleBtn);
     // Return Column, which is added to Content by the caller.
     return column;
 }
 ```

### Setting the Button Type

The **Button** component supports implementing different button types by setting the **NODE_BUTTON_TYPE** attribute, including normal buttons, capsule buttons, circle buttons, and rounded rectangle buttons. For the enumeration corresponding to button types, please refer to [ArkUI_ButtonType](../reference/apis-arkui/capi-button-h.md#arkui_buttontype).

The following example sets the button type to **ARKUI_BUTTON_TYPE_CIRCLE**.

<!-- @[button_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeFormExample/entry/src/main/cpp/demo/formTest.cpp) -->

``` C++
auto circleBtn = std::make_shared<NativeModule::ArkUIButtonNode>();
circleBtn->SetButtonLabel("Circle");
circleBtn->SetButtonType(ARKUI_BUTTON_TYPE_CIRCLE);
circleBtn->SetMargin(PARAM_20, false);
```

### Button Attributes

The following table describes the attributes specific to the **Button** component. For details, see the enumerated values in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

| Attribute| Description|
|------|------|
| NODE_BUTTON_LABEL| Text label of the button.|
| NODE_BUTTON_TYPE| Button type.|
| NODE_BUTTON_MIN_FONT_SCALE| Minimum font scale ratio. This attribute is supported since API version 18.|
| NODE_BUTTON_MAX_FONT_SCALE| Maximum font scale ratio. This attribute is supported since API version 18.|

## Slider Component

The **Slider** component is used to create a slider. You can drag the slider to select a value.

### Creating the Slider Component

The [createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) API creates the **Slider** component. The node type is **ARKUI_NODE_SLIDER**.

<!-- @[slider_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeFormExample/entry/src/main/cpp/demo/formTest.cpp) -->

``` C++
std::shared_ptr<NativeModule::ArkUIBaseNode> CreateSliderExample()
{
    auto column = std::make_shared<NativeModule::ArkUIColumnNode>();
    column->SetWidth(1, true);
    column->SetHeight(1, true);
    column->SetBackgroundColor(0x33ff0000);
    column->SetPadding(PARAM_20, false);
    auto sliderInSet = std::make_shared<NativeModule::ArkUISliderNode>();
    sliderInSet->SetSliderValue(PARAM_50);
    sliderInSet->SetSliderStep(PARAM_10);
    sliderInSet->SetSliderStyle(ARKUI_SLIDER_STYLE_IN_SET);
    sliderInSet->SetBlockColor(0xFF00FF00);
    sliderInSet->SetTrackColor(0xFFFFFF00);
    auto sliderOutSet = std::make_shared<NativeModule::ArkUISliderNode>();
    sliderOutSet->SetSliderValue(PARAM_50);
    sliderOutSet->SetSliderStep(PARAM_10);
    sliderOutSet->SetSliderStyle(ARKUI_SLIDER_STYLE_OUT_SET);
    sliderOutSet->SetMargin(PARAM_20, false);
    sliderOutSet->SetSliderDirection(ARKUI_SLIDER_DIRECTION_VERTICAL);
    sliderOutSet->SetIsReverse(true);
    sliderOutSet->SetIsShowSteps(true);
    column->AddChild(sliderInSet);
    column->AddChild(sliderOutSet);
    return column;
}
```

### Setting the Slider Style

Slider supports two styles, defined by [ARKUI_SliderStyle](../reference/apis-arkui/capi-slider-h.md#arkui_sliderstyle):

- **ARKUI_SLIDER_STYLE_OUT_SET**: The slider is outside the slider bar (default value).

- **ARKUI_SLIDER_STYLE_IN_SET**: The slider is inside the slider bar.

The following sample code creates the **Slider** component of the **ARKUI_SLIDER_STYLE_IN_SET** style and sets the colors of the slider and slider bar.

<!-- @[slider_inset_style](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeFormExample/entry/src/main/cpp/demo/formTest.cpp) -->

``` C++
auto sliderInSet = std::make_shared<NativeModule::ArkUISliderNode>();
sliderInSet->SetSliderValue(PARAM_50);
sliderInSet->SetSliderStep(PARAM_10);
sliderInSet->SetSliderStyle(ARKUI_SLIDER_STYLE_IN_SET);
sliderInSet->SetBlockColor(0xFF00FF00);
sliderInSet->SetTrackColor(0xFFFFFF00);
```

### Setting the Slider Direction and Step

You can set the sliding direction (horizontal or vertical), whether to reverse the slider, and whether to display the step scale.

<!-- @[slider_outset_style](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeFormExample/entry/src/main/cpp/demo/formTest.cpp) -->

``` C++
auto sliderOutSet = std::make_shared<NativeModule::ArkUISliderNode>();
sliderOutSet->SetSliderValue(PARAM_50);
sliderOutSet->SetSliderStep(PARAM_10);
sliderOutSet->SetSliderStyle(ARKUI_SLIDER_STYLE_OUT_SET);
sliderOutSet->SetMargin(PARAM_20, false);
sliderOutSet->SetSliderDirection(ARKUI_SLIDER_DIRECTION_VERTICAL);
sliderOutSet->SetIsReverse(true);
sliderOutSet->SetIsShowSteps(true);
```

### Slider Attributes

The following table describes the attributes specific to the **Slider** component. For details, see the enumerated values in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

| Attribute| Description|
|------|------|
| NODE_SLIDER_VALUE| Current progress.|
| NODE_SLIDER_MIN_VALUE| Minimum value.|
| NODE_SLIDER_MAX_VALUE| Maximum value.|
| NODE_SLIDER_STEP| Sliding step.|
| NODE_SLIDER_DIRECTION| Slider direction.|
| NODE_SLIDER_REVERSE| Whether to reverse the slider.|
| NODE_SLIDER_STYLE| Slider style.|
| NODE_SLIDER_BLOCK_COLOR| Slider color.|
| NODE_SLIDER_TRACK_COLOR| Track color.|
| NODE_SLIDER_SELECTED_COLOR| Color of the selected part.|
| NODE_SLIDER_SHOW_STEPS| Whether to display the step scale.|

## Toggle Component

The **Toggle** component is used to create a toggle to switch between the on and off states.

### Creating the Toggle Component

The [createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) API creates the **Toggle** component. The node type is **ARKUI_NODE_TOGGLE**.

<!-- @[toggle_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeFormExample/entry/src/main/cpp/demo/formTest.cpp) -->

``` C++
std::shared_ptr<NativeModule::ArkUIBaseNode> CreateToggleExample()
{
    auto column = std::make_shared<NativeModule::ArkUIColumnNode>();
    column->SetWidth(1, true);
    column->SetHeight(1, true);
    column->SetBackgroundColor(0x33ff0000);
    column->SetPadding(PARAM_20, false);
    auto toggle = std::make_shared<NativeModule::ArkUIToggleNode>();
    toggle->SetSelectedColor(0xFFFF0000);
    toggle->SetUnSelectedColor(0xFF0000FF);
    toggle->SetSwitchPointColor(0xFF00FF00);
    column->AddChild(toggle);

    return column;
}
```

### Setting the Toggle Style

You can set the background colors for a toggle in the on and off states, and the slider color.

<!-- @[toggle_colors](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeFormExample/entry/src/main/cpp/demo/formTest.cpp) -->

``` C++
toggle->SetSelectedColor(0xFFFF0000);
toggle->SetUnSelectedColor(0xFF0000FF);
toggle->SetSwitchPointColor(0xFF00FF00);
```

### Toggle Attributes

The following table describes the attributes specific to the **Toggle** component. For details, see the enumerated values in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

| Attribute| Description|
|------|------|
| NODE_TOGGLE_VALUE| Toggle status.|
| NODE_TOGGLE_SELECTED_COLOR| Background color for the toggle in on state.|
| NODE_TOGGLE_UNSELECTED_COLOR| Background color for the toggle in off state.|
| NODE_TOGGLE_SWITCH_POINT_COLOR| Slider color.|

## Checkbox Component

The **Checkbox** component is used to create a check box, which can be selected or deselected. The **CheckboxGroup** component is used to manage multiple check boxes and implement operations such as selecting all check boxes.

### Creating the Checkbox Component

The [createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) API creates the **Checkbox** component. The node type is **ARKUI_NODE_CHECKBOX**.

<!-- @[checkbox_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeFormExample/entry/src/main/cpp/demo/formTest.cpp) -->

``` C++
std::shared_ptr<NativeModule::ArkUIBaseNode> CreateCheckboxExample()
{
    auto column = std::make_shared<NativeModule::ArkUIColumnNode>();
    column->SetWidth(1, true);
    column->SetHeight(1, true);
    column->SetBackgroundColor(0x33ff0000);
    column->SetPadding(PARAM_20, false);
    auto checkbox1 = std::make_shared<NativeModule::ArkUICheckboxNode>();
    auto checkbox2 = std::make_shared<NativeModule::ArkUICheckboxNode>();
    auto checkbox3 = std::make_shared<NativeModule::ArkUICheckboxNode>();
    auto checkboxGroup = std::make_shared<NativeModule::ArkUICheckboxGroupNode>();
    checkboxGroup->SetCheckboxGroupName("check_group");
    checkbox1->SetCheckboxGroup("check_group");
    checkbox1->SetSelectColor(0xFFFF0000);
    checkbox2->SetCheckboxGroup("check_group");
    checkbox2->SetUnSelectColor(0xFFFF0000);
    checkbox3->SetCheckboxGroup("check_group");
    checkbox3->SetCheckboxShape(ArkUI_CHECKBOX_SHAPE_ROUNDED_SQUARE);
    checkbox1->SetCheckboxName("check_group1");
    checkbox2->SetCheckboxName("check_group2");
    checkbox3->SetCheckboxName("check_group3");

    column->AddChild(checkboxGroup);
    column->AddChild(checkbox1);
    column->AddChild(checkbox2);
    column->AddChild(checkbox3);

    // Return Column, to be added to Content by the caller.
    return column;
}
```

### Creating the CheckboxGroup Component

The **CheckboxGroup** component is used to manage multiple check boxes in the same group. The node type is **ARKUI_NODE_CHECKBOX_GROUP**.

<!-- @[checkbox_group](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeFormExample/entry/src/main/cpp/demo/formTest.cpp) -->

``` C++
auto checkboxGroup = std::make_shared<NativeModule::ArkUICheckboxGroupNode>();
checkboxGroup->SetCheckboxGroupName("check_group");
```

### Setting Checkbox Attributes

You can set the colors of the check box in the selected and unselected states, as well as its shape and group name.

<!-- @[checkbox_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeFormExample/entry/src/main/cpp/demo/formTest.cpp) -->

``` C++
checkbox1->SetCheckboxGroup("check_group");
checkbox1->SetSelectColor(0xFFFF0000);
checkbox2->SetCheckboxGroup("check_group");
checkbox2->SetUnSelectColor(0xFFFF0000);
checkbox3->SetCheckboxGroup("check_group");
checkbox3->SetCheckboxShape(ArkUI_CHECKBOX_SHAPE_ROUNDED_SQUARE);
checkbox1->SetCheckboxName("check_group1");
checkbox2->SetCheckboxName("check_group2");
checkbox3->SetCheckboxName("check_group3");
```

### Checkbox Attributes

The following table describes the attributes specific to the **Checkbox** component. For details, see the enumerated values in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

| Attribute| Description|
|------|------|
| NODE_CHECKBOX_SELECT| Whether to select the check box.|
| NODE_CHECKBOX_SELECT_COLOR| Color in the selected state.|
| NODE_CHECKBOX_UNSELECT_COLOR| Color in the unselected state.|
| NODE_CHECKBOX_MARK| Style of the check mark.|
| NODE_CHECKBOX_SHAPE| Shape of the check box.|
| NODE_CHECKBOX_NAME| Name of the check box. This attribute is supported since API version 15.|
| NODE_CHECKBOX_GROUP| Name of the check box group for **CheckboxGroup** management. This attribute is supported since API version 15.|

### CheckboxGroup Attributes

The following table describes the attributes specific to the **CheckboxGroup** component. For details, see the enumerated values in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

| Attribute| Description|
|------|------|
| NODE_CHECKBOX_GROUP_NAME| Name of the check box group. This attribute is supported since API version 15.|
| NODE_CHECKBOX_GROUP_SELECT_ALL| Whether to select all. This attribute is supported since API version 15.|
| NODE_CHECKBOX_GROUP_SELECTED_COLOR| Color in the selected state. This attribute is supported since API version 15.|
| NODE_CHECKBOX_GROUP_UNSELECTED_COLOR| Color in the unselected state. This attribute is supported since API version 15.|
| NODE_CHECKBOX_GROUP_MARK| Style of the check mark. This attribute is supported since API version 15.|
| NODE_CHECKBOX_GROUP_SHAPE| Shape of the check box. This attribute is supported since API version 15.|

## Radio Component

The **Radio** component is used to create a radio button. Only one radio button can be selected from a group.

### Creating the Radio Component

The [createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) API creates the **Radio** component. The node type is **ARKUI_NODE_RADIO**.

<!-- @[radio_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeFormExample/entry/src/main/cpp/demo/formTest.cpp) -->

``` C++
std::shared_ptr<NativeModule::ArkUIBaseNode> CreateRadioExample()
{
    auto column = std::make_shared<NativeModule::ArkUIColumnNode>();
    column->SetWidth(1, true);
    column->SetHeight(1, true);
    column->SetBackgroundColor(0x33ff0000);
    column->SetPadding(PARAM_20, false);
    auto radio1 = std::make_shared<NativeModule::ArkUIRadioNode>();
    auto radio2 = std::make_shared<NativeModule::ArkUIRadioNode>();
    auto radio3 = std::make_shared<NativeModule::ArkUIRadioNode>();
    radio1->SetIsOn(true);
    radio1->SetRadioGroup("radio_group");
    radio2->SetRadioGroup("radio_group");
    radio3->SetRadioGroup("radio_group");
    radio3->SetRadioStyle(0xFFFF0000, 0xFF00FF00, 0xFF00FFFF);

    column->AddChild(radio1);
    column->AddChild(radio2);
    column->AddChild(radio3);

    return column;
}
```

### Setting a Radio Group

Only one radio button can be selected from a group. You can implement mutual exclusion by setting the same group name.

<!-- @[radio_group](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeFormExample/entry/src/main/cpp/demo/formTest.cpp) -->

``` C++
radio1->SetIsOn(true);
radio1->SetRadioGroup("radio_group");
radio2->SetRadioGroup("radio_group");
radio3->SetRadioGroup("radio_group");
```

### Setting the Radio Style

You can set the style of a radio button, including the color of the button in the unselected state and the colors of the inner ring and outer ring in the selected state.

<!-- @[radio_style](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NativeFormExample/entry/src/main/cpp/demo/formTest.cpp) -->

``` C++
radio3->SetRadioStyle(0xFFFF0000, 0xFF00FF00, 0xFF00FFFF);
```

### Radio Attributes

The following table describes the attributes specific to the **Radio** component. For details, see the enumerated values in [ArkUI_NodeAttributeType](../reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype).

| Attribute| Description|
|------|------|
| NODE_RADIO_CHECKED| Whether to select the radio button.|
| NODE_RADIO_STYLE| Style of the radio button in the selected and unselected states (including the background color in the selected state, stroke color in the unselected state, and color of the indicator in the selected state).|
| NODE_RADIO_VALUE| Value of a radio button.|
| NODE_RADIO_GROUP| Name of a radio button group. Radio buttons in the same group are mutually exclusive.|

<!--no_check-->