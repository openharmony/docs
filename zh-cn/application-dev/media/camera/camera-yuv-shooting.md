# YUV拍照(ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

从API version 23开始，相机框架提供YUV格式图片拍照能力。与普通拍照相比，YUV拍照获取到的是未经过编码的图像数据，完整保留了传感器捕获的原始亮度和色度信息，适用于视频编码或专业处理。同时，拍摄过程会产生更高的能耗开销，保存会占用更多的存储空间。

## 开发步骤

详细的相机功能API说明请参考Camera模块描述[Camera](../../reference/apis-camera-kit/arkts-apis-camera.md)。

1. 导入依赖模块。

   获取拍照输出的数据需要用到系统提供的image、dataSharePredicates、photoAccessHelper接口能力，方法如下。

   <!-- @[import_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->
   
   ``` TypeScript
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   import { dataSharePredicates } from '@kit.ArkData';
   import { image } from '@kit.ImageKit';
   import { fileIo } from '@kit.CoreFileKit';
   ```

2. 获取相机设备完整输出能力。

   通过[getSupportedFullOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedfulloutputcapability23)方法，获取当前相机设备支持的所有输出流的能力，包含预览流、拍照流、录像流等。输出流在[CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability)中的各个profile字段中，其中拍照流支持YUV格式。

   <!-- @[get_full_outputCapability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->
   
   ``` TypeScript
     getFullOutputCapability(cameraManager: camera.CameraManager, cameraDevice: camera.CameraDevice,
       sceneMode: camera.SceneMode): camera.CameraOutputCapability | undefined {
       let cameraOutputCapability = cameraManager.getSupportedFullOutputCapability(cameraDevice, sceneMode);
       if (!cameraOutputCapability) {
         console.error('cameraManager.getSupportedFullOutputCapability error');
         return undefined;
       }
       // ...
       return cameraOutputCapability;
   }
   ```

3. 创建拍照输出流。

   通过[CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability)中的photoProfiles属性，可获取当前设备支持的拍照输出流。

   通过[createPhotoOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createphotooutput11)方法传入支持的某一个输出流[Profile](../../reference/apis-camera-kit/arkts-apis-camera-i.md#profile)，创建拍照输出流。

   通过[getSupportedFullOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedfulloutputcapability23)获取相机支持的完整输出能力cameraOutputCapability，参考步骤2。在cameraOutputCapability的photoProfiles中选择支持YUV格式的Profile，作为创建拍照输出流的参数photoProfile。

   ```ts
   function getPhotoOutput(cameraManager: camera.CameraManager, photoProfile: camera.Profile): camera.PhotoOutput | undefined {
     // 创建拍照输出流。
     let photoOutput: camera.PhotoOutput | undefined = undefined;
     try {
       photoOutput = cameraManager.createPhotoOutput(photoProfile);
     } catch (error) {
       let err = error as BusinessError;
       console.error("Failed to createPhotoOutput. error: ${err}");
     }
     return photoOutput;
   }
   ```

4. 设置拍照输出流的回调。

   设置单段式拍照[onCapturePhotoAvailable](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#oncapturephotoavailable23)或分段式拍照[on('photoAssetAvailable')](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#onphotoassetavailable12)的回调，并将拍照的pixelMap数据保存为图片。如果应用需要快速得到返回的图像，推荐使用分段式拍照回调。

   Context获取方式请参考：[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

   如果需要在图库中看到所保存的图片、视频资源，需要先将其保存到媒体库，保存方式请参考：[保存媒体库资源](../medialibrary/photoAccessHelper-savebutton.md)。

   如果需要在[onCapturePhotoAvailable](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#oncapturephotoavailable23)接口获取到buffer，先将[PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md)数据在安全控件中保存到媒体库。

   - **单段式拍照（onCapturePhotoAvailable）开发流程**：

     - 在会话[commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11-1)前注册单段式拍照回调。
     - 在单段式拍照回调函数中获取图片信息，解析出pixelMap数据，做自定义业务处理。
     - 将处理完的pixelMap通过回调回传，做图片显示或通过安全控件写文件保存图片。
     - 使用完后解注册单段式拍照回调函数。

     <!-- @[set_photo_cb_single](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->
     
     ``` TypeScript
     setPhotoOutputCbSingle(photoOutput: camera.PhotoOutput, context: Context) {
       // 设置回调之后，调用photoOutput的capture方法，就会将拍照的pixelMap回传到回调中。
       photoOutput.onCapturePhotoAvailable((capturePhoto: camera.CapturePhoto): void => {
         if (capturePhoto === undefined) {
           Logger.error(TAG_LOG, 'getPhoto failed');
           return;
         }
     
         Logger.info(TAG_LOG, 'photoAvailable success');
         this.mediaLibSavePhotoSingle(context, capturePhoto.main)
       });
     }
     
     async mediaLibSavePhotoSingle(context: Context, imageObj: image.Image | image.Picture) {
       let picture: image.Picture = imageObj as image.Picture;
       Logger.info(TAG_LOG, 'picture GetMainPixelmap E');
       await this.GetMainPixelmap(context, picture);
       Logger.info(TAG_LOG, 'picture GetMainPixelmap X');
     
       Logger.info(TAG_LOG, 'picture Release E');
       await this.Release(picture);
       Logger.info(TAG_LOG, 'picture Release X');
     }
     
     async packToFileFromPixelMap(context : Context, pixelMap : image.PixelMap) {
       const imagePackerApi = image.createImagePacker();
       let packOpts : image.PackingOption = { format: 'image/jpeg', quality: 95 };
       const path : string = context.cacheDir + '/pixel_map.jpg';
       let file = fileIo.openSync(path, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
       try {
         await imagePackerApi.packToFile(pixelMap, file.fd, packOpts);
         this.srcFileUri = file.path;
       } catch (error) {
         Logger.error(TAG_LOG, `Failed to pack the pixelMap to file. And the errorcode: ${error.code} ,error.message: ${error.message}`);
       }
     }
     
     async saveFile(srcFileUri: string, phAccessHelper: photoAccessHelper.PhotoAccessHelper){
       try {
         // 指定待保存到媒体库的位于应用沙箱的图片uri。
         let srcFileUris: string[] = [
           srcFileUri
         ];
         // 指定待保存照片的创建选项，包括文件后缀和照片类型，标题和照片子类型可选。
         let photoCreationConfigs: photoAccessHelper.PhotoCreationConfig[] = [
           {
             title: 'test', // 可选。
             fileNameExtension: 'jpg',
             photoType: photoAccessHelper.PhotoType.IMAGE,
             subtype: photoAccessHelper.PhotoSubtype.DEFAULT, // 可选。
           }
         ];
         // 基于弹窗授权的方式获取媒体库的目标uri。
         let desFileUris: string[] = await phAccessHelper.showAssetsCreationDialog(srcFileUris, photoCreationConfigs);
         // 将来源于应用沙箱的照片内容写入媒体库的目标uri。
         let desFile: fileIo.File = await fileIo.open(desFileUris[0], fileIo.OpenMode.WRITE_ONLY);
         let srcFile: fileIo.File = await fileIo.open(srcFileUri, fileIo.OpenMode.READ_ONLY);
         await fileIo.copyFile(srcFile.fd, desFile.fd);
         fileIo.closeSync(srcFile);
         fileIo.closeSync(desFile);
         console.info('create asset by dialog successfully');
       } catch (err) {
         console.error(`failed to create asset by dialog successfully errCode is: ${err.code}, ${err.message}`);
       }
     }
     
     // 获取拍照的主图的pixelMap。
     async GetMainPixelmap(context: Context, pictureObj : image.Picture) {
       let funcName = 'getMainPixelmap';
       if (pictureObj != null) {
         let mainPixelmap: image.PixelMap = pictureObj.getMainPixelmap();
         if (mainPixelmap != null) {
           // 编码。
           await this.packToFileFromPixelMap(context, mainPixelmap);
           // 保存。
           let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
           this.saveFile(this.srcFileUri, phAccessHelper);
     
           this.callback(mainPixelmap, '');
           mainPixelmap.getImageInfo().then((imageInfo: image.ImageInfo) => {
             if (imageInfo != null) {
               Logger.info(TAG_LOG, 'GetMainPixelmap information height:' + imageInfo.size.height + ' width:' + imageInfo.size.width +
                 ' pixelFormat:' + imageInfo.pixelFormat + ' isHdr:' + imageInfo.isHdr);
             }
           }).catch((error: BusinessError) => {
             Logger.error(TAG_LOG, `Failed error.code: ${error.code} ,error.message: ${error.message}`);
           });
         } else {
           Logger.error(TAG_LOG, 'PictureObj getMainPixelmap is null');
         }
       } else {
         Logger.error(TAG_LOG, 'PictureObj is null');
       }
     }
     
     // 释放资源。
     async Release(pictureObj : image.Picture) {
       let funcName = 'Release';
       if (pictureObj != null) {
         pictureObj.release();
         if (pictureObj.getMainPixelmap() == null) {
           Logger.info(TAG_LOG, 'PictureObj release Success !');
         } else {
           Logger.error(TAG_LOG, 'PictureObj release Failed !');
         }
       } else {
         Logger.error(TAG_LOG, 'PictureObj is null');
       }
     }
     ```

   - **分段式拍照（PhotoAvailable）开发流程**：

     - 在会话[commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11-1)前注册分段式拍照回调。
     - 在分段式拍照回调函数中获取图片信息，解析出pixelMap数据，做自定义业务处理。
     - 将处理完的pixelMap回传，做图片显示或通过安全控件写文件保存图片。
     - 调用[capture](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#capture-2)拍照后，需要及时调用[saveCameraPhoto](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#savecameraphoto12)保存图片或[discardCameraPhoto](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#discardcameraphoto12)取消保存图片，否则会影响后续图片的拍摄。
     - 使用完后解注册分段式拍照回调函数。

     <!-- @[set_photo_cb_double](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->
     
     ``` TypeScript
     // 保存图片。
     async mediaLibSavePhoto(photoAsset: photoAccessHelper.PhotoAsset,
       phAccessHelper: photoAccessHelper.PhotoAccessHelper): Promise<void> {
       try {
         let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest =
           new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
         Logger.info(TAG_LOG, `saveCameraPhoto E`);
         await assetChangeRequest.saveCameraPhoto(photoAccessHelper.ImageFileType.JPEG);
         await phAccessHelper.applyChanges(assetChangeRequest);
         Logger.info(TAG_LOG, `saveCameraPhoto X`);
         await phAccessHelper.release();
       } catch (error) {
         Logger.error(TAG_LOG, `apply saveCameraPhoto failed with error: ${error.code}, ${error.message}`);
       }
     }
     
     async mediaLibRequestBuffer(photoAsset: photoAccessHelper.PhotoAsset, context: Context,
       callback: (pixelMap: image.PixelMap, url: string) => void) {
       // 获取图片pixelmap信息。
       try {
         Logger.info(TAG_LOG, 'quickRequestImage E');
     
         class MediaDataHandler implements photoAccessHelper.QuickImageDataHandler<image.Picture> {
           onDataPrepared(data: image.Picture, imageSource: image.ImageSource, map: Map<string, string>) {
             if (data != undefined) {
               console.info(`On photoAssetAvailable callback data is not undefined`);
               let pixelMap: image.PixelMap = data.getMainPixelmap();
               callback(pixelMap, photoAsset.uri);
             } else if (data === undefined && imageSource != undefined) {
               console.info(`On photoAssetAvailable callback data is undefined, and imageSource is not undefined`);
               imageSource.createPixelMap().then((pixelMap: image.PixelMap) => {
                 callback(pixelMap, photoAsset.uri);
               }).catch((error: BusinessError) => {
                 console.error(`On photoAssetAvailable callback createPixelMap failed, error: ${error.message}`);
               })
             } else {
               console.error(`On photoAssetAvailable callback data and imageSource are both undefined`);
               return;
             }
           }
         }
         // 创建数据共享谓词。
         let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
         // 配置媒体资产检索条件。
         let fetchOptions: photoAccessHelper.FetchOptions = {
           fetchColumns: [],
           predicates: predicates
         };
         // 配置请求策略为平衡模式。
         let requestOptions: photoAccessHelper.RequestOptions = {
           deliveryMode: photoAccessHelper.DeliveryMode.BALANCE_MODE,
         }
     
         const handler = new MediaDataHandler();
         await photoAccessHelper.MediaAssetManager.quickRequestImage(context, photoAsset, requestOptions, handler);
       } catch (error) {
         Logger.error(TAG_LOG, `mediaLibRequestBuffer failed with error: ${error.code}, ${error.message}`);
       }
     }
     
     
     public setPhotoOutputCbDouble(cameraPhotoOutput: camera.PhotoOutput) {
       Logger.info(TAG_LOG, 'setPhotoOutputCbDouble ...');
       cameraPhotoOutput.on('photoAssetAvailable',
         async (_err: BusinessError, photoAsset: photoAccessHelper.PhotoAsset): Promise<void> => {
           try {
             Logger.info(TAG_LOG, `on photoAssetAvailable callback uri:${photoAsset.uri}`);
             let accessHelper: photoAccessHelper.PhotoAccessHelper =
               photoAccessHelper.getPhotoAccessHelper(this.context);
             await this.mediaLibSavePhoto(photoAsset, accessHelper);
             await this.mediaLibRequestBuffer(photoAsset, this.context, this.callback);
           } catch (_err) {
             Logger.error(TAG_LOG, `photoAssetAvailable err:${_err.code}`);
           }
         });
     }
     ```

5. 触发拍照。

   通过photoOutput的[capture](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#capture-2)方法，执行拍照任务。该方法有两个参数，第一个参数为拍照设置setting，setting中可以设置图片质量，图片旋转角度等信息。第二参数为异步回调函数，用于获取结果。接口调用失败会返回相应错误码。

   通过PhotoOutput中的[getPhotoRotation](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#getphotorotation12)方法，可以获取拍照旋转角度。

   通过geoLocationManager中的[geoLocationManager.getCurrentLocation](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation)方法，可以获取图片地理位置信息。使用方法可参考[capture](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#capture-3)示例。

   <!-- @[capture_photo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->
   
   ``` TypeScript
   public async capture(isFront: boolean) {
     Logger.info(TAG_LOG, 'capture start.');
     const degree = await this.getPhotoDegree();
     let rotation = this.getPhotoRotation(this.output!, degree);
     rotation = camera.ImageRotation.ROTATION_0;
     Logger.info(TAG_LOG, `rotation: ${rotation}.`);
     let settings: camera.PhotoCaptureSetting = {
       quality: camera.QualityLevel.QUALITY_LEVEL_HIGH,  // 设置图片质量。
       rotation,  // 设置图片旋转角度。
       mirror: isFront  // 设置镜像使能开关。
     };
     this.output?.capture(settings, (err: BusinessError) => {
       if (err) {
         Logger.error(TAG_LOG, `Failed to capture the photo. error: ${JSON.stringify(err)}`);
         return;
       }
       Logger.info(TAG_LOG, 'Callback invoked to indicate the photo capture request success.');
     });
   }
   ```

## 状态监听

在相机应用开发过程中，可以随时监听拍照输出流状态，包括拍照流开始、拍照帧的开始与结束、拍摄下一张图片是否就绪、拍照输出流的错误等。

- 通过注册固定的captureStart回调函数监听拍照开始结果，当photoOutput创建成功时，即可监听。在相机设备准备开始当前拍照时触发，该事件返回此次拍照的captureId。

  <!-- @[set_capture_start_cb](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->
  
  ``` TypeScript
  onPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureStartWithInfo', (err: BusinessError, captureStartInfo: camera.CaptureStartInfo) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info(`photo capture started, captureId : ${captureStartInfo.captureId}`);
    });
  }
  ```

- 通过注册固定的captureEnd回调函数监听拍照结束结果，当photoOutput创建成功时，即可监听。该事件返回结果为拍照完全结束后的相关信息[CaptureEndInfo](../../reference/apis-camera-kit/arkts-apis-camera-i.md#captureendinfo)。

  <!-- @[set_capture_end_cb](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->
  
  ``` TypeScript
  onPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureEnd', (err: BusinessError, captureEndInfo: camera.CaptureEndInfo) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info(`photo capture end, captureId : ${captureEndInfo.captureId}`);
      console.info(`frameCount : ${captureEndInfo.frameCount}`);
    });
  }
  ```

- 通过注册固定的captureReady回调函数获取监听能否继续拍摄下一张的结果，当photoOutput创建成功时，即可监听。当下一张可拍时触发，该事件返回结果为下一张可拍的相关信息。

  <!-- @[set_capture_ready_cb](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->
  
  ``` TypeScript
  captureReadyCallback(err: BusinessError): void {
    if (err !== undefined && err.code !== 0) {
      Logger.error(TAG_LOG, `Callback Error, errorCode: ${err.code}`);
      return;
    }
    Logger.info(TAG_LOG, `photo capture ready`);
  }
  
  registerPhotoOutputCaptureReady(photoOutput: camera.PhotoOutput): void {
    Logger.info(TAG_LOG, `register PhotoOutput Capture Ready...`);
    photoOutput.on('captureReady', this.captureReadyCallback);
  }
  
  unregisterPhotoOutputCaptureReady(photoOutput: camera.PhotoOutput): void {
    Logger.info(TAG_LOG, `unregister PhotoOutput Capture Ready...`);
    photoOutput.off('captureReady');
  }
  ```

- 通过注册固定的error回调函数获取监听拍照输出流的错误结果。回调返回拍照输出接口使用错误时的对应错误码，错误码类型参见[CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode)。

  <!-- @[set_photo_error_cb](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/YUVPhotoSample/camera/src/main/ets/cameramanagers/PhotoManager.ets) -->
  
  ``` TypeScript
  onPhotoOutputError(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('error', (error: BusinessError) => {
      console.error(`Photo output error code: ${error.code}`);
    });
  }
  ```
