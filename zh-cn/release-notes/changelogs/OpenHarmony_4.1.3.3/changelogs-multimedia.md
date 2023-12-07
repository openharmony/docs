# multimedia子系统变更说明

## cl.multimedia.1 audioRender和audioCapturer回调接口变更

**访问级别**

公开接口

**变更原因**

audioRender和audioCapturer回调接口,为了更准确反馈当前流的发声/录音设备，回调信息存在变化。

**变更影响**

该变更为非兼容性变更，可能影响三方应用的兼容性。

**变更发生版本**

从OpenHarmony SDK 4.1.3.3开始。

**变更的接口/组件**

变更前：

on(type: 'audioRendererChange', callback: Callback<AudioRendererChangeInfoArray>): void;

on(type: 'audioCapturerChange', callback: Callback<AudioCapturerChangeInfoArray>): void;

非播放/录音状态时，AudAudioRendererChangeInfo.deviceDescriptors和AudAudioRendererChangeInfo.deviceDescriptors为上一次播放/录音的设备；

变更后：

on(type: 'audioRendererChange', callback: Callback<AudioRendererChangeInfoArray>): void;

on(type: 'audioCapturerChange', callback: Callback<AudioCapturerChangeInfoArray>): void;

非播放/录音状态时，AudAudioRendererChangeInfo.deviceDescriptors和AudAudioRendererChangeInfo.deviceDescriptors为空设备；

**适配指导**

修改后用户调用该接口时，如果需要通过回调获取当前发声/录音设备，需要先启动播放/录音。