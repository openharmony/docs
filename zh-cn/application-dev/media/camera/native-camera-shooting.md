# 拍照(C/C++)

拍照是相机的最重要功能之一，拍照模块基于相机复杂的逻辑，为了保证用户拍出的照片质量，在中间步骤可以设置分辨率、闪光灯、焦距、照片质量及旋转角度等信息。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/_o_h___camera.md)。

1. 导入NDK接口，接口中提供了相机相关的属性和方法，导入方法如下。

   ```c++
   // 导入NDK接口头文件。
   #include <cstdint>
   #include <cstdlib>
   #include <cstring>
   #include <string.h>
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

2. 在CMake脚本中链接相关动态库。

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

3. 创建并打开相机设备，参考[ 设备输入(C/C++)](./native-camera-device-input.md)步骤3-5。

4. 选择设备支持的输出流能力，创建拍照输出流。

   通过[OH_CameraManager_CreatePhotoOutputWithoutSurface()](../../reference/apis-camera-kit/_o_h___camera.md#oh_cameramanager_createphotooutputwithoutsurface)方法创建拍照输出流。

   ```c++
   Camera_PhotoOutput* CreatePhotoOutput(Camera_Manager* cameraManager, const Camera_Profile* photoProfile) {
       Camera_PhotoOutput* photoOutput = nullptr;
       // 无需传入surfaceId，直接创建拍照流。
       Camera_ErrorCode ret = OH_CameraManager_CreatePhotoOutputWithoutSurface(cameraManager, photoProfile, &photoOutput);
       if (photoOutput == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePhotoOutputWithoutSurface failed.");
       }
       return photoOutput;
   }
   ```

5. 注册单段式(PhotoAvailable)拍照回调，若应用希望快速得到回图，推荐使用[分段式拍照回调(PhotoAssetAvailable)](./native-camera-deferred-capture.md)。

   > **注意：**
   >
   > 如果已经注册了PhotoAssetAvailable回调，并且在Session开始之后又注册了PhotoAvailable回调，PhotoAssetAvailable和PhotoAvailable同时注册，会导致流被重启，仅PhotoAssetAvailable生效。
   >
   > 不建议开发者同时注册PhotoAssetAvailable和PhotoAvailable。

   **单段式拍照开发流程（PhotoAssetAvailable）**：

   - 在会话commitConfig前注册单段式拍照回调。
   - 在单段式拍照回调函数中获取图片信息，解析出buffer数据，做自定义业务处理。
   - 将处理完的buffer通过回调传给ArkTS侧，做图片显示或通过安全控件写文件保存图片。
   - 使用完后解注册单段式拍照回调函数。

   ```c++
   // 保存NAPI侧注册的buffer处理回调函数。
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

   // 单段式拍照回调函数。
   void OnPhotoAvailable(Camera_PhotoOutput* photoOutput, OH_PhotoNative* photo) {
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable start!");
       OH_ImageNative* imageNative;
       Camera_ErrorCode errCode = OH_PhotoNative_GetMainImage(photo, &imageNative);
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable errCode:%{public}d imageNative:%{public}p", errCode, imageNative);
       // 读取OH_ImageNative的 size 属性。
       Image_Size size;
       Image_ErrorCode imageErr = OH_ImageNative_GetImageSize(imageNative, &size);
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d width:%{public}d height:%{public}d", imageErr,
                    size.width, size.height);
       // 读取OH_ImageNative的组件列表的元素个数。
       size_t componentTypeSize = 0;
       imageErr = OH_ImageNative_GetComponentTypes(imageNative, nullptr, &componentTypeSize);
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d componentTypeSize:%{public}zu", imageErr,
                    componentTypeSize);
       // 读取OH_ImageNative的组件列表。
       uint32_t* components = new uint32_t[componentTypeSize];
       imageErr = OH_ImageNative_GetComponentTypes(imageNative, &components, &componentTypeSize);
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable OH_ImageNative_GetComponentTypes imageErr:%{public}d", imageErr);
       // 读取OH_ImageNative的第一个组件所对应的缓冲区对象。
       OH_NativeBuffer* nativeBuffer = nullptr;
       imageErr = OH_ImageNative_GetByteBuffer(imageNative, components[0], &nativeBuffer);
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable OH_ImageNative_GetByteBuffer imageErr:%{public}d", imageErr);
       // 读取OH_ImageNative的第一个组件所对应的缓冲区大小。
       size_t nativeBufferSize = 0;
       imageErr = OH_ImageNative_GetBufferSize(imageNative, components[0], &nativeBufferSize);
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d nativeBufferSize:%{public}zu", imageErr,
                    nativeBufferSize);
       // 读取OH_ImageNative的第一个组件所对应的像素行宽。
       int32_t rowStride = 0;
       imageErr = OH_ImageNative_GetRowStride(imageNative, components[0], &rowStride);
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d rowStride:%{public}d", imageErr, rowStride);
       // 读取OH_ImageNative的第一个组件所对应的像素大小。
       int32_t pixelStride = 0;
       imageErr = OH_ImageNative_GetPixelStride(imageNative, components[0], &pixelStride);
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d pixelStride:%{public}d", imageErr, pixelStride);
       // 将ION内存映射到进程空间。
       void* virAddr = nullptr; // 指向映射内存的虚拟地址，解除映射后这个指针将不再有效。
       int32_t ret = OH_NativeBuffer_Map(nativeBuffer, &virAddr); // 映射后通过第二个参数virAddr返回内存的首地址。
       OH_LOG_INFO(LOG_APP, "OnPhotoAvailable OH_NativeBuffer_Map err:%{public}d", ret);
       // 调用NAPI层buffer回调。
       auto cb = (void (*)(void *, size_t))(bufferCb);
       cb(virAddr, nativeBufferSize);
       // 释放资源。
	   delete[] components;
	   OH_ImageNative_Release(imageNative);
       ret = OH_NativeBuffer_Unmap(nativeBuffer); // 在处理完之后，解除映射并释放缓冲区。
       if (ret != 0) {
           OH_LOG_ERROR(LOG_APP, "OnPhotoAvailable OH_NativeBuffer_Unmap error:%{public}d", ret);
       }
	   OH_LOG_INFO(LOG_APP, "OnPhotoAvailable end");
   }

   // 注册单段式拍照回调。
   Camera_ErrorCode PhotoOutputRegisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput) {
       OH_LOG_INFO(LOG_APP, "PhotoOutputRegisterPhotoAvailableCallback start!");
       Camera_ErrorCode ret = OH_PhotoOutput_RegisterPhotoAvailableCallback(photoOutput, OnPhotoAvailable);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "PhotoOutputRegisterPhotoAvailableCallback failed.");
       }
       OH_LOG_INFO(LOG_APP, "PhotoOutputRegisterPhotoAvailableCallback return with ret code: %{public}d!", ret);
       return ret;
   }

   // 解注册单段式拍照回调。
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

   NAPI层buffer回处理参考示例代码：

   ```c++
   static napi_ref bufferCbRef_ = nullptr;
   static napi_env env_;
   size_t g_size = 0;
   
   // NAPI层buffer回调方法。
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
       // 使用 std::memcpy 复制 buffer 的内容到 copyBuffer。
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
               // 调用ArkTS的buffer处理回调函数，将图片arrayBuffer传给页面做显示或保存。
               napi_call_function(env, nullptr, callback, 1, &arrayBuffer, &retVal);
               // 清理内存。
               free(data); // 释放在异步工作中分配的内存。
           },
           copyBuffer, &work);

       // 错误检查：创建异步工作失败时释放内存。
       if (status != napi_ok) {
           OH_LOG_ERROR(LOG_APP, "Failed to create async work");
           free(copyBuffer); // 释放分配的内存。
           return;
       }
       napi_queue_async_work_with_qos(env_, work, napi_qos_user_initiated);
   }

   // 保存ArkTS侧传入的buffer处理回调函数。
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
       // 注册ArkTS侧buffer回调到NAPI层。
       RegisterBufferCb((void *)BufferCb);
       return result;
   }
   ```

