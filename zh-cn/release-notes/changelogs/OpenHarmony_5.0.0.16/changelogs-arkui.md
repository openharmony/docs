# ArkUI子系统变更说明

## cl.arkui.1  Swiper组件的默认曲线参数变更

**访问级别**

其他

**变更原因**

规格优化。

**变更影响**

当Swiper组件不设置curve参数时，默认曲线从Linear变更为interpolatingSpring(-1,1,328,34)。

**API Level**

8

**变更发生版本**

从OpenHarmony SDK 5.0.0.16 开始。

**变更的接口/组件**

受影响的组件：Swiper
变更前：Swiper默认曲线为Linear
变更后：Swiper默认曲线为interpolatingSpring(-1,1,328,34)。

**适配指导**

无需适配
