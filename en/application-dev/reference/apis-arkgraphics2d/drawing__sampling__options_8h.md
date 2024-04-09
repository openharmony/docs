# drawing_sampling_options.h


## Overview

The **drawing_sampling_options.h** file declares the functions related to sampling in the drawing module. It is used for image or texture sampling.

**File to include**: &lt;native_drawing/drawing_sampling_options.h&gt;

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](_drawing.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [OH_Drawing_FilterMode](_drawing.md#oh_drawing_filtermode)  [OH_Drawing_FilterMode](_drawing.md#oh_drawing_filtermode) | Describes an enum for filter modes.|
| typedef enum [OH_Drawing_MipmapMode](_drawing.md#oh_drawing_mipmapmode)  [OH_Drawing_MipmapMode](_drawing.md#oh_drawing_mipmapmode) | Describes an enum for mipmap modes.|


### Enums

| Name| Description|
| -------- | -------- |
| [OH_Drawing_FilterMode](_drawing.md#oh_drawing_filtermode) { FILTER_MODE_NEAREST, FILTER_MODE_LINEAR } | Enumerates the filter modes.|
| [OH_Drawing_MipmapMode](_drawing.md#oh_drawing_mipmapmode) { MIPMAP_MODE_NONE, MIPMAP_MODE_NEAREST, MIPMAP_MODE_LINEAR } | Enumerates the mipmap modes.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) \* [OH_Drawing_SamplingOptionsCreate](_drawing.md#oh_drawing_samplingoptionscreate) ([OH_Drawing_FilterMode](_drawing.md#oh_drawing_filtermode), [OH_Drawing_MipmapMode](_drawing.md#oh_drawing_mipmapmode)) | Creates an **OH_Drawing_SamplingOptions** object.|
| void [OH_Drawing_SamplingOptionsDestroy](_drawing.md#oh_drawing_samplingoptionsdestroy) ([OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) \*) | Destroys an **OH_Drawing_SamplingOptions** object and reclaims the memory occupied by the object.|
