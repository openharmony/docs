# multimedia子系统变更说明

## cl.multimedia.1 audioRenderer和audioCapturer回调接口变更

**访问级别**

公开接口

**变更原因**

audioRenderer和audioCapturer回调接口,为了更准确反馈当前流的发声/录音设备，回调信息存在变化。

**变更影响**

非播放/录音状态时，AudioRendererChangeInfo.deviceDescriptors和AudioCapturerChangeInfo.deviceDescriptors为空设备。

**变更发生版本**

从OpenHarmony SDK 4.1.3.3开始。

**变更的接口/组件**

变更前：

on(type: 'audioRendererChange', callback: Callback<AudioRendererChangeInfoArray>): void;

on(type: 'audioCapturerChange', callback: Callback<AudioCapturerChangeInfoArray>): void;

非播放/录音状态时，AudioRendererChangeInfo.deviceDescriptors和AudioCapturerChangeInfo.deviceDescriptors为上一次播放/录音的设备。

变更后：

on(type: 'audioRendererChange', callback: Callback<AudioRendererChangeInfoArray>): void;

on(type: 'audioCapturerChange', callback: Callback<AudioCapturerChangeInfoArray>): void;

非播放/录音状态时，AudioRendererChangeInfo.deviceDescriptors和AudioCapturerChangeInfo.deviceDescriptors为空设备。

**适配指导**

修改后用户调用该接口时，如果需要通过回调获取当前发声/录音设备，需要先启动播放/录音。

## cl.multimedia.2 cameraInput的open和on回调接口行为变更

**访问级别**

公开接口

**变更原因**

cameraInput的open接口，新增抢占机制，保证高优先级应用可以优先使用相机，open和on回调接口行为出现变化。

**变更影响**

该变更为非兼容性变更，可能影响三方应用的兼容性。

**变更发生版本**

从OpenHarmony SDK 4.1.3.3开始。

**变更的接口/组件**

变更前：

on(type: 'error', camera: CameraDevice, callback: ErrorCallback): void;

open(callback: AsyncCallback<void>): void;

当存在其他应用正在使用相机设备时，当前应用使用open接口打开失败，回调CONFLICT_CAMERA错误码；

变更后：

on(type: 'error', camera: CameraDevice, callback: ErrorCallback): void;

open(callback: AsyncCallback<void>): void;

当存在其他应用正在使用相机设备时，当前应用若优先级高于其他应用，比如处于前台，其他应用已退后台，此时使用open接口打开成功，

之前使用相机的应用会收到回调DEVICE_PREEMPTED错误码；

**适配指导**

在使用cameraInput的on回调接口时，需要对错误码增加DEVICE_PREEMPTED错误的处理逻辑。