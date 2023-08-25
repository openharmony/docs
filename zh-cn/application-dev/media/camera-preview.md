# 预览

预览是启动相机后看见的画面，通常在拍照和录像前执行。

## 开发步骤

详细的API说明请参考[Camera API参考](../reference/apis/js-apis-camera.md)。

1. 创建Surface。
     
     XComponent组件为预览流提供的Surface，而XComponent的能力由UI提供，相关介绍可参考[XComponent组件参考](../reference/arkui-ts/ts-basic-components-xcomponent.md)。
     
   ```ts
   // 创建XComponentController 
   mXComponentController: XComponentController = new XComponentController;                   
   build() {
       Flex() {
           // 创建XComponent
           XComponent({                                                                     
               id: '',
               type: 'surface',
               libraryname: '',
               controller: this.mXComponentController
           })
           .onLoad(() => {                                                                  
               // 设置Surface宽高（1920*1080），预览尺寸设置参考前面 previewProfilesArray 获取的当前设备所支持的预览分辨率大小去设置
               this.mXComponentController.setXComponentSurfaceSize({surfaceWidth:1920,surfaceHeight:1080});
               // 获取Surface ID
               globalThis.surfaceId = this.mXComponentController.getXComponentSurfaceId();
           })
           .width('1920px')                                                                 
           .height('1080px')                                                                
       }
   }
   ```

2. 通过CameraOutputCapability类中的previewProfiles()方法获取当前设备支持的预览能力，返回previewProfilesArray数组 。通过createPreviewOutput()方法创建预览输出流，其中，createPreviewOutput()方法中的两个参数分别是previewProfilesArray数组中的第一项和步骤一中获取的surfaceId。
     
   ```ts
   let previewProfilesArray = cameraOutputCapability.previewProfiles;
   let previewOutput;
   try {
       previewOutput = cameraManager.createPreviewOutput(previewProfilesArray[0], surfaceId);
   } 
   catch (error) {
       console.error("Failed to create the PreviewOutput instance." + error);
   }
   ```

3. 使能。通过start()方法输出预览流，接口调用失败会返回相应错误码，错误码类型参见[CameraErrorCode](../reference/apis/js-apis-camera.md#cameraerrorcode)。
     
   ```ts
   previewOutput.start().then(() => {
       console.info('Callback returned with previewOutput started.');
   }).catch((err) => {
       console.info('Failed to previewOutput start '+ err.code);
   });
   ```


## 状态监听

在相机应用开发过程中，可以随时监听预览输出流状态，包括预览流启动、预览流结束、预览流输出错误。

- 通过注册固定的frameStart回调函数获取监听预览启动结果，previewOutput创建成功时即可监听，预览第一次曝光时触发，有该事件返回结果则认为预览流已启动。
    
  ```ts
  previewOutput.on('frameStart', () => {
      console.info('Preview frame started');
  })
  ```

- 通过注册固定的frameEnd回调函数获取监听预览结束结果，previewOutput创建成功时即可监听，预览完成最后一帧时触发，有该事件返回结果则认为预览流已结束。
    
  ```ts
  previewOutput.on('frameEnd', () => {
      console.info('Preview frame ended');
  })
  ```

- 通过注册固定的error回调函数获取监听预览输出错误结果，callback返回预览输出接口使用错误时对应的错误码，错误码类型参见[CameraErrorCode](../reference/apis/js-apis-camera.md#cameraerrorcode)。
    
  ```ts
  previewOutput.on('error', (previewOutputError) => {
      console.info(`Preview output error code: ${previewOutputError.code}`);
  })
  ```
