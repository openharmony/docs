# OH_Pixelmap_HdrMetadataValue


## Overview

The OH_Pixelmap_HdrMetadataValue struct describes the HDR metadata values used by the pixel map and available for the key [OH_Pixelmap_HdrMetadataKey](_image___native_module.md#oh_pixelmap_hdrmetadatakey). It is used in [OH_PixelmapNative_SetMetadata](_image___native_module.md#oh_pixelmapnative_setmetadata) and [OH_PixelmapNative_GetMetadata](_image___native_module.md#oh_pixelmapnative_getmetadata).

**Since**: 12

**Related module**: [Image_NativeModule](_image___native_module.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_Pixelmap_HdrMetadataType](_image___native_module.md#oh_pixelmap_hdrmetadatatype) [type](#type) | Values available for the key **HDR_METADATA_TYPE**. | 
| [OH_Pixelmap_HdrStaticMetadata](_o_h___pixelmap___hdr_static_metadata.md) [staticMetadata](#staticmetadata) | Values available for the key **HDR_STATIC_METADATA**. | 
| [OH_Pixelmap_HdrDynamicMetadata](_o_h___pixelmap___hdr_dynamic_metadata.md) [dynamicMetadata](#dynamicmetadata) | Values available for the key **HDR_DYNAMIC_METADATA**. | 
| [OH_Pixelmap_HdrGainmapMetadata](_o_h___pixelmap___hdr_gainmap_metadata.md) [gainmapMetadata](#gainmapmetadata) | Values available for the key **HDR_GAINMAP_METADATA**. | 


## Member Variable Description


### dynamicMetadata

```
OH_Pixelmap_HdrDynamicMetadata OH_Pixelmap_HdrMetadataValue::dynamicMetadata
```

**Description**

Values available for the key **HDR_DYNAMIC_METADATA**.


### gainmapMetadata

```
OH_Pixelmap_HdrGainmapMetadata OH_Pixelmap_HdrMetadataValue::gainmapMetadata
```

**Description**

Values available for the key **HDR_GAINMAP_METADATA**.


### staticMetadata

```
OH_Pixelmap_HdrStaticMetadata OH_Pixelmap_HdrMetadataValue::staticMetadata
```

**Description**

Values available for the key **HDR_STATIC_METADATA**.


### type

```
OH_Pixelmap_HdrMetadataType OH_Pixelmap_HdrMetadataValue::type
```

**Description**

Values available for the key **HDR_METADATA_TYPE**.
