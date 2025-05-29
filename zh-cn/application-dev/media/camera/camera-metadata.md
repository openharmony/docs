# 元数据(ArkTS)

在开发相机应用时，需要先参考开发准备[申请相关权限](camera-preparation.md)。

元数据（Metadata）是对相机返回的图像信息数据的描述和上下文，针对图像信息，提供的更详细的数据，如照片或视频中，识别人像的取景框坐标等信息。

Metadata主要是通过一个TAG（Key），去找对应的Data，用于传递参数和配置信息，减少内存拷贝操作。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/js-apis-camera.md)。

1. 导入相关接口，导入方法如下。
   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 调用[CameraOutputCapability](../../reference/apis-camera-kit/js-apis-camera.md#cameraoutputcapability)类中的supportedMetadataObjectTypes属性，获取当前设备支持的元数据类型，并通过[createMetadataOutput](../../reference/apis-camera-kit/js-apis-camera.md#createmetadataoutput)方法创建元数据输出流。
     
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

3. 调用[Session.start](../../reference/apis-camera-kit/js-apis-camera.md#start11)方法开启metadata数据输出，再通过监听事件metadataObjectsAvailable回调拿到数据，接口调用失败时，会返回相应错误码，错误码类型参见[Camera错误码](../../reference/apis-camera-kit/js-apis-camera.md#cameraerrorcode)。

   previewOutput获取方式请参考[相机预览开发步骤](camera-preview.md#开发步骤)。
   ```ts
   async function startMetadataOutput(previewOutput: camera.PreviewOutput, metadataOutput: camera.MetadataOutput, cameraManager: camera.CameraManager): Promise<void> {
     let cameraArray: Array<camera.CameraDevice> = [];
     cameraArray = cameraManager.getSupportedCameras();
     if (cameraArray.length == 0) {
       console.error('no camera.');
       return;
     }
     // 获取支持的模式类型。
     let sceneModes: Array<camera.SceneMode> = cameraManager.getSupportedSceneModes(cameraArray[0]);
     let isSupportPhotoMode: boolean = sceneModes.indexOf(camera.SceneMode.NORMAL_PHOTO) >= 0;
     if (!isSupportPhotoMode) {
       console.error('photo mode not support');
       return;
     }
     let cameraInput: camera.CameraInput | undefined = undefined;
     cameraInput = cameraManager.createCameraInput(cameraArray[0]);
     if (cameraInput === undefined) {
       console.error('cameraInput is undefined');
       return;
     }
     // 打开相机。
     await cameraInput.open();
     let session: camera.PhotoSession = cameraManager.createSession(camera.SceneMode.NORMAL_PHOTO) as camera.PhotoSession;
     session.beginConfig();
     session.addInput(cameraInput);
     session.addOutput(previewOutput);
     session.addOutput(metadataOutput);
     await session.commitConfig();
     await session.start();
   }
   ```

4. 调用[Session.stop](../../reference/apis-camera-kit/js-apis-camera.md#stop11)方法停止输出metadata数据，接口调用失败会返回相应错误码，错误码类型参见[Camera错误码](../../reference/apis-camera-kit/js-apis-camera.md#cameraerrorcode)。
     
   ```ts
   function stopMetadataOutput(session: camera.Session): void {
     session.stop().then(() => {
       console.info('Callback returned with session stopped.');
     }).catch((err: BusinessError) => {
       console.error(`Failed to session stop, error code: ${err.code}`);
     });
   }
   ```

## 状态监听

在相机应用开发过程中，可以随时监听metadata数据以及输出流的状态。

- 通过注册监听获取metadata对象，监听事件固定为metadataObjectsAvailable。检测到有效metadata数据时，callback返回相应的metadata数据信息，metadataOutput创建成功时可监听。
    
  ```ts
  function onMetadataObjectsAvailable(metadataOutput: camera.MetadataOutput): void {
    metadataOutput.on('metadataObjectsAvailable', (err: BusinessError, metadataObjectArr: Array<camera.MetadataObject>) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('metadata output metadataObjectsAvailable');
    });
  }
  ```

  > **说明：**
  >
  > 当前的元数据类型仅支持人脸检测（FACE_DETECTION）功能。元数据信息对象为识别到的人脸区域的矩形信息（Rect），包含矩形区域的左上角x坐标、y坐标和矩形的宽高数据。

- 通过注册回调函数，获取监听metadata流的错误结果，callback返回metadata输出接口使用错误时返回的错误码，错误码类型参见[Camera错误码](../../reference/apis-camera-kit/js-apis-camera.md#cameraerrorcode)。
    
  ```ts
  function onMetadataError(metadataOutput: camera.MetadataOutput): void {
    metadataOutput.on('error', (metadataOutputError: BusinessError) => {
      console.error(`Metadata output error code: ${metadataOutputError.code}`);
    });
  }
  ```
