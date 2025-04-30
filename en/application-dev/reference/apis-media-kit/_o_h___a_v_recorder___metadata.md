# OH_AVRecorder_Metadata


## Overview

The OH_AVRecorder_Metadata struct describes the metadata.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Since**: 18

**Related module**: [AVRecorder](_a_v_recorder.md)

**Header file**: [avrecorder_base.h](avrecorder__base_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| char \*[genre](#genre) | Type or genre of the media asset.| 
| char \*[videoOrientation](#videoorientation) | Video rotation direction, in degrees.| 
| [OH_AVRecorder_Location](_o_h___a_v_recorder___location.md) [location](#location) | Geographical location of the media asset.| 
| [OH_AVRecorder_MetadataTemplate](_o_h___a_v_recorder___metadata_template.md) [customInfo](#custominfo) | Custom key-value mappings read from **moov.meta.list**.| 


## Member Variable Description


### genre

```
char *genre
```

**Description**

Type or genre of the media asset.


### videoOrientation

```
char *videoOrientation
```

**Description**

Video rotation direction, in degrees.


### location

```
OH_AVRecorder_Location location
```

**Description**

Geographical location of the media asset.


### customInfo

```
OH_AVRecorder_MetadataTemplate customInfo
```

**Description**

Custom key-value mappings read from **moov.meta.list**.
