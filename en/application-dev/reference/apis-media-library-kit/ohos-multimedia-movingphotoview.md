# @ohos.multimedia.movingphotoview (MovingPhotoView)

The **MovingPhotoView** component is used to play moving photos and control the playback status.

> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>
> Currently, the **MovingPhotoView** component cannot be used in Previewer.

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
> - This component uses [AVPlayer](../apis-media-kit/js-apis-media.md#avplayer9) to play moving photos. A maximum of three AVPlayers can be used at the same time. Otherwise, frame freezing may occur.

MovingPhotoView(options: MovingPhotoViewOptions)

**Parameters**


| Name | Type                                                 | Mandatory| Description      |
| ------- | --------------------------------------------------------- | ---- | -------------- |
| options | [MovingPhotoViewOptions](#movingphotoviewoptions) | Yes  | Moving photo information.|

## MovingPhotoViewOptions


| Name     | Type                                                                                        | Mandatory| Description                                                                                                                                       |
| ----------- | ------------------------------------------------------------------------------------------------ | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| movingPhoto | [MovingPhoto](js-apis-photoAccessHelper.md#movingphoto12) | Yes  | **MovingPhoto** instance. For details, see [MovingPhoto](js-apis-photoAccessHelper.md#movingphoto12).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| controller  | [MovingPhotoViewController](#movingphotoviewcontroller)                                          | No  | Controller used to control the playback status of the moving photo.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                     |
| imageAIOptions<sup>18+</sup>   | [ImageAIOptions](../apis-arkui/arkui-ts/ts-image-common.md#imageaioptions) | No  | AI options. You can set the image analyzer type or bind an image analyzer controller.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## Properties

In addition to the [universal properties](../apis-arkui/arkui-ts/ts-component-general-attributes.md), the following properties are supported.

### muted

muted(isMuted: boolean)

Sets whether to mute the player.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name | Type   | Mandatory| Description                        |
| ------- | ------- | ---- | ---------------------------- |
| isMuted | boolean | Yes  | Whether to mute the player.<br>Default value: **false**<br>The value **true** means to mute the player; the value **false** means the opposite.|

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

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name | Type   | Mandatory| Description                        |
| ------- | ------- | ---- | ---------------------------- |
| startTime| number| Yes  | Start playback time, in ms.<br>The value must be greater than or equal to 0.|
| endTime| number| Yes  | End playback time, in ms.<br>The value must be greater than **startTime**.|

### autoPlay<sup>13+</sup>

autoPlay(isAutoPlay: boolean)

Sets autoplay. After the moving photo is played once, a static image is displayed.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name | Type   | Mandatory| Description                        |
| ------- | ------- | ---- | ---------------------------- |
| isAutoPlay| boolean| Yes  | Whether to enable autoplay.<br>The value **true** means to enable autoplay; the value **false** means the opposite.<br>Default value: **false**|

### repeatPlay<sup>13+</sup>

repeatPlay(isRepeatPlay: boolean)

Sets repeat play. **repeatPlay** is mutually exclusive with **autoPlay** and **Long Press**, and takes precedence over them.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name | Type   | Mandatory| Description                        |
| ------- | ------- | ---- | ---------------------------- |
| isRepeatPlay| boolean| Yes  | Whether to enable repeat play.<br>The value **true** means to enable repeat play; the value **false** means the opposite.<br>Default value: **false**|

### enableAnalyzer<sup>18+</sup> 

enableAnalyzer(enabled: boolean)

Sets the AI analyzer. Currently, the AI analyzer supports features, such as subject recognition, text recognition, and object search.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name | Type   | Mandatory| Description                        |
| ------- | ------- | ---- | ---------------------------- |
| enabled| boolean| Yes  | Whether to enable the AI analyzer.<br>The value **false** means to disable the AI analyzer; **true** means the opposite.<br>Default value: **true**|

## Events

In addition to [universal events](../apis-arkui/arkui-ts/ts-component-general-events.md), the following events are supported.

### onComplete<sup>13+</sup>

onComplete(callback: MovingPhotoViewEventCallback)

Called when the image of a moving photo is loaded.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**


| Name  | Type                                                         | Mandatory| Description                          |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | Yes  | Callback to be invoked when the image of a moving photo is loaded.|

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

### refreshMovingPhoto<sup>18+</sup> 

refreshMovingPhoto(): void

Forcibly refreshes the video and image resources loaded by the **MovingPhotoView** component. This API will interrupt the ongoing actions of the component. Exercise caution when using it.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

## Example 1: Play a moving photo in multiple modes.

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
  private uiContext: UIContext = this.getUIContext()

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
            try {
              let uris: Array<string> = []
              const photoSelectOptions = new photoAccessHelper.PhotoSelectOptions()
              photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE
              photoSelectOptions.maxSelectNumber = 2
              const photoViewPicker = new photoAccessHelper.PhotoViewPicker()
              let photoSelectResult: photoAccessHelper.PhotoSelectResult = await photoViewPicker.select(photoSelectOptions)
              uris = photoSelectResult.photoUris
              if (uris[0]) {
                this.handlePickerResult(this.uiContext.getHostContext()!, uris[0], new MediaDataHandlerMovingPhoto())
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
## Example 2: Enable the AI analyzer.

```ts
// xxx.ets
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { emitter } from '@kit.BasicServicesKit';
import { dataSharePredicates } from '@kit.ArkData';
import { MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@kit.MediaLibraryKit';
import visionImageAnalyzer from '@hms.ai.visionImageAnalyzer';
const PHOTO_SELECT_EVENT_ID: number = 80001

@Entry
@Component
struct MovingPhotoViewDemo {
  @State src: photoAccessHelper.MovingPhoto | undefined = undefined
  @State isMuted: boolean = false
  controller: MovingPhotoViewController = new MovingPhotoViewController()
  private aiController: visionImageAnalyzer.VisionImageAnalyzerController =
    new visionImageAnalyzer.VisionImageAnalyzerController()
  private options: ImageAIOptions = {
    types: [ImageAnalyzerType.SUBJECT, ImageAnalyzerType.TEXT, ImageAnalyzerType.OBJECT_LOOKUP],
    aiController: this.aiController
  }
  private uiContext: UIContext = this.getUIContext()

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
            try {
              let uris: Array<string> = []
              const photoSelectOptions = new photoAccessHelper.PhotoSelectOptions()
              photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE
              photoSelectOptions.maxSelectNumber = 2
              const photoViewPicker = new photoAccessHelper.PhotoViewPicker()
              let photoSelectResult: photoAccessHelper.PhotoSelectResult = await photoViewPicker.select(photoSelectOptions)
              uris = photoSelectResult.photoUris
              if (uris[0]) {
                this.handlePickerResult(this.uiContext.getHostContext()!, uris[0], new MediaDataHandlerMovingPhoto())
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
            controller: this.controller,
            imageAIOptions: this.options
          })
            .width('100%')
            .height('100%')
            .muted(this.isMuted)
            .autoPlay(true)
            .repeatPlay(false)
            .autoPlayPeriod(0, 600)
            .objectFit(ImageFit.Cover)
            .enableAnalyzer(true)
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
## Example 3: Use moving photos in an atomic service.

```ts
// xxx.ets
import { photoAccessHelper, MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@kit.MediaLibraryKit';

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
  controller: MovingPhotoViewController = new MovingPhotoViewController()
  private uiContext: UIContext = this.getUIContext()
  @State ImageFit: ImageFit | undefined | null = ImageFit.Contain;
  @State flag: boolean = true;
  @State autoPlayFlag: boolean = true;
  @State repeatPlayFlag: boolean = false;
  @State autoPlayPeriodStart: number = 0;
  @State autoPlayPeriodEnd: number = 500;
  aboutToAppear(): void {
    loading(this.uiContext.getHostContext()!)
  }

  build() {
    NavDestination() {
      Column() {
        Stack({ alignContent: Alignment.BottomStart }) {
          MovingPhotoView({
            movingPhoto: data,
            controller: this.controller
          })
            .width(300)
            .height(400)
            .muted(this.flag)
            .objectFit(this.ImageFit)
            .autoPlay(this.autoPlayFlag)
            .autoPlayPeriod(this.autoPlayPeriodStart, this.autoPlayPeriodEnd)
            .repeatPlay(this.repeatPlayFlag)
            .onComplete(() => {
              console.info('onComplete')
            })
            .onStart(() => {
              console.info('onStart')
            })
            .onStop(() => {
              console.info('onStop')
            })
            .onPause(() => {
              console.info('onPause')
            })
            .onFinish(() => {
              console.info('onFinish')
            })
            .onError(() => {
              console.info('onError')
            })
        }

        Row() {
          Button('Play')
            .onClick(() => {
              this.controller.startPlayback()
            })
          Button('StopPlay')
            .onClick(() => {
              this.controller.stopPlayback()
            })
          Button('refreshMovingPhoto')
            .onClick(() => {
              this.controller.refreshMovingPhoto()
            })
          Button('mute').id('MovingPhotoView_true')
            .onClick(() => {
              this.flag = false
            })
        }
      }
    }
  }
}
```
