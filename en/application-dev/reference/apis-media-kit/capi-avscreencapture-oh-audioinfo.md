# OH_AudioInfo
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zzs_911-->
<!--Designer: @stupig001-->
<!--Tester: @xdlinc-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the audio information.

To perform both external capture (using microphones) and internal capture, **audioSampleRate** and **audioChannels** must be the same for both audio channels.

**Since**: 10

**Related module**: [AVScreenCapture](capi-avscreencapture.md)

**Header file**: [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [OH_AudioCaptureInfo](capi-avscreencapture-oh-audiocaptureinfo.md) micCapInfo | External audio capture information.|
| [OH_AudioCaptureInfo](capi-avscreencapture-oh-audiocaptureinfo.md) innerCapInfo | Internal audio capture information.|
| [OH_AudioEncInfo](capi-avscreencapture-oh-audioencinfo.md) audioEncInfo | Audio encoding information, which is not required for raw streams.|
