# 使用Image_NativeModule处理图像信息
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

图像信息类，用于设置和读取图像的矩形大小、组件信息和像素信息。

## 开发步骤

### 添加依赖

在进行应用开发之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加libohimage.so，libimage_receiver.so，libnative_image.so 以及日志依赖libhilog_ndk.z.so。

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libohimage.so libimage_receiver.so libnative_image.so)
```

### Native接口调用

具体接口说明请参考[API文档](../../reference/apis-image-kit/capi-image-nativemodule.md)。

在Deveco Studio新建Native C++应用，默认生成的项目中包含index.ets文件，在entry\src\main\cpp目录下会自动生成一个cpp文件（hello.cpp或napi_init.cpp，本示例以hello.cpp文件名为例）。在hello.cpp中实现C API接口调用逻辑，示例代码如下：

```c++
#include <hilog/log.h>
#include <multimedia/image_framework/image/image_native.h>
#include <multimedia/image_framework/image/image_receiver_native.h>

#undef LOG_DOMAIN
#define LOG_DOMAIN 0x3200

#undef LOG_TAG
#define LOG_TAG "MY_TAG"

#define IMAGE_WIDTH 320
#define IMAGE_HEIGHT 480
#define IMAGE_CAPACITY 2

static void ImageNativeCTest()
{
    // 创建 OH_ImageReceiverOptions 实例。
    OH_ImageReceiverOptions* options = nullptr;
    Image_ErrorCode errCode = OH_ImageReceiverOptions_Create(&options);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest create image receiver options failed, errCode: %{public}d.", errCode);
        return;
    }

    Image_Size imgSize;
    imgSize.width = IMAGE_WIDTH;
    imgSize.height = IMAGE_HEIGHT;

    // 设置 OH_ImageReceiverOptions 的 size 属性。该属性仅为必要入参，实际上不会生效，图片属性由生产者决定，如相机。
    errCode = OH_ImageReceiverOptions_SetSize(options, imgSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest set image receiver options size failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // 设置 OH_ImageReceiverOptions 的 capacity 属性。
    errCode = OH_ImageReceiverOptions_SetCapacity(options, IMAGE_CAPACITY);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest set image receiver options capacity failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // 创建 OH_ImageReceiverNative 实例。
    OH_ImageReceiverNative* receiver = nullptr;
    errCode = OH_ImageReceiverNative_Create(options, &receiver);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest create image receiver failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);
        return;
    }

    // 读取 OH_ImageReceiverNative 的下一个图片对象。
    OH_ImageNative* image = nullptr;
    errCode = OH_ImageReceiverNative_ReadNextImage(receiver, &image);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image receiver next image failed, errCode: %{public}d.", errCode);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // 读取 OH_ImageNative 的 size 属性。该属性实际上不会生效，图片属性由生产者决定，如相机。
    Image_Size imgSizeRead;
    errCode = OH_ImageNative_GetImageSize(image, &imgSizeRead);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image size failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // 读取 OH_ImageNative 的组件列表的元素个数。
    size_t componentTypeSize = 0;
    errCode = OH_ImageNative_GetComponentTypes(image, nullptr, &componentTypeSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image component types failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // 读取 OH_ImageNative 的组件列表。
    uint32_t* components = new uint32_t[componentTypeSize];
    errCode = OH_ImageNative_GetComponentTypes(image, &components, &componentTypeSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image component types failed, errCode: %{public}d.", errCode);
        delete [] components;
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    delete [] components;

    // 读取 OH_ImageNative 的第一个组件所对应的缓冲区对象。
    OH_NativeBuffer* nativeBuffer = nullptr;
    errCode = OH_ImageNative_GetByteBuffer(image, components[0], &nativeBuffer);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image byte buffer failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // 读取 OH_ImageNative 的第一个组件所对应的缓冲区大小。
    size_t nativeBufferSize = 0;
    errCode = OH_ImageNative_GetBufferSize(image, components[0], &nativeBufferSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image buffer size failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // 读取 OH_ImageNative 的第一个组件所对应的像素行宽。
    int32_t rowStride = 0;
    errCode = OH_ImageNative_GetRowStride(image, components[0], &rowStride);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image row stride failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // 读取 OH_ImageNative 的第一个组件所对应的像素大小。
    int32_t pixelStride = 0;
    errCode = OH_ImageNative_GetPixelStride(image, components[0], &pixelStride);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get image pixel stride failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // 读取 OH_ImageNative 对象所对应的时间戳信息。
    int64_t timestamp = 0;
    errCode = OH_ImageNative_GetTimestamp(image, &timestamp);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest get timestamp failed, errCode: %{public}d.", errCode);
        OH_ImageNative_Release(image);
        OH_ImageReceiverOptions_Release(options);
        OH_ImageReceiverNative_Release(receiver);
        return;
    }

    // 释放 OH_ImageNative 实例。
    errCode = OH_ImageNative_Release(image);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest release image native failed, errCode: %{public}d.", errCode);
    }

    // 释放 OH_ImageReceiverOptions 实例。
    errCode = OH_ImageReceiverOptions_Release(options);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest release image receiver options failed, errCode: %{public}d.", errCode);
    }

    // 释放 OH_ImageReceiverOptions 实例。
    errCode = OH_ImageReceiverNative_Release(receiver);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest release image receiver failed, errCode: %{public}d.", errCode);
    }
}
```
