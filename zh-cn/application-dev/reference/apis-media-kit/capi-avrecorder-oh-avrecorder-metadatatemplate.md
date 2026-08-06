# OH_AVRecorder_MetadataTemplate
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AVRecorder_MetadataTemplate {...} OH_AVRecorder_MetadataTemplate
```

## 概述

定义音视频录制过程中元数据的基本模板，通过键值对（key-value）形式组织元数据信息，适用于需要在录制输出中附加自定义元数据（如标题、作者、描述等）的场景。

**起始版本：** 18

**相关模块：** [AVRecorder](capi-avrecorder.md)

**所在头文件：** [avrecorder_base.h](capi-avrecorder-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char* key | 元数据的键。 |
| char* value | 元数据的值。 |


