# OH_AudioSuite_DownloadStatusInfo
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AudioSuite_DownloadStatusInfo {...} OH_AudioSuite_DownloadStatusInfo
```

## Overview

This struct defines the download status information structure.

**Since:** 26.0.0

**Related module**: [OHAudioSuite](capi-ohaudiosuite.md)

**Header file**: [native_audio_suite_download_manager.h](capi-native-audio-suite-download-manager-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char featureName[256] | Cloud file name.<br>**Since:** 26.0.0|
| int32_t downloadStatus | Current download status of the cloud file.<br>**Since:** 26.0.0|
| int64_t size | Cloud file size.<br>**Since:** 26.0.0|
| char installPath[256] | Local installation path of the cloud file.<br>**Since:** 26.0.0|
| int32_t progress | Current download progress of the cloud file, ranging from 0 to 100.<br>**Since:** 26.0.0|
| int32_t errorCode | Error code.<br>**Since:** 26.0.0|
