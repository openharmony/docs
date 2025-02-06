# @ohos.multimedia.movingphotoview (动态照片)

用于播放动态照片文件并控制其播放状态的组件。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> 当前不支持在预览器中使用MovingPhotoView组件。

## 导入模块

```
import { MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@kit.MediaLibraryKit';
```

## MovingPhotoView

> **说明：**
>
> - 当前不支持动态属性设置。
> - 当前不支持ArkUI通用属性ComponentOptions中expandSafeArea属性设置。
> - 该组件长按触发播放时组件区域放大为1.1倍。
> - 该组件使用[AVPlayer](../apis-media-kit/_a_v_player.md#avplayer)进行播放，同时开启的[AVPlayer](../apis-media-kit/_a_v_player.md#avplayer)个数不建议超过3个，超过3个可能会出现视频播放卡顿现象。

MovingPhotoView(options: MovingPhotoViewOptions)

**参数：**


| 参数名  | 参数类型                                                  | 必填 | 参数描述       |
| ------- | --------------------------------------------------------- | ---- | -------------- |
| options | [MovingPhotoViewOptions](#movingphotoviewoptions) | 是   | 动态照片信息。 |

## MovingPhotoViewOptions


| 参数名      | 参数类型                                                                                         | 必填 | 参数描述                                                                                                                                        |
| ----------- | ------------------------------------------------------------------------------------------------ | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| movingPhoto | [MovingPhoto](js-apis-photoAccessHelper.md#movingphoto12) | 是   | 支持媒体库MovingPhoto数据源，具体信息详见[MovingPhoto说明](js-apis-photoAccessHelper.md#movingphoto12)。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| controller  | [MovingPhotoViewController](#movingphotoviewcontroller)                                          | 否   | 设置动态照片控制器，可以控制动态照片的播放状态。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                      |
| imageAIOptions<sup>16+</sup>  | [ImageAIOptions](../apis-arkui/arkui-ts/ts-image-common.md#imageaioptions) | 否   | 设置动态照片AI分析选项，可配置分析类型或绑定一个分析控制器。<br/>**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。 |

## 属性

除支持[通用属性](../apis-arkui/arkui-ts/ts-universal-attributes-size.md)外，还支持以下属性：

### muted

muted(isMuted: boolean)

设置是否静音。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**


| 参数名  | 类型    | 必填 | 说明                         |
| ------- | ------- | ---- | ---------------------------- |
| isMuted | boolean | 是   | 是否静音。<br/>默认值：false<br/>false：非静音<br/>true：静音|

### objectFit

objectFit(value: ImageFit)

设置动态照片显示模式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**


| 参数名 | 类型                                                                          | 必填 | 说明                             |
| ------ | ----------------------------------------------------------------------------- | ---- | -------------------------------- |
| value  | [ImageFit](../apis-arkui/arkui-ts/ts-appendix-enums.md#imagefit) | 是   | 视频显示模式。<br/>默认值：Cover |

### autoPlayPeriod<sup>13+</sup>

autoPlayPeriod(startTime: number, endTime: number)

设置自动播放区间，附属于autoPlay的子配置项。

在调用此方法前，需将[autoPlay](#autoplay13)设置为true，设置自动播放，否则指定的视频区间(startTime, endTime)无法生效。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**


| 参数名  | 类型    | 必填 | 说明                         |
| ------- | ------- | ---- | ---------------------------- |
| startTime| number| 是   | 区间播放开始时间，单位：ms。<br/>取值范围：大于等于0|
| endTime| number| 是   | 区间播放结束时间，单位：ms。<br/>取值范围：大于startTime |

### autoPlay<sup>13+</sup>

autoPlay(isAutoPlay: boolean)

设置自动播放，自动播放一遍视频，完成播放后显示静态图。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**


| 参数名  | 类型    | 必填 | 说明                         |
| ------- | ------- | ---- | ---------------------------- |
| isAutoPlay| boolean| 是   | 是否自动播放。<br/>false：不自动播放<br/>true：自动播放<br/>默认值：false|

### repeatPlay<sup>13+</sup>

repeatPlay(isRepeatPlay: boolean)

设置循环播放，重复播放视频。 repeatPlay与autoPlay及长按播放互斥，repeatPlay设置时，autoPlay和长按播放均不生效。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**


| 参数名  | 类型    | 必填 | 说明                         |
| ------- | ------- | ---- | ---------------------------- |
| isRepeatPlay| boolean| 是   | 是否循环播放。<br/>false：不循环播放<br/>true：循环播放<br/>默认值：false|

### enableAnalyzer<sup>16+</sup>

enableAnalyzer(enabled: boolean)

设置该图片是否支持AI分析，当前支持主体识别、文字识别和对象查找等功能。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**


| 参数名  | 类型    | 必填 | 说明                         |
| ------- | ------- | ---- | ---------------------------- |
| enabled| boolean| 是   | 是否开启AI分析。<br/>false：不开启AI分析<br/>true：开启AI分析<br/>默认值：true|

## 事件

除支持[通用事件](../apis-arkui/arkui-ts/ts-universal-events-click.md)外，还支持以下事件：

### onComplete<sup>13+</sup>

onComplete(callback: MovingPhotoViewEventCallback)

动态照片加载完成图片时触发该事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**


| 参数名   | 类型                                                          | 必填 | 说明                           |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | 是   | 动态照片加载完成图片的回调。 |

### onStart

onStart(callback: MovingPhotoViewEventCallback)

播放时触发该事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**


| 参数名   | 类型                                                          | 必填 | 说明                           |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | 是   | 动态照片开始播放时触发的回调。 |

### onPause

onPause(callback: MovingPhotoViewEventCallback)

播放暂停时触发该事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**


| 参数名   | 类型                                                          | 必填 | 说明                           |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | 是   | 动态照片播放暂停时触发的回调。 |

### onFinish

onFinish(callback: MovingPhotoViewEventCallback)

播放结束时触发该事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**


| 参数名   | 类型                                                          | 必填 | 说明                           |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | 是   | 动态照片播放结束时触发的回调。 |

### onError

onError(callback: MovingPhotoViewEventCallback)

播放失败时触发该事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**


| 参数名   | 类型                                                          | 必填 | 说明                           |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | 是   | 动态照片播放失败时触发的回调。 |

### onStop

onStop(callback: MovingPhotoViewEventCallback)

播放停止时触发该事件(当stop()方法被调用后触发)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**


| 参数名   | 类型                                                          | 必填 | 说明                           |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | 是   | 动态照片停止播放时触发的回调。 |

## MovingPhotoViewEventCallback

declare type MovingPhotoViewEventCallback = () => void

动态照片播放状态发生变化时触发的回调。

## MovingPhotoViewController

一个MovingPhotoViewController对象可以控制一个MovingPhotoView，可用视频播放实例请参考[@ohos.multimedia.media](../apis-media-kit/js-apis-media.md)。

### startPlayback

startPlayback(): void

开始播放。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

### stopPlayback

stopPlayback(): void

停止播放，再次播放时从头开始播放。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

### refreshMovingPhoto<sup>16+</sup>

refreshMovingPhoto(): void

强制刷新动态照片组件加载的视频和图片资源，会打断组件当前的行为，使用时要谨慎。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

## 示例1：多种形式播放动态照片

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
## 示例2：图像分析功能使用

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
## 示例3：在原子化服务中使用动态照片

```ts
// xxx.ets
import { photoAccessHelper, MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@kit.MediaLibraryKit';

let context = getContext(this)
let data: photoAccessHelper.MovingPhoto
async function loading() {
  try {
    // 需要确保imageFileUri和videoFileUri对应的资源在应用沙箱存在
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
  @State ImageFit: ImageFit | undefined | null = ImageFit.Contain;
  @State flag: boolean = true;
  @State autoPlayFlag: boolean = true;
  @State repeatPlayFlag: boolean = false;
  @State autoPlayPeriodStart: number = 0;
  @State autoPlayPeriodEnd: number = 500;
  aboutToAppear(): void {
    loading()
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