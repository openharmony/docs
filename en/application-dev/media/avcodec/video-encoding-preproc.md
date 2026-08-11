# Encoding with Preprocessing

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650-->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=45526eba67080b876eb51af31a33be43ae26f701 translatedAt=2026-07-13T13:19:20.788Z pushedAt=2026-07-21T12:11:27.919Z -->

Starting from API version 26.0.0, video encoders support preprocessing, including downsampling, cropping, and frame dropping.

## Overview

Encoding preprocessing refers to the preprocessing capabilities executed by the video encoder before input frames enter the encoding pipeline. The primary encoder created via [OH_VideoEncoder_CreatePrimaryWithPreproc](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_createprimarywithpreproc) supports the following three preprocessing features.

| Feature | Description | Typical Scenario |
|------|------|----------|
| Downsampling | Scales high-resolution frames to a lower resolution before feeding them into the encoder. | Low-resolution encoding output. |
| Cropping | Extracts a specified rectangular region from the original frame for encoding. | Region-of-interest (ROI) encoding and close-up views. |
| Frame dropping | Selectively drops input frames based on the target frame rate. | Bandwidth reduction and adaptive bitrate (ABR). |

**Mutual exclusion rule**: Downsampling parameters and cropping parameters **cannot be used simultaneously**. Frame dropping can be **combined with** either downsampling or cropping.

### When to Use

**Scenario 1: Low-Resolution Encoding Output**

Use downsampling to scale high-resolution input frames before encoding, producing a lower-resolution output stream.

**Scenario 2: ROI Encoding**

- Use cropping to encode only a specified ROI from a high-resolution camera frame.

**Scenario 3: ABR**

- Normal network conditions: Disable frame dropping or use a low frame-dropping rate to maintain image quality.

- Network congestion: Increase the frame-dropping rate dynamically by calling `SetParameter` to reduce the output frame rate and save bandwidth.

- Network recovery: Set the frame-dropping target to `0.00` to disable frame dropping.

### Constraints

**Basic Constraints**

| Item | Description |
|--------|------|
| Supported MIME types | Same as the support scope of standard video encoders. Available via `OH_AVCodec_GetCapability` to query whether encoding of the specified MIME type is supported. |
| Creation method | Must be created via `OH_VideoEncoder_CreatePrimaryWithPreproc`. |
| Data path | **Only Surface asynchronous mode is supported.** Both Buffer mode and synchronous mode are not supported (returning `AV_ERR_OPERATE_NOT_PERMIT`). |
| Per-frame parameters | The `RegisterParameterCallback` API is not supported (returning `AV_ERR_OPERATE_NOT_PERMIT`). |

**Downsampling Constraints**

| No. | Constraint Rule |
|------|----------|
| 1 | Paired configuration: The target width and target height for downsampling must be configured or updated together. If only one is specified, `Configure` or `SetParameter` returns `AV_ERR_INVALID_VAL`. |
| 2 | Disabling downsampling: Downsampling is disabled when both the target width and target height are set to valid zero values. |
| 3 | Valid range: Downsampling is enabled when both the target width and target height are within the supported ranges. You are advised to call `OH_AVCapability_IsVideoSizeSupported` to check whether the target size is supported. |
| 4 | Out-of-range values: If either the target width or target height is outside the supported range, `Configure` or `SetParameter` returns `AV_ERR_INVALID_VAL`. |
| 5 | Mutual exclusivity with cropping: Downsampling cannot be used together with the cropping parameters (`CROP_LEFT`, `CROP_TOP`, `CROP_RIGHT`, and `CROP_BOTTOM`). If both downsampling and cropping parameters are specified, `AV_ERR_INVALID_VAL` is returned. |

**Cropping Constraints**

Coordinate system description:

- `(left, top)` is the coordinate of the upper-left corner of the cropping rectangle.

- `(right, bottom)` is the coordinate of the lower-right corner of the cropping rectangle.

- Row and column indexes start from **0**.

- **Cropping area width = right - left + 1**

- **Cropping area height = bottom - top + 1**

