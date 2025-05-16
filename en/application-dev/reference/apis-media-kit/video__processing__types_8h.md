# video_processing_types.h


## Overview

The **video_processing_types.h** file declares the video processing types.

**Library**: libvideo_processing.so

**File to include**: <multimedia/video_processing_engine/video_processing_types.h>

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Since**: 12

**Related module**: [VideoProcessing](_video_processing.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) | Describes the color space information of video processing.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_VideoProcessing](_video_processing.md#oh_videoprocessing ) [OH_VideoProcessing](_video_processing.md#oh_videoprocessing) | Defines a struct for the video processing object.| 
| typedef struct NativeWindow [OHNativeWindow](_video_processing.md#ohnativewindow) | Defines a struct for the NativeWindow object.| 
| typedef struct [OH_AVFormat](_video_processing.md#oh_avformat-1) [OH_AVFormat](_video_processing.md#oh_avformat) | Defines a struct for the OH_AVFormat object.| 
| typedef struct [VideoProcessing_ColorSpaceInfo](_video_processing___color_space_info.md) [VideoProcessing_ColorSpaceInfo](_video_processing.md#videoprocessing_colorspaceinfo) | Defines a struct for the color space information of video processing.| 
| typedef enum [VideoDetailEnhancer_QualityLevel](_video_processing.md#videodetailenhancer_qualitylevel-1) [VideoDetailEnhancer_QualityLevel](_video_processing.md#videodetailenhancer_qualitylevel) | Defines an enum for the quality levels for detail enhancement.| 
| typedef enum [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode-1) [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) | Defines an enum for the video processing error codes.| 
| typedef enum [VideoProcessing_State](_video_processing.md#videoprocessing_state-1) [VideoProcessing_State](_video_processing.md#videoprocessing_state) | Defines an enum for the video processing states.| 
| typedef struct [VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) [VideoProcessing_Callback](_video_processing.md#videoprocessing_callback) | Defines a struct for the video processing callback object.| 
| typedef void(\* [OH_VideoProcessingCallback_OnError](_video_processing.md#oh_videoprocessingcallback_onerror)) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode) error, void \*userData) | Defines a pointer to the callback function for reporting an error during video processing.| 
| typedef void(\* [OH_VideoProcessingCallback_OnState](_video_processing.md#oh_videoprocessingcallback_onstate)) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, [VideoProcessing_State](_video_processing.md#videoprocessing_state) state, void \*userData) | Defines a pointer to the callback function for reporting the video processing state.| 
| typedef void(\* [OH_VideoProcessingCallback_OnNewOutputBuffer](_video_processing.md#oh_videoprocessingcallback_onnewoutputbuffer)) ([OH_VideoProcessing](_video_processing.md#oh_videoprocessing) \*videoProcessor, uint32_t index, void \*userData) | Defines a pointer to the callback function for reporting the data filled in the output buffer.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [VideoDetailEnhancer_QualityLevel](_video_processing.md#videodetailenhancer_qualitylevel-1) {<br>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_NONE,<br>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_LOW,<br>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM,<br>VIDEO_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH<br>} | Enumerates the quality levels for detail enhancement.| 
| [VideoProcessing_ErrorCode](_video_processing.md#videoprocessing_errorcode-1) {<br>VIDEO_PROCESSING_SUCCESS,<br>VIDEO_PROCESSING_ERROR_INVALID_PARAMETER = 401,<br>VIDEO_PROCESSING_ERROR_UNKNOWN = 29210001,<br>VIDEO_PROCESSING_ERROR_INITIALIZE_FAILED,<br>VIDEO_PROCESSING_ERROR_CREATE_FAILED,<br>VIDEO_PROCESSING_ERROR_PROCESS_FAILED,<br>VIDEO_PROCESSING_ERROR_UNSUPPORTED_PROCESSING,<br>VIDEO_PROCESSING_ERROR_OPERATION_NOT_PERMITTED,<br>VIDEO_PROCESSING_ERROR_NO_MEMORY,<br>VIDEO_PROCESSING_ERROR_INVALID_INSTANCE,<br>VIDEO_PROCESSING_ERROR_INVALID_VALUE<br>} | Enumerates the video processing error codes.| 
| [VideoProcessing_State](_video_processing.md#videoprocessing_state-1) {<br>VIDEO_PROCESSING_STATE_RUNNING,<br>VIDEO_PROCESSING_STATE_STOPPED<br>} | Enumerates the video processing states.| 


### Variables

| Name| Description| 
| -------- | -------- |
| const int32_t [VIDEO_PROCESSING_TYPE_COLOR_SPACE_CONVERSION](_video_processing.md#video_processing_type_color_space_conversion) | Instance created for color space conversion during video processing.| 
| const int32_t [VIDEO_PROCESSING_TYPE_METADATA_GENERATION](_video_processing.md#video_processing_type_metadata_generation) | Instance created for metadata generation during video processing.| 
| const int32_t [VIDEO_PROCESSING_TYPE_DETAIL_ENHANCER](_video_processing.md#video_processing_type_detail_enhancer) | Instance for detail enhancement during video processing.| 
| const char \* [VIDEO_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](_video_processing.md#video_detail_enhancer_parameter_key_quality_level) | Pointer to the quality level of video detail enhancement.| 
