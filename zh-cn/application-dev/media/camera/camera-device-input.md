# 设备输入(ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

在开发相机应用时，需要先参考开发准备[申请相关权限](camera-preparation.md)。

相机应用可通过调用和控制相机设备，完成预览、拍照和录像等基础操作。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/arkts-apis-camera.md)。

1. 导入camera接口，接口中提供了相机相关的属性和方法，导入方法如下。

   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

   > **说明：**
   >
   > 在相机设备输入之前需要先完成相机管理，详细开发步骤请参考[相机管理](camera-device-management.md)。

2. 通过[cameraManager](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md)类中的[createCameraInput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createcamerainput)方法创建相机输入流。

   ```ts
   async function createInput(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager): Promise<camera.CameraInput | undefined> {
     // 创建相机输入流。
     let cameraInput: camera.CameraInput | undefined = undefined;
     try {
       cameraInput = cameraManager.createCameraInput(cameraDevice);
     } catch (error) {
       let err = error as BusinessError;
       console.error('Failed to createCameraInput errorCode = ' + err.code);
     }
     if (cameraInput === undefined) {
       return undefined;
     }
     // 监听cameraInput错误信息。
     cameraInput.on('error', cameraDevice, (error: BusinessError) => {
       console.error(`Camera input error code: ${error.code}`);
     });
     // 打开相机。
     await cameraInput.open();
     return cameraInput;
   }
   ```

3. 通过[getSupportedSceneModes](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedscenemodes11)方法，获取当前相机设备支持的模式列表，列表中存储了相机设备支持的所有模式[SceneMode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#scenemode11)。

    ```ts
    function getSupportedSceneMode(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager): Array<camera.SceneMode> {
      // 获取相机设备支持的模式列表。
      let sceneModeArray: Array<camera.SceneMode> = cameraManager.getSupportedSceneModes(cameraDevice);
      if (sceneModeArray != undefined && sceneModeArray.length > 0) {
        for (let index = 0; index < sceneModeArray.length; index++) {
          console.info('Camera SceneMode : ' + sceneModeArray[index]);  
      }
        return sceneModeArray;
      } else {
          console.error("cameraManager.getSupportedSceneModes error");
          return [];
      }
    }
    ```

4. 通过[getSupportedOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedoutputcapability11)方法，获取当前相机设备支持的所有输出流，如预览流、拍照流、录像流等。输出流在[CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability)中的各个profile字段中，根据相机设备指定模式[SceneMode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#scenemode11)的不同，需要添加不同类型的输出流。

   ```ts
   async function getSupportedOutputCapability(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager, sceneMode: camera.SceneMode): Promise<camera.CameraOutputCapability | undefined> {
      // 获取相机设备支持的输出流能力。
      let cameraOutputCapability: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevice, sceneMode);
      if (!cameraOutputCapability) {
        console.error("cameraManager.getSupportedOutputCapability error");
        return undefined;
      }
      console.info("outputCapability: " + JSON.stringify(cameraOutputCapability));
      // 以NORMAL_PHOTO模式为例，需要添加预览流、拍照流。
      // previewProfiles属性为获取当前设备支持的预览输出流。
      let previewProfilesArray: Array<camera.Profile> = cameraOutputCapability.previewProfiles;
      if (!previewProfilesArray) {
        console.error("createOutput previewProfilesArray == null || undefined");
      }
      //photoProfiles属性为获取当前设备支持的拍照输出流。
      let photoProfilesArray: Array<camera.Profile> = cameraOutputCapability.photoProfiles;
      if (!photoProfilesArray) {
        console.error("createOutput photoProfilesArray == null || undefined");
      }
      return cameraOutputCapability;
   } 
   ```