| No. | Constraint Rule |
|------|----------|
| 1 | Complete configuration: `left`, `top`, `right`, and `bottom` must all be configured together. If only some of these parameters are specified, `AV_ERR_INVALID_VAL` is returned. |
| 2 | Disabling cropping: Cropping is disabled when `left`, `top`, `right`, and `bottom` are all set to `0`. |
| 3 | Valid range: Cropping is enabled when the width and height of the cropped region are within the supported ranges. You are advised to call `OH_AVCapability_IsVideoSizeSupported` to check whether the cropped size is supported. |
| 4 | Out-of-range values: If the width or height of the cropped region is outside the supported range, `AV_ERR_INVALID_VAL` is returned. |
| 5 | Mutual exclusivity with downsampling: Cropping cannot be used together with the downsampling parameters (`DOWNSAMPLING_WIDTH` and `DOWNSAMPLING_HEIGHT`). If both cropping and downsampling parameters are specified, `AV_ERR_INVALID_VAL` is returned. |
| 6 | Behavior: When cropping is enabled, the encoder encodes only the specified cropped region of each input frame. Content outside the cropped region is discarded. |

**Frame Dropping Constraints**

| No. | Constraint Rule |
|------|----------|
| 1 | Prerequisite: The caller must have set the original frame rate (`OH_MD_KEY_FRAME_RATE`). |
| 2 | Precision requirement: The value precision is retained to **2** decimal places (using **rounding**). |
| 3 | Value `0.00`: The frame dropping feature is disabled. |
| 4 | Valid positive value: When set to a positive number greater than 0 and less than the original frame rate, frame dropping is performed at the configured frame rate. |
| 5 | Invalid value: When set to a negative number or a value greater than or equal to the original frame rate, `AV_ERR_INVALID_VAL` is returned. |
| 6 | Combinability: Can be used **simultaneously** with the downsampling parameter. |
| 7 | Combinability: Can be used **simultaneously** with the cropping parameter.|

**API Availability**

The following table describes the availability of APIs for encoders created by calling `OH_VideoEncoder_CreatePrimaryWithPreproc`.

