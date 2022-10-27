# 属性动画

组件的某些通用属性变化时，可以通过属性动画实现渐变过渡效果，提升用户体验。支持的属性包括width、height、backgroundColor、opacity、scale、rotate、translate等。

> **说明：**
>
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


animation(value: {duration?: number, tempo?: number, curve?: string | Curve | ICurve, delay?:number, iterations: number, playMode?: PlayMode, onFinish?: () => void})

**参数：**

| 名称         | 参数类型                                       | 必填    | 描述                                                         |
| ---------- | ------------------------------------------| ---- | ------------------------------------------------------------ |
| duration   | number                                    | 否    | 设置动画时长。单位为毫秒，默认动画时长为1000毫秒。<br/>默认值：1000 |
| tempo      | number                                    | 否    | 动画播放速度。数值越大，动画播放速度越快，数值越小，播放速度越慢<br/>值为0时，表示不存在动画。<br/>默认值：1 |
| curve      | string&nbsp;\|&nbsp;[Curve](ts-appendix-enums.md#curve)&nbsp;\|&nbsp;ICurve<sup>9+</sup> | 否   | 设置动画曲线。默认曲线为线性。<br/>默认值：Curve.Linear   |
| delay      | number                                    | 否    | 设置动画延迟执行的时长。单位为毫秒，默认不延时播放。<br/>默认值：0   |
| iterations | number                                    | 否    | 设置播放次数。默认播放一次，设置为-1时表示无限次播放。<br/>默认值：1 |
| playMode   | [PlayMode](ts-appendix-enums.md#playmode) | 否    | 设置动画播放模式，默认播放完成后重头开始播放。<br/>默认值：PlayMode.Normal |
| onFinish   | () => void                                | 否    | 状态回调，动画播放完成时触发。                        |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct AttrAnimationExample {
  @State widthSize: number = 250
  @State heightSize: number = 100
  @State changeColor: number = 0xFF0000FF
  @State rotateAngle: number = 0
  @State flagA: boolean = true
  @State flagB: boolean = true
  @State flagC: boolean = true

  build() {
    Column() {
      Button('change width and height')
        .onClick(() => {
          if (this.flagA) {
            this.widthSize = 100
            this.heightSize = 50
          } else {
            this.widthSize = 250
            this.heightSize = 100
          }
          this.flagA = !this.flagA
        })
        .margin(30)
        .width(this.widthSize)
        .height(this.heightSize)
        .animation({
          duration: 2000,
          curve: Curve.EaseOut,
          delay: 500,
          iterations: 1,
          playMode: PlayMode.Normal
        })
      Button('change backgroundColor')
        .onClick(() => {
          if (this.flagB) {
            this.changeColor = 0xFFFF4500
          } else {
            this.changeColor = 0xFF0000FF
          }
          this.flagB = !this.flagB
        })
        .margin(30)
        .backgroundColor(this.changeColor)
        .animation({
          duration: 800,
          curve: Curve.ExtremeDeceleration,
          iterations: 3,
          playMode: PlayMode.Normal
        })
      Button('change rotate angle')
        .onClick(() => {
          if (this.flagC) {
            this.rotateAngle = 90
          } else {
            this.rotateAngle = 0
          }
          this.flagC = !this.flagC
        })
        .margin(30)
        .rotate({ angle: this.rotateAngle })
        .animation({
          duration: 1200,
          curve: Curve.Friction,
          delay: 500,
          iterations: 10,
          playMode: PlayMode.AlternateReverse
        })
    }.width('100%').margin({ top: 20 })
  }
}
```
