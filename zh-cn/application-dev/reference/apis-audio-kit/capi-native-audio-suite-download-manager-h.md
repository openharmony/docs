# native_audio_suite_download_manager.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明音频下载管理器相关接口。

**引用文件：** <ohaudiosuite/native_audio_suite_download_manager.h>

**库：** libohaudiosuite.so

**系统能力：** SystemCapability.Multimedia.Audio.SuiteEngine

**起始版本：** 26.0.0

**相关模块：** [OHAudioSuite](capi-ohaudiosuite.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioSuite_DownloadStatusInfo](capi-ohaudiosuite-oh-audiosuite-downloadstatusinfo.md) | OH_AudioSuite_DownloadStatusInfo | 定义下载状态信息结构。 |
| [OH_AudioSuite_DownloadStatusInfoArray](capi-ohaudiosuite-oh-audiosuite-downloadstatusinfoarray.md) | OH_AudioSuite_DownloadStatusInfoArray | 定义下载状态信息数组结构。 |
| [OH_AudioSuite_DownloadManagerStruct](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) | OH_AudioSuite_DownloadManager | 声明音频下载管理器。<br> 音频下载管理器的句柄用于执行下载相关功能。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_AudioSuite_DownloadCallback)(OH_AudioSuite_DownloadStatusInfoArray *downloadStatusInfoArray)](#oh_audiosuite_downloadcallback) | OH_AudioSuite_DownloadCallback | 下载状态更新的回调函数。 |
| [int32_t OH_AudioSuite_GetDownloadManager(OH_AudioSuite_DownloadManager **downloadManager)](#oh_audiosuite_getdownloadmanager) | - | 获取音频下载管理器句柄，由OH_AudioSuite_GetDownloadManager获取，用于后续调用下载相关接口时标识操作目标。 |
| [int32_t OH_AudioSuite_RegisterDownloadCallback(OH_AudioSuite_DownloadManager *downloadManager, const OH_AudioSuite_DownloadCallback *callback)](#oh_audiosuite_registerdownloadcallback) | - | 注册下载状态回调。 |
| [int32_t OH_AudioSuite_UnregisterDownloadCallback(OH_AudioSuite_DownloadManager *downloadManager, const OH_AudioSuite_DownloadCallback *callback)](#oh_audiosuite_unregisterdownloadcallback) | - | 取消注册下载状态回调。 |
| [int32_t OH_AudioSuite_StartDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)](#oh_audiosuite_startdownload) | - | 开始下载。 |
| [int32_t OH_AudioSuite_PauseDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)](#oh_audiosuite_pausedownload) | - | 暂停下载。 |
| [int32_t OH_AudioSuite_CancelDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)](#oh_audiosuite_canceldownload) | - | 取消下载。 |
| [int32_t OH_AudioSuite_StartBackgroundDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)](#oh_audiosuite_startbackgrounddownload) | - | 后台下载。 |
| [int32_t OH_AudioSuite_GetDownloadStatus(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName, OH_AudioSuite_DownloadStatusInfo *status)](#oh_audiosuite_getdownloadstatus) | - | 获取下载状态。 |
| [int32_t OH_AudioSuite_UninstallCloudRom(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)](#oh_audiosuite_uninstallcloudrom) | - | 卸载已下载的云端文件。 |

## 函数说明

### OH_AudioSuite_DownloadCallback()

```c
typedef void (*OH_AudioSuite_DownloadCallback)(OH_AudioSuite_DownloadStatusInfoArray *downloadStatusInfoArray)
```

**描述**

下载状态更新的回调函数。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuite_DownloadStatusInfoArray](capi-ohaudiosuite-oh-audiosuite-downloadstatusinfoarray.md) *downloadStatusInfoArray | 指向下载状态信息数组的指针。 |

### OH_AudioSuite_GetDownloadManager()

```c
int32_t OH_AudioSuite_GetDownloadManager(OH_AudioSuite_DownloadManager **downloadManager)
```

**描述**

获取音频下载管理器句柄，由OH_AudioSuite_GetDownloadManager获取，用于后续调用下载相关接口时标识操作目标。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) **downloadManager | 指向接收下载管理器句柄的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | AUDIOCOMMON_RESULT_SUCCESS：执行成功。<br>         202：非系统应用调用此系统API。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：下载管理器为空指针。 |

### OH_AudioSuite_RegisterDownloadCallback()

```c
int32_t OH_AudioSuite_RegisterDownloadCallback(OH_AudioSuite_DownloadManager *downloadManager, const OH_AudioSuite_DownloadCallback *callback)
```

**描述**

注册下载状态回调。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | 下载管理器句柄。 |
| [const OH_AudioSuite_DownloadCallback](capi-native-audio-suite-download-manager-h.md#oh_audiosuite_downloadcallback) *callback | 接收下载状态更新的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | AUDIOCOMMON_RESULT_SUCCESS：执行成功。<br>         202：非系统应用调用此系统API。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：下载管理器或回调函数为空指针。<br>         AUDIOCOMMON_RESULT_ERROR_SYSTEM：IPC通信失败或操作失败。 |

### OH_AudioSuite_UnregisterDownloadCallback()

```c
int32_t OH_AudioSuite_UnregisterDownloadCallback(OH_AudioSuite_DownloadManager *downloadManager, const OH_AudioSuite_DownloadCallback *callback)
```

**描述**

取消注册下载状态回调。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | 下载管理器句柄。 |
| [const OH_AudioSuite_DownloadCallback](capi-native-audio-suite-download-manager-h.md#oh_audiosuite_downloadcallback) *callback | 需要取消注册的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | AUDIOCOMMON_RESULT_SUCCESS：执行成功。<br>         202：非系统应用调用此系统API。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：下载管理器或回调函数为空指针。<br>         AUDIOCOMMON_RESULT_ERROR_SYSTEM：IPC通信失败或操作失败。 |

### OH_AudioSuite_StartDownload()

```c
int32_t OH_AudioSuite_StartDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)
```

**描述**

开始下载。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | 下载管理器句柄。 |
| const char *featureName | 需要下载的云端文件名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | AUDIOCOMMON_RESULT_SUCCESS：执行成功。<br>         202：非系统应用调用此系统API。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：下载管理器或云端文件名称为空指针。<br>         AUDIOCOMMON_RESULT_ERROR_SYSTEM：IPC通信失败或操作失败。 |

### OH_AudioSuite_PauseDownload()

```c
int32_t OH_AudioSuite_PauseDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)
```

**描述**

暂停下载。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | 下载管理器句柄。 |
| const char *featureName | 需要暂停的云端文件名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | AUDIOCOMMON_RESULT_SUCCESS：执行成功。<br>         202：非系统应用调用此系统API。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：下载管理器或云端文件名称为空指针。<br>         AUDIOCOMMON_RESULT_ERROR_SYSTEM：IPC通信失败或操作失败。 |

### OH_AudioSuite_CancelDownload()

```c
int32_t OH_AudioSuite_CancelDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)
```

**描述**

取消下载。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | 下载管理器句柄。 |
| const char *featureName | 需要取消的云端文件名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | AUDIOCOMMON_RESULT_SUCCESS：执行成功。<br>         202：非系统应用调用此系统API。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：下载管理器或云端文件名称为空指针。<br>         AUDIOCOMMON_RESULT_ERROR_SYSTEM：IPC通信失败或操作失败。<br>         AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE：当前状态不允许取消。 |

### OH_AudioSuite_StartBackgroundDownload()

```c
int32_t OH_AudioSuite_StartBackgroundDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)
```

**描述**

后台下载。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | 下载管理器句柄。 |
| const char *featureName | 需要下载的云端文件名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | AUDIOCOMMON_RESULT_SUCCESS：执行成功。<br>         202：非系统应用调用此系统API。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：下载管理器或云端文件名称为空指针。<br>         AUDIOCOMMON_RESULT_ERROR_SYSTEM：IPC通信失败或操作失败。 |

### OH_AudioSuite_GetDownloadStatus()

```c
int32_t OH_AudioSuite_GetDownloadStatus(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName, OH_AudioSuite_DownloadStatusInfo *status)
```

**描述**

获取下载状态。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | 下载管理器句柄。 |
| const char *featureName | 云端文件名称。 |
| [OH_AudioSuite_DownloadStatusInfo](capi-ohaudiosuite-oh-audiosuite-downloadstatusinfo.md) *status | 指向接收下载状态信息的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | AUDIOCOMMON_RESULT_SUCCESS：执行成功。<br>         202：非系统应用调用此系统API。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：下载管理器、云端文件名称或状态指针为空指针。<br>         AUDIOCOMMON_RESULT_ERROR_SYSTEM：IPC通信失败或操作失败。 |

### OH_AudioSuite_UninstallCloudRom()

```c
int32_t OH_AudioSuite_UninstallCloudRom(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)
```

**描述**

卸载已下载的云端文件。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | 下载管理器句柄。 |
| const char *featureName | 需要卸载的云端文件名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | AUDIOCOMMON_RESULT_SUCCESS：执行成功。<br>         202：非系统应用调用此系统API。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：下载管理器或云端文件名称为空指针。<br>         AUDIOCOMMON_RESULT_ERROR_SYSTEM：IPC通信失败或操作失败。 |


