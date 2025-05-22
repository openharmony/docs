# 请求动画绘制帧率

在应用开发中，[属性动画](../reference/apis-arkui/arkui-ts/ts-animatorproperty.md)和[显式动画](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md)能够使用可选参数[ExpectedFrameRateRange](../reference/apis-arkui/arkui-ts/ts-explicit-animation.md#expectedframeraterange11)，为不同的动画配置不同的期望绘制帧率。

## 请求属性动画的绘制帧率
定义文本组件的属性动画，请求绘制帧率为60，范例如下：

   ```ts
    Text()
     .animation({
        duration: 1200,
        iterations: 10,
        expectedFrameRateRange: { // 设置属性动画的帧率范围
          expected: 60, // 设置动画的期望帧率为60hz
          min: 0, // 设置帧率范围
          max: 120, // 设置帧率范围
        },
     })
   ```

## 请求显式动画的绘制帧率
定义按钮组件的显式动画，请求绘制帧率为30，范例如下：

   ```ts
   Button()
    .onClick(() => {
      // uiContext需通过getUIContext获取，具体可见下文完整示例
      this.uiContext?.animateTo({
        duration: 1200,
        iterations: 10,
        expectedFrameRateRange: { // 设置显式动画的帧率范围
          expected: 30, // 设置动画的期望帧率为30hz
          min: 0, // 设置帧率范围
          max: 120, // 设置帧率范围
        },
      }, () => {
      })
    })
   ```


## 完整示例

```ts
@Entry
@Component
struct AnimationToAnimationDemo {
  @State isAnimation: boolean = false;
  @State translateX1: number = -100;
  @State translateX2: number = -100;
  @State translateX3: number = -100;
  uiContext: UIContext | undefined = undefined;

  aboutToAppear() {
    this.uiContext = this.getUIContext();
    if (!this.uiContext) {
      console.warn('no uiContext');
      return;
    }
  }

  build() {
    Column() {
      Row() {
        Text('30')
          .fontWeight(FontWeight.Bold)
          .fontSize(16)
          .fontColor(Color.White)
          .textAlign(TextAlign.Center)
          .borderRadius(10)
          .backgroundColor(0xF56C6C)
          .width(80)
          .height(80)
          .translate({ x: this.translateX1 })
      }
      .height('20%')

      Row() {
        Text('40')
          .fontWeight(FontWeight.Bold)
          .fontSize(16)
          .fontColor(Color.White)
          .textAlign(TextAlign.Center)
          .borderRadius(10)
          .backgroundColor(0x2E8B57)
          .width(80)
          .height(80)
          .translate({ x: this.translateX2 })
      }
      .height('20%')

      Row() {
        Text('60')
          .fontWeight(FontWeight.Bold)
          .fontSize(16)
          .fontColor(Color.White)
          .textAlign(TextAlign.Center)
          .borderRadius(10)
          .backgroundColor(0x008B8B)
          .width(80)
          .height(80)
          .translate({ x: this.translateX3 })
          .animation({
            duration: 1200,
            iterations: 10,
            playMode: PlayMode.AlternateReverse,
            expectedFrameRateRange: { // 设置属性动画的帧率范围
              expected: 60, // 设置动画的期望帧率为60hz
              min: 0, // 设置帧率范围
              max: 120, // 设置帧率范围
            },
          })
      }
      .height('20%')

      Row() {
        Button('Start')
          .id('PropertyAnimationStart')
          .fontSize(14)
          .fontWeight(500)
          .margin({ bottom: 10, left: 5 })
          .fontColor(Color.White)
          .onClick(() => {
            this.isAnimation = !this.isAnimation;
            this.translateX3 = this.isAnimation ? 100 : -100;

            this.uiContext?.animateTo({
              duration: 1200,
              iterations: 10,
              playMode: PlayMode.AlternateReverse,
              expectedFrameRateRange: { // 设置显式动画的帧率范围
                expected: 30, // 设置动画的期望帧率为30hz
                min: 0, // 设置帧率范围
                max: 120, // 设置帧率范围
              },
            }, () => {
              this.translateX1 = this.isAnimation ? 100 : -100;
            })

            this.uiContext?.animateTo({
              duration: 1200,
              iterations: 10,
              playMode: PlayMode.AlternateReverse,
              expectedFrameRateRange: { // 设置显式动画的帧率范围
                expected: 40, // 设置动画的期望帧率为40hz
                min: 0, // 设置帧率范围
                max: 120, // 设置帧率范围
              },
            }, () => {
              this.translateX2 = this.isAnimation ? 100 : -100;
            })
          })
          .width('40%')
          .height(40)
          .shadow(ShadowStyle.OUTER_DEFAULT_LG)
      }
      .width('100%')
      .justifyContent(FlexAlign.Center)
      .shadow(ShadowStyle.OUTER_DEFAULT_SM)
      .alignItems(VerticalAlign.Bottom)
      .layoutWeight(1)
    }
    .width('100%')
    .justifyContent(FlexAlign.Center)
    .shadow(ShadowStyle.OUTER_DEFAULT_SM)
    .layoutWeight(1)
  }
}
```

## 相关实例

针对可变帧率的开发，有以下相关实例可供参考：

- [DisplaySync分级管控(ArkTS)(API11)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Graphics/DisplaySync)