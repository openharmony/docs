# 会话管理

相机使用预览、拍照、录像、元数据功能前，均需要创建相机会话。

在会话中，可以完成以下功能：

- 配置相机的输入流和输出流。相机在拍摄前，必须完成输入输出流的配置。
  配置输入流即添加设备输入，对用户而言，相当于选择设备的某一摄像头拍摄；配置输出流，即选择数据将以什么形式输出。当应用需要实现拍照时，输出流应配置为预览流和拍照流，预览流的数据将显示在XComponent组件上，拍照流的数据将通过ImageReceiver接口的能力保存到相册中。

- 添加闪光灯、调整焦距等配置。具体支持的配置及接口说明请参考[Camera API参考](../reference/apis/js-apis-camera.md)。

- 会话切换控制。应用可以通过移除和添加输出流的方式，切换相机模式。如当前会话的输出流为拍照流，应用可以将拍照流移除，然后添加视频流作为输出流，即完成了拍照到录像的切换。

完成会话配置后，应用提交和开启会话，可以开始调用相机相关功能。

## 开发步骤

1. 调用cameraManager类中的createCaptureSession()方法创建一个会话。
     
   ```ts
   let captureSession;
   try {
       captureSession = cameraManager.createCaptureSession();
   } catch (error) {
       console.error('Failed to create the CaptureSession instance. errorCode = ' + error.code);
   }
   ```

2. 调用captureSession类中的beginConfig()方法配置会话。
     
   ```ts
   try {
       captureSession.beginConfig();
   } catch (error) {
       console.error('Failed to beginConfig. errorCode = ' + error.code);
   }
   ```

3. 使能。向会话中添加相机的输入流和输出流，调用captureSession.addInput()添加相机的输入流；调用captureSession.addOutput()添加相机的输出流。以下示例代码以添加预览流previewOutput和拍照流photoOutput为例，即当前模式支持拍照和预览。

     调用captureSession类中的commitConfig()和start()方法提交相关配置，并启动会话。
     
   ```ts
   try {
       captureSession.addInput(cameraInput);
   } catch (error) {
       console.error('Failed to addInput. errorCode = ' + error.code);
   }
   try {
       captureSession.addOutput(previewOutput);
   } catch (error) {
       console.error('Failed to addOutput(previewOutput). errorCode = ' + error.code);
   }
   try {
       captureSession.addOutput(photoOutput);
   } catch (error) {
       console.error('Failed to addOutput(photoOutput). errorCode = ' + error.code);
   }
   await captureSession.commitConfig() ;
   await captureSession.start().then(() => {
       console.info('Promise returned to indicate the session start success.');
   })
   ```

4. 会话控制。调用captureSession类中的stop()方法可以停止当前会话。调用removeOutput()和addOutput()方法可以完成会话切换控制。以下示例代码以移除拍照流photoOutput，添加视频流videoOutput为例，完成了拍照到录像的切换。
     
   ```ts
   await captureSession.stop();
   try {
       captureSession.beginConfig();
   } catch (error) {
       console.error('Failed to beginConfig. errorCode = ' + error.code);
   } 
   // 从会话中移除拍照输出流
   try {
       captureSession.removeOutput(photoOutput);
   } catch (error) {
       console.error('Failed to removeOutput(photoOutput). errorCode = ' + error.code);
   } 
   // 向会话中添加视频输出流
   try {
       captureSession.addOutput(videoOutput);
   } catch (error) {
       console.error('Failed to addOutput(videoOutput). errorCode = ' + error.code);
   }
   ```
