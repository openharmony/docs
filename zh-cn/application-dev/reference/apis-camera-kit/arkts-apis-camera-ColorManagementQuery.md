# Interface (ColorManagementQuery)

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 12开始支持。

色彩管理类，用于查询色彩空间参数。

## 导入模块

```ts
import { camera } from '@kit.CameraKit';
```

## getSupportedColorSpaces<sup>12+</sup>

getSupportedColorSpaces(): Array\<colorSpaceManager.ColorSpace\>

获取支持的色彩空间列表。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Array<[colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace)>| 支持的色彩空间列表。     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { colorSpaceManager } from '@kit.ArkGraphics2D';

function getSupportedColorSpaces(session: camera.PhotoSession): Array<colorSpaceManager.ColorSpace> {
  let colorSpaces: Array<colorSpaceManager.ColorSpace> = [];
  colorSpaces = session.getSupportedColorSpaces();
  return colorSpaces;
}
```
