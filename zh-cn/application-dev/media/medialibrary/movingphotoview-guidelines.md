# 使用MovingPhotoView播放动态照片

系统提供了MovingPhotoView组件，在一些社交类、图库类应用中，可用于播放动态照片文件。

## 约束与限制

针对MovingPhotoView组件的使用，有以下约束与限制：

- 当前不支持动态属性设置。
- 当前不支持设置ArkUI通用属性[expandSafeArea](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-expand-safe-area.md#expandsafearea)。
- 该组件长按触发播放时组件区域放大为1.1倍。
- 该组件使用[AVPlayer](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md)进行播放，同时开启的AVPlayer个数不建议超过3个，超过3个可能会出现视频播放卡顿现象。

## 开发步骤

1. 导入动态照片模块。
 
   ```ts
   import { MovingPhotoView, MovingPhotoViewController, MovingPhotoViewAttribute } from '@kit.MediaLibraryKit';
   ```

2. 获取动态照片对象（[MovingPhoto](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MovingPhoto.md)）。

   MovingPhoto对象需要通过photoAccessHelper接口创建或获取，MovingPhotoView只接收构造完成的MovingPhoto对象。

   创建、获取的方式可参考[访问和管理动态照片资源](photoAccessHelper-movingphoto.md)。

   ```ts
   src: photoAccessHelper.MovingPhoto | undefined = undefined;
   ```

3. 创建动态照片控制器（[MovingPhotoViewController](../../reference/apis-media-library-kit/ohos-multimedia-movingphotoview.md#movingphotoviewcontroller)），用于控制动态照片的播放状态（如播放、停止）。

   ```ts
   controller: MovingPhotoViewController = new MovingPhotoViewController();
   ```

4. 创建动态照片组件。

   以下参数取值仅为举例，具体每个属性的取值范围，可参考API文档：[@ohos.multimedia.movingphotoview](../../reference/apis-media-library-kit/ohos-multimedia-movingphotoview.md)。

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
            // 是否静音播放，此处由按钮控制，默认值为false非静音播放。
            .muted(this.isMuted)
            // 视频显示模式，默认值为Cover。
            .objectFit(ImageFit.Cover)
            // 播放时触发。
            .onStart(() => {
              console.log('onStart');
            })
            // 播放结束触发。
            .onFinish(() => {
              console.log('onFinish');
            })
            // 播放停止触发。
            .onStop(() => {
              console.log('onStop')
            })
            // 出现错误触发。
            .onError(() => {
              console.log('onError');
            })
    
          Row() {
            // 按钮：开始播放。
            Button('start')
              .onClick(() => {
                this.controller.startPlayback()
              })
              .margin(5)
            // 按钮：停止播放。
            Button('stop')
              .onClick(() => {
                this.controller.stopPlayback()
              })
              .margin(5)
            // 按钮：是否静音播放。
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

## 效果展示

![](figures/moving-photo-view.gif)