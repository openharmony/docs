# ArkUI无障碍能力

## 概述

ArkUI提供了丰富的无障碍能力，使开发者能够创建可访问的应用界面，满足视觉、听觉、运动和认知障碍等用户的需求。

组件的无障碍属性值变化时，通常会触发辅助工具重新读取组件信息、无障碍服务重新扫描组件树、状态播报、虚拟节点动态更新等响应和行为，这些机制旨在确保辅助工具（如屏幕朗读）能及时感知并适配变化，从而为障碍用户提供连贯的体验。

## 设置无障碍分组

accessibilityGroup属性，用于将组件及其子组件作为一个整体处理，无障碍服务不再单独处理子组件。

这里以Column组件为例，启用无障碍分组：

```ts
Column() {
}
.accessibilityGroup(true)
```

## 设置无障碍重要性

accessibilityLevel属性，用于控制组件是否可被无障碍服务识别，支持以下值：

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

accessibilityText属性，用于为无文本内容的组件提供朗读文本。若组件已有文本，则优先播报无障碍文本。

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

accessibilityDescription属性，用于提供更详细的组件说明，播报时紧随文本内容之后。

这里以Column组件为例，设置其无障碍说明为“分组”，用于为用户进一步说明当前组件：

```ts
Column() {
}
.accessibilityGroup(true)
.accessibilityLevel("yes")
.accessibilityText("分组")
.accessibilityDescription("Column组件可以被选中，播报的内容是“分组”")
```

## 设置无障碍虚拟子节点

accessibilityVirtualNode属性，用于为自绘制组件添加虚拟无障碍节点，辅助工具会读取这些节点的信息而非实际显示内容。

## 设置无障碍节点是否被选中

accessibilityChecked和accessibilitySelected是两个用于增强无障碍体验的属性，它们主要用于向屏幕朗读等辅助工具传达组件的选中状态。

### 在支持多选的情况下，设置无障碍节点是否被选中

accessibilityChecked属性，用于表示组件在支持多选的情况下是否被勾选（如复选框、开关按钮等二态或三态组件），适用于需要明确“选中/未选中”语义的场景，支持以下值：

- undefined（默认）：由系统自动判断（依赖组件自身的状态，如 Toggle 组件的 isOn 属性）。

- true：表示选中（如复选框打勾）。

- false：表示未选中。

这里以Column组件为例，设置其在支持多选的情况下被选中：

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

accessibilitySelected属性，用于表示组件在支持单选的情况下是否被选择（如单选列表项、标签页等），适用于需要区分“当前选中项”的场景（如单选组、导航菜单），支持以下值：

- undefined（默认）：由系统自动判断。

- true：表示当前选中。

- false：表示未选中。

这里以Column组件为例，设置在支持单选的情况下由系统自行确定其选中状态：

```ts
Column() {
}
.accessibilityGroup(true)
.accessibilityLevel("yes")
.accessibilityText("分组")
.accessibilityDescription("Column组件可以被选中，播报的内容是“分组”")
.accessibilitySelected(undefined)
```

### accessibilityChecked属性与accessibilitySelected属性的关键区别

| 属性    | accessibilityChecked     | accessibilitySelected |
| ------- | ------------------------ | --------------------- |
| 常见场景 | 复选框、开关等二态/三态组件 | 单选列表、标签页等互斥选择场景 |
| 语义    | “勾选”状态                | 	“焦点选中”状态 |
| 自动播报 | 通常自动触发             | 可能需要手动通知事件 |
| 典型组件 | Checkbox，Toggle，Switch | Radio，Tabs，列表项 |

## 使用建议

- 优先级控制

  通过accessibilityLevel确保关键操作可被识别。

- 语义化描述

  为图标、图片等非文本元素添加accessibilityText和accessibilityDescription。

- 分组优化

  对复杂布局使用accessibilityGroup减少冗余播报。

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