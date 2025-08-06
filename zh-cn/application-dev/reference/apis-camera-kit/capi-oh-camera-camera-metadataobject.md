# Camera_MetadataObject
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

## 概述

元数据对象基础。

**起始版本：** 11

**相关模块：** [OH_Camera](capi-oh-camera.md)

**所在头文件：** [camera.h](capi-camera-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [Camera_MetadataObjectType](capi-camera-h.md#camera_metadataobjecttype) type | 元数据对象类型。 |
| int64_t timestamp | 元数据对象时间戳（以毫秒为单位）。 |
| [Camera_Rect](capi-oh-camera-camera-rect.md)* boundingBox | 检测到的元数据对象的轴对齐边界框。 |


