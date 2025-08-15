# @ohos.multimedia.movingphotoview (动态照片)(系统接口)
<!--Kit: Media Library Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @tangye123456-->
<!--Designer: @YanSanzo-->
<!--Tester: @tinygreyy-->
<!--Adviser: @zengyawen-->

用于播放动态照片文件并控制其播放状态的组件。

> **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.multimedia.movingphotoview (动态照片)](ohos-multimedia-movingphotoview.md)。

## MovingPhotoViewOptions


| 参数名      | 参数类型                                                                                         | 必填 | 参数描述                                                                                                                                        |
| ----------- | ------------------------------------------------------------------------------------------------ | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| movingPhotoFormat<sup>14+</sup>  | [PixelMapFormat](#pixelmapformat14)    | 否   | 设置动态照片组件封面图片的解码格式。                  |
| dynamicRangeMode<sup>14+</sup>  | [DynamicRangeMode](#dynamicrangemode14) | 否   | 设置动态照片组件封面图片的RangeMode样式。 |
| playWithMask<sup>19+</sup>  | boolean | 否   | 带有水印的动态照片播放时是否保留水印显示。<br/>默认值：false。<br/>false：播放时保持宽高比撑满组件，不展示水印信息。<br/>true：播放时不遮挡封面照片的水印，展示水印信息。||

## PixelMapFormat<sup>14+</sup>

动态照片组件封面图片的解码格式。

**系统接口**：此接口为系统接口。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                   |   值   | 说明              |
| ---------------------- | ------ | ----------------- |
| UNKNOWN                | 0      | 未知格式。|
| RGBA_8888             | 1      | 格式为RGBA_8888。|
| NV21                  | 2      | 格式为NV21。 |
| RGBA_1010102           | 3      | 格式为RGBA_1010102。|
| YCBCR_P010            | 4      | 格式为YCBCR_P010。|
| YCRCB_P010             | 5      | 格式为YCRCB_P010。 |

## DynamicRangeMode<sup>14+</sup>

动态照片组件封面图片的可使用的扩展范围，决定了图片的显示效果。

**系统接口**：此接口为系统接口。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                   |   值   | 说明              |
| ---------------------- | ------ | ----------------- |
| HIGH                | 0      | 允许图像内容使用不受限制的扩展范围，显示HDR效果，建议使用的解码格式YCBCR_P010。|
| CONSTRAINT         | 1      | 允许图像内容使用一些扩展范围。|
| STANDARD            | 2      | 允许图像内容动态单位限制在标准范围内，显示SDR效果，需要使用的解码格式UNKNOWN或者RGBA_8888。|

## 示例1：系统应用设置动态照片解码格式和rangemode格式

```ts
// 该示例只展示参数用法，具体可以执行用例参考动态照片公开接口文档
import { photoAccessHelper, MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@kit.MediaLibraryKit';
import { PixelMapFormat, DynamicRangeMode } from '@ohos.multimedia.movingphotoview';

let data: photoAccessHelper.MovingPhoto
async function loading(context: Context) {
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

一个MovingPhotoViewController对象可以控制一个MovingPhotoView，可用视频播放实例请参考[媒体业务模块](../apis-media-kit/arkts-apis-media.md)。

### pausePlayback<sup>20+</sup>

pausePlayback()

停止播放时显示当前帧，再次播放时从当前帧开始播放。

**系统接口：** 该接口为系统接口。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Non-system applications are not allowed to use system APIs. |

### reset<sup>20+</sup>

reset()

重置播放时显示封面帧，再次播放时从头开始播放。

**系统接口：** 该接口为系统接口。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Non-system applications are not allowed to use system APIs. |

### restart<sup>20+</sup>

restart()

重启播放视频，继承当前播放区间和播放模式参数。

**系统接口：** 该接口为系统接口。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Non-system applications are not allowed to use system APIs. |

### setPlaybackPeriod<sup>20+</sup>

setPlaybackPeriod(startTime: double, endTime: double)

设置播放区间，再次播放时生效。

**系统接口：** 该接口为系统接口。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 参数名  | 类型    | 必填 | 说明                         |
| ------- | ------- | ---- | ---------------------------- |
| startTime| double| 是   | 区间播放开始时间，单位：ms。取值范围：大于等于0。|
| endTime| double| 是   | 区间播放结束时间，单位：ms。取值范围：大于startTime。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Non-system applications are not allowed to use system APIs. |

### enableTransition<sup>20+</sup>

enableTransition(enabled: boolean)

关闭视频启动播放时的放大效果，再次播放时生效。

**系统接口：** 该接口为系统接口。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 参数名  | 类型    | 必填 | 说明                         |
| ------- | ------- | ---- | ---------------------------- |
| enabled| boolean| 是   | 是否开启放大过渡效果。true表示开启，false表示不开启。<br></div>默认值：true。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Non-system applications are not allowed to use system APIs. |

### enableAutoPlay<sup>20+</sup>

enableAutoPlay(enabled: boolean)

控制动态照片数据中视频是否能够自动播放并自动播放一次。

**系统接口：** 该接口为系统接口。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 参数名  | 类型    | 必填 | 说明                         |
| ------- | ------- | ---- | ---------------------------- |
| enabled| boolean| 是   | 是否能够自动播放。true表示能自动播放，false表示不能自动播放。<br></div>默认值：false。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Non-system applications are not allowed to use system APIs. |
