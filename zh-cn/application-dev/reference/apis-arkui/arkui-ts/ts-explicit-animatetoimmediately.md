# 显式动画立即下发 (animateToImmediately)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

animateToImmediately接口提供[显式动画](ts-explicit-animation.md)立即下发功能。典型应用场景包括：页面切换时优先展示关键过渡效果、主线程耗时期间提前刷新可见区域UI等。同时加载多个属性动画的情况下，使用该接口可以立即执行闭包代码中状态变化导致的过渡动效。

与[animateTo](../arkts-apis-uicontext-uicontext.md#animateto)相比，animateTo需等待vsync信号后下发动画指令，而animateToImmediately能即时将生成的动画指令发送至渲染层执行，无需等待vsync信号，从而在视觉效果上实现闭包内涉及的动画属性的优先呈现。当应用的主线程存在耗时操作，且需提前更新闭包内涉及的用户界面时，此接口可有效缩短应用的响应延迟。需要注意的是，animateToImmediately仅支持渲染层上的属性动画提前执行，无法用于UI侧的逐帧动画。

此外，该接口会将调用animateToImmediately前的UI状态和新生成的动画一并发送至渲染层，因此渲染结果可能会基于调用animateToImmediately时的UI状态进行。务必确保调用时所有涉及动画的属性值已正确设置，否则动画开始的少量帧可能出现渲染异常。

因此，建议开发者优先使用[animateTo](../arkts-apis-uicontext-uicontext.md#animateto)，仅在应用主线程存在耗时操作且需提前更新部分用户界面时使用animateToImmediately，以防止干扰框架的显示时序，避免在动画启动时因状态设置不完整而导致的显示错误。

> **说明：**
>
> - 从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## 接口

## animateToImmediately

animateToImmediately(value: AnimateParam, event: () => void): void

提供显式动画立即下发功能。该接口仅支持渲染层上的属性动画提前执行，无法用于UI侧的逐帧动画。建议开发者优先使用[animateTo](../arkts-apis-uicontext-uicontext.md#animateto)，以防止干扰框架的显示时序，避免在动画启动时因状态设置不完整而导致的显示错误。务必确保调用时所有涉及动画的属性值已正确设置，否则动画开始的少量帧可能出现渲染异常。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| value  | [AnimateParam](ts-explicit-animation.md#animateparam对象说明) | 是       | 设置动画效果相关参数，动画参数将作用于event闭包函数中状态变化产生的过渡动效。各属性的取值范围及含义详见[AnimateParam对象说明](ts-explicit-animation.md#animateparam对象说明)。animateToImmediately接口对AnimateParam各属性的使用与[animateTo](../arkts-apis-uicontext-uicontext.md#animateto)一致，但仅支持渲染层上的属性动画，无法用于UI侧的逐帧动画。 |
| event  | () => void                                                   | 是       | 指定显式动效的闭包函数，闭包中仅支持渲染层上的属性动画相关的状态变化，无法用于UI侧的逐帧动画。在闭包函数中导致的状态变化系统会自动插入过渡动画，动画效果由value参数控制。务必确保调用时所有涉及动画的属性值已正确设置，否则动画开始的少量帧可能出现渲染异常。 |

## 示例

该示例主要演示使用[animateToImmediately](#animatetoimmediately)接口实现显式动画立即下发。

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
          // 通过if/else分支对比演示：animateToImmediately立即下发动画与animateTo延迟下发动画的效果差异
          // flag切换演示场景：true时透明度立即下发、尺寸延迟下发；false时尺寸立即下发、透明度延迟下发
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
