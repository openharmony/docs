# 相机控制器(ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

从API version 20开始，相机框架通过相机控制器，为应用直播场景提供美颜、虚化等能力。

相机控制器服务于直播场景，仅支持前置镜头下的[VideoSession](../../reference/apis-camera-kit/arkts-apis-camera-VideoSession.md)，支持分辨率上限1080P，帧率上限30fps。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/arkts-apis-camera.md)。

1. 导入camera接口，接口中提供了相机相关的属性和方法，导入方法如下。

```ts
import { camera } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';
```
2. 通过[VideoSession](../../reference/apis-camera-kit/arkts-apis-camera-VideoSession.md)的[isControlCenterSupported](../../reference/apis-camera-kit/arkts-apis-camera-ControlCenterQuery.md#iscontrolcentersupported20)接口，查询当前设备及当前场景是否支持相机控制器。

```ts
function isControlCenterSupported(videoSession: camera.VideoSession): boolean {
    let isSupported: boolean = videoSession.isControlCenterSupported();
    return isSupported;
}
```

3. 通过[VideoSesssion](../../reference/apis-camera-kit/arkts-apis-camera-VideoSession.md)的[getSupportedEffectTypes](../../reference/apis-camera-kit/arkts-apis-camera-ControlCenterQuery.md#getsupportedeffecttypes20)接口，查询当前设备及当前场景下，相机控制器支持的效果类型。

```ts
function getSupportedEffectTypes(videoSession: camera.VideoSession): Array<camera.ControlCenterEffectType> {
    let effectTypes: Array<camera.ControlCenterEffectType> = [];
    effectTypes = videoSession.getSupportedEffectTypes();
    return effectTypes;
}
```

4. 若当前设备及当前场景支持相机控制器，通过[VideoSesssion](../../reference/apis-camera-kit/arkts-apis-camera-VideoSession.md)的[enableControlCenter](../../reference/apis-camera-kit/arkts-apis-camera-ControlCenter.md#enablecontrolcenter20)接口，可以使能或关闭相机控制器。

```ts
function enableControlCenter(videoSession: camera.VideoSession, enable: boolean): void {
    let isSupported: boolean = videoSession.isControlCenterSupported();
    if (isSupported) {
        videoSession.enableControlCenter(enable);
    }
}
```

使能相机控制器后，可以在状态栏看到新增的视频效果图标。

![camera-control-center-status](figures/camera-control-center-status.png)

点击视频效果图标，在弹出的二级页面中，用户可调节控制器支持的效果，如图所示为美颜和背景虚化。

![camera-control-center](figures/camera-control-center.png)


## 状态监听

使用相机控制器的过程中，应用可以监听控制器效果的使能状态。

通过注册[controlCenterEffectStatusChange](../../reference/apis-camera-kit/arkts-apis-camera-VideoSession.md#oncontrolcentereffectstatuschange20)的回调函数获取控制器中各效果的使能状态。

当控制器中某效果使能状态发生变化时，callback返回[ControlCenterStatusInfo](../../reference/apis-camera-kit/arkts-apis-camera-i.md#controlcenterstatusinfo20)参数。

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, status: camera.ControlCenterStatusInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`controlCenterEffectStatusChange: ${status}`);
}

function registerControlCenterEffectStatusChangeCallback(videoSession: camera.VideoSession): void {
  videoSession.on('controlCenterEffectStatusChange', callback);
}
```