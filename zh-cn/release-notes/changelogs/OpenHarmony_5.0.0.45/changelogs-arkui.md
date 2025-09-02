# ArkUI子系统Changelog

## cl.arkui.1 bindSheet半模态面板视觉样式增加

**访问级别**

公开接口

**变更原因**

增强视觉效果。

**变更影响**

此变更涉及应用适配。

设备宽度在600-840vp间时，SheetOptions中的preferType设置为SheetType.POPUP，原先显示居中弹窗样式，现在显示跟手弹窗样式。

API version 14及以后，设备宽度在600-840vp间时，默认显示居中弹窗样式，增加跟手弹窗样式。

变更前：设备宽度在600-840vp间时，SheetOptions中的preferType设置为SheetType.POPUP，实际显示居中弹窗样式。

![zh-cn_image_alert](figures/45.1.3.png)

变更后：设备宽度在600-840vp间时，SheetOptions中的preferType设置为SheetType.POPUP，实际显示跟手弹窗样式。

![zh-cn_image_alert](figures/45.1.2.png)

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.45 版本开始。

**变更的接口/组件**

SheetType.POPUP

**适配指导**

设备宽度在600-840vp间时，如需显示跟手弹窗样式，则SheetOptions中的preferType设置为SheetType.POPUP；如需显示底部弹窗样式，则preferType设置为SheetType.BOTTOM；如需显示居中弹窗样式，则preferType设置为SheetType.CENTER或者不设置。


## cl.arkui.3 bindSheet半模态面板标题与关闭按钮布局变更

**访问级别**

公开接口

**变更原因**

增强视觉效果。

**变更影响**

此变更不涉及应用适配。

API version 14及以后，关闭按钮不显示时，关闭按钮区域放开限制给标题栏区域布局。

变更前：关闭按钮不显示时，关闭按钮区域未放开限制给标题栏区域布局。

变更后：关闭按钮不显示时，关闭按钮区域放开限制给标题栏区域布局。

| 变更前                                   | 变更后                                   |
| ---------------------------------------- | ---------------------------------------- |
| ![zh-cn_image_alert](figures/45.1.5.png) | ![zh-cn_image_alert](figures/45.1.4.png) |

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.45 版本开始。

**变更的接口/组件**

showClose

