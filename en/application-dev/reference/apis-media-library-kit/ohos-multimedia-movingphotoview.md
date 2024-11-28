# @ohos.multimedia.movingphotoview (MovingPhotoView)

The **MovingPhotoView** component is used to play moving photos and control the playback status.

> **NOTE**
>
> - This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
> - Currently, the **MovingPhotoView** component cannot be used in Previewer.

## Modules to Import

```
import { MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@kit.MediaLibraryKit';
```

## MovingPhotoView

> **NOTE**
>
> - Currently, live attributes cannot be set.
> - Currently, **expandSafeArea** in the ArkUI common attribute **ComponentOptions** cannot be set.
> - When this component is long pressed to trigger playback, the component area is zoomed in to 1.1 times.
> - This component uses [AVPlayer](../apis-media-kit/_a_v_player.md#avplayer) to play moving photos. A maximum of three [AVPlayers](../apis-media-kit/_a_v_player.md#avplayer) can be used at the same time. Otherwise, frame freezing may occur during the playback. Otherwise, frame freezing may occur during the playback.



MovingPhotoView(options: MovingPhotoViewOptions)

**Parameters**


| Name | Type                                                 | Mandatory| Description      |
| ------- | --------------------------------------------------------- | ---- | -------------- |
| options | [MovingPhotoViewOptions](#movingphotoviewoptions) | Yes  | Moving photo information. <br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## MovingPhotoViewOptions


| Name     | Type                                                                                        | Mandatory| Description                                                                                                                                       |
| ----------- | ------------------------------------------------------------------------------------------------ | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| movingPhoto | [MovingPhoto](js-apis-photoAccessHelper.md#movingphoto12) | Yes  | **MovingPhoto** instance. For details, see [MovingPhoto](js-apis-photoAccessHelper.md#movingphoto12).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| controller  | [MovingPhotoViewController](#movingphotoviewcontroller)                                          | No  | Controller used to control the playback status of the moving photo.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                     |

## Properties

In addition to the [universal properties](../apis-arkui/arkui-ts/ts-universal-attributes-size.md), the following properties are supported.

### muted

muted(isMuted: boolean)

Sets whether to mute the player.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name | Type   | Mandatory| Description                        |
| ------- | ------- | ---- | ---------------------------- |
| isMuted | boolean | Yes  | Whether to mute the player.<br>Default value: **false**<br>The value **true** means to mute the player; the value **false** means the opposite. |

### objectFit

objectFit(value: ImageFit)

Sets the display mode of the moving photo.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name| Type                                                                         | Mandatory| Description                            |
| ------ | ----------------------------------------------------------------------------- | ---- | -------------------------------- |
| value  | [ImageFit](../apis-arkui/arkui-ts/ts-appendix-enums.md#imagefit) | Yes  | Image scale type.<br>Default value: **Cover**|

### autoPlayPeriod<sup>13+</sup>

autoPlayPeriod(startTime: number, endTime: number)

Sets the autoplay period, which is a configuration item of **autoPlay**.

Before this API is called, [autoPlay](#autoplay13) must be set to **true**. Otherwise, the specified video play period (**startTime**, **endTime**) does not take effect.


**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name | Type   | Mandatory| Description                        |
| ------- | ------- | ---- | ---------------------------- |
| startTime| number| Yes  | Start playback time, in ms.<br>Value range: [0, 3000]|
| endTime| number| Yes  | End playback time, in ms.<br>Value range: [0, 3000]|

### autoPlay<sup>13+</sup>

autoPlay(isAutoPlay: boolean)

Sets autoplay. After the moving photo is played once, a static image is displayed.


**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name | Type   | Mandatory| Description                        |
| ------- | ------- | ---- | ---------------------------- |
| isAutoPlay| boolean| Yes  | Whether to enable autoplay.<br>The value **true** means to enable autoplay; the value **false** means the opposite.<br>Default value: **false** |

### repeatPlay<sup>13+</sup>

repeatPlay(isRepeatPlay: boolean)

Sets repeat play. **repeatPlay** is mutually exclusive with **autoPlay** and **Long Press**, and takes precedence over them.


**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name | Type   | Mandatory| Description                        |
| ------- | ------- | ---- | ---------------------------- |
| isRepeatPlay| boolean| Yes  | Whether to enable repeat play.<br>The value **true** means to enable repeat play; the value **false** means the opposite.<br>Default value: **false** |

## Events

In addition to [universal events](../apis-arkui/arkui-ts/ts-universal-events-click.md), the following events are supported.

### onComplete<sup>13+</sup>

onComplete(callback: MovingPhotoViewEventCallback)

Called when the image of a moving photo is loaded.


**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name  | Type                                                         | Mandatory| Description                          |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | Yes  | Callback to be invoked when the image of a moving photo is loaded. |

### onStart

onStart(callback: MovingPhotoViewEventCallback)

Called when a moving photo starts playing.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name  | Type                                                         | Mandatory| Description                          |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | Yes  | Callback to be invoked when a moving photo starts playing.|

### onPause

onPause(callback: MovingPhotoViewEventCallback)

Called when the playback is paused.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name  | Type                                                         | Mandatory| Description                          |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | Yes  | Callback to be invoked when the playback of a moving photo is paused.|

### onFinish

onFinish(callback: MovingPhotoViewEventCallback)

Called when the playback is finished.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name  | Type                                                         | Mandatory| Description                          |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | Yes  | Callback to be invoked when the playback of a moving photo ends.|

### onError

onError(callback: MovingPhotoViewEventCallback)

Called when the playback fails.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name  | Type                                                         | Mandatory| Description                          |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | Yes  | Callback to be invoked when the playback of a moving photo fails.|

### onStop

onStop(callback: MovingPhotoViewEventCallback)

Called when the playback is stopped by **stop()**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name  | Type                                                         | Mandatory| Description                          |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | Yes  | Callback to be invoked when the playback of a moving photo is stopped.|

## MovingPhotoViewEventCallback

declare type MovingPhotoViewEventCallback = () => void

Defines a callback to be invoked when the playback status of a moving photo changes.

## MovingPhotoViewController

A **MovingPhotoViewController** object can be used to control a **MovingPhotoView** component. For details, see [@ohos.multimedia.media](../apis-media-kit/js-apis-media.md).

### startPlayback

startPlayback(): void

Starts playback.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### stopPlayback

stopPlayback(): void

Stops playback. Once started again, the playback starts from the beginning.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

## Example


```ts
// xxx.ets
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { emitter } from '@kit.BasicServicesKit';
import { dataSharePredicates } from '@kit.ArkData';
import { MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@kit.MediaLibraryKit';

const PHOTO_SELECT_EVENT_ID: number = 80001

@Entry
@Component
struct MovingPhotoViewDemo {
  @State src: photoAccessHelper.MovingPhoto | undefined = undefined
  @State isMuted: boolean = false
  controller: MovingPhotoViewController = new MovingPhotoViewController()

  aboutToAppear(): void {
    emitter.on({
      eventId: PHOTO_SELECT_EVENT_ID,
      priority: emitter.EventPriority.IMMEDIATE,
    }, (eventData: emitter.EventData) => {
      this.src = AppStorage.get<photoAccessHelper.MovingPhoto>('mv_data') as photoAccessHelper.MovingPhoto
    })
  }

  aboutToDisappear(): void {
    emitter.off(PHOTO_SELECT_EVENT_ID)
  }

  build() {
    Column() {
      Row() {
        Button('PICK')
          .margin(5)
          .onClick(async () => {
            let context = getContext(this)
            try {
              let uris: Array<string> = []
              const photoSelectOptions = new photoAccessHelper.PhotoSelectOptions()
              photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE
              photoSelectOptions.maxSelectNumber = 2
              const photoViewPicker = new photoAccessHelper.PhotoViewPicker()
              let photoSelectResult: photoAccessHelper.PhotoSelectResult = await photoViewPicker.select(photoSelectOptions)
              uris = photoSelectResult.photoUris
              if (uris[0]) {
                this.handlePickerResult(context, uris[0], new MediaDataHandlerMovingPhoto())
              }
            } catch (e) {
              console.error(`pick file failed`)
            }
          })
      }
      .alignItems(VerticalAlign.Center)
      .justifyContent(FlexAlign.Center)
      .height('15%')

      Row() {
        Column() {
          MovingPhotoView({
            movingPhoto: this.src,
            controller: this.controller
          })
            .width('100%')
            .height('100%')
            .muted(this.isMuted)
            .autoPlay(true)
            .repeatPlay(false)
            .autoPlayPeriod(0, 600)
            .objectFit(ImageFit.Cover)
            .onComplete(() => {
              console.log('Completed');
            })
            .onStart(() => {
              console.log('onStart')
            })
            .onFinish(() => {
              console.log('onFinish')
            })
            .onStop(() => {
              console.log('onStop')
            })
            .onError(() => {
              console.log('onError')
            })
        }
      }
      .height('70%')

      Row() {
        Button('start')
          .onClick(() => {
            this.controller.startPlayback()
          })
          .margin(5)
        Button('stop')
          .onClick(() => {
            this.controller.stopPlayback()
          })
          .margin(5)
        Button('mute')
          .onClick(() => {
            this.isMuted = !this.isMuted
          })
          .margin(5)
      }
      .alignItems(VerticalAlign.Center)
      .justifyContent(FlexAlign.Center)
      .height('15%')
    }
  }

  async handlePickerResult(context: Context, uri: string, handler: photoAccessHelper.MediaAssetDataHandler<photoAccessHelper.MovingPhoto>): Promise<void> {
    let uriPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    uriPredicates.equalTo('uri', uri)
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: uriPredicates
    };
    let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context)
    let assetResult = await phAccessHelper.getAssets(fetchOptions)
    let asset = await assetResult.getFirstObject()
    let requestOptions: photoAccessHelper.RequestOptions = {
      deliveryMode: photoAccessHelper.DeliveryMode.FAST_MODE,
    }
    try {
      photoAccessHelper.MediaAssetManager.requestMovingPhoto(context, asset, requestOptions, handler)
    } catch (err) {
      console.error("request error: ", err)
    }
  }
}

class MediaDataHandlerMovingPhoto implements photoAccessHelper.MediaAssetDataHandler<photoAccessHelper.MovingPhoto> {
  async onDataPrepared(movingPhoto: photoAccessHelper.MovingPhoto) {
    AppStorage.setOrCreate('mv_data', movingPhoto)
    emitter.emit({
      eventId: PHOTO_SELECT_EVENT_ID,
      priority: emitter.EventPriority.IMMEDIATE,
    }, {
    })
  }
}
```













