# Creating a Media Asset Using SaveButton

This topic walks you through on how to create an image using the **SaveButton** security component. When **SaveButton** is used to create a media asset, the caller does not need to have the ohos.permission.WRITE_IMAGEVIDEO permission. For details, see [SaveButton](../../reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md).

**How to Develop**

1. Set the attributes of the security component.
2. Create a button with the security component.
3. Use [MediaAssetChangeRequest.createImageAssetRequest](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#createimageassetrequest11) and [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11) to create an image asset.

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
  } // Set the attributes of the security component.

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        SaveButton(this.saveButtonOptions) // Create a security component.
          .onClick(async (event, result: SaveButtonOnClickResult) => {
             if (result == SaveButtonOnClickResult.SUCCESS) {
               try {
                 let context = getContext();
                 let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
                 // Ensure that the asset specified by fileUri exists.
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
