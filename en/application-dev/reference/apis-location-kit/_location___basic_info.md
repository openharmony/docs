# Location_BasicInfo


## Overview

Defines the struct for the basic location information.

**Since**: 13

**Related module**: [Location](_location.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| double [latitude](#latitude) | Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude. The value ranges from –90 to 90. Only the WGS84 coordinate system is supported. | 
| double [longitude](#longitude) | Longitude information. A positive value indicates east longitude, and a negative value indicates west longitude. The value ranges from -180 to 180. Only the WGS84 coordinate system is supported. | 
| double [altitude](#altitude) | Location altitude, in meters. | 
| double [accuracy](#accuracy) | Location accuracy, in meters. | 
| double [speed](#speed) | Speed, in m/s. | 
| double [direction](#direction) | Direction information. The value ranges from **0** to **360**, in degrees. | 
| int64_t [timeForFix](#timeforfix) | Location timestamp in the UTC format. | 
| int64_t [timeSinceBoot](#timesinceboot) | Location timestamp since boot, in nanosecond.<br>The value is the duration from the time when the device is booted to the time when the location is obtained. This means that the timestamp is reset each time the device is restarted.<br>  | 
| double [altitudeAccuracy](#altitudeaccuracy) | Height accuracy, in meters. | 
| double [speedAccuracy](#speedaccuracy) | Speed accuracy, in m/s. | 
| double [directionAccuracy](#directionaccuracy) | Direction accuracy. The value ranges from **0** to **360**, in degrees. | 
| int64_t [uncertaintyOfTimeSinceBoot](#uncertaintyoftimesinceboot) | Uncertainty of the location timestamp (that is, **timeSinceBoot**), in nanosecond. | 
| [Location_SourceType](_location.md#location_sourcetype) [locationSourceType](#locationsourcetype) | Source of the location result.<br>For details, see [Location_SourceType](_location.md#location_sourcetype).| 


## Member Variable Description


### accuracy

```
double Location_BasicInfo::accuracy
```
**Description**
Location accuracy, in meters.


### altitude

```
double Location_BasicInfo::altitude
```
**Description**
Location altitude, in meters.


### altitudeAccuracy

```
double Location_BasicInfo::altitudeAccuracy
```
**Description**
Height accuracy, in meters.


### direction

```
double Location_BasicInfo::direction
```
**Description**
Direction information. The value ranges from 0 to 360, in degrees.


### directionAccuracy

```
double Location_BasicInfo::directionAccuracy
```
**Description**
Direction accuracy. The value ranges from 0 to 360, in degrees.


### latitude

```
double Location_BasicInfo::latitude
```
**Description**
Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude. The value ranges from –90 to 90. Only the WGS84 coordinate system is supported.


### locationSourceType

```
Location_SourceType Location_BasicInfo::locationSourceType
```
**Description**
Source of the location result. For details, see [Location_SourceType](_location.md#location_sourcetype).


### longitude

```
double Location_BasicInfo::longitude
```
**Description**
Longitude information. A positive value indicates east longitude, and a negative value indicates west longitude. The value ranges from -180 to 180. Only the WGS84 coordinate system is supported.


### speed

```
double Location_BasicInfo::speed
```
**Description**
Speed, in m/s.


### speedAccuracy

```
double Location_BasicInfo::speedAccuracy
```
**Description**
Speed accuracy, in m/s.


### timeForFix

```
int64_t Location_BasicInfo::timeForFix
```
**Description**
Location timestamp in the UTC format.


### timeSinceBoot

```
int64_t Location_BasicInfo::timeSinceBoot
```
**Description**
Location timestamp since boot.


### uncertaintyOfTimeSinceBoot

```
int64_t Location_BasicInfo::uncertaintyOfTimeSinceBoot
```
**Description**
Uncertainty of the location timestamp.
