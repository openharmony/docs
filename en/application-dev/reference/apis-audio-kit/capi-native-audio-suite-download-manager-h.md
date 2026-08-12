# native_audio_suite_download_manager.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## Overview

The file declares the APIs of the audio download manager.

**File to include**: <ohaudiosuite/native_audio_suite_download_manager.h>

**Library**: libohaudiosuite.so

**System capability**: SystemCapability.Multimedia.Audio.SuiteEngine

**Since:** 26.0.0

**Related module**: [OHAudioSuite](capi-ohaudiosuite.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioSuite_DownloadStatusInfo](capi-ohaudiosuite-oh-audiosuite-downloadstatusinfo.md) | OH_AudioSuite_DownloadStatusInfo | Defines the download status information structure.|
| [OH_AudioSuite_DownloadStatusInfoArray](capi-ohaudiosuite-oh-audiosuite-downloadstatusinfoarray.md) | OH_AudioSuite_DownloadStatusInfoArray | Defines the download status information array structure.|
| [OH_AudioSuite_DownloadManagerStruct](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) | OH_AudioSuite_DownloadManager | Declares the audio download manager.<br> The handle to the audio download manager is used to perform download-related functions.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_AudioSuite_DownloadCallback)(OH_AudioSuite_DownloadStatusInfoArray *downloadStatusInfoArray)](#oh_audiosuite_downloadcallback) | OH_AudioSuite_DownloadCallback | Callback for download status updates.|
| [int32_t OH_AudioSuite_GetDownloadManager(OH_AudioSuite_DownloadManager **downloadManager)](#oh_audiosuite_getdownloadmanager) | - | Obtains the handle to the audio download manager, which is obtained via **OH_AudioSuite_GetDownloadManager**. The handle is used to identify the operation target when calling download-related APIs later.|
| [int32_t OH_AudioSuite_RegisterDownloadCallback(OH_AudioSuite_DownloadManager *downloadManager, const OH_AudioSuite_DownloadCallback *callback)](#oh_audiosuite_registerdownloadcallback) | - | Registers a download status callback.|
| [int32_t OH_AudioSuite_UnregisterDownloadCallback(OH_AudioSuite_DownloadManager *downloadManager, const OH_AudioSuite_DownloadCallback *callback)](#oh_audiosuite_unregisterdownloadcallback) | - | Unregisters a download status callback.|
| [int32_t OH_AudioSuite_StartDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)](#oh_audiosuite_startdownload) | - | Starts a download.|
| [int32_t OH_AudioSuite_PauseDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)](#oh_audiosuite_pausedownload) | - | Pauses a download.|
| [int32_t OH_AudioSuite_CancelDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)](#oh_audiosuite_canceldownload) | - | Cancels download.|
| [int32_t OH_AudioSuite_StartBackgroundDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)](#oh_audiosuite_startbackgrounddownload) | - | Performs download in the background.|
| [int32_t OH_AudioSuite_GetDownloadStatus(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName, OH_AudioSuite_DownloadStatusInfo *status)](#oh_audiosuite_getdownloadstatus) | - | Obtains the download status.|
| [int32_t OH_AudioSuite_UninstallCloudRom(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)](#oh_audiosuite_uninstallcloudrom) | - | Uninstalls a downloaded cloud file.|

## Function Description

### OH_AudioSuite_DownloadCallback()

```c
typedef void (*OH_AudioSuite_DownloadCallback)(OH_AudioSuite_DownloadStatusInfoArray *downloadStatusInfoArray)
```

**Description**

Callback for download status updates.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSuite_DownloadStatusInfoArray](capi-ohaudiosuite-oh-audiosuite-downloadstatusinfoarray.md) *downloadStatusInfoArray | Pointer to the download status information array.|

### OH_AudioSuite_GetDownloadManager()

```c
int32_t OH_AudioSuite_GetDownloadManager(OH_AudioSuite_DownloadManager **downloadManager)
```

**Description**

Obtains the handle to the audio download manager, which is obtained via **OH_AudioSuite_GetDownloadManager**. The handle is used to identify the operation target when calling download-related APIs later.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) **downloadManager | Pointer to the download manager handle.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **AUDIOCOMMON_RESULT_SUCCESS**: The operation is successful.<br>         **202**: A non-system app calls this system API.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The download manager is a null pointer.|

### OH_AudioSuite_RegisterDownloadCallback()

```c
int32_t OH_AudioSuite_RegisterDownloadCallback(OH_AudioSuite_DownloadManager *downloadManager, const OH_AudioSuite_DownloadCallback *callback)
```

**Description**

Registers a download status callback.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | Handle to the download manager.|
| [const OH_AudioSuite_DownloadCallback](capi-native-audio-suite-download-manager-h.md#oh_audiosuite_downloadcallback) *callback | Callback for receiving the download status updates.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **AUDIOCOMMON_RESULT_SUCCESS**: The operation is successful.<br>         **202**: A non-system app calls this system API.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The download manager or the callback function is a null pointer.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: IPC failed or the operation failed.|

### OH_AudioSuite_UnregisterDownloadCallback()

```c
int32_t OH_AudioSuite_UnregisterDownloadCallback(OH_AudioSuite_DownloadManager *downloadManager, const OH_AudioSuite_DownloadCallback *callback)
```

**Description**

Unregisters a download status callback.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | Handle to the download manager.|
| [const OH_AudioSuite_DownloadCallback](capi-native-audio-suite-download-manager-h.md#oh_audiosuite_downloadcallback) *callback | Callback to unregister.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **AUDIOCOMMON_RESULT_SUCCESS**: The operation is successful.<br>         **202**: A non-system app calls this system API.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The download manager or the callback function is a null pointer.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: IPC failed or the operation failed.|

### OH_AudioSuite_StartDownload()

```c
int32_t OH_AudioSuite_StartDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)
```

**Description**

Starts a download.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | Handle to the download manager.|
| const char *featureName | Name of the cloud file to download.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **AUDIOCOMMON_RESULT_SUCCESS**: The operation is successful.<br>         **202**: A non-system app calls this system API.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The download manager or cloud file name is a null pointer.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: IPC failed or the operation failed.|

### OH_AudioSuite_PauseDownload()

```c
int32_t OH_AudioSuite_PauseDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)
```

**Description**

Pauses a download.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | Handle to the download manager.|
| const char *featureName | Name of the cloud file to be paused.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **AUDIOCOMMON_RESULT_SUCCESS**: The operation is successful.<br>         **202**: A non-system app calls this system API.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The download manager or cloud file name is a null pointer.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: IPC failed or the operation failed.|

### OH_AudioSuite_CancelDownload()

```c
int32_t OH_AudioSuite_CancelDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)
```

**Description**

Cancels download.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | Handle to the download manager.|
| const char *featureName | Name of the cloud file to be canceled.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **AUDIOCOMMON_RESULT_SUCCESS**: The operation is successful.<br>         **202**: A non-system app calls this system API.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The download manager or cloud file name is a null pointer.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: IPC failed or the operation failed.<br>         **AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: Cancellation is not allowed in the current state.|

### OH_AudioSuite_StartBackgroundDownload()

```c
int32_t OH_AudioSuite_StartBackgroundDownload(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)
```

**Description**

Performs download in the background.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | Handle to the download manager.|
| const char *featureName | Name of the cloud file to download.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **AUDIOCOMMON_RESULT_SUCCESS**: The operation is successful.<br>         **202**: A non-system app calls this system API.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The download manager or cloud file name is a null pointer.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: IPC failed or the operation failed.|

### OH_AudioSuite_GetDownloadStatus()

```c
int32_t OH_AudioSuite_GetDownloadStatus(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName, OH_AudioSuite_DownloadStatusInfo *status)
```

**Description**

Obtains the download status.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | Handle to the download manager.|
| const char *featureName | Cloud file name.|
| [OH_AudioSuite_DownloadStatusInfo](capi-ohaudiosuite-oh-audiosuite-downloadstatusinfo.md) *status | Pointer to the download status information.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **AUDIOCOMMON_RESULT_SUCCESS**: The operation is successful.<br>         **202**: A non-system app calls this system API.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The download manager, cloud file name, or status pointer is null.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: IPC failed or the operation failed.|

### OH_AudioSuite_UninstallCloudRom()

```c
int32_t OH_AudioSuite_UninstallCloudRom(OH_AudioSuite_DownloadManager *downloadManager, const char *featureName)
```

**Description**

Uninstalls a downloaded cloud file.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioSuite_DownloadManager](capi-ohaudiosuite-oh-audiosuite-downloadmanagerstruct.md) *downloadManager | Handle to the download manager.|
| const char *featureName | Name of the cloud file to be uninstalled.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **AUDIOCOMMON_RESULT_SUCCESS**: The operation is successful.<br>         **202**: A non-system app calls this system API.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The download manager or cloud file name is a null pointer.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: IPC failed or the operation failed.|
