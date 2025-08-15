# Types
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## HdrMetadataValue<sup>12+</sup>

type HdrMetadataValue = HdrMetadataType | HdrStaticMetadata | ArrayBuffer | HdrGainmapMetadata

PixelMap使用的HDR元数据值类型，和[HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12)关键字相对应。

**系统能力：** SystemCapability.Multimedia.Image.Core

| 类型                | 说明                                            |
| ------------------- | ----------------------------------------------- |
| [HdrMetadataType](arkts-apis-image-e.md#hdrmetadatatype12) | [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12)中HDR_GAINMAP_METADATA关键字对应的元数据值类型。 |
| [HdrStaticMetadata](arkts-apis-image-i.md#hdrstaticmetadata12) | [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12)中HDR_STATIC_METADATA关键字对应的元数据值类型。 |
| ArrayBuffer | [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12)中HDR_DYNAMIC_METADATA关键字对应的元数据值类型。 |
| [HdrGainmapMetadata](arkts-apis-image-i.md#hdrgainmapmetadata12) | [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12)中HDR_GAINMAP_METADATA关键字对应的元数据值类型。 |
