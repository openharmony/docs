# 拍照(ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## 概述

拍照是相机的重要功能之一，拍照模块基于相机复杂的逻辑，为了保证用户拍出的照片质量，在中间步骤可以设置分辨率、闪光灯、焦距、照片质量及旋转角度等信息。 

目前相机开发有两种相机拍照方案，分别是相机[分段式拍照](./camera-deferred-capture.md)和相机单段式拍照（**本文将以单段式拍照为基础进行说明**）。 

- 分段式拍照是指相机拍照既可以输出低质量图用作缩略图，提升用户感知拍照速度，也可以使用高质量图保证最后的成图质量达到系统相机的水平。满足了图像处理算法的需求的同时，又不会阻塞前台的拍照速度，构筑相机性能竞争力，提升用户体验。 
- 单段式拍照是指在拍照过程中通过多帧融合以及多个底层算法处理之后返回一张高质量图片，所以Shot2See（用户点击拍照控件到在缩略图显示区域显示缩略图的过程）完成时延较长。此外，单段式拍照支持通过[高性能拍照](#高性能拍照)功能调整[画质优先策略](#画质优先策略)，以加快出图速度或提升图片质量。 
 

## 开发步骤

详细的API说明请参考[@ohos.multimedia.camera (相机管理)](../../reference/apis-camera-kit/arkts-apis-camera.md)。

1. 导入[Image](../../reference/apis-image-kit/arkts-apis-image-Image.md)接口。获取拍照输出的数据需要用到系统提供的Image接口能力，导入Image接口的方法如下。

   ```ts
   import { image } from '@kit.ImageKit';
   import { camera } from '@kit.CameraKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 创建拍照输出流。

   通过[CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability)中的photoProfiles属性，可获取当前设备支持的拍照输出流。通过[createPhotoOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createphotooutput11)方法传入支持的某一个输出流[Profile](../../reference/apis-camera-kit/arkts-apis-camera-i.md#profile)创建拍照输出流。

   <!-- @[camera_getPhotoOutput](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->
   
   ``` TypeScript
   getPhotoOutput(cameraManager: camera.CameraManager,
     cameraOutputCapability: camera.CameraOutputCapability): camera.PhotoOutput | undefined {
     let photoProfilesArray: camera.Profile[] = cameraOutputCapability.photoProfiles;
     if (!photoProfilesArray || photoProfilesArray.length === 0) {
       console.error('photoProfilesArray is null or []');
     }
     let photoOutput: camera.PhotoOutput | undefined = undefined;
     try {
       this.photoProfileObj = photoProfilesArray[0]
       photoOutput = cameraManager.createPhotoOutput(photoProfilesArray[0]);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to createPhotoOutput. error: ${err}`);
     }
     return photoOutput;
   }
   ```

3. 设置拍照[on('photoAvailable')](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#onphotoavailable11)的回调，并将拍照的buffer保存为图片。

   Context获取方式请参考：[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

   如需要在图库中看到所保存的图片、视频资源，需要将其保存到媒体库，保存方式请参考：[保存媒体库资源](../medialibrary/photoAccessHelper-savebutton.md)。

   需要在[photoOutput.on('photoAvailable')](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#onphotoavailable11)接口获取到buffer时，将buffer在安全控件中保存到媒体库。

   <!-- @[camera_photoAvailable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->
   
   ``` TypeScript
   setPhotoOutputCb(photoOutput: camera.PhotoOutput, context: Context) {
     // 设置回调之后，调用photoOutput的capture方法，就会将拍照的buffer回传到回调中。
     photoOutput.on('photoAvailable', (errCode: BusinessError, photo: camera.Photo): void => {
       console.info('getPhoto start');
       if (errCode || photo === undefined) {
         console.error('getPhoto failed, err: ${errCode}');
         return;
       }
         // 如需要在图库中看到所保存的图片、视频资源，请使用用户无感的安全控件创建媒体资源。
         this.mediaLibSavePhotoSingle(context, photo.main)
     });
   }
   
   mediaLibSavePhotoSingle(context: Context, imageObj: image.Image) {
     imageObj.getComponent(image.ComponentType.JPEG, async (errCode: BusinessError, component: image.Component) => {
       if (errCode || component === undefined) {
         Logger.error('getComponent failed');
         return;
       }
       const buffer: ArrayBuffer = component.byteBuffer;
       if (!buffer) {
         Logger.error('byteBuffer is null');
         return;
       }
       let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
       let extension: string = 'jpg';
       let options: photoAccessHelper.CreateOptions = {
         title: 'testPhoto'
       }
       let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest =
         photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context, photoType, extension, options);
       assetChangeRequest.addResource(photoAccessHelper.ResourceType.IMAGE_RESOURCE, buffer)
       assetChangeRequest.saveCameraPhoto();
       let accessHelper: photoAccessHelper.PhotoAccessHelper =
         photoAccessHelper.getPhotoAccessHelper(context);
       await accessHelper.applyChanges(assetChangeRequest);
       let imageSource = image.createImageSource(buffer);
       let pixelmap = imageSource.createPixelMapSync();
       this.callback(pixelmap, assetChangeRequest.getAsset().uri);
       accessHelper.release();
       // buffer处理结束后需要释放该资源，如果未正确释放资源会导致后续拍照获取不到buffer。
       imageObj.release();
     });
   }
   ```

4. 参数配置。

   配置相机的参数可以调整拍照的一些功能，包括闪光灯、变焦、焦距等。


   <!-- @[camera_param_config](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->    
   ``` TypeScript
   configuringSession(photoSession: camera.PhotoSession | camera.VideoSession): void {
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
       // 判断是否支持关闭闪光灯模式。
       let flashModeStatus: boolean = false;
       try {
         flashModeStatus = photoSession?.isFlashModeSupported(camera.FlashMode.FLASH_MODE_CLOSE);
       } catch (error) {
         let err = error as BusinessError;
         console.error(`Failed to check whether the flash mode is supported. error: ${err}`);
       }
       if (flashModeStatus) {
         // 设置闪光灯模式关闭。
         try {
           photoSession?.setFlashMode(camera.FlashMode.FLASH_MODE_CLOSE);
         } catch (error) {
           let err = error as BusinessError;
           console.error(`Failed to set the flash mode. error: ${err}`);
         }
       }
     }
     // 判断是否支持连续自动变焦模式。
     let focusModeStatus: boolean = false;
     try {
       focusModeStatus = photoSession?.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to check whether the focus mode is supported. error: ${err}`);
     }
     if (focusModeStatus) {
       // 设置连续自动变焦模式。
       try {
         photoSession?.setFocusMode(camera.FocusMode.FOCUS_MODE_CONTINUOUS_AUTO);
       } catch (error) {
         let err = error as BusinessError;
         console.error(`Failed to set the focus mode. error: ${err}`);
       }
     }
     // 获取相机支持的可变焦距比范围。
     let zoomRatioRange: number[] = [];
     try {
       zoomRatioRange = photoSession?.getZoomRatioRange();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to get the zoom ratio range. error: ${err}`);
     }
     if (zoomRatioRange.length <= 0 ) {
       return;
     }
     // 设置可变焦距比。
     try {
       photoSession?.setZoomRatio(zoomRatioRange[0]);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to set the zoom ratio value. error: ${err}`);
     }
   }
   ```

5. 触发拍照。

   通过photoOutput的[capture](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#capture-2)方法，执行拍照任务。该方法有两个参数，第一个参数为拍照设置参数的setting，setting中可以设置照片的质量和旋转角度，第二参数为回调函数。

   获取拍照旋转角度的方法为，通过[PhotoOutput](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md)中的[getPhotoRotation](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#getphotorotation12)方法获取rotation实际的值。

   > **说明：**
   >
   > 图片地理位置信息[Location](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation)，使用方法可参考[capture](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#capture-3)示例。


   <!-- @[camera_capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->
   
   ``` TypeScript
   capture(captureLocation?: camera.Location): void {
     let captureLocationDefault: camera.Location = {
       latitude: 0,
       longitude: 0,
       altitude: 0
     };
     if (captureLocation != undefined) {
       captureLocationDefault = captureLocation;
     }
     let settings: camera.PhotoCaptureSetting = {
       quality: camera.QualityLevel.QUALITY_LEVEL_HIGH,  // 设置图片质量高。
       // 设置图片旋转角度的camera.ImageRotation.ROTATION_0是通过说明中获取拍照角度的getPhotoRotation方法获取的值进行设置。
       rotation: camera.ImageRotation.ROTATION_0,
       location: captureLocation,  // 设置图片地理位置。
       mirror: false  // 设置镜像使能开关(默认关)。
     };
     try {
       if (this.photoOutput == undefined) {
         console.info(`photoOutput is undefined.`);
         return;
       }
       this.photoOutput.capture(settings, (err: BusinessError) => {
         if (err) {
           console.error(`Failed to capture the photo. error: ${err}`);
           return;
         }
         console.info('Callback invoked to indicate the photo capture request success.');
       });
     } catch (error) {
       console.error(`capture call failed. error: ${error}`);
     }
   }
   ```
## 高性能拍照

从API version 21开始支持高性能拍照功能，即在进行单段式拍照时设置明确的[画质优先策略](#画质优先策略)。

单段式拍照的体验主要由出图速度和最终图片质量衡量。因此，为满足开发者在不同场景下的差异化需求，对这两项指标的侧重也不同。例如，街头抓拍要求快速捕捉瞬间，而风景或人像拍摄则更追求极致的画质。

> **注意：**
>
> 仅单段式拍照支持设置画质优先策略。若在分段式拍照中设置画质优先策略，该设置将无效。 


### 画质优先策略

在使用单段式拍照时，支持设置速度优先和画质优先两种画质优先策略类型，并且分别对应着不同的[PhotoQualityPrioritization](../../reference/apis-camera-kit/arkts-apis-camera-e.md#photoqualityprioritization21)枚举类型。 

- [SPEED](../../reference/apis-camera-kit/arkts-apis-camera-e.md#photoqualityprioritization21)对应着速度优先，表示降低画质来提升拍照的速度。如果开发者在进行单段式拍照时没有设置明确的画质优先策略，**单段式拍照就默认为速度优先状态**。 
- [HIGH_QUALITY](../../reference/apis-camera-kit/arkts-apis-camera-e.md#photoqualityprioritization21)对应着画质优先，表示通过较长的耗时来得到画质更高的图片。 

### 如何正确设置画质优先策略

为了正确地在单段式拍照中设置画质优先策略，高性能拍照功能提供了如下两个接口：

- [isPhotoQualityPrioritizationSupported](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#isphotoqualityprioritizationsupported21)：查询当前设备是否支持指定的画质优先策略。返回true表示支持，返回false表示不支持。在进行设置画质优先策略之前，必须先查询将要设置的画质优先策略在当前设备上是否可用。 
- [setPhotoQualityPrioritization](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#setphotoqualityprioritization21)：画质优先策略设置接口，通过该接口设置对应的画质优先策略，实现高性能拍照。

### 开发步骤

高性能拍照相关接口需要在[会话管理(ArkTS)](camera-session-management.md)流程的使能步骤中进行调用。  

具体调用时机如下：  

- 在[会话管理(ArkTS)](camera-session-management.md)流程的使能步骤中的[commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11)结束之后进行调用。 

  ```ts
  async function startSession(photoSession: camera.PhotoSession, cameraInput: camera.CameraInput, previewOutput: camera.PreviewOutput, photoOutput: camera.PhotoOutput): Promise<void> {
    try {
      photoSession.addInput(cameraInput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to addInput. error: ${err.code}`);
    }
    let canAddPreviewOutput : boolean = false;
    try {
      canAddPreviewOutput = photoSession.canAddOutput(previewOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add previewOutput. error: ${err.code}`);
    } 
    if (!canAddPreviewOutput) {
      console.error(`Failed to add preview output.`);
      return;
    }
    try {
      photoSession.addOutput(previewOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add previewOutput. error: ${err.code}`);
    }
    let canAddPhotoOutput : boolean = false
    try {
      canAddPhotoOutput = photoSession.canAddOutput(photoOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add photoOutput error: ${err.code}`);
    }
    if (!canAddPhotoOutput) {
      console.error(`Failed to add photo output.`);
      return;
    }
    try {
      photoSession.addOutput(photoOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add photoOutput. error: ${err.code}`);
    }
    try {
      await photoSession.commitConfig();
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to commitConfig. error: ${err.code}`);
      return;
    }
   
    try {
      await photoSession.start();
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to start. error: ${err.code}`);
    }
    modeSwitchToHigh(photoSession, photoOutput);
  }

  async function modeSwitchToHigh(photoSession: camera.PhotoSession, photoOutput: camera.PhotoOutput): Promise<void> {
    try {
      if (photoSession) {
        let quality: camera.PhotoQualityPrioritization = camera.PhotoQualityPrioritization.HIGH_QUALITY;
        let isSupported = false;
        isSupported = photoOutput.isPhotoQualityPrioritizationSupported(quality);
        if (isSupported) {
          photoOutput.setPhotoQualityPrioritization(quality);
        } else {
          console.error(`session is not supported`);
        }
      } else {
        console.error(`session is null`);
      }
    } catch {
      console.error(`catch error`);
    }
  }
  ```

- 在[会话管理(ArkTS)](camera-session-management.md)流程的使能步骤中的[commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11)之前调用。 

  ```ts
  async function startSession(photoSession: camera.PhotoSession, cameraInput: camera.CameraInput, previewOutput: camera.PreviewOutput, photoOutput: camera.PhotoOutput): Promise<void> {
    try {
      photoSession.addInput(cameraInput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to addInput. error: ${err.code}`);
    }
    let canAddPreviewOutput : boolean = false;
    try {
      canAddPreviewOutput = photoSession.canAddOutput(previewOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add previewOutput. error: ${err.code}`);
    } 
    if (!canAddPreviewOutput) {
      console.error(`Failed to add preview output.`);
      return;
    }
    try {
      photoSession.addOutput(previewOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add previewOutput. error: ${err.code}`);
    }
    let canAddPhotoOutput : boolean = false
    try {
      canAddPhotoOutput = photoSession.canAddOutput(photoOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add photoOutput error: ${err.code}`);
    }
    if (!canAddPhotoOutput) {
      console.error(`Failed to add photo output.`);
      return;
    }
    try {
      photoSession.addOutput(photoOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to add photoOutput. error: ${err.code}`);
    }
    modeSwitchToHigh(photoSession, photoOutput);
    try {
      await photoSession.commitConfig();
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to commitConfig. error: ${err.code}`);
      return;
    }
   
    try {
      await photoSession.start();
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to start. error: ${err.code}`);
    }
  }

  async function modeSwitchToHigh(photoSession: camera.PhotoSession, photoOutput: camera.PhotoOutput): Promise<void> {
    try {
      if (photoSession) {
        let quality: camera.PhotoQualityPrioritization = camera.PhotoQualityPrioritization.HIGH_QUALITY;
        let isSupported = false;
        isSupported = photoOutput.isPhotoQualityPrioritizationSupported(quality);
        if (isSupported) {
          photoOutput.setPhotoQualityPrioritization(quality);
        } else {
          console.error(`session is not supported`);
        }
      } else {
        console.error(`session is null`);
      }
    } catch {
      console.error(`catch error`);
    }
  }
  ```

## 状态监听

在相机应用开发过程中，可以随时监听拍照输出流状态，包括拍照流开始、拍照帧的开始与结束、拍照输出流的错误。

- 通过注册固定的captureStart回调函数获取监听拍照开始结果，photoOutput创建成功时即可监听，相机设备已经准备开始这次拍照时触发，该事件返回此次拍照的captureId。

  <!-- @[capture_start_with_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->
  
  ``` TypeScript
  // 监听拍照开始
  photoOutput.on('captureStartWithInfo', (err: BusinessError, captureStartInfo: camera.CaptureStartInfo): void => {
    Logger.info(TAG, `photoOutputCallBack captureStartWithInfo success: ${JSON.stringify(captureStartInfo)}`);
  });
  ```

- 通过注册固定的captureEnd回调函数获取监听拍照结束结果，photoOutput创建成功时即可监听，该事件返回结果为拍照完全结束后的相关信息[CaptureEndInfo](../../reference/apis-camera-kit/arkts-apis-camera-i.md#captureendinfo)。


  <!-- @[capture_end](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->
  
  ``` TypeScript
  // 监听拍照结束
  photoOutput.on('captureEnd', (err: BusinessError, captureEndInfo: camera.CaptureEndInfo): void => {
    Logger.info(TAG, `photoOutputCallBack captureEnd captureId:
      ${captureEndInfo.captureId}, frameCount: ${captureEndInfo.frameCount}`);
  });
  ```

- 通过注册固定的captureReady回调函数获取监听可拍下一张结果，photoOutput创建成功时即可监听，当下一张可拍时触发，该事件返回结果为下一张可拍的相关信息。

  <!-- @[capture_ready](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->
  
  ``` TypeScript
  photoOutput.on('captureReady', (err: BusinessError) => {
    if (err !== undefined && err.code !== 0) {
      return;
    }
    console.info(`photo capture ready`);
  });
  ```

- 通过注册固定的error回调函数获取监听拍照输出流的错误结果。回调返回拍照输出接口使用错误时的对应错误码，错误码类型参见[CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode)。

  <!-- @[photoOutput_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->
  
  ``` TypeScript
  // 监听拍照异常
  photoOutput.on('error', (data: BusinessError): void => {
    Logger.info(TAG, `photoOutput data: ${JSON.stringify(data)}`);
  });
  ```
