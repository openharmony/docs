# Using Image_NativeModule to Receive Images

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-11T01:47:08.591Z pushedAt=2026-08-11T08:31:47.235Z -->

You can use the **ImageReceiver** class to obtain the surface ID of a component, read the latest image or the next image, and release ImageReceiver instances. For details about the sample code of camera preview implemented with the use of the camera API, see [Secondary Processing of Preview Streams (C/C++)](../camera/native-camera-preview-imageReceiver.md).

> **NOTE**
>
> The ImageReceiver merely serves as the recipient and consumer of images. The properties set in ImageReceiver, such as size and format, do not actually take effect. Image properties need to be configured on the sending side (the producer), such as when setting up the preview profiles for a [preview stream (C/C++)](../camera/native-camera-preview.md).

## How to Develop

### Adding Dependencies

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libohimage.so**, **libimage_receiver.so**, **libnative_image.so**, and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libohimage.so libimage_receiver.so libnative_image.so)
```

### Calling the Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/capi-image-nativemodule.md).

The code below mainly shows how to initialize the receiver, create a camera preview stream, obtain image information, and release the receiver.

> **NOTE**
>
> Certain APIs are supported only in API version 20 or later. You should select an appropriate API version during development.

1. Import the required header files.

   <!-- @[receiver_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->        

   ``` C++
   #include <hilog/log.h>
   #include "napi/native_api.h"
   #include <string>
   #include <multimedia/image_framework/image/image_native.h>
   #include <multimedia/image_framework/image/image_receiver_native.h>
   
   #include "ohcamera/camera.h"
   #include "ohcamera/camera_input.h"
   #include "ohcamera/capture_session.h"
   #include "ohcamera/photo_output.h"
   #include "ohcamera/preview_output.h"
   #include "ohcamera/video_output.h"
   #include "ohcamera/camera_manager.h"
   
   #include <mutex>
   #include &lt;shared_mutex&gt; // Use C++17 or later.
   #include <condition_variable>
   ```

2. Define constants.

   <!-- @[receiver_defineConst](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->      

   ``` C++
   #undef LOG_DOMAIN
   #define LOG_DOMAIN 0x3200
   
   #undef LOG_TAG
   #define LOG_TAG "MY_TAG"
   
   #define IMAGE_WIDTH 320
   #define IMAGE_HEIGHT 480
   #define IMAGE_CAPACITY 2
   ```

3. Define global variables.

   <!-- @[define_receiverInstance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->                

   ``` C++
   static OH_ImageReceiverNative* g_receiver = nullptr;
   
   static std::mutex g_mutex;
   static std::shared_mutex shared_receiver_mutex;
   static std::condition_variable g_condVar;
   static bool g_imageReady = false;
   static OH_ImageNative* g_imageInfoResult = nullptr;
   ```

4. Define certain helper functions to manage the NAPI return value and parameter type conversion.

   <!-- @[receiver_utility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->      

   ``` C++
   // Process the NAPI return value.
   napi_value GetJsResultDemo(napi_env env, int result)
   {
       napi_value resultNapi = nullptr;
       napi_create_int32(env, result, &resultNapi);
       return resultNapi;
   }
   
   // Convert uint64_t to a char array terminated with null.
   std::unique_ptr<char[]> ConvertUint64ToCharTemp(uint64_t value)
   {
       std::string strValue = std::to_string(value);
       auto charBuffer = std::make_unique<char[]>(strValue.size() + 1);
       std::copy(strValue.begin(), strValue.end(), charBuffer.get());
       charBuffer[strValue.size()] = '\0';
   
       return charBuffer;
   }
   ```

5. Initialize the receiver.

   - Create and set receiver options.

     <!-- @[set_receiverOptions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->       

     ``` C++
     static Image_ErrorCode CreateAndConfigOptions(OH_ImageReceiverOptions** options)
     {
         Image_ErrorCode errCode = OH_ImageReceiverOptions_Create(options);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "Create image receiver options failed, errCode: %{public}d.", errCode);
             return errCode;
         }
         Image_Size imgSize = {IMAGE_WIDTH, IMAGE_HEIGHT};
         errCode = OH_ImageReceiverOptions_SetSize(*options, imgSize);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "Set image receiver options size failed, errCode: %{public}d.", errCode);
             OH_ImageReceiverOptions_Release(*options);
             return errCode;
         }
         errCode = OH_ImageReceiverOptions_SetCapacity(*options, IMAGE_CAPACITY);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "Set image receiver options capacity failed, errCode: %{public}d.", errCode);
             OH_ImageReceiverOptions_Release(*options);
             return errCode;
         }
         return IMAGE_SUCCESS;
     }
     ```

   - Obtain the receiver options.

     <!-- @[get_receiverOptions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->       

     ``` C++
     static Image_ErrorCode ValidateOptions(OH_ImageReceiverOptions* options)
     {
         Image_Size imgSizeRead;
         Image_ErrorCode errCode = OH_ImageReceiverOptions_GetSize(options, &imgSizeRead);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "Get image receiver options size failed, errCode: %{public}d.", errCode);
             return errCode;
         }
         if (imgSizeRead.width != IMAGE_WIDTH || imgSizeRead.height != IMAGE_HEIGHT) {
             OH_LOG_ERROR(LOG_APP, "Get image receiver options size failed,"
                          "width: %{public}d, height: %{public}d.", imgSizeRead.width, imgSizeRead.height);
             return IMAGE_BAD_PARAMETER;
         }
         int32_t capacity = 0;
         errCode = OH_ImageReceiverOptions_GetCapacity(options, &capacity);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "Get image receiver options capacity failed, errCode: %{public}d.", errCode);
             return errCode;
         }
         if (capacity != IMAGE_CAPACITY) {
             OH_LOG_ERROR(LOG_APP, "Get image receiver options capacity failed, capacity: %{public}d.", capacity);
             return IMAGE_BAD_PARAMETER;
         }
         return IMAGE_SUCCESS;
     }
     ```

   - Create a receiver instance.

     <!-- @[create_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->       

     ``` C++
     static Image_ErrorCode CreateReceiver(OH_ImageReceiverOptions* options, OH_ImageReceiverNative** receiver)
     {
         Image_ErrorCode errCode = OH_ImageReceiverNative_Create(options, receiver);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "Create image receiver failed, errCode: %{public}d.", errCode);
             return errCode;
         }
         return IMAGE_SUCCESS;
     }
     ```

   - Define the callback for obtaining the next image.

     <!-- @[define_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->         

     ``` C++
     static void OnCallback(OH_ImageReceiverNative* receiver)
     {
         OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest buffer available.");
     
         // Shared lock (read).
         std::shared_lock<std::shared_mutex> lock(shared_receiver_mutex);
         OH_ImageNative* image = nullptr;
         Image_ErrorCode errCode = OH_ImageReceiverNative_ReadNextImage(receiver, &image);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver next image failed,"
                          "errCode: %{public}d.", errCode);
             OH_ImageNative_Release(image);
             return;
         } else {
             std::lock_guard<std::mutex> lock(g_mutex);
             g_imageInfoResult = image;
             g_imageReady = true;
         }
         g_condVar.notify_one();
     }
     ```

   - Register the callback.

     <!-- @[register_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->       

     ``` C++
     static Image_ErrorCode RegisterCallbackAndQuery(OH_ImageReceiverNative* receiver)
     {
         uint64_t surfaceID = 0;
         Image_ErrorCode errCode = OH_ImageReceiverNative_On(receiver, OnCallback);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "Image receiver on failed, errCode: %{public}d.", errCode);
             return errCode;
         }
         errCode = OH_ImageReceiverNative_GetReceivingSurfaceId(receiver, &surfaceID);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "Get image receiver surfaceID failed, errCode: %{public}d.", errCode);
             return errCode;
         }
         OH_LOG_INFO(LOG_APP, "Get image receiver surfaceID: %{public}lu.", surfaceID);
         Image_Size imgSizeRead;
         errCode = OH_ImageReceiverNative_GetSize(receiver, &imgSizeRead);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "Get image receiver size failed, errCode: %{public}d.", errCode);
             return errCode;
         }
         OH_LOG_INFO(LOG_APP, "Get image receiver size: width = %{public}d, height = %{public}d.",
                     imgSizeRead.width, imgSizeRead.height);
         int32_t capacity = 0;
         errCode = OH_ImageReceiverNative_GetCapacity(receiver, &capacity);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "Get image receiver capacity failed, errCode: %{public}d.", errCode);
             return errCode;
         }
         OH_LOG_INFO(LOG_APP, "Get image receiver capacity: %{public}d.", capacity);
         return IMAGE_SUCCESS;
     }
     ```

   - Initialize the receiver.

     <!-- @[init_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->      

     ``` C++
     static napi_value ImageReceiverNativeCTest(napi_env env, napi_callback_info info)
     {
         if (g_receiver != nullptr) {
             OH_ImageReceiverNative_Off(g_receiver);
             OH_ImageReceiverNative_Release(g_receiver);
             g_receiver = nullptr;
         }
     
         OH_ImageReceiverOptions* options = nullptr;
         Image_ErrorCode errCode = CreateAndConfigOptions(&options);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "CreateAndConfigOptions failed errCode=%{public}d", errCode);
             return GetJsResultDemo(env, errCode);
         }
         errCode = ValidateOptions(options);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "ValidateOptions failed errCode=%{public}d", errCode);
             OH_ImageReceiverOptions_Release(options);
             return GetJsResultDemo(env, errCode);
         }
         errCode = CreateReceiver(options, &g_receiver);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "CreateReceiver failed errCode=%{public}d", errCode);
             OH_ImageReceiverOptions_Release(options);
             return GetJsResultDemo(env, errCode);
         }
         errCode = RegisterCallbackAndQuery(g_receiver);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "RegisterCallbackAndQuery failed errCode=%{public}d", errCode);
             OH_ImageReceiverOptions_Release(options);
             OH_ImageReceiverNative_Release(g_receiver);
             g_receiver = nullptr;
             return GetJsResultDemo(env, errCode);
         }
         OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest create and config success.");
         OH_ImageReceiverOptions_Release(options);
         return GetJsResultDemo(env, IMAGE_SUCCESS);
     }
     ```

6. Call the camera photo stream to take a photo and trigger the callback.

   - Create a CameraManager instance.

     <!-- @[init_camera](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->     

     ``` C++
     Camera_ErrorCode InitCameraManagerAndInput(Camera_Manager*& cameraManager,
                                                Camera_Device*& cameras,
                                                uint32_t& size,
                                                Camera_Input*& cameraInput)
     {
         cameraManager = nullptr;
         cameras = nullptr;
         size = 0;
         cameraInput = nullptr;
         Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
         if (cameraManager == nullptr || ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraManager failed.");
             return ret;
         }
         ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
         if (cameras == nullptr || size < 1 || ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
             return ret;
         }
     
         for (uint32_t i = 0; i < size; ++i) {
             OH_LOG_INFO(LOG_APP, "Camera[%{public}u]: id=%{public}s, position=%{public}d, type=%{public}d, "
                 "connectionType=%{public}d", i, cameras[i].cameraId, cameras[i].cameraPosition, cameras[i].cameraType,
                 cameras[i].connectionType);
         }
     
         ret = OH_CameraManager_CreateCameraInput(cameraManager, &cameras[0], &cameraInput);
         if (cameraInput == nullptr || ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCameraInput failed.ret:%{public}d", ret);
             return ret;
         }
         return CAMERA_OK;
     }
     ```

   - Obtain the camera output capability.

     <!-- @[get_cameraOutCapability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->      

     ``` C++
     Camera_ErrorCode GetCameraOutputCapability(Camera_Manager* cameraManager,
                                                Camera_Device* cameras,
                                                uint32_t cameraDeviceIndex,
                                                Camera_OutputCapability*& capability)
     {
         capability = nullptr;
         Camera_ErrorCode ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager,
                                                                                    &cameras[cameraDeviceIndex],
                                                                                    &capability);
         if (capability == nullptr || ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
         }
         return ret;
     }
     ```

   - Create a camera capture session, which is used to capture photos taken using the camera.

     <!-- @[create_captureSession](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->      

     ``` C++
     Camera_CaptureSession* CreateAndStartSession(Camera_Manager* cameraManager, Camera_Input* cameraInput, int sessionMode)
     {
         Camera_CaptureSession* captureSession = nullptr;
         Camera_ErrorCode ret = OH_CameraManager_CreateCaptureSession(cameraManager, &captureSession);
         if (captureSession == nullptr || ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCaptureSession failed.");
             return nullptr;
         }
         ret = OH_CaptureSession_SetSessionMode(captureSession, static_cast<Camera_SceneMode>(sessionMode));
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetSessionMode failed.");
             return nullptr;
         }
         ret = OH_CaptureSession_BeginConfig(captureSession);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_BeginConfig failed.");
             return nullptr;
         }
         ret = OH_CaptureSession_AddInput(captureSession, cameraInput);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddInput failed.");
             return nullptr;
         }
         return captureSession;
     }
     ```

   - Start the capture session.

     <!-- @[start_captureSession](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->      

     ``` C++
     static Camera_ErrorCode StartCaptureSession(Camera_Manager* mgr, Camera_Input* input,
                                                 Camera_PreviewOutput* previewOutput,
                                                 Camera_CaptureSession** sessionOut)
     {
         *sessionOut = CreateAndStartSession(mgr, input, NORMAL_PHOTO);
         if (*sessionOut == nullptr) {
             OH_LOG_ERROR(LOG_APP, "CreateAndStartSession failed.");
             return CAMERA_INVALID_ARGUMENT;
         }
     
         Camera_ErrorCode ret = OH_CaptureSession_AddPreviewOutput(*sessionOut, previewOutput);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPreviewOutput failed.");
             return ret;
         }
     
         ret = OH_CaptureSession_CommitConfig(*sessionOut);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_CommitConfig failed.");
             return ret;
         }
     
         ret = OH_CaptureSession_Start(*sessionOut);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Start failed.");
         }
         
         return ret;
     }
     ```

   - Create a camera photo stream.

     <!-- @[start_cameraSession](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->      

     ``` C++
     Camera_ErrorCode StartTakePhoto(char* str)
     {
         char* photoSurfaceId = str;
         Camera_Manager* cameraManager = nullptr;
         Camera_Device* cameras = nullptr;
         uint32_t size = 0;
         Camera_Input* cameraInput = nullptr;
         Camera_ErrorCode ret = InitCameraManagerAndInput(cameraManager, cameras, size, cameraInput);
         if (ret != CAMERA_OK) return ret;
     
         Camera_OutputCapability* cameraOutputCapability = nullptr;
         ret = GetCameraOutputCapability(cameraManager, cameras, 0, cameraOutputCapability);
         if (ret != CAMERA_OK) return ret;
         
         const Camera_Profile* photoProfile = cameraOutputCapability->previewProfiles[0];
         Camera_PreviewOutput* previewOutput = nullptr;
         ret = OH_CameraManager_CreatePreviewOutput(cameraManager, photoProfile, photoSurfaceId, &previewOutput);
         if (photoProfile == nullptr || previewOutput == nullptr || ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
             return ret;
         }
     
         ret = OH_CameraInput_Open(cameraInput);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "OH_CameraInput_open failed.");
             return ret;
         }
     
         Camera_CaptureSession* captureSession = nullptr;
         ret = StartCaptureSession(cameraManager, cameraInput, previewOutput, &captureSession);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "StartCaptureSession failed.");
             return ret;
         }
     
         return CAMERA_OK;
     }
     ```

   - Call the camera to take a photo.

     <!-- @[load_cameraSession](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->      

     ``` C++
     static napi_value TakePhoto(napi_env env, napi_callback_info info)
     {
         if (g_receiver == nullptr) {
             OH_LOG_ERROR(LOG_APP, "ImageReceiver not initialized.");
             return GetJsResultDemo(env, IMAGE_BAD_PARAMETER);
         }
         uint64_t surfaceId = 0;
         Image_ErrorCode errCode = OH_ImageReceiverNative_GetReceivingSurfaceId(g_receiver, &surfaceId);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "Get surfaceId failed.");
             return GetJsResultDemo(env, errCode);
         }
     
         auto surfaceId_c = ConvertUint64ToCharTemp(surfaceId);
         Camera_ErrorCode photoRet = StartTakePhoto(surfaceId_c.get());
         return GetJsResultDemo(env, photoRet);
     }
     ```

7. Obtain the image information received by the receiver.

   - Wait for the OnCallback notification.

     <!-- @[wait_callBack](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->       

     ``` C++
     // Synchronous waiting.
     static OH_ImageNative* NotifyJsImageInfoSync()
     {
         std::unique_lock<std::mutex> lock(g_mutex);
         g_imageReady = false;
         g_imageInfoResult = nullptr;
     
         // Wait for the OnCallback notification.
         bool ret = g_condVar.wait_for(lock, std::chrono::seconds(1), [] {
             OH_LOG_INFO(LOG_APP, "NotifyJsImageInfoSync: wait_for wakeup, g_imageReady=%{public}d", g_imageReady);
             return g_imageReady;
         });
         if (!ret) {
             OH_LOG_ERROR(LOG_APP, "NotifyJsImageInfoSync: wait_for timeout.");
             return nullptr;
         }
         return g_imageInfoResult;
     }
     ```

   - Obtain the image size.

     <!-- @[get_imageSize](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->       

     ``` C++
     // Obtain the image size.
     static napi_value GetImageSizeInfo(napi_env env, OH_ImageNative* image)
     {
         OH_LOG_INFO(LOG_APP, "GetImageSizeInfo: enter, image=%{public}p", image);
     
         Image_Size imgSizeRead;
         Image_ErrorCode errCode = OH_ImageNative_GetImageSize(image, &imgSizeRead);
         OH_LOG_INFO(LOG_APP, "GetImageSizeInfo: GetImageSize errCode=%{public}d, width=%{public}d, height=%{public}d",
                     errCode, imgSizeRead.width, imgSizeRead.height);
     
         if (errCode == IMAGE_SUCCESS) {
             napi_value resultObj;
             napi_create_object(env, &resultObj);
     
             napi_value width;
             napi_value height;
             napi_create_int32(env, imgSizeRead.width, &width);
             napi_create_int32(env, imgSizeRead.height, &height);
     
             napi_set_named_property(env, resultObj, "width", width);
             napi_set_named_property(env, resultObj, "height", height);
     
             OH_LOG_INFO(LOG_APP, "GetImageSizeInfo: exit");
             return resultObj;
         }
     
         OH_LOG_ERROR(LOG_APP, "GetImageSizeInfo: Failed to get image size");
         return nullptr;
     }
     ```

   - Obtain the component type.

     <!-- @[get_componentType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->      

     ``` C++
     // Obtain the component type.
     static size_t GetComponentTypeSize(OH_ImageNative* image, size_t& componentTypeSize)
     {
         OH_LOG_INFO(LOG_APP, "GetComponentTypeSize: enter, image=%{public}p", image);
         // Obtain the size of the component type.
         Image_ErrorCode errCode = OH_ImageNative_GetComponentTypes(image, nullptr, &componentTypeSize);
         OH_LOG_INFO(LOG_APP, "GetComponentTypeSize: GetComponentTypes (query size) errCode=%{public}d,"
                     "componentTypeSize=%{public}zu", errCode, componentTypeSize);
         return componentTypeSize;
     }
     ```

   - Obtain the component information.

     <!-- @[get_componentInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->      

     ``` C++
     // Obtain the component information.
     static napi_value GetComponentInfo(napi_env env, size_t componentTypeSize, OH_ImageNative* image, napi_value resultObj)
     {
         if (componentTypeSize > 0) {
             uint32_t* components = new uint32_t[componentTypeSize];
             Image_ErrorCode errCode = OH_ImageNative_GetComponentTypes(image, &components, &componentTypeSize);
             OH_LOG_INFO(LOG_APP, "GetImageInfoObject: GetComponentTypes (get types) errCode=%{public}d,"
                         "firstComponent=%{public}u", errCode, componentTypeSize > 0 ? components[0] : 0);
             if (errCode != IMAGE_SUCCESS) {
                 OH_LOG_ERROR(LOG_APP, "GetImageInfoObject: GetComponentTypes (get types) failed");
                 delete [] components;
                 return resultObj;
             }
             
             OH_NativeBuffer* nativeBuffer = nullptr;
             errCode = OH_ImageNative_GetByteBuffer(image, components[0], &nativeBuffer);
             if (errCode == IMAGE_SUCCESS) {
                 OH_LOG_INFO(LOG_APP, "Get native buffer success.");
             }
         
             size_t nativeBufferSize = 0;
             errCode = OH_ImageNative_GetBufferSize(image, components[0], &nativeBufferSize);
             OH_LOG_INFO(LOG_APP, "GetImageInfoObject: GetBufferSize errCode=%{public}d, nativeBufferSize=%{public}zu",
                         errCode, nativeBufferSize);
             if (errCode == IMAGE_SUCCESS) {
                 napi_value bufSize;
                 napi_create_int32(env, static_cast<int32_t>(nativeBufferSize), &bufSize);
                 napi_set_named_property(env, resultObj, "bufferSize", bufSize);
             }
         
             int32_t rowStride = 0;
             errCode = OH_ImageNative_GetRowStride(image, components[0], &rowStride);
             OH_LOG_INFO(LOG_APP, "GetImageInfoObject: GetRowStride errCode=%{public}d,"
                         "rowStride=%{public}d", errCode, rowStride);
             if (errCode == IMAGE_SUCCESS) {
                 napi_value jsRowStride;
                 napi_create_int32(env, rowStride, &jsRowStride);
                 napi_set_named_property(env, resultObj, "rowStride", jsRowStride);
             }
         
             int32_t pixelStride = 0;
             errCode = OH_ImageNative_GetPixelStride(image, components[0], &pixelStride);
             OH_LOG_INFO(LOG_APP, "GetImageInfoObject: GetPixelStride errCode=%{public}d, pixelStride=%{public}d",
                         errCode, pixelStride);
             if (errCode == IMAGE_SUCCESS) {
                 napi_value jsPixelStride;
                 napi_create_int32(env, pixelStride, &jsPixelStride);
                 napi_set_named_property(env, resultObj, "pixelStride", jsPixelStride);
             }
             delete [] components;
         }
         return resultObj;
     }
     ```

   - Obtain the image properties and encapsulate them into an NAPI object.

     <!-- @[get_imageInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->      

     ``` C++
     // Obtain the image properties and encapsulate them into an NAPI object.
     static napi_value GetImageInfoObject(napi_env env, OH_ImageNative* image)
     {
         OH_LOG_INFO(LOG_APP, "GetImageInfoObject: enter, image=%{public}p", image);
         napi_value resultObj;
         napi_create_object(env, &resultObj);
         resultObj = GetImageSizeInfo(env, image);
         
         size_t componentTypeSize = 0;
         componentTypeSize = GetComponentTypeSize(image, componentTypeSize);
         if (componentTypeSize > 0) {
             resultObj = GetComponentInfo(env, componentTypeSize, image, resultObj);
         }
     
         int64_t timestamp = 0;
         Image_ErrorCode errCode = OH_ImageNative_GetTimestamp(image, &timestamp);
         OH_LOG_INFO(LOG_APP, "GetImageInfoObject: GetTimestamp errCode=%{public}d, timestamp=%{public}ld",
                     errCode, timestamp);
         if (errCode == IMAGE_SUCCESS) {
             napi_value jsTimestamp;
             napi_create_int64(env, timestamp, &jsTimestamp);
             napi_set_named_property(env, resultObj, "timestamp", jsTimestamp);
         }
     
         OH_LOG_INFO(LOG_APP, "GetImageInfoObject: exit");
         return resultObj;
     }
     ```

   - Obtain the ReceiverImageInfo.

     <!-- @[get_receiverImageInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->      

     ``` C++
     static napi_value GetReceiverImageInfo(napi_env env, napi_callback_info info)
     {
         OH_ImageNative* image = NotifyJsImageInfoSync();
         if (!image) {
             napi_value undefined;
             napi_get_undefined(env, &undefined);
             return undefined;
         }
         napi_value resultObj = GetImageInfoObject(env, image);
         OH_ImageNative_Release(image);
         return resultObj;
     }
     ```

8. Release the receiver.

   <!-- @[release_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadReceiver.cpp) -->     

   ``` C++
   static napi_value ReleaseImageReceiver(napi_env env, napi_callback_info info)
   {
       if (g_receiver == nullptr) {
           OH_LOG_INFO(LOG_APP, "No image receiver to release.");
           return nullptr;
       }
   
       Image_ErrorCode errCode = OH_ImageReceiverNative_Off(g_receiver);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest image receiver off failed, errCode: %{public}d.", errCode);
       }
   
       // Exclusive lock (write).
       std::unique_lock<std::shared_mutex> lock(shared_receiver_mutex);
       errCode = OH_ImageReceiverNative_Release(g_receiver);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "Release image receiver failed, errCode: %{public}d.", errCode);
       }
       
       g_receiver = nullptr;
       return GetJsResultDemo(env, errCode);
   }
   ```