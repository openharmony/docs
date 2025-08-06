# 边框设置
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zju_ljz-->
<!--SE: @lanshouren-->
<!--TSE: @liuli0427-->

设置组件边框样式。

>  **说明：**
>
>  从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>

## border

border(value: BorderOptions): T

设置边框样式。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                    | 必填 | 说明                                                         |
| ------ | --------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [BorderOptions](#borderoptions对象说明) | 是   | 统一边框样式设置接口。<br/>**说明：** <br/>边框宽度默认值为0，即不显示边框。<br/>从API version 9开始，父节点的border显示在子节点内容之上。 |

**返回值：**

| 类型 | 说明 |
| --- | --- |
|  T | 返回当前组件。 |

## borderStyle

borderStyle(value: BorderStyle | EdgeStyles): T

设置元素的边框线条样式。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                               |
| ------ | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| value  | [BorderStyle](ts-appendix-enums.md#borderstyle)&nbsp;\|&nbsp;[EdgeStyles](#edgestyles9对象说明)<sup>9+</sup> | 是   | 设置元素的边框样式。<br/>默认值：BorderStyle.Solid |

**返回值：**

| 类型 | 说明 |
| --- | --- |
|  T | 返回当前组件。 |

## borderWidth

borderWidth(value: Length | EdgeWidths | LocalizedEdgeWidths): T

设置边框的宽度。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                               |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------- |
| value  | [Length](ts-types.md#length)&nbsp;\|&nbsp;[EdgeWidths](#edgewidths9对象说明)<sup>9+</sup>&nbsp;\|&nbsp;[LocalizedEdgeWidths](#localizededgewidths12对象说明)<sup>12+</sup> | 是   | 设置元素的边框宽度，不支持百分比。 |

**返回值：**

| 类型 | 说明 |
| --- | --- |
|  T | 返回当前组件。 |

## borderColor

borderColor(value: ResourceColor | EdgeColors | LocalizedEdgeColors): T

设置边框的颜色。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                         |
| ------ | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| value  | [ResourceColor](ts-types.md#resourcecolor)&nbsp;\|&nbsp;[EdgeColors](#edgecolors9对象说明)<sup>9+</sup>&nbsp;\|&nbsp;[LocalizedEdgeColors](#localizededgecolors12对象说明)<sup>12+</sup> | 是   | 设置元素的边框颜色。<br/>默认值：Color.Black |

**返回值：**

| 类型 | 说明 |
| --- | --- |
|  T | 返回当前组件。 |

## borderRadius

borderRadius(value: Length | BorderRadiuses | LocalizedBorderRadiuses): T

设置边框的圆角。圆角大小受组件尺寸限制，最大值为组件宽或高的一半。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                   |
| ------ | ------------------------------------------------------------ | ---- | -------------------------------------- |
| value  | [Length](ts-types.md#length)&nbsp;\|&nbsp;[BorderRadiuses](#borderradiuses9对象说明)<sup>9+</sup>&nbsp;\|&nbsp;[LocalizedBorderRadiuses](#localizedborderradiuses12对象说明)<sup>12+</sup> | 是   | 设置元素的边框圆角半径，支持百分比，百分比依据组件宽度。设置圆角后，可搭配[.clip属性](./ts-universal-attributes-sharp-clipping.md#clip12)进行裁剪，避免子组件超出组件自身。|

**返回值：**

| 类型 | 说明 |
| --- | --- |
|  T | 返回当前组件。 |

## BorderOptions对象说明

| 名称   | 参数类型                                                     | 必填 | 描述               |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| width  | [Length](ts-types.md#length)&nbsp;\|&nbsp;[EdgeWidths](#edgewidths9对象说明)<sup>9+</sup>&nbsp;\|&nbsp;[LocalizedEdgeWidths](#localizededgewidths12对象说明)<sup>12+</sup> | 否   | 设置边框宽度。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。     |
| color  | [ResourceColor](ts-types.md#resourcecolor)&nbsp;\|&nbsp;[EdgeColors](#edgecolors9对象说明)<sup>9+</sup>&nbsp;\|&nbsp;[LocalizedEdgeColors](#localizededgecolors12对象说明)<sup>12+</sup> | 否   | 设置边框颜色。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。     |
| radius | [Length](ts-types.md#length)&nbsp;\|&nbsp;[BorderRadiuses](#borderradiuses9对象说明)<sup>9+</sup>&nbsp;\|&nbsp;[LocalizedBorderRadiuses](#localizedborderradiuses12对象说明)<sup>12+</sup> | 否   | 设置边框圆角半径。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| style  | [BorderStyle](ts-appendix-enums.md#borderstyle)&nbsp;\|&nbsp;[EdgeStyles](#edgestyles9对象说明)<sup>9+</sup> | 否   | 设置边框样式。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。    |
| dashGap<sup>12+</sup>  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)&nbsp;\|&nbsp;[EdgeWidths](#edgewidths9对象说明)&nbsp;\|&nbsp;[LocalizedEdgeWidths](#localizededgewidths12对象说明) | 否  | 设置虚线的线段间距，仅在边框样式为虚线时生效。<br/>不支持设置百分比。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br/>**卡片能力：** 该接口不支持在ArkTS卡片中使用。|
| dashWidth<sup>12+</sup>  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)&nbsp;\|&nbsp;[EdgeWidths](#edgewidths9对象说明)&nbsp;\|&nbsp;[LocalizedEdgeWidths](#localizededgewidths12对象说明) | 否   | 设置虚线的线段长度，仅在边框样式为虚线时生效。<br/>不支持设置百分比。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br/>**卡片能力：** 该接口不支持在ArkTS卡片中使用。     |

## EdgeWidths<sup>9+</sup>对象说明

引入该对象时，至少传入一个参数。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称     | 参数类型                         | 必填   | 描述      |
| ------ | ---------------------------- | ---- | ------- |
| left   | [Length](ts-types.md#length) | 否    | 左侧边框宽度。 |
| right  | [Length](ts-types.md#length) | 否    | 右侧边框宽度。 |
| top    | [Length](ts-types.md#length) | 否    | 上侧边框宽度。 |
| bottom | [Length](ts-types.md#length) | 否    | 下侧边框宽度。 |

## LocalizedEdgeWidths<sup>12+</sup>对象说明

边框宽度类型，用于描述组件边框不同方向的宽度。
引入该对象时，至少传入一个参数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

| 名称     | 参数类型                         | 必填   | 描述      |
| ------ | ---------------------------- | ---- | ------- |
| start   | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否    | 左侧边框宽度。<br />从右至左显示语言模式下为右侧边框宽度。 |
| end     | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否    | 右侧边框宽度。<br />从右至左显示语言模式下为左侧边框宽度。 |
| top     | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否    | 上侧边框宽度。 |
| bottom  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否    | 下侧边框宽度。 |

## EdgeColors<sup>9+</sup>对象说明

引入该对象时，至少传入一个参数。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称     | 参数类型                                     | 必填   | 描述      |
| ------ | ---------------------------------------- | ---- | ------- |
| left   | [ResourceColor](ts-types.md#resourcecolor) | 否    | 左侧边框颜色。 |
| right  | [ResourceColor](ts-types.md#resourcecolor) | 否    | 右侧边框颜色。 |
| top    | [ResourceColor](ts-types.md#resourcecolor) | 否    | 上侧边框颜色。 |
| bottom | [ResourceColor](ts-types.md#resourcecolor) | 否    | 下侧边框颜色。 |

## LocalizedEdgeColors<sup>12+</sup>对象说明

边框颜色，描述组件边框四条边的颜色。

引入该对象时，至少传入一个参数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称     | 参数类型                                     | 必填   | 描述      |
| ------ | ---------------------------------------- | ---- | ------- |
| start   | [ResourceColor](ts-types.md#resourcecolor) | 否    | 左侧边框颜色。<br />从右至左显示语言模式下为右侧边框颜色。 |
| end     | [ResourceColor](ts-types.md#resourcecolor) | 否    | 右侧边框颜色。<br />从右至左显示语言模式下为左侧边框颜色。 |
| top     | [ResourceColor](ts-types.md#resourcecolor) | 否    | 上侧边框颜色。 |
| bottom  | [ResourceColor](ts-types.md#resourcecolor) | 否    | 下侧边框颜色。 |

## BorderRadiuses<sup>9+</sup>对象说明

引用该对象时，至少传入一个参数。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称          | 参数类型                         | 必填   | 描述       |
| ----------- | ---------------------------- | ---- | -------- |
| topLeft     | [Length](ts-types.md#length) | 否    | 左上角圆角半径。 |
| topRight    | [Length](ts-types.md#length) | 否    | 右上角圆角半径。 |
| bottomLeft  | [Length](ts-types.md#length) | 否    | 左下角圆角半径。 |
| bottomRight | [Length](ts-types.md#length) | 否    | 右下角圆角半径。 |

## LocalizedBorderRadiuses<sup>12+</sup>对象说明

圆角类型，用于描述组件边框圆角半径。

引用该对象时，至少传入一个参数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称          | 参数类型                         | 必填   | 描述       |
| ----------- | ---------------------------- | ---- | -------- |
| topStart     | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否    | 左上角圆角半径。<br />从右至左显示语言模式下为右上角圆角半径。 |
| topEnd       | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否    | 右上角圆角半径。<br />从右至左显示语言模式下为左上角圆角半径。 |
| bottomStart  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否    | 左下角圆角半径。<br />从右至左显示语言模式下为右下角圆角半径。 |
| bottomEnd    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否    | 右下角圆角半径。<br />从右至左显示语言模式下为左下角圆角半径。 |

## EdgeStyles<sup>9+</sup>对象说明

引入该对象时，至少传入一个参数。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称     | 参数类型                                     | 必填   | 描述      |
| ------ | ---------------------------------------- | ---- | ------- |
| left   | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否    | 左侧边框样式。 |
| right  | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否    | 右侧边框样式。 |
| top    | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否    | 上侧边框样式。 |
| bottom | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否    | 下侧边框样式。 |

## 示例

### 示例1（基本样式用法）

设置边框的宽度、颜色、圆角半径以及点、线样式。

```ts
// xxx.ets
@Entry
@Component
struct BorderExample {
  build() {
    Column() {
      Flex({ justifyContent: FlexAlign.SpaceAround, alignItems: ItemAlign.Center }) {
        // 线段
        Text('dashed')
          .borderStyle(BorderStyle.Dashed).borderWidth(5).borderColor(0xAFEEEE).borderRadius(10)
          .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
        // 点线
        Text('dotted')
          .border({ width: 5, color: 0x317AF7, radius: 10, style: BorderStyle.Dotted })
          .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
      }.width('100%').height(150)

      Text('.border')
        .fontSize(50)
        .width(300)
        .height(300)
        .border({
          width: { left: 3, right: 6, top: 10, bottom: 15 },
          color: { left: '#e3bbbb', right: Color.Blue, top: Color.Red, bottom: Color.Green },
          radius: { topLeft: 10, topRight: 20, bottomLeft: 40, bottomRight: 80 },
          style: {
            left: BorderStyle.Dotted,
            right: BorderStyle.Dotted,
            top: BorderStyle.Solid,
            bottom: BorderStyle.Dashed
          }
        }).textAlign(TextAlign.Center)
    }
  }
}
```

![zh-cn_image_0000001219982705](figures/zh-cn_image_0000001219982705.gif)

### 示例2（边框宽度类型和边框颜色）

border属性的width、radius、color属性值使用LocalizedEdgeWidths类型和LocalizedEdgeColors类型。

```ts
// xxx.ets
import { LengthMetrics } from '@kit.ArkUI';
@Entry
@Component
struct BorderExample {
  build() {
    Column() {
      Flex({ justifyContent: FlexAlign.SpaceAround, alignItems: ItemAlign.Center }) {
        // 线段
        Text('dashed')
          .borderStyle(BorderStyle.Dashed)
          .borderWidth(5)
          .borderColor(0xAFEEEE)
          .borderRadius(10)
          .width(120)
          .height(120)
          .textAlign(TextAlign.Center)
          .fontSize(16)
        // 点线
        Text('dotted')
          .border({ width: 5, color: 0x317AF7, radius: 10, style: BorderStyle.Dotted })
          .width(120)
          .height(120)
          .textAlign(TextAlign.Center)
          .fontSize(16)
      }.width('100%').height(150)

      Text('.border')
        .fontSize(50)
        .width(300)
        .height(300)
        .border({
          width: {
            start: LengthMetrics.vp(3),
            end: LengthMetrics.vp(6),
            top: LengthMetrics.vp(10),
            bottom: LengthMetrics.vp(15)
          },
          color: { start: '#e3bbbb', end: Color.Blue, top: Color.Red, bottom: Color.Green },
          radius: {
            topStart: LengthMetrics.vp(10),
            topEnd: LengthMetrics.vp(20),
            bottomStart: LengthMetrics.vp(40),
            bottomEnd: LengthMetrics.vp(80)
          },
          style: {
            left: BorderStyle.Dotted,
            right: BorderStyle.Dotted,
            top: BorderStyle.Solid,
            bottom: BorderStyle.Dashed
          }
        })
        .textAlign(TextAlign.Center)
    }
  }
}
```

从左至右显示语言示例图

![zh-cm_image_border_ltr](figures/zh-cn_image_border_ltr.png)

从右至左显示语言示例图

![zh-cm_image_border_rtl](figures/zh-cn_image_border_rtl.png)