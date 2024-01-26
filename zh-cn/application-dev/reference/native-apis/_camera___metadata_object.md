# Camera_MetadataObject


## 概述

元数据对象基础。

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) [type](#type) | 元数据对象类型。  | 
| int64_t [timestamp](#timestamp) | 元数据对象时间戳（以毫秒为单位）。  | 
| [Camera_Rect](_camera___rect.md) \* [boundingBox](#boundingbox) | 检测到的元数据对象的轴对齐边界框。  | 


## 结构体成员变量说明


### boundingBox

```
Camera_Rect* Camera_MetadataObject::boundingBox
```
**描述**
检测到的元数据对象的轴对齐边界框。


### timestamp

```
int64_t Camera_MetadataObject::timestamp
```
**描述**
元数据对象时间戳（以毫秒为单位）。


### type

```
Camera_MetadataObjectType Camera_MetadataObject::type
```
**描述**
元数据对象类型。
