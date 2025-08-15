# 相机管理(ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

在开发一个相机应用前，需要先通过调用相机接口来创建一个独立的相机设备。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/arkts-apis-camera.md)。

1. 导入camera接口，接口中提供了相机相关的属性和方法，导入方法如下。

   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. 通过[getCameraManager](../../reference/apis-camera-kit/arkts-apis-camera-f.md#cameragetcameramanager)方法，获取cameraManager对象。

   Context获取方式请参考：[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

   ```ts
   function getCameraManager(context: common.BaseContext): camera.CameraManager | undefined {
     let cameraManager: camera.CameraManager;
     try {
       cameraManager = camera.getCameraManager(context);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`getCameraManager error, errCode: ${err.code}`);
       return undefined;
     }
     return cameraManager;
   }
   ```

   > **说明：**
   >
   > 如果获取对象失败，说明相机可能被占用或无法使用。如果被占用，须等到相机被释放后才能重新获取。

3. 通过[CameraManager](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md)类中的[getSupportedCameras](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedcameras)方法，获取当前设备支持的相机列表，列表中存储了设备支持的所有相机ID。若列表不为空，则说明列表中的每个ID都支持独立创建相机对象；否则，说明当前设备无可用相机，不可继续后续操作。

   ```ts
   function getCameraDevices(cameraManager: camera.CameraManager): Array<camera.CameraDevice> {
     let cameraArray: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
     if (cameraArray != undefined && cameraArray.length > 0) {
       for (let index = 0; index < cameraArray.length; index++) {
         console.info('cameraId : ' + cameraArray[index].cameraId);  // 获取相机ID。
         console.info('cameraPosition : ' + cameraArray[index].cameraPosition);  // 获取相机位置。
         console.info('cameraType : ' + cameraArray[index].cameraType);  // 获取相机类型。
         console.info('connectionType : ' + cameraArray[index].connectionType);  // 获取相机连接类型。
       }
       return cameraArray;
     } else {
       console.error("cameraManager.getSupportedCameras error");
       return [];
     }
   }
   ```


## 状态监听

在相机应用开发过程中，可以随时监听相机状态，包括新相机的出现、相机的移除、相机的可用状态。在回调函数中，通过相机ID、相机状态这两个参数进行监听，如当有新相机出现时，可以将新相机加入到应用的备用相机中。

  通过注册cameraStatus事件，通过回调返回监听结果，callback返回CameraStatusInfo参数，参数的具体内容可参考相机管理器回调接口实例[CameraStatusInfo](../../reference/apis-camera-kit/arkts-apis-camera-i.md#camerastatusinfo)。

```ts
function onCameraStatusChange(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraStatus', (err: BusinessError, cameraStatusInfo: camera.CameraStatusInfo) => {
    if (err !== undefined && err.code !== 0) {
      console.error(`Callback Error, errorCode: ${err.code}`);
      return;
    }
    // 如果当通过USB连接相机设备时，回调函数会返回新的相机出现状态。
    if (cameraStatusInfo.status == camera.CameraStatus.CAMERA_STATUS_APPEAR) {
      console.info(`New Camera device appear.`);
    }
    // 如果当断开相机设备USB连接时，回调函数会返回相机被移除状态。
    if (cameraStatusInfo.status == camera.CameraStatus.CAMERA_STATUS_DISAPPEAR) {
      console.info(`Camera device has been removed.`);
    }
    // 相机被关闭时，回调函数会返回相机可用状态。
    if (cameraStatusInfo.status == camera.CameraStatus.CAMERA_STATUS_AVAILABLE) {
      console.info(`Current Camera is available.`);
    }
    // 相机被打开/占用时，回调函数会返回相机不可用状态。
    if (cameraStatusInfo.status == camera.CameraStatus.CAMERA_STATUS_UNAVAILABLE) {
      console.info(`Current Camera has been occupied.`);
    }
    console.info(`camera: ${cameraStatusInfo.camera.cameraId}`);
    console.info(`status: ${cameraStatusInfo.status}`);
  });
}
```