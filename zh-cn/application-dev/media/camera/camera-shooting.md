# 拍照(ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

拍照是相机的最重要功能之一，拍照模块基于相机复杂的逻辑，为了保证用户拍出的照片质量，在中间步骤可以设置分辨率、闪光灯、焦距、照片质量及旋转角度等信息。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/arkts-apis-camera.md)。

1. 导入image接口。创建拍照输出流的SurfaceId以及拍照输出的数据，都需要用到系统提供的image接口能力，导入image接口的方法如下。

   ```ts
   import { image } from '@kit.ImageKit';
   import { camera } from '@kit.CameraKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 创建拍照输出流。

   通过[CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability)类中的photoProfiles属性，可获取当前设备支持的拍照输出流，通过[createPhotoOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createphotooutput11)方法传入支持的某一个输出流及步骤一获取的SurfaceId创建拍照输出流。

   ```ts
   function getPhotoOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability): camera.PhotoOutput | undefined {
     let photoProfilesArray: Array<camera.Profile> = cameraOutputCapability.photoProfiles;
     if (!photoProfilesArray) {
       console.error("createOutput photoProfilesArray == null || undefined");
     }
     let photoOutput: camera.PhotoOutput | undefined = undefined;
     try {
       photoOutput = cameraManager.createPhotoOutput(photoProfilesArray[0]);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to createPhotoOutput. error: ${err}`);
     }
     return photoOutput;
   }
   ```

3. 设置拍照photoAvailable的回调，并将拍照的buffer保存为图片。

    Context获取方式请参考：[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

    如需要在图库中看到所保存的图片、视频资源，需要将其保存到媒体库，保存方式请参考：[保存媒体库资源](../medialibrary/photoAccessHelper-savebutton.md)。

    需要在[photoOutput.on('photoAvailable')](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#onphotoavailable11)接口获取到buffer时，将buffer在安全控件中保存到媒体库。
   ```ts
   function setPhotoOutputCb(photoOutput: camera.PhotoOutput, context: Context) {
   //设置回调之后，调用photoOutput的capture方法，就会将拍照的buffer回传到回调中。
     photoOutput.on('photoAvailable', (errCode: BusinessError, photo: camera.Photo): void => {
        console.info('getPhoto start');
        console.error(`err: ${errCode}`);
        if (errCode || photo === undefined) {
          console.error('getPhoto failed');
          return;
        }
        let imageObj: image.Image = photo.main;
        imageObj.getComponent(image.ComponentType.JPEG, (errCode: BusinessError, component: image.Component): void => {
          console.info('getComponent start');
          if (errCode || component === undefined) {
            console.error('getComponent failed');
            return;
          }
          let buffer: ArrayBuffer;
          if (component.byteBuffer) {
            buffer = component.byteBuffer;
          } else {
            console.error('byteBuffer is null');
            return;
          }
          // 如需要在图库中看到所保存的图片、视频资源，请使用用户无感的安全控件创建媒体资源。

          // buffer处理结束后需要释放该资源，如果未正确释放资源会导致后续拍照获取不到buffer。
          imageObj.release(); 
        });
      });
   }
   ```

4. 参数配置。

   配置相机的参数可以调整拍照的一些功能，包括闪光灯、变焦、焦距等。

   ```ts
   function configuringSession(photoSession: camera.PhotoSession): void {
     // 判断设备是否支持闪光灯。
     let flashStatus: boolean = false;
     try {
       flashStatus = photoSession.hasFlash();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to hasFlash. error: ${err}`);
     }
     console.info(`Returned with the flash light support status: ${flashStatus}`);
     if (flashStatus) {
       // 判断是否支持自动闪光灯模式。
       let flashModeStatus: boolean = false;
       try {
         let status: boolean = photoSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
         flashModeStatus = status;
       } catch (error) {
         let err = error as BusinessError;
         console.error(`Failed to check whether the flash mode is supported. error: ${err}`);
       }
       if (flashModeStatus) {
         // 设置自动闪光灯模式。
         try {
           photoSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);
         } catch (error) {
           let err = error as BusinessError;
           console.error(`Failed to set the flash mode. error: ${err}`);
         }
       }
     }
     // 判断是否支持连续自动变焦模式。
     let focusModeStatus: boolean = false;
     try {
       let status: boolean = photoSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
       focusModeStatus = status;
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to check whether the focus mode is supported. error: ${err}`);
     }
     if (focusModeStatus) {
       // 设置连续自动变焦模式。
       try {
         photoSession.setFocusMode(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
       } catch (error) {
         let err = error as BusinessError;
         console.error(`Failed to set the focus mode. error: ${err}`);
       }
     }
     // 获取相机支持的可变焦距比范围。
     let zoomRatioRange: Array<number> = [];
     try {
       zoomRatioRange = photoSession.getZoomRatioRange();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to get the zoom ratio range. error: ${err}`);
     }
     if (zoomRatioRange.length <= 0 ) {
       return;
     }
     // 设置可变焦距比。
     try {
       photoSession.setZoomRatio(zoomRatioRange[0]);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to set the zoom ratio value. error: ${err}`);
     }
   }
   ```

5. 触发拍照。

   通过photoOutput类的[capture](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#capture-2)方法，执行拍照任务。该方法有两个参数，第一个参数为拍照设置参数的setting，setting中可以设置照片的质量和旋转角度，第二参数为回调函数。

   获取拍照旋转角度的方法为，通过[PhotoOutput](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md)类中的[getPhotoRotation](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#getphotorotation12)方法获取rotation实际的值。

   ```ts
   function capture(captureLocation: camera.Location, photoOutput: camera.PhotoOutput): void {
     let settings: camera.PhotoCaptureSetting = {
       quality: camera.QualityLevel.QUALITY_LEVEL_HIGH,  // 设置图片质量高。
       rotation: camera.ImageRotation.ROTATION_0,  // 设置图片旋转角度的camera.ImageRotation.ROTATION_0是通过说明中获取拍照角度的getPhotoRotation方法获取的值进行设置。
       location: captureLocation,  // 设置图片地理位置。
       mirror: false  // 设置镜像使能开关(默认关)。
     };
     photoOutput.capture(settings, (err: BusinessError) => {
       if (err) {
         console.error(`Failed to capture the photo. error: ${err}`);
         return;
       }
       console.info('Callback invoked to indicate the photo capture request success.');
     });
   }
   ```

## 状态监听

在相机应用开发过程中，可以随时监听拍照输出流状态，包括拍照流开始、拍照帧的开始与结束、拍照输出流的错误。

- 通过注册固定的captureStart回调函数获取监听拍照开始结果，photoOutput创建成功时即可监听，相机设备已经准备开始这次拍照时触发，该事件返回此次拍照的captureId。

  ```ts
  function onPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureStartWithInfo', (err: BusinessError, captureStartInfo: camera.CaptureStartInfo) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info(`photo capture started, captureId : ${captureStartInfo.captureId}`);
    });
  }
  ```

- 通过注册固定的captureEnd回调函数获取监听拍照结束结果，photoOutput创建成功时即可监听，该事件返回结果为拍照完全结束后的相关信息[CaptureEndInfo](../../reference/apis-camera-kit/arkts-apis-camera-i.md#captureendinfo)。

  ```ts
  function onPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureEnd', (err: BusinessError, captureEndInfo: camera.CaptureEndInfo) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info(`photo capture end, captureId : ${captureEndInfo.captureId}`);
      console.info(`frameCount : ${captureEndInfo.frameCount}`);
    });
  }
  ```

- 通过注册固定的captureReady回调函数获取监听可拍下一张结果，photoOutput创建成功时即可监听，当下一张可拍时触发，该事件返回结果为下一张可拍的相关信息。

  ```ts
  function onPhotoOutputCaptureReady(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureReady', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info(`photo capture ready`);
    });
  }
  ```

- 通过注册固定的error回调函数获取监听拍照输出流的错误结果。回调返回拍照输出接口使用错误时的对应错误码，错误码类型参见[Camera错误码](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode)。

  ```ts
  function onPhotoOutputError(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('error', (error: BusinessError) => {
      console.error(`Photo output error code: ${error.code}`);
    });
  }
  ```
