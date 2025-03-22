# ArkUI子系统Changelog


## cl.arkui.1 XComponent组件上使用renderFit接口显示效果变更

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
