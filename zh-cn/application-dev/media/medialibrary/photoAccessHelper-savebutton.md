# 使用安全控件创建媒体资源

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
  @State message: string = 'Hello World'
  @State saveButtonOptions: SaveButtonOptions = {
    icon: SaveIconStyle.FULL_FILLED,
    text: SaveDescription.SAVE_IMAGE,
    buttonType: ButtonType.Capsule
  } // 设置安全控件按钮属性

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
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