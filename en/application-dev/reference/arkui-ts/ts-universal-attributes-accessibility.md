# Accessibility

You can set accessibility attributes and events for components.

>  **NOTE**
>
>  The APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## Name

| Name| Type| Description|
| -------- | -------- | -------- |
| accessibilityGroup | boolean | Accessibility group. If this attribute is set to **true**, the component and all its child components form an entire selectable component, and the accessibility service will no longer be available for the content of its child components.<br>Default value: **false**|
| accessibilityText | string   | Accessibility text. If a component does not contain text information, it will not be read when the component is selected by the screen reader. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set this attribute for components without text information. When the component is selected by the screen reader, the specified accessibility text will be read, informing the user which component is selected.<br>Default value: **""**<br>**NOTE**<br>If a component with this attribute set contains text information, only the accessibility text will be read.<br>If a component with its **accessibilityGroup** attribute set to **true** does not have **accessibilityText** set and does not contain text information, text concatenation will be performed on its child components (depth first).|
| accessibilityDescription | string | Accessibility description. You can specify further explanation of the current component, for example, possible operation consequences, especially those that cannot be learned from component attributes and accessibility text. If a component contains both text information and the accessibility description, the text is read first and then the accessibility description, when the component is selected.<br>Default value: **""**|
| accessibilityLevel | string | Accessibility importance, which is used to decide whether a component can be identified by the accessibility service.<br>The options are as follows:<br>**"auto"**: The value is converted to **"yes"** or **"no"** based on the component.<br>**"yes"**: The current component is selectable for the accessibility service.<br>**"no"**: The current component is not selectable for the accessibility service.<br>**"no-hide-descendants"**: The current component and all its child components are not selectable for the accessibility service.<br>**Default value**: **"auto"**<br>**NOTE**<br>When the **accessibilityLevel** attribute of the following components is set to **"auto"**, they are selectable for the accessibility service: Checkbox, CheckboxGroup, Gauge, Marquee, MenuItem, MenuItemGroup, Menu, Navigation, DatePicker, Progress, Radio, Rating, ScrollBar, Select, Slider, Stepper, Text, TextClock, TextPicker, TextTimer, TimePicker, Toggle, Web.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct Index {

  build() {
    Row() {
      Column() {
        Text ("Text 1")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Text ("Text 2")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
      .accessibilityGroup(true)
      .accessibilityLevel("yes")
      .accessibilityText ("Group")
      .accessibilityDescription("The <Column> component is selectable , and the text to be read out is "Group".)
    }
    .height('100%')
  }
}
```
