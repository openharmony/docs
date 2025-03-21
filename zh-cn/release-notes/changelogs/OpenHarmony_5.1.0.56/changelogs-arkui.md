# ArkUI子系统Changelog


## cl.arkui.1 系统主动感知组件变化触发onHover事件

**访问级别**

公开接口

**变更原因**

当前onHover事件依赖于鼠标事件的触发，若应用主动触发了布局变化，则不会触发onHover事件。

**变更影响**

此变更不涉及应用适配。

变更前：组件主动调整布局，若鼠标静止，则不会触发onHover事件。例如，当组件绑定了onHover事件，鼠标悬浮在组件上，组件位置发生变化，使得鼠标不再悬浮于该组件时，该组件不会触发onHover(false)的回调；同样，如果组件位置变动导致鼠标悬浮在新的组件上，新组件也不会触发onHover(true)的回调。

变更后：组件主动调整布局，鼠标未移动会触发onHover事件。例如，当组件绑定onHover事件，鼠标悬浮在组件上时，如果组件位置发生改变，鼠标不再悬浮在该组件上，从而触发onHover(false)的回调；如果有新组件有位置变化，鼠标悬浮在新组件上，则会触发新组件的onHover(true)回调。

**起始API Level**

API 8

**变更发生版本**

从OpenHarmony 5.1.0.56 版本开始。

**变更的接口/组件**

onHover

**适配指导**

系统默认行为变化，无需适配。


## cl.arkui.2 XComponent组件上使用renderFit接口显示效果变更

**访问级别**

公开接口

**变更原因**

优化XComponent组件上使用renderFit接口显示效果的正确性。

**变更影响**

此变更要求涉及XComponent组件上使用renderFit接口的应用进行适配。

- 变更前：在XComponent组件上使用renderFit接口，使用部分fit模式的显示效果不符合预期。
  
- 变更后：XComponent组件上使用renderFit接口后，可以正确显示。

![变更前后效果](figures/renderFit/renderFit.png)

**起始API Level**

API 10

**变更发生版本**

从OpenHarmony SDK 5.1.0.56开始。

**变更的接口/组件**

涉及接口: renderFit。

涉及组件: XComponent组件。

**适配指导**

默认行为变更，涉及XComponent组件上使用renderFit接口的应用进行适配，若出现显示效果变更，则需要按照正确效果进行布局。
