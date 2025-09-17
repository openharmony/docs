# OH_AVRecorder_Metadata
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @shiwei75-->
<!--Designer: @HmQQQ-->
<!--Tester: @xdlinc-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the metadata.

**Since**: 18

**Related module**: [AVRecorder](capi-avrecorder.md)

**Header file**: [avrecorder_base.h](capi-avrecorder-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char* genre | Pointer to the type or genre of the media asset.|
| char* videoOrientation | Pointer to the video rotation direction, in degrees.|
| [OH_AVRecorder_Location](capi-avrecorder-oh-avrecorder-location.md) location | Geographical location of the media asset.|
| [OH_AVRecorder_MetadataTemplate](capi-avrecorder-oh-avrecorder-metadatatemplate.md) customInfo | Custom key-value mappings read from **moov.meta.list**.|
