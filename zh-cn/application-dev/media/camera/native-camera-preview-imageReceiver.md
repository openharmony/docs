# 预览流二次处理(C/C++)

通过ImageReceiver创建预览输出，获取预览流实时数据，以供后续进行图像二次处理，比如应用可以对其添加滤镜算法等。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/_o_h___camera.md)。

1. 导入NDK接口，接口中提供了相机相关的属性和方法，导入方法如下。

   ```c++
    // 导入NDK接口头文件
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

2. 在CMake脚本中链接相关动态库。

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

3. 初始化图片接收器[ImageReceiver](../image/image-receiver-c.md)实例，获取SurfaceId。

   通过image的OH_ImageReceiverNative_Create方法创建OH_ImageReceiverNative实例，再通过实例的OH_ImageReceiverNative_GetReceivingSurfaceId方法获取SurfaceId。

   ```c++
   void InitImageReceiver() {
       OH_ImageReceiverOptions *options = nullptr;
       // 注意捕获错误码处理异常及对象判空，当前示例仅展示调用流程
       // 设置图片参数
       Image_ErrorCode errCode = OH_ImageReceiverOptions_Create(&options);
       Image_Size imgSize;
       imgSize.width = 1080; // 创建预览流的宽
       imgSize.height = 1080; // 创建预览流的高
       int32_t capacity = 8; // BufferQueue里最大Image数量，推荐填写8
       errCode = OH_ImageReceiverOptions_SetSize(options, imgSize);
       errCode = OH_ImageReceiverOptions_SetCapacity(options, capacity);
       // 创建OH_ImageReceiverNative对象
       OH_ImageReceiverNative *receiver = nullptr;
       errCode = OH_ImageReceiverNative_Create(options, &receiver);
       // 获取OH_ImageReceiverNative对象的SurfaceId
       uint64_t receiverSurfaceID = 0;
       errCode = OH_ImageReceiverNative_GetReceivingSurfaceId(receiver, &receiverSurfaceID);
       OH_LOG_INFO(LOG_APP, "receiver surfaceID:%{public}%llu", receiverSurfaceID);
   }
   ```

4. 通过上一步获取到的SurfaceId创建预览流，参考[预览(C/C++)](./native-camera-preview.md)步骤4。

5. 创建会话，使能会话，参考[会话管理(C/C++)](./native-camera-session-management.md)。

6. 注册ImageReceiver图片接收器的回调，监听获取每帧上报图像内容。

   ```c++
   OH_ImageReceiverNative *receiver; // 步骤3创建的实例

   // 图像回调函数，参考媒体/Image Kit（图片处理服务）
   static void OnCallback(OH_ImageReceiverNative *receiver) {
       OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest buffer available.");
       // 注意捕获错误码处理异常及对象判空，当前示例仅展示调用流程
       OH_ImageNative *image = nullptr;
       // 从bufferQueue中获取图像
       Image_ErrorCode errCode = OH_ImageReceiverNative_ReadNextImage(receiver, &image);
       // 读取图像宽高
       Image_Size size;
       errCode = OH_ImageNative_GetImageSize(image, &size);
       OH_LOG_INFO(LOG_APP, "OH_ImageNative_GetImageSize errCode:%{public}d width:%{public}d height:%{public}d", errCode,
           size.width, size.height);

       // 获取图像ComponentType
       size_t typeSize = 0;
       OH_ImageNative_GetComponentTypes(image, nullptr, &typeSize);
       uint32_t* types = new uint32_t[typeSize];
       OH_ImageNative_GetComponentTypes(image, &types, &typeSize);
       uint32_t component = types[0];
       // 获取图像buffer
       OH_NativeBuffer *imageBuffer = nullptr;
       errCode = OH_ImageNative_GetByteBuffer(image, component, &imageBuffer);
       size_t bufferSize = 0;
       errCode = OH_ImageNative_GetBufferSize(image, component, &bufferSize);
       OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest buffer component: %{public}d size:%{public}zu", component, bufferSize);
       // 获取图像行距
       int32_t stride = 0;
       errCode = OH_ImageNative_GetRowStride(image, component, &stride);
       OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest buffer stride：%{public}d.", stride);
       void* srcVir = nullptr;
       OH_NativeBuffer_Map(imageBuffer, &srcVir);
       uint8_t* srcBuffer = static_cast<uint8_t*>(srcVir);
       // 判断行距与预览流宽是否一致，如不一致，需要考虑stride对读取buffer的影响
       if (stride == size.width) {
           // 传给其他不需要stride的接口处理
       } else {
           // 传给其他支持stride的接口处理，或去除stride数据
           // 去除stride数据示例:将byteBuffer中的数据去除stride，拷贝得到新的dstBuffer数据
           size_t dstBufferSize = size.width * size.height * 1.5; // 相机预览流返回NV21格式
           std::unique_ptr<uint8_t[]> dstBuffer = std::make_unique<uint8_t[]>(dstBufferSize);
           uint8_t *dstPtr = dstBuffer.get();
           for (int j = 0; j < size.height * 1.5; j++) {
               memcpy(dstPtr, srcBuffer, size.width);
               dstPtr += size.width;
               srcBuffer += stride;
           }
           // 传给其他不需要stride的接口处理
       }
       // 释放buffer,保证bufferQueue正常轮转
       OH_NativeBuffer_Unmap(imageBuffer);
       errCode = OH_ImageNative_Release(image);
   }
   
   void OnImageReceiver() {
       // 注册图像回调事件，监听每帧上报的图像
       Image_ErrorCode errCode = OH_ImageReceiverNative_On(receiver, OnCallback);
   }
   ```