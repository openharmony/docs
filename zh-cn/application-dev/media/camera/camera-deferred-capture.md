# 分段式拍照(ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

分段式拍照是相机的重要功能之一，即应用下发拍照任务后，系统将分多阶段上报不同质量的图片。

- 在第一阶段，系统快速上报轻量处理的图片，轻量处理的图片比全质量图低，出图速度快。应用通过回调会收到一个PhotoAsset对象，通过该对象可调用媒体库接口，读取图片或落盘图片。
- 在第二阶段，相机框架会根据应用的请求图片诉求或者在系统闲时，进行图像增强处理得到全质量图，将处理好的图片传回给媒体库，替换轻量处理的图片。

通过分段式拍照，优化了系统的拍照响应时延，从而提升用户体验。

应用开发分段式拍照主要分为以下步骤：

- 通过PhotoOutput，监听photoAssetAvailable回调，获取[photoAccessHelper](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper.md)的PhotoAsset对象。
- 通过PhotoAsset对象，调用媒体库相关接口，读取或落盘图片。

> **说明：**
> 
> - 分段式拍照能力是根据**设备**和**模式**决定的，不同的设备支持不同的模式，不同的模式下分段式能力也各有不同，所以应用在切换设备或模式后分段式能力可能会发生变化。
> - 分段式拍照能力应用无需主动使能，相机框架会在配流期间判断设备和模式是否支持分段式，如果支持会使能分段式拍照。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/arkts-apis-camera.md)。

1. 导入依赖，需要导入相机框架、媒体库、图片相关领域依赖。

   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   ```

2. 确定拍照输出流。

   通过[CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability)中的photoProfiles属性，可获取当前设备支持的拍照输出流，通过[createPhotoOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createphotooutput11)方法创建拍照输出流。

   ```ts
   function getPhotoOutput(cameraManager: camera.CameraManager, 
     cameraOutputCapability: camera.CameraOutputCapability): camera.PhotoOutput | undefined {
     let photoProfilesArray: Array<camera.Profile> = cameraOutputCapability.photoProfiles;
     if (photoProfilesArray===null || photoProfilesArray===undefined) {
       console.error("createOutput photoProfilesArray is null!");
       return undefined;
     }
     let photoOutput: camera.PhotoOutput | undefined = undefined;
     try {
      if (photoProfilesArray.length > 0) {
          photoOutput = cameraManager.createPhotoOutput(photoProfilesArray[0]);
      } else {
          console.error("the length of photoProfilesArray<=0!");
          return undefined;
      }
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to createPhotoOutput. error: ${err}`);
     }
     return photoOutput;
   }
   ```

3. 设置拍照photoAssetAvailable的回调。

   > **注意：**
   >
   > 如果已经注册了photoAssetAvailable回调，并且在Session开始之后又注册了photoAvailable回调，photoAssetAvailable和photoAvailable同时注册，会导致流被重启，仅photoAssetAvailable生效。
   >
   > 不建议开发者同时注册[photoAvailable](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#onphotoavailable11)和[photoAssetAvailable](../../reference/apis-camera-kit/arkts-apis-camera-PhotoOutput.md#onphotoassetavailable12)。

   ```ts
   function getPhotoAccessHelper(context: Context): photoAccessHelper.PhotoAccessHelper {
     let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
     return phAccessHelper;
   }

   function onPhotoOutputPhotoAssetAvailable(photoOutput: camera.PhotoOutput, context: Context): void {
     photoOutput.on('photoAssetAvailable', (err: BusinessError, photoAsset: photoAccessHelper.PhotoAsset) => {
       if (err) {
         console.error(`photoAssetAvailable error: ${err}.`);
         return;
       }
       console.info('photoOutPutCallBack photoAssetAvailable');
       // 开发者可通过photoAsset调用媒体库相关接口，自定义处理图片。
       // 处理方式一：调用媒体库落盘接口保存一阶段图，二阶段图就绪后媒体库会主动帮应用替换落盘图片。
       mediaLibSavePhoto(photoAsset, getPhotoAccessHelper(context));
       // 处理方式二：调用媒体库接口请求图片并注册一阶段图或二阶段图buffer回调，自定义使用。
       mediaLibRequestBuffer(photoAsset, context);
     });
   }

   async function mediaLibSavePhoto(photoAsset: photoAccessHelper.PhotoAsset,
     phAccessHelper: photoAccessHelper.PhotoAccessHelper): Promise<void> {
     try {
       let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
       assetChangeRequest.saveCameraPhoto();
       await phAccessHelper.applyChanges(assetChangeRequest);
       console.info('apply saveCameraPhoto successfully');
     } catch (err) {
       console.error(`apply saveCameraPhoto failed with error: ${err.code}, ${err.message}`);
     }
   }

   class MediaDataHandler implements photoAccessHelper.MediaAssetDataHandler<ArrayBuffer> {
     onDataPrepared(data: ArrayBuffer) {
       if (data === undefined) {
         console.error('Error occurred when preparing data');
         return;
       }
       // 应用获取到图片buffer后可自定义处理。
       console.info('on image data prepared');
     }
   }

   async function mediaLibRequestBuffer(photoAsset: photoAccessHelper.PhotoAsset, context: Context) {
     let requestOptions: photoAccessHelper.RequestOptions = {
       // 按照业务需求配置回图模式。
       // FAST_MODE：仅接收一阶段低质量图回调。
       // HIGH_QUALITY_MODE：仅接收二阶段全质量图回调。
       // BALANCE_MODE：接收一阶段及二阶段图片回调。
       deliveryMode: photoAccessHelper.DeliveryMode.FAST_MODE,
     }
     const handler = new MediaDataHandler();
     await photoAccessHelper.MediaAssetManager.requestImageData(context, photoAsset, requestOptions, handler);
     console.info('requestImageData successfully');
   }
   ```

   落盘图片参考媒体库接口：[saveCameraPhoto](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#savecameraphoto12)

   请求图片参考媒体库接口：[requestImageData](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetManager.md#requestimagedata11) 和 [onDataPrepared](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetDataHandler.md#ondataprepared11)

4. 拍照时的会话配置及触发拍照的方式，与普通拍照相同，请参考[拍照](camera-shooting.md)的步骤4-5。

## 状态监听

在相机应用开发过程中，可以随时监听拍照输出流状态，包括拍照流开始、拍照帧的开始与结束、拍照输出流的错误。

- 通过注册固定的captureStartWithInfo回调函数获取监听拍照开始结果，photoOutput创建成功时即可监听，相机设备已经准备开始这次拍照时触发，该事件返回此次拍照的captureId。

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

- 通过注册固定的error回调函数获取监听拍照输出流的错误结果。callback返回拍照输出接口使用错误时的对应错误码，错误码类型参见[Camera错误码](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode)。

  ```ts
  function onPhotoOutputError(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('error', (error: BusinessError) => {
      console.error(`Photo output error code: ${error.code}`);
    });
  }
  ```