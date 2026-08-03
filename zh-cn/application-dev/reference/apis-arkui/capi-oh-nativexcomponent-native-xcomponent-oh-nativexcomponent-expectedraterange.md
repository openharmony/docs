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

定义期望帧率范围，用于设置XComponent渲染时的期望帧率区间，适用于需要对动画或渲染帧率进行精确控制的场景，可帮助在画面流畅度与功耗之间取得平衡。

**起始版本：** 11

**相关模块：** [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**所在头文件：** [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t min | 期望帧率范围最小值。取值需大于等于0且小于等于max。单位为帧/秒。传入无效值时不生效。取值范围：[0, +∞)。需满足 min <= max。 |
| int32_t max | 期望帧率范围最大值。取值需大于等于min且不超过设备支持的最大帧率。单位为帧/秒。传入无效值时不生效。取值范围：[0, +∞)。需满足 max >= min。 |
| int32_t expected | 期望帧率。取值需满足 min ≤ expected ≤ max。单位为帧/秒。取值范围：[0, +∞)，且应在[min, max]范围内。 |


