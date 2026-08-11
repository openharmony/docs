# ColumnSplit
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zju_ljz-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

将子组件纵向布局，并在每个子组件之间插入横向分割线。适用于需要垂直方向上多区域布局且支持动态调整区域大小的场景，如仪表盘界面、可调节高度的上下分区布局等。通过可拖拽的分割线，用户可以灵活调整各区域高度，提升界面交互性和用户体验。

>  **说明：**
>
> 该组件从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
## 子组件

可以包含子组件。

ColumnSplit通过分割线限制子组件的高度。初始化时，分割线位置根据子组件的高度来计算。初始化后，动态修改子组件的高度不生效，分割线位置保持不变。设置resizeable(true)后，可通过拖动相邻分割线改变子组件高度。

初始化后，当动态修改[margin](ts-universal-attributes-size.md#margin)、[border](ts-universal-attributes-border.md#border)、[padding](ts-universal-attributes-size.md#padding)通用属性导致子组件尺寸大于相邻分割线间距时，不支持拖动分割线改变子组件的高度。
## 接口

ColumnSplit()

带分割线的子组件纵向布局。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## 属性

除支持[通用属性](ts-component-general-attributes.md)外，还支持以下属性：

> **说明：**
>
> ColumnSplit组件[形状裁剪](ts-universal-attributes-sharp-clipping.md)的默认值为true。

### resizeable

resizeable(value: boolean)

设置分割线是否可拖拽。设置为true时，用户可拖动分割线调整相邻子组件高度；设置为false时，分割线不可拖动，子组件高度固定。

>  **说明：**
>
> 初始化后，当动态修改[margin](ts-universal-attributes-size.md#margin)、[border](ts-universal-attributes-border.md#border)、[padding](ts-universal-attributes-size.md#padding)通用属性导致子组件尺寸大于相邻分割线间距时，不支持拖动分割线改变子组件的高度。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                 |
| ------ | ------- | ---- | ------------------------------------ |
| value  | boolean | 是   | 分割线是否可拖动。设置为true时表示分割线可拖动，设置为false时表示分割线不可拖动。子组件的高度调整范围受其最大最小高度限制；当子组件尺寸大于相邻分割线间距时，不支持拖动分割线。初始化后，当动态修改margin、border、padding通用属性导致子组件尺寸大于相邻分割线间距时，不支持拖动分割线改变子组件的高度。<br>默认值：false <br>非法值：按默认值处理。 |

### divider<sup>10+</sup>

divider(value: ColumnSplitDividerStyle | null)

设置分割线与子组件之间的距离。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [ColumnSplitDividerStyle](#columnsplitdividerstyle10对象说明)&nbsp;\|&nbsp;null | 是   | 分割线的margin，即设置分割线与子组件的距离。对象属性包括：startMargin（子组件与上方分割线的距离）和endMargin（子组件与下方分割线的距离）。<br>默认值：null。当设置为null时，分割线与子组件的距离为0vp。<br>非法值：按默认值处理。 |

## ColumnSplitDividerStyle<sup>10+</sup>对象说明

设置子组件与上下分割线的距离。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| startMargin | [Dimension](ts-types.md#dimension10)       | 否 | 是  | 子组件与其上方分割线的距离。可调整间距（如避免内容与分割线重叠、美化布局等场景）。<br>默认值：0vp<br>取值范围：不支持负值。<br>非法值：按默认值处理，此时[getInspectorByKey()](ts-universal-attributes-component-id.md#getinspectorbykey9)接口获取到的属性值为undefined。 |
| endMargin   | [Dimension](ts-types.md#dimension10)       | 否 | 是  | 子组件与其下方分割线的距离。可调整间距（如避免内容与分割线重叠、美化布局等场景）。<br>默认值：0vp<br>取值范围：不支持负值。<br>非法值：按默认值处理，此时[getInspectorByKey()](ts-universal-attributes-component-id.md#getinspectorbykey9)接口获取到的属性值为undefined。 |

>  **说明：**
>
> 与[RowSplit](ts-container-rowsplit.md)相同，ColumnSplit的分割线可调整上下两侧子组件的高度，子组件的高度调整范围受其最大最小高度限制。
>
> 支持[clip](ts-universal-attributes-sharp-clipping.md#clip12)、[margin](ts-universal-attributes-size.md#margin)等通用属性，未设置clip属性时，其默认值为true。

## 事件

支持[通用事件](ts-component-general-events.md)。

## 示例

### 示例1（设置可拖动的ColumnSplit组件）

本示例展示如何设置可拖动的ColumnSplit组件及其效果。

``` ts
// xxx.ets
@Entry
@Component
struct ColumnSplitExample {
  build() {
    Column() {
      Text('The dividing line can be dragged').fontSize(9).fontColor(0xCCCCCC).width('90%')
      ColumnSplit() {
        Text('1').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('2').width('100%').height(50).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('3').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('4').width('100%').height(50).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('5').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
      }
      .borderWidth(1)
      .resizeable(true) // 设置分割线可拖拽
      .width('90%').height('60%')
    }.width('100%')
  }
}
```

![columnSplitDividerStyle](figures/columnSplitDividerStyle.gif)

### 示例2（设置带有间隔的ColumnSplit组件）

本示例展示如何设置带有间隔的ColumnSplit组件及其效果。

``` ts
// xxx.ets
@Entry
@Component
struct ColumnSplitDividerExample {
  build() {
    Column() {
      Text('The dividing line can be dragged').fontSize(9).fontColor(0xCCCCCC).width('90%')
      ColumnSplit() {
        Text('1').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('2').width('100%').height(50).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('3').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('4').width('100%').height(50).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('5').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
      }
      .borderWidth(1)
      .divider({ startMargin: 5, endMargin: 5 }) // 设置分割线与子组件的距离
      .width('90%')
      .height('60%')
    }.width('100%')
  }
}
```

![ColumnSplitDividerExample](figures/ColumnSplitDividerExample.png)
