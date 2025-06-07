# Using the System Camera to Take Photos and Record Videos (CameraPicker)

Applications can invoke the camera picker to take photos or record videos without applying for the camera permission.
The camera interaction UI of the camera picker is provided by the system. After a user touches the **PHOTO** and **OK** buttons, the application that invokes the camera picker obtains a photo or video.

If your application only needs to obtain photos or videos taken in real time, it can invoke the camera picker.

Given that users are the ones who actively take and confirm the photos, your application does not need to request the permission to operate the camera.

## How to Develop

Read [CameraPicker](../../reference/apis-camera-kit/js-apis-cameraPicker.md) for the API reference.

1. Import the module.
   ```ts
   import { camera, cameraPicker as picker } from '@kit.CameraKit';
   import { fileIo, fileUri } from '@kit.CoreFileKit';
   ```

2. Configure [PickerProfile](../../reference/apis-camera-kit/js-apis-cameraPicker.md#pickerprofile).

   > **NOTE**
   >
   > The **saveUri** parameter of **PickerProfile** is optional. If this parameter is not set, photos and videos are stored in the media library by default.
   >
   > If you do not want to save photos and videos to the media library, configure a file path in the application sandbox. Ensure that this file is already present and writable. By passing the file's URI into the **picker** API, you are effectively giving the camera picker permission to read from and write to this file. Upon completion of a photo or video capture, the camera picker will replace the contents of this file.

   ```ts
   function createPickerProfile(context: Context): picker.PickerProfile {
     let pathDir = context.filesDir;
     let fileName = `${new Date().getTime()}`;
     let filePath = pathDir + `/${fileName}.tmp`;
     fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.CREATE);
     
     let uri = fileUri.getUriFromPath(filePath);
     let pickerProfile: picker.PickerProfile = {
       cameraPosition: camera.CameraPosition.CAMERA_POSITION_BACK,
       saveUri: uri
     };
     return pickerProfile;
   }
   ```

3. Call the **picker** API to obtain the photo or video capture result.
   ```ts
   async function getPickerResult(context: Context, pickerProfile: picker.PickerProfile): Promise<picker.PickerResult> {
     let result: picker.PickerResult =
       await picker.pick(context, [picker.PickerMediaType.PHOTO, picker.PickerMediaType.VIDEO],
         pickerProfile);
     console.info(`picker resultCode: ${result.resultCode},resultUri: ${result.resultUri},mediaType: ${result.mediaType}`);
     return result;
   }
   ```

## Example
   ```ts 
   import { camera, cameraPicker as picker } from '@kit.CameraKit';
   import { fileIo, fileUri } from '@kit.CoreFileKit';

   @Entry
   @Component
   struct Index {
     @State imgSrc: string = '';
     @State videoSrc: string = '';
     createPickerProfile(context: Context): picker.PickerProfile {
       let pathDir = context.filesDir;
       let fileName = `${new Date().getTime()}`
       let filePath = pathDir + `/${fileName}.tmp`
       fileIo.createRandomAccessFileSync(filePath, fileIo.OpenMode.CREATE);
       
       let uri = fileUri.getUriFromPath(filePath);
       let pickerProfile: picker.PickerProfile = {
         cameraPosition: camera.CameraPosition.CAMERA_POSITION_BACK,
         saveUri: uri
       };
       return pickerProfile;
     }

     async getPickerResult(context: Context, pickerProfile: picker.PickerProfile): Promise<picker.PickerResult> {
       let result: picker.PickerResult =
         await picker.pick(context, [picker.PickerMediaType.PHOTO, picker.PickerMediaType.VIDEO],
           pickerProfile);
       console.info(`picker resultCode: ${result.resultCode},resultUri: ${result.resultUri},mediaType: ${result.mediaType}`);
       return result;
     }

     getContext(): Context | undefined {
       let uiContext: UIContext = this.getUIContext();
       let context: Context | undefined = uiContext.getHostContext();
       return context;
     }

     build() {
       RelativeContainer() {
         Column() {
           Image(this.imgSrc).width(200).height(200).backgroundColor(Color.Black).margin(5);
           Video({ src: this.videoSrc}).width(200).height(200).autoPlay(true);
           Button("Test Picker Photo&Video").fontSize(20)
             .fontWeight(FontWeight.Bold)
             .onClick(async () => {
               let context = this.getContext();
               if (context === undefined) {
                 return;
               }
               let pickerProfile = this.createPickerProfile(context);
               let result = await this.getPickerResult(context, pickerProfile);
               if (result.resultCode == 0) {
                 if (result.mediaType === picker.PickerMediaType.PHOTO) {
                   this.imgSrc = result.resultUri;
                 } else {
                   this.videoSrc = result.resultUri;
                 }
               }
             }).margin(5);
   
         }.alignRules({
           center: { anchor: '__container__', align: VerticalAlign.Center },
           middle: { anchor: '__container__', align: HorizontalAlign.Center }
         });
       }
       .height('100%')
       .width('100%')
     }
   }
   ```
