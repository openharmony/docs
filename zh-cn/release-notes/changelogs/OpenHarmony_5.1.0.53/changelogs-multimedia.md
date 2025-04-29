# 媒体子系统变更说明

## c1.multimedia.1 音频框架识别USB音频设备类型行为变更
**访问级别**

公开接口

**变更原因**

原有的USB音频设备在系统侧均识别为耳机输入/输出设备。为了提高识别的准确度，满足应用的UX显示需求，系统侧区分USB耳机和普通的USB音频设备(如音箱)。

**变更影响**

此变更涉及应用适配。
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

TS：@ohos.multimedia.audio.d.ts中DeviceType的USB_HEADSET接口。

NDK: native_audio_device_base.h中OH_AudioDevice_Type的AUDIO_DEVICE_USB_HEADSET接口。

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