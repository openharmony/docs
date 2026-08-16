# Using AVScreenCapture in Custom Scenarios

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zzs_911-->
<!--Designer: @stupig001-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=448fbb624ecca901e0e0d000496a23c1a0b2fe39 translatedAt=2026-08-11T01:50:51.350Z pushedAt=2026-08-11T12:18:41.555Z -->

AVScreenCapture enables applications to implement scenario-based custom configurations. Refer to the guidelines below for specific setup instructions.

## Setting Screen Capture Strategies

### Cellular Call Handling

Starting from API version 20, cellular call handling is supported.

Call [OH_AVScreenCapture_StrategyForKeepCaptureDuringCall](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_strategyforkeepcaptureduringcall) to set whether screen capture continues during cellular calls.

<!-- @[screenCapture_buffer_strategy_keepCaptureDuringCall](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
OH_AVScreenCapture_CaptureStrategy* strategy = OH_AVScreenCapture_CreateCaptureStrategy();
OH_AVScreenCapture_StrategyForKeepCaptureDuringCall(strategy, true);
OH_AVScreenCapture_SetCaptureStrategy(capture, strategy);
OH_AVScreenCapture_ReleaseCaptureStrategy(strategy);
```

### B-Frame Encoding Control

Starting from API version 20, you can set whether to use B-frame encoding.

Call [OH_AVScreenCapture_StrategyForBFramesEncoding](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_strategyforbframesencoding) to enable B-frame encoding, which helps reduce the size of captured files.

<!-- @[screenCapture_buffer_strategy_BFramesEncoding](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
OH_AVScreenCapture_CaptureStrategy* strategy = OH_AVScreenCapture_CreateCaptureStrategy();
OH_AVScreenCapture_StrategyForBFramesEncoding(strategy, true);
OH_AVScreenCapture_SetCaptureStrategy(capture, strategy);
OH_AVScreenCapture_ReleaseCaptureStrategy(strategy);
```

### Screen Capture Picker Control

Starting from API version 20, screen capture pickers can be configured on PC and 2-in-1 devices.

Starting from API version 23, screen capture pickers can be configured on phones and tablets.

Call [OH_AVScreenCapture_StrategyForPickerPopUp](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_strategyforpickerpopup) to set whether to display the screen capture picker.

<!-- @[screenCapture_buffer_strategy_pickerPopUp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// Create a CaptureStrategy object.
OH_AVScreenCapture_CaptureStrategy* strategy = OH_AVScreenCapture_CreateCaptureStrategy();

// Set whether to display the screen capture Picker.
// Set to true, indicating that the Picker is displayed uniformly after screen recording starts.
OH_AVScreenCapture_StrategyForPickerPopUp(strategy, true);

// Set the CaptureStrategy to the AVScreenCapture instance.
OH_AVScreenCapture_SetCaptureStrategy(capture, strategy);

// Release the CaptureStrategy object.
OH_AVScreenCapture_ReleaseCaptureStrategy(strategy);
```

## Setting Rotation Adaptation

Starting from API version 20, you can set rotation adaptation.

Call [OH_AVScreenCapture_StrategyForCanvasFollowRotation](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_strategyforcanvasfollowrotation) to set whether screen capture automatically follows screen rotation.

After this API is called, you do not need to call [OH_AVScreenCapture_ResizeCanvas](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_resizecanvas) to manually change the resolution.

<!-- @[screenCapture_buffer_strategy_canvasFollowRotation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
OH_AVScreenCapture_CaptureStrategy* strategy = OH_AVScreenCapture_CreateCaptureStrategy();
// Set StrategyForCanvasFollowRotation to true to enable automatic rotation following. This will automatically adjust the virtual screen size after a rotation, ensuring the output follows the rotation promptly.
OH_AVScreenCapture_StrategyForCanvasFollowRotation(strategy, true);
OH_AVScreenCapture_SetCaptureStrategy(capture, strategy);
OH_AVScreenCapture_ReleaseCaptureStrategy(strategy);
```

## Setting Microphone Control

Call [OH_AVScreenCapture_SetMicrophoneEnabled](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_setmicrophoneenabled) to enable or disable the microphone during screen capture. The microphone is enabled by default.

> **NOTE**
> To use the microphone during screen capture, you must:
>
> - Configure the ohos.permission.MICROPHONE permission. For details, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).
> - Apply for a continuous task. For details, see [Continuous Task](../../task-management/continuous-task.md).

<!-- @[screenCapture_buffer_strategy_setMicrophoneEnabled](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
bool isMic = true;
OH_AVScreenCapture_SetMicrophoneEnabled(g_avCapture, isMic);
```

## Setting Privacy Mode

Starting from API version 20, you can use [OH_AVScreenCapture_StrategyForPrivacyMaskMode](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_strategyforprivacymaskmode) to set the privacy window mask mode for screen recording.

<!-- @[screenCapture_buffer_strategy_privacyMaskMode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
// Set value to 0 to indicate full-screen masking mode. Set value to 1 to indicate window masking mode. The default is full-screen masking mode. You can select an appropriate value based on actual requirements.
int value = PRIVACY_MASK_MODE_FULL_SCREEN;
OH_AVScreenCapture_CaptureStrategy* strategy = OH_AVScreenCapture_CreateCaptureStrategy();
OH_AVScreenCapture_StrategyForPrivacyMaskMode(strategy, value);
OH_AVScreenCapture_SetCaptureStrategy(capture, strategy);
OH_AVScreenCapture_ReleaseCaptureStrategy(strategy);
```

Starting from API version 12, you can call [OH_AVScreenCapture_SkipPrivacyMode](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_skipprivacymode) to set windows exempt from privacy masking during screen capture. Currently, you must pass all privacy child window and main window IDs. Pass an empty array to cancel privacy mode exemptions.

<!-- @[screenCapture_buffer_skipPrivacyMode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
std::vector<int> windowIdsSkipPrivacy = {};
OH_AVScreenCapture_SkipPrivacyMode(capture, windowIdsSkipPrivacy.empty() ? nullptr : &windowIdsSkipPrivacy[0],
    static_cast<int32_t>(windowIdsSkipPrivacy.size()));
```

## Setting the Capture Area

Starting from API version 20, you can configure the capture area.

You can set the area coordinates and size as needed. Call [OH_AVScreenCapture_SetCaptureArea](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_setcapturearea) to set the area to capture. The following example creates a rectangular area 100 px wide and 100 px high, starting from (0, 0). This API can be called both before and after screen recording starts.

<!-- @[screenCapture_buffer_setCaptureArea](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
OH_Rect* region = new OH_Rect;
region->x = 0;
region->y = 0;
region->width = CAPTURE_REGION_SIZE;
region->height = CAPTURE_REGION_SIZE;
uint64_t regionDisplayId = 0; // Pass in the screen ID where the rectangular region is located.
OH_AVScreenCapture_SetCaptureArea(capture, regionDisplayId, region);
delete region;
region = nullptr;
```

## Setting Cursor Visibility

Starting from API version 15, you can set cursor visibility during capture.

Call [OH_AVScreenCapture_ShowCursor](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_showcursor) to set cursor visibility during capture. This API can be called both before and after capture starts.

<!-- @[screenCapture_buffer_showCursor](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
OH_AVScreenCapture_ShowCursor(g_avCapture, false);
```

## Setting the Maximum Frame Rate

Starting from API version 14, you can set the maximum frame rate.

Call [OH_AVScreenCapture_SetMaxVideoFrameRate](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_setmaxvideoframerate) to set the maximum frame rate for screen capture. This API must be called after capture starts.

<!-- @[screenCapture_buffer_setMaxVideoFrameRate](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
OH_AVScreenCapture_SetMaxVideoFrameRate(g_avCapture, CAPTURE_VIDEO_FRAME_RATE);
```

## Setting Screen Resolution

Use [OH_AVScreenCapture_ResizeCanvas](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_resizecanvas) to adjust the screen capture resolution. This API must be called after screen capture starts. The resolution is subject to range limits. The maximum video width and height must not exceed the ranges defined by [OH_AVCapability_GetVideoWidthRange](../../reference/apis-avcodec-kit/capi-native-avcapability-h.md#oh_avcapability_getvideowidthrange) and [OH_AVCapability_GetVideoHeightRange](../../reference/apis-avcodec-kit/capi-native-avcapability-h.md#oh_avcapability_getvideoheightrange).

<!-- @[screenCapture_buffer_resizeCanvas](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

``` C++
OH_AVScreenCapture_ResizeCanvas(g_avCapture, CANVAS_RESIZE_WIDTH, CANVAS_RESIZE_HEIGHT);
```

## Setting Content Filtering

Filter specific audio and windows during screen capture.

Call [OH_AVScreenCapture_ContentFilter_AddAudioContent](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_contentfilter_addaudiocontent) to exclude specific audio types, including system sounds and the application's own audio.

Call [OH_AVScreenCapture_ContentFilter_AddWindowContent](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_contentfilter_addwindowcontent) to exclude specific windows by their window IDs.

<!-- @[screenCapture_buffer_excludeContent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
OH_AVScreenCapture_ContentFilter *contentFilter = OH_AVScreenCapture_CreateContentFilter();
// Filter notification sounds.
OH_AVScreenCapture_ContentFilter_AddAudioContent(contentFilter, OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO);
// If a specific window needs to be excluded, fill the window ID array first.
std::vector<int> windowIdsExclude = {};
OH_AVScreenCapture_ContentFilter_AddWindowContent(contentFilter, windowIdsExclude.empty() ?
    nullptr : &windowIdsExclude[0], static_cast<int32_t>(windowIdsExclude.size()));

OH_AVScreenCapture_ExcludeContent(capture, contentFilter);
OH_AVScreenCapture_ReleaseContentFilter(contentFilter);
contentFilter = nullptr;
```

## Additional Resources

- API reference: For details, see [native_avscreen_capture.h](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md).

- Sample project: This sample demonstrates screen capture using the AVScreenCapture component APIs. For details, see [Screen Capture](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample).