# ArkUI 无障碍能力

## 概述

ArkUI提供了丰富的无障碍能力，使开发者能够创建可访问的应用界面，满足视觉、听觉、运动和认知障碍等用户的需求。

组件的无障碍属性值变化时，通常会触发辅助工具重新读取组件信息、无障碍服务重新扫描组件树、状态播报、虚拟节点动态更新等响应和行为，这些机制旨在确保辅助工具（如屏幕朗读）能及时感知并适配变化，从而为障碍用户提供连贯的体验。

## 设置无障碍分组

将该组件及其子组件作为一个整体处理，无障碍服务不再单独处理子组件。

这里以Column组件为例，启用无障碍分组：

```ts
Column() {
}
.accessibilityGroup(true)
```

## 设置无障碍重要性

控制组件是否可被无障碍服务识别，支持以下值：

- "auto"（默认）：根据组件类型自动判断。

- "yes"：显式启用识别。

- "no"：显式禁用识别。

- "no-hide-descendants"：隐藏当前组件及其所有子组件。

这里以Column组件为例，设置其无障碍重要性为可被无障碍辅助服务所识别：

```ts
Column() {
}
.accessibilityGroup(true)
.accessibilityLevel("yes")
```

## 设置无障碍文本

为无文本内容的组件提供朗读文本。若组件已有文本，则优先播报无障碍文本。

支持字符串或资源引用。

这里以Column组件为例，设置其无障碍文本为“分组”：

```ts
Column() {
}
.accessibilityGroup(true)
.accessibilityLevel("yes")
.accessibilityText("分组")
```

## 设置无障碍说明

提供更详细的组件说明，播报时紧随文本内容之后。

这里以Column组件为例，设置其无障碍说明为“分组”，用于为用户进一步说明当前组件：

```ts
Column() {
}
.accessibilityGroup(true)
.accessibilityLevel("yes")
.accessibilityText("分组")
.accessibilityDescription("Column组件可以被选中，播报的内容是“分组”")
```

## 设置无障碍节点是否被选中

### 在支持多选的情况下，设置无障碍节点是否被选中

在支持多选的情况下，设置 Column 组件被选中

```ts
Column() {
}
.accessibilityGroup(true)
.accessibilityLevel("yes")
.accessibilityText("分组")
.accessibilityDescription("Column组件可以被选中，播报的内容是“分组”")
.accessibilityChecked(true)
```

### 在支持单选的情况下，设置无障碍节点是否被选中

在支持单选的情况下，设置 Column 组件自行确定选中状态

```ts
Column() {
}
.accessibilityGroup(true)
.accessibilityLevel("yes")
.accessibilityText("分组")
.accessibilityDescription("Column组件可以被选中，播报的内容是“分组”")
.accessibilitySelected(undefined)
```

## 场景示例

该示例主要演示accessibilityText无障碍文本和accessibilityDescription无障碍说明的播报内容。

其中，对于该组件的无障碍文本的内容，在既拥有文本属性又拥有无障碍文本属性的情况下，当组件被选中时，仅播报无障碍文本内容。

```ts
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
      .accessibilityText("分组")
      .accessibilityDescription("Column组件可以被选中，播报的内容是“分组”")
      .accessibilityVirtualNode(this.customAccessibilityNode)
      .accessibilityChecked(true)
      .accessibilitySelected(undefined)
    }
    .height('100%')
  }
}
```

![zh-cn_image_0000001745415556](figures/zh-cn_image_0000001745415556.jpg)
<!--RP1--><!--RP1End-->