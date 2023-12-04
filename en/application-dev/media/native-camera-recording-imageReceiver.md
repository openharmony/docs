# Secondary Processing of Video Streams (Native)

You can use the APIs in the **ImageReceiver** class to create a **VideoOutput** instance and obtain real-time data of the video stream for secondary processing. For example, you can add a filter algorithm to the preview stream.

## How to Develop

Read [Camera](../reference/apis/js-apis-camera.md) for the API reference.

1. Import the image module. The APIs provided by this module are used to obtain the surface ID and create a photo output stream.
     
   ```ts
   // Import the image module on the TS side.
   import image from '@ohos.multimedia.image';
   ```

2. Obtain the surface ID.
   
   Call **createImageReceiver()** of the image module to create an **ImageReceiver** instance, and use **getReceivingSurfaceId()** of the instance to obtain the surface ID, which is associated with the preview output stream to obtain the stream data.
 
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
              // Read the image.
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
3. Link the camera NDK dynamic library in the CMake script.

   ```txt
    target_link_libraries(PUBLIC libohcamera.so)
   ```

4. Import the NDK. The NDK is used for creating video output data, setting camera parameters, and triggering recording.

   ```c++
    // Include the NDK header files in camera_manager.cpp.
    #include "multimedia/camera_framework/camera.h"
    #include "multimedia/camera_framework/camera_input.h"
    #include "multimedia/camera_framework/capture_session.h"
    #include "multimedia/camera_framework/photo_output.h"
    #include "multimedia/camera_framework/preview_output.h"
    #include "multimedia/camera_framework/video_output.h"
    #include "multimedia/camera_framework/camera_manager.h"
   ```

5. Create a video output stream.

   Obtain the video output streams supported by the current device from **videoProfiles** in the **CameraOutputCapability** class. Then, define video recording parameters and use **createVideoOutput()** to create a video output stream.

   **NOTE**: The preview stream and video output stream must have the same aspect ratio of the resolution. For example, the aspect ratio in the code snippet below is 640:480 (which is equal to 4:3), then the aspect ratio of the resolution of the preview stream must also be 4:3. This means that the resolution can be 640:480, 960:720, 1440:1080, or the like.

  ```c++
    // Obtain the output streams supported by the camera.
    ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex],
                                                                &cameraOutputCapability);
    if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
    }
    if (cameraOutputCapability->videorofilesSize < 0) {
      console.error("videorofilesSize == null");
    }
    videoProfile = cameraOutputCapability->videoProfiles[0];
     // Create a VideoOutput instance.
    ret = OH_CameraManager_CreateVideoOutput(cameraManager, videoProfile, videoSurfaceId, &videoOutput);
    if (videoProfile == nullptr || videoOutput == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateVideoOutput failed.");
    }
   ```

6. Start video recording.
   
   Call **start()** of the **VideoOutput** instance to start the video output stream.

  ```c++
  // Start the video output stream.
  ret = OH_VideoOutput_Start(videoOutput);
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Start failed.");
  }
  ```

7. Stop video recording.
     
   Call **stop()** of the **VideoOutput** instance to stop the video output stream.

  ```c++
  // Stop the video output stream.
  ret = OH_VideoOutput_Stop(videoOutput);
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Stop failed.");
  }
  ```


## Status Listening

During camera application development, you can listen for the status of the video output stream, including recording start, recording end, and video output errors.

- Register the **'frameStart'** event to listen for recording start events. This event can be registered when a **VideoOutput** instance is created and is triggered when the bottom layer starts exposure for recording for the first time. Video recording starts as long as a result is returned.
    
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

- Register the **'frameEnd'** event to listen for recording end events. This event can be registered when a **VideoOutput** instance is created and is triggered when the last frame of recording ends. Video recording ends as long as a result is returned.
    
  ```c++
  void VideoOutputOnFrameEnd(Camera_VideoOutput* videoOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutput frameCount = %{public}d", frameCount);
  }
  ```

- Register the **'error'** event to listen for video output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
    
  ```c++
  void VideoOutputOnError(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutput errorCode = %{public}d", errorCode);
  }
  ```
