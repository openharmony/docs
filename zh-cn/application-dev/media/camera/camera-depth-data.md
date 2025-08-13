# 深度信息(仅对系统应用开放)(ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

深度信息表示图像中每个像素点与相机之间的距离关系，可以辅助实现更精准的对焦和背景虚化效果等。在相机应用预览、拍照和录像场景中，支持上报深度信息。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/arkts-apis-camera.md)。

1. 导入camera接口，接口中提供了相机相关的属性和方法，导入方法如下。
     
   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 通过[CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability)类中的depthProfiles属性获取当前设备支持的深度能力，返回depthProfilesArray数组。通过[createDepthDataOutput](../../reference/apis-camera-kit/js-apis-camera-sys.md#createdepthdataoutput13)方法创建深度流。

   ```ts
   function getDepthDataOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability): camera.DepthDataOutput | undefined {
     let depthProfilesArray: Array<camera.DepthProfile> = cameraOutputCapability.depthProfiles;
     if (!depthProfilesArray) {
       console.error("createOutput depthProfilesArray is null");
     }
     let depthDataOutput: camera.DepthDataOutput | undefined = undefined;
     try {
       depthDataOutput = cameraManager.createDepthDataOutput(depthProfilesArray[0]);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to create the DepthDataOutput instance. error: ${err}`);
     }
     return depthDataOutput;
   }
   ```

3. 使能。通过depthDataOutput类的[start](../../reference/apis-camera-kit/js-apis-camera-sys.md#start13)方法输出深度流。接口调用失败会返回相应错误码，错误码类型参见[Camera错误码](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode)。
     
   ```ts
   async function startDepthDataOutput(depthDataOutput: camera.DepthDataOutput): Promise<void> {
     if (!depthDataOutput) {
       console.error('depthDataOutput Undefined');
       return;
     }
     try {
       await depthDataOutput.start();
     } catch (err) {
       const error = err as BusinessError;
       console.error(`Failed to start depth data output. error: ${err}`);
     }
   }
   ```

## 状态监听

在相机应用开发过程中，可以随时监听深度流的深度数据回调信息，以及深度流输出错误信息。

- 通过注册固定的depthDataAvailable回调函数获取监听深度流数据。
    
  ```ts
  function onDepthDataAvailable(depthDataOutput: camera.DepthDataOutput): void {
    depthDataOutput.on('depthDataAvailable', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('Depth data available');
    });
  }
  ```

- 通过注册固定的error回调函数获取监听深度流输出错误结果，callback返回深度输出接口使用错误时对应的错误码，错误码类型参见[Camera错误码](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode)。
    
  ```ts
  function onDepthDataOutputError(depthDataOutput: camera.DepthDataOutput): void {
    depthDataOutput.on('error', (depthDataOutputError: BusinessError) => {
      console.error(`Depth data output error code: ${depthDataOutputError.code}`);
    });
  }
  ```
