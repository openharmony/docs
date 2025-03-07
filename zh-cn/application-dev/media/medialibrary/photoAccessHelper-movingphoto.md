# 访问和管理动态照片资源

动态照片是一种结合了图片和视频的照片形式，可以显示一小段时间的动态画面和声音。可以帮助用户捕捉精彩的动态瞬间，提升创作空间，同时令拍照的容错率更高。

媒体库提供访问和管理动态照片资源的能力，包括：

- [使用安全控件保存动态照片资源](#保存动态照片资源)
- [获取动态照片对象（MovingPhoto）](#获取动态照片对象)
- [使用MovingPhotoView播放动态照片](movingphotoview-guidelines.md)
- [读取动态照片资源](#读取动态照片资源)

拍摄动态照片的能力由Camera Kit提供，开发者可参考[Camera Kit-动态照片](../camera/camera-moving-photo.md)。

## 保存动态照片资源

使用安全控件保存动态照片资源后，可用于获取MovingPhoto对象，从而完成播放动态照片等操作。 

使用安全控件保存动态照片资源，无需申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'，允许用户通过点击按钮临时获取存储权限，并将资源直接保存到指定的媒体库路径，使得操作更为便捷。

详情请参考[安全控件的保存控件](../../reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md)。

**开发步骤**

1. 设置安全控件按钮属性。
2. 创建安全控件按钮。
3. 调用[MediaAssetChangeRequest.createAssetRequest](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#createassetrequest11)接口新建一个创建资产的变更请求，指定待创建资产的子类型为动态照片。
4. 调用[MediaAssetChangeRequest.addResource](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#addresource11)接口指定动态照片的图片和视频内容。
   
   以下示例以从应用沙箱的[应用文件](../../file-management/app-file-access.md)fileUri指定动态照片的图片和视频内容为例。
   
   开发者可根据实际情况，通过ArrayBuffer的方式指定资源内容，参考[MediaAssetChangeRequest.addResource(type: ResourceType, data: ArrayBuffer)](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#addresource11-1)。

5. 调用[PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11)接口提交创建资产的变更请求。

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'
  @State saveButtonOptions: SaveButtonOptions = {
    icon: SaveIconStyle.FULL_FILLED,
    text: SaveDescription.SAVE_IMAGE,
    buttonType: ButtonType.Capsule
  } // 设置安全控件按钮属性。

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        SaveButton(this.saveButtonOptions) // 创建安全控件按钮。
          .onClick(async (event, result: SaveButtonOnClickResult) => {
             if (result == SaveButtonOnClickResult.SUCCESS) {
               try {
                 let context = getContext();
                 let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
                 // 需要确保imageFileUri和videoFileUri对应的资源存在，分别表示待创建到媒体库的动态照片的图片和视频。
                 let imageFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/create_moving_photo.jpg';
                 let videoFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/create_moving_photo.mp4';
                 let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context, photoAccessHelper.PhotoType.IMAGE, "jpg", {
                  title: "moving_photo",
                  subtype: photoAccessHelper.PhotoSubtype.MOVING_PHOTO
                 });
                 assetChangeRequest.addResource(photoAccessHelper.ResourceType.IMAGE_RESOURCE, imageFileUri);
                 assetChangeRequest.addResource(photoAccessHelper.ResourceType.VIDEO_RESOURCE, videoFileUri);
                 await phAccessHelper.applyChanges(assetChangeRequest);
                 console.info('create moving photo successfully, uri: ' + assetChangeRequest.getAsset().uri);
               } catch (err) {
                 console.error(`create moving photo failed with error: ${err.code}, ${err.message}`);
               }
             } else {
               console.error('SaveButtonOnClickResult create moving photo failed');
             }
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 获取动态照片对象

- 应用可以通过Picker的方式获取用户媒体库里的动态照片对象，后续可用于在应用内播放动态照片，或是读取动态照片资源进行其他操作（如上传到应用共享给他人浏览等）。

- 应用也可以通过传入应用沙箱的[应用文件](../../file-management/app-file-access.md)图片和视频fileUri的方式构造应用本地的动态照片对象。

获取到动态照片对象后，如需播放动态照片请使用[MovingPhotoView组件](movingphotoview-guidelines.md)。

### 获取媒体库动态照片对象

1. 通过Picker选择动态照片的[媒体文件](../../file-management/user-file-uri-intro.md#媒体文件uri)uri。
2. 调用[PhotoAccessHelper.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets-1)和[FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取uri对应的PhotoAsset资产。
3. 调用[MediaAssetManager.requestMovingPhoto](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#requestmovingphoto12)获取PhotoAsset对应的动态照片对象（MovingPhoto）。

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { dataSharePredicates } from '@kit.ArkData';
let context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  try {
    // picker选择动态照片uri。
    let photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
    photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.MOVING_PHOTO_IMAGE_TYPE;
    photoSelectOptions.maxSelectNumber = 9;
    let photoViewPicker = new photoAccessHelper.PhotoViewPicker();
    let photoSelectResult = await photoViewPicker.select(photoSelectOptions);
    let uris = photoSelectResult.photoUris;
    for (let i = 0; i < uris.length; i++) {
      // 获取uri对应的PhotoAsset资产。
      let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
      predicates.equalTo(photoAccessHelper.PhotoKeys.URI, uris[i]);
      let fetchOption: photoAccessHelper.FetchOptions = {
        fetchColumns: [],
        predicates: predicates
      };
      let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      // 获取PhotoAsset对应的动态照片对象。
      await photoAccessHelper.MediaAssetManager.requestMovingPhoto(context, photoAsset, {
        deliveryMode: photoAccessHelper.DeliveryMode.FAST_MODE
      }, {
        async onDataPrepared(movingPhoto: photoAccessHelper.MovingPhoto) {
          if (movingPhoto !== undefined) {
            // 应用可自定义对movingPhoto的处理逻辑。
            console.info('request moving photo successfully, uri: ' + movingPhoto.getUri());
          }
        }
      })
    }
  } catch (err) {
    console.error(`request moving photo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### 获取应用沙箱动态照片对象

调用[MediaAssetManager.loadMovingPhoto](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#loadmovingphoto12)加载应用沙箱的动态照片对象（MovingPhoto）。

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
let context = getContext(this);

async function example() {
  try {
    let imageFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/local_moving_photo.jpg';
    let videoFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/local_moving_photo.mp4';
    let movingPhoto = await photoAccessHelper.MediaAssetManager.loadMovingPhoto(context, imageFileUri, videoFileUri);
    console.info('load moving photo successfully');
  } catch (err) {
    console.error(`load moving photo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## 读取动态照片资源

对于一个动态照片对象，应用可以通过[MovingPhoto.requestContent](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#requestcontent12)导出图片和视频到应用沙箱，或者读取图片或视频的ArrayBuffer内容。

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(movingPhoto: photoAccessHelper.MovingPhoto) {
  try {
    let imageFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/request_moving_photo.jpg';
    let videoFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/request_moving_photo.mp4';
    await movingPhoto.requestContent(imageFileUri, videoFileUri); // 将动态照片导出到应用沙箱。
    let imageData = await movingPhoto.requestContent(photoAccessHelper.ResourceType.IMAGE_RESOURCE); // 读取图片的ArrayBuffer内容。
    let videoData = await movingPhoto.requestContent(photoAccessHelper.ResourceType.VIDEO_RESOURCE); // 读取视频的ArrayBuffer内容。
  } catch (err) {
    console.error(`request content of moving photo failed with error: ${err.code}, ${err.message}`);
  }
}
```
