# 录像

录像也是相机应用的最重要功能之一，录像是循环帧的捕获。对于录像的流畅度，开发者可以参考[拍照](camera-shooting.md)中的步骤4，设置分辨率、闪光灯、焦距、照片质量及旋转角度等信息。

## 开发步骤

详细的API说明请参考[Camera API参考](../reference/apis/js-apis-camera.md)。

1. 导入media模块。创建拍照输出流的SurfaceId以及拍照输出的数据，都需要用到系统提供的[media接口](../reference/apis/js-apis-media.md)能力，导入media接口的方法如下。
     
   ```ts
   import media from '@ohos.multimedia.media';
   ```

2. 创建Surface。
   
   系统提供的media接口可以创建一个录像AVRecorder实例，通过该实例的getInputSurface方法获取SurfaceId，与录像输出流做关联，处理录像输出流输出的数据。
 
   ```ts
   let AVRecorder;
   media.createAVRecorder((error, recorder) => {
      if (recorder != null) {
          AVRecorder = recorder;
          console.info('createAVRecorder success');
      } else {
          console.info(`createAVRecorder fail, error:${error}`);
      }
   });
   // AVRecorderConfig可参考下一章节
   AVRecorder.prepare(AVRecorderConfig, (err) => {
      if (err == null) {
          console.log('prepare success');
      } else {
          console.log('prepare failed and error is ' + err.message);
      }
   })

   let videoSurfaceId = null; 
   AVRecorder.getInputSurface().then((surfaceId) => {
      console.info('getInputSurface success');
      videoSurfaceId = surfaceId; 
   }).catch((err) => {
      console.info('getInputSurface failed and catch error is ' + err.message); 
   });
   ```

3. 创建录像输出流。
     
    通过CameraOutputCapability类中的videoProfiles，可获取当前设备支持的录像输出流。然后，定义创建录像的参数，通过createVideoOutput方法创建录像输出流。
     
   ```ts
   let videoProfilesArray = cameraOutputCapability.videoProfiles;
   if (!videoProfilesArray) {
       console.error("createOutput videoProfilesArray == null || undefined");
   } 
   
   // 创建视频录制的参数
   let videoConfig = {
       videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
       profile: {
           fileFormat : media.ContainerFormatType.CFT_MPEG_4, // 视频文件封装格式，只支持MP4
           videoBitrate : 100000, // 视频比特率
           videoCodec : media.CodecMimeType.VIDEO_MPEG4, // 视频文件编码格式，支持mpeg4和avc两种格式
           videoFrameWidth : 640,  // 视频分辨率的宽
           videoFrameHeight : 480, // 视频分辨率的高
           videoFrameRate : 30 // 视频帧率
       },
       url: 'fd://35',
       rotation: 0
   } 
   // 创建avRecorder
   let avRecorder;
   media.createAVRecorder((error, recorder) => {
     if (recorder != null) {
         avRecorder = recorder;
         console.info('createAVRecorder success');
     } else {
         console.info(`createAVRecorder fail, error:${error}`);
     }
    });
   // 设置视频录制的参数
   avRecorder.prepare(videoConfig);
   // 创建VideoOutput对象
   let videoOutput;
   try {
       videoOutput = cameraManager.createVideoOutput(videoProfilesArray[0], videoSurfaceId);
   } catch (error) {
       console.error('Failed to create the videoOutput instance. errorCode = ' + error.code);
   }
   ```

4. 开始录像。
   
   先通过videoOutput的start方法启动录像输出流，再通过avRecorder的start方法开始录像。

   ```
   videoOutput.start(async (err) => {
       if (err) {
           console.error('Failed to start the video output ${err.message}');
           return;
       }
       console.info('Callback invoked to indicate the video output start success.');
   });
    
   avRecorder.start().then(() => {
       console.info('avRecorder start success');
   }
   ```

5. 停止录像。
     
   先通过avRecorder的stop方法停止录像，再通过videoOutput的stop方法停止录像输出流。
     
   ```ts
   videoRecorder.stop().then(() => {
       console.info('stop success');
   }
   
   videoOutput.stop((err) => {
       if (err) {
           console.error('Failed to stop the video output ${err.message}');
           return;
       }
       console.info('Callback invoked to indicate the video output stop success.');
   });
   ```


## 状态监听

在相机应用开发过程中，可以随时监听录像输出流状态，包括录像开始、录像结束、录像流输出的错误。

- 通过注册固定的frameStart回调函数获取监听录像开始结果，videoOutput创建成功时即可监听，录像第一次曝光时触发，有该事件返回结果则认为录像开始。
    
  ```ts
  videoOutput.on('frameStart', () => {
      console.info('Video frame started');
  })
  ```

- 通过注册固定的frameEnd回调函数获取监听录像结束结果，videoOutput创建成功时即可监听，录像完成最后一帧时触发，有该事件返回结果则认为录像流已结束。
    
  ```ts
  videoOutput.on('frameEnd', () => {
      console.info('Video frame ended');
  })
  ```

- 通过注册固定的error回调函数获取监听录像输出错误结果，callback返回预览输出接口使用错误时对应的错误码，错误码类型参见[CameraErrorCode](../reference/apis/js-apis-camera.md#cameraerrorcode)。
    
  ```ts
  videoOutput.on('error', (error) => {
      console.info(`Video output error code: ${error.code}`);
  })
  ```
