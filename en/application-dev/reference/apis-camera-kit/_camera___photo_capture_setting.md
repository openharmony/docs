# Camera_PhotoCaptureSetting


## Overview

The **Camera_PhotoCaptureSetting** struct defines the photographing parameters.

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [quality](#quality) | Quality of the photo.|
| [rotation](#rotation) | Rotation angle.|
| [location](#location) | Location where the photo is taken.|
| [mirror](#mirror) | Whether mirroring is enabled. The default value is **false**.|


## Member Variable Description


### location

```
Camera_Location* Camera_PhotoCaptureSetting::location
```

**Description**

Location where the photo is taken.


### mirror

```
bool Camera_PhotoCaptureSetting::mirror
```

**Description**

Whether mirroring is enabled. The default value is **false**.


### quality

```
Camera_QualityLevel Camera_PhotoCaptureSetting::quality
```

**Description**

Quality of the photo.


### rotation

```
Camera_ImageRotation Camera_PhotoCaptureSetting::rotation
```

**Description**

Rotation angle.
