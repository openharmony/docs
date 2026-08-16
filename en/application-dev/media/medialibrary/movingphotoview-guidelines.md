# Playing Moving Photos with MovingPhotoView

<!--Kit: Media Library Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @tangye123456-->
<!--Designer: @YanSanzo-->
<!--Tester: @tinygreyy-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=f54aea239b05f95120e350943376ec3af39fe8f4 translatedAt=2026-08-11T01:57:29.227Z pushedAt=2026-08-12T03:37:21.611Z -->

The system provides the **MovingPhotoView** component, which can be used to play moving photos in social networking and gallery applications.

## Constraints

The restrictions on using the **MovingPhotoView** component are as follows:

- Currently, live properties cannot be set.

- Currently, the ArkUI [expandSafeArea](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-expand-safe-area.md#expandsafearea) cannot be set.

- When this component is long pressed to trigger playback, the component area is zoomed in to 1.1 times.

- This component uses [AVPlayer](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md) to play moving photos. A maximum of three AVPlayers can be used at the same time. Otherwise, frame freezing may occur.

## How to Develop

1. Import modules.

   > **NOTE**
   >
   > - **MovingPhotoViewAttribute** is essential for configuring the **MovingPhotoView** component. In API version 21 and earlier, you must manually import **MovingPhotoViewAttribute** after importing the **MovingPhotoView** component. Otherwise, a compilation error is reported. However, starting from API version 22, the compilation toolchain automatically imports **MovingPhotoViewAttribute** when it detects the **MovingPhotoView** component, so manual import is no longer necessary.
   > - After **MovingPhotoViewAttribute** is imported, DevEco Studio displays it as grayed out, but this does not affect its usage.

    API version 21 and earlier:

     <!-- @[movingphotoview_import_api21](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/MovingPhotoViewSample/entry/src/main/ets/pages/Index.ets) -->

     ``` TypeScript
     //import { MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@kit.MediaLibraryKit';
     ```

    API version 22 and later:

     <!-- @[movingphotoview_import_api22](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/MovingPhotoViewSample/entry/src/main/ets/pages/Index.ets) -->

     ``` TypeScript
     import { MovingPhotoView, MovingPhotoViewController } from '@kit.MediaLibraryKit';
     ```

2. Obtain a [MovingPhoto](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MovingPhoto.md) object.

   Use the **photoAccessHelper** APIs to create or obtain a moving photo object. The **MovingPhotoView** receives only the constructed moving photo object.

   For details about how to create and obtain a moving photo object, see [Accessing and Managing Moving Photo Assets](photoAccessHelper-movingphoto.md).

   <!-- @[movingphotoview_src](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/MovingPhotoViewSample/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   @State src: photoAccessHelper.MovingPhoto | undefined = undefined
   ```

3. Create a [MovingPhotoViewController](../../reference/apis-media-library-kit/ohos-multimedia-movingphotoview.md#movingphotoviewcontroller) to control the playback status (such as playing or stopping) of the moving photo.

   <!-- @[movingphotoview_controller](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/MovingPhotoViewSample/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   controller: MovingPhotoViewController = new MovingPhotoViewController();
   ```

4. Create a MovingPhotoView instance.

   The values in the following sample code are only examples. For details about the value range of each parameter, see [@ohos.multimedia.movingphotoview](../../reference/apis-media-library-kit/ohos-multimedia-movingphotoview.md).

   <!-- @[movingphotoview_component](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/MovingPhotoViewSample/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // For API version 21 and earlier, import as follows: import { photoAccessHelper, MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@kit.MediaLibraryKit';
   // For API version 22 and later, import as follows:
   // import { photoAccessHelper, MovingPhotoView, MovingPhotoViewController } from '@kit.MediaLibraryKit';
   
   @Entry
   @Component
   struct Index {
     @State src: photoAccessHelper.MovingPhoto | undefined = undefined
     // ...
     @State isMuted: boolean = false
     controller: MovingPhotoViewController = new MovingPhotoViewController();
   
     // ...
   
     build() {
       Column() {
         // ...

         MovingPhotoView({
           movingPhoto: this.src,
           controller: this.controller
         })
           // Whether to play muted. Controlled by a button here. The default value is false, meaning unmuted playback.
           .muted(this.isMuted)
           // Video display mode. The default value is Cover.
           .objectFit(ImageFit.Cover)
           // Triggered when playback starts.
           .onStart(() => {
             console.info('onStart');
           })
           // Triggered when playback ends.
           .onFinish(() => {
             console.info('onFinish');
           })
           // Triggered when playback stops.
           .onStop(() => {
             console.info('onStop')
           })
           // Triggered when an error occurs.
           .onError(() => {
             console.error('onError');
           })
         // ...
    
         Row() {
           // Button: Start playback.
           Button('PLAY')
             .onClick(() => {
               this.controller.startPlayback()
             })
             .margin(5)
           // Button: Stop playback.
           Button('STOP')
             .onClick(() => {
               this.controller.stopPlayback()
             })
             .margin(5)
           // ...
         }
         .alignItems(VerticalAlign.Center)
         .justifyContent(FlexAlign.Center)
         .height('15%')
       }
       // ...
     }
   }
   ```

## Effect

![](figures/moving-photo-view.gif)