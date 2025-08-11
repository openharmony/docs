# Camera Metadata (C/C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

Metadata is the description and context of image information returned by the camera application. It provides detailed data for the image information, such as the coordinates of a viewfinder frame for identifying a portrait in a photo or video.

Metadata uses a tag (key) to find the corresponding data during the transfer of parameters and configurations, reducing memory copy operations.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/capi-oh-camera.md) for the API reference.

1. Import the NDK.

   ```c++
   // Include the NDK header files.
   #include "hilog/log.h"
   #include "ohcamera/camera.h"
   #include "ohcamera/camera_input.h"
   #include "ohcamera/capture_session.h"
   #include "ohcamera/photo_output.h"
   #include "ohcamera/preview_output.h"
   #include "ohcamera/video_output.h"
   #include "ohcamera/camera_manager.h"
   ```

2. Link the dynamic library in the CMake script.

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libohcamera.so
       libhilog_ndk.z.so
   )
   ```

3. Call **OH_CameraManager_GetSupportedCameraOutputCapability()** to obtain the metadata types supported by the current device, and then call **OH_CameraManager_CreateMetadataOutput()** to create a metadata output stream.
     
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

4. Call **start()** to start outputting metadata. If the call fails, an error code is returned.
     
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

5. Call **stop()** to stop outputting metadata. If the call fails, an error code is returned.
     
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

## Status Listening

During camera application development, you can listen for the status of metadata objects and output stream.

- Register the **'metadataObjectsAvailable'** event to listen for metadata objects that are available. When a valid metadata object is detected, the callback function returns the metadata. This event can be registered when a MetadataOutput object is created.
  ```c++
  void OnMetadataObjectAvailable(Camera_MetadataOutput* metadataOutput,
      Camera_MetadataObject* metadataObject, uint32_t size)
  {
      OH_LOG_INFO(LOG_APP, "size = %{public}d", size);
  }
  ```

  > **NOTE**
  >
  > Currently, only **FACE_DETECTION** is available for the metadata type. The metadata object is the rectangle of the recognized face, including the x-axis coordinate and y-axis coordinate of the upper left corner of the rectangle as well as the width and height of the rectangle.

- Register the **'error'** event to listen for metadata stream errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).

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
