# 显式动画立即下发（animateToImmediately）

animateToImmediately接口用来提供[显式动画](ts-explicit-animation.md)立即下发功能。同时加载多个属性动画的情况下，使用该接口可以立即执行闭包代码中状态变化导致的过渡动效。

**系统API**：该接口为系统接口，三方应用不支持调用。

>  **说明：**
>
>  从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

animateToImmediately(value: AnimateParam, event: () => void): void

| 参数    | 类型                                | 是否必填 | 描述                                    |
| ----- | --------------------------------- | ---- | ------------------------------------- |
| value | [AnimateParam](ts-explicit-animation#animateparam对象说明) | 是    | 设置动画效果相关参数。                           |
| event | () => void                        | 是    | 指定显示动效的闭包函数，在闭包函数中导致的状态变化系统会自动插入过渡动画。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct AnimateToImmediatelyExample {
  @State widthSize: number = 250
  @State heightSize: number = 100
  @State opacitySize: number = 0
  private flag: boolean = true

  build() {
    Column() {
      Column()
      .width(this.widthSize)
      .height(this.heightSize)
      .backgroundColor(Color.Green)
      .opacity(this.opacitySize)
      Button('change size')
        .margin(30)
        .onClick(() => {
          if (this.flag) {
            animateToImmediately({
              delay: 0,
              duration: 1000
            }, () => {
              this.opacitySize = 1
            })
            animateTo({
              delay: 1000,
              duration: 1000
            }, () => {
              this.widthSize = 150
              this.heightSize = 60
            })
          } else {
            animateToImmediately({
              delay: 0,
              duration: 1000
            }, () => {
              this.widthSize = 250
              this.heightSize = 100
            })
            animateTo({
              delay: 1000,
              duration: 1000
            }, () => {
              this.opacitySize = 0
            })
          }
          this.flag = !this.flag
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

![animation1](figures/animateToImmediately1.gif)
