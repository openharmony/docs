# Interface (Photo)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 11开始支持。

全质量图对象。

## 导入模块

```ts
import { camera } from '@kit.CameraKit';
```

## 属性

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 类型                           |   只读    |   可选   | 说明       |
| ------ | ----------------------------- | --------  |  ------ | ---------- |
| main<sup>11+</sup> | [image.Image](../apis-image-kit/arkts-apis-image-Image.md) |    否   |    否    | 全质量图Image。 |

## release<sup>11+</sup>

release(): Promise\<void\>

释放输出资源。使用Promise异步回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<void\> | Promise对象，无返回结果。 |

**示例：**

```ts
async function releasePhoto(photo: camera.Photo): Promise<void> {
  await photo.release();
}
```
