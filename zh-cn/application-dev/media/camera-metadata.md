# 元数据(ArkTS)

元数据（Metadata）是对相机返回的图像信息数据的描述和上下文，针对图像信息，提供的更详细的数据，如照片或视频中，识别人像的取景框坐标等信息。

Metadata主要是通过一个TAG（Key），去找对应的Data，用于传递参数和配置信息，减少内存拷贝操作。

## 开发步骤

详细的API说明请参考[Camera API参考](../reference/apis/js-apis-camera.md)。

1. 导入相关接口，导入方法如下。
   ```ts
   import camera from '@ohos.multimedia.camera';
   import { BusinessError } from '@ohos.base';
   ```

2. 调用[CameraOutputCapability](../reference/apis/js-apis-camera.md#cameraoutputcapability)类中的supportedMetadataObjectTypes方法，获取当前设备支持的元数据类型，并通过[createMetadataOutput](../reference/apis/js-apis-camera.md#createmetadataoutput)方法创建元数据输出流。
     
   ```ts
   function getMetadataOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability): camera.MetadataOutput | undefined {
     let metadataObjectTypes: Array<camera.MetadataObjectType> = cameraOutputCapability.supportedMetadataObjectTypes;
     let metadataOutput: camera.MetadataOutput | undefined = undefined;
     try {
       metadataOutput = cameraManager.createMetadataOutput(metadataObjectTypes);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to createMetadataOutput, error code: ${err.code}`);
     }
     return metadataOutput;
   }
   ```

3. 调用[start](../reference/apis/js-apis-camera.md#start-3)方法输出metadata数据，接口调用失败时，会返回相应错误码，错误码类型参见[Camera错误码](../reference/apis/js-apis-camera.md#cameraerrorcode)。
     
   ```ts
   function startMetadataOutput(metadataOutput: camera.MetadataOutput): void {
     metadataOutput.start().then(() => {
       console.info('Callback returned with metadataOutput started.');
     }).catch((err: BusinessError) => {
       console.error(`Failed to metadataOutput start, error code: ${err.code}`);
     });
   }
   ```

4. 调用[stop](../reference/apis/js-apis-camera.md#stop-3)方法停止输出metadata数据，接口调用失败会返回相应错误码，错误码类型参见[Camera错误码](../reference/apis/js-apis-camera.md#cameraerrorcode)。
     
   ```ts
   function stopMetadataOutput(metadataOutput: camera.MetadataOutput): void {
     metadataOutput.stop().then(() => {
       console.info('Callback returned with metadataOutput stopped.');
     }).catch((err: BusinessError) => {
       console.error(`Failed to metadataOutput stop, error code: ${err.code}`);
     });
   }
   ```

## 状态监听

在相机应用开发过程中，可以随时监听metadata数据以及输出流的状态。

- 通过注册监听获取metadata对象，监听事件固定为metadataObjectsAvailable。检测到有效metadata数据时，callback返回相应的metadata数据信息，metadataOutput创建成功时可监听。
    
  ```ts
  function onMetadataObjectsAvailable(metadataOutput: camera.MetadataOutput): void {
    metadataOutput.on('metadataObjectsAvailable', (err: BusinessError, metadataObjectArr: Array<camera.MetadataObject>) => {
      console.info('metadata output metadataObjectsAvailable');
    });
  }
  ```

  > **说明：**
  >
  > 当前的元数据类型仅支持人脸检测（FACE_DETECTION）功能。元数据信息对象为识别到的人脸区域的矩形信息（Rect），包含矩形区域的左上角x坐标、y坐标和矩形的宽高数据。

- 通过注册回调函数，获取监听metadata流的错误结果，callback返回metadata输出接口使用错误时返回的错误码，错误码类型参见[CameraErrorCode](../reference/apis/js-apis-camera.md#cameraerrorcode)。
    
  ```ts
  function onMetadataError(metadataOutput: camera.MetadataOutput): void {
    metadataOutput.on('error', (metadataOutputError: BusinessError) => {
      console.error(`Metadata output error code: ${metadataOutputError.code}`);
    });
  }
  ```
