# native_audio_debugging_manager.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @zhanganxiang1-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## Overview

The file declares the APIs related to an audio debugging manager. The APIs in this file are used to obtain the audio debugging manager instance and provide audio runtime debugging capabilities, including snapshot information retrieval.

**File to include**: <ohaudio/native_audio_debugging_manager.h>

**Library**: libohaudio.so

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since:** 26.0.0

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioDebuggingManager](capi-ohaudio-oh-audiodebuggingmanager.md) | OH_AudioDebuggingManager | Declares an audio debugging manager, which is used for audio runtime debugging, including features such as retrieving snapshot information.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AudioCommon_Result OH_AudioManager_GetAudioDebuggingManager(OH_AudioDebuggingManager **manager)](#oh_audiomanager_getaudiodebuggingmanager) | Obtains an audio debugging manager instance (singleton).|
| [OH_AudioCommon_Result OH_AudioDebuggingManager_PrintAppInfo(OH_AudioDebuggingManager *manager, int32_t fd)](#oh_audiodebuggingmanager_printappinfo) | Prints the snapshot information of all audio modules in the current process.|
| [OH_AudioCommon_Result OH_AudioDebuggingManager_PrintRendererInfo(OH_AudioDebuggingManager *manager, OH_AudioRenderer *renderer, int32_t fd)](#oh_audiodebuggingmanager_printrendererinfo) | Prints the snapshot information of a specified audio player instance.|
| [OH_AudioCommon_Result OH_AudioDebuggingManager_PrintCapturerInfo(OH_AudioDebuggingManager *manager, OH_AudioCapturer *capturer, int32_t fd)](#oh_audiodebuggingmanager_printcapturerinfo) | Prints the snapshot information of a specified audio recorder instance.|
| [OH_AudioCommon_Result OH_AudioDebuggingManager_PrintSessionInfo(OH_AudioDebuggingManager *manager, OH_AudioSessionManager *session, int32_t fd)](#oh_audiodebuggingmanager_printsessioninfo) | Prints the snapshot information of a specified session manager instance.|

## Function Description

### OH_AudioManager_GetAudioDebuggingManager()

```c
OH_AudioCommon_Result OH_AudioManager_GetAudioDebuggingManager(OH_AudioDebuggingManager **manager)
```

**Description**

Obtains an audio debugging manager instance (singleton).

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDebuggingManager](capi-ohaudio-oh-audiodebuggingmanager.md) **manager | Output parameter, which is used to receive the OH_AudioDebuggingManager instance.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AudioCommon_Result | <ul><br>         <li>**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.</li><br>         <li>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM: The **manager** parameter is **nullptr**.</li><br>         </ul> |

### OH_AudioDebuggingManager_PrintAppInfo()

```c
OH_AudioCommon_Result OH_AudioDebuggingManager_PrintAppInfo(OH_AudioDebuggingManager *manager, int32_t fd)
```

**Description**

Prints the snapshot information of all audio modules in the current process.

> **NOTE**
> 
> The content and format of the snapshot information may change across versions. It is intended for manual debugging reference only, and you are advised not to build functional logic based on the snapshot information.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDebuggingManager](capi-ohaudio-oh-audiodebuggingmanager.md) *manager | Audio debugging manager instance obtained through [OH_AudioManager_GetAudioDebuggingManager](capi-native-audio-debugging-manager-h.md#oh_audiomanager_getaudiodebuggingmanager).|
| int32_t fd | File descriptor. If **fd** is less than 0 or is not writable, the snapshot information is output to the runtime log. Otherwise, it is output to the file pointed to by **fd**.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AudioCommon_Result | <ul><br>         <li>**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.</li><br>         <li>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM: The **manager** parameter is **nullptr**.</li><br>         </ul> |

### OH_AudioDebuggingManager_PrintRendererInfo()

```c
OH_AudioCommon_Result OH_AudioDebuggingManager_PrintRendererInfo(OH_AudioDebuggingManager *manager, OH_AudioRenderer *renderer, int32_t fd)
```

**Description**

Prints the snapshot information of a specified audio player instance.

> **NOTE**
> 
> The content and format of the snapshot information may change across versions. It is intended for manual debugging reference only, and you are advised not to build functional logic based on the snapshot information.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDebuggingManager](capi-ohaudio-oh-audiodebuggingmanager.md) *manager | Audio debugging manager instance obtained through [OH_AudioManager_GetAudioDebuggingManager](capi-native-audio-debugging-manager-h.md#oh_audiomanager_getaudiodebuggingmanager).|
| OH_AudioRenderer *renderer | Pointer to the target audio player instance, which is used to print snapshot information.|
| int32_t fd | File descriptor. If **fd** is less than 0 or is not writable, the snapshot information is output to the runtime log. Otherwise, it is output to the file pointed to by **fd**.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AudioCommon_Result | <ul><br>         <li>**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.</li><br>         <li>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **manager** or **renderer** parameter is **nullptr**.</li><br>         </ul> |

### OH_AudioDebuggingManager_PrintCapturerInfo()

```c
OH_AudioCommon_Result OH_AudioDebuggingManager_PrintCapturerInfo(OH_AudioDebuggingManager *manager, OH_AudioCapturer *capturer, int32_t fd)
```

**Description**

Prints the snapshot information of a specified audio recorder instance.

> **NOTE**
> 
> The content and format of the snapshot information may change across versions. It is intended for manual debugging reference only, and you are advised not to build functional logic based on the snapshot information.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDebuggingManager](capi-ohaudio-oh-audiodebuggingmanager.md) *manager | Audio debugging manager instance obtained through [OH_AudioManager_GetAudioDebuggingManager](capi-native-audio-debugging-manager-h.md#oh_audiomanager_getaudiodebuggingmanager).|
| OH_AudioCapturer *capturer | Pointer to the target audio recorder instance, which is used to print snapshot information.|
| int32_t fd | File descriptor. If **fd** is less than 0 or is not writable, the snapshot information is output to the runtime log. Otherwise, it is output to the file pointed to by **fd**.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AudioCommon_Result | <ul><br>         <li>**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.</li><br>         <li>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **manager** or **capturer** parameter is **nullptr**.</li><br>         </ul> |

### OH_AudioDebuggingManager_PrintSessionInfo()

```c
OH_AudioCommon_Result OH_AudioDebuggingManager_PrintSessionInfo(OH_AudioDebuggingManager *manager, OH_AudioSessionManager *session, int32_t fd)
```

**Description**

Prints the snapshot information of a specified session manager instance.

> **NOTE**
> 
> The content and format of the snapshot information may change across versions. It is intended for manual debugging reference only, and you are advised not to build functional logic based on the snapshot information.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDebuggingManager](capi-ohaudio-oh-audiodebuggingmanager.md) *manager | Audio debugging manager instance obtained through [OH_AudioManager_GetAudioDebuggingManager](capi-native-audio-debugging-manager-h.md#oh_audiomanager_getaudiodebuggingmanager).|
| [OH_AudioSessionManager](capi-ohaudio-oh-audiosessionmanager.md) *session | Pointer to the target session manager instance, which is used to print snapshot information.|
| int32_t fd | File descriptor. If **fd** is less than 0 or is not writable, the snapshot information is output to the runtime log. Otherwise, it is output to the file pointed to by **fd**.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AudioCommon_Result | <ul><br>         <li>**AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.</li><br>         <li>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **manager** or **session** parameter is **nullptr**.</li><br>         </ul> |
<!--no_check-->