# OH_AVScreenCaptureHighlightConfig
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AVScreenCaptureHighlightConfig {...} OH_AVScreenCaptureHighlightConfig
```

## 概述

表示高亮边框的样式，用于在录屏场景中标记被录制区域的边界，包括高亮边框的模式、边框宽度和边框颜色。通过配置高亮边框，可帮助用户清晰区分录屏区域与非录屏区域，提升录屏交互体验。该配置通常用于屏幕录制场景中高亮显示特定区域，例如：录制操作教程时高亮标注操作区域、录制应用演示时突出显示重点内容、录制游戏时标注关注区域等。

**起始版本：** 22

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [OH_ScreenCaptureHighlightMode](capi-native-avscreen-capture-base-h.md#oh_screencapturehighlightmode) mode | 高亮边框的模式，各枚举值的意义及与数字的对应关系请参见[OH_ScreenCaptureHighlightMode](capi-native-avscreen-capture-base-h.md#oh_screencapturehighlightmode)枚举定义。方形全包边框：适用于常规录制场景，高亮效果更明显。四角包裹边框：适用于需要减少视觉干扰的场景。未指定时默认为方形全包边框（即边框完全包围捕获区域的所有边）；其他模式请根据录制区域的显示需求选择。 |
| uint32_t lineThickness | 高亮边框的宽度，不设置默认不显示线宽（即线宽为0或未绘制），宽度有效值范围在[1, 8]，单位为虚拟像素（vp）。超出有效值范围的设置不生效。设置后会以指定的宽度在录制区域周围绘制高亮边框，宽度越大边框越粗。 |
| uint32_t lineColor | 高亮边框的颜色，不设置默认为黑色（0x000000），颜色有效值为RGB（0x000000-0xffffff）格式和非透明的ARGB（0xff000000-0xffffffff）格式，超出有效值范围的设置不生效。设置后会以指定的颜色在录制区域周围绘制高亮边框，可用于区分不同的录制区域或提高可视性。 |