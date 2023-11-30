# 预览流二次处理(C/C++)

通过ImageReceiver创建预览输出，获取预览流实时数据，以供后续进行图像二次处理，比如应用可以对其添加滤镜算法等。

## 开发步骤

详细的API说明请参考[Camera API参考](../reference/native-apis/_o_h___camera.md)。

1. 导入NDK接口，接口中提供了相机相关的属性和方法，导入方法如下。
     
   ```c++
    // 导入NDK接口头文件 （参考ndk demo：在camera_manager.cpp中调用）
    #include "multimedia/camera_framework/camera.h"
    #include "multimedia/camera_framework/camera_input.h"
    #include "multimedia/camera_framework/capture_session.h"
    #include "multimedia/camera_framework/photo_output.h"
    #include "multimedia/camera_framework/preview_output.h"
    #include "multimedia/camera_framework/video_output.h"
    #include "multimedia/camera_framework/camera_manager.h"
   ```

2. 在CMake脚本中链接Camera NDK动态库。

   ```txt
    target_link_libraries(PUBLIC libohcamera.so)
   ```

3. 获取SurfaceId。
   
   通过image的createImageReceiver方法创建ImageReceiver实例，再通过实例的getReceivingSurfaceId方法获取SurfaceId，与预览输出流相关联，获取预览输出流的数据。
 
   ```ts
   async function getPreviewSurfaceId(): Promise<string | undefined> {
     let previewSurfaceId: string | undefined = undefined;
     let previewReceiver: image.ImageReceiver = image.createImageReceiver(320, 240, 2000, 8);
     console.info('before ImageReceiver check');
     if (previewReceiver !== undefined) {
       console.info('ImageReceiver is ok');
       previewSurfaceId = await previewReceiver.getReceivingSurfaceId();
       console.info(`ImageReceived id: ${JSON.stringify(previewSurfaceId)}`);
     } else {
       console.info('ImageReceiver is not ok');
     }
     return previewSurfaceId;
   }
   ```

4. 通过OH_CameraManager_GetSupportedCameraOutputCapability方法获取当前设备支持的预览能力。通过OH_CameraManager_CreatePreviewOutput方法创建预览输出流，其中，OH_CameraManager_CreatePreviewOutput方法中的参数分别是cameraManager指针，previewProfiles数组中的第一项，步骤二中获取的surfaceId，以及返回的previewOutput指针
     
   ```c++
    ret = OH_CameraManager_CreatePreviewOutput(cameraManager, previewProfile, previewSurfaceId, &previewOutput);
    if (previewProfile == nullptr || previewOutput == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
    }
   ```

5. 使能。当session完成CommitConfig后通过调用start()方法输出预览流，接口调用失败会返回相应错误码，错误码类型参见[Camera_ErrorCode]。
     
   ```c++
    ret = OH_PreviewOutput_Start(previewOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_Start failed.");
    }
   ```

6. 通过stop()方法停止预览流，接口调用失败会返回相应错误码，错误码类型参见[Camera_ErrorCode]。
     
   ```c++
    ret = OH_PreviewOutput_Stop(previewOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_Stop failed.");
    }
   ```

## 状态监听

在相机应用开发过程中，可以随时监听预览输出流状态，包括预览流启动、预览流结束、预览流输出错误。

- 通过注册固定的frameStart回调函数获取监听预览启动结果，previewOutput创建成功时即可监听，预览第一次曝光时触发，有该事件返回结果则认为预览流已启动。
    
  ```c++
    void PreviewOutputOnFrameStart(Camera_PreviewOutput* previewOutput)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutputOnFrameStart");
    }
    PreviewOutput_Callbacks* GetPreviewOutputListener(void)
    {
        static PreviewOutput_Callbacks previewOutputListener = {
            .onFrameStart = PreviewOutputOnFrameStart,
            .onFrameEnd = PreviewOutputOnFrameEnd,
            .onError = PreviewOutputOnError
        };
        return &previewOutputListener;
    }
    ret = OH_PreviewOutput_RegisterCallback(previewOutput_, GetPreviewOutputListener());
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_RegisterCallback failed.");
    }
  ```

- 通过注册固定的frameEnd回调函数获取监听预览结束结果，previewOutput创建成功时即可监听，预览完成最后一帧时触发，有该事件返回结果则认为预览流已结束。
    
  ```c++
    void PreviewOutputOnFrameEnd(Camera_PreviewOutput* previewOutput, int32_t frameCount)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutput frameCount = %{public}d", frameCount);
    }
  ```

- 通过注册固定的error回调函数获取监听预览输出错误结果，callback返回预览输出接口使用错误时对应的错误码，错误码类型参见[Camera_ErrorCode]。
    
  ```c++
    void PreviewOutputOnError(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutput errorCode = %{public}d", errorCode);
    }
  ```
