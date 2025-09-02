# Interface (QuickImageDataHandler)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 13.

QuickImageDataHandler is a media asset handler used to customize the media asset processing logic in **onDataPrepared**.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

## Modules to Import

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## onDataPrepared<sup>13+</sup>

onDataPrepared(data: T, imageSource: image.ImageSource, map: Map<string, string>): void

Called when the requested image is ready. If an error occurs, **data** returned by the callback is **undefined**.

Information returned by **map**:

| Map Key | **Description**|
|----------|-------|
| 'quality'  | Image quality. The value **high** means high quality, and **low** means poor quality.|

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type| Mandatory| Description                                                                           |
|------|---| ---- |-------------------------------------------------------------------------------|
| data | T | Yes  | Data of the image asset that is ready. It is of the generic type and supports the [Picture](../apis-image-kit/arkts-apis-image-Picture.md) type.|
| imageSource | image.ImageSource | Yes  | Data of the image asset that is ready.|
| map<sup>13+</sup> | Map<string, string> | Yes  | Additional information about the image asset, such as the image quality. Currently, only **quality** is supported.|

**Example**

```ts
import { image } from '@kit.ImageKit';

class MediaHandler implements photoAccessHelper.QuickImageDataHandler<image.Picture> {
  onDataPrepared(data: image.Picture, imageSource: image.ImageSource, map: Map<string, string>) {
    console.info('on image data prepared');
  }
}
```
