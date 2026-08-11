# ArkUI_AccessibleRect
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyinhua-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} ArkUI_AccessibleRect
```

## 概述

节点在屏幕中的矩形区域坐标位置。该结构体用于描述无障碍节点的边界矩形，通过左上角和右下角的坐标定义节点在屏幕上的可视区域，支持无障碍服务获取节点的位置和大小信息。

**起始版本：** 13

**相关模块：** [ArkUI_Accessibility](capi-arkui-accessibility.md)

**所在头文件：** [native_interface_accessibility.h](capi-native-interface-accessibility-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t leftTopX | 左上角X轴坐标位置，单位：px。 |
| int32_t leftTopY | 左上角Y轴坐标位置，单位：px。 |
| int32_t rightBottomX | 右下角X轴坐标位置，单位：px。 |
| int32_t rightBottomY | 右下角Y轴坐标位置，单位：px。 |


