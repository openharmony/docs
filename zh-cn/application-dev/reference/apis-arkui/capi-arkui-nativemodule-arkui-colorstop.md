# ArkUI_ColorStop
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} ArkUI_ColorStop
```

## 概述

定义渐变色结构，用于配置组件的渐变效果，支持通过颜色数组与位置数组组合定义多种渐变样式。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_type.h](capi-native-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| const uint32_t* colors | 颜色数组，与stops数组按索引一一对应，每个颜色对应一个渐变位置，数组长度必须与size一致。 |
| float* stops | 位置数组，与colors数组成对对应，取值范围为0.0~1.0，表示渐变色的位置偏移，数组长度必须与size一致。设置小于0的值时，自动修正为0。 |
| int size | 数组长度，必须与colors和stops数组的实际元素个数一致，设置前需先确定colors和stops数组的实际元素个数。 |


