# 动态照片(ArkTS)

相机框架提供动态照片拍摄能力，业务应用可以类似拍摄普通照片一样，一键式拍摄得到动态照片。

应用开发动态照片主要分为以下步骤：

- 查询当前设备的当前模式是否支持拍摄动态照片。
- 如果支持动态照片，可以调用相机框架提供的使能接口**使能**动态照片能力。
- 监听照片回调，将照片存入媒体库。可参考[MediaLibrary Kit-访问和管理动态照片资源](../medialibrary/photoAccessHelper-movingphoto.md)。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/js-apis-camera.md)。

> **说明：**
>
> - 使能动态照片前需要使能[分段式拍照](camera-deferred-capture.md)能力。
> - 拍摄动态照片需要麦克风权限ohos.permission.MICROPHONE，权限申请和校验的方式请参考[开发准备](camera-preparation.md)。否则拍摄的照片没有声音。

1. 导入依赖，需要导入相机框架、媒体库、图片相关领域依赖。

   ```ts
   import { camera } from '@kit.CameraKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   import { BusinessError } from '@kit.BasicServicesKit';
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

3. 查询当前设备当前模式是否支持动态照片能力。

    > **说明：**
    > 查询是否支持动态照片前需要先完成相机会话配置、提交和启动会话，详细开发步骤请参考[会话管理](camera-session-management.md)。

    ```ts
    function isMovingPhotoSupported(photoOutput: camera.PhotoOutput): boolean {
      let isSupported: boolean = false;
      try {
        isSupported = photoOutput.isMovingPhotoSupported();
      } catch (error) {
        // 失败返回错误码error.code并处理
        let err = error as BusinessError;
        console.error(`The isMovingPhotoSupported call failed. error code: ${err.code}`);
      }
      return isSupported;
    }
    ```

4. 使能动态照片拍照能力。

   ```ts
   function enableMovingPhoto(photoOutput: camera.PhotoOutput): void {
     try {
       photoOutput.enableMovingPhoto(true);
     } catch (error) {
       // 失败返回错误码error.code并处理
       let err = error as BusinessError;
       console.error(`The enableMovingPhoto call failed. error code: ${err.code}`);
     }
   }
   ```

5. 触发拍照，与普通拍照方式相同，请参考[拍照](camera-shooting.md)。

## 状态监听

在相机应用开发过程中，可以随时监听动态照片拍照输出流状态。通过注册photoAsset的回调函数获取监听结果，photoOutput创建成功时即可监听。

   ```ts
   let context = getContext(this);
   let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

   async function mediaLibSavePhoto(photoAsset: photoAccessHelper.PhotoAsset): Promise<void> {
     try {
       let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
       assetChangeRequest.saveCameraPhoto();
       await phAccessHelper.applyChanges(assetChangeRequest);
       console.info('apply saveCameraPhoto successfully');
     } catch (err) {
       console.error(`apply saveCameraPhoto failed with error: ${err.code}, ${err.message}`);
     }
   }

   function onPhotoOutputPhotoAssetAvailable(photoOutput: camera.PhotoOutput): void {
     photoOutput.on('photoAssetAvailable', (err: BusinessError, photoAsset: photoAccessHelper.PhotoAsset): void => {
       if (err) {
         console.info(`photoAssetAvailable error: ${JSON.stringify(err)}.`);
         return;
       }
       console.info('photoOutPutCallBack photoAssetAvailable');
       // 调用媒体库落盘接口保存一阶段图和动态照片视频
       mediaLibSavePhoto(photoAsset);
     });
   }
   ```
