# Location_BasicInfo
<!--Kit: Location Kit-->
<!--Subsystem: Location-->
<!--Owner: @liu-binjun-->
<!--Designer: @liu-binjun-->
<!--Tester: @mhy123456789-->
<!--Adviser: @RayShih-->

```c
typedef struct Location_BasicInfo {...} Location_BasicInfo
```

## Overview

Defines the struct for the basic location information.

**Since**: 13

**Related module**: [Location](capi-location.md)

**Header file**: [oh_location_type.h](capi-oh-location-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| double latitude | Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude. The value ranges from –90 to 90. Only the WGS84 coordinate system is supported.|
| double longitude | Longitude information. A positive value indicates east longitude, and a negative value indicates west longitude. The value ranges from -180 to 180. Only the WGS84 coordinate system is supported.|
| double altitude | Location altitude, in meters.|
| double accuracy | Location accuracy, in meters.|
| double speed | Speed, in m/s.|
| double direction | Direction information. The value ranges from **0** to **360**, in degrees.|
| int64_t timeForFix | Location timestamp in the UTC format.|
| int64_t timeSinceBoot | Timestamp when the location is successfully obtained. The value is the duration from the time when the device is booted to the time when the location is obtained, in nanoseconds.|
| double altitudeAccuracy | Height accuracy, in meters.|
| double speedAccuracy | Speed accuracy, in m/s.|
| double directionAccuracy | Direction accuracy. The value ranges from **0** to **360**, in degrees.|
| int64_t uncertaintyOfTimeSinceBoot | Uncertainty of the location timestamp, in nanoseconds.|
| [Location_SourceType](capi-oh-location-type-h.md#location_sourcetype) locationSourceType | Source of the location result. For details, see [Location_SourceType](capi-oh-location-type-h.md#location_sourcetype).|
