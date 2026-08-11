# native_audio_device_enhance_manager.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @zhanganxiang1-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## Overview

The file declares the APIs related to an audio device enhancement manager. The APIs in this file are used to obtain the OH_AudioDeviceEnhanceManager handle, switch input and output devices for applications or audio streams, and perform other enhanced functions related to audio devices or routing.

**File to include**: <ohaudio/native_audio_device_enhance_manager.h>

**Library**: libohaudio.so

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since:** 26.0.0

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioDeviceEnhanceManager](capi-ohaudio-oh-audiodeviceenhancemanager.md) | OH_AudioDeviceEnhanceManager | Defines the handle type for the audio device enhancement manager. This manager enables device selection at both the application level and the stream level.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AudioCommon_Result OH_AudioManager_GetAudioDeviceEnhanceManager(OH_AudioDeviceEnhanceManager **audioDeviceEnhanceManager)](#oh_audiomanager_getaudiodeviceenhancemanager) | Obtains the handle to the audio device enhancement manager.|
| [OH_AudioCommon_Result OH_AudioDeviceEnhanceManager_IsEnhancedRoutingSupported(OH_AudioDeviceEnhanceManager *audioDeviceEnhanceManager, bool *supported)](#oh_audiodeviceenhancemanager_isenhancedroutingsupported) | Checks whether the system supports the enhanced routing function provided by the current manager.|
| [OH_AudioCommon_Result OH_AudioDeviceEnhanceManager_SelectOutputDevice(OH_AudioDeviceEnhanceManager *audioDeviceEnhanceManager, OH_AudioDeviceDescriptor *deviceDescriptor)](#oh_audiodeviceenhancemanager_selectoutputdevice) | Selects an output device for an application.|
| [OH_AudioCommon_Result OH_AudioDeviceEnhanceManager_SelectInputDevice(OH_AudioDeviceEnhanceManager *audioDeviceEnhanceManager, OH_AudioDeviceDescriptor *deviceDescriptor)](#oh_audiodeviceenhancemanager_selectinputdevice) | Selects an input device for an application.|
| [OH_AudioCommon_Result OH_AudioDeviceEnhanceManager_SelectOutputDeviceForAudioRenderer(OH_AudioDeviceEnhanceManager *audioDeviceEnhanceManager, OH_AudioRenderer *renderer, OH_AudioDeviceDescriptor *deviceDescriptor)](#oh_audiodeviceenhancemanager_selectoutputdeviceforaudiorenderer) | Selects an output device for a specified audio playback stream.|
| [OH_AudioCommon_Result OH_AudioDeviceEnhanceManager_SelectInputDeviceForAudioCapturer(OH_AudioDeviceEnhanceManager *audioDeviceEnhanceManager, OH_AudioCapturer *capturer, OH_AudioDeviceDescriptor *deviceDescriptor)](#oh_audiodeviceenhancemanager_selectinputdeviceforaudiocapturer) | Selects an input device for a specified audio recording stream.|

## Function Description

### OH_AudioManager_GetAudioDeviceEnhanceManager()

```c
OH_AudioCommon_Result OH_AudioManager_GetAudioDeviceEnhanceManager(OH_AudioDeviceEnhanceManager **audioDeviceEnhanceManager)
```

**Description**

Obtains the handle to the audio device enhancement manager.

> **NOTE**
>
> This handle should be passed as the first parameter to APIs related to audio device enhancement management.
> The capabilities provided by this manager are available only on specific devices.
> Before using this manager, applications should call [OH_AudioDeviceEnhanceManager_IsEnhancedRoutingSupported](capi-native-audio-device-enhance-manager-h.md#oh_audiodeviceenhancemanager_isenhancedroutingsupported) to confirm whether the system supports the audio device enhancement management feature.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDeviceEnhanceManager](capi-ohaudio-oh-audiodeviceenhancemanager.md) **audioDeviceEnhanceManager | Pointer to the OH_AudioDeviceEnhanceManager handle, which is used to receive the manager instance returned by the function.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AudioCommon_Result | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioDeviceEnhanceManager** parameter is **nullptr**.|

### OH_AudioDeviceEnhanceManager_IsEnhancedRoutingSupported()

```c
OH_AudioCommon_Result OH_AudioDeviceEnhanceManager_IsEnhancedRoutingSupported(OH_AudioDeviceEnhanceManager *audioDeviceEnhanceManager, bool *supported)
```

**Description**

Checks whether the system supports the enhanced routing function provided by the current manager.

> **NOTE**
> 
> The enhanced routing feature supports selecting input and output devices for applications or audio streams.
> Before calling a related enhanced routing API, applications should call this API to check whether the system supports the audio device enhancement management feature.
> Even for devices of the same product model, support for this feature may vary across different hardware variants due to hardware limitations.
> If the system does not support the enhanced routing feature, calling the related APIs will not take effect, and the system will select the default input and output devices for the application or audio stream.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDeviceEnhanceManager](capi-ohaudio-oh-audiodeviceenhancemanager.md) *audioDeviceEnhanceManager | Handle to the audio device enhancement manager obtained through [OH_AudioManager_GetAudioDeviceEnhanceManager](capi-native-audio-device-enhance-manager-h.md#oh_audiomanager_getaudiodeviceenhancemanager).|
| bool *supported | Query result, indicating whether the system supports the audio device enhancement management feature. **true** if supported; **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AudioCommon_Result | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioDeviceEnhanceManager** or **supported** parameter is **nullptr**.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: The audio client failed to call the audio service or a system error occurred.|

### OH_AudioDeviceEnhanceManager_SelectOutputDevice()

```c
OH_AudioCommon_Result OH_AudioDeviceEnhanceManager_SelectOutputDevice(OH_AudioDeviceEnhanceManager *audioDeviceEnhanceManager, OH_AudioDeviceDescriptor *deviceDescriptor)
```

**Description**

Selects an output device for an application.

> **NOTE**
> 
> This setting applies to all playback streams created by the application, except for streams that have already been assigned a dedicated output device.
> When implementing output device selection, the application can obtain the list of available output devices via [OH_AudioRoutingManager_GetAvailableDevices](capi-native-audio-routing-manager-h.md#oh_audioroutingmanager_getavailabledevices), 
> and retrieve the current preferred output device via [OH_AudioRoutingManager_GetPreferredOutputDevice](capi-native-audio-routing-manager-h.md#oh_audioroutingmanager_getpreferredoutputdevice).
> This selection becomes invalid after the application exits or the selected device goes offline. After the application restarts or when the device comes back online, the selection needs to be re-configured.
> If the system does not support this feature, the default output device will be used for the application.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDeviceEnhanceManager](capi-ohaudio-oh-audiodeviceenhancemanager.md) *audioDeviceEnhanceManager | Handle to the audio device enhancement manager obtained through [OH_AudioManager_GetAudioDeviceEnhanceManager](capi-native-audio-device-enhance-manager-h.md#oh_audiomanager_getaudiodeviceenhancemanager).|
| OH_AudioDeviceDescriptor *deviceDescriptor | Pointer to the target device. The available devices must be obtained from the device list returned by [OH_AudioRoutingManager_GetAvailableDevices](capi-native-audio-routing-manager-h.md#oh_audioroutingmanager_getavailabledevices). If **nullptr** is passed, the system clears the previous selection and restores the default output device for the application.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AudioCommon_Result | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioDeviceEnhanceManager** parameter is nullptr.<br>         The **deviceDescriptor** parameter is invalid or the specified output device is offline.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: The audio client failed to call the audio service or a system error occurred.|

### OH_AudioDeviceEnhanceManager_SelectInputDevice()

```c
OH_AudioCommon_Result OH_AudioDeviceEnhanceManager_SelectInputDevice(OH_AudioDeviceEnhanceManager *audioDeviceEnhanceManager, OH_AudioDeviceDescriptor *deviceDescriptor)
```

**Description**

Selects an input device for an application.

> **NOTE**
>
> This setting applies to all recording streams created by the application, except for streams that have already been assigned a dedicated input device.
> When implementing input device selection, the application can obtain the list of available input devices via [OH_AudioRoutingManager_GetAvailableDevices](capi-native-audio-routing-manager-h.md#oh_audioroutingmanager_getavailabledevices), 
> and retrieve the current preferred input device via [OH_AudioRoutingManager_GetPreferredInputDevice](capi-native-audio-routing-manager-h.md#oh_audioroutingmanager_getpreferredinputdevice).
> This selection becomes invalid after the application exits or the selected device goes offline. After the application restarts or when the device comes back online, the selection needs to be re-configured.
> If the system does not support this feature, the default input device will be used for the application.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDeviceEnhanceManager](capi-ohaudio-oh-audiodeviceenhancemanager.md) *audioDeviceEnhanceManager | Handle to the audio device enhancement manager obtained through [OH_AudioManager_GetAudioDeviceEnhanceManager](capi-native-audio-device-enhance-manager-h.md#oh_audiomanager_getaudiodeviceenhancemanager).|
| OH_AudioDeviceDescriptor *deviceDescriptor | Pointer to the target device. The available devices must be obtained from the device list returned by [OH_AudioRoutingManager_GetAvailableDevices](capi-native-audio-routing-manager-h.md#oh_audioroutingmanager_getavailabledevices). If **nullptr** is passed, the system clears the previous selection and restores the default input device for the application.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AudioCommon_Result | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioDeviceEnhanceManager** parameter is nullptr.<br>         The **deviceDescriptor** parameter is invalid or the specified input device is offline.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: The audio client failed to call the audio service or a system error occurred.|

### OH_AudioDeviceEnhanceManager_SelectOutputDeviceForAudioRenderer()

```c
OH_AudioCommon_Result OH_AudioDeviceEnhanceManager_SelectOutputDeviceForAudioRenderer(OH_AudioDeviceEnhanceManager *audioDeviceEnhanceManager, OH_AudioRenderer *renderer, OH_AudioDeviceDescriptor *deviceDescriptor)
```

**Description**

Selects an output device for a specified audio playback stream.

> **NOTE**
> 
> The application must ensure that the specified audio playback stream is valid.
> This selection applies only to the specified stream. Other playback streams in the application will continue to use the application-level selected device or the system default output device.
> This selection becomes invalid after the application exits or the selected device goes offline. After the application restarts or when the device comes back online, the selection needs to be re-configured.
> If the system does not support this feature, the default output device will be used for the audio playback stream.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDeviceEnhanceManager](capi-ohaudio-oh-audiodeviceenhancemanager.md) *audioDeviceEnhanceManager | Handle to the audio device enhancement manager obtained through [OH_AudioManager_GetAudioDeviceEnhanceManager](capi-native-audio-device-enhance-manager-h.md#oh_audiomanager_getaudiodeviceenhancemanager).|
| OH_AudioRenderer *renderer | Pointer to the audio playback stream instance obtained through [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| OH_AudioDeviceDescriptor *deviceDescriptor | Pointer to the target device. The available devices must be obtained from the device list returned by [OH_AudioRoutingManager_GetAvailableDevices](capi-native-audio-routing-manager-h.md#oh_audioroutingmanager_getavailabledevices). If **nullptr** is passed, the system clears the previous selection and restores the default output device for the audio playback stream.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AudioCommon_Result | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioDeviceEnhanceManager** or **renderer** parameter is **nullptr**.<br>         The **deviceDescriptor** parameter is invalid or the specified output device is offline.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: The audio client failed to call the audio service or a system error occurred.|

### OH_AudioDeviceEnhanceManager_SelectInputDeviceForAudioCapturer()

```c
OH_AudioCommon_Result OH_AudioDeviceEnhanceManager_SelectInputDeviceForAudioCapturer(OH_AudioDeviceEnhanceManager *audioDeviceEnhanceManager, OH_AudioCapturer *capturer, OH_AudioDeviceDescriptor *deviceDescriptor)
```

**Description**

Selects an input device for a specified audio recording stream.

> **NOTE**
> 
> The application must ensure that the specified audio recording stream is valid.
> This selection applies only to the specified stream. Other recording streams in the application will continue to use the application-level selected device or the system default input device.
> This selection becomes invalid after the application exits or the selected device goes offline. After the application restarts or when the device comes back online, the selection needs to be re-configured.
> If the system does not support this feature, the default input device will be used for the audio recording stream.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDeviceEnhanceManager](capi-ohaudio-oh-audiodeviceenhancemanager.md) *audioDeviceEnhanceManager | Handle to the audio device enhancement manager obtained through [OH_AudioManager_GetAudioDeviceEnhanceManager](capi-native-audio-device-enhance-manager-h.md#oh_audiomanager_getaudiodeviceenhancemanager).|
| OH_AudioCapturer *capturer | Pointer to the audio recording stream instance obtained through [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| OH_AudioDeviceDescriptor *deviceDescriptor | Pointer to the target device. The available devices must be obtained from the device list returned by [OH_AudioRoutingManager_GetAvailableDevices](capi-native-audio-routing-manager-h.md#oh_audioroutingmanager_getavailabledevices). If **nullptr** is passed, the system clears the previous selection and restores the default input device for the audio recording stream.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AudioCommon_Result | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioDeviceEnhanceManager** or **capturer** parameter is **nullptr**.<br>         The **deviceDescriptor** parameter is invalid or the specified input device is offline.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM**: The audio client failed to call the audio service or a system error occurred.|
<!--no_check-->