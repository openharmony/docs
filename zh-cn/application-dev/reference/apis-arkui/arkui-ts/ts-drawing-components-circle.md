# Circle
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @camlostshi-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

 用于绘制圆形的组件。 

>  **说明：**
>
>  该组件从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 子组件

无

## 接口

### Circle

new Circle(value?: CircleOptions)

用于绘制圆形的构造函数。调用后创建一个Circle对象，可设置宽高属性。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | [CircleOptions](#circleoptions对象说明) | 否 | 设置圆形尺寸。当需要自定义圆形大小时传入此参数，不传入时width和height默认为0。<br>异常值undefined和null按照无效值处理，本次设置不生效。 |

### Circle

Circle(value?: CircleOptions)

用于绘制圆形的构造函数。调用后创建一个Circle对象，可设置宽高属性。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | [CircleOptions](#circleoptions对象说明) | 否 | 设置圆形尺寸。当需要自定义圆形大小时传入此参数，不传入时width和height默认为0。<br>异常值undefined和null按照无效值处理，本次设置不生效。 |

## CircleOptions对象说明

用于描述Circle组件绘制属性。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| width | [Length](ts-types.md#length) | 否 | 是 | 宽度，取值范围≥0。当需要自定义圆形大小时设置此属性，不传入时默认为0。<br>默认单位：vp<br>异常值undefined、null、NaN和Infinity按照默认值处理。 |
| height | [Length](ts-types.md#length) | 否 | 是 | 高度，取值范围≥0。当需要自定义圆形大小时设置此属性，不传入时默认为0。<br>默认单位：vp<br>异常值undefined、null、NaN和Infinity按照默认值处理。 |

## 属性

除支持[通用属性](ts-component-general-attributes.md)以及[图形绘制通用属性](ts-drawing-components-common.md)外，还支持以下属性：

### stroke

stroke(value: ResourceColor | ColorMetrics)

设置边框颜色，支持使用[ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)描述颜色，可进行HDR提亮。支持[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)动态设置属性。不设置时，默认边框颜色为[Color](ts-appendix-enums.md#color).Transparent，即没有边框。异常值undefined和null按照默认值处理，NaN和Infinity按照[Color](ts-appendix-enums.md#color).Black处理。

**起始版本：** 26.0.0

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| value  | [ResourceColor](ts-types.md#resourcecolor) \| [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | 是   | 边框颜色。<br>默认值：[Color](ts-appendix-enums.md#color).Transparent<br>异常值undefined和null按照默认值处理，NaN和Infinity按照[Color](ts-appendix-enums.md#color).Black处理。 |

### fill

fill(value: ResourceColor | ColorMetrics)

设置填充区域的颜色，支持使用[ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)描述颜色，可进行HDR提亮。支持[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)动态设置属性。不设置时，默认填充颜色为[Color](ts-appendix-enums.md#color).Black。异常值undefined、null、NaN和Infinity按照默认值处理。与通用属性foregroundColor同时设置时，后设置的属性生效。

**起始版本：** 26.0.0

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| value  | [ResourceColor](ts-types.md#resourcecolor) \| [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | 是   | 填充区域颜色。<br>默认值：[Color](ts-appendix-enums.md#color).Black <br>异常值undefined、null、NaN和Infinity按照默认值处理。 |

## 示例

### 示例1（组件属性绘制）

通过fillOpacity、stroke、strokeDashArray属性可分别设置圆的透明度、边框颜色和边框间隙样式。

```ts
// xxx.ets
@Entry
@Component
struct CircleExample {
  build() {
    Column({ space: 10 }) {
      // 绘制一个直径为150的圆
      Circle({ width: 150, height: 150 })
      // 绘制一个直径为150、线条为红色虚线的圆环（宽高设置不一致时以短边为直径）
      Circle()
        .width(150)
        .height(200)
        .fillOpacity(0)
        .strokeWidth(3)
        .stroke(Color.Red)
        .strokeDashArray([1, 2])
    }.width('100%')
  }
}
```

![circle1](figures/circle1.png)

### 示例2（宽和高使用不同参数类型绘制圆）

width、height属性分别使用不同的长度类型绘制圆。

```ts
// xxx.ets
@Entry
@Component
struct CircleTypeExample {
  build() {
    Column({ space: 10 }) {
      // 绘制一个直径为50的圆
      Circle({ width: '50', height: '50' }) // 使用string类型
      // 绘制一个直径为100的圆
      Circle({ width: 100, height: 100 }) // 使用number类型
      // 绘制一个直径为150的圆
      Circle({ width: $r('app.string.CircleWidth'), height: $r('app.string.CircleHeight') }) // 使用Resource类型，需用户自定义
    }.width('100%')
  }
}
```

![circleDemo2](figures/circleDemo2.png)

### 示例3（使用attributeModifier动态设置Circle组件的属性）

以下示例展示了如何使用attributeModifier动态设置Circle组件的fill、fillOpacity、stroke、strokeDashArray、strokeDashOffset、strokeLineCap、strokeOpacity、strokeWidth和antiAlias属性。

```ts
// xxx.ets
class MyCircleModifier implements AttributeModifier<CircleAttribute> {
  applyNormalAttribute(instance: CircleAttribute): void {
    // 填充颜色#707070，填充透明度0.5，边框颜色#2787D9，虚线样式[20]，起点偏移量15，端点样式为圆头，边框透明度0.5，边框宽度10，抗锯齿开启
    instance.fill("#707070")
    instance.fillOpacity(0.5)
    instance.stroke("#2787D9")
    instance.strokeDashArray([20])
    instance.strokeDashOffset("15")
    instance.strokeLineCap(LineCapStyle.Round)
    instance.strokeOpacity(0.5)
    instance.strokeWidth(10)
    instance.antiAlias(true)
  }
}

@Entry
@Component
struct CircleModifierDemo {
  @State modifier: MyCircleModifier = new MyCircleModifier()

  build() {
    Column() {
      Circle({ width: 150, height: 150 })
        .attributeModifier(this.modifier)
        .offset({ x: 20, y: 20 })
    }
  }
}
```

![](figures/circleModifier.png)

### 示例4（使用ColorMetrics设置HDR填充和边框颜色）

通过[ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)可为Circle组件设置HDR颜色，实现超出普通显示范围的亮度效果。其中，[fill](#fill)接口用于设置填充区域的颜色，[stroke](#stroke)接口用于设置边框颜色。以下示例左侧使用HDR暖金色填充和冰蓝色边框（亮度倍数大于1.0），右侧使用普通SDR颜色作为对照。在支持HDR的屏幕上可观察到左侧明显比右侧更亮且色彩更鲜艳。

从API版本26.0.0开始，新增Circle组件专有的[fill](#fill)和[stroke](#stroke)接口，支持传入[ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)类型以实现HDR提亮效果。

```ts
// xxx.ets
import { ColorMetrics } from '@kit.ArkUI';

@Entry
@Component
struct CircleHDRDemo {
  build() {
    Column({ space: 30 }) {
      Row({ space: 60 }) {
        // HDR填充和边框：颜色分量值可以超过1.0，超过1.0的部分用于表现超出普通屏幕亮度范围的高亮效果
        Column({ space: 8 }) {
          Circle()
            .width(120).height(120).strokeWidth(6)
            .fill(ColorMetrics.createHDRColor(ColorSpace.BT2020, 2.5, 1.2, 0.0, 1)) // 高亮暖金
            .stroke(ColorMetrics.createHDRColor(ColorSpace.BT2020, 0.0, 0.8, 2.5, 1)) // 高亮冰蓝
          Text('HDR').fontColor(Color.White).fontSize(14)
        }

        // SDR填充和边框：颜色分量值的范围为0.0到1.0，是常规标准动态范围的颜色显示方式
        Column({ space: 8 }) {
          Circle()
            .width(120).height(120).strokeWidth(6)
            .fill('#ffc800') // 普通金黄
            .stroke('#0066ff') // 普通深蓝
          Text('SDR').fontColor(Color.White).fontSize(14)
        }
      }
    }
    .width('100%').height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

![circleHdr](figures/circleHdr.png)
