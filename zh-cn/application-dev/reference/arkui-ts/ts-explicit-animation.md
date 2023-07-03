# 显式动画

提供全局animateTo显式动画接口来指定由于闭包代码导致的状态变化插入过渡动效。

>  **说明：**
>
>  从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 本模块功能依赖UI的执行上下文，不可在UI上下文不明确的地方使用，参见[UIContext](../apis/js-apis-arkui-UIContext.md#uicontext)说明。
>
> 从API version 10开始，可以通过使用[UIContext](../apis/js-apis-arkui-UIContext.md#uicontext)中的[animateTo](../apis/js-apis-arkui-UIContext.md#animateto)来明确UI的执行上下文。

animateTo(value: AnimateParam, event: () => void): void

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 参数             | 类型        |       是否必填     |        描述        |
| ---------------- | ------------ | -------------------- | -------------------- |
| value | [AnimateParam](#animateparam对象说明) | 是 | 设置动画效果相关参数。 |
| event | () => void | 是 | 指定显示动效的闭包函数，在闭包函数中导致的状态变化系统会自动插入过渡动画。 |

## AnimateParam对象说明

| 名称 | 类型 | 描述 |
| -------- | -------- | -------- |
| duration | number | 动画持续时间，单位为毫秒。<br/>默认值：1000<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>- 在ArkTS卡片上最大动画持续时间为1000毫秒，若超出则固定为1000毫秒。<br/>-&nbsp;设置小于0的值时按0处理。<br/>-&nbsp;设置浮点型类型的值时，向下取整。例如，设置值为1.2，按照1处理。 |
| tempo | number | 动画的播放速度，值越大动画播放越快，值越小播放越慢，为0时无动画效果。<br/>默认值：1.0<br/>**说明：** <br/>当设置小于0的值时按值为1处理。 |
| curve | [Curve](ts-appendix-enums.md#curve)&nbsp;\|&nbsp;[ICurve](../apis/js-apis-curve.md#icurve)&nbsp;\|&nbsp;string | 动画曲线。<br/>默认值：Curve.Linear<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| delay | number | 单位为ms(毫秒)，默认不延时播放。<br/>默认值：0<br/>**说明：** <br/>-&nbsp;当设置的值小于0时按0处理。<br/>-&nbsp;设置浮点型类型的值时，向下取整。例如，设置值为1.2，按照1处理。 |
| iterations | number | 默认播放一次，设置为-1时表示无限次播放。<br/>默认值：1 |
| playMode | [PlayMode](ts-appendix-enums.md#playmode) | 设置动画播放模式，默认播放完成后重头开始播放。<br/>默认值：PlayMode.Normal<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>相关使用约束请参考PlayMode说明。 |
| onFinish   | ()&nbsp;=&gt;&nbsp;void   | 动效播放完成回调。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |

> **PlayMode说明：**
> - PlayMode推荐使用PlayMode.Normal和PlayMode.Alternate，此场景下动画的第一轮是正向播放的。如使用PlayMode.Reverse和PlayMode.AlternateReverse，则动画的第一轮是逆向播放的，在动画刚开始时会跳变到终止状态，然后逆向播放动画。
> - 使用PlayMode.Alternate或PlayMode.AlternateReverse时，开发者应保证动画最终状态和状态变量的取值一致，即应保证动画的最后一轮是正向播放的。使用PlayMode.Alternate时，iterations应为奇数。使用PlayMode.AlternateReverse时，iterations应为偶数。
> - 不推荐使用PlayMode.Reverse，此场景下不仅会导致动画刚开始就跳变到终止状态，也会导致动画最终状态和状态变量的取值不同。

## 示例

```ts
// xxx.ets
@Entry
@Component
struct AnimateToExample {
  @State widthSize: number = 250
  @State heightSize: number = 100
  @State rotateAngle: number = 0
  private flag: boolean = true

  build() {
    Column() {
      Button('change size')
        .width(this.widthSize)
        .height(this.heightSize)
        .margin(30)
        .onClick(() => {
          if (this.flag) {
            animateTo({
              duration: 2000,
              curve: Curve.EaseOut,
              iterations: 3,
              playMode: PlayMode.Normal,
              onFinish: () => {
                console.info('play end')
              }
            }, () => {
              this.widthSize = 150
              this.heightSize = 60
            })
          } else {
            animateTo({}, () => {
              this.widthSize = 250
              this.heightSize = 100
            })
          }
          this.flag = !this.flag
        })
      Button('change rotate angle')
        .margin(50)
        .rotate({ x: 0, y: 0, z: 1, angle: this.rotateAngle })
        .onClick(() => {
          animateTo({
            duration: 1200,
            curve: Curve.Friction,
            delay: 500,
            iterations: -1, // 设置-1表示动画无限循环
            playMode: PlayMode.Alternate,
            onFinish: () => {
              console.info('play end')
            }
          }, () => {
            this.rotateAngle = 90
          })
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

![animation1](figures/animation1.gif)
