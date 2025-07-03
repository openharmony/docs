# @ohos.multimedia.movingphotoview (动态照片)(系统接口)

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