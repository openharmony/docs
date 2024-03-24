# 元数据(C/C++)

元数据（Metadata）是对相机返回的图像信息数据的描述和上下文，针对图像信息，提供的更详细的数据，如照片或视频中，识别人像的取景框坐标等信息。

Metadata主要是通过一个TAG（Key），去找对应的Data，用于传递参数和配置信息，减少内存拷贝操作。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/_o_h___camera.md)。

1. 导入NDK接口，导入方法如下。

   ```c++
    // 导入NDK接口头文件
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
    target_link_libraries(entry PUBLIC libohcamera.so libhilog_ndk.z.so)
   ```

3. 调用OH_CameraManager_GetSupportedCameraOutputCapability()方法，获取当前设备支持的元数据类型metaDataObjectType，并通过OH_CameraManager_CreateMetadataOutput()方法创建元数据输出流。
     
   ```c++
    Camera_Manager *cameraManager = nullptr;
    Camera_Device* cameras = nullptr;
    Camera_OutputCapability* cameraOutputCapability = nullptr;
    Camera_MetadataOutput* metadataOutput = nullptr;
    const Camera_MetadataObjectType* metaDataObjectType;
    uint32_t size = 0;
    uint32_t cameraDeviceIndex = 0;
    char* previewSurfaceId = nullptr;
    Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
    if (cameraManager == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraManager failed.");
    }
    ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
    if (cameras == nullptr || size < 0 || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
    }
    ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex],
                                                                      &cameraOutputCapability);
    if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
    }
    if (cameraOutputCapability->previewProfilesSize < 0) {
        OH_LOG_ERROR(LOG_APP, "previewProfilesSize == null");
    }
    metaDataObjectType = cameraOutputCapability->supportedMetadataObjectTypes[2]; // 2:camera metedata types
    if (metaDataObjectType == nullptr) {
        OH_LOG_ERROR(LOG_APP, "Get metaDataObjectType failed.");
    }
    
    ret = OH_CameraManager_CreateMetadataOutput(cameraManager, metaDataObjectType, &metadataOutput);
    if (metadataOutput == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "CreateMetadataOutput failed.");
    }
   ```

4. 调用start()方法输出metadata数据，接口调用失败时，会返回相应错误码。
     
   ```c++
    ret = OH_MetadataOutput_Start(metadataOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_MetadataOutput_Start failed.");
    }
   ```

5. 调用stop()方法停止输出metadata数据，接口调用失败会返回相应错误码。
     
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
    ret = OH_MetadataOutput_RegisterCallback(metadataOutput, GetMetadataOutputListener());
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_MetadataOutput_RegisterCallback failed.");
    }
  ```
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
  ```

  > **说明：**
  >
  > 当前的元数据类型仅支持人脸检测（FACE_DETECTION）功能。元数据信息对象为识别到的人脸区域的矩形信息（Rect），包含矩形区域的左上角x坐标、y坐标和矩形的宽高数据。

- 通过注册回调函数，获取监听metadata流的错误结果，callback返回metadata输出接口使用错误时返回的错误码，错误码类型参见[Camera_ErrorCode](../../reference/apis-camera-kit/_o_h___camera.md#camera_errorcode-1)。
    
  ```c++
    void OnMetadataOutputError(Camera_MetadataOutput* metadataOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "OnMetadataOutput errorCode = %{public}d", errorCode);
    }
  ```