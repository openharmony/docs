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

## 概述

定义下载状态信息结构。

**起始版本：** 26.0.0

**相关模块：** [OHAudioSuite](capi-ohaudiosuite.md)

**所在头文件：** [native_audio_suite_download_manager.h](capi-native-audio-suite-download-manager-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char featureName[256] | 云端文件名称。<br>**起始版本：** 26.0.0 |
| int32_t downloadStatus | 云端文件当前下载状态。<br>**起始版本：** 26.0.0 |
| int64_t size | 云端文件大小。<br>**起始版本：** 26.0.0 |
| char installPath[256] | 云端文件本地安装路径。<br>**起始版本：** 26.0.0 |
| int32_t progress | 云端文件当前下载进度[0-100]。<br>**起始版本：** 26.0.0 |
| int32_t errorCode | 错误码。<br>**起始版本：** 26.0.0 |


