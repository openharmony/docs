# 预览(ArkTS)

在开发相机应用时，需要先参考开发准备[申请相关权限](camera-preparation.md)。

预览是启动相机后看见的画面，通常在拍照和录像前执行。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/arkts-apis-camera.md)。

1. 导入camera接口，接口中提供了相机相关的属性和方法，导入方法如下。
     
   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 创建Surface。

    相机开发模型为Surface模型，该模型主要通过Surface实现数据交互。在开发相机应用界面时，首先需要通过创建XComponent组件为预览流提供Surface，再通过获取XComponent组件对应Surface的ID创建预览流，预览流画面即可直接在XComponent组件内渲染，详细获取surfaceId请参考[getXComponentSurfaceId](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid9)方法。而XComponent的能力由UI提供，相关介绍可参考[XComponent组件参考](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)。

    > **说明：**
    > 预览流与录像输出流的分辨率的宽高比要保持一致，如果设置XComponent组件中的Surface显示区域宽高比为1920:1080 = 16:9，则需要预览流中的分辨率的宽高比也为16:9，如分辨率选择640:360，或960:540，或1920:1080，以此类推。

3. 通过[CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability)类中的previewProfiles属性获取当前设备支持的预览能力，返回previewProfilesArray数组 。通过[createPreviewOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput)方法创建预览输出流，其中，[createPreviewOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput)方法中的两个参数分别是当前设备支持的预览配置信息previewProfile和步骤二中获取的surfaceId。
     
   ```ts
   function getPreviewOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability, surfaceId: string): camera.PreviewOutput | undefined {
     let previewProfilesArray: Array<camera.Profile> = cameraOutputCapability.previewProfiles;
     let previewOutput: camera.PreviewOutput | undefined = undefined;
     try {
       //previewProfilesArray要选择与步骤二设置宽高比一致的previewProfile配置信息，此处选择数组第一项仅供接口使用示例参考。
       previewOutput = cameraManager.createPreviewOutput(previewProfilesArray[0], surfaceId);
     } catch (error) {
       let err = error as BusinessError;
       console.error("Failed to create the PreviewOutput instance. error code: " + err.code);
     }
     return previewOutput;
   }
   ```

4. 使能。通过[Session.start](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#start11)方法输出预览流，接口调用失败会返回相应错误码，错误码类型参见[Camera错误码](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode)。
     
   ```ts
   async function startPreviewOutput(cameraManager: camera.CameraManager, previewOutput: camera.PreviewOutput): Promise<void> {
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
     await session.commitConfig();
     await session.start();
   }
   ```


## 状态监听

在相机应用开发过程中，可以随时监听预览输出流状态，包括预览流启动、预览流结束、预览流输出错误。

- 通过注册固定的frameStart回调函数获取监听预览启动结果，previewOutput创建成功时即可监听，预览第一次曝光时触发，有该事件返回结果则认为预览流已启动。
    
  ```ts
  function onPreviewOutputFrameStart(previewOutput: camera.PreviewOutput): void {
    previewOutput.on('frameStart', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('Preview frame started');
    });
  }
  ```

- 通过注册固定的frameEnd回调函数获取监听预览结束结果，previewOutput创建成功时即可监听，预览完成最后一帧时触发，有该事件返回结果则认为预览流已结束。
    
  ```ts
  function onPreviewOutputFrameEnd(previewOutput: camera.PreviewOutput): void {
    previewOutput.on('frameEnd', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('Preview frame ended');
    });
  }
  ```

- 通过注册固定的error回调函数获取监听预览输出错误结果，回调返回预览输出接口使用错误时对应的错误码，错误码类型参见[Camera错误码](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode)。
    
  ```ts
  function onPreviewOutputError(previewOutput: camera.PreviewOutput): void {
    previewOutput.on('error', (previewOutputError: BusinessError) => {
      console.error(`Preview output error code: ${previewOutputError.code}`);
    });
  }
  ```
