# 分段式拍照(ArkTS)

分段式拍照是相机的重要功能之一，优化了拍照响应时延，提升用户体验。分段式拍照又名二阶段拍照，应用下发拍照请求后，**第一阶段**系统会很快返回给应用一张**缩略图**（80分图），应用需将该图片及相关信息存入媒体库；**第二阶段**子服务会根据系统压力及定制化场景进行调度，将后处理好的**原图**（100分图）回传给媒体库。

应用开发分段式拍照主要分为以下步骤：

- 查询当前设备的当前模式是否支持分段式拍照。
- 如果支持分段式能力，可以调用相机框架提供的使能接口**使能**分段式能力。
- 监听缩略图回调，获取缩略图代理类，将缩略图存入媒体库。

**注意事项：**

- 分段式拍照能力是根据**设备**和**模式**决定的，不同的设备支持不同的模式，不同的模式下分段式能力也各有不同，所以应用在切换设备或模式后需要重新使能分段式能力。
- 分段式使能需要在配流期间完成，配流完成后的使能操作不生效。



## 开发步骤

详细的API说明请参考[Camera API参考](../reference/apis/js-apis-camera.md)。

1. 导入依赖，需要导入相机框架、媒体库、图片相关领域依赖。

   【示例1】

   ```ts
   import camera from '@ohos.multimedia.camera';
   import image from '@ohos.multimedia.image';
   import mediaLibrary from '@ohos.multimedia.mediaLibrary';
   import fs from '@ohos.file.fs';
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   import { BusinessError } from '@ohos.base';
   ```

2. 确定拍照输出流。

   通过CameraOutputCapability类中的photoProfiles()方法，可获取当前设备支持的拍照输出流，通过createPhotoOutput()方法创建拍照输出流。

   【示例2】

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

   【示例3】

   ```ts
   function isDeferredImageDeliverySupported(photoOutput: camera.PhotoOutput,
                                             deferredType: camera.DeferredDeliveryImageType): boolean {
   	let res: boolean = false;
       if (photoOutPut !== null) {
   		res = photoOutPut.isDeferredImageDeliverySupported(camera.DeferredDeliveryImageType.PHOTO);
       }
       console.info(`isDeferredImageDeliverySupported res: ${res}`);
       return res;
   }
   ```

4. 使能分段式拍照能力。

   【示例4】

   ```ts
   function EnableDeferredPhotoAbility(photoOutput: camera.PhotoOutput): void {
   	photoOutPut.deferImageDeliveryFor(camera.DeferredDeliveryImageType.PHOTO);
   }
   ```

5. 查询是否已经成功使能分段式拍照。

   【示例5】

   ```ts
   function isDeferredImageDeliveryEnabled(photoOutput: camera.PhotoOutpu,
                                           deferredType: camera.DeferredDeliveryImageType): boolean {
   	let res: boolean = false;
       if (photoOutPut !== null) {
   		res = photoOutPut.isDeferredImageDeliveryEnabled(camera.DeferredDeliveryImageType.PHOTO);
       }
       console.info(`isDeferredImageDeliveryEnabled res: ${res}`);
       return res;
   }
   ```

6. 触发拍照，与普通拍照方式相同，请参考[拍照(ArkTS)](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/media/camera-shooting.md)。



## 状态监听

1. 注册缩略图监听回调。

   【示例6】

   ```ts
   function onPhotoOutputDeferredPhotoProxyAvailable(photoOutput: camera.PhotoOutput): void {
   	photoOutPut.on('deferredPhotoProxyAvailable', (err: BusinessError, proxyObj: camera.DeferredPhotoProxy): void => {
         if (err) {
           console.info(`deferredPhotoProxyAvailable error: ${JSON.stringify(err)}.`);
           return;
         }
         console.info('photoOutPutCallBack deferredPhotoProxyAvailable');
         // 获取缩略图 pixelMap
         proxyObj.getThumbnail().then((thumbnail: image.PixelMap) => {
           AppStorage.setOrCreate('proxyThumbnail', thumbnail); 
         });
         // 调用媒体库接口落盘缩略图，详细实现见【示例7】。
         this.saveDeferredPhoto(proxyObj);
       });
   }
   ```

   

2. 调用媒体库接口落盘缩略图。

   Context获取方式请参考：[获取UIAbility的上下文信息](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/application-models/uiability-usage.md#获取uiability的上下文信息)。

   【示例7】

   ```ts
   let context = getContext(this);
   
   async function saveDeferredPhoto(proxyObj: camera.DeferredPhotoProxy) {    
       try {
           // 创建 photoAsset
   		let photoAccessHelper = PhotoAccessHelper.getPhotoAccessHelper(context);
   		let testFileName = 'testFile' + Date.now() + '.jpg';
   		let photoAsset = await photoAccessHelper.createAsset(testFileName);
           // 将缩略图代理类传递给媒体库
           let mediaRequest: photoAccessHelper.MediaChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
           mediaRequest.AddResource(photoAccessHelper.ResourceTypeType.PHOTOT_PROXY, proxyObj);
           let res = await photoAccessHelper.applyChanges(mediaRequest);
   		console.info('saveDeferredPhoto success.');
       } catch (err) {
           console.error(`Failed to saveDeferredPhoto. error: ${JSON.stringify(err)}`);
       }
   }
   ```
