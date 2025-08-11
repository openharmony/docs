# Playing Moving Photos with MovingPhotoView 

The system provides the **MovingPhotoView** component, which can be used to play moving photos in social networking and gallery applications.

## Constraints

The restrictions on using the **MovingPhotoView** component are as follows:

- Currently, live properties cannot be set.
- Currently, the ArkUI [expandSafeArea](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-expand-safe-area.md#expandsafearea) cannot be set.
- When this component is long pressed to trigger playback, the component area is zoomed in to 1.1 times.
- This component uses [AVPlayer](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md) to play moving photos. A maximum of three AVPlayers can be used at the same time. Otherwise, frame freezing may occur.

## How to Develop

1. Import modules.
 
   ```ts
   import { MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@kit.MediaLibraryKit';
   ```

2. Obtain a [MovingPhoto](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MovingPhoto.md) object.

   Use the **photoAccessHelper** APIs to create or obtain a moving photo object. The **MovingPhotoView** receives only the constructed moving photo object.

   For details about how to create and obtain a moving photo object, see [Accessing and Managing Moving Photo Assets](photoAccessHelper-movingphoto.md).

   ```ts
   src: photoAccessHelper.MovingPhoto | undefined = undefined;
   ```

3. Create a [MovingPhotoViewController](../../reference/apis-media-library-kit/ohos-multimedia-movingphotoview.md#movingphotoviewcontroller) to control the playback status (such as playing or stopping) of the moving photo.

   ```ts
   controller: MovingPhotoViewController = new MovingPhotoViewController();
   ```

4. Create a MovingPhotoView instance.

   The values in the following sample code are only examples. For details about the value range of each parameter, see [@ohos.multimedia.movingphotoview](../../reference/apis-media-library-kit/ohos-multimedia-movingphotoview.md).

   ```ts
    import { photoAccessHelper, MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@kit.MediaLibraryKit';

    @Entry
    @Component
    struct Index {
      @State src: photoAccessHelper.MovingPhoto | undefined = undefined
      @State isMuted: boolean = false
      controller: MovingPhotoViewController = new MovingPhotoViewController();
      build() {
        Column() {
          MovingPhotoView({
            movingPhoto: this.src,
            controller: this.controller
          })
            // Whether to mute the playback. The default value is false. In this example, it is controlled by the button.
            .muted(this.isMuted)
            // Video display mode. The default value is Cover.
            .objectFit(ImageFit.Cover)
            // Triggered when the playback starts.
            .onStart(() => {
              console.log('onStart');
            })
            // Triggered when the playback ends.
            .onFinish(() => {
              console.log('onFinish');
            })
            // Triggered when the playback stops.
            .onStop(() => {
              console.log('onStop')
            })
            // Triggered when an error occurs.
            .onError(() => {
              console.log('onError');
            })
    
          Row() {
            // Button for starting playback.
            Button('start')
              .onClick(() => {
                this.controller.startPlayback()
              })
              .margin(5)
            // Button for stopping playback.
            Button('stop')
              .onClick(() => {
                this.controller.stopPlayback()
              })
              .margin(5)
            // Button controlling whether to mute the playback.
            Button('mute')
              .onClick(() => {
                this.isMuted = !this.isMuted
              })
              .margin(5)
          }
          .alignItems(VerticalAlign.Center)
          .justifyContent(FlexAlign.Center)
          .height('15%')
        }
      }
    }
   ```

## Effect

![](figures/moving-photo-view.gif)
