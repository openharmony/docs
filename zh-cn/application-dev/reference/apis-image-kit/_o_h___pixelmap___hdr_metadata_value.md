# OH_Pixelmap_HdrMetadataValue


## 概述

Pixelmap使用的HDR元数据值，和OH_Pixelmap_HdrMetadataKey关键字相对应。用于[OH_PixelmapNative_SetMetadata](_image___native_module.md#oh_pixelmapnative_setmetadata)及[OH_PixelmapNative_GetMetadata](_image___native_module.md#oh_pixelmapnative_getmetadata)，有相应[OH_Pixelmap_HdrMetadataKey](_image___native_module.md#oh_pixelmap_hdrmetadatakey)关键字作为入参时，设置或获取到本结构体中相对应的元数据类型的值。

**起始版本：** 12

**相关模块：**[Image_NativeModule](_image___native_module.md)

**所在头文件：**[pixelmap_native.h](pixelmap__native_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Pixelmap_HdrMetadataType](_image___native_module.md#oh_pixelmap_hdrmetadatatype) [type](#type) | HDR_METADATA_TYPE关键字对应的具体值。  | 
| [OH_Pixelmap_HdrStaticMetadata](_o_h___pixelmap___hdr_static_metadata.md) [staticMetadata](#staticmetadata) | HDR_STATIC_METADATA关键字对应的具体值。  | 
| [OH_Pixelmap_HdrDynamicMetadata](_o_h___pixelmap___hdr_dynamic_metadata.md) [dynamicMetadata](#dynamicmetadata) | HDR_DYNAMIC_METADATA关键字对应的具体值。  | 
| [OH_Pixelmap_HdrGainmapMetadata](_o_h___pixelmap___hdr_gainmap_metadata.md) [gainmapMetadata](#gainmapmetadata) | HDR_GAINMAP_METADATA关键字对应的具体值。  | 


## 结构体成员变量说明


### dynamicMetadata

```
OH_Pixelmap_HdrDynamicMetadata OH_Pixelmap_HdrMetadataValue::dynamicMetadata
```
**描述**
HDR_DYNAMIC_METADATA关键字对应的具体值。


### gainmapMetadata

```
OH_Pixelmap_HdrGainmapMetadata OH_Pixelmap_HdrMetadataValue::gainmapMetadata
```
**描述**
HDR_GAINMAP_METADATA关键字对应的具体值。


### staticMetadata

```
OH_Pixelmap_HdrStaticMetadata OH_Pixelmap_HdrMetadataValue::staticMetadata
```
**描述**
HDR_STATIC_METADATA关键字对应的具体值。


### type

```
OH_Pixelmap_HdrMetadataType OH_Pixelmap_HdrMetadataValue::type
```
**描述**
HDR_METADATA_TYPE关键字对应的具体值。
