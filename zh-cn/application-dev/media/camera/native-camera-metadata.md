# 元数据(C/C++)

元数据（Metadata）是对相机返回的图像信息数据的描述和上下文，针对图像信息，提供的更详细的数据，如照片或视频中，识别人像的取景框坐标等信息。

Metadata主要是通过一个TAG（Key），去找对应的Data，用于传递参数和配置信息，减少内存拷贝操作。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/capi-oh-camera.md)。

1. 导入NDK接口，导入方法如下。

   ```c++
   // 导入NDK接口头文件。
   #include "hilog/log.h"
   #include "ohcamera/camera.h"
   #include "ohcamera/camera_input.h"
   #include "ohcamera/capture_session.h"
   #include "ohcamera/photo_output.h"
   #include "ohcamera/preview_output.h"
   #include "ohcamera/video_output.h"
   #include "ohcamera/camera_manager.h"
   ```

2. 在CMake脚本中链接相关动态库。

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libohcamera.so
       libhilog_ndk.z.so
   )
   ```

3. 调用OH_CameraManager_GetSupportedCameraOutputCapability()方法，获取当前设备支持的元数据类型metaDataObjectType，并通过OH_CameraManager_CreateMetadataOutput()方法创建元数据输出流。
     
   ```c++
   Camera_MetadataOutput* CreateMetadataOutput(Camera_Manager* cameraManager,
       Camera_OutputCapability* cameraOutputCapability)
   {
       Camera_MetadataOutput* metadataOutput = nullptr;
       if (cameraOutputCapability->supportedMetadataObjectTypes == nullptr) {
           return metadataOutput;
       }
       Camera_MetadataObjectType* metaDataObjectType = nullptr;
       bool isSupported = false;
       for (int index = 0; index < cameraOutputCapability->metadataProfilesSize; index++) {
           if (cameraOutputCapability->supportedMetadataObjectTypes[index] != nullptr &&
               *cameraOutputCapability->supportedMetadataObjectTypes[index] == FACE_DETECTION) {
               metaDataObjectType = *cameraOutputCapability->supportedMetadataObjectTypes;
               isSupported = true;
               break;
           }
       }
       if (!isSupported || metaDataObjectType == nullptr) {
           OH_LOG_ERROR(LOG_APP, "FACE_DETECTION is not supported.");
           return metadataOutput;
       }
       
       Camera_ErrorCode ret = OH_CameraManager_CreateMetadataOutput(cameraManager, metaDataObjectType, &metadataOutput);
       if (metadataOutput == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "CreateMetadataOutput failed.");
       }
       return metadataOutput;
   }
   ```

4. 调用start()方法输出metadata数据，接口调用失败时，会返回相应错误码。
     
   ```c++
   Camera_ErrorCode StartMetadataOutput(Camera_MetadataOutput* metadataOutput)
   {
       Camera_ErrorCode ret = OH_MetadataOutput_Start(metadataOutput);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_MetadataOutput_Start failed.");
       }
       return ret;
   }
   ```

5. 调用stop()方法停止输出metadata数据，接口调用失败会返回相应错误码。
     
   ```c++
   Camera_ErrorCode StopMetadataOutput(Camera_MetadataOutput* metadataOutput)
   {
       Camera_ErrorCode ret = OH_MetadataOutput_Stop(metadataOutput);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_MetadataOutput_Stop failed.");
       }
       return ret;
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
  ```

  > **说明：**
  >
  > 当前的元数据类型仅支持人脸检测（FACE_DETECTION）功能。元数据信息对象为识别到的人脸区域的矩形信息（Rect），包含矩形区域的左上角x坐标、y坐标和矩形的宽高数据。

- 通过注册回调函数，获取监听metadata流的错误结果，callback返回metadata输出接口使用错误时返回的错误码，错误码类型参见[Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode)。

  ```c++
  void OnMetadataOutputError(Camera_MetadataOutput* metadataOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "OnMetadataOutput errorCode = %{public}d", errorCode);
  }
  ```

  ```c++
  MetadataOutput_Callbacks* GetMetadataOutputListener(void)
  {
      static MetadataOutput_Callbacks metadataOutputListener = {
          .onMetadataObjectAvailable = OnMetadataObjectAvailable,
          .onError = OnMetadataOutputError
      };
      return &metadataOutputListener;
  }
  Camera_ErrorCode RegisterMetadataOutputCallback(Camera_MetadataOutput* metadataOutput)
  {
      Camera_ErrorCode ret = OH_MetadataOutput_RegisterCallback(metadataOutput, GetMetadataOutputListener());
      if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_MetadataOutput_RegisterCallback failed.");
      }
      return ret;
  }
  ```