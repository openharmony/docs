# 无障碍属性

组件可以设置相应的无障碍属性和事件来更好地使用无障碍能力。

>  **说明：**
>
>  从API Version 10 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## accessibilityGroup

accessibilityGroup(value: boolean)

无障碍组。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | 是   | 无障碍组，设置为true时表示该组件及其所有子组件为一整个可以选中的组件，无障碍服务将不再关注其子组件内容。<br/>默认值：false |

## accessibilityGroup<sup>14+</sup>

accessibilityGroup(isGroup: boolean, accessibilityOptions: AccessibilityOptions)

无障碍组，支持优先拼接无障碍文本进行朗读。

**卡片能力：** 从API version 14开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名               | 类型                                                    | 必填 | 说明                                                         |
| -------------------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| isGroup              | boolean                                                 | 是   | 无障碍组，设置为true时表示该组件及其所有子组件为一整个可以选中的组件，无障碍服务将不再关注其子组件内容。<br/>默认值：false |
| accessibilityOptions | [AccessibilityOptions](#accessibilityoptions14对象说明) | 否   | 设置为true时，使应用优先拼接无障碍文本进行朗读。             |

## AccessibilityOptions<sup>14+</sup>对象说明

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                   | 类型    | 必填 | 说明                                                         |
| ---------------------- | ------- | ---- | ------------------------------------------------------------ |
| accessibilityPreferred | boolean | 否   | 若accessibilityPreferred设置为true，则深度遍历每个子节点时优先选择该子节点的无障碍文本accessibilityText。<br/>若无障碍文本为空则选择本身Text文本，最终将拼接完成的文本设置给accessibilityText与Text都为空的父节点。 |

## accessibilityText

accessibilityText(value: string)

无障碍文本。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | string | 是   | 无障碍文本，当组件不包含文本属性时，屏幕朗读选中此组件时不播报，使用者无法清楚地知道当前选中了什么组件。为了解决此场景，开发人员可为不包含文字信息的组件设置无障碍文本，当屏幕朗读选中此组件时播报无障碍文本的内容，帮助屏幕朗读的使用者清楚地知道自己选中了什么组件。<br/>默认值：“”<br/>**说明：**<br/>若组件既拥有文本属性，又拥有无障碍文本属性，则组件被选中时，仅播报无障碍文本内容。<br/>若组件设置了无障碍分组属性为true，但是即没有无障碍文本属性，也没有文本属性，会对其子节点的组件进行文本拼接（深度优先）。<br/>不对无障碍文本属性进行拼接，如需优先拼接无障碍文本，则需设置accessibilityGroup的accessibilityPreferred。 |

## accessibilityText<sup>12+</sup>

accessibilityText(text: Resource)

无障碍文本，支持通过Resource引用资源文件。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                                                                                                                                                                                                                                   |
| ------ | ------ | ---- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| text  | [Resource](ts-types.md#resource) | 是   | 无障碍文本引用资源，当组件不包含文本属性时，屏幕朗读选中此组件时不播报，使用者无法清楚地知道当前选中了什么组件。为了解决此场景，开发人员可为不包含文字信息的组件设置无障碍文本，当屏幕朗读选中此组件时播报无障碍文本的内容，帮助屏幕朗读的使用者清楚地知道自己选中了什么组件。<br/>**说明：**<br/>若组件既拥有文本属性，又拥有无障碍文本属性，则组件被选中时，仅播报无障碍文本内容。<br/>若组件设置了无障碍分组属性为true，但是即没有无障碍文本属性，也没有文本属性，会对其子节点的组件进行文本拼接（深度优先）。<br/>不对无障碍文本属性进行拼接，如需优先拼接无障碍文本，则需设置accessibilityGroup的accessibilityPreferred。 |


## accessibilityDescription

accessibilityDescription(value: string)

无障碍说明。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | string | 是   | 无障碍说明，用于为用户进一步说明当前组件，开发人员可为组件的该属性设置相对较详细的解释文本，帮助用户理解将要执行的操作。如帮助用户理解将要执行的操作可能导致什么后果，尤其是当这些后果无法从组件本身属性与无障碍文本中了解到时。若组件既拥有文本属性又拥有无障碍说明属性，则组件被选中时，先播报组件的文本属性，再播报无障碍说明属性的内容。<br/>默认值：“” |

## accessibilityDescription<sup>12+</sup>

accessibilityDescription(description: Resource)

无障碍说明，支持通过Resource引用资源文件。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                                                                                                                                                    |
| ------ | ------ | ---- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| description  | [Resource](ts-types.md#resource) | 是   | 无障碍说明引用资源，用于为用户进一步说明当前组件，开发人员可为组件的该属性设置相对较详细的解释文本，帮助用户理解将要执行的操作。如帮助用户理解将要执行的操作可能导致什么后果，尤其是当这些后果无法从组件本身属性与无障碍文本中了解到时。若组件既拥有文本属性又拥有无障碍说明属性，则组件被选中时，先播报组件的文本属性，再播报无障碍说明属性的内容。 |

## accessibilityLevel

accessibilityLevel(value: string)

无障碍重要性。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | string | 是   | 无障碍重要性，用于控制某个组件是否可被无障碍辅助服务所识别。<br/>支持的值为:<br/>"auto"：根据组件不同会转换为“yes”或者“no”。<br/>"yes"：当前组件可被无障碍辅助服务所识别。<br/>"no"：当前组件不可被无障碍辅助服务所识别。<br/>"no-hide-descendants"：当前组件及其所有子组件不可被无障碍辅助服务所识别。<br/>默认值："auto"<br/>**说明：**<br/>以下组件当accessibilityLevel设置成"auto"时，当前组件可被无障碍辅助服务所识别：Checkbox, CheckboxGroup, Gauge, Marquee, MenuItem, MenuItemGroup, Menu, Navigation,  DatePicker, Progress, Radio, Rating, ScrollBar, Select, Slider, Stepper, Text, TextClock, TextPicker, TextTimer, TimePicker, Toggle, Web. |

## accessibilityVirtualNode<sup>11+</sup>

accessibilityVirtualNode(builder: CustomBuilder)

无障碍虚拟节点。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| builder  | [CustomBuilder](ts-types.md#custombuilder8) | 是   | 无障碍虚拟子节点，使开发者可以对自绘制组件传入一个自定义的CustomBuilder，该CustomBuilder中的组件在后端仅做布局不做显示，辅助应用获取无障碍节点信息时会返回CustomBuilder中的节点信息。 |

## accessibilityChecked<sup>13+</sup>

accessibilityChecked(isCheck: boolean)

无障碍节点是否选中的状态维护，用于支持多选的情况使用。

**卡片能力：** 从API version 13开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| isCheck | boolean | 是   | 用于表示组件是否被选中。<br/>支持的值为:<br/>true:当前组件被选中。<br/>false:当前组件未被选中。<br/>undefined:由组件自行确定选中状态。<br/>默认值:undefined。<br/>**说明：**<br/>1. 使用该接口设置true或false后，会默认修改该组件的checkable属性为true。<br/>2. 使用该接口设置true或false后，如果需要同时使用accessibilitySelected接口则需要将accessibilitySelected接口的参数设置为undefined。 |

## accessibilitySelected<sup>13+</sup>

accessibilitySelected(isSelect: boolean)

无障碍节点是否选中的状态维护，用于支持单选的情况使用。

**卡片能力：** 从API version 13开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型    | 必填 | 说明                                                         |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| isSelect | boolean | 是   | 用于表示组件是否被选中。<br/>支持的值为:<br/>true:当前组件被选中。<br/>false:当前组件未被选中。<br/>undefined:由组件自行确定选中状态。<br/>默认值:undefined。<br/>**说明：**<br/>1. 使用该接口设置true或false后，如果需要同时使用accessibilityChecked接口则需要将accessibilityChecked接口的参数设置为undefined。 |



## 示例 1

该示例主要演示accessibilityText无障碍文本和accessibilityDescription无障碍说明的播报内容。

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
        Text("文本1")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Text("文本2")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
      .accessibilityGroup(true)
      .accessibilityLevel("yes")
      .accessibilityText("分组") // 无障碍文本的内容，若组件既拥有文本属性又拥有无障碍文本属性，则组件被选中时，仅播报无障碍文本内容。
      .accessibilityDescription("Column组件可以被选中，播报的内容是“分组”")
      .accessibilityVirtualNode(this.customAccessibilityNode)
      .accessibilityChecked(true)
      .accessibilitySelected(undefined)
    }
    .height('100%')
  }
}
```

## 示例 2

该示例主要演示优先使用子组件的无障碍文本进行朗读。

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
        .accessibilityText("有accessibility有text优先读accessibility")
        .accessibilityLevel("yes")
      Button().accessibilityLevel("yes").accessibilityText("accessibility无text 读accessibility")
      Button("无accessibility有text 读text").accessibilityLevel("yes")
      Button()
      Button('btnl23').accessibilityText("有accessibility有text btn123").accessibilityLevel("yes")
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

## 
