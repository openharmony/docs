# native_audio_device_base.h


## 概述

定义音频设备参数的类型以及获取每个设备参数的接口。

**库：** libohaudio.so

**引用文件**：&lt;ohaudio/native_audio_device_base.h&gt;

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**相关模块：**[OHAudio](_o_h_audio.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) | 声明音频设备描述符数组。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) [OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) | 声明音频设备描述符。 该实例用于获取更多音频设备详细信息属性。  | 
| typedef struct [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) [OH_AudioDeviceDescriptorArray](_o_h_audio.md#oh_audiodevicedescriptorarray) | 声明音频设备描述符数组。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioDevice_ChangeType](_o_h_audio.md#oh_audiodevice_changetype) {<br/>AUDIO_DEVICE_CHANGE_TYPE_CONNECT = 0,<br/>AUDIO_DEVICE_CHANGE_TYPE_DISCONNECT = 1<br/>} | 定义音频设备更改类型。 | 
| [OH_AudioDevice_Role](_o_h_audio.md#oh_audiodevice_role) {<br/>AUDIO_DEVICE_ROLE_INPUT = 1,<br/>AUDIO_DEVICE_ROLE_OUTPUT = 2<br/>} | 定义音频设备角色。 | 
| [OH_AudioDevice_Type](_o_h_audio.md#oh_audiodevice_type) {<br/>AUDIO_DEVICE_TYPE_INVALID = 0,<br/>AUDIO_DEVICE_TYPE_EARPIECE = 1,<br/>AUDIO_DEVICE_TYPE_SPEAKER = 2,<br/>AUDIO_DEVICE_TYPE_WIRED_HEADSET = 3,<br/>AUDIO_DEVICE_TYPE_WIRED_HEADPHONES = 4,<br/>AUDIO_DEVICE_TYPE_BLUETOOTH_SCO = 7,<br/>AUDIO_DEVICE_TYPE_BLUETOOTH_A2DP = 8,<br/>AUDIO_DEVICE_TYPE_MIC = 15,<br/>AUDIO_DEVICE_TYPE_USB_HEADSET = 22,<br/>AUDIO_DEVICE_TYPE_DISPLAY_PORT = 23,<br/>AUDIO_DEVICE_TYPE_REMOTE_CAST = 24,<br/>AUDIO_DEVICE_TYPE_HDMI = 27,<br/>AUDIO_DEVICE_TYPE_LINE_DIGITAL = 28,<br/>AUDIO_DEVICE_TYPE_DEFAULT = 1000<br/>} | 定义音频设备类型。 | 
| [OH_AudioDevice_Flag](_o_h_audio.md#oh_audiodevice_flag) {<br/>AUDIO_DEVICE_FLAG_NONE = 0,<br/>AUDIO_DEVICE_FLAG_OUTPUT = 1,<br/>AUDIO_DEVICE_FLAG_INPUT = 2,<br/>AUDIO_DEVICE_FLAG_ALL = 3<br/>} | 定义音频设备标志。 | 
| [OH_AudioDevice_Usage](_o_h_audio.md#oh_audiodevice_usage) {<br/>AUDIO_DEVICE_USAGE_MEDIA_OUTPUT = 1, <br/>AUDIO_DEVICE_USAGE_MEDIA_INPUT = 2, <br/>AUDIO_DEVICE_USAGE_MEDIA_ALL = 3, <br/>AUDIO_DEVICE_USAGE_CALL_OUTPUT = 4,<br/>AUDIO_DEVICE_USAGE_CALL_INPUT = 8, <br/>AUDIO_DEVICE_USAGE_CALL_ALL = 12<br/>} | 定义可获取的设备种类。  | 
| [OH_AudioDevice_BlockStatus](_o_h_audio.md#oh_audiodevice_blockstatus) { <br/>AUDIO_DEVICE_UNBLOCKED = 0, <br/>AUDIO_DEVICE_BLOCKED = 1 } | 声明音频设备的堵塞状态。默认情况下，音频设备被视为未堵塞。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceRole](_o_h_audio.md#oh_audiodevicedescriptor_getdevicerole)([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioDevice_Role](_o_h_audio.md#oh_audiodevice_role) \*deviceRole) | 查询目标音频设备描述符的设备角色。 | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceType](_o_h_audio.md#oh_audiodevicedescriptor_getdevicetype)([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioDevice_Type](_o_h_audio.md#oh_audiodevice_type) \*deviceType) | 查询目标音频设备描述符的设备类型。 | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceId](_o_h_audio.md#oh_audiodevicedescriptor_getdeviceid)([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*id) | 查询目标音频设备描述符的设备id。 | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceName](_o_h_audio.md#oh_audiodevicedescriptor_getdevicename)([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*name) | 查询目标音频设备描述符的设备名称。 | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceAddress](_o_h_audio.md#oh_audiodevicedescriptor_getdeviceaddress)([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*address) | 查询目标音频设备描述符的设备地址。 | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceSampleRates](_o_h_audio.md#oh_audiodevicedescriptor_getdevicesamplerates)([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*\*sampleRates, uint32_t \*size) | 查询目标音频设备描述符的采样率数组。 | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceChannelCounts](_o_h_audio.md#oh_audiodevicedescriptor_getdevicechannelcounts)([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, uint32_t \*\*channelCounts, uint32_t \*size) | 查询目标音频设备描述符的设备通道计数数组。 | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceDisplayName](_o_h_audio.md#oh_audiodevicedescriptor_getdevicedisplayname)([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, char \*\*displayName) | 查询目标音频设备描述符的显示名称。 | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioDeviceDescriptor_GetDeviceEncodingTypes](_o_h_audio.md#oh_audiodevicedescriptor_getdeviceencodingtypes)([OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*audioDeviceDescriptor, [OH_AudioStream_EncodingType](_o_h_audio.md#oh_audiostream_encodingtype) \*\*encodingTypes, uint32_t \*size) | 查询目标音频设备描述符的编码类型数组。 | 
