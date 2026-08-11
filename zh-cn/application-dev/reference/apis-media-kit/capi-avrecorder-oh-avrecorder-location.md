# OH_AVRecorder_Location
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AVRecorder_Location {...} OH_AVRecorder_Location
```

## 概述

OH_AVRecorder_Location用于提供媒体资源的地理位置信息，支持在音视频录制过程中标注纬度和经度，适用于需要在录制结果中嵌入地理位置的场景，如在视频拍摄时标记拍摄地点、运动记录应用中标记轨迹位置、旅行日记应用中记录行程坐标等场景，便于后续按位置检索和分类管理媒体资源。

**起始版本：** 18

**相关模块：** [AVRecorder](capi-avrecorder.md)

**所在头文件：** [avrecorder_base.h](capi-avrecorder-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| float latitude | 纬度，取值范围[-90, 90]，单位：度（°）。需与longitude配合使用以提供完整的地理位置信息，超出范围时将导致错误。 |
| float longitude | 经度，取值范围[-180, 180]，单位：度（°）。需与latitude配合使用以提供完整的地理位置信息，超出范围时将导致错误。 |


