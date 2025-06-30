# @ohos.multimedia.movingphotoview (MovingPhotoView) (System API)

The **MovingPhotoView** component is used to play moving photos and control the playback status.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.multimedia.movingphotoview (MovingPhotoView)](ohos-multimedia-movingphotoview.md).

## MovingPhotoViewOptions


| Name     | Type                                                                                        | Mandatory| Description                                                                                                                                       |
| ----------- | ------------------------------------------------------------------------------------------------ | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| movingPhotoFormat<sup>14+</sup>  | [PixelMapFormat](#pixelmapformat14)    | No  | Decoding format of the cover image of the **MovingPhotoView** component.                 |
| dynamicRangeMode<sup>14+</sup>  | [DynamicRangeMode](#dynamicrangemode14) | No  | Range mode of the cover image of the **MovingPhotoView** component.|

## PixelMapFormat<sup>14+</sup>

Enumerates the decoding formats available for the cover image of the **MovingPhotoView** component.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  |   Value  | Description             |
| ---------------------- | ------ | ----------------- |
| UNKNOWN                | 0      | Unknown format.|
| RGBA_8888             | 1      | RGBA_8888.|
| NV21                  | 2      | NV21.|
| RGBA_1010102           | 3      | RGBA_1010102.|
| YCBCR_P010            | 4      | YCBCR_P010.|
| YCRCB_P010             | 5      | YCRCB_P010.|

## DynamicRangeMode<sup>14+</sup>

Enumerates the extended range modes available for the cover image of the **MovingPhotoView** component. The range mode determines the image display effect.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  |   Value  | Description             |
| ---------------------- | ------ | ----------------- |
| HIGH                | 0      | Enables unrestricted extended range for HDR effects. The recommended decoding format is YCBCR_P010.|
| CONSTRAINT         | 1      | Allows limited extended range for the image content.|
| STANDARD            | 2      | Keeps the image content within the standard dynamic range for SDR effects. The recommended decoding formats are UNKNOWN and RGBA_8888.|

## Example: Setting the Decoding Format and Range Mode for Moving Photos in a System Application

```ts
// This example illustrates how to use the parameters. For detailed implementation, check the public API documentation for moving photos.
import { photoAccessHelper, MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@kit.MediaLibraryKit';
import { PixelMapFormat, DynamicRangeMode } from '@ohos.multimedia.movingphotoview';

let data: photoAccessHelper.MovingPhoto
async function loading(context: Context) {
  try {
    // Ensure that the media assets corresponding to imageFileUri and videoFileUri exist in the application sandbox directory.
    let imageFileUri = 'file://{bundleName}/data/storage/el2/base/haps/entry/files/xxx.jpg';
    let videoFileUri = 'file://{bundleName}/data/storage/el2/base/haps/entry/files/xxx.mp4';
    data = await photoAccessHelper.MediaAssetManager.loadMovingPhoto(context, imageFileUri, videoFileUri);
    console.info('load moving photo successfully');
  } catch (err) {
    console.error(`load moving photo failed with error: ${err.code}, ${err.message}`);
  }
}
@Entry
@Component
struct Index {
  controller: MovingPhotoViewController = new MovingPhotoViewController();
  format: undefined | PixelMapFormat = PixelMapFormat.YCBCR_P010;
  mode: undefined | DynamicRangeMode = DynamicRangeMode.HIGH;
  private uiContext: UIContext = this.getUIContext()
  aboutToAppear(): void {
    loading(this.uiContext.getHostContext()!)
  }

  build() {
    NavDestination() {
      Column() {
        Stack({ alignContent: Alignment.BottomStart }) {
          MovingPhotoView({
            movingPhoto: data,
            controller: this.controller,
            movingPhotoFormat: this.format,
            dynamicRangeMode: this.mode
          })
        }
      }
    }
  }
}
```
