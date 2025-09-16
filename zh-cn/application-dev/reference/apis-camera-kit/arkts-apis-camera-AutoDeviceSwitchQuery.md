# Interface (AutoDeviceSwitchQuery)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 13开始支持。

自动切换镜头查询类，用于查询设备是否支持自动切换镜头。

## 导入模块

```ts
import { camera } from '@kit.CameraKit';
```

## isAutoDeviceSwitchSupported<sup>13+</sup>

isAutoDeviceSwitchSupported(): boolean

查询设备是否支持自动切换镜头能力。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明          |
| ----------------------------------------------- |-------------|
| boolean               | 是否支持自动切换镜头，true为支持，false为不支持。 |

**示例：**

```ts
function isAutoDeviceSwitchSupported(session: camera.PhotoSession): boolean {
  let isSupported = false;
  isSupported = session.isAutoDeviceSwitchSupported();
  return isSupported;
}
```
