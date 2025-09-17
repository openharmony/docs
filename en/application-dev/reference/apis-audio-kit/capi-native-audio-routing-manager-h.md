# native_audio_routing_manager.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the functions related to an audio routing manager.

You can use the functions to create an audio routing manager, register and deregister a callback to listen for device connection status changes, and release devices.

**File to include**: <ohaudio/native_audio_routing_manager.h>

**Library**: libohaudio.so

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioRoutingManager](capi-ohaudio-oh-audioroutingmanager.md) | OH_AudioRoutingManager | Describes an audio routing manager, which is used for routing and device-related functions.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef int32_t (\*OH_AudioRoutingManager_OnDeviceChangedCallback)(OH_AudioDevice_ChangeType type, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray)](#oh_audioroutingmanager_ondevicechangedcallback) | OH_AudioRoutingManager_OnDeviceChangedCallback | Defines a pointer to the callback that returns the changed audio device descriptor (possibly multiple descriptors).|
| [OH_AudioCommon_Result OH_AudioManager_GetAudioRoutingManager(OH_AudioRoutingManager **audioRoutingManager)](#oh_audiomanager_getaudioroutingmanager) | - | Obtains the handle to an audio routing manager. The handle should be set as the first parameter in the routing-related functions.|
| [OH_AudioCommon_Result OH_AudioRoutingManager_GetDevices(OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Flag deviceFlag, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)](#oh_audioroutingmanager_getdevices) | - | Obtains available devices based on the device flag.|
| [OH_AudioCommon_Result OH_AudioRoutingManager_GetAvailableDevices(OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Usage deviceUsage, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)](#oh_audioroutingmanager_getavailabledevices) | - | Obtains the available audio devices. |
| [OH_AudioCommon_Result OH_AudioRoutingManager_GetPreferredOutputDevice(OH_AudioRoutingManager *audioRoutingManager, OH_AudioStream_Usage streamUsage, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)](#oh_audioroutingmanager_getpreferredoutputdevice) | - | Obtains the output device with the highest priority based on the usage scenario of an audio output stream.|
| [OH_AudioCommon_Result OH_AudioRoutingManager_GetPreferredInputDevice(OH_AudioRoutingManager *audioRoutingManager, OH_AudioStream_SourceType sourceType, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)](#oh_audioroutingmanager_getpreferredinputdevice) | - | Obtains the input device with the highest priority based on the usage scenario of an audio input stream.|
| [OH_AudioCommon_Result OH_AudioRoutingManager_RegisterDeviceChangeCallback(OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Flag deviceFlag, OH_AudioRoutingManager_OnDeviceChangedCallback callback)](#oh_audioroutingmanager_registerdevicechangecallback) | - | Registers a callback to listen for device changes of an audio routing manager.|
| [OH_AudioCommon_Result OH_AudioRoutingManager_UnregisterDeviceChangeCallback(OH_AudioRoutingManager *audioRoutingManager, OH_AudioRoutingManager_OnDeviceChangedCallback callback)](#oh_audioroutingmanager_unregisterdevicechangecallback) | - | Unregisters the callback used to listen for device changes of an audio routing manager.|
| [OH_AudioCommon_Result OH_AudioRoutingManager_ReleaseDevices(OH_AudioRoutingManager *audioRoutingManager, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray)](#oh_audioroutingmanager_releasedevices) | - | Releases audio devices available for an audio routing manager.|
| [typedef void (\*OH_AudioRoutingManager_OnDeviceBlockStatusCallback)(OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray, OH_AudioDevice_BlockStatus status, void *userData)](#oh_audioroutingmanager_ondeviceblockstatuscallback) | OH_AudioRoutingManager_OnDeviceBlockStatusCallback | Defines a pointer to the callback that returns the blocked status of one or more audio devices.|
| [OH_AudioCommon_Result OH_AudioRoutingManager_IsMicBlockDetectionSupported(OH_AudioRoutingManager *audioRoutingManager, bool *supported)](#oh_audioroutingmanager_ismicblockdetectionsupported) | - | Checks whether the current device supports microphone blocking detection.|
| [OH_AudioCommon_Result OH_AudioRoutingManager_SetMicBlockStatusCallback(OH_AudioRoutingManager *audioRoutingManager, OH_AudioRoutingManager_OnDeviceBlockStatusCallback callback, void *userData)](#oh_audioroutingmanager_setmicblockstatuscallback) | - | Sets a callback function to be invoked when the microphone's blocked status is changed.<br>Before using this function, check whether the current device supports microphone blocking detection. The application receives a callback only when the microphone is used for recording and the microphone's blocked status changes. Currently, this function takes effect only for the microphone on the local device.|

## Function Description

### OH_AudioRoutingManager_OnDeviceChangedCallback()

```
typedef int32_t (*OH_AudioRoutingManager_OnDeviceChangedCallback)(OH_AudioDevice_ChangeType type, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray
)
```

**Description**

Defines a pointer to the callback that returns the changed audio device descriptor (possibly multiple descriptors).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDevice_ChangeType](capi-native-audio-device-base-h.md#oh_audiodevice_changetype) type | Device connection status, which is [OH_AudioDevice_ChangeType](capi-native-audio-device-base-h.md#oh_audiodevice_changetype). The status can be either connected or disconnected.|
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) *audioDeviceDescriptorArray | Pointer to the audio device descriptors in the array. For details, see [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md). Do not release the pointer to the audioDeviceDescriptorArray struct separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release the DeviceDescriptor array.|

### OH_AudioManager_GetAudioRoutingManager()

```
OH_AudioCommon_Result OH_AudioManager_GetAudioRoutingManager(OH_AudioRoutingManager **audioRoutingManager)
```

**Description**

Obtains the handle to an audio routing manager. The handle should be set as the first parameter in the routing-related functions.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRoutingManager](capi-ohaudio-oh-audioroutingmanager.md) **audioRoutingManager | Handle to the audio routing manager, which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.|

### OH_AudioRoutingManager_GetDevices()

```
OH_AudioCommon_Result OH_AudioRoutingManager_GetDevices(OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Flag deviceFlag, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)
```

**Description**

Obtains available devices based on the device flag.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRoutingManager](capi-ohaudio-oh-audioroutingmanager.md) *audioRoutingManager | Handle to the audio routing manager, which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|
| [OH_AudioDevice_Flag](capi-native-audio-device-base-h.md#oh_audiodevice_flag) deviceFlag | Device flag, which is used to filter the target device.|
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) **audioDeviceDescriptorArray | Double pointer to the audio device descriptors in the array. Do not release the pointer to the audioDeviceDescriptorArray struct separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release the DeviceDescriptor array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioRoutingManager** parameter is nullptr.<br>                                                        2. The **deviceFlag** parameter is set to an invalid value.<br>                                                        3. The **audioDeviceDescriptorArray** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_NO_MEMORY**: The memory is insufficient.|

### OH_AudioRoutingManager_GetAvailableDevices()

```
OH_AudioCommon_Result OH_AudioRoutingManager_GetAvailableDevices(OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Usage deviceUsage, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)
```

**Description**

Obtains the available audio devices.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRoutingManager](capi-ohaudio-oh-audioroutingmanager.md) *audioRoutingManager | Handle to the audio routing manager, which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|
| [OH_AudioDevice_Usage](capi-native-audio-device-base-h.md#oh_audiodevice_usage) deviceUsage | Usage scenario of the audio device. For details about the available options, see [OH_AudioDevice_Usage](capi-native-audio-device-base-h.md#oh_audiodevice_usage).|
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) **audioDeviceDescriptorArray | Double pointer to the audio device descriptors in the array. Do not release the pointer to the audioDeviceDescriptorArray struct separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release the DeviceDescriptor array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioRoutingManager** parameter is nullptr.<br>                                                        2. The **deviceUsage** parameter is invalid.<br>                                                        3. The **audioDeviceDescriptorArray** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_NO_MEMORY**: The memory is insufficient.|

### OH_AudioRoutingManager_GetPreferredOutputDevice()

```
OH_AudioCommon_Result OH_AudioRoutingManager_GetPreferredOutputDevice(OH_AudioRoutingManager *audioRoutingManager, OH_AudioStream_Usage streamUsage, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)
```

**Description**

Obtains the output device with the highest priority based on the usage scenario of an audio output stream.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRoutingManager](capi-ohaudio-oh-audioroutingmanager.md) *audioRoutingManager | Handle to the audio routing manager, which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) streamUsage | Usage scenario of the audio input stream. For details about the available options, see [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage).|
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) **audioDeviceDescriptorArray | Double pointer to the audio device descriptors in the array. Do not release the pointer to the audioDeviceDescriptorArray struct separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release the DeviceDescriptor array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioRoutingManager** parameter is nullptr.<br>                                                        2. The **streamUsage** parameter is invalid.<br>                                                        3. The **audioDeviceDescriptorArray** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_NO_MEMORY**: The memory is insufficient.|

### OH_AudioRoutingManager_GetPreferredInputDevice()

```
OH_AudioCommon_Result OH_AudioRoutingManager_GetPreferredInputDevice(OH_AudioRoutingManager *audioRoutingManager, OH_AudioStream_SourceType sourceType, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray)
```

**Description**

Obtains the input device with the highest priority based on the usage scenario of an audio input stream.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRoutingManager](capi-ohaudio-oh-audioroutingmanager.md) *audioRoutingManager | Handle to the audio routing manager, which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|
| [OH_AudioStream_SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype) sourceType | Usage scenario of the audio input stream. For details about the available options, see [OH_AudioStream_SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype).|
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) **audioDeviceDescriptorArray | Double pointer to the audio device descriptors in the array. Do not release the pointer to the audioDeviceDescriptorArray struct separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release the DeviceDescriptor array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioRoutingManager** parameter is nullptr.<br>                                                        2. The **sourceType** parameter is invalid.<br>                                                        3. The **audioDeviceDescriptorArray** parameter is nullptr.<br>         **AUDIOCOMMON_RESULT_ERROR_NO_MEMORY**: The memory is insufficient.|

### OH_AudioRoutingManager_RegisterDeviceChangeCallback()

```
OH_AudioCommon_Result OH_AudioRoutingManager_RegisterDeviceChangeCallback(OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Flag deviceFlag, OH_AudioRoutingManager_OnDeviceChangedCallback callback)
```

**Description**

Registers a callback to listen for device changes of an audio routing manager.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRoutingManager](capi-ohaudio-oh-audioroutingmanager.md) *audioRoutingManager | Handle to the audio routing manager, which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|
| [OH_AudioDevice_Flag](capi-native-audio-device-base-h.md#oh_audiodevice_flag) deviceFlag | Device flag.|
| [OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback) callback | Callback function used to return the changed audio device descriptor.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioRoutingManager** parameter is nullptr.<br>                                                        2. The **deviceFlag** parameter is set to an invalid value.<br>                                                        3. The **callback** parameter is nullptr.|

### OH_AudioRoutingManager_UnregisterDeviceChangeCallback()

```
OH_AudioCommon_Result OH_AudioRoutingManager_UnregisterDeviceChangeCallback(OH_AudioRoutingManager *audioRoutingManager, OH_AudioRoutingManager_OnDeviceChangedCallback callback)
```

**Description**

Unregisters the callback used to listen for device changes of an audio routing manager.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRoutingManager](capi-ohaudio-oh-audioroutingmanager.md) *audioRoutingManager | Handle to the audio routing manager, which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|
| [OH_AudioRoutingManager_OnDeviceChangedCallback](#oh_audioroutingmanager_ondevicechangedcallback) callback | Callback function used to return the changed audio device descriptor.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioRoutingManager** parameter is nullptr.<br>                                                        2. The **callback** parameter is nullptr.|

### OH_AudioRoutingManager_ReleaseDevices()

```
OH_AudioCommon_Result OH_AudioRoutingManager_ReleaseDevices(OH_AudioRoutingManager *audioRoutingManager, OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray)
```

**Description**

Releases audio devices available for an audio routing manager.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRoutingManager](capi-ohaudio-oh-audioroutingmanager.md) *audioRoutingManager | Handle to the audio routing manager, which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) *audioDeviceDescriptorArray | Pointer to the array of audio devices, which are obtained by calling [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                        1. The **audioRoutingManager** parameter is nullptr.<br>                                                        2. The **audioDeviceDescriptorArray** parameter is nullptr.|

### OH_AudioRoutingManager_OnDeviceBlockStatusCallback()

```
typedef void (*OH_AudioRoutingManager_OnDeviceBlockStatusCallback)(OH_AudioDeviceDescriptorArray *audioDeviceDescriptorArray, OH_AudioDevice_BlockStatus status, void *userData)
```

**Description**

Defines a pointer to the callback that returns the blocked status of one or more audio devices.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md) *audioDeviceDescriptorArray | Pointer to the array of audio devices, which are obtained by calling [OH_AudioRoutingManager_GetDevices](#oh_audioroutingmanager_getdevices). Do not release the pointer to the **audioDeviceDescriptorArray** struct separately. Instead, call [OH_AudioRoutingManager_ReleaseDevices](#oh_audioroutingmanager_releasedevices) to release the **DeviceDescriptor** array.|
| [OH_AudioDevice_BlockStatus](capi-native-audio-device-base-h.md#oh_audiodevice_blockstatus) status | Blocked status of the audio device.|
|  void *userData | Pointer to user data.|

### OH_AudioRoutingManager_IsMicBlockDetectionSupported()

```
OH_AudioCommon_Result OH_AudioRoutingManager_IsMicBlockDetectionSupported(OH_AudioRoutingManager *audioRoutingManager, bool *supported)
```

**Description**

Checks whether the current device supports microphone blocking detection.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRoutingManager](capi-ohaudio-oh-audioroutingmanager.md) *audioRoutingManager | Handle to the audio routing manager, which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|
| bool *supported | Check result for the support of microphone blocking detection. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                    1. The **audioRoutingManager** parameter is nullptr.<br>                                                    2. The **supported** parameter is nullptr.|

### OH_AudioRoutingManager_SetMicBlockStatusCallback()

```
OH_AudioCommon_Result OH_AudioRoutingManager_SetMicBlockStatusCallback(OH_AudioRoutingManager *audioRoutingManager, OH_AudioRoutingManager_OnDeviceBlockStatusCallback callback, void *userData)
```

**Description**

Sets a callback function to be invoked when the microphone's blocked status is changed.

Before using this function, check whether the current device supports microphone blocking detection. The application receives a callback only when the microphone is used for recording and the microphone's blocked status changes. Currently, this function takes effect only for the microphone on the local device.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRoutingManager](capi-ohaudio-oh-audioroutingmanager.md) *audioRoutingManager | Handle to the audio routing manager, which is obtained by calling [OH_AudioManager_GetAudioRoutingManager](#oh_audiomanager_getaudioroutingmanager).|
| [OH_AudioRoutingManager_OnDeviceBlockStatusCallback](#oh_audioroutingmanager_ondeviceblockstatuscallback) callback | Pointer to the [OH_AudioRoutingManager_OnDeviceBlockStatusCallback](#oh_audioroutingmanager_ondeviceblockstatuscallback) callback, which is used to return the blocked status.|
| void *userData | Pointer to user data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>                                                    1. The **audioRoutingManager** parameter is nullptr.<br>                                                    2. The **callback** parameter is nullptr.|
