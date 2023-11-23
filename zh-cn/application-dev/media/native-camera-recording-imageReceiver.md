# 录像流二次处理(Native)

通过ImageReceiver创建录像输出，获取录像流实时数据，以供后续进行图像二次处理，比如应用可以对其添加滤镜算法等。

## 开发步骤

详细的API说明请参考[Camera API参考]。

1. 导入image模块。创建拍照输出流的SurfaceId以及录像输出的数据，都需要用到系统提供的image接口能力，导入image接口的方法如下。
     
   ```ts
   // ts侧需要导入image接口
   import image from '@ohos.multimedia.image';
   ```

2. 获取SurfaceId。
   
   通过image的createImageReceiver方法创建ImageReceiver实例，再通过实例的getReceivingSurfaceId方法获取SurfaceId，与录像输出流相关联，获取录像输出流的数据。
 
   ```ts
   async function getVideoSurfaceId(): Promise<string | undefined> {
      let videoSurfaceId: string | undefined = undefined;
      let videoReceiver: image.ImageReceiver = image.createImageReceiver(320, 240, 2000, 8);
      try {
        videoReceiver.on('imageArrival', () => {
          console.info('imageArrival start');
          videoReceiver.readNextImage((err, image) => {
            console.info('readNextImage start');
            if (err || image === undefined) {
              console.error('readNextImage failed');
              return;
            }
            image.getComponent(4, (errMsg, img) => {
              console.info('getComponent start');
              if (errMsg || img === undefined) {
                console.error('getComponent failed');
                return;
              }
              let buffer;
              if (img.byteBuffer) {
                buffer = img.byteBuffer;
              } else {
                console.error('img.byteBuffer is undefined');
              }
              // 读取图像
              try {
                console.info('savePicture start');
                let imgFileAsset = await this.mediaUtil.createAndGetUri(mediaLibrary.MediaType.IMAGE);
                let imgPhotoUri = imgFileAsset.uri;
                let imgFd = await this.mediaUtil.getFdPath(imgFileAsset);
                await fileio.write(imgFd, buffer);
                await imgFileAsset.close(imgFd);
                await img.release();
                console.info('save image End');
              } catch (err) {
                console.error('savePicture err');
              }
            })
          })
        })
      } catch {
        console.error('savePicture err');
    }
     console.info('before ImageReceiver check');
     if (videoReceiver !== undefined) {
       console.info('ImageReceiver is ok');
       videoSurfaceId = await videoReceiver.getReceivingSurfaceId();
       console.info(`ImageReceived id: ${JSON.stringify(videoSurfaceId)}`);
     } else {
       console.info('ImageReceiver is not ok');
     }
     return videoSurfaceId;
   }
   ```
3. 在CMake脚本中链接Camera NDK动态库。

   ```txt
    target_link_libraries(PUBLIC libohcamera.so)
   ```

4. 导入NDK接口。创建录像输出数据、配置相机参数以及触发录像流程，都需要用到系统提供的NDK接口能力，导入NDK接口的方法如下。

   ```c++
    //导入NDK接口头文件 （参考ndk demo：在camera_manager.cpp中调用）
    #include "multimedia/camera_framework/camera.h"
    #include "multimedia/camera_framework/camera_input.h"
    #include "multimedia/camera_framework/capture_session.h"
    #include "multimedia/camera_framework/photo_output.h"
    #include "multimedia/camera_framework/preview_output.h"
    #include "multimedia/camera_framework/video_output.h"
    #include "multimedia/camera_framework/camera_manager.h"
   ```

5. 创建录像输出流。

   通过CameraOutputCapability类中的videoProfiles，可获取当前设备支持的录像输出流。然后，定义创建录像的参数，通过createVideoOutput方法创建录像输出流。

   **注**：预览流与录像输出流的分辨率的宽高比要保持一致，如示例代码中宽高比为640:480 = 4:3，则需要预览流中的分辨率的宽高比也为4:3，如分辨率选择640:480，或960:720，或1440:1080，以此类推

  ```c++
    // 获取相机设备支持的输出流能力
    ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex],
                                                                &cameraOutputCapability);
    if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
    }
    if (cameraOutputCapability->videorofilesSize < 0) {
      console.error("videorofilesSize == null");
    }
    videoProfile = cameraOutputCapability->videoProfiles[0];
     // 创建VideoOutput对象
    ret = OH_CameraManager_CreateVideoOutput(cameraManager, videoProfile, videoSurfaceId, &videoOutput);
    if (videoProfile == nullptr || videoOutput == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateVideoOutput failed.");
    }
   ```

6. 开始录像。
   
   通过videoOutput的start方法启动录像输出流。

  ```c++
  // 启动录像输出流
  ret = OH_VideoOutput_Start(videoOutput);
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Start failed.");
  }
  ```

7. 停止录像。
     
   通过videoOutput的stop方法停止录像输出流。

  ```c++
  // 停止录像输出流
  ret = OH_VideoOutput_Stop(videoOutput);
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Stop failed.");
  }
  ```


## 状态监听

在相机应用开发过程中，可以随时监听录像输出流状态，包括录像开始、录像结束、录像流输出的错误。

- 通过注册固定的frameStart回调函数获取监听录像开始结果，videoOutput创建成功时即可监听，录像第一次曝光时触发，有该事件返回结果则认为录像开始。
    
  ```c++
  void VideoOutputOnFrameStart(Camera_VideoOutput* videoOutput)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutputOnFrameStart");
  }

  VideoOutput_Callbacks* GetVideoOutputListener(void)
  {
      static VideoOutput_Callbacks videoOutputListener = {
          .onFrameStart = VideoOutputOnFrameStart,
          .onFrameEnd = VideoOutputOnFrameEnd,
          .onError = VideoOutputOnError
      };
      return &videoOutputListener;
  }
  ret = OH_VideoOutput_RegisterCallback(videoOutput_, GetVideoOutputListener());
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_RegisterCallback failed.");
  }
  ```

- 通过注册固定的frameEnd回调函数获取监听录像结束结果，videoOutput创建成功时即可监听，录像完成最后一帧时触发，有该事件返回结果则认为录像流已结束。
    
  ```c++
  void VideoOutputOnFrameEnd(Camera_VideoOutput* videoOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutput frameCount = %{public}d", frameCount);
  }
  ```

- 通过注册固定的error回调函数获取监听录像输出错误结果，callback返回预览输出接口使用错误时对应的错误码，错误码类型参见[Camera_ErrorCode]。
    
  ```c++
  void VideoOutputOnError(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutput errorCode = %{public}d", errorCode);
  }
  ```
