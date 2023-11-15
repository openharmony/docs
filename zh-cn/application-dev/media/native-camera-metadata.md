# 元数据(Native)

元数据（Metadata）是对相机返回的图像信息数据的描述和上下文，针对图像信息，提供的更详细的数据，如照片或视频中，识别人像的取景框坐标等信息。

Metadata主要是通过一个TAG（Key），去找对应的Data，用于传递参数和配置信息，减少内存拷贝操作。

## 开发步骤

详细的API说明请参考[Camera API参考]。

1. 导入NDK接口，导入方法如下。
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

3. 调用OH_CameraManager_GetSupportedCameraOutputCapability方法，获取当前设备支持的元数据类型metaDataObjectType，并通过OH_CameraManager_CreateMetadataOutput方法创建元数据输出流。
     
   ```c++
    Camera_ErrorCode ret = OH_CameraManager_CreateMetadataOutput(cameraManager_, metaDataObjectType, &metadataOutput);
    if (previewProfile == nullptr || previewOutput == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
    }
   ```

4. 调用start()方法输出metadata数据，接口调用失败时，会返回相应错误码，错误码类型参见CameraErrorCode。
     
   ```c++
    ret = OH_MetadataOutput_Start(metadataOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MetadataOutput_Start failed.");
    }
   ```

5. 调用stop方法停止输出metadata数据，接口调用失败会返回相应错误码，错误码类型参见CameraErrorCode。
     
   ```c++
    ret = OH_MetadataOutput_Stop(metadataOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MetadataOutput_Stop failed.");
    }
   ```

## 状态监听

在相机应用开发过程中，可以随时监听metadata数据以及输出流的状态。

- 通过注册监听获取metadata对象，监听事件固定为metadataObjectsAvailable。检测到有效metadata数据时，callback返回相应的metadata数据信息，metadataOutput创建成功时可监听。
    
  ```c++
  void OnMetadataObjectAvailable(Camera_MetadataOutput* metadataOutput,
      Camera_MetadataObject* metadataObject, uint32_t size)
  {
      OH_LOG_INFO(LOG_APP, "size = %{public}d", size);
  }

  MetadataOutput_Callbacks* GetMetadataOutputListener(void)
  {
      static MetadataOutput_Callbacks metadataOutputListener = {
          .onMetadataObjectAvailable = OnMetadataObjectAvailable,
          .onError = OnMetadataOutputError
      };
      return &metadataOutputListener;
  }
  ret = OH_MetadataOutput_RegisterCallback(metadataOutput_, GetMetadataOutputListener());
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MetadataOutput_RegisterCallback failed.");
  }
  ```

  > **说明：**
  >
  > 当前的元数据类型仅支持人脸检测（FACE_DETECTION）功能。元数据信息对象为识别到的人脸区域的矩形信息（Rect），包含矩形区域的左上角x坐标、y坐标和矩形的宽高数据。

- 通过注册回调函数，获取监听metadata流的错误结果，callback返回metadata输出接口使用错误时返回的错误码，错误码类型参见[Camera_ErrorCode]。
    
  ```c++
  void OnMetadataOutputError(Camera_MetadataOutput* metadataOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "OnMetadataOutput errorCode = %{public}d", errorCode);
  }
  ```

## 相关实例

针对元数据，有以下相关实例可供参考：
- [元数据(Native)](https://gitee.com/openharmony/multimedia_camera_framework/tree/master/frameworks/native/camera/test/ndktest/camera_ndk_demo)