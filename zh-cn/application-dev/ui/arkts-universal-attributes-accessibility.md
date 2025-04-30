# ArkUI 无障碍能力

组件可以设置对应的无障碍属性和事件，从而更好地使用无障碍能力。

## 启用无障碍分组

这里以 Column 组件为例，启用无障碍分组

```ts
Column() {
}
.accessibilityGroup(true)
```

## 设置无障碍重要性

设置 Column 组件的无障碍重要性为可被无障碍辅助服务所识别

```ts
Column() {
}
.accessibilityGroup(true)
.accessibilityLevel("yes")
```

## 设置无障碍文本

设置 Column 组件的无障碍文本为“分组”

```ts
Column() {
}
.accessibilityGroup(true)
.accessibilityLevel("yes")
.accessibilityText("分组")
```

## 设置无障碍说明

设置 Column 组件的无障碍说明为“分组”，用于为用户进一步说明当前组件

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