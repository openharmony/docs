# 媒体子系统变更说明

## c1.multimedia.1 音频框架识别USB音频设备类型行为变更
**访问级别**

公开接口

**变更原因**

原有的USB音频设备在系统侧均识别为耳机输入/输出设备。为了提高识别的准确度，满足应用的UX显示需求，系统侧区分USB耳机和普通的USB音频设备(如音箱)。

**变更影响**

此变更涉及应用适配。
当音频设备上下线时，会向应用上报某个类型的音频设备上线。应用也可以通过接口主动查询可用的设备类型。针对API18以前的应用，系统的行为保持不变。针对API18及以后的应用，USB型的设备识别和上报发生了如下变更：
TS接口
| 平台 | 变更前 | 变更后 |
| --- | ----- | ----- |
| 通用 | 同USB地址下只有输入设备，识别为USB_HEADSET。| 同USB地址下只有输入设备，识别为USB_DEVICE。|
| PC/2in1 | 同USB地址下只有输出设备，识别为USB_HEADSET。| 同USB地址下只有输出设备，识别为USB_DEVICE。|

NDK接口
| 平台 | 变更前 | 变更后 |
| --- | ----- | ----- |
| 通用 | 同USB地址下只有输入设备，识别为AUDIO_DEVICE_USB_HEADSET。| 同USB地址下只有输入设备，识别为AUDIO_DEVICE_USB_DEVICE。|
| PC/2in1 | 同USB地址下只有输出设备，识别为AUDIO_DEVICE_USB_HEADSET。| 同USB地址下只有输出设备，识别为AUDIO_DEVICE_USB_DEVICE。|

**起始API Level**

9

**变更发生版本**

从OpenHarmony 5.1.0.53开始。

**变更的接口/组件**

本次变更后，当单输入或者单输出的USB音频设备接入系统后，如下接口返回的设备类型发生变化：

@ohos.multimedia.audio.d.ts中的ArkTS API：

| 类  | 接口  |
|---|---|
| audio.AudioRoutingManager  |  getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback\<AudioDeviceDescriptors>): void |
| audio.AudioRoutingManager  |  getDevices(deviceFlag: DeviceFlag): Promise\<AudioDeviceDescriptors> |
| audio.AudioRoutingManager  |  getDevicesSync(deviceFlag: DeviceFlag): AudioDeviceDescriptors |
| audio.AudioRoutingManager  |  getAvailableDevices(deviceUsage: DeviceUsage): AudioDeviceDescriptors |
| audio.AudioRoutingManager  |  on(type: 'availableDeviceChange', deviceUsage: DeviceUsage, callback: Callback\<DeviceChangeAction>): void |
| audio.AudioRoutingManager  |  off(type: 'availableDeviceChange', callback?: Callback\<DeviceChangeAction>): void |

native_audio_routing_manager.h中的C API：

| 接口 |
|--|
| OH_AudioCommon_Result OH_AudioRoutingManager_GetDevices(OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Flag deviceFlag, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray) |
| OH_AudioCommon_Result OH_AudioRoutingManager_GetAvailableDevices(OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Usage deviceUsage, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray) |

**适配指导**

TS接口

如应用对USB音频设备有特殊处理需求，现在不仅需要处理USB_HEADSET类型的音频设备，还需将USB_DEVICE类型也纳入到处理范围内。
```cpp
// 针对usb音频设备做特殊处理
if (devicetype == DeviceType.USB_HEADSET) {
  // do sth
}
```

变更后：如应用对USB音频设备有特殊处理需求，不仅要考虑USB_HEADSET类型，也要考虑USB_DEVICE类型的音频设备。
```cpp
// 针对usb音频设备做特殊处理
if (devicetype == DeviceType.USB_HEADSET || devicetype == DeviceType.USB_DEVICE) {
  // do sth
}
```


NDK接口

如应用对USB音频设备有特殊处理需求，现在不仅需要处理AUDIO_DEVICE_USB_HEADSET类型的音频设备，还需将AUDIO_DEVICE_USB_DEVICE类型也纳入到处理范围内。
变更前：如应用对USB音频设备有特殊处理需求，仅处理AUDIO_DEVICE_USB_HEADSET类型的音频设备即可。
```cpp
// 针对usb音频设备做特殊处理
if (devicetype == OH_AudioDevice_Type.AUDIO_DEVICE_USB_HEADSET) {
  // do sth
}
```

变更后：如应用对USB音频设备有特殊处理需求，不仅要考虑AUDIO_DEVICE_USB_HEADSET类型，也要考虑AUDIO_DEVICE_USB_DEVICE类型的音频设备。
```cpp
// 针对usb音频设备做特殊处理
if (devicetype == OH_AudioDevice_Type.AUDIO_DEVICE_USB_HEADSET || devicetype == OH_AudioDevice_Type.AUDIO_DEVICE_USB_DEVICE) {
  // do sth
}
```