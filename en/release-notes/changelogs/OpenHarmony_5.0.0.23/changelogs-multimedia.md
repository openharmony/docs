# Multimedia Subsystem Changelog

## c1.multimedia.1 Internal Audio Recording APIs in ohos.multimedia.audio Are Deprecated
**Access Level**

Public

**Reason for Change**

The internal audio recording APIs of the audio framework are incorporated to the screen capture module of the playback framework.

**Change Impact**

This change is a non-compatible change. Applications developed on API version 10 or 11 can still use internal audio recording APIs. However, applications developed on API version 12 can no longer obtain valid data using these deprecated APIs. Instead, they must use the screen capture module of Media Kit.

**Change Since**

OpenHarmony SDK 5.0.0.23

**Deprecated APIs**

1. Member variable **playbackCaptureConfig?: AudioPlaybackCaptureConfig;** in **AudioCapturerOptions**
2. Member **filterOptions: CaptureFilterOptions;** in **AudioPlaybackCaptureConfig** and **AudioPlaybackCaptureConfig**
3. Member **usages: Array\<StreamUsage\>** in **CaptureFilterOptions** and **CaptureFilterOptions**

**Adaptation Guide**

For details, see [AVScreenCapture](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-media-kit/_a_v_screen_capture.md#oh_audiocapturesourcetype-1) of Media Kit.


## c1.multimedia.2 Internal Audio Recording APIs in native_audiostream_base.h Are Deprecated
**Access Level**

Public

**Reason for Change**

The internal audio recording APIs of the audio framework are incorporated to the screen capture module of the playback framework.

**Change Impact**

This change is a non-compatible change. Applications developed on API version 10 or 11 can still use internal audio recording APIs. However, applications developed on API version 12 can no longer obtain valid data using these deprecated APIs. Instead, they must use the screen capture module of Media Kit.

**Change Since**

OpenHarmony SDK 5.0.0.23

**Deprecated APIs**

Enumerated value **AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE** of **OH_AudioStream_SourceType**.

**Adaptation Guide**

For details, see [AVScreenCapture](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-media-kit/_a_v_screen_capture.md#oh_audiocapturesourcetype-1) of Media Kit.
