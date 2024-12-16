# 保存媒体库资源

## 安全控件保存

下面以使用安全控件创建一张图片资源为例。使用安全控件创建媒体资源无需在应用中申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'，详情请参考[安全控件的保存控件](../../reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md)。

**开发步骤**

1. 设置安全控件按钮属性。
2. 创建安全控件按钮。
3. 调用[MediaAssetChangeRequest.createImageAssetRequest](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#createimageassetrequest11)和[PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11)接口创建图片资源。

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';

@Entry
@Component
struct Index {
    saveButtonOptions: SaveButtonOptions = {
    icon: SaveIconStyle.FULL_FILLED,
    text: SaveDescription.SAVE_IMAGE,
    buttonType: ButtonType.Capsule
  } // 设置安全控件按钮属性

  build() {
    Row() {
      Column() {
        SaveButton(this.saveButtonOptions) // 创建安全控件按钮
          .onClick(async (event, result: SaveButtonOnClickResult) => {
             if (result == SaveButtonOnClickResult.SUCCESS) {
               try {
                 let context = getContext();
                 let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
                 // 需要确保fileUri对应的资源存在
                 let fileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg';
                 let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createImageAssetRequest(context, fileUri);
                 await phAccessHelper.applyChanges(assetChangeRequest);
                 console.info('createAsset successfully, uri: ' + assetChangeRequest.getAsset().uri);
               } catch (err) {
                 console.error(`create asset failed with error: ${err.code}, ${err.message}`);
               }
             } else {
               console.error('SaveButtonOnClickResult create asset failed');
             }
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

除了上述通过fileUri从应用沙箱指定资源内容的方式，开发者还可以通过ArrayBuffer的方式添加资源内容，详情请参考[addResource](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#addresource11-1)接口。

## 弹窗授权保存

下面以弹窗授权的方式保存一张图片资源为例。使用弹窗授权保存媒体资源无需在应用中申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'。

**开发步骤**

1. 指定待保存到媒体库的位于应用沙箱的图片uri。
2. 指定待保存照片的创建选项，包括文件后缀和照片类型，标题和照片子类型可选。
3. 调用[showAssetsCreationDialog](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#showassetscreationdialog12)，基于弹窗授权的方式获取媒体库的目标uri。
4. 将来源于应用沙箱的照片内容写入媒体库的目标uri。

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { fileIo } from '@kit.CoreFileKit';

let context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  try {
    // 指定待保存到媒体库的位于应用沙箱的图片uri
    let srcFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg';
    let srcFileUris: Array<string> = [
      srcFileUri
    ];
    // 指定待保存照片的创建选项，包括文件后缀和照片类型，标题和照片子类型可选
    let photoCreationConfigs: Array<photoAccessHelper.PhotoCreationConfig> = [
      {
        title: 'test', // 可选
        fileNameExtension: 'jpg',
        photoType: photoAccessHelper.PhotoType.IMAGE,
        subtype: photoAccessHelper.PhotoSubtype.DEFAULT, // 可选
      }
    ];
    // 基于弹窗授权的方式获取媒体库的目标uri
    let desFileUris: Array<string> = await phAccessHelper.showAssetsCreationDialog(srcFileUris, photoCreationConfigs);
    // 将来源于应用沙箱的照片内容写入媒体库的目标uri
    let desFile: fileIo.File = await fileIo.open(desFileUris[0], fileIo.OpenMode.WRITE_ONLY);
    let srcFile: fileIo.File = await fileIo.open(srcFileUri, fileIo.OpenMode.READ_ONLY);
    await fileIo.copyFile(srcFile.fd, desFile.fd);
    fileIo.closeSync(srcFile);
    fileIo.closeSync(desFile);
    console.info('create asset by dialog successfully');
  } catch (err) {
    console.error(`failed to create asset by dialog successfully errCode is: ${err.code}, ${err.message}`);
  }
}
```
