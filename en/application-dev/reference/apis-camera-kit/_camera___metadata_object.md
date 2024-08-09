# Camera_MetadataObject


## Overview

The Camera_MetadataObject struct describes the camera metadata.

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) [type](#type) | Type of the metadata object. | 
| int64_t [timestamp](#timestamp) | Timestamp of the metadata object, in milliseconds. | 
| [Camera_Rect](_camera___rect.md) \* [boundingBox](#boundingbox) | Pointer to the axis aligned bounding box of the metadata object. | 


## Member Variable Description


### boundingBox

```
Camera_Rect* Camera_MetadataObject::boundingBox
```
**Description**

Pointer to the axis aligned bounding box of the metadata object.


### timestamp

```
int64_t Camera_MetadataObject::timestamp
```
**Description**

Timestamp of the metadata object, in milliseconds.


### type

```
Camera_MetadataObjectType Camera_MetadataObject::type
```
**Description**

Type of the metadata object.
