# OH_AudioDeviceDescriptorArray
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes an array of audio device descriptors.

**Since**: 12

**Related module**: [OHAudio](capi-ohaudio.md)

**Header file**: [native_audio_device_base.h](capi-native-audio-device-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t size | Size of the audio device descriptor array.|
| [OH_AudioDeviceDescriptor](capi-ohaudio-oh-audiodevicedescriptor.md)** descriptors | Double pointer to the audio device descriptors in the array.|
