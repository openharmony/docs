# OH_NativeXComponent_ExpectedRateRange
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} OH_NativeXComponent_ExpectedRateRange
```

## 概述

定义期望帧率范围。该结构体用于设置XComponent的帧率范围，支持在高性能渲染场景下进行精确的帧率控制，帮助平衡画面流畅度与功耗。

**起始版本：** 11

**相关模块：** [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**所在头文件：** [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t min | 期望帧率范围最小值。单位为帧/秒。取值范围：[0, +∞)。需满足 min <= max。 |
| int32_t max | 期望帧率范围最大值。单位为帧/秒。取值范围：[0, +∞)。需满足 max >= min。 |
| int32_t expected | 期望帧率。单位为帧/秒。取值范围：[0, +∞)，且应在[min, max]范围内。 |


