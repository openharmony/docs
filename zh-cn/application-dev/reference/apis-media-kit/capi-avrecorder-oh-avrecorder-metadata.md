# OH_AVRecorder_Metadata
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @zzs911-->

```c
typedef struct OH_AVRecorder_Metadata {...} OH_AVRecorder_Metadata
```

## 概述

定义录制的元数据结构，用于描述媒体资源的体裁分类、视频旋转角度、地理位置及自定义参数等元数据信息，适用于录制过程中需要携带或读取媒体元数据的场景。

**起始版本：** 18

**相关模块：** [AVRecorder](capi-avrecorder.md)

**所在头文件：** [avrecorder_base.h](capi-avrecorder-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char* genre | 媒体资源的体裁分类。不设置时不携带体裁分类信息。 |
| char* videoOrientation | 视频的旋转角度，单位为度（°），仅支持特定角度值：0°（无旋转，视频保持原始方向）、90°（顺时针旋转90度）、180°（旋转180度）、270°（顺时针旋转270度）。不设置时默认为0°。传入不支持的角度值时，设置失败。 |
| [OH_AVRecorder_Location](capi-avrecorder-oh-avrecorder-location.md) location | 媒体资源的地理位置信息，包含纬度（latitude）和经度（longitude）。其中latitude取值范围[-90, 90]，longitude取值范围[-180, 180]，单位为度（°）。传入超出取值范围的值时，设置失败。不设置时不携带地理位置信息。 |
| [OH_AVRecorder_MetadataTemplate](capi-avrecorder-oh-avrecorder-metadatatemplate.md) customInfo | 写入 moov.meta.list 的自定义参数键值映射，键和值均为字符串类型，用于在录制时携带应用自定义的元数据标签，如添加业务标识、扩展属性等。不设置时不携带自定义元数据信息。 |


