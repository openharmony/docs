# native_audio_routing_manager.h


## 概述

声明与音频路由管理器相关的接口。

包含用于创建audioRoutingManager，设备连接状态发生变化时的注册和注销功能，以及存储设备信息的指针数组的释放。

**库：** libohaudio.so

**引用文件**：&lt;ohaudio/native_audio_routing_manager.h&gt;

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**相关模块：**[OHAudio](_o_h_audio.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) [OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) | 声明音频路由管理器，用于路由和设备相关功能的音频路由管理器的句柄。  | 
| typedef int32_t (\*[OH_AudioRoutingManager_OnDeviceChangedCallback](_o_h_audio.md#oh_audioroutingmanager_ondevicechangedcallback))([OH_AudioDevice_ChangeType](_o_h_audio.md#oh_audiodevice_changetype) type, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*audioDeviceDescriptorArray) | 此函数指针将指向用于返回更改的音频设备描述符的回调函数，可能返回多个音频设备描述符。  | 
| typedef void (\*[OH_AudioRoutingManager_OnDeviceBlockStatusCallback](_o_h_audio.md#oh_audioroutingmanager_ondeviceblockstatuscallback))([OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*audioDeviceDescriptorArray, [OH_AudioDevice_BlockStatus](_o_h_audio.md#oh_audiodevice_blockstatus) status, void \*userData) | 此函数指针将指向用于返回音频设备堵塞状态的回调函数，可能返回多个音频设备描述符。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioManager_GetAudioRoutingManager](_o_h_audio.md#oh_audiomanager_getaudioroutingmanager)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*\*audioRoutingManager) | 查询音频路由管理器句柄，该句柄应设置为路由相关函数中的第一个参数。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_GetDevices](_o_h_audio.md#oh_audioroutingmanager_getdevices)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Flag](_o_h_audio.md#oh_audiodevice_flag) deviceFlag, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | 根据输入的deviceFlag查询可用的设备。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_GetAvailableDevices](_o_h_audio.md#oh_audioroutingmanager_getavailabledevices)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Usage](_o_h_audio.md#oh_audiodevice_usage) deviceUsage, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | 获取音频可选设备列表。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_GetPreferredOutputDevice](_o_h_audio.md#oh_audioroutingmanager_getpreferredoutputdevice)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioStream_Usage](_o_h_audio.md#oh_audiostream_usage) streamUsage, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | 根据音频输出流的使用场景，获取优先级最高的输出设备。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_GetPreferredInputDevice](_o_h_audio.md#oh_audioroutingmanager_getpreferredinputdevice)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioStream_SourceType](_o_h_audio.md#oh_audiostream_sourcetype) sourceType, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*\*audioDeviceDescriptorArray) | 根据音频输入流的使用场景，获取优先级最高的输入设备。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_RegisterDeviceChangeCallback](_o_h_audio.md#oh_audioroutingmanager_registerdevicechangecallback)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDevice_Flag](_o_h_audio.md#oh_audiodevice_flag) deviceFlag, [OH_AudioRoutingManager_OnDeviceChangedCallback](_o_h_audio.md#oh_audioroutingmanager_ondevicechangedcallback) callback) | 注册音频路由管理器的设备更改回调。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_UnregisterDeviceChangeCallback](_o_h_audio.md#oh_audioroutingmanager_unregisterdevicechangecallback)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioRoutingManager_OnDeviceChangedCallback](_o_h_audio.md#oh_audioroutingmanager_ondevicechangedcallback) callback) | 取消注册音频路由管理器的设备更改回调。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_ReleaseDevices](_o_h_audio.md#oh_audioroutingmanager_releasedevices)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioDeviceDescriptorArray](_o_h___audio_device_descriptor_array.md) \*audioDeviceDescriptorArray) | 释放音频设备描述符数组对象。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_IsMicBlockDetectionSupported](_o_h_audio.md#oh_audioroutingmanager_ismicblockdetectionsupported)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, bool \*supported) | 查询当前设备是否支持麦克风堵塞状态检测。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioRoutingManager_SetMicBlockStatusCallback](_o_h_audio.md#oh_audioroutingmanager_setmicblockstatuscallback)([OH_AudioRoutingManager](_o_h_audio.md#oh_audioroutingmanager) \*audioRoutingManager, [OH_AudioRoutingManager_OnDeviceBlockStatusCallback](_o_h_audio.md#oh_audioroutingmanager_ondeviceblockstatuscallback) callback, void \*userData) | 设置麦克风是否堵塞状态回调。  | 
