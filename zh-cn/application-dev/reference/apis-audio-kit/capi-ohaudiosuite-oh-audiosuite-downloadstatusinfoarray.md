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

## 概述

定义下载状态信息数组结构。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**相关模块：** [OHAudioSuite](capi-ohaudiosuite.md)

**所在头文件：** [native_audio_suite_download_manager.h](capi-native-audio-suite-download-manager-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t size | 下载状态信息指针数组大小。<br>**起始版本：** 26.0.0 |
| [OH_AudioSuite_DownloadStatusInfo](capi-ohaudiosuite-oh-audiosuite-downloadstatusinfo.md) **downloadStatusInfo | 下载状态信息指针数组。<br>**起始版本：** 26.0.0 |


