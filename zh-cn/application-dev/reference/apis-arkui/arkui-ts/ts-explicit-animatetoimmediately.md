# 显式动画立即下发 (animateToImmediately)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--SE: @yangfan229-->
<!--TSE: @lxl007-->

animateToImmediately接口用来提供[显式动画](ts-explicit-animation.md)立即下发功能。同时加载多个属性动画的情况下，使用该接口可以立即执行闭包代码中状态变化导致的过渡动效。

与[animateTo](../arkts-apis-uicontext-uicontext.md#animateto)相比，animateToImmediately能即时将生成的动画指令发送至渲染层执行，无需等待vsync信号，从而在视觉效果上实现部分动画的优先呈现。当应用的主线程存在耗时操作，且需提前更新部分用户界面时，此接口可有效缩短应用的响应延迟。值得注意的是，animateToImmediately仅支持渲染层上的属性动画提前执行，而无法使UI侧的逐帧属性动画提前。

此外，animateToImmediately会将调用前的状态与animateToImmediately产生的动画一并发送至渲染层，这意味着渲染可能依据调用时的状态进行。因此，务必确保调用时的状态完整无缺，能够支持当前状态下的渲染，否则动画初始阶段可能因部分状态设置不当，导致前几帧显示异常。

通常情况下，不建议开发者采用animateToImmediately接口，而应选择[animateTo](../arkts-apis-uicontext-uicontext.md#animateto)，以防止干扰框架的显示时序，避免在动画启动时因状态设置不完整而导致的显示错误。

> **说明：**
>
> 从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>

## 接口

## animateToImmediately

animateToImmediately(value: AnimateParam , event: () => void): void

提供显式动画立即下发功能。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| value  | [AnimateParam](ts-explicit-animation.md#animateparam对象说明) | 是       | 设置动画效果相关参数。                                       |
| event  | () => void                                                   | 是       | 指定显示动效的闭包函数，在闭包函数中导致的状态变化系统会自动插入过渡动画。 |

## 示例

该示例主要演示通过animateToImmediately接口来实现显式动画立即下发。

```ts
// xxx.ets
@Entry
@Component
struct AnimateToImmediatelyExample {
  @State widthSize: number = 250;
  @State heightSize: number = 100;
  @State opacitySize: number = 0;
  private flag: boolean = true;

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
              this.opacitySize = 1;
            })
            this.getUIContext()?.animateTo({
              delay: 1000,
              duration: 1000
            }, () => {
              this.widthSize = 150;
              this.heightSize = 60;
            })
          } else {
            animateToImmediately({
              delay: 0,
              duration: 1000
            }, () => {
              this.widthSize = 250;
              this.heightSize = 100;
            })
            this.getUIContext()?.animateTo({
              delay: 1000,
              duration: 1000
            }, () => {
              this.opacitySize = 0;
            })
          }
          this.flag = !this.flag;
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

![animation1](figures/animateToImmediately1.gif)
