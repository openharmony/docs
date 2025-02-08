# ArkUI子系统Changelog

## cl.arkui.1 Slider支持设置触控反馈（声音和振动）效果

**访问级别**

公开接口

**变更原因**

UX规范变更。

**变更影响**

此变更涉及应用适配。

- 变更前：Slider组件无触控反馈（声音和振动）效果。
  
- 变更后：Slider组件在显示刻度时，滑块在滑动过程中经过刻度会触发触控反馈（声音和振动）效果；在无极滑动模式下，滑块滑动到两侧边缘也会触发触控反馈（声音和振动）效果。

**起始API Level**

16

**变更发生版本**

从OpenHarmony SDK 5.1.0.52开始。

**适配指导**

Slider 默认支持触控反馈（声音和振动）效果，如果开发者不想要此效果，可以通过为Slider组件设置 enableHapticFeedback(false) 来关闭此效果。如下代码实现：
```ts
@Entry
@Component
struct SlideExample {
  build() {
    Row() {
      Column() {
        Slider()
          .enableHapticFeedback(false)

        Slider({
          step: 10,
        })
          .showSteps(true)
          .enableHapticFeedback(false)
      }.width('100%')
    }.height('100%')
  }
}
```