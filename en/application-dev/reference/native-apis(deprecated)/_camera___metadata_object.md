# Camera_MetadataObject


## Overview

The **Camera_MetadataObject** struct defines the camera metadata.

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [type](#type) | Type of the metadata object.|
| [timestamp](#timestamp) | Timestamp of the metadata object, in milliseconds.|
| \*[boundingBox](#boundingbox) | Axis alignment bounding box of the metadata object.|


## Member Variable Description


### boundingBox

```
Camera_Rect* Camera_MetadataObject::boundingBox
```

**Description**

Axis alignment bounding box of the metadata object.


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
