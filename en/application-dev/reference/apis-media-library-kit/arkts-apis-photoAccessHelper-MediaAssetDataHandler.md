# Interface (MediaAssetDataHandler)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 11.

MediaAssetDataHandler is a media asset handler used to customize the media asset processing logic in **onDataPrepared**.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

## Modules to Import

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## onDataPrepared<sup>11+</sup>

onDataPrepared(data: T, map?: Map<string, string>): void

Called when the requested media asset is ready. If an error occurs, **data** returned by the callback is **undefined**. Each media asset request corresponds to a callback.

T supports the following data types: ArrayBuffer, [ImageSource](../apis-image-kit/arkts-apis-image-ImageSource.md), [MovingPhoto](arkts-apis-photoAccessHelper-MovingPhoto.md), and boolean. ArrayBuffer indicates the image or video asset data, [ImageSource](../apis-image-kit/arkts-apis-image-ImageSource.md) indicates the image source, [MovingPhoto](arkts-apis-photoAccessHelper-MovingPhoto.md) indicates a moving photo object, and boolean indicates whether the image or video is successfully written to the application sandbox directory.

Information returned by **map**:

| Map Key | Description|
|----------|-------|
| 'quality'  | Image quality. The value **high** means high quality, and **low** means poor quality.|

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type| Mandatory| Description                                                                           |
|------|---| ---- |-------------------------------------------------------------------------------|
| data | T | Yes  | Data of the image asset that is ready. It is of the generic type and supports the following data types: ArrayBuffer, [ImageSource](../apis-image-kit/arkts-apis-image-ImageSource.md), [MovingPhoto](arkts-apis-photoAccessHelper-MovingPhoto.md), and boolean.|
| map<sup>12+</sup> | Map<string, string> | No  | Additional information about the image asset, such as the image quality. Currently, only **quality** is supported.|

**Example**

```ts
import { image } from '@kit.ImageKit';

class MediaHandler implements photoAccessHelper.MediaAssetDataHandler<image.ImageSource> {
  onDataPrepared = (data: image.ImageSource, map: Map<string, string>) => {
    if (data === undefined) {
      console.error('Error occurred when preparing data');
      return;
    }
    // Customize the processing logic for ImageSource.
    console.info('on image data prepared, photo quality is ' + map['quality']);
  }
}

class MediaDataHandler implements photoAccessHelper.MediaAssetDataHandler<ArrayBuffer> {
  onDataPrepared = (data: ArrayBuffer, map: Map<string, string>) => {
    if (data === undefined) {
      console.error('Error occurred when preparing data');
      return;
    }
    // Customize the processing logic for ArrayBuffer.
    console.info('on image data prepared, photo quality is ' + map['quality']);
  }
}

class MovingPhotoHandler implements photoAccessHelper.MediaAssetDataHandler<photoAccessHelper.MovingPhoto> {
  onDataPrepared = (data: photoAccessHelper.MovingPhoto, map: Map<string, string>) => {
    if (data === undefined) {
      console.error('Error occurred when preparing data');
      return;
    }
    // Customize the processing logic for MovingPhoto.
    console.info('on image data prepared, photo quality is ' + map['quality']);
  }
}
```