6. 创建拍照类型会话，参考[会话管理(C/C++)](./native-camera-session-management.md)，开启会话，准备拍照。

7. 配置拍照参数（可选）。
   配置相机的参数可以调整拍照的一些功能，包括闪光灯、变焦、焦距等。

   ```c++
   // 判断设备是否支持闪光灯。
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

   // 检测闪光灯模式是否支持。
   bool IsFlashModeSupported(Camera_CaptureSession* captureSession, Camera_FlashMode flashMode)
   {
       bool isSupported = false;
       Camera_ErrorCode ret = OH_CaptureSession_IsFlashModeSupported(captureSession, flashMode, &isSupported);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_IsFlashModeSupported failed.");
       }
       return isSupported;
   }
   // 在支持flashMode的情况下进行调用OH_CaptureSession_SetFlashMode。
   Camera_ErrorCode SetFocusMode(Camera_CaptureSession* captureSession, Camera_FlashMode flashMode)
   {
       Camera_ErrorCode ret = OH_CaptureSession_SetFlashMode(captureSession, flashMode);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetFlashMode success.");
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetFlashMode failed. %{public}d ", ret);
       }
       return ret;
   }

   // 判断是否支持连续自动变焦模式。
   bool IsFocusModeSupported(Camera_CaptureSession* captureSession, Camera_FocusMode focusMode)
   {
       bool isFocusModeSupported = false;
       Camera_ErrorCode ret = OH_CaptureSession_IsFocusModeSupported(captureSession, focusMode, &isFocusModeSupported);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_IsFocusModeSupported failed.");
       }
       return isFocusModeSupported;
   }
   // 在支持focusMode的情况下进行OH_CaptureSession_SetFocusMode。
   Camera_ErrorCode SetFocusMode(Camera_CaptureSession* captureSession, Camera_FocusMode focusMode)
   {
       Camera_ErrorCode ret = OH_CaptureSession_SetFocusMode(captureSession, focusMode);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetFocusMode failed. %{public}d ", ret);
       }
       return ret;
   }

   // 获取相机支持的可变焦距比范围。
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
   
   // 设置变焦，zoom需要在可变焦距比范围内。
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

8. 触发拍照。

   通过[OH_PhotoOutput_Capture()](../../reference/apis-camera-kit/_o_h___camera.md#oh_photooutput_capture)方法，执行拍照任务。

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

## 状态监听

在相机应用开发过程中，可以随时监听拍照输出流状态，包括拍照流开始、拍照帧的开始与结束、拍照输出流的错误。

- 通过注册固定的onFrameStart回调函数获取监听拍照开始结果，photoOutput创建成功时即可监听，拍照第一次曝光时触发。
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

- 通过注册固定的onFrameEnd回调函数获取监听拍照结束结果，photoOutput创建成功时即可监听。
  
  ```c++
  void PhotoOutputOnFrameEnd(Camera_PhotoOutput* photoOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutput frameCount = %{public}d", frameCount);
  }
  ```

- 通过注册固定的onError回调函数获取监听拍照输出流的错误结果。callback返回拍照输出接口使用错误时的对应错误码，错误码类型参见[Camera_ErrorCode](../../reference/apis-camera-kit/_o_h___camera.md#camera_errorcode-1)。
  
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