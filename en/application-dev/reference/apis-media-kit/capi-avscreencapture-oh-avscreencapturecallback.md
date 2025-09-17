# OH_AVScreenCaptureCallback
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zzs_911-->
<!--Designer: @stupig001-->
<!--Tester: @xdlinc-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes all the asynchronous callback function pointers of an OH_AVScreenCapture instance. To ensure the normal running of OH_AVScreenCapture, you must register the instance of this struct with the OH_AVScreenCapture instance and process the information reported by the callback functions.

From API version 12, you are advised to use [OH_AVScreenCapture_OnError](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onerror) and [OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable) instead.

**Since**: 10

**Related module**: [AVScreenCapture](capi-avscreencapture.md)

**Header file**: [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [OH_AVScreenCaptureOnError](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonerror) onError | Callback function invoked when an error occurs during the running of an OH_AVScreenCapture instance.<br>Since API version 12, you are advised to use [OH_AVScreenCapture_OnError](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onerror) instead.|
| [OH_AVScreenCaptureOnAudioBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonaudiobufferavailable) onAudioBufferAvailable | Callback function invoked when an audio buffer is available during the running of an OH_AVScreenCapture instance.<br>Since API version 12, you are advised to use [OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable) instead.|
| [OH_AVScreenCaptureOnVideoBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonvideobufferavailable) onVideoBufferAvailable | Callback function invoked when a video buffer is available during the running of an OH_AVScreenCapture instance.<br>Since API version 12, you are advised to use [OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable) instead.|
