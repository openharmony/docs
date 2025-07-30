# avimage_generator_base.h

## Overview

The file declares the enums used by the AVImageGenerator.

**Library**: libavimage_generator.so

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18

**Related module**: [AVImageGenerator](capi-avimagegenerator.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVImageGenerator_QueryOptions](#oh_avimagegenerator_queryoptions) | OH_AVImageGenerator_QueryOptions | Enumerates the mappings between time points and video frames.|

## Enum Description

### OH_AVImageGenerator_QueryOptions

```
enum OH_AVImageGenerator_QueryOptions
```

**Description**

Enumerates the mappings between time points and video frames.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18

| Enum Item| Description|
| -- | -- |
| OH_AVIMAGE_GENERATOR_QUERY_NEXT_SYNC = 0 | Extracts the key frame at or next to the specified time.|
| OH_AVIMAGE_GENERATOR_QUERY_PREVIOUS_SYNC = 1 | Extracts the key frame at or prior to the specified time.|
| OH_AVIMAGE_GENERATOR_QUERY_CLOSEST_SYNC = 2 | Extracts the key frame closest to the specified time.|
| OH_AVIMAGE_GENERATOR_QUERY_CLOSEST = 3 | Extracts the frame (not necessarily a key frame) closest to the specified time.|
