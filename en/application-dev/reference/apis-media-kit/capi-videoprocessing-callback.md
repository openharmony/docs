# VideoProcessing_Callback

## Overview

The VideoProcessing_Callback struct describes a callback object for handling video processing events.

You should define a null pointer for **VideoProcessing_Callback** and use [OH_VideoProcessingCallback_Create](capi-video-processing-h.md#oh_videoprocessingcallback_create) to create a callback object. Before creation, ensure that the pointer is null. After creating the callback object, call [OH_VideoProcessing_RegisterCallback](capi-video-processing-h.md#oh_videoprocessing_registercallback) to register it with the video processing instance.

**Since**: 12

**Related module**: [VideoProcessing](capi-videoprocessing.md)

**Header file**: [video_processing_types.h](capi-video-processing-types-h.md)
