# Interface (ColorManagement)

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

ColorManagement extends [ColorManagementQuery](arkts-apis-camera-ColorManagementQuery.md)

色彩管理类，用于设置色彩空间参数。

## 导入模块

```ts
import { camera } from '@kit.CameraKit';
```

## setColorSpace<sup>12+</sup>

setColorSpace(colorSpace: colorSpaceManager.ColorSpace): void

设置色彩空间。可以先通过[getSupportedColorSpaces](arkts-apis-camera-ColorManagementQuery.md#getsupportedcolorspaces12)获取当前设备所支持的ColorSpaces。

**P3广色域与HDR高动态范围成像**

应用可以下发不同的色彩空间(ColorSpace)参数来支持P3广色域以及HDR的功能。  
当应用不主动设置色彩空间时，拍照模式默认为SDR拍摄效果。  
在拍照模式下设置HDR高显效果可直接支持P3色域。  
应用针对不同模式使能HDR效果以及设置的色彩空间可参考下表。  

**录像模式：**

| SDR/HRD拍摄         | CameraFormat             | ColorSpace       |
|--------------------|--------------------------|------------------|
| SDR                | CAMERA_FORMAT_YUV_420_SP | BT709_LIMIT      |
| HDR_VIVID          | CAMERA_FORMAT_YCRCB_P010 | BT2020_HLG_LIMIT |

**拍照模式：**

| SDR/HRD拍摄        | ColorSpace |
|--------------------|------------|
| SDR(Default)       | SRGB       |
| HDR                | DISPLAY_P3 |

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                 | 必填 | 说明                      |
| ------------ |---------------------- | -- | -------------------------- |
| colorSpace | [colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace)  | 是 | 色彩空间，通过[getSupportedColorSpaces](arkts-apis-camera-ColorManagementQuery.md#getsupportedcolorspaces12)接口获取。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101         |  Parameter missing or parameter type incorrect.     |
| 7400102         |  The colorSpace does not match the format.     |
| 7400103         |  Session not config.                           |
| 7400201         |  Camera service fatal error.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { colorSpaceManager } from '@kit.ArkGraphics2D';

function setColorSpace(session: camera.PhotoSession, colorSpaces: Array<colorSpaceManager.ColorSpace>): void {
  if (colorSpaces === undefined || colorSpaces.length <= 0) {
    return;
  }
  try {
    session.setColorSpace(colorSpaces[0]);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The setColorSpace call failed, error code: ${err.code}`);
  }
}
```

## getActiveColorSpace<sup>12+</sup>

getActiveColorSpace(): colorSpaceManager.ColorSpace

获取当前设置的色彩空间。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace)               | 当前设置的色彩空间。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { colorSpaceManager } from '@kit.ArkGraphics2D';

function getActiveColorSpace(session: camera.PhotoSession): colorSpaceManager.ColorSpace | undefined {
  let colorSpace: colorSpaceManager.ColorSpace | undefined = undefined;
  try {
    colorSpace = session.getActiveColorSpace();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getActiveColorSpace call failed. error code: ${err.code}`);
  }
  return colorSpace;
}
```
