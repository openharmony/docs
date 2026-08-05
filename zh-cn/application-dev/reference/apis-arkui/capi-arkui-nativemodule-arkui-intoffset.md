# ArkUI_IntOffset
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @fenglinbailu-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} ArkUI_IntOffset
```

## 概述

偏移量，用于描述当前组件相对于父组件的位置。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_type.h](capi-native-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t x | 水平方向的偏移量，单位为px。x为正数时组件向右偏移，为负数时向左偏移。 |
| int32_t y | 竖直方向的偏移量，单位为px。y为正数时组件向下偏移，为负数时向上偏移。 |


