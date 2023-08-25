# OH_AVScreenCaptureCallback


## Overview

The **OH_AVScreenCaptureCallback** struct defines all the asynchronous callback function pointers of an **OH_AVScreenCapture** instance. To ensure the normal running of **OH_AVScreenCapture**, you must register the instance of this struct with the **OH_AVScreenCapture** instance and process the information reported by the callback functions.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**

10

**Related Modules**

[AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| **onError** | [OH_AVScreenCaptureOnError](_a_v_screen_capture.md#oh_avscreencaptureonerror) | 
| **onAudioBufferAvailable** | [OH_AVScreenCaptureOnAudioBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonaudiobufferavailable) | 
| **onVideoBufferAvailable** | [OH_AVScreenCaptureOnVideoBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonvideobufferavailable) | 
