# Accessibility

You can set accessibility attributes and events for components.

>  **NOTE**
>
>  The APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## accessibilityGroup

accessibilityGroup(value: boolean)

Sets the accessibility group.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Accessibility group. If this attribute is set to **true**, the component and all its child components form an entire selectable component, and the accessibility service will no longer be available for the content of its child components.<br>Default value: **false**|

## accessibilityGroup<sup>14+</sup>

accessibilityGroup(isGroup: boolean, accessibilityOptions: AccessibilityOptions)

Groups components for accessibility purposes, allowing the accessibility service to read out concatenated text.

**Widget capability**: This API can be used in ArkTS widgets since API version 14.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name              | Type                                                   | Mandatory| Description                                                        |
| -------------------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| isGroup              | boolean                                                 | Yes  | Whether to group the current component and its children. If this parameter is set to **true**, the component and all its children are treated as a single selectable unit. The accessibility service will not focus on individual child components.<br>Default value: **false**|
| accessibilityOptions | [AccessibilityOptions](#accessibilityoptions14) | No  | Options to customize accessibility behavior, such as prioritizing concatenated text for reading.            |

## AccessibilityOptions<sup>14+</sup>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                  | Type   | Mandatory| Description                                                        |
| ---------------------- | ------- | ---- | ------------------------------------------------------------ |
| accessibilityPreferred | boolean | No  | Whether to prioritize the accessibility text of child components during a deep traversal. The value **true** means to prioritize the accessibility text of child components.<br>If a child component's accessibility text is empty, the accessibility service uses the component's own text content. The concatenated text is then assigned to the parent node if both its accessibility text and text content are empty.|

## accessibilityText

accessibilityText(value: string)

Sets the accessibility text.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | string | Yes  | Accessibility text. If a component does not contain text information, it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set accessibility text for components without text information. When such a component is selected, the screen reader announces the specified accessibility text, informing the user which component is selected.<br>Default value: **""**<br>**NOTE**<br>If a component has both text content and accessibility text, only the accessibility text is announced.<br>If a component is grouped for accessibility purposes but lacks both text content and accessibility text, the screen reader will concatenate text from its child components (depth-first traversal).<br>To prioritize accessibility text concatenation, set **accessibilityPreferred** in **accessibilityGroup**.|

## accessibilityText<sup>12+</sup>

accessibilityText(text: Resource)

Sets the accessibility text, which supports referencing resource files through **Resource**.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                                                                                                                                                                                                                                  |
| ------ | ------ | ---- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| text  | [Resource](ts-types.md#resource) | Yes  | Reference resource of accessibility text. If a component does not contain text information, it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set accessibility text for components without text information. When such a component is selected, the screen reader announces the specified accessibility text, informing the user which component is selected.<br>**NOTE**<br>If a component has both text content and accessibility text, only the accessibility text is announced.<br>If a component is grouped for accessibility purposes but lacks both text content and accessibility text, the screen reader will concatenate text from its child components (depth-first traversal).<br>To prioritize accessibility text concatenation, set **accessibilityPreferred** in **accessibilityGroup**.|


## accessibilityDescription

accessibilityDescription(value: string)

Sets the accessibility description.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | string | Yes  | Accessibility description. You can specify further explanation of the current component, for example, possible operation consequences, especially those that cannot be learned from component attributes and accessibility text. If a component contains both text information and the accessibility description, the text is read first and then the accessibility description, when the component is selected.<br>Default value: **""**|

## accessibilityDescription<sup>12+</sup>

accessibilityDescription(description: Resource)

Sets the accessibility description, which supports referencing resource files through **Resource**.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                                                                                                                                                   |
| ------ | ------ | ---- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| description  | [Resource](ts-types.md#resource) | Yes  | Reference resource of the accessibility description. You can specify further explanation of the current component, for example, possible operation consequences, especially those that cannot be learned from component attributes and accessibility text. If a component contains both text information and the accessibility description, the text is read first and then the accessibility description, when the component is selected.|

## accessibilityLevel

accessibilityLevel(value: string)

Sets the accessibility level.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | string | Yes  | Accessibility level, which is used to decide whether a component can be identified by the accessibility service.<br>The options are as follows:<br>**"auto"**: The value is converted to **"yes"** or **"no"** based on the component.<br>**"yes"**: The current component is selectable for the accessibility service.<br>**"no"**: The current component is not selectable for the accessibility service.<br>**"no-hide-descendants"**: The current component and all its child components are not selectable for the accessibility service.<br>**Default value**: **"auto"**<br>**NOTE**<br>When the **accessibilityLevel** attribute of the following components is set to **"auto"**, they are selectable for the accessibility service: Checkbox, CheckboxGroup, Gauge, Marquee, MenuItem, MenuItemGroup, Menu, Navigation, DatePicker, Progress, Radio, Rating, ScrollBar, Select, Slider, Stepper, Text, TextClock, TextPicker, TextTimer, TimePicker, Toggle, Web.|

## accessibilityVirtualNode<sup>11+</sup>

accessibilityVirtualNode(builder: CustomBuilder)

Sets the accessibility virtual node.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| builder  | [CustomBuilder](ts-types.md#custombuilder8) | Yes  | Accessibility virtual node, which enables you to pass in a custom builder to the self-drawing component. The components in the custom builder are only laid out but not displayed at the backend. When the accessibility application obtains the accessibility node information, the node information in the custom builder is returned.|

## accessibilityChecked<sup>13+</sup>

accessibilityChecked(isCheck: boolean)

Sets the checked (selected) state of the accessibility node. It can be used to support multi-select scenarios.

**Widget capability**: This API can be used in ArkTS widgets since API version 13.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| isCheck | boolean | Yes  | Whether the current component is selected.<br>The options are as follows:<br>**true**: The component is selected.<br>**false**: The component is not selected.<br>**undefined**: The component determines its own selected state.<br>Default value: **undefined**<br>**NOTE**<br>1. Setting this parameter to **true** or **false** will automatically set the component's **checkable** attribute to **true**.<br>2. When this parameter is set to **true** or **false**, to use it with **accessibilitySelected**, set the **accessibilitySelected** parameter to **undefined**.|

## accessibilitySelected<sup>13+</sup>

accessibilitySelected(isSelect: boolean)

Sets the selected state of the accessibility node. It can be used to support single-select scenarios.

**Widget capability**: This API can be used in ArkTS widgets since API version 13.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| isSelect | boolean | Yes  | Whether the current component is selected.<br>The options are as follows:<br>**true**: The component is selected.<br>**false**: The component is not selected.<br>**undefined**: The component determines its own selected state.<br>Default value: **undefined**<br>**NOTE**<br>1. When this parameter is set to **true** or **false**, to use it with **accessibilityChecked**, set the **accessibilityChecked** parameter to **undefined**.|


## Example 1: Setting Accessibility Text and Description

This example demonstrates how to use **accessibilityText** and **accessibilityDescription** to customize the content announced by screen readers.

```
// xxx.ets
@Entry
@Component
struct Index {

  @Builder customAccessibilityNode() {
    Column() {
      Text(`virtual node`)
    }
    .width(10)
    .height(10)
  }

  build() {
    Row() {
      Column() {
        Text("Text 1")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Text("Text 2")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
      .accessibilityGroup(true)
      .accessibilityLevel("yes")
      .accessibilityText("Group") // If a component has both text content and accessibility text, only the accessibility text is announced.
      .accessibilityDescription("The <Column> component is selectable , and the text to be read out is "Group".)
      .accessibilityVirtualNode(this.customAccessibilityNode)
      .accessibilityChecked(true)
      .accessibilitySelected(undefined)
    }
    .height('100%')
  }
}
```

## Example 2: Setting the Accessibility Group

This example shows how to use **accessibilityGroup** to prioritize reading the accessibility text of child components.

```
// xxx.ets
@Entry
@Component
struct Focus {
  build() {
    Column({ space: 10 }) {
      Text('123456')
        .focusable(true)
        .borderRadius(5)
        .accessibilityText("Accessibility text is announced if both accessibility text and text content are present")
        .accessibilityLevel("yes")
      Button().accessibilityLevel("yes").accessibilityText("Accessibility text is announced if no text is present")
      Button("Text content is announced if no accessibility text is present").accessibilityLevel("yes")
      Button()
      Button('btnl23').accessibilityText("Button with both accessibility text and text").accessibilityLevel("yes")
      Button('btn123').accessibilityLevel("yes")
    }
    .accessibilityGroup(true, { accessibilityPreferred: true })
    //.accessibilityGroup(true)
    .borderWidth(5)
    .width('100%')
    .height('100%')
  }
}
```

