# Multimedia Subsystem Changelog

## c1.multimedia.1 Behavior Change in the Audio Framework for Identifying USB Audio Device Types
**Access Level**

Public API

**Reason for Change**

Previously, all USB audio devices are recognized by the system as headset input/output devices. To improve recognition accuracy and meet the UX display requirements of applications, the system now differentiates between USB headsets and ordinary USB audio devices (such as speakers).

**Impact of the Change**

This change requires application adaptation.

When audio devices are connected or disconnected, the system reports the type of audio device to the application. Applications can also actively query the available device types through interfaces. For applications targeting API levels before 18, the system behavior remains unchanged. For applications targeting API level 18 and later, the identification and reporting of USB devices have been changed as follows:

TS APIs

| Platform| Before Change| After Change|
| --- | ----- | ----- |
| General| If only an input device is present at a USB address, it is recognized as a USB_HEADSET.| If only an input device is present at a USB address, it is recognized as a USB_DEVICE.|
| PC/2-in-1 device| If only an output device is present at a USB address, it is recognized as a USB_HEADSET.| If only an output device is present at a USB address, it is recognized as a USB_DEVICE.|

NDK APIs
| Platform| Before Change| After Change|
| --- | ----- | ----- |
| General| If only an input device is present at a USB address, it is recognized as an AUDIO_DEVICE_USB_HEADSET.| If only an input device is present at a USB address, it is recognized as an AUDIO_DEVICE_USB_DEVICE.|
| PC/2-in-1 device| If only an output device is present at a USB address, it is recognized as an AUDIO_DEVICE_USB_HEADSET.| If only an output device is present at a USB address, it is recognized as an AUDIO_DEVICE_USB_DEVICE.|

**Start API Level**

9

**Change Since**

OpenHarmony 5.1.0.53

**Key API/Component Changes**

After this change, when a single-input or single-output USB audio device is connected to the system, the device type returned by the following APIs changes:

@ohos.multimedia.audio.d.ts ArkTS APIs:

| Class | API |
|---|---|
| audio.AudioRoutingManager  |  getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback\<AudioDeviceDescriptors>): void |
| audio.AudioRoutingManager  |  getDevices(deviceFlag: DeviceFlag): Promise\<AudioDeviceDescriptors> |
| audio.AudioRoutingManager  |  getDevicesSync(deviceFlag: DeviceFlag): AudioDeviceDescriptors |
| audio.AudioRoutingManager  |  getAvailableDevices(deviceUsage: DeviceUsage): AudioDeviceDescriptors |
| audio.AudioRoutingManager  |  on(type: 'availableDeviceChange', deviceUsage: DeviceUsage, callback: Callback\<DeviceChangeAction>): void |
| audio.AudioRoutingManager  |  off(type: 'availableDeviceChange', callback?: Callback\<DeviceChangeAction>): void |

C APIs in **native_audio_routing_manager.h**:

| API|
|--|
| OH_AudioCommon_Result OH_AudioRoutingManager_GetDevices(OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Flag deviceFlag, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray) |
| OH_AudioCommon_Result OH_AudioRoutingManager_GetAvailableDevices(OH_AudioRoutingManager *audioRoutingManager, OH_AudioDevice_Usage deviceUsage, OH_AudioDeviceDescriptorArray **audioDeviceDescriptorArray) |

**Adaptation Guide**

TS APIs

If your application has specific handling requirements for USB audio devices, you now need to handle both USB_HEADSET and USB_DEVICE types.
```cpp
// Perform special processing for the USB audio device.
if (devicetype == DeviceType.USB_HEADSET) {
  // do sth
}
```

After the change, if your application has specific handling requirements for USB audio devices, you now need to handle both USB_HEADSET and USB_DEVICE types.
```cpp
// Perform special processing for the USB audio device.
if (devicetype == DeviceType.USB_HEADSET || devicetype == DeviceType.USB_DEVICE) {
  // do sth
}
```


NDK APIs

If your application has specific handling requirements for USB audio devices, you now need to handle both AUDIO_DEVICE_USB_HEADSET and AUDIO_DEVICE_USB_DEVICE types.

Before the change, if your application has specific handling requirements for USB audio devices, you only need to handle AUDIO_DEVICE_USB_HEADSET.

```cpp
// Perform special processing for the USB audio device.
if (devicetype == OH_AudioDevice_Type.AUDIO_DEVICE_USB_HEADSET) {
  // do sth
}
```

After the change, if your application has specific handling requirements for USB audio devices, you now need to handle both AUDIO_DEVICE_USB_HEADSET and AUDIO_DEVICE_USB_DEVICE types.
```cpp
// Perform special processing for the USB audio device.
if (devicetype == OH_AudioDevice_Type.AUDIO_DEVICE_USB_HEADSET || devicetype == OH_AudioDevice_Type.AUDIO_DEVICE_USB_DEVICE) {
  // do sth
}
```
