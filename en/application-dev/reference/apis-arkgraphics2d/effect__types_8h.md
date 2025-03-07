# effect_types.h


## Overview

The **effect_types.h** file declares the data types of the image effect filter.

**File to include**: &lt;native_effect/effect_types.h&gt;

**Library**: libnative_effect.so

**System capability**: SystemCapability.Multimedia.Image.Core

**Since**: 12

**Related module**: [EffectKit](effect_kit.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_Filter](_o_h___filter.md) | Describes a filter used to generate a filter pixel map.| 
| struct  [OH_Filter_ColorMatrix](_o_h___filter___color_matrix.md) | Describes a matrix used to create an effect filter.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_Filter](_o_h___filter.md)  [pixelMap](effect_kit.md#pixelmap) | Defines a struct for a filter used to generate a filter pixel map.| 
| typedef enum [EffectErrorCode](effect_kit.md#effecterrorcode)  [EffectErrorCode](effect_kit.md#effecterrorcode) | Defines an enum for the status codes that may be used by the effect filter.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [EffectErrorCode](effect_kit.md#effecterrorcode) { EFFECT_SUCCESS = 0, EFFECT_BAD_PARAMETER = 401, EFFECT_UNSUPPORTED_OPERATION = 7600201, EFFECT_UNKNOWN_ERROR = 7600901 } | Enumerates the status codes that may be used by the effect filter.| 
| [EffectTileMode](effect_kit.md#effecttilemode) { CLAMP = 0, REPEAT, MIRROR, DECAL } | Enumerates the tile modes of the shader effect.| 
