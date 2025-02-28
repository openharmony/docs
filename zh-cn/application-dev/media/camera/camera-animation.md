# 相机基础动效(ArkTS)

在使用相机过程中，如相机模式切换，前后置镜头切换等场景，不可避免出现预览流替换，为优化用户体验，可合理使用动效过渡。本文主要介绍如何使用预览流截图，并通过ArkUI提供的[显示动画能力](../../reference/apis-arkui/arkui-ts/ts-explicit-animatetoimmediately.md)实现下方三种核心场景动效：

- 模式切换动效，使用预览流截图做模糊动效过渡。
  
   图片为从录像模式切换为拍照模式的效果。

   ![](figures/mode-switching.gif)

- 前后置切换动效，使用预览流截图做翻转模糊动效过渡。

   图片为从前置摄像头切换为后置摄像头的效果。

   ![](figures/front-rear-switching.gif)

- 拍照闪黑动效，使用闪黑组件覆盖预览流实现闪黑动效过渡。
  
  图片为点击完成拍摄的效果。

  ![](figures/flash-black.gif)

## 闪黑动效

使用组件覆盖的形式实现闪黑效果。

1. 导入依赖，需要导入相机框架、图片、ArkUI相关领域依赖。

   ```ts
   import { curves } from '@kit.ArkUI';
   ```

2. 构建闪黑组件。

   此处定义一个闪黑组件，在拍照闪黑及前后置切换时显示，用来遮挡XComponent组件。

   属性定义：

   ```ts
   @State isShowBlack: boolean = false; // 是否显示闪黑组件。
   @StorageLink('captureClick') @Watch('onCaptureClick') captureClickFlag: number = 0; // 拍照闪黑动效入口。
   @State flashBlackOpacity: number = 1; // 闪黑组件透明度。
   ```

   闪黑组件的实现逻辑参考：

   ```ts
   // 拍照闪黑及前后置切换时显示，用来遮挡XComponent组件。
   if (this.isShowBlack) {
     Column()
       .key('black')
       .width(px2vp(1080)) // 与预览流XComponent宽高保持一致，图层在预览流之上，截图组件之下。
       .height(px2vp(1920))
       .backgroundColor(Color.Black)
       .opacity(this.flashBlackOpacity)
   }
   ```

3. 实现闪黑动效。

   ```ts
   function flashBlackAnim() {
     console.info('flashBlackAnim E');
     this.flashBlackOpacity = 1; // 闪黑组件不透明。
     this.isShowBlack = true; // 显示闪黑组件。
     animateToImmediately({
       curve: curves.interpolatingSpring(1, 1, 410, 38),
       delay: 50, // 延时50ms，实现黑屏。
       onFinish: () => {
         this.isShowBlack = false; // 闪黑组件下树。
         this.flashBlackOpacity = 1;
         console.info('flashBlackAnim X');
       }
     }, () => {
       this.flashBlackOpacity = 0; // 闪黑组件从不透明到透明。
     })
   }
   ```

4. 触发闪黑动效。

   点击或触控拍照按钮，更新StorageLink绑定CaptureClick的值，触发onCaptureClick方法，动效开始播放。

   ```ts
   onCaptureClick(): void {
     console.info('onCaptureClick');
       console.info('onCaptureClick');
       this.flashBlackAnim();
   }
   ```



## 模糊动效

通过预览流截图，实现模糊动效，从而完成模式切换，或是前后置切换的动效。

1. 导入依赖，需要导入相机框架、图片、ArkUI相关领域依赖。

   ```ts
   import { camera } from '@kit.CameraKit';
   import { image } from '@kit.ImageKit';
   import { curves } from '@kit.ArkUI';
   ```

