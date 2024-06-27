# 分段式拍照(ArkTS)

分段式拍照是相机的重要功能之一，优化了拍照响应时延，提升用户体验。分段式拍照即应用下发拍照后，系统会分多阶段上报不同质量的图片。当前**第一阶段**系统快速上报低质量图，应用通过回调会收到一个**PhotoAsset对象**，通过该对象调用媒体库接口，读取图片或落盘图片；**第二阶段**分段式子服务会根据系统压力及定制化场景进行调度，将后处理好的**原图**回传给媒体库，替换低质量图。

应用开发分段式拍照主要分为以下步骤：

- 监听**photoAssetAvailable**回调，获取**PhotoAsset对象**。
- 通过**PhotoAsset对象**，调用媒体库相关接口，读取或落盘图片。

> **说明：**
> 
> - 分段式拍照能力是根据**设备**和**模式**决定的，不同的设备支持不同的模式，不同的模式下分段式能力也各有不同，所以应用在切换设备或模式后分段式能力可能会发生变化。
> - 分段式拍照能力应用无需主动使能，相机框架会在配流期间判断设备和模式是否支持分段式，如果支持会使能分段式拍照。

**注意事项：**
**如果已经注册了photoAssetAvailable回调，在session start 之后又注册了photoAvailable回调，会导致重启流！**
**不建议同时注册photoAvailable和photoAssetAvailable！**

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/js-apis-camera.md)。

1. 导入依赖，需要导入相机框架、媒体库、图片相关领域依赖。

   ```ts
   import camera from '@ohos.multimedia.camera';
   import image from '@ohos.multimedia.image';
   import mediaLibrary from '@ohos.multimedia.mediaLibrary';
   import fs from '@ohos.file.fs';
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   import { BusinessError } from '@ohos.base';
   ```

2. 确定拍照输出流。

   通过[CameraOutputCapability](../../reference/apis-camera-kit/js-apis-camera.md#cameraoutputcapability)类中的photoProfiles属性，可获取当前设备支持的拍照输出流，通过[createPhotoOutput](../../reference/apis-camera-kit/js-apis-camera.md#createphotooutput11)方法创建拍照输出流。

   ```ts
   function getPhotoOutput(cameraManager: camera.CameraManager, 
                           cameraOutputCapability: camera.CameraOutputCapability): camera.PhotoOutput | undefined {
     let photoProfilesArray: Array<camera.Profile> = cameraOutputCapability.photoProfiles;
     if (!photoProfilesArray) {
       console.error("createOutput photoProfilesArray == null || undefined");
     }
     let photoOutput: camera.PhotoOutput | undefined = undefined;
     try {
       photoOutput = cameraManager.createPhotoOutput(photoProfilesArray[0]);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to createPhotoOutput. error: ${JSON.stringify(err)}`);
     }
     return photoOutput;
   }
   ```

3. 设置拍照photoAssetAvailable的回调。

   ```ts
   function photoAssetAvailableCallback(err: BusinessError, photoAsset: photoAccessHelper.PhotoAsset): void {
     if (err) {
       console.info(`photoAssetAvailable error: ${JSON.stringify(err)}.`);
       return;
     }
     console.info('photoOutPutCallBack photoAssetAvailable');
     // 开发者可通过photoAsset调用媒体库相关接口，自定义处理图片
     // 处理方式一：调用媒体库落盘接口保存一阶段低质量图，二阶段真图就绪后媒体库会主动帮应用替换落盘图片
     // 处理方式二：调用媒体库接口请求图片并注册低质量图或高质量图buffer回调，自定义使用
   }
   
   function onPhotoOutputPhotoAssetAvailable(photoOutput: camera.PhotoOutput): void {
     photoOutput.on('photoAssetAvailable', photoAssetAvailableCallback);
   }
   ```

   媒体库落盘图片参考：[saveCameraPhoto](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#savecameraphoto12)

   媒体库请求图片参考：[requestimagedata](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#requestimagedata11) 和 [ondataprepare](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#ondataprepared11)

4. 参数配置，与普通拍照方式相同，请参考[拍照](camera-shooting.md)。

5. 触发拍照，与普通拍照方式相同，请参考[拍照](camera-shooting.md)。

## 状态监听

在相机应用开发过程中，可以随时监听拍照输出流状态，包括拍照流开始、拍照帧的开始与结束、拍照输出流的错误。

- 通过注册固定的captureStart回调函数获取监听拍照开始结果，photoOutput创建成功时即可监听，拍照第一次曝光时触发，该事件返回此次拍照的captureId。

  ```ts
  function onPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureStartWithInfo', (err: BusinessError, captureStartInfo: camera.CaptureStartInfo) => {
      console.info(`photo capture started, captureId : ${captureStartInfo.captureId}`);
    });
  }
  ```

- 通过注册固定的captureEnd回调函数获取监听拍照结束结果，photoOutput创建成功时即可监听，该事件返回结果为拍照完全结束后的相关信息[CaptureEndInfo](../../reference/apis-camera-kit/js-apis-camera.md#captureendinfo)。

  ```ts
  function onPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('captureEnd', (err: BusinessError, captureEndInfo: camera.CaptureEndInfo) => {
      console.info(`photo capture end, captureId : ${captureEndInfo.captureId}`);
      console.info(`frameCount : ${captureEndInfo.frameCount}`);
    });
  }
  ```

- 通过注册固定的error回调函数获取监听拍照输出流的错误结果。callback返回拍照输出接口使用错误时的对应错误码，错误码类型参见[CameraErrorCode](../../reference/apis-camera-kit/js-apis-camera.md#cameraerrorcode)。

  ```ts
  function onPhotoOutputError(photoOutput: camera.PhotoOutput): void {
    photoOutput.on('error', (error: BusinessError) => {
      console.error(`Photo output error code: ${error.code}`);
    });
  }
  ```