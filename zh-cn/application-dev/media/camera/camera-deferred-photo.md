# 高性能拍照(仅对系统应用开放)(ArkTS)

高性能拍照是相机的重要功能之一，优化了拍照响应时延，提升用户体验。高性能拍照又名分段式拍照，应用下发拍照请求后，**第一阶段**系统会很快返回给应用一张**缩略图**，应用需将该图片及相关信息存入媒体库；**第二阶段**子服务会根据系统压力及定制化场景进行调度，将后处理好的**原图**回传给媒体库。

应用开发分段式拍照主要分为以下步骤：

- 查询当前设备的当前模式是否支持分段式拍照。
- 如果支持分段式能力，可以调用相机框架提供的使能接口**使能**分段式能力。
- 监听缩略图回调，获取缩略图代理类，将缩略图存入媒体库。

> **说明：**
> 
> - 分段式拍照能力是根据**设备**和**模式**决定的，不同的设备支持不同的模式，不同的模式下分段式能力也各有不同，所以应用在切换设备或模式后需要重新使能分段式能力。
> - 分段式使能需要在配流期间完成，配流完成后的使能操作不生效。



## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/js-apis-camera.md)。

1. 导入依赖，需要导入相机框架、媒体库、图片相关领域依赖。

   ```ts
   import { camera } from '@kit.CameraKit';
   import { image } from '@kit.ImageKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
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

3. 查询当前设备当前模式是否支持相应分段式能力。

   ```ts
   function isDeferredImageDeliverySupported(photoOutput: camera.PhotoOutput): boolean {
     let isSupported: boolean = false;
     if (photoOutput !== null) {
       isSupported = photoOutput.isDeferredImageDeliverySupported(camera.DeferredDeliveryImageType.PHOTO);
     }
     console.info(`isDeferredImageDeliverySupported isSupported: ${isSupported}`);
     return isSupported;
   }
   ```

4. 使能分段式拍照能力。

   ```ts
   function EnableDeferredPhotoAbility(photoOutput: camera.PhotoOutput): void {
     photoOutput.deferImageDelivery(camera.DeferredDeliveryImageType.PHOTO);
   }
   ```

5. 查询是否已经成功使能分段式拍照。

   ```ts
   function isDeferredImageDeliveryEnabled(photoOutput: camera.PhotoOutput): boolean {
   	 let isEnabled: boolean = false;
     if (photoOutput !== null) {
   	   isEnabled = photoOutput.isDeferredImageDeliveryEnabled(camera.DeferredDeliveryImageType.PHOTO);
     }
     console.info(`isDeferredImageDeliveryEnabled isEnabled: ${isEnabled}`);
     return isEnabled;
   }
   ```

6. 触发拍照，与普通拍照方式相同，请参考[拍照](camera-shooting.md)。



## 状态监听

1. 注册缩略图监听回调。

   ```ts
   function onPhotoOutputDeferredPhotoProxyAvailable(photoOutput: camera.PhotoOutput, context: Context): void {
     photoOutput.on('deferredPhotoProxyAvailable', (err: BusinessError, proxyObj: camera.DeferredPhotoProxy): void => {
       if (err) {
         console.info(`deferredPhotoProxyAvailable error: ${JSON.stringify(err)}.`);
         return;
       }
       console.info('photoOutPutCallBack deferredPhotoProxyAvailable');
       // 获取缩略图 pixelMap。
       proxyObj.getThumbnail().then((thumbnail: image.PixelMap) => {
         AppStorage.setOrCreate('proxyThumbnail', thumbnail);
       });
       // 调用媒体库接口落盘缩略图，详细实现见2。
       saveDeferredPhoto(proxyObj, context);
     });
   }
   ```

   

2. 调用媒体库接口落盘缩略图。

   Context获取方式请参考：[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

   ```ts
   async function saveDeferredPhoto(proxyObj: camera.DeferredPhotoProxy, context: Context) {    
     try {
       // 创建 photoAsset。
       let accessHelper = photoAccessHelper.getPhotoAccessHelper(context);
       let testFileName = 'testFile' + Date.now() + '.jpg';
       let photoAsset = await accessHelper.createAsset(testFileName);
       // 将缩略图代理类传递给媒体库。
       let mediaRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
       mediaRequest.addResource(photoAccessHelper.ResourceType.PHOTO_PROXY, proxyObj);
       let res = await accessHelper.applyChanges(mediaRequest);
       console.info('saveDeferredPhoto success.');
     } catch (err) {
       console.error(`Failed to saveDeferredPhoto. error: ${JSON.stringify(err)}`);
     }
   }
   ```
