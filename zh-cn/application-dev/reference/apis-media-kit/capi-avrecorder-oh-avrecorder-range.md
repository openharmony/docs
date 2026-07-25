# OH_AVRecorder_Range
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AVRecorder_Range {...} OH_AVRecorder_Range;
```

## 概述

表示AVRecorder相关参数（如比特率、帧率等）的取值范围，用于限定录制参数的可配置范围，开发者应在min和max所界定的范围内设置参数值以确保配置有效。

**起始版本：** 18

**相关模块：** [AVRecorder](capi-avrecorder.md)

**所在头文件：** [avrecorder_base.h](capi-avrecorder-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t min | AVRecorder相关参数取值范围的最小值。单位与所描述的参数一致。 |
| int32_t max | AVRecorder相关参数取值范围的最大值。单位与所描述的参数一致。 |


