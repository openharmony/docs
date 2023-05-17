# 设备输入

在开发一个相机应用前，需要先创建一个独立的相机设备，应用通过调用和控制相机设备，完成预览、拍照和录像等基础操作。

## 开发步骤

详细的API说明请参考[Camera API参考](../reference/apis/js-apis-camera.md)。

1. 导入camera接口，接口中提供了相机相关的属性和方法，导入方法如下。
     
   ```ts
   import camera from '@ohos.multimedia.camera';
   ```

2. 通过getCameraManager()方法，获取cameraManager对象。
     
   ```ts
   let cameraManager;
   let context: any = getContext(this);
   cameraManager = camera.getCameraManager(context)
   ```

   > **说明：**
   >
   > 如果获取对象失败，说明相机可能被占用或无法使用。如果被占用，须等到相机被释放后才能重新获取。

3. 通过cameraManager类中的getSupportedCameras()方法，获取当前设备支持的相机列表，列表中存储了设备支持的所有相机ID。若列表不为空，则说明列表中的每个ID都支持独立创建相机对象；否则，说明当前设备无可用相机，不可继续后续操作。
     
   ```ts
   let cameraArray = cameraManager.getSupportedCameras();
   if (cameraArray.length <= 0) {
       console.error("cameraManager.getSupportedCameras error");
       return;
   } 
   
   for (let index = 0; index < cameraArray.length; index++) {
       console.info('cameraId : ' + cameraArray[index].cameraId);                          // 获取相机ID
       console.info('cameraPosition : ' + cameraArray[index].cameraPosition);              // 获取相机位置
       console.info('cameraType : ' + cameraArray[index].cameraType);                      // 获取相机类型
       console.info('connectionType : ' + cameraArray[index].connectionType);              // 获取相机连接类型
   }
   ```

4. 通过getSupportedOutputCapability()方法，获取当前设备支持的所有输出流，如预览流、拍照流等。输出流在CameraOutputCapability中的各个profile字段中。
     
   ```ts
   // 创建相机输入流 
   let cameraInput;
   try {    
       cameraInput = cameraManager.createCameraInput(cameraArray[0]);
   } catch (error) {
      console.error('Failed to createCameraInput errorCode = ' + error.code);
   } 
   // 监听cameraInput错误信息
   let cameraDevice = cameraArray[0];
   cameraInput.on('error', cameraDevice, (error) => {
       console.info(`Camera input error code: ${error.code}`);
   }) 
   // 打开相机
   await cameraInput.open(); 
   // 获取相机设备支持的输出流能力
   let cameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraArray[0]);
   if (!cameraOutputCapability) {
       console.error("cameraManager.getSupportedOutputCapability error");
       return;
   }
   console.info("outputCapability: " + JSON.stringify(cameraOutputCapability));
   ```


## 状态监听

在相机应用开发过程中，可以随时监听相机状态，包括新相机的出现、相机的移除、相机的可用状态。在回调函数中，通过相机ID、相机状态这两个参数进行监听，如当有新相机出现时，可以将新相机加入到应用的备用相机中。

  通过注册cameraStatus事件，通过回调返回监听结果，callback返回CameraStatusInfo参数，参数的具体内容可参考相机管理器回调接口实例[CameraStatusInfo](../reference/apis/js-apis-camera.md#camerastatusinfo)。
  
```ts
cameraManager.on('cameraStatus', (cameraStatusInfo) => {
  console.info(`camera: ${cameraStatusInfo.camera.cameraId}`);
  console.info(`status: ${cameraStatusInfo.status}`);
})
```
