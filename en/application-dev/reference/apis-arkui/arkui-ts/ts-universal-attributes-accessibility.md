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

## accessibilityText

accessibilityText(value: string)

Sets the accessibility text.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | string | Yes  | Accessibility text. If a component does not contain text information, it will not be read when the component is selected by the screen reader. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set this attribute for components without text information. When the component is selected by the screen reader, the specified accessibility text will be read, informing the user which component is selected.<br>Default value: **""**<br>**NOTE**<br>If a component with this attribute set contains text information, only the accessibility text will be read.<br>If a component with its **accessibilityGroup** attribute set to **true** does not have **accessibilityText** set and does not contain text information, text concatenation will be performed on its child components (depth first).|

## accessibilityText<sup>12+</sup>

accessibilityText(text: Resource)

Sets the accessibility text, which supports referencing resource files through **Resource**.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                                                                                                                                                                                                                                  |
| ------ | ------ | ---- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| text  | [Resource](ts-types.md#resource) | Yes  | Reference resource of accessibility text. If a component does not contain text information, it will not be read when the component is selected by the screen reader. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set this attribute for components without text information. When the component is selected by the screen reader, the specified accessibility text will be read, informing the user which component is selected.<br>**NOTE**<br>If a component with this attribute set contains text information, only the accessibility text will be read.<br>If a component with its **accessibilityGroup** attribute set to **true** does not have **accessibilityText** set and does not contain text information, text concatenation will be performed on its child components (depth first).|


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

## Example

```ts
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
      .accessibilityText("Group")
      .accessibilityDescription("The Column component is selectable , and the text to be read out is "Group".)
      .accessibilityVirtualNode(this.customAccessibilityNode)
    }
    .height('100%')
  }
}
```
