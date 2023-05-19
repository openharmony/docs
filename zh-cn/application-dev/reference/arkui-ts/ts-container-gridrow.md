# GridRow

栅格容器组件，仅可以和栅格子组件([GridCol](ts-container-gridcol.md))在栅格布局场景中使用。

>  **说明：**
>
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

可以包含GridCol子组件。


## 接口
GridRow(option?: {columns?: number | GridRowColumnOption, gutter?: Length | GutterOption, breakpoints?: BreakPoints, direction?: GridRowDirection})

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数名 |类型|必填|说明|
|-----|-----|----|----|
|gutter|Length \| GutterOption|   否  |栅格布局间距，x代表水平方向。|
|columns| number \| GridRowColumnOption |  否  |设置布局列数。|
|breakpoints|BreakPoints|  否  |设置断点值的断点数列以及基于窗口或容器尺寸的相应参照。|
|direction|GridRowDirection|   否  |栅格布局排列方向。|

## GutterOption

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 参数名   | 参数类型   | 必填   | 参数描述                                     |
| ----- | ------ | ---- | ---------------------------------------- |
| x  | Length \| GridRowSizeOption | 否   | 水平gutter option。    |
| y  | Length \| GridRowSizeOption | 否   | 竖直gutter option。      |

## GridRowColumnOption

栅格在不同宽度设备类型下，栅格列数。

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 参数名   | 参数类型   | 必填   | 参数描述                                     |
| ----- | ------ | ---- | ---------------------------------------- |
| xs  | number | 否    | 最小宽度类型设备。    |
| sm  | number | 否    | 小宽度类型设备。      |
| md  | number | 否    | 中等宽度类型设备。    |
| lg  | number | 否    | 大宽度类型设备。      |
| xl  | number | 否    | 特大宽度类型设备。    |
| xxl | number | 否    | 超大宽度类型设备。    |

## GridRowSizeOption

栅格在不同宽度设备类型下，gutter的大小。

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 参数名   | 参数类型   | 必填   | 参数描述                                     |
| ----- | ------ | ---- | ---------------------------------------- |
| xs  | Length | 否    | 最小宽度类型设备。    |
| sm  | Length | 否    | 小宽度类型设备。      |
| md  | Length | 否    | 中等宽度类型设备。    |
| lg  | Length | 否    | 大宽度类型设备。      |
| xl  | Length | 否    | 特大宽度类型设备。    |
| xxl | Length | 否    | 超大宽度类型设备。    |

## BreakPoints

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 参数名   | 参数类型   | 必填   | 参数描述                                     |
| ----- | ------ | ---- | ---------------------------------------- |
| value  | Array&lt;string&gt; | 否  | 设置断点位置的单调递增数组。<br>默认值：["320vp", "600vp", "840vp"]    |
| reference  | BreakpointsReference | 否    | 断点切换参照物。 |
```ts
  // 启用xs、sm、md共3个断点
  breakpoints: {value: ["100vp", "200vp"]}
  // 启用xs、sm、md、lg共4个断点，断点范围值必须单调递增
  breakpoints: {value: ["320vp", "600vp", "840vp"]}
  // 启用xs、sm、md、lg、xl共5个断点，断点范围数量不可超过断点可取值数量-1
  breakpoints: {value: ["320vp", "600vp", "840vp", "1080vp"]}
```

## BreakpointsReference枚举类型

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 枚举名 | 描述 |
| -------- | -------- |
| WindowSize | 以窗口为参照。 |
| ComponentSize | 以容器为参照。 |

## GridRowDirection枚举类型

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 枚举名 | 描述 |
| -------- | -------- |
| Row | 栅格元素按照行方向排列。 |
| RowReverse | 栅格元素按照逆序行方向排列。 |

栅格最多支持xs、sm、md、lg、xl、xxl六个断点，且名称不可修改。假设传入的数组是[n0, n1, n2, n3, n4]，各个断点取值如下：  

|断点|取值范围|
|---|-----------|
|xs |[0, n0)    |
|sm |[n0, n1)   |
|md |[n1, n2)   |
|lg |[n2, n3)   |
|xl |[n3, n4)   |
|xxl|[n4, INF)  |

**说明：**
* 栅格元素仅支持Row/RowReverse排列，不支持column/ColumnReverse方向排列。
* 栅格子组件仅能通过span、offset计算子组件位置与大小。多个子组件span超过规定列数时自动换行。
* 单个元素span大小超过最大列数时后台默认span为最大column数。
* 新一行的Offset加上子组件的span超过总列数时，将下一个子组件在新的一行放置。
* 例：Item1: GridCol({ span: 6})， Item2: GridCol({ span: 8, offset:11})  

|1      | 2     | 3     | 4     | 5     | 6     | 7     | 8     | 9     | 10    | 11    | 12    |
| ----- | ------ | ---- | ---- | -----|-----|---------|--------|------|------- |------- |------- |
| $\circ$ | $\circ$ | $\circ$ | $\circ$ | $\circ$|$\circ$| - |  - |  - |  -  | -  | -  |
| -     | -     | -     | -     | -     |       |       |       |       |       |   |   |
| $\circ$ | $\circ$ | $\circ$ | $\circ$ | $\circ$|$\circ$|$\circ$|$\circ$|  |   |   |   |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称                       | 参数类型                            | 描述                                               |
| ----------------------- | ----------------------------------- | ------------------------------------------- |
| alignItems<sup>10+</sup>             | ItemAlign | 设置GridRow中的GridCol垂直主轴方向对齐方式，默认值：ItemAlign.Start<br/>**说明**：<br/>ItemAlign支持的枚举：ItemAlign.Start、ItemAlign.Center、ItemAlign.End、ItemAlign.Stretch。<br/>GridCol本身也可通过alignSelf([ItemAlign](ts-appendix-enums.md#itemalign))设置自身对齐方式。当上述两种对齐方式都设置时，以GridCol自身设置为准。<br/>从API version 10开始，该接口支持在ArkTS卡片中使用。 |


## 事件

### onBreakpointChange

onBreakpointChange(callback: (breakpoints: string) => void)

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数名   | 参数类型   | 必填   | 说明   |
| ----- | ------ | ---- | ---------------------------------------- |
|breakpoints| string |是|断点发生变化时触发回调<br>取值为`"xs"`、`"sm"`、`"md"`、`"lg"`、`"xl"`、`"xxl"`。|

## 示例

```ts
// xxx.ets
@Entry
@Component
struct GridRowExample {
  @State bgColors: Color[] = [Color.Red, Color.Orange, Color.Yellow, Color.Green, Color.Pink, Color.Grey, Color.Blue, Color.Brown]
  @State currentBp: string = 'unknown'

  build() {
    Column() {
      GridRow({
        columns: 5,
        gutter: { x: 5, y: 10 },
        breakpoints: { value: ["400vp", "600vp", "800vp"],
          reference: BreakpointsReference.WindowSize },
        direction: GridRowDirection.Row
      }) {
        ForEach(this.bgColors, (color) => {
          GridCol({ span: { xs: 1, sm: 2, md: 3, lg: 4 } }) {
            Row().width("100%").height("20vp")
          }.borderColor(color).borderWidth(2)
        })
      }.width("100%").height("100%")
      .onBreakpointChange((breakpoint) => {
        this.currentBp = breakpoint
      })
    }.width('80%').margin({ left: 10, top: 5, bottom: 5 }).height(200)
    .border({ color: '#880606', width: 2 })
  }
}
```

![figures/gridrow.png](figures/gridrow.png)
