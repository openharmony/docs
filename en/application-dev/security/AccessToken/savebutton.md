# Using \<SaveButton>

The \<**SaveButton**> component comes with the privilege for saving data, which allows an application to temporarily save data without any authorization information.

When it is tapped, the application obtains one-time permission to access the **mediaLibrary** APIs within 10 seconds. You can use this component when your application needs to save image or videos to the media library.

This component allows for simpler operations than Pickers, which have to start a system application and have the user select a directory for saving the image or video.

The following figure shows the effect of the \<**SaveButton**> component.

![](figures/SaveButton_effect.png)

## Constraints

- The interval for calling **onClick()** to trigger a **mediaLibrary** API cannot exceed 10 seconds after **\<SaveButton>** is tapped.

- Each time the component is tapped, the application obtains only one-time perform for API calling.

- The \<**SaveButton**> component must be visible and legible to users. You need to properly configure the component attributes such as the size and color to prevent authorization failures. If the authorization fails due to invalid component style, check the device error logs.

## How to Develop

For example, to save the image in the dialog box shown above, the application only needs to use the image saving feature for a short period of time in the foreground. In this case, you can the \<**SaveButton**> component to obtain temporary permission to save the image without requesting the related permission for the application.

1. Import the dependencies.
   
   ```ts
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   import fs from '@ohos.file.fs';
   ```

2. Set the image asset and add the \<**SaveButton**> component.
   
   The \<**SaveButton**> component is a button-like component consisting of an icon, text, and background. Either the icon or text is mandatory, and the background is optional. The icon and text cannot be customized. You can only select from the existing options. When declaring the API for creating a security component, you can determine whether to pass in parameters. If parameters are passed in, the component is created based on the specified parameters. If no parameter is passed in, a component with default icon, text, and background is created.

   The following example uses the default parameters. For details, see [SaveButton](../../reference/arkui-ts/ts-security-components-savebutton.md).<br>In addition, all security components inherit the [Security Component Universal Attributes](../../reference/arkui-ts/ts-securitycomponent-attributes.md), which can be used to customize styles.
   
   ```ts
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   import fs from '@ohos.file.fs';
   import common from '@ohos.app.ability.common';
   import promptAction from '@ohos.promptAction';
   import { BusinessError } from '@ohos.base';
   
   async function savePhotoToGallery(context: common.UIAbilityContext) {
     let helper = photoAccessHelper.getPhotoAccessHelper(context);
     try {
       // After onClick is triggered, call createAsset API within 5 seconds to create an image. After 5 seconds have elapsed, the permission to call createAsset is revoked.
       let uri = await helper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'jpg');
       // Open the file based on its URI. The write process is not time bound.
       let file = await fs.open(uri, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
       context.resourceManager.getMediaContent($r('app.media.icon').id, 0)
         .then(async value => {
           let media = value.buffer;
           // Write data to the file in the media library.
           await fs.write(file.fd, media);
           await fs.close(file.fd);
           promptAction.showToast({message: 'Saved to album.'});
         });
     }
     catch (error) {
       const err: BusinessError = error as BusinessError;
       console.error(`Failed to save photo. Code is ${err.code}, message is ${err.message}`);
     }
   }
   
   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         Column({ space: 10 }) {
           Image($r('app.media.icon'))
             .height(400)
             .width('100%')
   
           SaveButton().onClick(async (event: ClickEvent, result: SaveButtonOnClickResult) => {
             if (result === SaveButtonOnClickResult.SUCCESS) {
               const context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext;
               // Obtain temporary authorization to save the image without requesting the related permission for the application.
               savePhotoToGallery(context);
             } else {
               promptAction.showToast ({ message: 'Failed to set the permission.' })
             }
           })
         }
         .width('100%')
       }
       .height('100%')
       .backgroundColor(0xF1F3F5)
     }
   }
   ```
