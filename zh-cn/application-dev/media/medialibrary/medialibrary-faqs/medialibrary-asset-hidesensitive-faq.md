# 查看的媒体图片未包含地理位置信息
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhaochang14-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## 问题现象

使用只读模式打开图片后，解析图片无法获取图片中的地理位置信息。

## 问题原因

为了保护用户图片中的隐私信息，应用在读取图片时，[Media Library Kit](../photoAccessHelper-overview.md)（媒体文件管理服务）会对图片进行脱敏（抹除图片EXIF中敏感字段信息）处理，因此在图片使用过程中会出现地理位置丢失的情况。

> **注意：**
>
> 脱敏处理仅针对图片，视频不提供脱敏能力。

## 解决措施

应用申请[ohos.permission.MEDIA_LOCATION](../../../security/AccessToken/permissions-for-all-user.md#ohospermissionmedia_location)权限后，应用的脱敏级别变为不进行脱敏，应用即可正常获取图片所有敏感信息。

**示例**

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { dataSharePredicates } from '@kit.ArkData';
import { common } from '@kit.AbilityKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { image } from '@kit.ImageKit';

@Entry({ routeName : 'Scene1' })
@Component
export struct Scene1 {

  @State latitude: string = '';

  build() {
    NavDestination() {
      Column({ space: 20 }) {

        Button('example')
          .width('80%')
          .height(50)
          .fontSize(16)
          .onClick(async () => {
            let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
            this.latitude = await example(phAccessHelper, context);
          })
      }
      .width('100%')
      .height('100%')
    }
    .title('Get from Media Library')
  }
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context): Promise<string> {
  try {
    // 获取图片URI。
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = 
      await phAccessHelper.getAssets(fetchOption);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    // 通过图片URI打开图片。
    let file: fs.File = fs.openSync(photoAsset.uri, fs.OpenMode.READ_ONLY);
    const imageSourceObj = image.createImageSource(file.fd);
    console.info("getImagePropertySync");
    // 获取图片中的纬度信息。
    let latitude = imageSourceObj.getImagePropertySync(image.PropertyKey.GPS_LATITUDE);
    return latitude;
  } catch (err) {
    console.error(`get latitude failed with error: ${err.code}, ${err.message}`);
    return `get latitude failed with error: ${err.code}, ${err.message}`;
  }
}
```

## 附录

地理位置信息字段说明，具体字段说明和使用方式请参考Image Kit中的[PropertyKey](../../../reference/apis-image-kit/arkts-apis-image-e.md#propertykey7)。

| 名称  |  说明 |
| ----- | ---- |
| GPSLatitude | 图片纬度。 |
| GPSLongitude | 图片经度。 |
| GPSTimeStamp | GPS时间戳。 |
| GPSDateStamp | GPS日期戳。 |
| GPSAltitude | 基于GPSAltitudeRef的高度。 |
| GPSVersionID | GPS信息版本号。 |