| API | availability | Description |
|------|:--------:|------|
| [OH_VideoEncoder_RegisterCallback](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_registercallback) | √ | Supported. |
| [OH_VideoEncoder_RegisterParameterCallback](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_registerparametercallback) | × | Per-frame parameter configuration is not supported. Returns `AV_ERR_OPERATE_NOT_PERMIT`. |
| [OH_VideoEncoder_PushInputParameter](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_pushinputparameter) | × | Per-frame parameter configuration is not supported. Returns `AV_ERR_OPERATE_NOT_PERMIT`. |
| [OH_VideoEncoder_Configure](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_configure) | √ | Supported. Preprocessing parameters can be configured. |
| [OH_VideoEncoder_GetSurface](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getsurface) | √ | Supported. |
| [OH_VideoEncoder_Prepare](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_prepare) | √ | Supported. Prepares internal resources. |
| [OH_VideoEncoder_Start](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_start) | √ | Supported. |
| [OH_VideoEncoder_Stop](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_stop) | √ | Supported. |
| [OH_VideoEncoder_Flush](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_flush) | √ | Supported. |
| [OH_VideoEncoder_Reset](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_reset) | √ | Supported. Resets to the `Initialized` state. |
| [OH_VideoEncoder_SetParameter](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_setparameter) | √ | Supported. Dynamically adjusts preprocessing and other parameters at runtime. |
| [OH_VideoEncoder_NotifyEndOfStream](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_notifyendofstream) | √ | Supported. Notifies the encoder of EOS information. |
| [OH_VideoEncoder_FreeOutputBuffer](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_freeoutputbuffer) | √ | Supported. |
| [OH_VideoEncoder_GetInputDescription](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getinputdescription) | √ | Supported. Preprocessing metadata is included. |
| [OH_VideoEncoder_GetOutputDescription](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getoutputdescription) | √ | Supported. |
| [OH_VideoEncoder_IsValid](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_isvalid) | √ | Supported. |
| [OH_VideoEncoder_Destroy](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_destroy) | √ | Supported. Destroys the encoder instance. |
| [OH_VideoEncoder_PushInputData](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_pushinputdata)  | × | Buffer mode is not supported. |
| [OH_VideoEncoder_PushInputBuffer](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_pushinputbuffer) | × | Buffer mode is not supported. |
| [OH_VideoEncoder_QueryInputBuffer](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_queryinputbuffer) | × | Synchronous mode is not supported. |
| [OH_VideoEncoder_QueryOutputBuffer](../../reference/apis-avcodec-kit/capi-native-avcodec-videoencoder-h.md#oh_videoencoder_queryoutputbuffer) | × | Synchronous mode is not supported. |

## How to Develop

The workflow for encoding with pre-processing is the same as that for a regular encoder. The main differences are the encoder creation method, pre-processing parameter configuration, and dynamic parameter updates. This section describes only these differences. For the complete encoding workflow, see [Surface Mode](video-encoding.md#surface-mode) in video encoding.

### Creating an Encoder with Preprocessing Support

Before creating an encoder with preprocessing support, you are advised to check whether the current encoder supports the required preprocessing features through the capability query API:

```c++
const char *mime = OH_AVCODEC_MIMETYPE_VIDEO_AVC;

OH_AVCapability *capability = OH_AVCodec_GetCapability(mime, true);
if (capability == nullptr) {
    return -1; // Failed to obtain capability, possibly due to an unsupported MIME type.
}

// Query whether downsampling preprocessing is supported.
bool supportDownsampling = OH_AVCapability_IsFeatureSupported(capability,
    VIDEO_ENCODER_PREPROC_DOWNSAMPLING);

// Query whether cropping preprocessing is supported.
bool supportCrop = OH_AVCapability_IsFeatureSupported(capability,
    VIDEO_ENCODER_PREPROC_CROP);

OH_AVCodec *encoder = nullptr;
OH_AVErrCode ret = OH_VideoEncoder_CreatePrimaryWithPreproc(mime, &encoder);
if (ret != AV_ERR_OK || encoder == nullptr) {
    // Handle the exception.
    return -1;
}
```

### Registering Callbacks

Register callbacks by referring to step 3 (call `OH_VideoEncoder_RegisterCallback()` to register the callback functions) in [Surface Mode](video-encoding.md#surface-mode) of video encoding.

### Setting Encoding and Preprocessing Parameters

Set encoding parameters by referring to step 5 (call `OH_VideoEncoder_Configure()` to configure the encoder) in [Surface Mode](video-encoding.md#surface-mode) of video encoding. The following focuses on the setting of basic parameters and preprocessing parameters.

```c++
OH_AVFormat *format = OH_AVFormat_Create();

// Set basic encoding parameters (mandatory).
OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1920);         // Width of the input image.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1080);        // Height of the input image.
OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 30.0); // Original frame rate (prerequisite for the frame dropping feature).

// Preprocessing parameters (configure as needed; verify feature support via IsFeatureSupported before configuration).
// Option A: Downsampling example.
// The following example encodes a 1920 x 1080 video after scaling it down to 640 x 360.
// Note: width and height must be specified in pairs.
if (supportDownsampling) {
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_WIDTH, 640); // Downsampling target width.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_HEIGHT, 360); // Downsampling target height.
}

// Option B: Cropping example.
// The following example crops the central 1280 x 720 region from 1920 x 1080.
// Note: left/top/right/bottom must all appear together.
// Downsampling and cropping are mutually exclusive and cannot be used simultaneously.
// Example: left = 320, top = 180, right = 1599, bottom = 899; corresponding to: width = 1599 - 320 + 1 = 1280, height = 899 - 180 + 1 = 720.
// if (supportCrop) {
//     OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_LEFT, 320);
//     OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_TOP, 180);
//     OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_RIGHT, 1599);
//     OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_CROP_BOTTOM, 899);
// }

// Option C: Frame dropping example.
// The following example shows reducing from 30 fps to 15 fps (can be used alone or combined with Downsampling/Cropping).
// OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_VIDEO_ENCODER_PREPROC_DROP_TO_FRAME_RATE, 15.0);

// Execute the configuration.
OH_AVErrCode ret = OH_VideoEncoder_Configure(encoder, format);
if (ret != AV_ERR_OK) {
    // Handle the error.
    OH_AVFormat_Destroy(format);
    return -1;
}
OH_AVFormat_Destroy(format);
```

### Obtaining the Surface

```c++
// Key: The Surface can only be obtained through the primary encoder handle.
OHNativeWindow *window = nullptr;
OH_AVErrCode ret = OH_VideoEncoder_GetSurface(encoder, &window);
if (ret != AV_ERR_OK || window == nullptr) {
    // Handle the exception.
    return -1;
}

// Bind the window to a data source such as Camera or XComponent.
// For example: cameraManager->SetPreviewSurface(window)
//       nativeXComponent->SetSurface(window)
```

> **Key rules:**
> - Only the primary encoder can call `GetSurface`. Calling it on the secondary encoder will return `AV_ERR_OPERATE_NOT_PERMIT`.
> - For the one-input dual-output scenario, the Surface needs to be obtained only once (the primary and secondary encoders share the same input source).

### Preparing, Starting, and Writing Encoded Images

For details, see steps 7, 8, and 10 in [Surface Mode](video-encoding.md#surface-mode) of video encoding.

### (Optional) Dynamically Adjusting at Runtime

Dynamically modify preprocessing parameters at runtime via `SetParameter`:

```c++
// Dynamically adjust the target frame rate for frame dropping (for example, in response to network status changes).
// When network congestion occurs, aggressive frame dropping can be applied, e.g.: AdjustDropFrameRate(encoder, 10.0);
// When the network recovers, frame dropping can be canceled: AdjustDropFrameRate(encoder, 0.0);
void AdjustDropFrameRate(OH_AVCodec *enc, double targetFps)
{
    OH_AVFormat *param = OH_AVFormat_Create();
    if (targetFps > 0) {
        OH_AVFormat_SetDoubleValue(param,
            OH_MD_KEY_VIDEO_ENCODER_PREPROC_DROP_TO_FRAME_RATE, targetFps);
    } else {
        // Set to 0.00 to disable the frame dropping feature.
        OH_AVFormat_SetDoubleValue(param,
            OH_MD_KEY_VIDEO_ENCODER_PREPROC_DROP_TO_FRAME_RATE, 0.0);
    }
    OH_VideoEncoder_SetParameter(enc, param);
    OH_AVFormat_Destroy(param);
}

// Dynamically adjust the downsampling target dimensions.
void AdjustDownsampling(OH_AVCodec *enc, int newWidth, int newHeight)
{
    OH_AVFormat *param = OH_AVFormat_Create();
    OH_AVFormat_SetIntValue(param, OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_WIDTH, newWidth);
    OH_AVFormat_SetIntValue(param, OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_HEIGHT, newHeight);
    OH_VideoEncoder_SetParameter(enc, param);
    OH_AVFormat_Destroy(param);
}
```

Other encoder parameters can also be updated dynamically. For details, see step 9 in [Surface Mode](video-encoding.md#surface-mode) of video encoding.

### Notifying End of Stream, Releasing Output Buffers, and Destroying the Encoder

The steps are the same as those for a regular encoder. For details, see steps 12, 13, and 17 in [Surface Mode](video-encoding.md#surface-mode) of video encoding.

## Query via GetInputDescription

After preprocessing is enabled, you can query the actual input information and configuration parameters after preprocessing via `GetInputDescription`:

```c++
OH_AVFormat *inputDesc = OH_VideoEncoder_GetInputDescription(encoder);
if (inputDesc != nullptr) {
    int32_t originWidth = 0, originHeight = 0;
    OH_AVFormat_GetIntValue(inputDesc, OH_MD_KEY_WIDTH, &originWidth);
    OH_AVFormat_GetIntValue(inputDesc, OH_MD_KEY_HEIGHT, &originHeight);

    // Query the currently effective preprocessing configuration parameters.
    int32_t dsWidth = 0;
    if (OH_AVFormat_GetIntValue(inputDesc,
        OH_MD_KEY_VIDEO_ENCODER_PREPROC_DOWNSAMPLING_WIDTH, &dsWidth)) {
    }
}
```