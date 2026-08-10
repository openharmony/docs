# ArkUI_ScaleOptions
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} ArkUI_ScaleOptions
```

## 概述

定义组件转场时的缩放选项。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_type_visual.h](capi-native-type-visual-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| float x | x轴的缩放倍数，默认值1.0。x>1时沿x轴方向放大，0<x<1时沿x轴方向缩小，x<0时沿x轴方向反向，缩放倍数为\|x\|。缩放以centerX为锚点进行。注意：x=0时组件在x轴方向完全消失，使用时需留意特殊值的影响。 |
| float y | y轴的缩放倍数，默认值1.0。y>1时沿y轴方向放大，0<y<1时沿y轴方向缩小，y<0时沿y轴方向反向，缩放倍数为\|y\|。注意：y=0时组件在y轴方向完全消失，使用时需留意特殊值的影响。 |
| float z | z轴的缩放倍数，默认值1.0。在二维显示模式下，该参数无效。 |
| float centerX | 组件变换中心点（即锚点）的x轴坐标，单位为百分比，0表示组件左边缘，1表示组件右边缘，0.5表示组件水平中心。默认值0.5。x轴缩放效果以该点为锚点进行，不同centerX值决定缩放锚点的x方向位置。取值为0时缩放从组件左边缘展开，取值为0.5时缩放从水平中心展开，取值为1时缩放从右边缘展开。 |
| float centerY | 组件变换中心点（即锚点）的y轴坐标，单位为百分比，0表示组件顶部边缘，1表示组件底部边缘，0.5表示组件垂直中心。默认值0.5。y轴缩放效果以该点为锚点进行，不同centerY值决定缩放锚点的y方向位置。取值为0时缩放从组件顶部边缘展开，取值为0.5时缩放从垂直中心展开，取值为1时缩放从底部边缘展开。 |


