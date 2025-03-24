# native_audio_routing_manager.h


## Overview

The **native_audio_routing_manager.h** file declares the functions related to an audio routing manager.

You can use the functions to create an audio routing manager, register and deregister a callback to listen for device connection status changes, and release devices.

**Library**: libohaudio.so

**File to include**: &lt;ohaudio/native_audio_routing_manager.h&gt;

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) [OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) | Defines the struct of an audio routing manager, which is used for routing and device-related functions. | 
| typedef int32_t (\*[OH_AudioRoutingManager_OnDeviceChangedCallback](_o_h_audio.md#oh_audioroutingmanager_ondevicechangedcallback))([OH_AudioDevice_ChangeType](_o_h_audio.md#oh_audiodevice_changetype) type, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*audioDeviceDescriptorArray) | Defines a pointer to the callback function that returns the changed audio device descriptor (possibly multiple descriptors). | 
| typedef void (\*[OH_AudioRoutingManager_OnDeviceBlockStatusCallback](_o_h_audio.md#oh_audioroutingmanager_ondeviceblockstatuscallback))([OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*audioDeviceDescriptorArray, [OH_AudioDevice_BlockStatus](_o_h_audio.md#oh_audiodevice_blockstatus) status, void \*userData) | Defines a pointer to the callback function that returns the blocked status of one or more audio devices. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioManager_GetAudioRoutingManager](_o_h_audio.md#oh_audiomanager_getaudioroutingmanager)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*\*audioRoutingManager) | Obtains the handle to an audio routing manager. The handle should be set as the first parameter in the routing-related functions. | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_GetDevices](_o_h_audio.md#oh_audioroutingmanager_getdevices)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Flag](_o_h_audio.md#oh_audiodevice_flag) deviceFlag, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | Obtains available devices based on the device flag. | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_GetAvailableDevices](_o_h_audio.md#oh_audioroutingmanager_getavailabledevices)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Usage](_o_h_audio.md#oh_audiodevice_usage) deviceUsage, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | Obtains the available audio devices.  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_GetPreferredOutputDevice](_o_h_audio.md#oh_audioroutingmanager_getpreferredoutputdevice)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioStream_Usage](_o_h_audio.md#oh_audiostream_usage) streamUsage, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | Obtains the output device with the highest priority based on the usage scenario of an audio output stream. | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_GetPreferredInputDevice](_o_h_audio.md#oh_audioroutingmanager_getpreferredinputdevice)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioStream_SourceType](_o_h_audio.md#oh_audiostream_sourcetype) sourceType, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | Obtains the input device with the highest priority based on the usage scenario of an audio input stream. | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_RegisterDeviceChangeCallback](_o_h_audio.md#oh_audioroutingmanager_registerdevicechangecallback)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Flag](_o_h_audio.md#oh_audiodevice_flag) deviceFlag, [OH_AudioRoutingManager_OnDeviceChangedCallback](_o_h_audio.md#oh_audioroutingmanager_ondevicechangedcallback) callback) | Registers a callback to listen for device changes of an audio routing manager. | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_UnregisterDeviceChangeCallback](_o_h_audio.md#oh_audioroutingmanager_unregisterdevicechangecallback)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioRoutingManager_OnDeviceChangedCallback](_o_h_audio.md#oh_audioroutingmanager_ondevicechangedcallback) callback) | Unregisters the callback used to listen for device changes of an audio routing manager. | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_ReleaseDevices](_o_h_audio.md#oh_audioroutingmanager_releasedevices)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*audioDeviceDescriptorArray) | Releases audio devices available for an audio routing manager. | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_IsMicBlockDetectionSupported](_o_h_audio.md#oh_audioroutingmanager_ismicblockdetectionsupported)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, bool \*supported) | Checks whether the current device supports microphone blocking detection. | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_SetMicBlockStatusCallback](_o_h_audio.md#oh_audioroutingmanager_setmicblockstatuscallback)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioRoutingManager_OnDeviceBlockStatusCallback](_o_h_audio.md#oh_audioroutingmanager_ondeviceblockstatuscallback) callback, void \*userData) | Sets a callback function to be invoked when the microphone's blocked status is changed. | 
