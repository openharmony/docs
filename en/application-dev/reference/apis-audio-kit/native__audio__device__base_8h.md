# native_audio_device_base.h


## Overview

The **native_audio_device_base.h** file declares the types of audio device parameters and the functions for obtaining these parameters.

**Library**: libohaudio.so

**File to include**: &lt;ohaudio/native_audio_device_base.h&gt;

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) | Describes an array of audio device descriptors. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) [OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) | Defines a struct for an audio device descriptor. It provides detailed attributes of an audio device. | 
| typedef struct [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) [OH_AudioDeviceDescriptorArray](_o_h_audio.md#oh_audiodevicedescriptorarray) | Defines a struct for an array of audio device descriptors. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AudioDevice_ChangeType](_o_h_audio.md#oh_audiodevice_changetype) {<br>AUDIO_DEVICE_CHANGE_TYPE_CONNECT = 0,<br>AUDIO_DEVICE_CHANGE_TYPE_DISCONNECT = 1<br>} | Enumerates the types of audio device changes.| 
| [OH_AudioDevice_Role](_o_h_audio.md#oh_audiodevice_role) {<br>AUDIO_DEVICE_ROLE_INPUT = 1,<br>AUDIO_DEVICE_ROLE_OUTPUT = 2<br>} | Enumerates the roles of audio devices.| 
| [OH_AudioDevice_Type](_o_h_audio.md#oh_audiodevice_type) {<br>AUDIO_DEVICE_TYPE_INVALID = 0,<br>AUDIO_DEVICE_TYPE_EARPIECE = 1,<br>AUDIO_DEVICE_TYPE_SPEAKER = 2,<br>AUDIO_DEVICE_TYPE_WIRED_HEADSET = 3,<br>AUDIO_DEVICE_TYPE_WIRED_HEADPHONES = 4,<br>AUDIO_DEVICE_TYPE_BLUETOOTH_SCO = 7,<br>AUDIO_DEVICE_TYPE_BLUETOOTH_A2DP = 8,<br>AUDIO_DEVICE_TYPE_MIC = 15,<br>AUDIO_DEVICE_TYPE_USB_HEADSET = 22,<br>AUDIO_DEVICE_TYPE_DISPLAY_PORT = 23,<br>AUDIO_DEVICE_TYPE_REMOTE_CAST = 24,<br>AUDIO_DEVICE_TYPE_DEFAULT = 1000<br>} | Enumerates the types of audio devices.| 
| [OH_AudioDevice_Flag](_o_h_audio.md#oh_audiodevice_flag) {<br>AUDIO_DEVICE_FLAG_NONE = 0,<br>AUDIO_DEVICE_FLAG_OUTPUT = 1,<br>AUDIO_DEVICE_FLAG_INPUT = 2,<br>AUDIO_DEVICE_FLAG_ALL = 3<br>} | Enumerates the flags of audio devices.| 
| [OH_AudioDevice_Usage](_o_h_audio.md#oh_audiodevice_usage) {<br>AUDIO_DEVICE_USAGE_MEDIA_OUTPUT = 1, <br>AUDIO_DEVICE_USAGE_MEDIA_INPUT = 2, <br>AUDIO_DEVICE_USAGE_MEDIA_ALL = 3, <br>AUDIO_DEVICE_USAGE_CALL_OUTPUT = 4,<br>AUDIO_DEVICE_USAGE_CALL_INPUT = 8, <br>AUDIO_DEVICE_USAGE_CALL_ALL = 12<br>} | Enumerates the usage scenarios of audio devices. | 
| [OH_AudioDevice_BlockStatus](_o_h_audio.md#oh_audiodevice_blockstatus) { <br>AUDIO_DEVICE_UNBLOCKED = 0, <br>AUDIO_DEVICE_BLOCKED = 1 } | Enumerates the blocked status of audio devices. By default, an audio device is not blocked.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceRole](_o_h_audio.md#oh_audiodevicedescriptor_getdevicerole) ([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioDevice_Role](_o_h_audio.md#oh_audiodevice_role) \*deviceRole) | Obtains the device role based on an audio device descriptor.| 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceType](_o_h_audio.md#oh_audiodevicedescriptor_getdevicetype) ([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioDevice_Type](_o_h_audio.md#oh_audiodevice_type) \*deviceType) | Obtains the device type based on an audio device descriptor.| 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceId](_o_h_audio.md#oh_audiodevicedescriptor_getdeviceid) ([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*id) | Obtains the device ID based on an audio device descriptor.| 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceName](_o_h_audio.md#oh_audiodevicedescriptor_getdevicename) ([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*name) | Obtains the device name based on an audio device descriptor.| 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceAddress](_o_h_audio.md#oh_audiodevicedescriptor_getdeviceaddress) ([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*address) | Obtains the device address based on an audio device descriptor.| 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceSampleRates](_o_h_audio.md#oh_audiodevicedescriptor_getdevicesamplerates) ([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*\*sampleRates, uint32_t \*size) | Obtains the sample rates based on an audio device descriptor.| 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceChannelCounts](_o_h_audio.md#oh_audiodevicedescriptor_getdevicechannelcounts) ([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*\*channelCounts, uint32_t \*size) | Obtains an array that holds the number of device channels based on an audio device descriptor.| 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceDisplayName](_o_h_audio.md#oh_audiodevicedescriptor_getdevicedisplayname) ([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*displayName) | Obtains the device display name based on an audio device descriptor.| 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceEncodingTypes](_o_h_audio.md#oh_audiodevicedescriptor_getdeviceencodingtypes) ([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioStream_EncodingType](_o_h_audio.md#oh_audiostream_encodingtype) \*\*encodingTypes, uint32_t \*size) | Obtains the device encoding types based on an audio device descriptor.| 
