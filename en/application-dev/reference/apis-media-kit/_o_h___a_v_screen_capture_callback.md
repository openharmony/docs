# OH_AVScreenCaptureCallback


## Overview

The OH_AVScreenCaptureCallback struct describes all the asynchronous callback function pointers of an **OH_AVScreenCapture** instance. To ensure the normal running of **OH_AVScreenCapture**, you must register the instance of this struct with the **OH_AVScreenCapture** instance and process the information reported by the callback functions.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Deprecated from**: 12

**Substitute APIs**: [OH_AVScreenCapture_OnError](_a_v_screen_capture.md#oh_avscreencapture_onerror) and [OH_AVScreenCapture_OnBufferAvailable](_a_v_screen_capture.md#oh_avscreencapture_onbufferavailable)

**Related module**: [AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_AVScreenCaptureOnError](_a_v_screen_capture.md#oh_avscreencaptureonerror) [onError](#onerror) | Pointer to a callback function that is called when an error occurs during the running of an **OH_AVScreenCapture** instance. For details, see [OH_AVScreenCaptureOnError](_a_v_screen_capture.md#oh_avscreencaptureonerror).| 
| [OH_AVScreenCaptureOnAudioBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonaudiobufferavailable) [onAudioBufferAvailable](#onaudiobufferavailable) | Pointer to a callback function that is called when an audio buffer is available during the running of an **OH_AVScreenCapture** instance. For details, see [OH_AVScreenCaptureOnAudioBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonaudiobufferavailable).| 
| [OH_AVScreenCaptureOnVideoBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonvideobufferavailable) [onVideoBufferAvailable](#onvideobufferavailable) | Pointer to a callback function that is called when a video buffer is available during the running of an **OH_AVScreenCapture** instance. For details, see [OH_AVScreenCaptureOnVideoBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonvideobufferavailable).| 


## Member Variable Description


### onAudioBufferAvailable

```
OH_AVScreenCaptureOnAudioBufferAvailable OH_AVScreenCaptureCallback::onAudioBufferAvailable
```

Pointer to a callback function that is called when an audio buffer is available during the running of an **OH_AVScreenCapture** instance. For details, see [OH_AVScreenCaptureOnAudioBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonaudiobufferavailable).

**Since**: 10

**Deprecated from**: 12

**Substitute API**: [OH_AVScreenCapture_OnBufferAvailable](_a_v_screen_capture.md#oh_avscreencapture_onbufferavailable)


### onError

```
OH_AVScreenCaptureOnError OH_AVScreenCaptureCallback::onError
```

Pointer to a callback function that is called when an error occurs during the running of an **OH_AVScreenCapture** instance. For details, see [OH_AVScreenCaptureOnError](_a_v_screen_capture.md#oh_avscreencaptureonerror).

**Since**: 10

**Deprecated from**: 12

**Substitute API**: [OH_AVScreenCapture_OnError](_a_v_screen_capture.md#oh_avscreencapture_onerror)


### onVideoBufferAvailable

```
OH_AVScreenCaptureOnVideoBufferAvailable OH_AVScreenCaptureCallback::onVideoBufferAvailable
```

Pointer to a callback function that is called when a video buffer is available during the running of an **OH_AVScreenCapture** instance. For details, see [OH_AVScreenCaptureOnVideoBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonvideobufferavailable).

**Since**: 10

**Deprecated from**: 12

**Substitute API**: [OH_AVScreenCapture_OnBufferAvailable](_a_v_screen_capture.md#oh_avscreencapture_onbufferavailable)