2. 获取预览流截图。

   预览流截图通过图形提供的[image.createPixelMapFromSurface](../../reference/apis-image-kit/js-apis-image.md#imagecreatepixelmapfromsurface11)接口实现，surfaceId为当前预览流的surfaceId，size为当前预览流profile的宽高。创建截图工具类(ts文件)，导入依赖，导出获取截图方法供页面使用，截图工具类实现参考：

   ```ts
   import { image } from '@kit.ImageKit';
   
   export class BlurAnimateUtil {
     public static surfaceShot: image.PixelMap;
   
     /**
      * 获取surface截图
      * @param surfaceId
      * @returns
      */
     public static async doSurfaceShot(surfaceId: string) {
       console.info(`doSurfaceShot surfaceId:${surfaceId}.`);
       if (surfaceId === '') {
         console.error('surface not ready!');
         return;
       }
       try {
         if (this.surfaceShot) {
           await this.surfaceShot.release();
         }
         this.surfaceShot = await image.createPixelMapFromSurface(surfaceId, {
           size: { width: 1920, height: 1080 }, // 取预览流profile的宽高。
           x: 0,
           y: 0
         });
         let imageInfo: image.ImageInfo = await this.surfaceShot.getImageInfo();
         console.info('doSurfaceShot surfaceShot:' + JSON.stringify(imageInfo.size));
       } catch (err) {
         console.error(JSON.stringify(err));
       }
     }
   
     /**
      * 获取doSurfaceShot得到的截图
      * @returns
      */
     public static getSurfaceShot(): image.PixelMap {
       return this.surfaceShot;
     }
   }
   ```

3. 构建截图组件。

   此处定义一个截图组件，置于预览流XComponent组件之上，用来遮挡XComponent组件。

   属性定义：

   ```ts
   @State isShowBlur: boolean = false; // 是否显示截图组件。
   @StorageLink('modeChange') @Watch('onModeChange') modeChangeFlag: number = 0; // 模式切换动效触发入口。
   @StorageLink('switchCamera') @Watch('onSwitchCamera') switchCameraFlag: number = 0;// 前后置切换动效触发入口。
   @StorageLink('frameStart') @Watch('onFrameStart') frameStartFlag: number = 0; // 动效消失入口。
   @State screenshotPixelMap: image.PixelMap | undefined = undefined; // 截图组件PixelMap。
   @State surfaceId: string = ''; // 当前预览流XComponent的surfaceId。
   @StorageLink('curPosition') curPosition: number = 0; // 当前镜头前后置状态。
   @State shotImgBlur: number = 0; // 截图组件模糊度。
   @State shotImgOpacity: number = 1; // 截图组件透明度。
   @State shotImgScale: ScaleOptions = { x: 1, y: 1 }; // 截图组件比例。
   @State shotImgRotation: RotateOptions = { y: 0.5, angle: 0 } // 截图组件旋转角度。
   ```

   截图组件的实现参考：

   ```ts
   // 截图组件，置于预览流XComponent组件之上。
   if (this.isShowBlur) {
     Column() {
       Image(this.screenshotPixelMap)
         .blur(this.shotImgBlur)
         .opacity(this.shotImgOpacity)
         .rotate(this.shotImgRotation)// ArkUI提供，用于组件旋转。
         .scale(this.shotImgScale)
         .width(px2vp(1080)) // 与预览流XComponent宽高保持一致，图层在预览流之上。
         .height(px2vp(1920))
         .syncLoad(true)
     }
     .width(px2vp(1080))
     .height(px2vp(1920))
   }
   ```

4. （按实际情况选择）实现模糊出现动效。

   模式切换动效分两段实现，模糊出现动效和模糊消失动效。

   模糊出现动效：用户点击或触控事件触发预览流截图，显示截图组件，截图清晰到模糊，覆盖旧预览流。

   > 注意：由于图形提供的image.createPixelMapFromSurface接口是截取surface内容获取PixelMap，其内容和XComponent组件绘制逻辑不同，需要根据**前后置**镜头做不同的**图片内容旋转补偿**和**组件旋转补偿**。

   ```ts
   async function showBlurAnim() {
     console.info('showBlurAnim E');
     // 获取已完成的surface截图。
     let shotPixel = BlurAnimateUtil.getSurfaceShot();
     // 后置。
     if (this.curPosition === 0) {
       console.info('showBlurAnim BACK');
       // 直板机后置截图初始内容旋转补偿90°。
       await shotPixel.rotate(90); //ImageKit提供，用于图片内容旋转。
       // 直板机后置截图初始组件旋转补偿0°。
       this.shotImgRotation = { y: 0.5, angle: 0 };
     } else {
       console.info('showBlurAnim FRONT');
       // 直板机前置截图内容旋转补偿270°。
       await shotPixel.rotate(270);
       // 直板机前置截图组件旋转补偿180°。
       this.shotImgRotation = { y: 0.5, angle: 180 };
     }
     this.screenshotPixelMap = shotPixel;
     // 初始化动效参数。
     this.shotImgBlur = 0; // 无模糊。
     this.shotImgOpacity = 1; // 不透明。
     this.isShowBlur = true;  // 显示截图组件。
     animateToImmediately(
       {
         duration: 200,
         curve: Curve.Friction,
         onFinish: async () => {
           console.info('showBlurAnim X');
         }
       },
       () => {
         this.shotImgBlur = 48; // 截图组件模糊度变化动效。
       }
     );
   }
   ```

5. 实现模糊消失动效。

   模糊消失动效：由新模式预览流首帧回调[on('frameStart')](../../reference/apis-camera-kit/js-apis-camera.md#onframestart)触发，截图组件模糊到清晰，显示新预览流。

   ```ts
   function hideBlurAnim(): void {
     this.isShowBlack = false;
     console.info('hideBlurAnim E');
     animateToImmediately({
       duration: 200,
       curve: Curve.FastOutSlowIn,
       onFinish: () => {
         this.isShowBlur = false; // 模糊组件下树。
         this.shotImgBlur = 0;
         this.shotImgOpacity = 1;
         console.info('hideBlurAnim X');
       }
     }, () => {
       // 截图透明度变化动效。
       this.shotImgOpacity = 0; // 截图组件透明度变化动效。
     });
   }
   ```

6. （按实际情况选择）实现模糊翻转动效。

   模糊翻转动效分两段实现，模糊翻转动效和模糊消失动效，其中模糊消失动效同第5步。

   模糊翻转动效：分两段组件翻转实现，先向外翻转90°再向内翻转90°，同时还执行了模糊度、透明度、比例缩放等动效。

   为保证预览流在翻转时不露出，需要构建一个闪黑组件用于遮挡XComponent组件，构建方式参考[闪黑动效](#闪黑动效)-步骤2。

   ```ts
   /**
    * 先向外翻转90°，前后置切换触发
    */
   async function rotateFirstAnim() {
     console.info('rotateFirstAnim E');
     // 获取已完成的surface截图。
     let shotPixel = BlurAnimateUtil.getSurfaceShot();
     // 后置切前置。
     if (this.curPosition === 1) {
       console.info('rotateFirstAnim BACK');
       // 直板机后置切前置截图初始内容旋转补偿90°。
       await shotPixel.rotate(90); //ImageKit提供，用于图片内容旋转。
       // 直板机后置切前置截图初始组件旋转补偿0°。
       this.shotImgRotation = { y: 0.5, angle: 0 };
     } else {
       console.info('rotateFirstAnim FRONT');
       // 直板机前置切后置截图初始内容旋转补偿270°。
       await shotPixel.rotate(270);
       // 直板机前置切后置截图初始组件旋转补偿180°。
       this.shotImgRotation = { y: 0.5, angle: 180 };
     }
     this.screenshotPixelMap = shotPixel;
     this.isShowBlack = true; // 显示闪黑组件，覆盖预览流保证视觉效果。
     this.isShowBlur = true; // 显示截图组件。
     animateToImmediately(
       {
         duration: 200,
         delay: 50, // 时延保证组件缩放模糊动效先行，再翻转,视觉效果更好。
         curve: curves.cubicBezierCurve(0.20, 0.00, 0.83, 1.00),
         onFinish: () => {
           console.info('rotateFirstAnim X');
           // 在onFinish后触发二段翻转。
           this.rotateSecondAnim();
         }
       },
       () => {
         // 截图向外翻转动效。
         if (this.curPosition === 1) {
           this.shotImgRotation = { y: 0.5, angle: 90 };
         } else {
           this.shotImgRotation = { y: 0.5, angle: 270 };
         }
       }
     )
   }
   
   /**
    * 再向内翻转90°
    */
   async function rotateSecondAnim() {
     console.info('rotateSecondAnim E');
     // 获取已完成的surface截图。
     let shotPixel = BlurAnimateUtil.getSurfaceShot();
     // 后置。
     if (this.curPosition === 1) {
       // 直板机后置镜头内容旋转补偿90°。
       await shotPixel.rotate(90);
       // 组件旋转调整为-90°，保证二段翻转后，图片不是镜像的。
       this.shotImgRotation = { y: 0.5, angle: 90 };
     } else { // 前置。
       // 直板机前置截图内容旋转补偿270°。
       await shotPixel.rotate(270);
       // 直板机前置截图组件旋转补偿180°。
       this.shotImgRotation = { y: 0.5, angle: 180 };
     }
     this.screenshotPixelMap = shotPixel;
     animateToImmediately(
       {
         duration: 200,
         curve: curves.cubicBezierCurve(0.17, 0.00, 0.20, 1.00),
         onFinish: () => {
           console.info('rotateSecondAnim X');
         }
       },
       () => {
         // 截图向内翻转动效，翻转至初始状态。
         if (this.curPosition === 1) {
           this.shotImgRotation = { y: 0.5, angle: 0 };
         } else {
           this.shotImgRotation = { y: 0.5, angle: 180 };
         }
       }
     )
   }
   
   /**
    * 向外翻转90°同时
    */
   function blurFirstAnim() {
     console.info('blurFirstAnim E');
     // 初始化动效参数。
     this.shotImgBlur = 0; //无模糊。
     this.shotImgOpacity = 1; //不透明。
     this.shotImgScale = { x: 1, y: 1 };
     animateToImmediately(
       {
         duration: 200,
         curve: Curve.Sharp,
         onFinish: () => {
           console.info('blurFirstAnim X');
           this.blurSecondAnim();
         }
       },
       () => {
         // 截图模糊动效。
         this.shotImgBlur = 48;
         // 截图比例缩小动效。
         this.shotImgScale = { x: 0.75, y: 0.75 };
       }
     );
   }
   
   /**
    * 向内翻转90°同时
    */
   function blurSecondAnim() {
     console.info('blurSecondAnim E');
     animateToImmediately(
       {
         duration: 200,
         curve: Curve.Sharp,
         onFinish: () => {
           console.info('blurSecondAnim X');
         }
       },
       () => {
         // 截图比例恢复动效。
         this.shotImgScale = { x: 1, y: 1 };
       }
     )
   }
   ```

7. 按需触发动效。

   模式切换动效触发：点击或触控模式按钮立即执行doSurfaceShot截图方法，更新StorageLink绑定modeChange的值，触发onModeChange方法，开始动效。

   ```ts
   onModeChange(): void {
     console.info('onModeChange');
     this.showBlurAnim();
   }
   ```

   前后置切换动效触发：点击或触控前后置切换按钮立即执行doSurfaceShot截图方法，更新StorageLink绑定switchCamera的值，触发onSwitchCamera方法，开始动效。

   ```ts
   onSwitchCamera(): void {
     console.info('onSwitchCamera');
     this.blurFirstAnim();
     this.rotateFirstAnim();
   }
   ```

   模糊消失动效触发：监听预览流首帧回调[on('frameStart')](../../reference/apis-camera-kit/js-apis-camera.md#onframestart)，更新StorageLink绑定frameStart的值，触发onFrameStart方法，开始动效。

   ```ts
   onFrameStart(): void {
     console.info('onFrameStart');
     this.hideBlurAnim();
   }
   ```
