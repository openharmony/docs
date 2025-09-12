# Interface (Photo)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 11.

Photo defines a full-quality image object.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## Properties

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                          |   Read-Only   |   Optional  | Description      |
| ------ | ----------------------------- | --------  |  ------ | ---------- |
| main<sup>11+</sup> | [image.Image](../apis-image-kit/arkts-apis-image-Image.md) |    No  |    No   | Full-quality image.|

## release<sup>11+</sup>

release(): Promise\<void\>

Releases output resources. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<void\> | Promise that returns no value.|

**Example**

```ts
async function releasePhoto(photo: camera.Photo): Promise<void> {
  await photo.release();
}
```
