# Accessibility

You can set accessibility attributes and events for components.

>  **NOTE**
>
>  The APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## accessibilityGroup

accessibilityGroup(value: boolean)

Sets whether to enable accessibility grouping. When accessibility grouping is enabled, the component and all its children are treated as a single selectable unit, and the accessibility service will no longer focus on the individual child components.

If accessibility grouping is enabled and the component does not contain a universal text attribute or an [accessibility text](#accessibilitytext) attribute, the system will concatenate the universal text attributes of its child components to form a merged text for the component. If a child component lacks a universal text attribute, it will be ignored in the concatenation process. The merged text will not use the accessibility text of the child components.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether to enable accessibility grouping. When accessibility grouping is enabled, the component and all its children are treated as a single selectable unit, and the accessibility service will no longer focus on the individual child components.<br>Default value: **false**|

## accessibilityGroup<sup>14+</sup>

accessibilityGroup(isGroup: boolean, accessibilityOptions: AccessibilityOptions)

Sets whether to enable accessibility grouping, with support for prioritizing the concatenation of accessibility text for accessibility announcement. When accessibility grouping is enabled, the component and all its children are treated as a single selectable entity, and the accessibility service will no longer focus on the individual child components.

If accessibility grouping is enabled and the component does not contain a universal text attribute or an [accessibility text](#accessibilitytext) attribute, the system will concatenate the universal text attributes of its child components to form a merged text for the component. If a child component lacks a universal text attribute, it will be ignored in the concatenation process.

When **accessibilityPreferred** is set to **true**, the system will prioritize concatenating the accessibility text attributes of the child components to form the merged text. If a child component lacks an accessibility text attribute, the system will continue to concatenate its universal text attribute. If a child component lacks both, it will be ignored.

**Widget capability**: This API can be used in ArkTS widgets since API version 14.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name              | Type                                                   | Mandatory| Description                                                        |
| -------------------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| isGroup              | boolean                                                 | Yes  | Whether to enable accessibility grouping. When accessibility grouping is enabled, the component and all its children are treated as a single selectable unit, and the accessibility service will no longer focus on the individual child components.<br>Default value: **false**|
| accessibilityOptions | [AccessibilityOptions](#accessibilityoptions14) | Yes  | Options for accessibility grouping. When **accessibilityPreferred** is set to **true**, the system will prioritize concatenating the accessibility text attributes of the child components to form the merged text.<br>Default value: **false**           |

## AccessibilityOptions<sup>14+</sup>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                  | Type   | Mandatory| Description                                                        |
| ---------------------- | ------- | ---- | ------------------------------------------------------------ |
| accessibilityPreferred | boolean | No  | Whether to prioritize the accessibility text of child components during a deep traversal. The value **true** means to prioritize the accessibility text of child components.<br>If a child component's accessibility text is empty, the accessibility service uses the component's own text content. The concatenated text is then assigned to the parent node if both its accessibility text and text content are empty.<br>Default value: **false**|

## accessibilityText

accessibilityText(value: string)

Sets the accessibility text. When a component does not contain a text attribute, you can use this API to set an accessibility text attribute, so that accessibility services can announce the specified content for the component.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | string | Yes  | Accessibility text. If a component does not contain text information, it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set accessibility text for components without text information. When such a component is selected, the screen reader announces the specified accessibility text, informing the user which component is selected.<br>Default value: **""**<br>**NOTE**<br>If a component has both text content and accessibility text, only the accessibility text is announced.<br>If a component is grouped for accessibility purposes but lacks both text content and accessibility text, the screen reader will concatenate text from its child components (depth-first traversal).<br>To prioritize accessibility text concatenation, set **accessibilityPreferred** in **accessibilityGroup**.|

## accessibilityText<sup>12+</sup>

accessibilityText(text: Resource)

Sets the accessibility text, with support for resource references using **Resource**. When a component does not contain a text attribute, you can use this API to set an accessibility text attribute, so that accessibility services can announce the specified content for the component.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                                                                                                                                                                                                                                  |
| ------ | ------ | ---- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| text  | [Resource](ts-types.md#resource) | Yes  | Reference resource of accessibility text. If a component does not contain text information, it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set accessibility text for components without text information. When such a component is selected, the screen reader announces the specified accessibility text, informing the user which component is selected.<br>**NOTE**<br>If a component has both text content and accessibility text, only the accessibility text is announced.<br>If a component is grouped for accessibility purposes but lacks both text content and accessibility text, the screen reader will concatenate text from its child components (depth-first traversal).<br>To prioritize accessibility text concatenation, set **accessibilityPreferred** in **accessibilityGroup**.|


## accessibilityDescription

accessibilityDescription(value: string)

Sets the accessibility description. This property provides additional context or explanation for the component, helping users understand the action or function it performs.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | string | Yes  | Accessibility description. You can specify further explanation of the current component, for example, possible operation consequences, especially those that cannot be learned from component attributes and accessibility text. If a component contains both text information and the accessibility description, the text is read first and then the accessibility description, when the component is selected.<br>Default value: **""**|

## accessibilityDescription<sup>12+</sup>

accessibilityDescription(description: Resource)

Sets the accessibility description, with support for resource references using **Resource**. This property provides additional context or explanation for the component, helping users understand the action or function it performs.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                                                                                                                                                   |
| ------ | ------ | ---- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| description  | [Resource](ts-types.md#resource) | Yes  | Reference resource of the accessibility description. You can specify further explanation of the current component, for example, possible operation consequences, especially those that cannot be learned from component attributes and accessibility text. If a component contains both text information and the accessibility description, the text is read first and then the accessibility description, when the component is selected.|

## accessibilityLevel

accessibilityLevel(value: string)

Sets the accessibility level. This property determines whether the component can be recognized by accessibility services.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | string | Yes  | Accessibility level, which is used to decide whether a component can be identified by the accessibility service.<br>The options are as follows:<br>**"auto"**: The component's recognizability is determined by the accessibility grouping service and ArkUI.<br>**"yes"**: The component can be recognized by accessibility services.<br>**"no"**: The component cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: Neither the component nor its child components can be recognized by accessibility services.<br>Default value: **"auto"**<br>**NOTE**<br>When accessibilityLevel is set to **"auto"**, the component's recognizability depends on the following factors:<br>1. The accessibility service internally determines whether the component can be recognized.<br>2. If the parent component's **accessibilityGroup** property has **isGroup** set to **true**, the accessibility service will not focus on its child components, making them unrecognizable.<br>3. If the parent component's **accessibilityLevel** is set to **"no-hide-descendants"**, the component will not be recognized by accessibility services.|

## accessibilityVirtualNode<sup>11+</sup>

accessibilityVirtualNode(builder: CustomBuilder)

Sets an accessibility virtual child node. For custom drawing components, a **CustomBuilder** is passed, which is used to provide accessibility information. The components within the **CustomBuilder** are only used for layout and not for display. When the accessibility service obtains node information, it returns the node information from the **CustomBuilder**.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| builder  | [CustomBuilder](ts-types.md#custombuilder8) | Yes  | Accessibility virtual node, which enables you to pass in a custom builder to the self-drawing component. The components in the custom builder are only laid out but not displayed at the backend. When the accessibility application obtains the accessibility node information, the node information in the custom builder is returned.|

## accessibilityChecked<sup>13+</sup>

accessibilityChecked(isCheck: boolean)

Sets the checked state of the accessibility component. This property is used in multiselect scenarios.

**Widget capability**: This API can be used in ArkTS widgets since API version 13.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| isCheck | boolean | Yes  | Whether the current component is selected.<br>The options are as follows:<br>**true**: The component is selected.<br>**false**: The component is not selected.<br>**undefined**: The component determines its own selected state.<br>Default value: **undefined**<br>**NOTE**<br>1. Setting this parameter to **true** or **false** will automatically set the component's **checkable** attribute to **true**.<br>2. When this parameter is set to **true** or **false**, to use it with **accessibilitySelected**, set the **accessibilitySelected** parameter to **undefined**.|

## accessibilitySelected<sup>13+</sup>

accessibilitySelected(isSelect: boolean)

Sets the selected state of the accessibility component. This property is used in single-select scenarios.

**Widget capability**: This API can be used in ArkTS widgets since API version 13.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| isSelect | boolean | Yes  | Whether the current component is selected.<br>The options are as follows:<br>**true**: The component is selected.<br>**false**: The component is not selected.<br>**undefined**: The component determines its own selected state.<br>Default value: **undefined**<br>**NOTE**<br>1. When this parameter is set to **true** or **false**, to use it with **accessibilityChecked**, set the **accessibilityChecked** parameter to **undefined**.|

## accessibilityTextHint<sup>12+</sup>

accessibilityTextHint(value: string)

Sets the text hint for the component, which can be queried by accessibility services.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name        |  Type   | Mandatory| Description                                                        |
| -------------- | ------- | ---- | ------------------------------------------------------------ |
| value  | string | Yes  | Text hint for the component, which can be queried by accessibility services.|


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
      .accessibilityDescription("The Column component is selectable , and the text to be read out is "Group".)
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

