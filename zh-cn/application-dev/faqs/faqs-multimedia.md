# 媒体开发常见问题


## 使用XComponent组件显示相机的预览输出流时，如何获取相机的帧数据(API 9)

**问题现象**

目前接口不支持实时预览相机的帧数据，只能绑定一个动作来获取，比如拍照动作。

**解决措施**

通过创建双路预览来实现。

1. Xcomponent来创建预览流。

   ```
   // 获取PreviewOutput(预览输出类)实例
   const surfaceId = globalThis.mxXComponentController.getXComponentSurfaceld();
   this.mPreviewOutput = await Camera.createPreviewOutput(surfaceld) ;
   ```

2. 使用imageReceiver来监听图像信息。

   ```
   // 添加双路预览
   const fullWidth = this.mFullScreenSize.width;
   const fullHeight = this.mFullScreenSize.height;
   const imageReceiver = await image.createImageReceiver(fullwidth, fullHeight, 
     formatImage, capacityImage) ;
   const photoSurfaceId = await imageReceiver.getReceivingSurfaceld();
   this.mPreviewOutputDouble = await Camera.createPreviewOutput ( photoSurfaceld)
   ```


## 如何获取前置摄像头的预览图像(API 9)

**解决措施**

1. 使用系统相机框架\@ohos.multimedia.camera获取物理摄像头信息。

   ```
   let cameraManager = await camera.getCameraManager(context);
   let camerasInfo = await cameraManager.getSupportedCameras();
   let cameraDevice = this.camerasInfo[0];
   ```

2. 创建并启动物理摄像头输入流通道。

   ```
   let cameraInput = await cameraManager.createCameraInput(cameraDevice);
   await this.cameraInput.open();
   ```

3. 拿到物理摄像头信息查询摄像头支持预览流支持的输出格式，结合XComponent提供的surfaceId创建预览输出通道。

   ```
   let outputCapability = await this.cameraManager.getSupportedOutputCapability(cameraDevice);
   let previewProfile = this.outputCapability.previewProfiles[0];
   let previewOutput = await cameraManager.createPreviewOutput(previewProfile, previewId);
   ```

4. 创建相机会话，在会话中添加摄像头输入流和预览输出流，然后启动会话，预览画面就会在XComponent组件上送显。

   ```
   let captureSession = await cameraManager.createCaptureSession();
   await captureSession.beginConfig();
   await captureSession.addInput(cameraInput);
   await captureSession.addOutput(previewOutput);
   await this.captureSession.commitConfig()
   await this.captureSession.start();
   ```


## 如何设置相机焦距(API 9)

**解决措施**

1. 判断当前摄像头是否为前置摄像头，前置摄像头不支持设置焦距。

2. 通过captureSession.getZoomRatioRange()接口获取设备焦距设置支持的最大、最小范围。

3. 判断目标焦距参数大小是否在步骤二获取的范围内，然后通过captureSession.setZoomRatio()接口设置相机焦距。


## 创建多个视频组件无法播放(API 9)

**问题现象**

创建十几个视频组件无法播放甚至崩溃。

**解决措施**

当前限制最多创建13个媒体播放实例。


## 如何直接调起图片库(API 9)

**解决措施**

```
let want = {
  bundleName: 'com.ohos.photos',
  abilityName: 'com.ohos.photos.MainAbility',
  parameters: {
 uri: 'detail'
  }
};
let context = getContext(this) as common.UIAbilityContext;
context.startAbility(want);
```


## 如何申请设备上的媒体读写权限(API 9)

适用于Stage模型。

**解决措施**

1. 在module.json5配置文件中配置媒体读写权限ohos.permission.READ_MEDIA和ohos.permission.WRITE_MEDIA。

   示例：

   ```
   {
     "module" : {
       "requestPermissions":[
         {
           "name" : "ohos.permission.READ_MEDIA",
           "reason": "$string:reason"
         },
         {
           "name" : "ohos.permission.WRITE_MEDIA",
           "reason": "$string:reason"
         }
       ]
     }
   }
   ```

2. 这两个权限的授权方式均为user_grant，因此需要调用requestPermissionsFromUser接口，以动态弹窗的方式向用户申请授权。

   ```
   let context = getContext(this) as common.UIAbilityContext;
   let atManager = abilityAccessCtrl.createAtManager();
   let permissions: Array<string> = ['ohos.permission.READ_MEDIA','ohos.permission.WRITE_MEDIA']
   atManager.requestPermissionsFromUser(context, permissions)
   .then((data) => {
       console.log("Succeed to request permission from user with data: " + JSON.stringify(data))
   }).catch((error) => {
       console.log("Failed to request permission from user with error: " + JSON.stringify(error))
   })
   ```


## 如何检测当前相机服务的状态(API 9)

适用于Stage模型。

**解决措施**

cameraManager通过设置状态回调返回相机状态。

```
cameraManager.on('cameraStatus', (cameraStatusInfo) => {
  console.log(`camera : ${cameraStatusInfo.camera.cameraId}`);
  console.log(`status: ${cameraStatusInfo.status}`);
})
```

相机状态：CameraStatus

枚举，相机状态。

CAMERA_STATUS_APPEAR 0 新的相机出现。

CAMERA_STATUS_DISAPPEAR 1 相机被移除。

CAMERA_STATUS_AVAILABLE 2 相机可用。

CAMERA_STATUS_UNAVAILABLE 3 相机不可用。

参考文档：[CameraStatus](../reference/apis/js-apis-camera.md#oncamerastatus)

