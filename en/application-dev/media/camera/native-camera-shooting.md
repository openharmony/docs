# Photo Capture (C/C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Photo capture is an important function of the camera application. Based on the complex logic of the camera device, the camera module provides APIs for you to set information such as resolution, flash, focal length, photo quality, and rotation angle.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/capi-oh-camera.md) for the API reference.

1. Import the NDK, which provides camera-related properties and methods.

   ```c++
   // Include the NDK header files.
   #include <cstdint>
   #include <cstdlib>
   #include <cstring>
   #include <string.h>
   #include <new>
   #include "hilog/log.h"
   #include "ohcamera/camera.h"
   #include "ohcamera/camera_input.h"
   #include "ohcamera/capture_session.h"
   #include "ohcamera/photo_output.h"
   #include "ohcamera/preview_output.h"
   #include "ohcamera/video_output.h"
   #include "ohcamera/camera_manager.h"
   #include <multimedia/image_framework/image/image_native.h>
   ```

2. Link the dynamic library in the CMake script.

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libhilog_ndk.z.so
       libnative_buffer.so
       libohcamera.so
       libohimage.so
       libohfileuri.so
   )
   ```

3. Create and open a camera device. For details, see steps 3 to 5 in [Device Input Management (C/C++)](./native-camera-device-input.md).

4. Select the output stream capability supported by the camera device and create a photo output stream.

   Call [OH_CameraManager_CreatePhotoOutputWithoutSurface()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_createphotooutputwithoutsurface) to create a photo output stream.

   ```c++
   Camera_PhotoOutput* CreatePhotoOutput(Camera_Manager* cameraManager, const Camera_Profile* photoProfile) {
       Camera_PhotoOutput* photoOutput = nullptr;
       // Create a photo output stream without passing a surface ID.
       Camera_ErrorCode ret = OH_CameraManager_CreatePhotoOutputWithoutSurface(cameraManager, photoProfile, &photoOutput);
       if (photoOutput == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePhotoOutputWithoutSurface failed.");
       }
       return photoOutput;
   }
   ```

5. Register a one-time photo capture callback, which is defined as **PhotoAvailable**. If your application requires rapid image display, use the deferred photo delivery callback, which is defined as [PhotoAssetAvailable](./native-camera-deferred-capture.md).

   > **NOTE**
   >
   > If the **PhotoAssetAvailable** callback has been registered and the **PhotoAvailable** callback is registered after the session starts, the stream will be restarted. In this case, only the **PhotoAssetAvailable** callback takes effect.
   >
   > Therefore, you are not advised to register both **PhotoAssetAvailable** and **PhotoAvailable**.

   The development process is as follows:

   - Register the callback before the session commits the configuration.
   - Obtain the image information from the callback, parse the buffer data, and perform custom service processing.
   - Pass the processed buffer to the ArkTS side through the callback for image display or storage (using a security component).
   - Unregister the callback when it is no longer required.

   ```c++
   // Save the buffer processing callback registered on the NAPI side.
   static void* bufferCb = nullptr;
   Camera_ErrorCode RegisterBufferCb(void* cb) {
       OH_LOG_INFO(LOG_APP, " RegisterBufferCb start");
       if (cb == nullptr) {
           OH_LOG_INFO(LOG_APP, " RegisterBufferCb invalid error");
           return CAMERA_INVALID_ARGUMENT;
       }
       bufferCb = cb;
       return CAMERA_OK;
   }

   // One-time photo capture callback.
   void OnPhotoAvailable(Camera_PhotoOutput* photoOutput, OH_PhotoNative* photo) {
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable start!");
       OH_ImageNative* imageNative;
       Camera_ErrorCode errCode = OH_PhotoNative_GetMainImage(photo, &imageNative);
       if (errCode != CAMERA_OK || imageNative == nullptr) {
           OH_LOG_ERROR(LOG_APP, "OH_PhotoNative_GetMainImage call failed, errorCode: %{public}d", errCode);
           return;
       }
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable errCode:%{public}d imageNative:%{public}p", errCode, imageNative);
       // Read the size attribute of OH_ImageNative.
       Image_Size size;
       Image_ErrorCode imageErr = OH_ImageNative_GetImageSize(imageNative, &size);
       if (imageErr != IMAGE_SUCCESS) {
            OH_LOG_ERROR(LOG_APP, "OH_ImageNative_GetImageSize call failed, errorCode: %{public}d", imageErr);
            OH_ImageNative_Release(imageNative);
            return;
        }
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d width:%{public}d height:%{public}d", imageErr,
                    size.width, size.height);
       // Read the number of elements in the component list of OH_ImageNative.
       size_t componentTypeSize = 0;
       imageErr = OH_ImageNative_GetComponentTypes(imageNative, nullptr, &componentTypeSize);
       if (imageErr != IMAGE_SUCCESS || componentTypeSize == 0) {
           OH_LOG_ERROR(LOG_APP, "cOH_ImageNative_GetComponentTypes call failed, errorCode: %{public}d", imageErr);
           OH_ImageNative_Release(imageNative);
           return;
       }
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d componentTypeSize:%{public}zu", imageErr,
                    componentTypeSize);
       // Read the component list of OH_ImageNative.
       uint32_t* components = new (std::nothrow) uint32_t[componentTypeSize];
       if (!components) {
           OH_LOG_ERROR(LOG_APP, "Failed to allocate memory");
           OH_ImageNative_Release(imageNative);
           return;
       }
       imageErr = OH_ImageNative_GetComponentTypes(imageNative, &components, &componentTypeSize);
       if (imageErr != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_ImageNative_GetComponentTypes call failed, errorCode: %{public}d", imageErr);
           OH_ImageNative_Release(imageNative);
           delete[] components;
           return;
       }
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable OH_ImageNative_GetComponentTypes imageErr:%{public}d", imageErr);
       // Read the buffer object corresponding to the first component of OH_ImageNative.
       OH_NativeBuffer* nativeBuffer = nullptr;
       imageErr = OH_ImageNative_GetByteBuffer(imageNative, components[0], &nativeBuffer);
       if (imageErr != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_ImageNative_GetByteBuffer call failed, errorCode: %{public}d", imageErr);
           OH_ImageNative_Release(imageNative);
           delete[] components;
           return;
       }
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable OH_ImageNative_GetByteBuffer imageErr:%{public}d", imageErr);
       // Read the size of the buffer corresponding to the first component of OH_ImageNative.
       size_t nativeBufferSize = 0;
       imageErr = OH_ImageNative_GetBufferSize(imageNative, components[0], &nativeBufferSize);
       if (imageErr != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_ImageNative_GetBufferSize call failed, errorCode: %{public}d", imageErr);
           OH_ImageNative_Release(imageNative);
           delete[] components;
           return;
       }
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d nativeBufferSize:%{public}zu", imageErr,
                    nativeBufferSize);
       // Read the row stride corresponding to the first component of OH_ImageNative.
       int32_t rowStride = 0;
       imageErr = OH_ImageNative_GetRowStride(imageNative, components[0], &rowStride);
       if (imageErr != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_ImageNative_GetRowStride call failed, errorCode: %{public}d", imageErr);
           OH_ImageNative_Release(imageNative);
           delete[] components;
           return;
       }
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d rowStride:%{public}d", imageErr, rowStride);
       // Read the pixel stride corresponding to the first component of OH_ImageNative.
       int32_t pixelStride = 0;
       imageErr = OH_ImageNative_GetPixelStride(imageNative, components[0], &pixelStride);
       if (imageErr != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_ImageNative_GetPixelStride call failed, errorCode: %{public}d", imageErr);
           OH_ImageNative_Release(imageNative);
           delete[] components;
           return;
       }
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d pixelStride:%{public}d", imageErr, pixelStride);
       // Map the ION memory to the process address space.
       void* virAddr = nullptr; // Point to the virtual address of the mapped memory. After unmapping, the pointer is invalid.
       int32_t ret = OH_NativeBuffer_Map(nativeBuffer, &virAddr); // After mapping, the start address of the memory is returned through the parameter virAddr.
       if (ret != 0) {
           OH_LOG_ERROR(LOG_APP, "OH_NativeBuffer_Map call failed, errorCode: %{public}d", ret);
           OH_ImageNative_Release(imageNative);
           delete[] components;
           return;
       }
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable OH_NativeBuffer_Map err:%{public}d", ret);
       // Call the buffer callback at the NAPI layer.
       auto cb = (void (*)(void *, size_t))(bufferCb);
       if (!virAddr || nativeBufferSize <= 0) {
         OH_LOG_INFO(LOG_APP, "On buffer callback failed");
         return;
       }
       cb(virAddr, nativeBufferSize);
       // Release resources.
       delete[] components;
       ret = OH_ImageNative_Release(imageNative);
       if (ret != 0) {
           OH_LOG_ERROR(LOG_APP, "OH_ImageNative_Release call failed., errorCode: %{public}d", ret);
       }
       ret = OH_NativeBuffer_Unmap(nativeBuffer); // After the processing is complete, unmap and release the buffer.
       if (ret != 0) {
           OH_LOG_ERROR(LOG_APP, "OH_NativeBuffer_Unmap call failed, errorCode: %{public}d", ret);
       }
	   OH_LOG_INFO(LOG_APP, "OnPhotoAvailable end");
   }

   // Register the PhotoAvailableCallback callback.
   Camera_ErrorCode PhotoOutputRegisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput) {
       OH_LOG_INFO(LOG_APP, "PhotoOutputRegisterPhotoAvailableCallback start!");
       Camera_ErrorCode ret = OH_PhotoOutput_RegisterPhotoAvailableCallback(photoOutput, OnPhotoAvailable);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "PhotoOutputRegisterPhotoAvailableCallback failed.");
       }
       OH_LOG_INFO(LOG_APP, "PhotoOutputRegisterPhotoAvailableCallback return with ret code: %{public}d!", ret);
       return ret;
   }

   // Unregister the PhotoAvailableCallback callback.
   Camera_ErrorCode PhotoOutputUnRegisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput) {
       OH_LOG_INFO(LOG_APP, "PhotoOutputUnRegisterPhotoAvailableCallback start!");
       Camera_ErrorCode ret = OH_PhotoOutput_UnregisterPhotoAvailableCallback(photoOutput, OnPhotoAvailable);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "PhotoOutputUnRegisterPhotoAvailableCallback failed.");
       }
       OH_LOG_INFO(LOG_APP, "PhotoOutputUnRegisterPhotoAvailableCallback return with ret code: %{public}d!", ret);
       return ret;
   }
   ```

   Sample code for buffer processing at the NAPI layer:

   ```c++
   static napi_ref bufferCbRef_ = nullptr;
   static napi_env env_;
   size_t g_size = 0;
   
   // Buffer callback at the NAPI layer.
   static void BufferCb(void* buffer, size_t size) {
       OH_LOG_INFO(LOG_APP, "BufferCb size:%{public}zu", size);
       g_size = size;
       napi_value asyncResource = nullptr;
       napi_value asyncResourceName = nullptr;
       napi_async_work work;

       void* copyBuffer = malloc(size);
       if (copyBuffer == nullptr) {
           return;
       }
       OH_LOG_INFO(LOG_APP, "BufferCb copyBuffer:%{public}p", copyBuffer);
       // Use std::memcpy to copy the content in the buffer to the copyBuffer.
       std::memcpy(copyBuffer, buffer, size);
       napi_create_string_utf8(env_, "BufferCb", NAPI_AUTO_LENGTH, &asyncResourceName);
       napi_status status = napi_create_async_work(
           env_, asyncResource, asyncResourceName, [](napi_env env, void* copyBuffer) {},
           [](napi_env env, napi_status status, void* copyBuffer) {
               napi_value retVal;
               napi_value callback = nullptr;
               void* data = nullptr;
               napi_value arrayBuffer = nullptr;
               size_t bufferSize = g_size;
               napi_create_arraybuffer(env, bufferSize, &data, &arrayBuffer);
               std::memcpy(data, copyBuffer, bufferSize);
               OH_LOG_INFO(LOG_APP, "BufferCb g_size: %{public}zu", g_size);
               napi_get_reference_value(env, bufferCbRef_, &callback);
               if (callback) {
                   OH_LOG_INFO(LOG_APP, "BufferCb callback is full");
               } else {
                   OH_LOG_ERROR(LOG_APP, "BufferCb callback is null");
               }
               // Call the buffer processing callback function at the ArkTS side to pass the image arrayBuffer for display or storage.
               napi_call_function(env, nullptr, callback, 1, &arrayBuffer, &retVal);
               // Clear the memory.
               free(data); // Release the memory allocated during asynchronous work.
               free(copyBuffer);
           },
           copyBuffer, &work);

       // Error check: The memory is released when the asynchronous work fails to be created.
       if (status != napi_ok) {
           OH_LOG_ERROR(LOG_APP, "Failed to create async work");
           free(copyBuffer); // Release the allocated memory.
           return;
       }
       napi_queue_async_work_with_qos(env_, work, napi_qos_user_initiated);
   }

   // Save the buffer processing callback function passed from ArkTS.
   static napi_value SetBufferCb(napi_env env, napi_callback_info info) {
       OH_LOG_INFO(LOG_APP, "SetBufferCb start");
       napi_value result;
       napi_get_undefined(env, &result);

       napi_value argValue[1] = {nullptr};
       size_t argCount = 1;
       napi_get_cb_info(env, info, &argCount, argValue, nullptr, nullptr);

       env_ = env;
       napi_create_reference(env, argValue[0], 1, &bufferCbRef_);
       if (bufferCbRef_) {
           OH_LOG_INFO(LOG_APP, "SetBufferCb callbackRef is full");
       } else {
           OH_LOG_ERROR(LOG_APP, "SetBufferCb callbackRef is null");
       }
       // Register the buffer callback to be passed to the NAPI layer on the ArkTS side.
       RegisterBufferCb((void *)BufferCb);
       return result;
   }
   ```

6. Create a photo session. For details, see [Camera Session Management (C/C++)](./native-camera-session-management.md).

7. (Optional) Set photo capture parameters.

   You can set camera parameters to adjust photo capture functions, including the flash, zoom ratio, and focal length.

   ```c++
   // Check whether the camera has flash.
   bool HasFlash(Camera_CaptureSession* captureSession)
   {
       bool hasFlash = false;
       Camera_ErrorCode ret = OH_CaptureSession_HasFlash(captureSession, &hasFlash);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_HasFlash failed.");
       }
       if (hasFlash) {
           OH_LOG_INFO(LOG_APP, "hasFlash success");
       } else {
           OH_LOG_ERROR(LOG_APP, "hasFlash fail");
       }
       return hasFlash;
   }

   // Check whether a flash mode is supported.
   bool IsFlashModeSupported(Camera_CaptureSession* captureSession, Camera_FlashMode flashMode)
   {
       bool isSupported = false;
       Camera_ErrorCode ret = OH_CaptureSession_IsFlashModeSupported(captureSession, flashMode, &isSupported);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_IsFlashModeSupported failed.");
       }
       return isSupported;
   }
   // Call OH_CaptureSession_SetFlashMode when the specified mode is supported.
   Camera_ErrorCode SetFlashMode(Camera_CaptureSession* captureSession, Camera_FlashMode flashMode)
   {
       Camera_ErrorCode ret = OH_CaptureSession_SetFlashMode(captureSession, flashMode);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetFlashMode success.");
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetFlashMode failed. %{public}d ", ret);
       }
       return ret;
   }

   // Check whether the continuous auto focus is supported.
   bool IsFocusModeSupported(Camera_CaptureSession* captureSession, Camera_FocusMode focusMode)
   {
       bool isFocusModeSupported = false;
       Camera_ErrorCode ret = OH_CaptureSession_IsFocusModeSupported(captureSession, focusMode, &isFocusModeSupported);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_IsFocusModeSupported failed.");
       }
       return isFocusModeSupported;
   }
   // Call OH_CaptureSession_SetFocusMode when the specified mode is supported.
   Camera_ErrorCode SetFocusMode(Camera_CaptureSession* captureSession, Camera_FocusMode focusMode)
   {
       Camera_ErrorCode ret = OH_CaptureSession_SetFocusMode(captureSession, focusMode);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetFocusMode failed. %{public}d ", ret);
       }
       return ret;
   }

   // Obtain the zoom ratio range supported by the camera.
   Camera_ErrorCode GetZoomRatioRange(Camera_CaptureSession* captureSession, float* minZoom, float* maxZoom)
   {
       Camera_ErrorCode ret = OH_CaptureSession_GetZoomRatioRange(captureSession, minZoom, maxZoom);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetZoomRatioRange failed.");
       } else {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetZoomRatioRange success. minZoom: %{public}f, maxZoom:%{public}f",
               *minZoom, *maxZoom);
       }
       return ret;
   }
   
   // Set the zoom ratio, which must be within the allowed range.
   Camera_ErrorCode SetZoomRatio(Camera_CaptureSession* captureSession, float zoom)
   {
       Camera_ErrorCode ret = OH_CaptureSession_SetZoomRatio(captureSession, zoom);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetZoomRatio success.");
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetZoomRatio failed. %{public}d ", ret);
       }
       return ret;
   }
   ```

8. Trigger photo capture.

   Call [OH_PhotoOutput_Capture()](../../reference/apis-camera-kit/capi-photo-output-h.md#oh_photooutput_capture) to trigger photo capture.

   ```c++
   Camera_ErrorCode Capture(Camera_PhotoOutput* photoOutput)
   {
       Camera_ErrorCode ret = OH_PhotoOutput_Capture(photoOutput);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_PhotoOutput_Capture success ");
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_Capture failed. %d ", ret);
       }
       return ret;
   }
   ```

## Status Listening

During camera application development, you can listen for the status of the photo output stream, including the start of the photo stream, the start and end of the photo frame, and the errors of the photo output stream.

- Register the **'onFrameStart'** event to listen for photo capture start events. This event can be registered when a PhotoOutput instance is created and is triggered when the bottom layer starts exposure for photo capture for the first time. The capture ID is returned.
  ```c++
  void PhotoOutputOnFrameStart(Camera_PhotoOutput* photoOutput)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutputOnFrameStart");
  }
  void PhotoOutputOnFrameShutter(Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* info)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutputOnFrameShutter");
  }
  ```

- Register the **'onFrameEnd'** event to listen for photo capture end events. This event can be registered when a PhotoOutput instance is created.
  
  ```c++
  void PhotoOutputOnFrameEnd(Camera_PhotoOutput* photoOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutput frameCount = %{public}d", frameCount);
  }
  ```

- Register the **'onError'** event to listen for photo output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).
  
  ```c++
  void PhotoOutputOnError(Camera_PhotoOutput* photoOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutput errorCode = %{public}d", errorCode);
  }
  ```
  ```c++
  PhotoOutput_Callbacks* GetPhotoOutputListener()
  {
      static PhotoOutput_Callbacks photoOutputListener = {
          .onFrameStart = PhotoOutputOnFrameStart,
          .onFrameShutter = PhotoOutputOnFrameShutter,
          .onFrameEnd = PhotoOutputOnFrameEnd,
          .onError = PhotoOutputOnError
      };
      return &photoOutputListener;
  }
  Camera_ErrorCode RegisterPhotoOutputCallback(Camera_PhotoOutput* photoOutput)
  {
      Camera_ErrorCode ret = OH_PhotoOutput_RegisterCallback(photoOutput, GetPhotoOutputListener());
      if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_RegisterCallback failed.");
      }
      return ret;
  }
  ```
