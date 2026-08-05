# ArkUI_ExpectedFrameRateRange
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} ArkUI_ExpectedFrameRateRange
```

## 概述

设置动画的期望帧率。该结构体通过min、max和expected三个字段定义帧率范围，系统尽可能满足期望帧率。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_animate.h](capi-native-animate-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t min | 期望的最小帧率，单位为帧/秒（fps）。取值原则：min需小于等于max，且min需小于等于expected。取值需满足min &lt;= expected &lt;= max，不满足时该期望帧率范围设置不生效。 |
| uint32_t max | 期望的最大帧率，单位为帧/秒（fps）。取值原则：max需大于等于min，且max需大于等于expected。三者取值需满足min &lt;= expected &lt;= max。 |
| uint32_t expected | 期望的最优帧率，单位为帧/秒（fps）。取值原则：expected需在[min, max]范围内取值。 |


