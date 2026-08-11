# ArkUI_PointF
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} ArkUI_PointF
```

## 概述

定义一个二维坐标点结构体，用于描述组件位置或偏移等坐标信息，坐标以浮点类型存储。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_type_visual.h](capi-native-type-visual-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| float x | x轴坐标，单位为px。取值范围：(-∞, +∞)。 |
| float y | y轴坐标，单位为px。取值范围：(-∞, +∞)。 |
