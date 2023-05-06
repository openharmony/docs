# Panel

可滑动面板，提供一种轻量的内容展示窗口，方便在不同尺寸中切换。

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

可以包含子组件。

>  **说明：**
>
>  子组件类型：系统组件和自定义组件，支持渲染控制类型（[if/else](../../quick-start/arkts-rendering-control-ifelse.md)、[ForEach](../../quick-start/arkts-rendering-control-foreach.md)和[LazyForEach](../../quick-start/arkts-rendering-control-lazyforeach.md)）。


## 接口

Panel(show: boolean)

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| show | boolean | 是 | 控制Panel显示或隐藏。<br/>**说明：** <br/>如果设置为false时，则不占位隐藏。[Visible.None](ts-universal-attributes-visibility.md)或者show之间有一个生效时，都会生效不占位隐藏。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| type | [PanelType](#paneltype枚举说明) | 设置可滑动面板的类型。<br/>默认值：PanelType.Foldable |
| mode | [PanelMode](#panelmode枚举说明) | 设置可滑动面板的初始状态。<br/>Minibar类型默认值：PanelMode.Mini；其余类型默认值：PanelMode.Half<br />从API version 10开始，该属性支持[$$](../../quick-start/arkts-two-way-sync.md)双向绑定变量。 |
| dragBar | boolean | 设置是否存在dragbar，true表示存在，false表示不存在。<br/>默认值：true |
| fullHeight | string&nbsp;\|&nbsp;number | 指定PanelMode.Full状态下的高度。<br/>默认值：当前组件主轴大小减去8vp空白区<br/>**说明：** <br/>不支持设置百分比。 |
| halfHeight | string&nbsp;\|&nbsp;number | 指定PanelMode.Half状态下的高度。<br/>默认值：当前组件主轴大小的一半。<br/>**说明：** <br/>不支持设置百分比。 |
| miniHeight | string&nbsp;\|&nbsp;number | 指定PanelMode.Mini状态下的高度。<br/>默认值：48<br/>单位：vp<br/>**说明：** <br/>不支持设置百分比。 |
| show | boolean | 当滑动面板弹出时调用。 |
| backgroundMask<sup>9+</sup>|[ResourceColor](ts-types.md#resourcecolor)|指定Panel的背景蒙层。|

## PanelType枚举说明

| 名称 | 描述 |
| -------- | -------- |
| Minibar | 提供minibar和类全屏展示切换效果。 |
| Foldable | 内容永久展示类，提供大（类全屏）、中（类半屏）、小三种尺寸展示切换效果。 |
| Temporary | 内容临时展示区，提供大（类全屏）、中（类半屏）两种尺寸展示切换效果。 |

## PanelMode枚举说明

| 名称 | 描述 |
| -------- | -------- |
| Mini | 类型为minibar和foldable时，为最小状态；类型为temporary，则不生效。 |
| Half | 类型为foldable和temporary时，为类半屏状态；类型为minibar，则不生效。 |
| Full | 类全屏状态。 |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称 | 功能描述 |
| -------- | -------- |
| onChange(event:&nbsp;(width:&nbsp;number,&nbsp;height:&nbsp;number,&nbsp;mode:&nbsp;PanelMode)&nbsp;=&gt;&nbsp;void) | 当可滑动面板发生状态变化时触发，&nbsp;返回的height值为内容区高度值，当dragbar属性为true时，panel本身的高度值为dragbar高度加上内容区高度。 |
| onHeightChange(callback: (value: number) => void)<sup>9+</sup> |当可滑动面板发生高度变化时触发，返回的height值为内容区高度值，默认返回值单位为px。当dragbar属性为true时，panel本身的高度值为dragbar高度加上内容区高度。因用户体验设计原因，panel最高只能滑到 fullHeight-8vp。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct PanelExample {
  @State show: boolean = false

  build() {
    Column() {
      Text('2021-09-30    Today Calendar: 1.afternoon......Click for details')
        .width('90%').height(50).borderRadius(10)
        .backgroundColor(0xFFFFFF).padding({ left: 20 })
        .onClick(() => {
          this.show = !this.show
        })
      Panel(this.show) { // 展示日程
        Column() {
          Text('Today Calendar')
          Divider()
          Text('1. afternoon 4:00 The project meeting')
        }
      }
      .type(PanelType.Foldable).mode(PanelMode.Half)
      .dragBar(true) // 默认开启
      .halfHeight(500) // 默认一半
      .onChange((width: number, height: number, mode: PanelMode) => {
        console.info(`width:${width},height:${height},mode:${mode}`)
      })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![zh-cn_image_0000001174422896](figures/zh-cn_image_0000001174422896.gif)
