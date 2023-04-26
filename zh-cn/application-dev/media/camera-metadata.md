# 元数据

元数据（Metadata）是对相机返回的图像信息数据的描述和上下文，针对图像信息，提供的更详细的数据，如照片或视频中，识别人像的取景框坐标等信息。

Metadata主要是通过一个TAG（Key），去找对应的Data，用于传递参数和配置信息，减少内存拷贝操作。

## 开发步骤

详细的API说明请参考[Camera API参考](../reference/apis/js-apis-camera.md)。

1. 调用CameraOutputCapability类中的supportedMetadataObjectTypes()方法，获取当前设备支持的元数据类型，并通过createMetadataOutput()方法创建元数据输出流。
     
   ```ts
   let metadataObjectTypes = cameraOutputCapability.supportedMetadataObjectTypes;
   let metadataOutput;
   try {
       metadataOutput = cameraManager.createMetadataOutput(metadataObjectTypes);
   } catch (error) {
       // 失败返回错误码error.code并处理
       console.info(error.code);
   }
   ```

2. 调用start()方法输出metadata数据，接口调用失败时，会返回相应错误码，错误码类型参见CameraErrorCode。
     
   ```ts
   metadataOutput.start().then(() => {
       console.info('Callback returned with metadataOutput started.');
   }).catch((err) => {
       console.info('Failed to metadataOutput start '+ err.code);
   });
   ```

3. 调用stop方法停止输出metadata数据，接口调用失败会返回相应错误码，错误码类型参见CameraErrorCode。
     
   ```ts
   metadataOutput.stop().then(() => {
       console.info('Callback returned with metadataOutput stopped.');
   }).catch((err) => {
       console.info('Failed to metadataOutput stop '+ err.code);
   });
   ```

## 状态监听

在相机应用开发过程中，可以随时监听metadata数据以及输出流的状态。

- 通过注册监听获取metadata对象，监听事件固定为metadataObjectsAvailable。检测到有效metadata数据时，callback返回相应的metadata数据信息，metadataOutput创建成功时可监听。
    
  ```ts
  metadataOutput.on('metadataObjectsAvailable', (metadataObjectArr) => {
      console.info(`metadata output metadataObjectsAvailable`);
  })
  ```

  > **说明：**
  >
  > 当前的元数据类型仅支持人脸检测（FACE_DETECTION）功能。元数据信息对象为识别到的人脸区域的矩形信息（Rect），包含矩形区域的左上角x坐标、y坐标和矩形的宽高数据。

- 通过注册回调函数，获取监听metadata流的错误结果，callback返回metadata输出接口使用错误时返回的错误码，错误码类型参见[CameraErrorCode](../reference/apis/js-apis-camera.md#cameraerrorcode)。
    
  ```ts
  metadataOutput.on('error', (metadataOutputError) => {
      console.info(`Metadata output error code: ${metadataOutputError.code}`);
  })
  ```
