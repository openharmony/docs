# @ohos.multimedia.movingphotoview（动态照片）

用于播放动态照片文件并控制其播放状态的组件。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> 当前不支持在预览器中使用MovingPhotoView组件。

## 导入模块

```
import { MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@ohos.multimedia.movingphotoview'
```

## MovingPhotoView

> **说明：**
>
> - 当前不支持动态属性设置。
> - 该组件长按触发播放时组件区域放大为1.1倍。

MovingPhotoView(options: MovingPhotoViewOptions)

**参数：**


| 参数名  | 参数类型                                                  | 必填 | 参数描述       |
| ------- | --------------------------------------------------------- | ---- | -------------- |
| options | [MovingPhotoViewOptions](#movingphotoviewoptions) | 是   | 动态照片信息。 |

## MovingPhotoViewOptions


| 参数名      | 参数类型                                                                                         | 必填 | 参数描述                                                                                                                                        |
| ----------- | ------------------------------------------------------------------------------------------------ | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| movingPhoto | [MovingPhoto](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#movingphoto12) | 是   | 支持媒体库MovingPhoto数据源，具体信息详见[MovingPhoto说明](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#movingphoto12)。 |
| controller  | [MovingPhotoViewController](#movingphotoviewcontroller)                                          | 否   | 设置动态照片控制器，可以控制动态照片的播放状态。                                                                                                |

## 属性

除支持[通用属性](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md)外，还支持以下属性：

### muted

muted(isMuted: boolean)

设置是否静音。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**


| 参数名  | 类型    | 必填 | 说明                         |
| ------- | ------- | ---- | ---------------------------- |
| isMuted | boolean | 是   | 是否静音。<br/>默认值：false |

### objectFit

objectFit(value: ImageFit)

设置动态照片显示模式。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**


| 参数名 | 类型                                                                          | 必填 | 说明                             |
| ------ | ----------------------------------------------------------------------------- | ---- | -------------------------------- |
| value  | [ImageFit](../../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#imagefit) | 是   | 视频显示模式。<br/>默认值：Cover |

## 事件

除支持[通用事件](../../reference/apis-arkui/arkui-ts/ts-universal-events-click.md)外，还支持以下事件：

### onStart

onStart(callback: MovingPhotoViewEventCallback)

播放时触发该事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**


| 参数名   | 类型                                                          | 必填 | 说明                           |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | 是   | 动态照片开始播放时触发的回调。 |

### onFinish

onFinish(callback: MovingPhotoViewEventCallback)

播放结束时触发该事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**


| 参数名   | 类型                                                          | 必填 | 说明                           |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | 是   | 动态照片播放结束时触发的回调。 |

### onError

onError(callback: MovingPhotoViewEventCallback)

播放失败时触发该事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**


| 参数名   | 类型                                                          | 必填 | 说明                           |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | 是   | 动态照片播放失败时触发的回调。 |

### onStop

onStop(callback: MovingPhotoViewEventCallback)

播放停止时触发该事件(当stop()方法被调用后触发)。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**


| 参数名   | 类型                                                          | 必填 | 说明                           |
| -------- | ------------------------------------------------------------- | ---- | ------------------------------ |
| callback | [MovingPhotoViewEventCallback](#movingphotovieweventcallback) | 是   | 动态照片停止播放时触发的回调。 |

## MovingPhotoViewEventCallback

declare type MovingPhotoViewEventCallback = () => void

动态照片播放状态发生变化时触发的回调。

## MovingPhotoViewController

一个MovingPhotoViewController对象可以控制一个MovingPhotoView，可用视频播放实例请参考[@ohos.multimedia.media](../../reference/apis-media-kit/js-apis-media.md)。

### startPlayback

startPlayback(): void

开始播放。

### stopPlayback

stopPlayback(): void

停止播放，再次播放时从头开始播放。

## 示例

```ts
// xxx.ets
import photoAccessHelper from '@ohos.file.photoAccessHelper'
import emitter from '@ohos.events.emitter'
import { dataSharePredicates } from '@kit.ArkData'
import { MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@ohos.multimedia.movingphotoview'

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
            .objectFit(ImageFit.Contain)
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
![movingphotoview](figures/movingphotoview.gif)
