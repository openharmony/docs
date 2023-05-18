# 拍照

拍照是相机的最重要功能之一，拍照模块基于相机复杂的逻辑，为了保证用户拍出的照片质量，在中间步骤可以设置分辨率、闪光灯、焦距、照片质量及旋转角度等信息。

## 开发步骤

详细的API说明请参考[Camera API参考](../reference/apis/js-apis-camera.md)。

1. 导入image接口。创建拍照输出流的SurfaceId以及拍照输出的数据，都需要用到系统提供的image接口能力，导入image接口的方法如下。
     
   ```ts
   import image from '@ohos.multimedia.image';
   ```

2. 获取SurfaceId。
   
   通过image的createImageReceiver方法创建ImageReceiver实例，再通过实例的getReceivingSurfaceId方法获取SurfaceId，与拍照输出流相关联，获取拍照输出流的数据。
 
   ```ts
   function getImageReceiverSurfaceId() {
       let receiver = image.createImageReceiver(640, 480, 4, 8);
       console.info('before ImageReceiver check');
       if (receiver !== undefined) {
         console.info('ImageReceiver is ok');
         let photoSurfaceId = receiver.getReceivingSurfaceId();
         console.info('ImageReceived id: ' + JSON.stringify(photoSurfaceId));
       } else {
         console.info('ImageReceiver is not ok');
       }
   }
   ```

3. 创建拍照输出流。
   
   通过CameraOutputCapability类中的photoProfiles()方法，可获取当前设备支持的拍照输出流，通过createPhotoOutput()方法传入支持的某一个输出流及步骤一获取的SurfaceId创建拍照输出流。

   ```ts
   let photoProfilesArray = cameraOutputCapability.photoProfiles;
   if (!photoProfilesArray) {
       console.error("createOutput photoProfilesArray == null || undefined");
   }
   let photoOutput;
   try {
       photoOutput = cameraManager.createPhotoOutput(photoProfilesArray[0], photoSurfaceId);
   } catch (error) {
      console.error('Failed to createPhotoOutput errorCode = ' + error.code);
   }
   ```

4. 参数配置。
   
   配置相机的参数可以调整拍照的一些功能，包括闪光灯、变焦、焦距等。
 
   ```ts
   // 判断设备是否支持闪光灯
   let flashStatus;
   try {
       flashStatus = captureSession.hasFlash();
   } catch (error) {
       console.error('Failed to hasFlash. errorCode = ' + error.code);
   }
   console.info('Promise returned with the flash light support status:' + flashStatus); 
   if (flashStatus) {
       // 判断是否支持自动闪光灯模式
       let flashModeStatus;
       try {
           let status = captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
           flashModeStatus = status;    
       } catch (error) {
           console.error('Failed to check whether the flash mode is supported. errorCode = ' + error.code);
       }    
       if(flashModeStatus) {
           // 设置自动闪光灯模式
           try {
               captureSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);
           } catch (error) {
               console.error('Failed to set the flash mode. errorCode = ' + error.code);
           }
       }
   } 
   // 判断是否支持连续自动变焦模式
   let focusModeStatus;
   try {
       let status = captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
       focusModeStatus = status;
   } catch (error) {
       console.error('Failed to check whether the focus mode is supported. errorCode = ' + error.code);
   } 
   if (focusModeStatus) {
       // 设置连续自动变焦模式
       try {
           captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
       } catch (error) { 
          console.error('Failed to set the focus mode. errorCode = ' + error.code);
       }
   } 
   // 获取相机支持的可变焦距比范围
   let zoomRatioRange;
   try {
       zoomRatioRange = captureSession.getZoomRatioRange();
   } catch (error) {
       console.error('Failed to get the zoom ratio range. errorCode = ' + error.code);
   } 
   // 设置可变焦距比
   try {
       captureSession.setZoomRatio(zoomRatioRange[0]);
   } catch (error) {
       console.error('Failed to set the zoom ratio value. errorCode = ' + error.code);
   }
   ```

5. 触发拍照。
   
   通过photoOutput类的capture()方法，执行拍照任务。该方法有两个参数，第一个参数为拍照设置参数的setting，setting中可以设置照片的质量和旋转角度，第二参数为回调函数。
 
   ```ts
   let settings = {
       quality: camera.QualityLevel.QUALITY_LEVEL_HIGH,                                     // 设置图片质量高
       rotation: camera.ImageRotation.ROTATION_0,                                           // 设置图片旋转角度0
       location: captureLocation,                                                           // 设置图片地理位置
       mirror: false                                                                        // 设置镜像使能开关(默认关)
   };
   photoOutput.capture(settings, async (err) => {
       if (err) {
           console.error('Failed to capture the photo ${err.message}');
           return;
       }
       console.info('Callback invoked to indicate the photo capture request success.');
   });
   ```

## 状态监听

在相机应用开发过程中，可以随时监听拍照输出流状态，包括拍照流开始、拍照帧的开始与结束、拍照输出流的错误。

- 通过注册固定的captureStart回调函数获取监听拍照开始结果，photoOutput创建成功时即可监听，拍照第一次曝光时触发，该事件返回此次拍照的captureId。
    
  ```ts
  photoOutput.on('captureStart', (captureId) => {
      console.info(`photo capture stated, captureId : ${captureId}`);
  })
  ```

- 通过注册固定的captureEnd回调函数获取监听拍照结束结果，photoOutput创建成功时即可监听，该事件返回结果为拍照完全结束后的相关信息[CaptureEndInfo](../reference/apis/js-apis-camera.md#captureendinfo)。
    
  ```ts
  photoOutput.on('captureEnd', (captureEndInfo) => {
      console.info(`photo capture end, captureId : ${captureEndInfo.captureId}`);
      console.info(`frameCount : ${captureEndInfo.frameCount}`);
  })
  ```

- 通过注册固定的error回调函数获取监听拍照输出流的错误结果。callback返回拍照输出接口使用错误时的对应错误码，错误码类型参见[CameraErrorCode](../reference/apis/js-apis-camera.md#cameraerrorcode)。
    
  ```ts
  photoOutput.on('error', (error) => {
      console.info(`Photo output error code: ${error.code}`);
  })
  ```
