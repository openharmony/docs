# OH_AudioSuite_DownloadStatusInfoArray
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AudioSuite_DownloadStatusInfoArray {...} OH_AudioSuite_DownloadStatusInfoArray
```

## Overview

This struct defines the download status information array structure.

**Since:** 26.0.0

**Related module**: [OHAudioSuite](capi-ohaudiosuite.md)

**Header file**: [native_audio_suite_download_manager.h](capi-native-audio-suite-download-manager-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t size | Size of the download status information pointer array.<br>**Since:** 26.0.0|
| [OH_AudioSuite_DownloadStatusInfo](capi-ohaudiosuite-oh-audiosuite-downloadstatusinfo.md) **downloadStatusInfo | Download status information pointer array.<br>**Since:** 26.0.0|
