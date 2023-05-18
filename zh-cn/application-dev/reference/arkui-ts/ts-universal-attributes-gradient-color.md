# 颜色渐变

设置组件的颜色渐变效果。

>  **说明：**
>
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性


| 名称              | 参数类型                                         | 描述                               |
| -------------- | -------------------------------------------- | ----------------------------------- |
| linearGradient | {<br/>angle?:&nbsp;number \| string,<br/>direction?:&nbsp;[GradientDirection](ts-appendix-enums.md#gradientdirection),<br/>colors:&nbsp;Array&lt;[ColorStop](ts-basic-components-gauge.md#colorstop)&gt;,<br/>repeating?:&nbsp;boolean<br/>} | 线性渐变。<br/>- angle:&nbsp;线性渐变的起始角度。0点方向顺时针旋转为正向角度。<br/>  默认值：180<br/>- direction:&nbsp;线性渐变的方向，设置angle后不生效。<br/>  默认值：GradientDirection.Bottom <br/>- colors:&nbsp;渐变的颜色描述。<br/>- repeating:&nbsp;为渐变的颜色重复着色。 <br/>  默认值：false<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| sweepGradient  | {<br/>center:&nbsp;[Point](./ts-drawing-components-polygon.md#point),<br/>start?:&nbsp;number \| string,<br/>end?:&nbsp;number \| string,<br/>rotation?:&nbsp;number\|string,<br/>colors:&nbsp;Array&lt;[ColorStop](ts-basic-components-gauge.md#colorstop)&gt;,<br/>repeating?:&nbsp;boolean<br/>} | 角度渐变，仅绘制0-360度范围内的角度，超出时不绘制渐变色，只绘制纯色。<br/>- center：为角度渐变的中心点，即相对于当前组件左上角的坐标。<br/>- start：角度渐变的起点。<br/>&nbsp;默认值：0<br/>- end：角度渐变的终点。<br/>&nbsp;默认值：0<br/>- rotation:&nbsp;角度渐变的旋转角度。<br/>&nbsp;默认值：0<br/>- colors:&nbsp;为渐变的颜色描述。<br/>- repeating:&nbsp;为渐变的颜色重复着色。<br/>  默认值：false<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>设置为小于0的值时，按值为0处理，设置为大于360的值时，按值为360处理。<br/>当start、end、rotation的数据类型为string，值为"90"或"90%"，与90效果一致 |
| radialGradient | {<br/>center:&nbsp;[Point](./ts-drawing-components-polygon.md#point),<br/> radius:&nbsp;number \| string,<br/>colors:&nbsp;Array&lt;[ColorStop](ts-basic-components-gauge.md#colorstop)&gt;,<br/>repeating?:&nbsp;boolean<br/>} | 径向渐变。<br/>- center：径向渐变的中心点，即相对于当前组件左上角的坐标。<br/>- radius：径向渐变的半径。<br/>&nbsp;取值范围 [0,+∞)<br>&nbsp; **说明：** <br/>设置为小于的0值时，按值为0处理。<br/>- colors:&nbsp;为渐变的颜色描述。<br/>- repeating:&nbsp;为渐变的颜色重复着色。<br/>  默认值：false<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct ColorGradientExample {
  build() {
    Column({ space: 5 }) {
      Text('linearGradient').fontSize(12).width('90%').fontColor(0xCCCCCC)
      Row()
        .width('90%')
        .height(50)
        .linearGradient({
          angle: 90,
          colors: [[0xff0000, 0.0], [0x0000ff, 0.3], [0xffff00, 1.0]]
        })
      Text('linearGradient Repeat').fontSize(12).width('90%').fontColor(0xCCCCCC)
      Row()
        .width('90%')
        .height(50)
        .linearGradient({
          direction: GradientDirection.Left, // 渐变方向
          repeating: true, // 渐变颜色是否重复
          colors: [[0xff0000, 0.0], [0x0000ff, 0.3], [0xffff00, 0.5]] // 数组末尾元素占比小于1时满足重复着色效果
        })
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![zh-cn_image_0000001219864149](figures/gradientColor1.png)

```ts
@Entry
@Component
struct ColorGradientExample {
  build() {
    Column({ space: 5 }) {
      Text('sweepGradient').fontSize(12).width('90%').fontColor(0xCCCCCC)
      Row()
        .width(100)
        .height(100)
        .sweepGradient({
          center: [50, 50],
          start: 0,
          end: 359,
          colors: [[0xff0000, 0.0], [0x0000ff, 0.3], [0xffff00, 1.0]]
        })
      
      Text('sweepGradient Reapeat').fontSize(12).width('90%').fontColor(0xCCCCCC)
      Row()
        .width(100)
        .height(100)
        .sweepGradient({
          center: [50, 50],
          start: 0,
          end: 359,
          rotation: 45, // 旋转角度
          repeating: true, // 渐变颜色是否重复
          colors: [[0xff0000, 0.0], [0x0000ff, 0.3], [0xffff00, 0.5]] // 数组末尾元素占比小于1时满足重复着色效果
        })
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![zh-cn_image_0000001219864149](figures/gradientColor2.png)

```ts
// xxx.ets
@Entry
@Component
struct ColorGradientExample {
  build() {
    Column({ space: 5 }) {
      Text('radialGradient').fontSize(12).width('90%').fontColor(0xCCCCCC)
      Row()
        .width(100)
        .height(100)
        .radialGradient({
          center: [50, 50],
          radius: 60,
          colors: [[0xff0000, 0.0], [0x0000ff, 0.3], [0xffff00, 1.0]]
        })
      Text('radialGradient Repeat').fontSize(12).width('90%').fontColor(0xCCCCCC)
      Row()
        .width(100)
        .height(100)
        .radialGradient({
          center: [50, 50],
          radius: 60,
          repeating: true,
          colors: [[0xff0000, 0.0], [0x0000ff, 0.3], [0xffff00, 0.5]] // 数组末尾元素占比小于1时满足重复着色效果
        })
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![zh-cn_image_0000001219864149](figures/gradientColor3.png)
