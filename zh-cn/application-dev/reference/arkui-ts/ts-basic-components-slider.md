# Slider

滑动条组件，通常用于快速调节设置值，如音量调节、亮度调节等应用场景。

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

无


## 接口

Slider(options?: {value?: number, min?: number, max?: number, step?: number, style?: SliderStyle, direction?: Axis, reverse?: boolean})

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| value | number | 否 | 当前进度值。<br/>默认值：0 |
| min | number | 否 | 设置最小值。<br/>默认值：0 |
| max | number | 否 | 设置最大值。<br/>默认值：100 |
| step | number | 否 | 设置Slider滑动步长。<br/>默认值：1 |
| style | SliderStyle | 否 | 设置Slider的滑块与滑轨显示样式。<br/>默认值：SliderStyle.OutSet |
| direction<sup>8+</sup> | [Axis](ts-appendix-enums.md#axis) | 否 | 设置滑动条滑动方向为水平或竖直方向。<br/>默认值：Axis.Horizontal |
| reverse<sup>8+</sup> | boolean | 否 | 设置滑动条取值范围是否反向，横向Slider默认为从左往右滑动，竖向Slider默认为从上往下滑动。<br/>默认值：false |

## SliderStyle枚举说明

| 名称 | 描述 |
| -------- | -------- |
| OutSet | 滑块在滑轨上。 |
| InSet | 滑块在滑轨内。 |


## 属性

支持除触摸热区以外的通用属性设置。

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| blockColor | [ResourceColor](ts-types.md#resourcecolor) | 设置滑块的颜色。 |
| trackColor | [ResourceColor](ts-types.md#resourcecolor) | 设置滑轨的背景颜色。 |
| selectedColor | [ResourceColor](ts-types.md#resourcecolor) | 设置滑轨的已滑动部分颜色。 |
| showSteps | boolean | 设置当前是否显示步长刻度值。<br/>默认值：false |
| showTips | boolean | 设置滑动时是否显示百分比气泡提示。<br/>默认值：false |
| trackThickness      | [Length](ts-types.md#length) | 设置滑轨的粗细。 |


## 事件

通用事件仅支持挂载卸载事件：OnAppear，OnDisAppear。

| 名称 | 功能描述 |
| -------- | -------- |
| onChange(callback:&nbsp;(value:&nbsp;number,&nbsp;mode:&nbsp;SliderChangeMode)&nbsp;=&gt;&nbsp;void) | Slider滑动时触发事件回调。<br/>value：当前滑动进度值。若返回值有小数，可使用Math.toFixed()方法将数据处理为预期的精度。<br/>mode：拖动状态。 |

## SliderChangeMode枚举说明

| 名称 | 值 | 描述 |
| -------- | -------- | -------- |
| Begin | 0 | 开始拖动滑块。 |
| Moving | 1 | 正在拖动滑块过程中。 |
| End | 2 | 结束拖动滑块。 |
| Click    | 3    | 点击滑动条使滑块位置移动。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct SliderExample {
  @State outSetValueOne: number = 40
  @State inSetValueOne: number = 40
  @State outSetValueTwo: number = 40
  @State inSetValueTwo: number = 40
  @State vOutSetValueOne: number = 40
  @State vInSetValueOne: number = 40
  @State vOutSetValueTwo: number = 40
  @State vInSetValueTwo: number = 40

  build() {
    Column({ space: 8 }) {
      Text('outset slider').fontSize(9).fontColor(0xCCCCCC).width('90%').margin(15)
      Row() {
        Slider({
          value: this.outSetValueOne,
          min: 0,
          max: 100,
          style: SliderStyle.OutSet
        })
          .showTips(true)
          .onChange((value: number, mode: SliderChangeMode) => {
            this.outSetValueOne = value
            console.info('value:' + value + 'mode:' + mode.toString())
          })
        // toFixed(0)将滑动条返回值处理为整数精度
        Text(this.outSetValueOne.toFixed(0)).fontSize(12)
      }
      .width('80%')
      Row() {
        Slider({
          value: this.outSetValueTwo,
          step: 10,
          style: SliderStyle.OutSet
        })
          .showSteps(true)
          .onChange((value: number, mode: SliderChangeMode) => {
            this.outSetValueTwo = value
            console.info('value:' + value + 'mode:' + mode.toString())
          })
        Text(this.outSetValueTwo.toFixed(0)).fontSize(12)
      }
      .width('80%')

      Text('inset slider').fontSize(9).fontColor(0xCCCCCC).width('90%').margin(15)
      Row() {
        Slider({
          value: this.inSetValueOne,
          min: 0,
          max: 100,
          style: SliderStyle.InSet
        })
          .blockColor('#191970')
          .trackColor('#ADD8E6')
          .selectedColor('#4169E1')
          .showTips(true)
          .onChange((value: number, mode: SliderChangeMode) => {
            this.inSetValueOne = value
            console.info('value:' + value + 'mode:' + mode.toString())
          })
        Text(this.inSetValueOne.toFixed(0)).fontSize(12)
      }
      .width('80%')
      Row() {
        Slider({
          value: this.inSetValueTwo,
          step: 10,
          style: SliderStyle.InSet
        })
          .blockColor('#191970')
          .trackColor('#ADD8E6')
          .selectedColor('#4169E1')
          .showSteps(true)
          .onChange((value: number, mode: SliderChangeMode) => {
            this.inSetValueTwo = value
            console.info('value:' + value + 'mode:' + mode.toString())
          })
        Text(this.inSetValueTwo.toFixed(0)).fontSize(12)
      }
      .width('80%')

      Row() {
        Column() {
          Text('vertical outset slider').fontSize(9).fontColor(0xCCCCCC).width('50%').margin(15)
          Row() {
            Slider({
              value: this.vOutSetValueOne,
              style: SliderStyle.OutSet,
              direction: Axis.Vertical
            })
              .blockColor('#191970')
              .trackColor('#ADD8E6')
              .selectedColor('#4169E1')
              .showTips(true)
              .onChange((value: number, mode: SliderChangeMode) => {
                this.vOutSetValueOne = value
                console.info('value:' + value + 'mode:' + mode.toString())
              })
            Slider({
              value: this.vOutSetValueTwo,
              step: 10,
              style: SliderStyle.OutSet,
              direction: Axis.Vertical
            })
              .blockColor('#191970')
              .trackColor('#ADD8E6')
              .selectedColor('#4169E1')
              .showSteps(true)
              .onChange((value: number, mode: SliderChangeMode) => {
                this.vOutSetValueTwo = value
                console.info('value:' + value + 'mode:' + mode.toString())
              })
          }
        }.width('50%').height(300)

        Column() {
          Text('vertical inset slider').fontSize(9).fontColor(0xCCCCCC).width('50%').margin(15)
          Row() {
            Slider({
              value: this.vInSetValueOne,
              style: SliderStyle.InSet,
              direction: Axis.Vertical,
              reverse: true // 竖向的Slider默认是上端是min值，下端是max值，因此想要从下往上滑动，需要设置reverse为true
            })
              .showTips(true)
              .onChange((value: number, mode: SliderChangeMode) => {
                this.vInSetValueOne = value
                console.info('value:' + value + 'mode:' + mode.toString())
              })
            Slider({
              value: this.vInSetValueTwo,
              step: 10,
              style: SliderStyle.InSet,
              direction: Axis.Vertical,
              reverse: true
            })
              .showSteps(true)
              .onChange((value: number, mode: SliderChangeMode) => {
                this.vInSetValueTwo = value
                console.info('value:' + value + 'mode:' + mode.toString())
              })
          }
        }.width('50%').height(300)
      }
    }.width('100%')
  }
}
```

![zh-cn_image_0000001179613854](figures/zh-cn_image_0000001179613854.gif)
