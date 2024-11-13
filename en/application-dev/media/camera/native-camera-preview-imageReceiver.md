# Secondary Processing of Preview Streams (C/C++)

You can use the APIs in the **ImageReceiver** class to create a **PreviewOutput** instance and obtain real-time data of the preview stream for secondary processing. For example, you can add a filter algorithm to the preview stream.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/_o_h___camera.md) for the API reference.

1. Import the NDK, which provides camera-related attributes and methods.

   ```c++
    // Include the NDK header files.
   #include <cstdlib>
   #include <hilog/log.h>
   #include <memory>
   #include <multimedia/image_framework/image/image_native.h>
   #include <multimedia/image_framework/image/image_receiver_native.h>
   #include "ohcamera/camera.h"
   #include "ohcamera/camera_input.h"
   #include "ohcamera/capture_session.h"
   #include "ohcamera/preview_output.h"
   #include "ohcamera/camera_manager.h"
   ```

2. Link the dynamic library in the CMake script.

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libhilog_ndk.z.so
       libohimage.so
       libimage_receiver.so
       libnative_image.so
       libohcamera.so
   )
   ```

3. Initialize an [ImageReceiver](../image/image-receiver-c.md) instance and obtain a surface ID.

   Call **OH_ImageReceiverNative_Create** of the image module to create an **OH_ImageReceiverNative** instance, and call **OH_ImageReceiverNative_GetReceivingSurfaceId** of the instance to obtain a surface ID.

   ```c++
   void InitImageReceiver() {
       OH_ImageReceiverOptions *options = nullptr;
       // Capture exceptions and check whether the instance is null. This example shows only the API call process.
       // Set image parameters.
       Image_ErrorCode errCode = OH_ImageReceiverOptions_Create(&options);
       Image_Size imgSize;
       imgSize.width = 1080; // Width of the created preview stream.
       imgSize.height = 1080; // Height of the created preview stream.
       int32_t capacity = 8; // Maximum number of images in BufferQueue. The recommended value is 8.
       errCode = OH_ImageReceiverOptions_SetSize(options, imgSize);
       errCode = OH_ImageReceiverOptions_SetCapacity(options, capacity);
       // Create an OH_ImageReceiverNative instance.
       OH_ImageReceiverNative *receiver = nullptr;
       errCode = OH_ImageReceiverNative_Create(options, &receiver);
       // Obtain the Surface ID of the OH_ImageReceiverNative instance.
       uint64_t receiverSurfaceID = 0;
       errCode = OH_ImageReceiverNative_GetReceivingSurfaceId(receiver, &receiverSurfaceID);
       OH_LOG_INFO(LOG_APP, "receiver surfaceID:%{public}%llu", receiverSurfaceID);
   }
   ```

4. Create a preview stream based on the surface ID obtained. For details, see step 4 in [Camera Preview (C/C++)](./native-camera-preview.md).

5. Create a session and enable it. For details, see [Camera Session Management (C/C++)](./native-camera-session-management.md).

6. Register an ImageReceiver callback to listen for the image content reported by each frame.

   ```c++
   OH_ImageReceiverNative *receiver; // Instance created in step 3.
   uint32_t PREVIEW_WIDTH = 1080; // Width of the created preview stream.
   uint32_t PREVIEW_HEIGHT = 1080; // Height of the created preview stream.
   
   // Image callback. For details, see Media/Image Kit.
   static void OnCallback(OH_ImageReceiverNative *receiver) {
       OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest buffer available.");
       // Capture exceptions and check whether the instance is null. This example shows only the API call process.
       OH_ImageNative *image = nullptr;
       // Obtain the image from the bufferQueue.
       Image_ErrorCode errCode = OH_ImageReceiverNative_ReadNextImage(receiver, &image);
       // Obtain the image's component type.
       size_t typeSize = 0;
       OH_ImageNative_GetComponentTypes(image, nullptr, &typeSize);
       uint32_t* types = new uint32_t[typeSize];
       OH_ImageNative_GetComponentTypes(image, &types, &typeSize);
       uint32_t component = types[0];
       // Obtain the image buffer.
       OH_NativeBuffer *imageBuffer = nullptr;
       errCode = OH_ImageNative_GetByteBuffer(image, component, &imageBuffer);
       size_t bufferSize = 0;
       errCode = OH_ImageNative_GetBufferSize(image, component, &bufferSize);
       OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest buffer component: %{public}d size:%{public}zu", component, bufferSize);
       // Obtain the row stride of the image.
       int32_t stride = 0;
       errCode = OH_ImageNative_GetRowStride(image, component, &stride);
       OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest buffer stride: %{public}d.", stride);
       void* srcVir = nullptr;
       OH_NativeBuffer_Map(imageBuffer, &srcVir);
       uint8_t* srcBuffer = static_cast<uint8_t*>(srcVir);
       // Check whether the row stride is the same as the width of the preview stream. If they are different, consider the impact of the stride on buffer reading.
       if (stride == PREVIEW_WIDTH) {
           // Process the buffer by calling the API that does not support stride.
       } else {
           // Process the buffer by calling the API that supports stride or remove the stride data.
           // The following uses the operation of removing the stride data as an example. Specifically, remove the stride data from the byteBuffer and obtain a new dstBuffer by means of copy.
           size_t dstBufferSize = PREVIEW_WIDTH * PREVIEW_HEIGHT * 1.5; // Camera preview stream in NV21 format.
           std::unique_ptr<uint8_t[]> dstBuffer = std::make_unique<uint8_t[]>(dstBufferSize);
           uint8_t *dstPtr = dstBuffer.get();
           for (int j = 0; j < PREVIEW_HEIGHT * 1.5; j++) {
               memcpy(dstPtr, srcBuffer, PREVIEW_WIDTH);
               dstPtr += PREVIEW_WIDTH;
               srcBuffer += stride;
           }
           // Process the buffer by calling the API that does not support stride.
       }
       // Release the buffer to ensure that the bufferQueue is rotated properly.
       OH_NativeBuffer_Unmap(imageBuffer);
       errCode = OH_ImageNative_Release(image);
   }
   
   void OnImageReceiver() {
       // Register the callback to listen for the image content reported by each frame.
       Image_ErrorCode errCode = OH_ImageReceiverNative_On(receiver, OnCallback);
   }
   ```
