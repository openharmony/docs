# avimage_generator.h


## Overview

The **avimage_generator.h** file declares the AVImageGenerator APIs. With these native APIs, you can extract video frames at given time points from videos.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Library**: libavimage_generator.so

**Since**: 18

**Related module**: [AVImageGenerator](_a_v_image_generator.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AVImageGenerator](_a_v_image_generator.md#oh_avimagegenerator) [OH_AVImageGenerator](_a_v_image_generator.md#oh_avimagegenerator) | Defines a struct for the OH_AVImageGenerator. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVImageGenerator](_a_v_image_generator.md#oh_avimagegenerator) \* [OH_AVImageGenerator_Create](_a_v_image_generator.md#oh_avimagegenerator_create) (void) | Creates an **OH_AVImageGenerator** instance. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVImageGenerator_SetFDSource](_a_v_image_generator.md#oh_avimagegenerator_setfdsource) ([OH_AVImageGenerator](_a_v_image_generator.md#oh_avimagegenerator) \*generator, int32_t fd, int64_t offset, int64_t size) | Sets a data source based on the media file descriptor. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVImageGenerator_FetchFrameByTime](_a_v_image_generator.md#oh_avimagegenerator_fetchframebytime) ([OH_AVImageGenerator](_a_v_image_generator.md#oh_avimagegenerator) \*generator, int64_t timeUs, [OH_AVImageGenerator_QueryOptions](_a_v_image_generator.md#oh_avimagegenerator_queryoptions) options, OH_PixelmapNative \*\*pixelMap) | Extracts a video frame at a given time from a video. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVImageGenerator_Release](_a_v_image_generator.md#oh_avimagegenerator_release) ([OH_AVImageGenerator](_a_v_image_generator.md#oh_avimagegenerator) \*generator) | Releases the resources used by the **OH_AVImageGenerator** instance and destroys the instance. | 
