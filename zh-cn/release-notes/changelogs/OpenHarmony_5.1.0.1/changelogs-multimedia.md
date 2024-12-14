# 媒体子系统ChangeLog

## c1.multimedia.1 ohos.multimedia.audio USB音频设备类型识别行为变更
**访问级别**

公开接口

**变更原因**

原有的USB音频设备在系统侧均识别为耳机输入/输出设备。为了提高识别的准确度，满足应用的UX显示需求，系统侧区分USB耳机和普通的USB音频设备。

**变更影响**

非兼容性变更：如应用对USB音频设备有特殊处理需求，现在不仅需要处理USB_HEADSET类型的音频设备，还需将USB_DEVICE类型也纳入到处理范围内。

**变更发生版本**

从OpenHarmony SDK 5.1.0.XX开始。

**变更的接口/组件**

@ohos.multimedia.audio.d.ts中DeviceType的USB_HEADSET接口。

**适配指导**

如应用对USB音频设备有特殊处理需求，现在不仅需要处理USB_HEADSET类型的音频设备，还需将USB_DEVICE类型也纳入到处理范围内。

## c1.multimedia.2 native_audio_device_base.h USB音频设备类型识别行为变更
**访问级别**

公开接口

**变更原因**

原有的USB音频设备在系统侧均识别为耳机输入/输出设备。为了提高识别的准确度，满足应用的UX显示需求，系统侧区分USB耳机和普通的USB音频设备。

**变更影响**

非兼容性变更：如应用对USB音频设备有特殊处理需求，现在不仅需要处理USB_HEADSET类型的音频设备，还需将USB_DEVICE类型也纳入到处理范围内。

**变更发生版本**

从OpenHarmony SDK 5.1.0.xx开始。

**变更的接口/组件**

native_audio_device_base.h中OH_AudioDevice_Type的AUDIO_DEVICE_USB_HEADSET接口。

**适配指导**

如应用对USB音频设备有特殊处理需求，现在不仅需要处理USB_HEADSET类型的音频设备，还需将AUDIO_DEVICE_USB_DEVICE类型也纳入到处理范围内。