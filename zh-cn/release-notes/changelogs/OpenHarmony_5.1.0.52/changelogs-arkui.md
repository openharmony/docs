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

## cl.arkui.2 NavDestination标题栏工具栏支持跟手滑动隐藏后，超过2秒未操作，不恢复显示

**访问级别**

公开接口

**变更原因**

UX规范变更。

**变更影响**

此变更不涉及应用适配。

- 变更前：NavDestination组件的标题栏工具栏上滑隐藏，下滑显示，2s不操作后自动显示。
  
- 变更后：NavDestination组件的标题栏工具栏上滑隐藏，下滑显示，2s不操作后不会自动显示。

**起始API Level**

14

**变更发生版本**

从OpenHarmony SDK 5.1.0.52开始。

**变更的接口/组件**

NavDestination.bindToScrollable, NavDestination.bindToNestedScrollable

**适配指导**

默认行为变更，无需适配。

## cl.arkui.3 Tabs组件TabBar的显示和隐藏动效变更

**访问级别**

公开接口

**变更原因**

UX规范变更。

**变更影响**

此变更不涉及应用适配。

- 变更前：Tabs组件的TabBar上滑隐藏，下滑消失，2s不操作后自动显示。
  
- 变更后：Tabs组件的TabBar上滑隐藏，下滑消失，2s不操作后不会自动显示。

**起始API Level**

13

**变更发生版本**

从OpenHarmony SDK 5.1.0.52开始。

**变更的接口/组件**

UIContext的bindTabsToScrollable、bindTabsToNestedScrollable接口

**适配指导**

默认行为变更，无需适配。

## cl.arkui.4 页面退出场景自定义组件删除前移

**访问级别**

公开接口

**变更原因**

在页面退出动画的过程中，UI处于空闲状态。动画结束后，由于释放大量组件导致页面卡顿。可以将页面中自定义组件的释放提前，显著减轻卡顿并优化性能。

**变更影响**

此变更不涉及应用适配，仅针对Router和Navigation页面默认的退出动画场景。

- 变更前：页面退出动画结束后，依次执行自定义组件生命周期aboutToDisappear、onDisappear。
  
- 变更后：页面退出动画过程中，执行自定义组件生命周期aboutToDisappear。退出动画执行结束后，执行生命周期onDisappear。

**起始API Level**

7

**变更发生版本**

从OpenHarmony SDK 5.1.0.52开始。

**变更的接口/组件**

自定义组件的onDisappear生命周期回调。

**适配指导**

默认行为变更，无需适配。