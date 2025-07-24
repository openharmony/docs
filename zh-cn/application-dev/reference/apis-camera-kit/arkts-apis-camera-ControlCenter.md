# Interface (ControlCenter)

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 20开始支持。

ControlCenter extends [ControlCenterQuery](arkts-apis-camera-ControlCenterQuery.md)

控制中心类，用于使能相机控制器。

## 导入模块

```ts
import { camera } from '@kit.CameraKit';
```

## enableControlCenter<sup>20+</sup>

enableControlCenter(enabled: boolean): void

使能相机控制器。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                  |
| -------- | -------------------- | ---- | -------------------- |
| enabled | boolean | 是 | 开启或关闭相机控制器。true表示开启，false表示关闭。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID    | 错误信息                     |
|----------|--------------------------|
| 7400103  | Session not config.      |

**示例：**

```ts
function enableControlCenter(videoSession: camera.VideoSession, enable: boolean): void {
    let isSupported: boolean = videoSession.isControlCenterSupported();
    if (isSupported) {
        videoSession.enableControlCenter(enable);
    }
}
```