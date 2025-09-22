# @ohos.multimedia.movingphotoview (MovingPhotoView) (System API)
<!--Kit: Media Library Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @tangye123456-->
<!--Designer: @YanSanzo-->
<!--Tester: @tinygreyy-->
<!--Adviser: @zengyawen-->

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
| playWithMask<sup>19+</sup>  | boolean | No  | Whether the watermark is shown when a moving photo with a watermark is playing.<br>The default value is **false**.<br>**false**: The moving photo fills the component while keeping its aspect ratio; the watermark is hidden.<br>**true**: The watermark is shown.|

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
            dynamicRangeMode: this.mode,
            playWithMask: false
          })
        }
      }
    }
  }
}
```

## MovingPhotoViewController<sup>12+</sup>

A MovingPhotoViewController object can be used to control a **MovingPhotoView** component. For details, see [Media Module](../apis-media-kit/arkts-apis-media.md).

### pausePlayback<sup>20+</sup>

pausePlayback()

Pauses playback and freezes on the current frame. Once resumed, playback continues right where it left off.

**System API**: This is a system API.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| -------- | ---------------------------------------- |
| 202 | Non-system applications are not allowed to use system APIs. |

### reset<sup>20+</sup>

reset()

Returns to the cover frame and rewinds the video. The next play starts from the very beginning.

**System API**: This is a system API.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| -------- | ---------------------------------------- |
| 202 | Non-system applications are not allowed to use system APIs. |

### restart<sup>20+</sup>

restart()

Restarts playback from the beginning while keeping the current playback range and mode.

**System API**: This is a system API.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| -------- | ---------------------------------------- |
| 202 | Non-system applications are not allowed to use system APIs. |

### setPlaybackPeriod<sup>20+</sup>

setPlaybackPeriod(startTime: number, endTime: number)

Sets the playback range, which takes effect for the next playback.

**System API**: This is a system API.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Type   | Mandatory| Description                        |
| ------- | ------- | ---- | ---------------------------- |
| startTime| number| Yes  | Start of the range, in ms. The value must be greater than or equal to 0.|
| endTime| number| Yes  | End of the range, in ms. The value must be greater than **startTime**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| -------- | ---------------------------------------- |
| 202 | Non-system applications are not allowed to use system APIs. |

### enableTransition<sup>20+</sup>

enableTransition(enabled: boolean)

Enables or disables the zoom-in transition effect when the video starts to play. The setting takes effect for the next playback.

**System API**: This is a system API.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Type   | Mandatory| Description                        |
| ------- | ------- | ---- | ---------------------------- |
| enabled| boolean| Yes  | Whether to enable the zoom-in transition effect. **true** to enable, **false** otherwise.<br></div>The default value is **true**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| -------- | ---------------------------------------- |
| 202 | Non-system applications are not allowed to use system APIs. |

### enableAutoPlay<sup>20+</sup>

enableAutoPlay(enabled: boolean)

Enables or disables the embedded video in a moving photo to play automatically, once.

**System API**: This is a system API.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Type   | Mandatory| Description                        |
| ------- | ------- | ---- | ---------------------------- |
| enabled| boolean| Yes  | Whether to enable autoplay. **true** to enable, **false** otherwise.<br></div>The default value is **false**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| -------- | ---------------------------------------- |
| 202 | Non-system applications are not allowed to use system APIs. |
